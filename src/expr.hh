/*************************************************************************
 * expr.hh -- This file is part of sasm.                                 *
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

#ifndef _EXPR_HH
#define _EXPR_HH

#include <string>

extern uint32_t curraddr;

enum class AsmLabelBinding
{
  LOCAL = 0,
  GLOBAL,
  WEAK
};

enum class AsmLabelType
{
  NONE = 0,
  OBJECT,
  FUNC,
  SECTION,
  FILE
};

class AsmContext
{
public:
  unsigned char bytes; /* Target code size / 8 */

  AsmContext (unsigned char bytes) : bytes (bytes) {}
};

class AsmExpr
{
public:
  virtual ~AsmExpr (void) = default;
};

class AsmStorage : public AsmExpr
{
public:
  virtual size_t width (void) = 0;
};

class AsmImmediate : public AsmExpr
{
public:
  long long value;

  AsmImmediate (long long value) : value (value) {}
};

class AsmRegister : public AsmStorage
{
  size_t size;

public:
  std::string name;
  char id;

  AsmRegister (std::string name, char id, size_t size) :
    size (size), name (std::move (name)), id (id) {}
  size_t width (void);

  /* Segment registers */
  static AsmRegister *CS;
  static AsmRegister *DS;
  static AsmRegister *ES;
  static AsmRegister *FS;
  static AsmRegister *GS;
  static AsmRegister *SS;

  /* 8-bit registers */
  static AsmRegister *AL;
  static AsmRegister *CL;
  static AsmRegister *DL;
  static AsmRegister *BL;
  static AsmRegister *AH;
  static AsmRegister *CH;
  static AsmRegister *DH;
  static AsmRegister *BH;

  /* 16-bit registers */
  static AsmRegister *AX;
  static AsmRegister *CX;
  static AsmRegister *DX;
  static AsmRegister *BX;
  static AsmRegister *SP;
  static AsmRegister *BP;
  static AsmRegister *SI;
  static AsmRegister *DI;

  /* 32-bit registers */
  static AsmRegister *EAX;
  static AsmRegister *ECX;
  static AsmRegister *EDX;
  static AsmRegister *EBX;
  static AsmRegister *ESP;
  static AsmRegister *EBP;
  static AsmRegister *ESI;
  static AsmRegister *EDI;
};

class AsmLabel
{
public:
  std::string name;
  std::string section;
  AsmLabelBinding bind;
  AsmLabelType type;
  size_t size;
  uint32_t addr;

  AsmLabel (std::string name, std::string section, AsmLabelBinding bind,
	    AsmLabelType type, size_t size) :
    name (std::move (name)), section (std::move (section)), bind (bind),
    type (type), size (size), addr (curraddr) {}
};

class AsmMemoryLoc : public AsmStorage
{
public:
  AsmRegister *base;
  AsmRegister *index;
  unsigned char scale;
  long long disp;
  AsmRegister *segment;
  size_t size;
  std::string section;
  bool relocate;

  AsmMemoryLoc (AsmRegister *base, AsmRegister *index, unsigned char scale,
		long long disp, AsmRegister *segment, size_t size) :
    base (base), index (index), scale (scale), disp (disp), segment (segment),
    size (size), relocate (false) {}
  AsmMemoryLoc (AsmRegister *base, AsmRegister *index, unsigned char scale,
		long long disp, AsmRegister *segment, AsmLabel *label,
		size_t size) :
    base (base), index (index), scale (scale), disp (disp + label->addr),
    segment (segment), size (size), section (label->section), relocate (true) {}
  size_t width (void);
};

namespace AsmOpcodeExt
{
  /* Not really registers, used in place of register bits in ModR/M */
  extern AsmRegister *OE0;
  extern AsmRegister *OE1;
  extern AsmRegister *OE2;
  extern AsmRegister *OE3;
  extern AsmRegister *OE4;
  extern AsmRegister *OE5;
  extern AsmRegister *OE6;
  extern AsmRegister *OE7;
}

class AsmTranslationUnit
{
public:
  std::string filename;

  AsmTranslationUnit (std::string filename) : filename (std::move (filename)) {}
};

#endif
