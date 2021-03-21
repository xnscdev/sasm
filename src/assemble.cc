/*************************************************************************
 * assemble.cc -- This file is part of sasm.                             *
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

extern Object *result;

uint32_t curraddr;
uint32_t reloc_inst;
std::string reloc_section;
bool reloc;

bool
assemble (AsmInst *inst, std::vector <unsigned char> &result,
	  const AsmContext &ctx)
{
  curraddr += inst->width (ctx);
  return inst->assemble (result, ctx);
}

void
mark_reloc (uint32_t ip)
{
  std::string test = result->section_from_addr (ip);
  if (test != result->section)
    {
      reloc_inst = ip;
      reloc_section = test;
      reloc = true;
    }
}
