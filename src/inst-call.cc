/*************************************************************************
 * inst-call.cc -- This file is part of sasm.                            *
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
#include "inst.hh"
#include "opcodes.h"
#include "util.hh"

static bool
assemble_rel (std::vector <unsigned char> &result,
	      const AsmContext &ctx, AsmPointer *rel, size_t size)
{
  if (size == 1)
    return false;
  else if (size != ctx.bytes)
    result.push_back (ASM_OPCODE_OPSIZE_OVR);
  result.push_back (ASM_OPCODE_CALL_RELX);
  write_address (rel->get_addr () - curraddr, ctx, result);
  mark_reloc (curraddr - ctx.bytes);
  return true;
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
  result.push_back (ASM_OPCODE_CALL_RMX);
  return write_operand (AsmOpcodeExt::OE2, op, ctx, result);
}

size_t
AsmInstCALL::width (const AsmContext &ctx)
{
  if (op == nullptr)
    return ctx.bytes + (size != ctx.bytes) + 1;
  else
    {
      AsmMemoryLoc *l = CAST (AsmMemoryLoc *, op);
      size_t pfsize = l != nullptr && l->segment != default_segment (l);
      return operand_width (AsmOpcodeExt::OE2, op, ctx) + pfsize +
	(op->width () != ctx.bytes ? 2 : 1);
    }
}

bool
AsmInstCALL::assemble (std::vector <unsigned char> &result,
		       const AsmContext &ctx)
{
  if (op == nullptr)
    return assemble_rel (result, ctx, rel, size);
  else
    return assemble_rm (result, ctx, op);
}
