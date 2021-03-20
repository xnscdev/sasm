/*************************************************************************
 * gen-coff.cc -- This file is part of sasm.                             *
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
#include "gen-coff.hh"
#include "util.hh"

bool
COFF32AuxWeak::write (FILE *stream)
{
  print_int32_le (tag_index, stream);
  print_int32_le (chars, stream);
  for (int i = 0; i < 10; i++)
    fputc (0, stream);
  return true;
}

bool
COFF32AuxFile::write (FILE *stream)
{
  return fwrite (filename, 18, 1, stream) == 1;
}

bool
COFF32AuxSection::write (FILE *stream)
{
  print_int32_le (size, stream);
  print_int16_le (relocs, stream);
  print_int16_le (lnnos, stream);
  print_int32_le (checksum, stream);
  print_int16_le (section, stream);
  print_int32_le (0, stream);
  return true;
}

bool
COFF32Section::write (uint32_t offset, uint32_t header, COFF32Object *obj,
		      uint32_t sectid, FILE *stream)
{
  coff_scnhdr shdr;
  obj->fill_string (shdr.s_name, name);
  shdr.s_paddr = 0;
  shdr.s_vaddr = 0;
  shdr.s_size = data.size ();
  shdr.s_scnptr = offset;
  shdr.s_relptr = relptr;
  shdr.s_lnnoptr = 0;
  shdr.s_nreloc = relocs.size ();
  shdr.s_nlnno = 0;
  shdr.s_flags = flags;

  ssize_t symbol = obj->section_symbol (sectid);
  if (symbol != -1)
    {
      COFF32AuxSection *aux =
	CAST (COFF32AuxSection *, obj->symtab[symbol].aux.back ());
      aux->size = data.size ();
      aux->relocs = relocs.size ();
      aux->lnnos = 0;
      aux->checksum = 0;
      aux->section = 0;
    }

  if (fseek (stream, header, SEEK_SET) != 0)
    return false;
  if (fwrite (&shdr, sizeof (coff_scnhdr), 1, stream) != 1)
    return false;

  if (fseek (stream, offset, SEEK_SET) != 0)
    return false;
  for (unsigned char b : data)
    fputc (b, stream);
  return true;
}

COFF32Object::COFF32Object (std::string filename)
{
  COFF32Symbol symbol (".file", 0, N_DEBUG, T_NULL, C_FILE, 1);
  COFF32AuxFile *aux = new COFF32AuxFile ();
  (strncpy (aux->filename, filename.c_str (), 18));
  symbol.aux.push_back (aux);
  symtab.push_back (symbol);
}

bool
COFF32Object::write_strtab (FILE *stream)
{
  size_t len = 4;
  for (std::string str : strtab)
    len += str.size () + 1;
  print_int32_le (len, stream);

  for (std::string str : strtab)
    {
      if (fwrite (str.c_str (), str.size () + 1, 1, stream) != 1)
	return false;
    }
  return true;
}

void
COFF32Object::fill_string (coff_str &result, std::string str)
{
  if (str.size () > 8)
    {
      result.e_long.e_zeroes = 0;
      result.e_long.e_offset = 4;
      for (std::string p : strtab)
	result.e_long.e_offset += p.size () + 1;
      strtab.push_back (str);
    }
  else
    (strncpy ((char *) result.e_name, str.c_str (), 8));
}

uint32_t
COFF32Object::add_section (std::string name, uint32_t flags)
{
  shtable.emplace_back (name, flags);
  COFF32Symbol symbol (name, 0, shtable.size (), T_NULL, C_STAT, 1);
  symbol.section = true;
  symbol.aux.push_back (new COFF32AuxSection ());
  symtab.push_back (symbol);
  return shtable.size ();
}

short
COFF32Object::search_section (std::string name)
{
  for (size_t i = 0; i < shtable.size (); i++)
    {
      if (name == shtable[i].name)
	return i + 1;
    }
  return 0;
}

ssize_t
COFF32Object::section_symbol (uint32_t section)
{
  for (size_t i = 0; i < symtab.size (); i++)
    {
      const COFF32Symbol &symbol = symtab[i];
      if (symbol.scnum > 0 && (uint32_t) symbol.scnum == section
	  && symbol.section)
	return i;
    }
  return -1;
}

ssize_t
COFF32Object::section_symbol_aux (uint32_t section)
{
  size_t auxcnt = 0;
  for (size_t i = 0; i < symtab.size (); i++)
    {
      const COFF32Symbol &symbol = symtab[i];
      if (symbol.scnum > 0 && (uint32_t) symbol.scnum == section
	  && symbol.section)
	return i + auxcnt;
      auxcnt += symbol.auxcnt;
    }
  return -1;
}

bool
COFF32Object::assemble_inst (AsmInst *inst, uint32_t section)
{
  return assemble (inst, shtable[section - 1].data, ctx);
}

ssize_t
COFF32Object::add_symbol (AsmLabel *sym)
{
  COFF32Symbol symbol;
  symbol.name = sym->name;
  symbol.scnum = search_section (sym->section);
  switch (sym->bind)
    {
    case AsmLabelBinding::LOCAL:
      symbol.sclass = C_STAT;
      break;
    case AsmLabelBinding::GLOBAL:
    case AsmLabelBinding::WEAK:
      symbol.sclass = C_EXT;
      break;
    default:
      return -1;
    }
  /* Avoid messing with COFF auxiliary data */
  symbol.type = T_NULL;
  symbol.auxcnt = 0;
  symbol.value = sym->addr;
  symtab.push_back (symbol);
  return symtab.size () - 1;
}

