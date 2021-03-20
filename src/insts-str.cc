/*************************************************************************
 * insts-str.cc -- This file is part of sasm.                            *
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
zos_opcode (AsmInstZOSType type)
{
  switch (type)
    {
    case AsmInstZOSType::CMPS:
      return ASM_OPCODE_CMPSB;
    case AsmInstZOSType::INS:
      return ASM_OPCODE_INSB;
    case AsmInstZOSType::MOVS:
      return ASM_OPCODE_MOVSB;
    case AsmInstZOSType::LODS:
      return ASM_OPCODE_LODSB;
    case AsmInstZOSType::OUTS:
      return ASM_OPCODE_OUTSB;
    case AsmInstZOSType::STOS:
      return ASM_OPCODE_STOSB;
    case AsmInstZOSType::SCAS:
      return ASM_OPCODE_SCASB;
    default:
      return 0;
    }
}

size_t
AsmInstZOS::width (const AsmContext &ctx)
{
  return size != 1 && size != ctx.bytes ? 2 : 1;
}

bool
AsmInstZOS::assemble (std::vector <unsigned char> &result,
		      const AsmContext &ctx)
{
  unsigned char opcode = zos_opcode (type);
  if (opcode == 0)
    return false;
  if (size == 1)
    result.push_back (opcode);
  else
    {
      if (size != ctx.bytes)
	result.push_back (ASM_OPCODE_OPSIZE_OVR);
      result.push_back (opcode + 1);
    }
  return true;
}
