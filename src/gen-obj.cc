/*************************************************************************
 * gen-obj.cc -- This file is part of sasm.                              *
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

#include "assemble.hh"
#include "gen-obj.hh"

static Elf32_Word
elf_section_type (std::string section)
{
  if (section == ".bss")
    return SHT_NOBITS;
  if (section == ".note")
    return SHT_NOTE;
  if (section == ".hash")
    return SHT_HASH;
  if (section == ".dynamic")
    return SHT_DYNAMIC;
  return SHT_PROGBITS;
}

static Elf32_Word
elf_section_flags (std::string section)
{
  if (section.rfind (".data", 0) == 0 || section == ".bss")
    return SHF_ALLOC | SHF_WRITE;
  if (section.rfind (".rodata", 0) == 0 || section == ".hash")
    return SHF_ALLOC;
  if (section == ".text")
    return SHF_ALLOC | SHF_EXECINSTR;
  return 0;
}

static Elf32_Word
elf_section_align (std::string section)
{
  /* Not required, but for best performance */
  if (section == ".text")
    return 16;
  if (section.rfind (".data", 0) == 0 || section.rfind (".rodata", 0) == 0
      || section == ".bss")
    return 4;
  return 1;
}

static uint32_t
coff_section_flags (std::string section)
{
  uint32_t align = IMAGE_SCN_ALIGN_1BYTES;
  if (section == ".text")
    align = IMAGE_SCN_ALIGN_16BYTES;
  if (section.rfind (".data", 0) == 0 || section.rfind (".rodata", 0) == 0
      || section == ".bss")
    align = IMAGE_SCN_ALIGN_4BYTES;

  uint32_t perms = IMAGE_SCN_MEM_READ;
  if (section.rfind (".rodata", 0) != 0 && section != ".hash"
      && section != ".text")
    perms |= IMAGE_SCN_MEM_WRITE;
  if (section == ".text")
    perms |= IMAGE_SCN_MEM_EXECUTE;

  uint32_t type = IMAGE_SCN_CNT_INITIALIZED_DATA;
  if (perms & IMAGE_SCN_MEM_EXECUTE)
    type = IMAGE_SCN_CNT_CODE;
  if (section == ".bss")
    type = IMAGE_SCN_CNT_UNINITIALIZED_DATA;

  return align | perms | type;
}

bool
Object::elf_assemble (AsmInst *inst)
{
  Elf32_Word from = elf.search_section (section);
  if (from == 0)
    return false;
  bool ret = elf.assemble_inst (inst, from);
  if (reloc)
    {
      Elf32_Word target = elf.search_section (reloc_section);
      if (target == 0)
	return false;
      elf.relocate_from (target, section, reloc_inst, R_386_32);
    }
  reloc = false;
  return ret;
}

bool
Object::coff_assemble (AsmInst *inst)
{
  uint32_t from = coff.search_section (section);
  if (from == 0)
    return false;
  bool ret = coff.assemble_inst (inst, from);
  if (reloc)
    {
    }
  reloc = false;
  return ret;
}

void
Object::switch_section (std::string new_sect)
{
  section = new_sect;
  uint32_t id;
  switch (type)
    {
    case ObjectFileFormat::ELF32:
      id = elf.search_section (section);
      break;
    case ObjectFileFormat::COFF32:
      id = coff.search_section (section);
      break;
    default:
      return; /* Sections not supported in raw binary, or invalid type */
    }
  if (id == 0)
    {
      switch (type)
	{
	case ObjectFileFormat::ELF32:
	  elf.add_section (section, elf_section_type (section),
			   elf_section_flags (section),
			   elf_section_align (section));
	  break;
	case ObjectFileFormat::COFF32:
	  coff.add_section (section, coff_section_flags (section));
	  break;
	default:
	  break; /* -Wswitch */
	}
    }
}

bool
Object::assemble_inst (AsmInst *inst)
{
  switch (type)
    {
    case ObjectFileFormat::BINARY32:
      return assemble (inst, binary, ctx);
    case ObjectFileFormat::ELF32:
      return elf_assemble (inst);
    case ObjectFileFormat::COFF32:
      return coff_assemble (inst);
    default:
      return false;
    }
}

bool
Object::write (FILE *stream)
{
  switch (type)
    {
    case ObjectFileFormat::BINARY32:
      for (unsigned char b : binary)
	fputc (b, stream);
      return true;
    case ObjectFileFormat::ELF32:
      return elf.write (stream);
    case ObjectFileFormat::COFF32:
      return coff.write (stream);
    default:
      return false;
    }
}
