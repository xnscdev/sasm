/*************************************************************************
 * inst-mov.cc -- This file is part of sasm.                             *
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
assemble_sreg_rm (std::vector <unsigned char> &result,
		  const AsmContext &ctx, AsmRegister *dest, AsmExpr *src)
{
  if (!ISINSTANCE (AsmStorage *, src))
    return false;
  if (ISINSTANCE (AsmRegister *, src))
    {
      AsmRegister *rsrc = CAST (AsmRegister *, src);
      if (rsrc->id < 0)
	return false;
    }

  AsmStorage *st = CAST (AsmStorage *, src);
  if (st->width () != 2)
    return false;
  if (ISINSTANCE (AsmMemoryLoc *, st))
    {
      AsmMemoryLoc *loc = CAST (AsmMemoryLoc *, st);
      if (loc->segment != default_segment (loc))
	result.push_back (segment_prefix (loc->segment));
    }
  result.push_back (ASM_OPCODE_MOV_SREG_RM16);
  return write_operand (dest, st, ctx, result);
}

static bool
assemble_rm_sreg (std::vector <unsigned char> &result,
		  const AsmContext &ctx, AsmStorage *dest, AsmRegister *src)
{
  if (ISINSTANCE (AsmMemoryLoc *, dest))
    {
      AsmMemoryLoc *loc = CAST (AsmMemoryLoc *, dest);
      if (loc->segment != default_segment (loc))
	result.push_back (segment_prefix (loc->segment));
    }
  if (ISINSTANCE (AsmRegister *, dest) && dest->width () != ctx.bytes)
    result.push_back (ASM_OPCODE_OPSIZE_OVR);
  result.push_back (ASM_OPCODE_MOV_RM16_SREG);
  return write_operand (src, dest, ctx, result);
}

static bool
assemble_r_imm (std::vector <unsigned char> &result,
		const AsmContext &ctx, AsmRegister *dest, AsmImmediate *src)
{
  if (dest->id < 0)
    return false;
  if (dest->width () == 1)
    {
      result.push_back (ASM_OPCODE_MOV_R_IMM8_BASE + dest->id);
      result.push_back (src->value & 0xff);
      return true;
    }
  else
    {
      if (dest->width () != ctx.bytes)
	result.push_back (ASM_OPCODE_OPSIZE_OVR);
      result.push_back (ASM_OPCODE_MOV_R_IMMX_BASE + dest->id);
      write_imm (src->value, dest->width (), result);
      return true;
    }
}

static bool
assemble_r_r (std::vector <unsigned char> &result,
	      const AsmContext &ctx, AsmRegister *dest, AsmRegister *src)
{
  if (dest->width () != src->width ())
    return false; /* Mismatched operand sizes */
  if (dest->id < 0 || src->id < 0)
    return false;

  if (dest->width () == 1)
    result.push_back (ASM_OPCODE_MOV_RM_R8);
  else
    {
      if (dest->width () != ctx.bytes)
	result.push_back (ASM_OPCODE_OPSIZE_OVR);
      result.push_back (ASM_OPCODE_MOV_RM_RX);
    }
  return write_operand (src, dest, ctx, result);
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
      if (dest->id == 0 && src->base == nullptr && src->index == nullptr)
        {
	  result.push_back (ASM_OPCODE_MOV_AL_MOFFS8);
	  write_address (src->disp, ctx, result);
	  mark_reloc (curraddr +
		      (src->segment != default_segment (src) ? 2 : 1));
	  return true;
	}
      else
        {
	  result.push_back (ASM_OPCODE_MOV_R_RM8);
	  return write_operand (dest, src, ctx, result);
	}
    }
  else
    {
      if (dest->width () != ctx.bytes)
	result.push_back (ASM_OPCODE_OPSIZE_OVR);
      if (dest->id == 0 && src->base == nullptr && src->index == nullptr)
        {
	  result.push_back (ASM_OPCODE_MOV_AX_MOFFSX);
	  write_address (src->disp, ctx, result);
	  mark_reloc (curraddr + 1 +
		      (src->segment != default_segment (src)) +
		      (dest->width () != ctx.bytes));
	  return true;
	}
      else
        {
	  result.push_back (ASM_OPCODE_MOV_R_RMX);
	  return write_operand (dest, src, ctx, result);
	}
    }
}

static bool
assemble_m_imm (std::vector <unsigned char> &result,
		const AsmContext &ctx, AsmMemoryLoc *dest, AsmImmediate *src)
{
  if (dest->segment != default_segment (dest))
    result.push_back (segment_prefix (dest->segment));

  if (dest->width () == 1)
    {
      result.push_back (ASM_OPCODE_MOV_RM_IMM8);
      if (!write_operand (nullptr, dest, ctx, result))
	return false;
      result.push_back (src->value & 0xff);
      return true;
    }
  else
    {
      if (dest->width () != ctx.bytes)
	result.push_back (ASM_OPCODE_OPSIZE_OVR);
      result.push_back (ASM_OPCODE_MOV_RM_IMMX);
      if (!write_operand (nullptr, dest, ctx, result))
	return false;
      write_imm (src->value, dest->width (), result);
      return true;
    }
}

