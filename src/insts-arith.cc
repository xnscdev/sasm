/*************************************************************************
 * insts-arith.cc -- This file is part of sasm.                          *
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

static unsigned char
arith_al_imm8_opcode (AsmInstARITHType type)
{
  switch (type)
    {
    case AsmInstARITHType::ADC:
      return ASM_OPCODE_ADC_AL_IMM8;
    case AsmInstARITHType::ADD:
      return ASM_OPCODE_ADD_AL_IMM8;
    case AsmInstARITHType::AND:
      return ASM_OPCODE_AND_AL_IMM8;
    case AsmInstARITHType::CMP:
      return ASM_OPCODE_CMP_AL_IMM8;
    case AsmInstARITHType::OR:
      return ASM_OPCODE_OR_AL_IMM8;
    case AsmInstARITHType::SBB:
      return ASM_OPCODE_SBB_AL_IMM8;
    case AsmInstARITHType::SUB:
      return ASM_OPCODE_SUB_AL_IMM8;
    case AsmInstARITHType::XOR:
      return ASM_OPCODE_XOR_AL_IMM8;
    default:
      return 0;
    }
}

static unsigned char
arith_ax_immx_opcode (AsmInstARITHType type)
{
  switch (type)
    {
    case AsmInstARITHType::ADC:
      return ASM_OPCODE_ADC_AX_IMMX;
    case AsmInstARITHType::ADD:
      return ASM_OPCODE_ADD_AX_IMMX;
    case AsmInstARITHType::AND:
      return ASM_OPCODE_AND_AX_IMMX;
    case AsmInstARITHType::CMP:
      return ASM_OPCODE_CMP_AX_IMMX;
    case AsmInstARITHType::OR:
      return ASM_OPCODE_OR_AX_IMMX;
    case AsmInstARITHType::SBB:
      return ASM_OPCODE_SBB_AX_IMMX;
    case AsmInstARITHType::SUB:
      return ASM_OPCODE_SUB_AX_IMMX;
    case AsmInstARITHType::XOR:
      return ASM_OPCODE_XOR_AX_IMMX;
    default:
      return 0;
    }
}

static unsigned char
arith_rm_r8_opcode (AsmInstARITHType type)
{
  switch (type)
    {
    case AsmInstARITHType::ADC:
      return ASM_OPCODE_ADC_RM_R8;
    case AsmInstARITHType::ADD:
      return ASM_OPCODE_ADD_RM_R8;
    case AsmInstARITHType::AND:
      return ASM_OPCODE_AND_RM_R8;
    case AsmInstARITHType::CMP:
      return ASM_OPCODE_CMP_RM_R8;
    case AsmInstARITHType::OR:
      return ASM_OPCODE_OR_RM_R8;
    case AsmInstARITHType::SBB:
      return ASM_OPCODE_SBB_RM_R8;
    case AsmInstARITHType::SUB:
      return ASM_OPCODE_SUB_RM_R8;
    case AsmInstARITHType::XOR:
      return ASM_OPCODE_XOR_RM_R8;
    default:
      return 0;
    }
}

static unsigned char
arith_rm_rx_opcode (AsmInstARITHType type)
{
  switch (type)
    {
    case AsmInstARITHType::ADC:
      return ASM_OPCODE_ADC_RM_RX;
    case AsmInstARITHType::ADD:
      return ASM_OPCODE_ADD_RM_RX;
    case AsmInstARITHType::AND:
      return ASM_OPCODE_AND_RM_RX;
    case AsmInstARITHType::CMP:
      return ASM_OPCODE_CMP_RM_RX;
    case AsmInstARITHType::OR:
      return ASM_OPCODE_OR_RM_RX;
    case AsmInstARITHType::SBB:
      return ASM_OPCODE_SBB_RM_RX;
    case AsmInstARITHType::SUB:
      return ASM_OPCODE_SUB_RM_RX;
    case AsmInstARITHType::XOR:
      return ASM_OPCODE_XOR_RM_RX;
    default:
      return 0;
    }
}

static unsigned char
arith_r_rm8_opcode (AsmInstARITHType type)
{
  switch (type)
    {
    case AsmInstARITHType::ADC:
      return ASM_OPCODE_ADC_R_RM8;
    case AsmInstARITHType::ADD:
      return ASM_OPCODE_ADD_R_RM8;
    case AsmInstARITHType::AND:
      return ASM_OPCODE_AND_R_RM8;
    case AsmInstARITHType::CMP:
      return ASM_OPCODE_CMP_R_RM8;
    case AsmInstARITHType::OR:
      return ASM_OPCODE_OR_R_RM8;
    case AsmInstARITHType::SBB:
      return ASM_OPCODE_SBB_R_RM8;
    case AsmInstARITHType::SUB:
      return ASM_OPCODE_SUB_R_RM8;
    case AsmInstARITHType::XOR:
      return ASM_OPCODE_XOR_R_RM8;
    default:
      return 0;
    }
}

static unsigned char
arith_r_rmx_opcode (AsmInstARITHType type)
{
  switch (type)
    {
    case AsmInstARITHType::ADC:
      return ASM_OPCODE_ADC_R_RMX;
    case AsmInstARITHType::ADD:
      return ASM_OPCODE_ADD_R_RMX;
    case AsmInstARITHType::AND:
      return ASM_OPCODE_AND_R_RMX;
    case AsmInstARITHType::CMP:
      return ASM_OPCODE_CMP_R_RMX;
    case AsmInstARITHType::OR:
      return ASM_OPCODE_OR_R_RMX;
    case AsmInstARITHType::SBB:
      return ASM_OPCODE_SBB_R_RMX;
    case AsmInstARITHType::SUB:
      return ASM_OPCODE_SUB_R_RMX;
    case AsmInstARITHType::XOR:
      return ASM_OPCODE_XOR_R_RMX;
    default:
      return 0;
    }
}

static AsmRegister *
arith_opcode_ext (AsmInstARITHType type)
{
  switch (type)
    {
    case AsmInstARITHType::ADC:
      return AsmOpcodeExt::OE2;
    case AsmInstARITHType::ADD:
      return AsmOpcodeExt::OE0;
    case AsmInstARITHType::AND:
      return AsmOpcodeExt::OE4;
    case AsmInstARITHType::CMP:
      return AsmOpcodeExt::OE7;
    case AsmInstARITHType::OR:
      return AsmOpcodeExt::OE1;
    case AsmInstARITHType::SBB:
      return AsmOpcodeExt::OE3;
    case AsmInstARITHType::SUB:
      return AsmOpcodeExt::OE5;
    case AsmInstARITHType::XOR:
      return AsmOpcodeExt::OE6;
    default:
      return nullptr;
    }
}

static bool
assemble_r_imm (std::vector <unsigned char> &result,
		const AsmContext &ctx, AsmRegister *dest, AsmImmediate *src,
		AsmInstARITHType type)
{
  if (dest->id < 0)
    return false;
  if (dest->width () == 1)
    {
      if (dest->id == AsmRegister::EAX->id)
	result.push_back (arith_al_imm8_opcode (type));
      else
	{
	  result.push_back (ASM_OPCODE_ARITH_RM_IMM8);
	  if (!write_operand (arith_opcode_ext (type), dest, ctx, result))
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
	  result.push_back (arith_ax_immx_opcode (type));
	  write_imm (src->value, dest->width (), result);
	}
      else
	{
	  if (src->value < INT8_MIN || src->value > INT8_MAX)
	    result.push_back (ASM_OPCODE_ARITH_RM_IMMX);
	  else
	    result.push_back (ASM_OPCODE_ARITH_RMX_IMM8);
	  if (!write_operand (arith_opcode_ext (type), dest, ctx, result))
	    return false;
	  if (src->value < INT8_MIN || src->value > INT8_MAX)
	    write_imm (src->value, dest->width (), result);
	  else
	    result.push_back (src->value & 0xff);
	}
      return true;
    }
}

static bool
assemble_r_r (std::vector <unsigned char> &result,
	      const AsmContext &ctx, AsmRegister *dest, AsmRegister *src,
	      AsmInstARITHType type)
{
  if (dest->width () != src->width ())
    return false; /* Mismatched operand sizes */
  if (dest->id < 0 || src->id < 0)
    return false;

  if (dest->width () == 1)
    result.push_back (arith_rm_r8_opcode (type));
  else
    {
      if (dest->width () != ctx.bytes)
	result.push_back (ASM_OPCODE_OPSIZE_OVR);
      result.push_back (arith_rm_rx_opcode (type));
    }
  return write_operand (src, dest, ctx, result);
}

