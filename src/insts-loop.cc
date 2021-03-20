/*************************************************************************
 * insts-loop.cc -- This file is part of sasm.                           *
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
AsmInstLOOP::width (const AsmContext &ctx)
{
  return 2;
}

bool
AsmInstLOOP::assemble (std::vector <unsigned char> &result,
		       const AsmContext &ctx)
{
  long long rel = (long long) addr - curraddr;
  if (rel <= INT8_MIN + 2 || rel >= INT8_MAX - 2)
    return false;
  result.push_back (ASM_OPCODE_LOOP);
  result.push_back ((unsigned char) addr - (unsigned char) curraddr);
  return true;
}

size_t
AsmInstLOOPNZ::width (const AsmContext &ctx)
{
  return 2;
}

bool
AsmInstLOOPNZ::assemble (std::vector <unsigned char> &result,
			 const AsmContext &ctx)
{
  long long rel = (long long) addr - curraddr;
  if (rel <= INT8_MIN + 2 || rel >= INT8_MAX - 2)
    return false;
  result.push_back (ASM_OPCODE_LOOPNZ);
  result.push_back ((unsigned char) addr - (unsigned char) curraddr);
  return true;
}

size_t
AsmInstLOOPZ::width (const AsmContext &ctx)
{
  return 2;
}

bool
AsmInstLOOPZ::assemble (std::vector <unsigned char> &result,
			const AsmContext &ctx)
{
  long long rel = (long long) addr - curraddr;
  if (rel <= INT8_MIN + 2 || rel >= INT8_MAX - 2)
    return false;
  result.push_back (ASM_OPCODE_LOOPZ);
  result.push_back ((unsigned char) addr - (unsigned char) curraddr);
  return true;
}
