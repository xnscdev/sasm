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

#include "gen-coff.hh"
#include "gen-elf.hh"

/* Supported object formats */

enum class ObjectFileFormat
{
  BINARY32 = 1, /* 32-bit raw machine code */
  ELF32, /* 32-bit ELF relocatable */
  COFF32 /* 32-bit COFF relocatable */
};

/* Wrapper class for all types of code generation */

class Object
{
  AsmContext ctx {4}; /* 32-bit code only */
  std::vector <unsigned char> binary;
  ELF32Object elf;
  COFF32Object coff;

public:
  ObjectFileFormat type;

  Object (ObjectFileFormat type, std::string filename) :
    elf (filename), coff (filename), type (type) {}
  bool assemble_inst (AsmInst *inst, uint32_t section);
  bool write (FILE *stream);
};

#endif