static bool
assemble_r_m (std::vector <unsigned char> &result,
	      const AsmContext &ctx, AsmRegister *dest, AsmMemoryLoc *src,
	      AsmInstARITHType type)
{
  if (dest->width () != src->width ())
    return false; /* Mismatched operand sizes */
  if (dest->id < 0)
    return false;

  if (src->segment != default_segment (src))
    result.push_back (segment_prefix (src->segment));

  if (dest->width () == 1)
    {
      result.push_back (arith_r_rm8_opcode (type));
      return write_operand (dest, src, ctx, result);
    }
  else
    {
      if (dest->width () != ctx.bytes)
	result.push_back (ASM_OPCODE_OPSIZE_OVR);
      result.push_back (arith_r_rmx_opcode (type));
      return write_operand (dest, src, ctx, result);
    }
}

static bool
assemble_m_imm (std::vector <unsigned char> &result,
		const AsmContext &ctx, AsmMemoryLoc *dest, AsmImmediate *src,
		AsmInstARITHType type)
{
  if (dest->segment != default_segment (dest))
    result.push_back (segment_prefix (dest->segment));

  if (dest->width () == 1)
    {
      result.push_back (ASM_OPCODE_ARITH_RM_IMM8);
      if (!write_operand (arith_opcode_ext (type), dest, ctx, result))
	return false;
      result.push_back (src->value & 0xff);
      return true;
    }
  else
    {
      if (dest->width () != ctx.bytes)
	result.push_back (ASM_OPCODE_OPSIZE_OVR);
      if (src->value < INT8_MIN || src->value > INT8_MAX)
	result.push_back (ASM_OPCODE_ARITH_RM_IMMX);
      else
	result.push_back (ASM_OPCODE_ARITH_RMX_IMM8);
      if (!write_operand (arith_opcode_ext (type), dest, ctx, result))
	return false;
      if (src->value < INT8_MIN || src->value > INT8_MAX)
        write_imm (src->value, dest->width (), result);
      else
	result.push_back (src->value & 0xff);
      return true;
    }
}

