/*************************************************************************
 * gen-coff.hh -- This file is part of sasm.                             *
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

#ifndef _GEN_COFF_HH
#define _GEN_COFF_HH

#include <string>
#include <vector>
#include "coff.h"
#include "inst.hh"

class COFF32Object;

class COFF32Aux
{
public:
  virtual bool write (FILE *stream) = 0;
};

class COFF32AuxWeak : public COFF32Aux
{
public:
  uint32_t tag_index;
  uint32_t chars;

  bool write (FILE *stream);
};

class COFF32AuxFile : public COFF32Aux
{
public:
  char filename[18];

  bool write (FILE *stream);
};

class COFF32AuxSection : public COFF32Aux
{
public:
  uint32_t size;
  uint16_t relocs;
  uint16_t lnnos;
  uint32_t checksum;
  uint16_t section;

  bool write (FILE *stream);
};

class COFF32Symbol
{
public:
  std::string name;
  uint32_t value;
  short scnum;
  unsigned short type;
  unsigned char sclass;
  unsigned char auxcnt;
  bool section;
  std::vector <COFF32Aux *> aux;

  COFF32Symbol (void) = default;
  COFF32Symbol (std::string name, uint32_t value, short scnum,
		unsigned short type, unsigned char sclass, unsigned char aux) :
    name (std::move (name)), value (value), scnum (scnum), type (type),
    sclass (sclass), auxcnt (aux), section (false) {}
};

class COFF32Section
{
public:
  std::string name;
  std::vector <coff_reloc> relocs;
  uint32_t relptr;
  uint32_t flags;
  std::vector <unsigned char> data;

  COFF32Section (std::string name, uint32_t flags) :
    name (std::move (name)), flags (flags) {}
  bool write (uint32_t offset, uint32_t header, COFF32Object *obj,
	      uint32_t sectid, FILE *stream);
};

class COFF32Object
{
  AsmContext ctx {4};

  bool write_strtab (FILE *stream);

public:
  std::vector <COFF32Section> shtable;
  std::vector <COFF32Symbol> symtab;
  std::vector <std::string> strtab;

  COFF32Object (std::string filename);
  void fill_string (coff_str &result, std::string str);
  uint32_t add_section (std::string name, uint32_t flags);
  short search_section (std::string name);
  ssize_t section_symbol (uint32_t section);
  ssize_t section_symbol_aux (uint32_t section);
  bool assemble_inst (AsmInst *inst, uint32_t section);
  ssize_t add_symbol (AsmLabel *sym);
  bool write (FILE *stream);
};

#endif
