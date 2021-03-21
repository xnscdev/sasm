/*************************************************************************
 * gen-obj.hh -- This file is part of sasm.                              *
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

#ifndef _GEN_OBJ_HH
#define _GEN_OBJ_HH

#include <map>
#include "gen-coff.hh"
#include "gen-elf.hh"

/* Supported object formats */

enum class ObjectFileFormat
{
  NONE = 0, /* Invalid value */
  BINARY32, /* 32-bit raw machine code */
  ELF32, /* 32-bit ELF relocatable */
  COFF32 /* 32-bit COFF relocatable */
};

/* Wrapper class for all types of code generation */

class Object
{
  std::vector <unsigned char> binary;
  ELF32Object elf;
  COFF32Object coff;

  bool elf_assemble (AsmInst *inst);
  bool coff_assemble (AsmInst *inst);

public:
  ObjectFileFormat type;
  std::vector <AsmLine *> lines;
  std::map <std::string, uint32_t> addrspace;
  std::string section;
  AsmContext ctx {4}; /* 32-bit code only */

  Object (ObjectFileFormat type, std::string filename) :
    elf (filename), coff (filename), type (type) {}
  void switch_section (std::string new_sect);
  bool assemble_inst (AsmInst *inst);
  void add_label (AsmLabel *sym);
  std::string section_from_addr (uint32_t addr);
  bool write (FILE *stream);
};

#endif
