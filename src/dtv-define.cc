/*************************************************************************
 * dtv-define.cc -- This file is part of sasm.                           *
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
AsmInstDEFINE::width (const AsmContext &ctx)
{
  return size;
}

bool
AsmInstDEFINE::assemble (std::vector <unsigned char> &result,
			 const AsmContext &ctx)
{
  switch (size)
    {
    case 1:
      result.push_back (value & 0xff);
      return true;
    case 2:
      write_int16_le (value & 0xffff, result);
      return true;
    case 4:
      write_int32_le (value & 0xffffffff, result);
      return true;
    case 8:
      write_int64_le (value, result);
      return true;
    default:
      return false;
    }
}
