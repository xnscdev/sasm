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
