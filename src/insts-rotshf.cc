/*************************************************************************
 * insts-rotshf.cc -- This file is part of sasm.                         *
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

static AsmRegister *
rotshf_opcode_ext (AsmInstROTSHFType type)
{
  switch (type)
    {
    case AsmInstROTSHFType::RCL:
      return AsmOpcodeExt::OE2;
    case AsmInstROTSHFType::RCR:
      return AsmOpcodeExt::OE3;
    case AsmInstROTSHFType::ROL:
      return AsmOpcodeExt::OE0;
    case AsmInstROTSHFType::ROR:
      return AsmOpcodeExt::OE1;
    case AsmInstROTSHFType::SAR:
      return AsmOpcodeExt::OE7;
    case AsmInstROTSHFType::SHL:
      return AsmOpcodeExt::OE4;
    case AsmInstROTSHFType::SHR:
      return AsmOpcodeExt::OE5;
    default:
      return nullptr;
    }
}

static bool
rotshf_assemble (std::vector <unsigned char> &result,
		 const AsmContext &ctx, AsmRegister *ext, AsmStorage *op,
		 unsigned char times, bool cl)
{
  if (ISINSTANCE (AsmMemoryLoc *, op))
    {
      AsmMemoryLoc *loc = CAST (AsmMemoryLoc *, op);
      if (loc->segment != default_segment (loc))
	result.push_back (segment_prefix (loc->segment));
    }
  if (cl)
    {
      if (op->width () == 1)
	result.push_back (ASM_OPCODE_ROTSHF_RM8_CL);
      else
	{
	  if (op->width () != ctx.bytes)
	    result.push_back (ASM_OPCODE_OPSIZE_OVR);
	  result.push_back (ASM_OPCODE_ROTSHF_RMX_CL);
	}
      return write_operand (ext, op, ctx, result);
    }
  else if (times == 1)
    {
      if (op->width () == 1)
	result.push_back (ASM_OPCODE_ROTSHF_RM8_1);
      else
	{
	  if (op->width () != ctx.bytes)
	    result.push_back (ASM_OPCODE_OPSIZE_OVR);
	  result.push_back (ASM_OPCODE_ROTSHF_RMX_1);
	}
      return write_operand (ext, op, ctx, result);
    }
  else
    {
      if (op->width () == 1)
	result.push_back (ASM_OPCODE_ROTSHF_RM8_IMM);
      else
	{
	  if (op->width () != ctx.bytes)
	    result.push_back (ASM_OPCODE_OPSIZE_OVR);
	  result.push_back (ASM_OPCODE_ROTSHF_RMX_IMM);
	}
      if (!write_operand (ext, op, ctx, result))
	return false;
      result.push_back (times);
      return true;
    }
}

size_t
AsmInstROTSHF::width (const AsmContext &ctx)
{
  AsmMemoryLoc *l = CAST (AsmMemoryLoc *, op);
  size_t pfsize = l != nullptr && l->segment != default_segment (l);
  return (op->width () != 1 && op->width () != ctx.bytes ? 2 : 1) +
    operand_width (AsmOpcodeExt::OE0, op, ctx) + pfsize + (!cl && times != 1);
}

bool
AsmInstROTSHF::assemble (std::vector <unsigned char> &result,
			 const AsmContext &ctx)
{
  AsmRegister *ext = rotshf_opcode_ext (type);
  if (ext == nullptr)
    return false;
  return rotshf_assemble (result, ctx, ext, op, times, cl);
}
