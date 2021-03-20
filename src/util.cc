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

#include "assemble.hh"
#include "opcodes.h"
#include "util.hh"

std::map <std::string, uint32_t> label_addrs;
std::set <std::string> global_syms;

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

bool
write_operand (const AsmRegister *reg, const AsmStorage *rm,
	       const AsmContext &ctx, std::vector <unsigned char> &result)
{
  unsigned char regid =
    reg == nullptr ? 0 : (reg->id < 0 ? -(reg->id + 1) << 3 : reg->id << 3);
  if (ISINSTANCE (const AsmRegister *, rm))
    {
      result.push_back (0xc0 | regid | CAST (const AsmRegister *, rm)->id);
      return true;
    }
  else if (ISINSTANCE (const AsmMemoryLoc *, rm))
    {
      const AsmMemoryLoc *loc = CAST (const AsmMemoryLoc *, rm);
      unsigned char mod;
      unsigned char rm;

      if (ctx.bytes != 4)
	return false; /* TODO Support 16-bit addressing */

      if (loc->base == nullptr && loc->index == nullptr)
	{
	  result.push_back (regid | 5);
	  write_int32_le (loc->disp, result);
	  if (loc->relocate)
	    mark_reloc (curraddr + 1, loc->section);
	  return true;
	}

      if (loc->base == nullptr)
	return false; /* TODO Support no base */

      /* Check for valid 32-bit addressing registers */
      if (loc->base != nullptr && loc->base->width () != 0
	  && loc->base->width () != 4)
	return false;
      if (loc->index != nullptr && loc->index->width () != 0
	  && loc->index->width () != 4)
	return false;

      /* ModR/M byte */
      mod = loc->base->id == AsmRegister::EBP->id;
      rm = loc->base->id;
      if (loc->disp < INT8_MIN || loc->disp > INT8_MAX)
	mod = 2;
      else if (loc->disp != 0)
	mod = 1;
      if (loc->index != nullptr)
	rm = 4;
      result.push_back (mod << 6 | regid | rm);

      if (loc->index != nullptr)
	{
	  /* SIB byte */
	  unsigned char ss;
	  if (loc->index->id == AsmRegister::ESP->id)
	    return false; /* Index can't be ESP */
	  switch (loc->scale)
	    {
	    case 1:
	      ss = 0;
	      break;
	    case 2:
	      ss = 1;
	      break;
	    case 4:
	      ss = 2;
	      break;
	    case 8:
	      ss = 3;
	      break;
	    default:
	      return false;
	    }
	  result.push_back (ss << 6 | loc->index->id << 3 | loc->base->id);
	}

      if (mod == 1 && !loc->relocate)
	result.push_back (loc->disp);
      else
	{
	  if (loc->disp != 0)
	    write_int32_le (loc->disp, result);
	  else if (loc->base->id == AsmRegister::EBP->id)
	    write_int32_le (0, result);
	  if (loc->relocate)
	    mark_reloc (curraddr + (loc->index != nullptr ? 2 : 1),
			loc->section);
	}
      return true;
    }

  return false;
}

ssize_t
operand_width (const AsmRegister *reg, const AsmStorage *rm,
	       const AsmContext &ctx)
{
  if (ISINSTANCE (const AsmRegister *, rm))
    return 1;
  else if (ISINSTANCE (const AsmMemoryLoc *, rm))
    {
      const AsmMemoryLoc *loc = CAST (const AsmMemoryLoc *, rm);
      unsigned char mod;

      if (ctx.bytes != 4)
	return -1; /* TODO Support 16-bit addressing */

      if (loc->base == nullptr && loc->index == nullptr)
	return 5;

      if (loc->base == nullptr)
	return -1; /* TODO Support no base */

      /* Check for valid 32-bit addressing registers */
      if (loc->base != nullptr && loc->base->width () != 0
	  && loc->base->width () != 4)
	return -1;
      if (loc->index != nullptr && loc->index->width () != 0
	  && loc->index->width () != 4)
	return -1;

      mod = loc->base->id == AsmRegister::EBP->id;
      if (loc->disp < INT8_MIN || loc->disp > INT8_MAX)
	mod = 2;
      else if (loc->disp != 0)
	mod = 1;
      return 1 + (loc->index != nullptr) + (mod == 0 ? 0 : (mod == 1 ? 1 : 4));
    }

  return -1;
}

AsmRegister *
default_segment (const AsmMemoryLoc *loc)
{
  return loc->base != nullptr && loc->base->id == AsmRegister::EBP->id ?
    AsmRegister::SS : AsmRegister::DS;
}

unsigned char
segment_prefix (const AsmRegister *segment)
{
  switch (segment->id)
    {
    case -2:
      return ASM_OPCODE_CS_SGMT_OVR;
    case -4:
      return ASM_OPCODE_DS_SGMT_OVR;
    case -1:
      return ASM_OPCODE_ES_SGMT_OVR;
    case -5:
      return ASM_OPCODE_FS_SGMT_OVR;
    case -6:
      return ASM_OPCODE_GS_SGMT_OVR;
    case -3:
      return ASM_OPCODE_SS_SGMT_OVR;
    default:
      return 0;
    }
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
