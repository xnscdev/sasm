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

uint32_t curraddr;

static uint32_t reloc_inst;
static bool reloc;

bool
assemble (AsmInst *inst, std::vector <unsigned char> &result,
	  const AsmContext &ctx)
{
  curraddr += inst->width (ctx);
  bool ret = inst->assemble (result, ctx);
  if (reloc)
    ; /* TODO Add relocation entry */
  reloc = false;
  return ret;
}

void
mark_reloc (uint32_t ip)
{
  reloc_inst = ip;
  reloc = true;
}
