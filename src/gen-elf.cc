/*************************************************************************
 * gen-elf.cc -- This file is part of sasm.                              *
 * Copyright (C) 2021                                                    *
 *                                                                       *
 * This program is free software: you can redistribute it and/or modify  *
 * it under the terms of the GNU General Public License as published by  *
 * the Free Software Foundation, either version 3 of the License, or     *
 * (at your option) any later version.                                   *
 *                                                                       *
 * This program is distributed in the hope that it will be useful,       *
 * but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the          *
 * GNU General Public License for more details.                          *
 *                                                                       *
 * You should have received a copy of the GNU General Public License     *
 * along with this program. If not, see <https://www.gnu.org/licenses/>. *
 *************************************************************************/

#include <cstring>
#include "assemble.hh"
#include "gen-elf.hh"
#include "util.hh"

Elf32_Word
ELF32Section::add_string (std::string str)
{
  Elf32_Word size = data.size ();
  std::copy (str.begin (), str.end (), std::back_inserter (data));
  data.push_back (0);
  return size;
}

bool
ELF32Section::write (Elf32_Off offset, Elf32_Off header, FILE *stream)
{
  Elf32_Shdr shdr;
  if (type == SHT_NULL)
    memset (&shdr, 0, sizeof (Elf32_Shdr));
  else
    {
      shdr.sh_name = name;
      shdr.sh_type = type;
      shdr.sh_flags = flags;
      shdr.sh_addr = 0;
      shdr.sh_offset = offset;
      shdr.sh_link = link;
      shdr.sh_info = info;
      shdr.sh_size = data.size ();
      shdr.sh_addralign = alignment;
    }

  switch (type)
    {
    case SHT_SYMTAB:
      shdr.sh_entsize = sizeof (Elf32_Sym);
      break;
    case SHT_REL:
      shdr.sh_entsize = sizeof (Elf32_Rel);
      break;
    case SHT_RELA:
      shdr.sh_entsize = sizeof (Elf32_Rela);
      break;
    default:
      shdr.sh_entsize = 0;
    }

  if (fseek (stream, header, SEEK_SET) != 0)
    return false;
  if (fwrite (&shdr, sizeof (Elf32_Shdr), 1, stream) != 1)
    return false;

  if (fseek (stream, offset, SEEK_SET) != 0)
    return false;
  for (unsigned char b : data)
    fputc (b, stream);
  return true;
}

ELF32Object::ELF32Object (std::string filename)
{
  /* NULL section */
  shtable.emplace_back (0, SHT_NULL, 0, 0);

  /* Section string table */
  shstrtab.data.push_back (0);
  shstrtab.add_string (".shstrtab");
  shstrtab.add_string (".symtab");
  shstrtab.add_string (".strtab");

  /* Symbol string table */
  strtab.data.push_back (0);

  /* Symbol table */
  Elf32_Sym symbol;
  memset (&symbol, 0, sizeof (Elf32_Sym));
  local_symbols.push_back (symbol);
  symbol.st_name = strtab.add_string (filename);
  symbol.st_value = 0;
  symbol.st_size = 0;
  symbol.st_info = ELF32_ST_INFO (STB_LOCAL, STT_FILE);
  symbol.st_other = 0;
  symbol.st_shndx = SHN_ABS;
  local_symbols.push_back (symbol);
}

Elf32_Word
ELF32Object::shstrtab_match (Elf32_Word start, const char *str)
{
  size_t len = shstrtab.data.size ();
  char *buffer = (char *) malloc (len);
  memcpy (buffer, &shstrtab.data[0], len);
  for (Elf32_Word i = start; i < len; i++)
    {
      if (strcmp (&buffer[i], str) == 0)
	{
	  free (buffer);
	  return i;
	}
    }
  free (buffer);
  return 0;
}

void
ELF32Object::fix_relocation_link_info (void)
{
  for (ELF32Section &section : shtable)
    {
      if (section.type == SHT_REL || section.type == SHT_RELA)
        section.link = shtable.size () - 2;
    }
}

Elf32_Word
ELF32Object::add_section (std::string name, Elf32_Word type, Elf32_Word flags,
			  Elf32_Word addralign)
{
  Elf32_Word nidx = shstrtab.add_string (name);
  shtable.emplace_back (nidx, type, flags, addralign);

  if (type == SHT_PROGBITS || type == SHT_NOBITS)
    {
      Elf32_Sym symbol;
      symbol.st_name = 0;
      symbol.st_value = 0;
      symbol.st_size = 0;
      symbol.st_info = ELF32_ST_INFO (STB_LOCAL, STT_SECTION);
      symbol.st_other = 0;
      symbol.st_shndx = shtable.size () - 1;
      local_symbols.push_back (symbol);
    }
  return shtable.size () - 1;
}

Elf32_Word
ELF32Object::search_section (std::string name)
{
  Elf32_Word offset = 0;
  while ((offset = shstrtab_match (offset, name.c_str ())) != 0)
    {
      for (size_t i = 0; i < shtable.size (); i++)
	{
	  if (shtable[i].name == offset)
	    return i;
	}
    }
  return 0;
}

