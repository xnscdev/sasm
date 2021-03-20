/*************************************************************************
 * inst-inc.cc -- This file is part of sasm.                             *
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
AsmInstINC::width (const AsmContext &ctx)
{
  if (ISINSTANCE (AsmRegister *, op))
    {
      AsmRegister *r = CAST (AsmRegister *, op);
      return r->width () == 1 || r->width () != ctx.bytes ? 2 : 1;
    }
  else if (ISINSTANCE (AsmMemoryLoc *, op))
    {
      AsmMemoryLoc *l = CAST (AsmMemoryLoc *, op);
      return operand_width (AsmOpcodeExt::OE0, op, ctx) +
	(l->segment != default_segment (l) ? 2 : 1) +
	(l->width () != 1 && l->width () != ctx.bytes);
    }

  return 0;
}

bool
AsmInstINC::assemble (std::vector <unsigned char> &result,
		      const AsmContext &ctx)
{
  if (ISINSTANCE (AsmRegister *, op))
    {
      AsmRegister *rop = CAST (AsmRegister *, op);
      if (rop->id < 0)
	return false;
      if (rop->width () == 1)
	{
	  result.push_back (ASM_OPCODE_INCDEC_RM8);
	  return write_operand (AsmOpcodeExt::OE0, op, ctx, result);
	}
      else
	{
	  if (rop->width () != ctx.bytes)
	    result.push_back (ASM_OPCODE_OPSIZE_OVR);
	  result.push_back (ASM_OPCODE_INC_BASE + rop->id);
	  return true;
	}
    }
  else if (ISINSTANCE (AsmMemoryLoc *, op))
    {
      AsmMemoryLoc *memloc = CAST (AsmMemoryLoc *, op);
      if (memloc->segment != default_segment (memloc))
	result.push_back (segment_prefix (memloc->segment));
      if (memloc->width () == 1)
	result.push_back (ASM_OPCODE_INCDEC_RM8);
      else
	{
	  if (memloc->width () != ctx.bytes)
	    result.push_back (ASM_OPCODE_OPSIZE_OVR);
	  result.push_back (ASM_OPCODE_INCDEC_RMX);
	}
      return write_operand (AsmOpcodeExt::OE0, op, ctx, result);
    }

  return false;
}
