/*************************************************************************
 * util.hh -- This file is part of sasm.                                 *
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

#ifndef _UTIL_HH
#define _UTIL_HH

#include <vector>
#include "expr.hh"

#define CAST(t, x) dynamic_cast <t> (x)
#define ISINSTANCE(t, x) (CAST (t, x) != nullptr)

void write_int16_le (int16_t n, std::vector <unsigned char> &result);
void write_int32_le (int32_t n, std::vector <unsigned char> &result);
void write_int64_le (int64_t n, std::vector <unsigned char> &result);
void write_imm (long long n, size_t width, std::vector <unsigned char> &result);
void write_address (long long n, const AsmContext &ctx,
		    std::vector <unsigned char> &result);

void print_int16_le (int16_t n, FILE *stream);
void print_int32_le (int32_t n, FILE *stream);

uint32_t align (uint32_t n, size_t alignment);

#endif