static bool
assemble_m_r (std::vector <unsigned char> &result,
	      const AsmContext &ctx, AsmMemoryLoc *dest, AsmRegister *src,
	      AsmInstARITHType type)
{
  if (dest->width () != src->width ())
    return false; /* Mismatched operand sizes */
  if (src->id < 0)
    return false;

  if (dest->segment != default_segment (dest))
    result.push_back (segment_prefix (dest->segment));

  if (src->width () == 1)
    {
      result.push_back (arith_rm_r8_opcode (type));
      return write_operand (src, dest, ctx, result);
    }
  else
    {
      if (src->width () != ctx.bytes)
	result.push_back (ASM_OPCODE_OPSIZE_OVR);
      result.push_back (arith_rm_rx_opcode (type));
      return write_operand (src, dest, ctx, result);
    }
}

size_t
AsmInstARITH::width (const AsmContext &ctx)
{
  if (ISINSTANCE (AsmRegister *, dest))
    {
      AsmRegister *r = CAST (AsmRegister *, dest);
      if (ISINSTANCE (AsmImmediate *, src))
	{
	  AsmImmediate *isrc = CAST (AsmImmediate *, src);
	  if (r->width () == 1)
	    return (r->id == AsmRegister::EAX->id ? 1 : 1 +
		    operand_width (arith_opcode_ext (type), r, ctx)) + 1;
	  else
	    return (r->width () != ctx.bytes) +
	      (r->id == AsmRegister::EAX->id ? r->width () :
	       operand_width (arith_opcode_ext (type), r, ctx) +
	       (isrc->value < INT8_MIN || isrc->value > INT8_MAX ?
	        r->width () : 1)) + 1;
	}
      else if (ISINSTANCE (AsmStorage *, src))
	{
	  size_t opsize = r->width () != 1 && r->width () != ctx.bytes ? 2 : 1;
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
	{
	  AsmImmediate *isrc = CAST (AsmImmediate *, src);
	  return operand_width (arith_opcode_ext (type), dest, ctx) +
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
AsmInstARITH::assemble (std::vector <unsigned char> &result,
			const AsmContext &ctx)
{
  if (ISINSTANCE (AsmRegister *, dest))
    {
      AsmRegister *rdest = CAST (AsmRegister *, dest);
      if (rdest->id < 0)
	return false;
      else if (ISINSTANCE (AsmImmediate *, src))
	return assemble_r_imm (result, ctx, rdest, CAST (AsmImmediate *, src),
			       type);
      else if (ISINSTANCE (AsmRegister *, src))
	{
	  AsmRegister *rsrc = CAST (AsmRegister *, src);
	  if (rsrc->id < 0)
	    return false;
	  return assemble_r_r (result, ctx, rdest, rsrc, type);
	}
      else if (ISINSTANCE (AsmMemoryLoc *, src))
	return assemble_r_m (result, ctx, rdest, CAST (AsmMemoryLoc *, src),
			     type);
    }
  else if (ISINSTANCE (AsmMemoryLoc *, dest))
    {
      AsmMemoryLoc *memloc = CAST (AsmMemoryLoc *, dest);
      if (ISINSTANCE (AsmImmediate *, src))
	return assemble_m_imm (result, ctx, memloc, CAST (AsmImmediate *, src),
			       type);
      else if (ISINSTANCE (AsmRegister *, src))
	{
	  AsmRegister *rsrc = CAST (AsmRegister *, src);
	  if (rsrc->id < 0)
	    return false;
	  return assemble_m_r (result, ctx, memloc, rsrc, type);
	}
    }

  return false;
}