static bool
assemble_m_r (std::vector <unsigned char> &result,
	      const AsmContext &ctx, AsmMemoryLoc *dest, AsmRegister *src)
{
  if (dest->width () != src->width ())
    return false; /* Mismatched operand sizes */
  if (src->id < 0)
    return false;

  if (dest->segment != default_segment (dest))
    result.push_back (segment_prefix (dest->segment));

  if (src->width () == 1)
    {
      if (src->id == 0 && dest->base == nullptr && dest->index == nullptr)
        {
	  result.push_back (ASM_OPCODE_MOV_MOFFS8_AL);
	  write_address (dest->disp, ctx, result);
	  mark_reloc (curraddr +
		      (dest->segment != default_segment (dest) ? 2 : 1));
	  return true;
	}
      else
        {
	  result.push_back (ASM_OPCODE_MOV_RM_R8);
	  return write_operand (src, dest, ctx, result);
	}
    }
  else
    {
      if (src->width () != ctx.bytes)
	result.push_back (ASM_OPCODE_OPSIZE_OVR);
      if (src->id == 0 && dest->base == nullptr && dest->index == nullptr)
        {
	  result.push_back (ASM_OPCODE_MOV_MOFFSX_AX);
	  write_address (dest->disp, ctx, result);
	  mark_reloc (curraddr + 1 +
		      (dest->segment != default_segment (dest)) +
		      (src->width () != ctx.bytes));
	  return true;
	}
      else
        {
	  result.push_back (ASM_OPCODE_MOV_RM_RX);
	  return write_operand (src, dest, ctx, result);
	}
    }
}

size_t
AsmInstMOV::width (const AsmContext &ctx)
{
  if (ISINSTANCE (AsmRegister *, dest))
    {
      AsmRegister *r = CAST (AsmRegister *, dest);
      if (ISINSTANCE (AsmImmediate *, src))
        return r->width () +
	  (r->width () != 1 && r->width () != ctx.bytes ? 2 : 1);
      else if (ISINSTANCE (AsmStorage *, src))
	{
	  size_t opsize;
	  if ((ISINSTANCE (AsmRegister *, dest)
	       && CAST (AsmRegister *, dest)->id < 0)
	      || (ISINSTANCE (AsmRegister *, src)
		  && CAST (AsmRegister *, src)->id < 0))
	    opsize = 1;
	  else
	    opsize = r->width () != 1 && r->width () != ctx.bytes ? 2 : 1;
	  if (ISINSTANCE (AsmMemoryLoc *, src))
	    {
	      AsmMemoryLoc *loc = CAST (AsmMemoryLoc *, src);
	      if (loc->segment != default_segment (loc))
		opsize++;
	    }
	  return operand_width (r, CAST (AsmStorage *, src), ctx) + opsize;
	}
    }
  else if (ISINSTANCE (AsmMemoryLoc *, dest))
    {
      AsmMemoryLoc *l = CAST (AsmMemoryLoc *, dest);
      size_t pfsize = l->segment != default_segment (l);
      if (ISINSTANCE (AsmImmediate *, src))
	return ctx.bytes + l->width () + pfsize +
	  (l->width () != 1 && l->width () != ctx.bytes ? 3 : 2);
      else if (ISINSTANCE (AsmRegister *, src))
	{
	  AsmRegister *r = CAST (AsmRegister *, src);
	  size_t opsize;
	  if (r->id < 0)
	    opsize = 1;
	  else
	    opsize = r->width () != 1 && r->width () != ctx.bytes ? 2 : 1;
	  return operand_width (r, l, ctx) + opsize + pfsize;
	}
    }

  return 0;
}

bool
AsmInstMOV::assemble (std::vector <unsigned char> &result,
		      const AsmContext &ctx)
{
  if (ISINSTANCE (AsmRegister *, dest))
    {
      AsmRegister *rdest = CAST (AsmRegister *, dest);
      if (rdest->id < 0)
	return assemble_sreg_rm (result, ctx, rdest, src);
      else if (ISINSTANCE (AsmImmediate *, src))
	return assemble_r_imm (result, ctx, rdest, CAST (AsmImmediate *, src));
      else if (ISINSTANCE (AsmRegister *, src))
	{
	  AsmRegister *rsrc = CAST (AsmRegister *, src);
	  if (rsrc->id < 0)
	    return assemble_rm_sreg (result, ctx, rdest, rsrc);
	  else
	    return assemble_r_r (result, ctx, rdest, rsrc);
	}
      else if (ISINSTANCE (AsmMemoryLoc *, src))
	return assemble_r_m (result, ctx, rdest, CAST (AsmMemoryLoc *, src));
    }
  else if (ISINSTANCE (AsmMemoryLoc *, dest))
    {
      AsmMemoryLoc *memloc = CAST (AsmMemoryLoc *, dest);
      if (ISINSTANCE (AsmImmediate *, src))
	return assemble_m_imm (result, ctx, memloc, CAST (AsmImmediate *, src));
      else if (ISINSTANCE (AsmRegister *, src))
	{
	  AsmRegister *rsrc = CAST (AsmRegister *, src);
	  if (rsrc->id < 0)
	    return assemble_rm_sreg (result, ctx, memloc, rsrc);
	  else
	    return assemble_m_r (result, ctx, memloc, rsrc);
	}
    }

  return false;
}