Elf32_Word
ELF32Object::section_symbol (Elf32_Word section)
{
  for (Elf32_Word i = 0; i < local_symbols.size (); i++)
    {
      if (ELF32_ST_TYPE (local_symbols[i].st_info) == STT_SECTION)
	{
	  if (local_symbols[i].st_shndx == section)
	    return i;
	}
    }
  return 0;
}

bool
ELF32Object::assemble_inst (AsmInst *inst, Elf32_Word section)
{
  return assemble (inst, shtable[section].data, ctx);
}

bool
ELF32Object::add_symbol (AsmLabel *sym)
{
  Elf32_Sym symbol;
  symbol.st_name = strtab.add_string (sym->name);
  symbol.st_value = sym->addr;
  symbol.st_size = sym->size;
  symbol.st_info =
    ELF32_ST_INFO ((unsigned char) sym->bind, (unsigned char) sym->type);
  symbol.st_other = 0;
  symbol.st_shndx = search_section (sym->section);
  if (symbol.st_shndx == 0)
    symbol.st_shndx = add_section (sym->section, SHT_PROGBITS, SHF_ALLOC, 1);
  switch (sym->bind)
    {
    case AsmLabelBinding::LOCAL:
      local_symbols.push_back (symbol);
      break;
    case AsmLabelBinding::GLOBAL:
      global_symbols.push_back (symbol);
      break;
    case AsmLabelBinding::WEAK:
      weak_symbols.push_back (symbol);
      break;
    default:
      return false;
    }
  return true;
}

Elf32_Word
ELF32Object::relocate_from (Elf32_Word target, std::string section,
                            Elf32_Addr offset, unsigned char type)
{
  Elf32_Word targsym = section_symbol (target);
  if (targsym == 0)
    return 0;
  Elf32_Word from_sectid = search_section (section);
  if (from_sectid == 0)
    return 0;
  Elf32_Word rel_sectid = search_section (".rel" + section);
  if (rel_sectid == 0)
    rel_sectid = add_section (".rel" + section, SHT_REL, 0, 4);
  ELF32Section &rel_section = shtable[rel_sectid];
  Elf32_Rel rel;
  rel.r_offset = offset;
  rel.r_info = ELF32_R_INFO (targsym, type);
  rel_section.info = from_sectid;
  for (size_t i = 0; i < sizeof (Elf32_Rel); i++)
    rel_section.data.push_back (((unsigned char *) &rel)[i]);
  return rel_sectid;
}

bool
ELF32Object::write (FILE *stream)
{
  rewind (stream);

  Elf32_Ehdr header;
  header.e_ident[EI_MAG0] = ELFMAG0;
  header.e_ident[EI_MAG1] = ELFMAG1;
  header.e_ident[EI_MAG2] = ELFMAG2;
  header.e_ident[EI_MAG3] = ELFMAG3;
  header.e_ident[EI_CLASS] = ELFCLASS32;
  header.e_ident[EI_DATA] = ELFDATA2LSB;
  header.e_ident[EI_VERSION] = EV_CURRENT;
  header.e_ident[EI_OSABI] = 0;
  header.e_ident[EI_ABIVERSION] = 0;
  memset (&header.e_ident[EI_PAD], 0, EI_NIDENT - EI_PAD);
  header.e_type = ET_REL;
  header.e_machine = EM_386;
  header.e_version = EV_CURRENT;
  header.e_entry = 0;
  header.e_phoff = 0;
  header.e_shoff = 0x40;
  header.e_flags = 0;
  header.e_ehsize = sizeof (Elf32_Ehdr);
  header.e_phentsize = 0;
  header.e_phnum = 0;
  header.e_shentsize = sizeof (Elf32_Shdr);
  header.e_shnum = shtable.size () + 3;
  header.e_shstrndx = shtable.size ();
  if (fwrite (&header, sizeof (Elf32_Ehdr), 1, stream) != 1)
    return false;

  /* Write symbols to symbol table */
  for (Elf32_Sym symbol : local_symbols)
    {
      for (size_t i = 0; i < sizeof (Elf32_Sym); i++)
	symtab.data.push_back (((unsigned char *) &symbol)[i]);
    }
  for (Elf32_Sym symbol : global_symbols)
    {
      for (size_t i = 0; i < sizeof (Elf32_Sym); i++)
	symtab.data.push_back (((unsigned char *) &symbol)[i]);
    }
  for (Elf32_Sym symbol : weak_symbols)
    {
      for (size_t i = 0; i < sizeof (Elf32_Sym); i++)
	symtab.data.push_back (((unsigned char *) &symbol)[i]);
    }

  /* Fix section sh_link and sh_info */
  symtab.link = shtable.size () + 2;
  symtab.info = local_symbols.size ();

  /* Add reserved sections to section header table */
  shtable.push_back (shstrtab);
  shtable.push_back (symtab);
  shtable.push_back (strtab);

  fix_relocation_link_info ();

  /* Write section data */
  Elf32_Off offset = align (0x40 + shtable.size () * sizeof (Elf32_Shdr), 16);
  Elf32_Off hdroff = 0x40;
  for (ELF32Section &section : shtable)
    {
      if (!section.write (offset, hdroff, stream))
	return false;
      offset += section.data.size ();
      hdroff += sizeof (Elf32_Shdr);
      offset = align (offset, 16); /* Does this need to be aligned? */
    }
  return true;
}
