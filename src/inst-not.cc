/*************************************************************************
 * inst-not.cc -- This file is part of sasm.                             *
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
AsmInstNOT::width (const AsmContext &ctx)
{
  size_t pfsize = 0;
  if (ISINSTANCE (AsmMemoryLoc *, op))
    {
      AsmMemoryLoc *loc = CAST (AsmMemoryLoc *, op);
      pfsize = loc->segment != default_segment (loc);
    }
  return operand_width (AsmOpcodeExt::OE2, op, ctx) + pfsize +
    (op->width () != 1 && op->width () != ctx.bytes ? 2 : 1); 
}

bool
AsmInstNOT::assemble (std::vector <unsigned char> &result,
		      const AsmContext &ctx)
{
  if (ISINSTANCE (AsmRegister *, op))
    {
      AsmRegister *rop = CAST (AsmRegister *, op);
      if (rop->id < 0)
	return false;
    }
  else if (ISINSTANCE (AsmMemoryLoc *, op))
    {
      AsmMemoryLoc *loc = CAST (AsmMemoryLoc *, op);
      if (loc->segment != default_segment (loc))
	result.push_back (segment_prefix (loc->segment));
    }

  if (op->width () == 1)
    result.push_back (ASM_OPCODE_NOT_RM8);
  else
    {
      if (op->width () != ctx.bytes)
	result.push_back (ASM_OPCODE_OPSIZE_OVR);
      result.push_back (ASM_OPCODE_NOT_RMX);
    }
  return write_operand (AsmOpcodeExt::OE2, op, ctx, result);
}
