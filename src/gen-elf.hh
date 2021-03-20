/*************************************************************************
 * gen-elf.hh -- This file is part of sasm.                              *
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

#ifndef _GEN_ELF_HH
#define _GEN_ELF_HH

#include <string>
#include <vector>
#include "elf.h"
#include "inst.hh"

class ELF32Section
{
public:
  Elf32_Word name;
  Elf32_Word type;
  Elf32_Word flags;
  Elf32_Word alignment;
  unsigned char link;
  unsigned char info;
  std::vector <unsigned char> data;

  ELF32Section (Elf32_Word name, Elf32_Word type, Elf32_Word flags,
		Elf32_Word alignment) :
    name (name), type (type), flags (flags), alignment (alignment),
    link (SHN_UNDEF), info (0) {}
  Elf32_Word add_string (std::string str);
  bool write (Elf32_Off offset, Elf32_Off header, FILE *stream);
};

class ELF32Object
{
  AsmContext ctx {4};
  std::vector <Elf32_Sym> local_symbols;
  std::vector <Elf32_Sym> global_symbols;
  std::vector <Elf32_Sym> weak_symbols;
  ELF32Section shstrtab {1, SHT_STRTAB, 0, 1};
  ELF32Section symtab {11, SHT_SYMTAB, 0, 4};
  ELF32Section strtab {19, SHT_STRTAB, 0, 1};

  Elf32_Word shstrtab_match (Elf32_Word start, const char *str);
  void fix_relocation_link_info (void);

public:
  std::vector <ELF32Section> shtable;

  ELF32Object (std::string filename);
  Elf32_Word add_section (std::string name, Elf32_Word type, Elf32_Word flags,
			  Elf32_Word addralign);
  Elf32_Word search_section (std::string name);
  Elf32_Word section_symbol (Elf32_Word section);
  bool assemble_inst (AsmInst *inst, Elf32_Word section);
  bool add_symbol (AsmLabel *sym);
  Elf32_Word relocate_from (Elf32_Word target, std::string section,
			    Elf32_Addr offset, unsigned char type);
  bool write (FILE *stream);
};

#endif
