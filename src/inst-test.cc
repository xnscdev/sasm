/*************************************************************************
 * inst-test.cc -- This file is part of sasm.                            *
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
assemble_r_imm (std::vector <unsigned char> &result,
		const AsmContext &ctx, AsmRegister *dest, AsmImmediate *src)
{
  if (dest->id < 0)
    return false;
  if (dest->width () == 1)
    {
      if (dest->id == AsmRegister::EAX->id)
	result.push_back (ASM_OPCODE_TEST_AL_IMM8);
      else
	{
	  result.push_back (ASM_OPCODE_TEST_RM_IMM8);
	  if (!write_operand (AsmOpcodeExt::OE0, dest, ctx, result))
	    return false;
	}
      result.push_back (src->value & 0xff);
      return true;
    }
  else
    {
      if (dest->width () != ctx.bytes)
	result.push_back (ASM_OPCODE_OPSIZE_OVR);
      if (dest->id == AsmRegister::EAX->id)
	{
	  result.push_back (ASM_OPCODE_TEST_AX_IMMX);
	  write_imm (src->value, dest->width (), result);
	}
      else
	{
	  result.push_back (ASM_OPCODE_TEST_RM_IMMX);
	  if (!write_operand (AsmOpcodeExt::OE0, dest, ctx, result))
	    return false;
	  write_imm (src->value, dest->width (), result);
	}
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
    result.push_back (ASM_OPCODE_TEST_RM_R8);
  else
    {
      if (dest->width () != ctx.bytes)
	result.push_back (ASM_OPCODE_OPSIZE_OVR);
      result.push_back (ASM_OPCODE_TEST_RM_RX);
    }
  return write_operand (src, dest, ctx, result);
}

static bool
assemble_m_imm (std::vector <unsigned char> &result,
		const AsmContext &ctx, AsmMemoryLoc *dest, AsmImmediate *src)
{
  if (dest->segment != default_segment (dest))
    result.push_back (segment_prefix (dest->segment));

  if (dest->width () == 1)
    {
      result.push_back (ASM_OPCODE_TEST_RM_IMM8);
      if (!write_operand (AsmOpcodeExt::OE0, dest, ctx, result))
	return false;
      result.push_back (src->value & 0xff);
      return true;
    }
  else
    {
      if (dest->width () != ctx.bytes)
	result.push_back (ASM_OPCODE_OPSIZE_OVR);
      result.push_back (ASM_OPCODE_TEST_RM_IMMX);
      if (!write_operand (AsmOpcodeExt::OE0, dest, ctx, result))
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
      result.push_back (ASM_OPCODE_TEST_RM_R8);
      return write_operand (src, dest, ctx, result);
    }
  else
    {
      if (src->width () != ctx.bytes)
	result.push_back (ASM_OPCODE_OPSIZE_OVR);
      result.push_back (ASM_OPCODE_TEST_RM_RX);
      return write_operand (src, dest, ctx, result);
    }
}

size_t
AsmInstTEST::width (const AsmContext &ctx)
{
  if (ISINSTANCE (AsmRegister *, dest))
    {
      AsmRegister *r = CAST (AsmRegister *, dest);
      if (ISINSTANCE (AsmImmediate *, src))
	{
	  AsmImmediate *isrc = CAST (AsmImmediate *, src);
	  if (r->width () == 1)
	    return (r->id == AsmRegister::EAX->id ? 1 : 1 +
		    operand_width (AsmOpcodeExt::OE0, r, ctx)) + 1;
	  else
	    return (r->width () != ctx.bytes) +
	      (r->id == AsmRegister::EAX->id ? r->width () :
	       operand_width (AsmOpcodeExt::OE0, r, ctx) +
	       (isrc->value < INT8_MIN || isrc->value > INT8_MAX ?
	        r->width () : 1)) + 1;
	}
      else if (ISINSTANCE (AsmStorage *, src))
	return operand_width (r, CAST (AsmStorage *, src), ctx) +
	  (r->width () != 1 && r->width () != ctx.bytes ? 2 : 1);
    }
  else if (ISINSTANCE (AsmMemoryLoc *, dest))
    {
      AsmMemoryLoc *l = CAST (AsmMemoryLoc *, dest);
      size_t pfsize = l->segment != default_segment (l);
      if (ISINSTANCE (AsmImmediate *, src))
	{
	  AsmImmediate *isrc = CAST (AsmImmediate *, src);
	  return operand_width (AsmOpcodeExt::OE0, dest, ctx) +
	    (dest->width () == 1 ? 1 : (dest->width () != ctx.bytes) +
	     (isrc->value < INT8_MIN || isrc->value > INT8_MAX ? l->width () :
	      1)) + pfsize + 1;
	}
      else if (ISINSTANCE (AsmRegister *, src))
	{
	  AsmRegister *r = CAST (AsmRegister *, src);
	  size_t opsize = r->width () != 1 && r->width () != ctx.bytes ? 2 : 1;
	  return operand_width (r, l, ctx) + opsize + pfsize;
	}
    }

  return 0;
}

bool
AsmInstTEST::assemble (std::vector <unsigned char> &result,
		       const AsmContext &ctx)
{
  if (ISINSTANCE (AsmRegister *, dest))
    {
      AsmRegister *rdest = CAST (AsmRegister *, dest);
      if (rdest->id < 0)
	return false;
      else if (ISINSTANCE (AsmImmediate *, src))
	return assemble_r_imm (result, ctx, rdest, CAST (AsmImmediate *, src));
      else if (ISINSTANCE (AsmRegister *, src))
	{
	  AsmRegister *rsrc = CAST (AsmRegister *, src);
	  if (rsrc->id < 0)
	    return false;
	  return assemble_r_r (result, ctx, rdest, rsrc);
	}
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
	    return false;
	  return assemble_m_r (result, ctx, memloc, rsrc);
	}
    }

  return false;
}
