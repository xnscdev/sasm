/*************************************************************************
 * inst-push.cc -- This file is part of sasm.                            *
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
assemble_imm (std::vector <unsigned char> &result,
	      const AsmContext &ctx, AsmImmediate *op)
{
  if (op->value < INT8_MIN || op->value > INT8_MAX)
    {
      result.push_back (ASM_OPCODE_PUSH_IMMX);
      switch (ctx.bytes)
	{
	case 2:
	  write_int16_le (op->value & 0xffff, result);
	  return true;
	case 4:
	  write_int32_le (op->value & 0xffffffff, result);
	  return true;
	default:
	  return false;
	}
      return true;
    }
  else
    {
      result.push_back (ASM_OPCODE_PUSH_IMM8);
      result.push_back (op->value & 0xff);
      return true;
    }
}

static bool
assemble_sreg (std::vector <unsigned char> &result,
	       const AsmContext &ctx, AsmRegister *op)
{
  switch (op->id)
    {
    case -2:
      result.push_back (ASM_OPCODE_PUSH_CS);
      return true;
    case -4:
      result.push_back (ASM_OPCODE_PUSH_DS);
      return true;
    case -1:
      result.push_back (ASM_OPCODE_PUSH_ES);
      return true;
    case -5:
      result.push_back (ASM_OPCODE_2BYTE_INST);
      result.push_back (0xa0);
      return true;
    case -6:
      result.push_back (ASM_OPCODE_2BYTE_INST);
      result.push_back (0xa8);
      return true;
    case -3:
      result.push_back (ASM_OPCODE_PUSH_SS);
      return true;
    default:
      return false;
    }
}

static bool
assemble_m (std::vector <unsigned char> &result,
	    const AsmContext &ctx, AsmMemoryLoc *op)
{
  if (op->width () == 1)
    return false; /* Cannot push an 8-bit value */

  if (op->segment != default_segment (op))
    result.push_back (segment_prefix (op->segment));
  if (op->width () != ctx.bytes)
    result.push_back (ASM_OPCODE_OPSIZE_OVR);
  result.push_back (ASM_OPCODE_PUSH_RMX);
  if (!write_operand (AsmOpcodeExt::OE6, op, ctx, result))
    return false;
  return true;
}

size_t
AsmInstPUSH::width (const AsmContext &ctx)
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
AsmInstPUSH::assemble (std::vector <unsigned char> &result,
		       const AsmContext &ctx)
{
  if (ISINSTANCE (AsmImmediate *, op))
    return assemble_imm (result, ctx, CAST (AsmImmediate *, op));
  else if (ISINSTANCE (AsmRegister *, op))
    {
      AsmRegister *rop = CAST (AsmRegister *, op);
      if (rop->width () == 1)
	return false; /* Cannot push an 8-bit value */
      if (rop->id < 0)
	return assemble_sreg (result, ctx, rop);
      else if (rop->width () != ctx.bytes)
	result.push_back (ASM_OPCODE_OPSIZE_OVR);
      result.push_back (ASM_OPCODE_PUSH_BASE + rop->id);
      return true;
    }
  else if (ISINSTANCE (AsmMemoryLoc *, op))
    return assemble_m (result, ctx, CAST (AsmMemoryLoc *, op));

  return false;
}
