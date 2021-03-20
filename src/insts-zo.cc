/*************************************************************************
 * insts-zo.cc -- This file is part of sasm.                             *
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
AsmInstZO::width (const AsmContext &ctx)
{
  return type == AsmInstZOType::CBW || type == AsmInstZOType::CWD ? 2 : 1;
}

bool
AsmInstZO::assemble (std::vector <unsigned char> &result,
		     const AsmContext &ctx)
{
  switch (type)
    {
    case AsmInstZOType::AAA:
      result.push_back (ASM_OPCODE_AAA);
      return true;
    case AsmInstZOType::AAS:
      result.push_back (ASM_OPCODE_AAS);
      return true;
    case AsmInstZOType::CBW:
      result.push_back (ASM_OPCODE_OPSIZE_OVR);
      result.push_back (ASM_OPCODE_CWDE);
      return true;
    case AsmInstZOType::CDQ:
      result.push_back (ASM_OPCODE_CDQ);
      return true;
    case AsmInstZOType::CLC:
      result.push_back (ASM_OPCODE_CLC);
      return true;
    case AsmInstZOType::CLD:
      result.push_back (ASM_OPCODE_CLD);
      return true;
    case AsmInstZOType::CLI:
      result.push_back (ASM_OPCODE_CLI);
      return true;
    case AsmInstZOType::CWD:
      result.push_back (ASM_OPCODE_OPSIZE_OVR);
      result.push_back (ASM_OPCODE_CDQ);
      return true;
    case AsmInstZOType::CWDE:
      result.push_back (ASM_OPCODE_CWDE);
      return true;
    case AsmInstZOType::ENTER:
      result.push_back (ASM_OPCODE_ENTER);
      return true;
    case AsmInstZOType::HLT:
      result.push_back (ASM_OPCODE_HLT);
      return true;
    case AsmInstZOType::INT3:
      result.push_back (ASM_OPCODE_INT3);
      return true;
    case AsmInstZOType::INTO:
      result.push_back (ASM_OPCODE_INTO);
      return true;
    case AsmInstZOType::IRET:
      result.push_back (ASM_OPCODE_IRET);
      return true;
    case AsmInstZOType::LAHF:
      result.push_back (ASM_OPCODE_LAHF);
      return true;
    case AsmInstZOType::LEAVE:
      result.push_back (ASM_OPCODE_LEAVE);
      return true;
    case AsmInstZOType::POPA:
      result.push_back (ASM_OPCODE_POPA);
      return true;
    case AsmInstZOType::POPF:
      result.push_back (ASM_OPCODE_POPF);
      return true;
    case AsmInstZOType::PUSHA:
      result.push_back (ASM_OPCODE_PUSHA);
      return true;
    case AsmInstZOType::PUSHF:
      result.push_back (ASM_OPCODE_PUSHF);
      return true;
    case AsmInstZOType::SAHF:
      result.push_back (ASM_OPCODE_SAHF);
      return true;
    case AsmInstZOType::STC:
      result.push_back (ASM_OPCODE_STC);
      return true;
    case AsmInstZOType::STD:
      result.push_back (ASM_OPCODE_STD);
      return true;
    case AsmInstZOType::STI:
      result.push_back (ASM_OPCODE_STI);
      return true;
    case AsmInstZOType::XLAT:
      result.push_back (ASM_OPCODE_XLAT);
      return true;
    default:
      return false;
    }
}
