/*************************************************************************
 * inst-mul.cc -- This file is part of sasm.                             *
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
AsmInstMUL::width (const AsmContext &ctx)
{
  size_t pfsize = 0;
  if (ISINSTANCE (AsmMemoryLoc *, op))
    {
      AsmMemoryLoc *l = CAST (AsmMemoryLoc *, op);
      pfsize = l->segment != default_segment (l);
    }
  return (op->width () != 1 && op->width () != ctx.bytes ? 2 : 1) +
    operand_width (AsmOpcodeExt::OE4, op, ctx) + pfsize;
}

bool
AsmInstMUL::assemble (std::vector <unsigned char> &result,
		      const AsmContext &ctx)
{
  if (ISINSTANCE (AsmRegister *, op))
    {
      if (CAST (AsmRegister *, op)->id < 0)
	return false;
    }
  else if (ISINSTANCE (AsmMemoryLoc *, op))
    {
      AsmMemoryLoc *loc = CAST (AsmMemoryLoc *, op);
      if (loc->segment != default_segment (loc))
	result.push_back (segment_prefix (loc->segment));
    }
  else
    return false;

  if (op->width () == 1)
    result.push_back (ASM_OPCODE_MUL_AX_AL);
  else
    {
      if (op->width () != ctx.bytes)
	result.push_back (ASM_OPCODE_OPSIZE_OVR);
      result.push_back (ASM_OPCODE_MUL_DX_AX);
    }
  return write_operand (AsmOpcodeExt::OE4, op, ctx, result);
}
