/*************************************************************************
 * inst-xchg.cc -- This file is part of sasm.                            *
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
assemble_r_r (std::vector <unsigned char> &result,
	      const AsmContext &ctx, AsmRegister *dest, AsmRegister *src)
{
  if (dest->width () != src->width ())
    return false; /* Mismatched operand sizes */
  if (dest->id < 0 || src->id < 0)
    return false;

  if (dest->width () == 1)
    {
      result.push_back (ASM_OPCODE_XCHG_R_RM8);
      return write_operand (src, dest, ctx, result);
    }
  else
    {
      if (dest->width () != ctx.bytes)
	result.push_back (ASM_OPCODE_OPSIZE_OVR);
      if (dest->id == AsmRegister::EAX->id)
	result.push_back (ASM_OPCODE_XCHG_BASE + src->id);
      else if (src->id == AsmRegister::EAX->id)
	result.push_back (ASM_OPCODE_XCHG_BASE + dest->id);
      return true;
    }
}

static bool
assemble_r_m (std::vector <unsigned char> &result,
	      const AsmContext &ctx, AsmRegister *dest, AsmMemoryLoc *src)
{
  if (dest->width () != src->width ())
    return false; /* Mismatched operand sizes */
  if (dest->id < 0)
    return false;

  if (src->segment != default_segment (src))
    result.push_back (segment_prefix (src->segment));

  if (dest->width () == 1)
    {
      result.push_back (ASM_OPCODE_XCHG_R_RM8);
      return write_operand (dest, src, ctx, result);
    }
  else
    {
      if (dest->width () != ctx.bytes)
	result.push_back (ASM_OPCODE_OPSIZE_OVR);
      result.push_back (ASM_OPCODE_XCHG_R_RMX);
      return write_operand (dest, src, ctx, result);
    }
}

size_t
AsmInstXCHG::width (const AsmContext &ctx)
{
  if (ISINSTANCE (AsmRegister *, dest))
    {
      AsmRegister *r = CAST (AsmRegister *, dest);
      size_t opsize = r->width () != 1 && r->width () != ctx.bytes ? 2 : 1;
      if (ISINSTANCE (AsmMemoryLoc *, src))
	{
	  AsmMemoryLoc *loc = CAST (AsmMemoryLoc *, src);
	  if (loc->segment != default_segment (loc))
	    opsize++;
	}
      else if (ISINSTANCE (AsmRegister *, src))
        {
	  if (CAST (AsmRegister *, src)->id == AsmRegister::EAX->id
	      || r->id == AsmRegister::EAX->id)
	    return opsize;
	}
      return operand_width (r, src, ctx) + opsize;
    }
  else if (ISINSTANCE (AsmMemoryLoc *, dest))
    {
      AsmMemoryLoc *l = CAST (AsmMemoryLoc *, dest);
      size_t pfsize = l->segment != default_segment (l);
      if (ISINSTANCE (AsmRegister *, src))
	{
	  AsmRegister *r = CAST (AsmRegister *, src);
	  size_t opsize = r->width () != 1 && r->width () != ctx.bytes ? 2 : 1;
	  return operand_width (r, l, ctx) + opsize + pfsize;
	}
    }

  return 0;
}

bool
AsmInstXCHG::assemble (std::vector <unsigned char> &result,
		       const AsmContext &ctx)
{
  if (ISINSTANCE (AsmRegister *, dest))
    {
      AsmRegister *rdest = CAST (AsmRegister *, dest);
      if (rdest->id < 0)
	return false;
      if (ISINSTANCE (AsmRegister *, src))
	{
	  AsmRegister *rsrc = CAST (AsmRegister *, src);
	  if (rsrc->id < 0)
	    return false;
	  return assemble_r_r (result, ctx, rdest, rsrc);
	}
      else if (ISINSTANCE (AsmMemoryLoc *, src))
	return assemble_r_m (result, ctx, rdest, CAST (AsmMemoryLoc *, src));
    }
  else if (ISINSTANCE (AsmMemoryLoc *, dest))
    {
      AsmMemoryLoc *memloc = CAST (AsmMemoryLoc *, dest);
      if (ISINSTANCE (AsmRegister *, src))
	{
	  AsmRegister *rsrc = CAST (AsmRegister *, src);
	  if (rsrc->id < 0)
	    return false;
	  return assemble_r_m (result, ctx, rsrc, memloc);
	}
    }

  return false;
}
