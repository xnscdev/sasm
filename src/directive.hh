/*************************************************************************
 * directive.hh -- This file is part of sasm.                            *
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

#ifndef _DIRECTIVE_HH
#define _DIRECTIVE_HH

#include "inst.hh"

class AsmDirective : public AsmInst
{
};

class AsmInstDEFINE : public AsmDirective
{
public:
  size_t size;
  uint64_t value;

  AsmInstDEFINE (size_t size, uint64_t value) : size (size), value (value) {}
  size_t width (const AsmContext &ctx);
  bool assemble (std::vector <unsigned char> &result,
		 const AsmContext &ctx);
};

class AsmInstTIMES : public AsmDirective
{
public:
  AsmDirective *op;
  size_t times;

  AsmInstTIMES (AsmDirective *op, size_t times) : op (op), times (times) {}
  size_t width (const AsmContext &ctx);
  bool assemble (std::vector <unsigned char> &result,
		 const AsmContext &ctx);
};

#endif
