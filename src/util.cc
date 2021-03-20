/*************************************************************************
 * util.cc -- This file is part of sasm.                                 *
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

#include "opcodes.h"
#include "util.hh"

void
write_int16_le (int16_t n, std::vector <unsigned char> &result)
{
  result.push_back (n & 0xff);
  result.push_back (n >> 8 & 0xff);
}

void
write_int32_le (int32_t n, std::vector <unsigned char> &result)
{
  result.push_back (n & 0xff);
  result.push_back (n >> 8 & 0xff);
  result.push_back (n >> 16 & 0xff);
  result.push_back (n >> 24 & 0xff);
}

void
write_int64_le (int64_t n, std::vector <unsigned char> &result)
{
  result.push_back (n & 0xff);
  result.push_back (n >> 8 & 0xff);
  result.push_back (n >> 16 & 0xff);
  result.push_back (n >> 24 & 0xff);
  result.push_back (n >> 32 & 0xff);
  result.push_back (n >> 40 & 0xff);
  result.push_back (n >> 48 & 0xff);
  result.push_back (n >> 56 & 0xff);
}

void
write_imm (long long n, size_t width, std::vector <unsigned char> &result)
{
  switch (width)
    {
    case 2:
      write_int16_le (n & 0xffff, result);
      break;
    case 4:
      write_int32_le (n & 0xffffffff, result);
      break;
    }
}

void
write_address (long long n, const AsmContext &ctx,
	       std::vector <unsigned char> &result)
{
  write_imm (n, ctx.bytes, result);
}

void
print_int16_le (int16_t n, FILE *stream)
{
  fputc (n & 0xff, stream);
  fputc (n >> 8 & 0xff, stream);
}

void
print_int32_le (int32_t n, FILE *stream)
{
  fputc (n & 0xff, stream);
  fputc (n >> 8 & 0xff, stream);
  fputc (n >> 16 & 0xff, stream);
  fputc (n >> 24 & 0xff, stream);
}

uint32_t
align (uint32_t n, size_t alignment)
{
  if (n & (alignment - 1))
    {
      n &= ~(alignment - 1);
      n += alignment;
    }
  return n;
}
