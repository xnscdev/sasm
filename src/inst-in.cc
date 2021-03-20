/*************************************************************************
 * inst-in.cc -- This file is part of sasm.                              *
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
AsmInstIN::width (const AsmContext &ctx)
{
  return (size != 1 && size != ctx.bytes ? 2 : 1) + !dx;
}

bool
AsmInstIN::assemble (std::vector <unsigned char> &result,
		     const AsmContext &ctx)
{
  if (dx)
    {
      if (size == 1)
	result.push_back (ASM_OPCODE_IN_AL_DX);
      else
	{
	  if (size != ctx.bytes)
	    result.push_back (ASM_OPCODE_OPSIZE_OVR);
	  result.push_back (ASM_OPCODE_IN_AX_DX);
	}
    }
  else
    {
      if (size == 1)
	result.push_back (ASM_OPCODE_IN_AL_IMM8);
      else
	{
	  if (size != ctx.bytes)
	    result.push_back (ASM_OPCODE_OPSIZE_OVR);
	  result.push_back (ASM_OPCODE_IN_AX_IMM8);
	}
      result.push_back (port);
    }
  return true;
}
