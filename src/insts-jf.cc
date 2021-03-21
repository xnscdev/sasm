/*************************************************************************
 * insts-jf.cc -- This file is part of sasm.                             *
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
write_rel8_opcode (AsmInstJFType type,
		   std::vector <unsigned char> &result)
{
  switch (type)
    {
    case AsmInstJFType::JO:
      result.push_back (ASM_OPCODE_JO);
      return true;
    case AsmInstJFType::JNO:
      result.push_back (ASM_OPCODE_JNO);
      return true;
    case AsmInstJFType::JC:
      result.push_back (ASM_OPCODE_JC);
      return true;
    case AsmInstJFType::JNC:
      result.push_back (ASM_OPCODE_JNC);
      return true;
    case AsmInstJFType::JZ:
      result.push_back (ASM_OPCODE_JZ);
      return true;
    case AsmInstJFType::JNZ:
      result.push_back (ASM_OPCODE_JNZ);
      return true;
    case AsmInstJFType::JNA:
      result.push_back (ASM_OPCODE_JNA);
      return true;
    case AsmInstJFType::JA:
      result.push_back (ASM_OPCODE_JA);
      return true;
    case AsmInstJFType::JS:
      result.push_back (ASM_OPCODE_JS);
      return true;
    case AsmInstJFType::JNS:
      result.push_back (ASM_OPCODE_JNS);
      return true;
    case AsmInstJFType::JP:
      result.push_back (ASM_OPCODE_JP);
      return true;
    case AsmInstJFType::JNP:
      result.push_back (ASM_OPCODE_JNP);
      return true;
    case AsmInstJFType::JL:
      result.push_back (ASM_OPCODE_JL);
      return true;
    case AsmInstJFType::JNL:
      result.push_back (ASM_OPCODE_JNL);
      return true;
    case AsmInstJFType::JNG:
      result.push_back (ASM_OPCODE_JNG);
      return true;
    case AsmInstJFType::JG:
      result.push_back (ASM_OPCODE_JG);
      return true;
    default:
      return false;
    }
}

static bool
write_relx_opcode (AsmInstJFType type,
		   std::vector <unsigned char> &result)
{
  switch (type)
    {
    case AsmInstJFType::JO:
      result.push_back (0x80);
      return true;
    case AsmInstJFType::JNO:
      result.push_back (0x81);
      return true;
    case AsmInstJFType::JC:
      result.push_back (0x82);
      return true;
    case AsmInstJFType::JNC:
      result.push_back (0x83);
      return true;
    case AsmInstJFType::JZ:
      result.push_back (0x84);
      return true;
    case AsmInstJFType::JNZ:
      result.push_back (0x85);
      return true;
    case AsmInstJFType::JNA:
      result.push_back (0x86);
      return true;
    case AsmInstJFType::JA:
      result.push_back (0x87);
      return true;
    case AsmInstJFType::JS:
      result.push_back (0x88);
      return true;
    case AsmInstJFType::JNS:
      result.push_back (0x89);
      return true;
    case AsmInstJFType::JP:
      result.push_back (0x8a);
      return true;
    case AsmInstJFType::JNP:
      result.push_back (0x8b);
      return true;
    case AsmInstJFType::JL:
      result.push_back (0x8c);
      return true;
    case AsmInstJFType::JNL:
      result.push_back (0x8d);
      return true;
    case AsmInstJFType::JNG:
      result.push_back (0x8e);
      return true;
    case AsmInstJFType::JG:
      result.push_back (0x8f);
      return true;
    default:
      return false;
    }
}

size_t
AsmInstJF::width (const AsmContext &ctx)
{
  if (ISINSTANCE (AsmImmediate *, rel))
    {
      long long r = (long long) rel->get_addr () - curraddr;
      return r > INT8_MIN + 2 && r < INT8_MAX - 2 ? 2 : ctx.bytes +
	(size != ctx.bytes) + 2;
    }
  return (size != ctx.bytes ? 3 : 2) + ctx.bytes;
}

bool
AsmInstJF::assemble (std::vector <unsigned char> &result,
		     const AsmContext &ctx)
{
  if (ISINSTANCE (AsmImmediate *, rel))
    {
      long long r = (long long) rel->get_addr () - curraddr;
      if (r > INT8_MIN + 2 && r < INT8_MAX - 2)
	{
	  if (!write_rel8_opcode (type, result))
	    return false;
	  result.push_back ((unsigned char) rel->get_addr () -
			    (unsigned char) curraddr);
	  return true;
	}
    }

  if (size == 1)
    return false;
  else if (size != ctx.bytes)
    result.push_back (ASM_OPCODE_OPSIZE_OVR);
  result.push_back (ASM_OPCODE_2BYTE_INST);
  if (!write_relx_opcode (type, result))
    return false;
  write_address (rel->get_addr () - curraddr, ctx, result);
  return true;
}
