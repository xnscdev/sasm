/*************************************************************************
 * inst-pop.cc -- This file is part of sasm.                             *
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
assemble_sreg (std::vector <unsigned char> &result,
	       const AsmContext &ctx, AsmRegister *op)
{
  switch (op->id)
    {
    case -4:
      result.push_back (ASM_OPCODE_POP_DS);
      return true;
    case -1:
      result.push_back (ASM_OPCODE_POP_ES);
      return true;
    case -5:
      result.push_back (ASM_OPCODE_2BYTE_INST);
      result.push_back (0xa1);
      return true;
    case -6:
      result.push_back (ASM_OPCODE_2BYTE_INST);
      result.push_back (0xa9);
      return true;
    case -3:
      result.push_back (ASM_OPCODE_POP_SS);
      return true;
    default:
      /* CS cannot be popped */
      return false;
    }
}

static bool
assemble_m (std::vector <unsigned char> &result,
	    const AsmContext &ctx, AsmMemoryLoc *op)
{
  if (op->width () == 1)
    return false; /* Cannot pop an 8-bit value */

  if (op->segment != default_segment (op))
    result.push_back (segment_prefix (op->segment));
  if (op->width () != ctx.bytes)
    result.push_back (ASM_OPCODE_OPSIZE_OVR);
  result.push_back (ASM_OPCODE_POP_RMX);
  if (!write_operand (AsmOpcodeExt::OE0, op, ctx, result))
    return false;
  return true;
}

size_t
AsmInstPOP::width (const AsmContext &ctx)
{
  if (ISINSTANCE (AsmImmediate *, op))
    {
      AsmImmediate *iop = CAST (AsmImmediate *, op);
      return iop->value < INT8_MIN || iop->value > INT8_MAX ? ctx.bytes + 1 : 2;
    }
  else if (ISINSTANCE (AsmRegister *, op))
    {
      AsmRegister *rop = CAST (AsmRegister *, op);
      if (rop->width () == 1)
	return 0;
      if (rop->id < 0)
	return rop->id == AsmRegister::FS->id
	  || rop->id == AsmRegister::GS->id ? 2 : 1;
      else
	return rop->width () != ctx.bytes ? 2 : 1;
    }
  else if (ISINSTANCE (AsmMemoryLoc *, op))
    {
      AsmMemoryLoc *loc = CAST (AsmMemoryLoc *, op);
      return 1 + operand_width (AsmOpcodeExt::OE6, loc, ctx) +
	(loc->segment != default_segment (loc)) + (loc->width () != ctx.bytes);
    }

  return 0;
}

bool
AsmInstPOP::assemble (std::vector <unsigned char> &result,
		      const AsmContext &ctx)
{
  if (ISINSTANCE (AsmRegister *, op))
    {
      AsmRegister *rop = CAST (AsmRegister *, op);
      if (rop->width () == 1)
	return false; /* Cannot pop an 8-bit value */
      if (rop->id < 0)
	return assemble_sreg (result, ctx, rop);
      else if (rop->width () != ctx.bytes)
	result.push_back (ASM_OPCODE_OPSIZE_OVR);
      result.push_back (ASM_OPCODE_POP_BASE + rop->id);
      return true;
    }
  else if (ISINSTANCE (AsmMemoryLoc *, op))
    return assemble_m (result, ctx, CAST (AsmMemoryLoc *, op));

  return false;
}
