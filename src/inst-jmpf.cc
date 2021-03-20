/*************************************************************************
 * inst-jmpf.cc -- This file is part of sasm.                            *
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

static bool
assemble_segaddr (std::vector <unsigned char> &result,
		  const AsmContext &ctx, unsigned char segment,
		  uint32_t addr)
{
  result.push_back (ASM_OPCODE_JMPF_PX);
  write_address (addr, ctx, result);
  write_int16_le (segment, result);
  return true;
}

static bool
assemble_m (std::vector <unsigned char> &result,
	    const AsmContext &ctx, AsmMemoryLoc *loc)
{
  if (loc->width () == 1)
    return false;
  if (loc->segment != default_segment (loc))
    result.push_back (segment_prefix (loc->segment));
  if (loc->width () != ctx.bytes)
    result.push_back (ASM_OPCODE_OPSIZE_OVR);
  result.push_back (ASM_OPCODE_JMP_RMX);
  return write_operand (AsmOpcodeExt::OE5, loc, ctx, result);
}

size_t
AsmInstJMPF::width (const AsmContext &ctx)
{
  if (op == nullptr)
    return ctx.bytes + 3;
  else
    {
      size_t pfsize = op != nullptr && op->segment != default_segment (op);
      return operand_width (AsmOpcodeExt::OE5, op, ctx) + pfsize +
	(op->width () != ctx.bytes ? 2 : 1);
    }
}

bool
AsmInstJMPF::assemble (std::vector <unsigned char> &result,
		       const AsmContext &ctx)
{
  if (op == nullptr)
    return assemble_segaddr (result, ctx, segment, addr);
  else
    return assemble_m (result, ctx, op);
}
