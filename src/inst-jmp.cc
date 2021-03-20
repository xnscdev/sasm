/*************************************************************************
 * inst-jmp.cc -- This file is part of sasm.                             *
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
assemble_rel (std::vector <unsigned char> &result,
	      const AsmContext &ctx, AsmPointer *addr, size_t size)
{
  long long rel = (long long) addr->get_addr () - curraddr;
  if (rel > INT8_MIN + 2 && rel < INT8_MAX - 2)
    {
      result.push_back (ASM_OPCODE_JMP_REL8);
      result.push_back ((unsigned char) addr->get_addr () -
			(unsigned char) curraddr);
      return true;
    }
  else
    {
      if (size == 1)
	return false;
      else if (size != ctx.bytes)
	result.push_back (ASM_OPCODE_OPSIZE_OVR);
      result.push_back (ASM_OPCODE_JMP_RELX);
      write_address (addr->get_addr () - curraddr, ctx, result);
      return true;
    }
}

static bool
assemble_rm (std::vector <unsigned char> &result,
	     const AsmContext &ctx, AsmStorage *op)
{
  if (op->width () == 1)
    return false;
  if (ISINSTANCE (AsmMemoryLoc *, op))
    {
      AsmMemoryLoc *loc = CAST (AsmMemoryLoc *, op);
      if (loc->segment != default_segment (loc))
	result.push_back (segment_prefix (loc->segment));
    }
  if (op->width () != ctx.bytes)
    result.push_back (ASM_OPCODE_OPSIZE_OVR);
  result.push_back (ASM_OPCODE_JMP_RMX);
  return write_operand (AsmOpcodeExt::OE4, op, ctx, result);
}

size_t
AsmInstJMP::width (const AsmContext &ctx)
{
  if (op == nullptr)
    {
      long long r = (long long) rel->get_addr () - curraddr;
      return r > INT8_MIN + 2 && r < INT8_MAX - 2 ? 2 : ctx.bytes +
	(size != ctx.bytes) + 1;
    }
  else
    {
      AsmMemoryLoc *l = CAST (AsmMemoryLoc *, op);
      size_t pfsize = l != nullptr && l->segment != default_segment (l);
      return operand_width (AsmOpcodeExt::OE4, op, ctx) + pfsize +
	(op->width () != ctx.bytes ? 2 : 1);
    }
}

bool
AsmInstJMP::assemble (std::vector <unsigned char> &result,
		      const AsmContext &ctx)
{
  if (op == nullptr)
    return assemble_rel (result, ctx, rel, size);
  else
    return assemble_rm (result, ctx, op);
}
