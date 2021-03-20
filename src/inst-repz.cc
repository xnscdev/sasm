/*************************************************************************
 * inst-repz.cc -- This file is part of sasm.                            *
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

#include "inst.hh"
#include "opcodes.h"
#include "util.hh"

size_t
AsmInstREPZ::width (const AsmContext &ctx)
{
  return inst->width (ctx) + 1;
}

bool
AsmInstREPZ::assemble (std::vector <unsigned char> &result,
		       const AsmContext &ctx)
{
  result.push_back (ASM_OPCODE_REPZ);
  return inst->assemble (result, ctx);
}
