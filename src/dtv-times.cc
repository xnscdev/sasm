/*************************************************************************
 * dtv-times.cc -- This file is part of sasm.                            *
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

#include "directive.hh"
#include "opcodes.h"
#include "util.hh"

size_t
AsmInstTIMES::width (const AsmContext &ctx)
{
  return times * op->width (ctx);
}

bool
AsmInstTIMES::assemble (std::vector <unsigned char> &result,
			const AsmContext &ctx)
{
  for (size_t i = 0; i < times; i++)
    {
      if (!op->assemble (result, ctx))
	return false;
    }
  return true;
}