bool
COFF32Object::write (FILE *stream)
{
  coff_filehdr header;
  header.f_magic[0] = COFF_MAGIC0;
  header.f_magic[1] = COFF_MAGIC1;
  header.f_nscns = shtable.size ();
  header.f_timdat = time (nullptr);
  header.f_opthdr = 0;
  header.f_flags = 0;

  uint32_t offset = align (0x14 + shtable.size () * sizeof (coff_scnhdr), 16);
  uint32_t hdroff = 0x14;

  /* Write relocation tables */
  uint32_t reloc_offset = offset;
  for (COFF32Section &section : shtable)
    reloc_offset += section.data.size ();
  if (fseek (stream, reloc_offset, SEEK_SET) != 0)
    return false;
  for (COFF32Section &section : shtable)
    {
      section.relptr = reloc_offset;
      for (coff_reloc rel : section.relocs)
	{
	  if (fwrite (&rel, 10, 1, stream) != 1)
	    return false;
	  reloc_offset += 10;
	}
    }

  /* Write section data */
  for (size_t i = 0; i < shtable.size (); i++)
    {
      COFF32Section &section = shtable[i];
      if (!section.write (offset, hdroff, this, i + 1, stream))
	return false;
      offset += section.data.size ();
      hdroff += sizeof (coff_scnhdr);
    }

  header.f_symptr = reloc_offset;
  header.f_nsyms = symtab.size ();
  for (COFF32Symbol &symbol : symtab)
    header.f_nsyms += symbol.auxcnt;
  rewind (stream);
  if (fwrite (&header, sizeof (coff_filehdr), 1, stream) != 1)
    return false;

  if (fseek (stream, header.f_symptr, SEEK_SET) != 0)
    return false;
  for (COFF32Symbol &symbol : symtab)
    {
      coff_syms raw;
      fill_string (raw.n_name, symbol.name);
      raw.n_value = symbol.value;
      raw.n_scnum = symbol.scnum;
      raw.n_type = symbol.type;
      raw.n_sclass = symbol.sclass;
      raw.n_numaux = symbol.auxcnt;
      if (fwrite (&raw, 18, 1, stream) != 1)
	return false;
      for (COFF32Aux *aux : symbol.aux)
	{
	  if (!aux->write (stream))
	    return false;
	}
    }

  /* Write string table */
  if (!write_strtab (stream))
    return false;
  return true;
}
