/*************************************************************************
 * inst.hh -- This file is part of sasm.                                 *
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

#ifndef _INST_HH
#define _INST_HH

#include <vector>
#include "expr.hh"
#include "opcodes.h"

enum class AsmInstARITHType
{
  ADC = 1,
  ADD,
  AND,
  CMP,
  OR,
  SBB,
  SUB,
  XOR
};

enum class AsmInstJFType
{
  JO = 1,
  JNO,
  JC, /* JB, JNAE, JC */
  JNC, /* JNB, JAE, JNC */
  JZ, /* JZ, JE */
  JNZ, /* JNZ, JNE */
  JNA, /* JBE, JNA */
  JA, /* JNBE, JA */
  JS,
  JNS,
  JP, /* JP, JPE */
  JNP, /* JNP, JPO */
  JL, /* JL, JNGE */
  JNL, /* JNL, JGE */
  JNG, /* JLE, JNG */
  JG /* JNLE, JG */
};

enum class AsmInstROTSHFType
{
  RCL = 1,
  RCR,
  ROL,
  ROR,
  SAR,
  SHL,
  SHR
};

enum class AsmInstZOType
{
  AAA = 1,
  AAS,
  CBW,
  CDQ,
  CLC,
  CLD,
  CLI,
  CWD,
  CWDE,
  ENTER,
  HLT,
  INT3,
  INTO,
  IRET,
  LAHF,
  LEAVE,
  POPA,
  POPF,
  PUSHA,
  PUSHF,
  SAHF,
  STC,
  STD,
  STI,
  XLAT
};

enum class AsmInstZOSType
{
  CMPS = 1,
  INS,
  MOVS,
  LODS,
  OUTS,
  STOS,
  SCAS
};

class AsmInst
{
public:
  virtual ~AsmInst (void) = default;
  virtual size_t width (const AsmContext &ctx) = 0;
  virtual bool assemble (std::vector <unsigned char> &result,
			 const AsmContext &ctx) = 0;
};

class AsmStringInst : public AsmInst
{
};

class AsmInstAAD : public AsmInst
{
public:
  unsigned char base;

  AsmInstAAD (unsigned char base) : base (base) {}
  AsmInstAAD (void) : base (10) {}
  size_t width (const AsmContext &ctx);
  bool assemble (std::vector <unsigned char> &result,
		 const AsmContext &ctx);
};

class AsmInstAAM : public AsmInst
{
public:
  unsigned char base;

  AsmInstAAM (unsigned char base) : base (base) {}
  AsmInstAAM (void) : base (10) {}
  size_t width (const AsmContext &ctx);
  bool assemble (std::vector <unsigned char> &result,
		 const AsmContext &ctx);
};

class AsmInstARITH : public AsmInst
{
public:
  AsmInstARITHType type;
  AsmStorage *dest;
  AsmExpr *src;

  AsmInstARITH (AsmInstARITHType type, AsmStorage *dest, AsmExpr *src) :
    type (type), dest (dest), src (src) {}
  size_t width (const AsmContext &ctx);
  bool assemble (std::vector <unsigned char> &result,
		 const AsmContext &ctx);
};

class AsmInstCALL : public AsmInst
{
public:
  AsmStorage *op;
  uint32_t rel;
  size_t size;

  AsmInstCALL (uint32_t rel, size_t size) :
    op (nullptr), rel (rel), size (size) {}
  AsmInstCALL (AsmStorage *op) : op (op), rel (0), size (op->width ()) {}
  size_t width (const AsmContext &ctx);
  bool assemble (std::vector <unsigned char> &result,
		 const AsmContext &ctx);
};

class AsmInstCALLF : public AsmInst
{
public:
  AsmMemoryLoc *op;
  unsigned short segment;
  uint32_t addr;

  AsmInstCALLF (AsmMemoryLoc *op) : op (op), segment (0), addr (0) {}
  AsmInstCALLF (unsigned short segment, uint32_t addr) :
    op (nullptr), segment (segment), addr (addr) {}
  size_t width (const AsmContext &ctx);
  bool assemble (std::vector <unsigned char> &result,
		 const AsmContext &ctx);
};

class AsmInstDEC : public AsmInst
{
public:
  AsmStorage *op;

  AsmInstDEC (AsmStorage *op) : op (op) {}
  size_t width (const AsmContext &ctx);
  bool assemble (std::vector <unsigned char> &result,
		 const AsmContext &ctx);
};

class AsmInstDIV : public AsmInst
{
public:
  AsmStorage *op;

  AsmInstDIV (AsmStorage *op) : op (op) {}
  size_t width (const AsmContext &ctx);
  bool assemble (std::vector <unsigned char> &result,
		 const AsmContext &ctx);
};

class AsmInstIDIV : public AsmInst
{
public:
  AsmStorage *op;

  AsmInstIDIV (AsmStorage *op) : op (op) {}
  size_t width (const AsmContext &ctx);
  bool assemble (std::vector <unsigned char> &result,
		 const AsmContext &ctx);
};

class AsmInstIMUL : public AsmInst
{
public:
  AsmStorage *op;

  AsmInstIMUL (AsmStorage *op) : op (op) {}
  size_t width (const AsmContext &ctx);
  bool assemble (std::vector <unsigned char> &result,
		 const AsmContext &ctx);
};

class AsmInstIN : public AsmInst
{
public:
  unsigned char port;
  size_t size;
  bool dx;

  AsmInstIN (unsigned char port, size_t size) :
    port (port), size (size), dx (false) {}
  AsmInstIN (size_t size) : port (0), size (size), dx (true) {}
  size_t width (const AsmContext &ctx);
  bool assemble (std::vector <unsigned char> &result,
		 const AsmContext &ctx);
};

class AsmInstINC : public AsmInst
{
public:
  AsmStorage *op;

  AsmInstINC (AsmStorage *op) : op (op) {}
  size_t width (const AsmContext &ctx);
  bool assemble (std::vector <unsigned char> &result,
		 const AsmContext &ctx);
};

class AsmInstINT : public AsmInst
{
public:
  unsigned char vec;

  AsmInstINT (unsigned char vec) : vec (vec) {}
  size_t width (const AsmContext &ctx);
  bool assemble (std::vector <unsigned char> &result,
		 const AsmContext &ctx);
};

class AsmInstJF : public AsmInst
{
public:
  AsmInstJFType type;
  uint32_t rel;
  size_t size;

  AsmInstJF (AsmInstJFType type, uint32_t rel, size_t size) :
    type (type), rel (rel), size (size) {}
  size_t width (const AsmContext &ctx);
  bool assemble (std::vector <unsigned char> &result,
		 const AsmContext &ctx);
};

class AsmInstJMP : public AsmInst
{
public:
  AsmStorage *op;
  uint32_t rel;
  size_t size;

  AsmInstJMP (uint32_t rel, size_t size) :
    op (nullptr), rel (rel), size (size) {}
  AsmInstJMP (AsmStorage *op) : op (op), rel (0), size (op->width ()) {}
  size_t width (const AsmContext &ctx);
  bool assemble (std::vector <unsigned char> &result,
		 const AsmContext &ctx);
};

class AsmInstJMPF : public AsmInst
{
public:
  AsmMemoryLoc *op;
  unsigned short segment;
  uint32_t addr;

  AsmInstJMPF (AsmMemoryLoc *op) : op (op), segment (0), addr (0) {}
  AsmInstJMPF (unsigned short segment, uint32_t addr) :
    op (nullptr), segment (segment), addr (addr) {}
  size_t width (const AsmContext &ctx);
  bool assemble (std::vector <unsigned char> &result,
		 const AsmContext &ctx);
};

class AsmInstLEA : public AsmInst
{
public:
  AsmRegister *dest;
  AsmMemoryLoc *src;

  AsmInstLEA (AsmRegister *dest, AsmMemoryLoc *src) : dest (dest), src (src) {}
  size_t width (const AsmContext &ctx);
  bool assemble (std::vector <unsigned char> &result,
		 const AsmContext &ctx);
};

class AsmInstLOOP : public AsmInst
{
public:
  uint32_t addr;

  AsmInstLOOP (uint32_t addr) : addr (addr) {}
  size_t width (const AsmContext &ctx);
  bool assemble (std::vector <unsigned char> &result,
		 const AsmContext &ctx);
};

class AsmInstLOOPNZ : public AsmInst
{
public:
  uint32_t addr;

  AsmInstLOOPNZ (uint32_t addr) : addr (addr) {}
  size_t width (const AsmContext &ctx);
  bool assemble (std::vector <unsigned char> &result,
		 const AsmContext &ctx);
};

class AsmInstLOOPZ : public AsmInst
{
public:
  uint32_t addr;

  AsmInstLOOPZ (uint32_t addr) : addr (addr) {}
  size_t width (const AsmContext &ctx);
  bool assemble (std::vector <unsigned char> &result,
		 const AsmContext &ctx);
};

class AsmInstMOV : public AsmInst
{
public:
  AsmStorage *dest;
  AsmExpr *src;

  AsmInstMOV (AsmStorage *dest, AsmExpr *src) : dest (dest), src (src) {}
  size_t width (const AsmContext &ctx);
  bool assemble (std::vector <unsigned char> &result,
		 const AsmContext &ctx);
};

class AsmInstMUL : public AsmInst
{
public:
  AsmStorage *op;

  AsmInstMUL (AsmStorage *op) : op (op) {}
  size_t width (const AsmContext &ctx);
  bool assemble (std::vector <unsigned char> &result,
		 const AsmContext &ctx);
};

class AsmInstNEG : public AsmInst
{
public:
  AsmStorage *op;

  AsmInstNEG (AsmStorage *op) : op (op) {}
  size_t width (const AsmContext &ctx);
  bool assemble (std::vector <unsigned char> &result,
		 const AsmContext &ctx);
};

class AsmInstNOT : public AsmInst
{
public:
  AsmStorage *op;

  AsmInstNOT (AsmStorage *op) : op (op) {}
  size_t width (const AsmContext &ctx);
  bool assemble (std::vector <unsigned char> &result,
		 const AsmContext &ctx);
};

class AsmInstOUT : public AsmInst
{
public:
  unsigned char port;
  size_t size;
  bool dx;

  AsmInstOUT (unsigned char port, size_t size) :
    port (port), size (size), dx (false) {}
  AsmInstOUT (size_t size) : port (0), size (size), dx (true) {}
  size_t width (const AsmContext &ctx);
  bool assemble (std::vector <unsigned char> &result,
		 const AsmContext &ctx);
};

class AsmInstPOP : public AsmInst
{
public:
  AsmStorage *op;

  AsmInstPOP (AsmStorage *op) : op (op) {}
  size_t width (const AsmContext &ctx);
  bool assemble (std::vector <unsigned char> &result,
		 const AsmContext &ctx);
};

class AsmInstPUSH : public AsmInst
{
public:
  AsmExpr *op;

  AsmInstPUSH (AsmExpr *op) : op (op) {}
  size_t width (const AsmContext &ctx);
  bool assemble (std::vector <unsigned char> &result,
		 const AsmContext &ctx);
};

class AsmInstREPNZ : public AsmInst
{
public:
  AsmStringInst *inst;

  AsmInstREPNZ (AsmStringInst *inst) : inst (inst) {}
  size_t width (const AsmContext &ctx);
  bool assemble (std::vector <unsigned char> &result,
		 const AsmContext &ctx);
};

class AsmInstREPZ : public AsmInst
{
public:
  AsmStringInst *inst;

  AsmInstREPZ (AsmStringInst *inst) : inst (inst) {}
  size_t width (const AsmContext &ctx);
  bool assemble (std::vector <unsigned char> &result,
		 const AsmContext &ctx);
};

class AsmInstRET : public AsmInst
{
public:
  bool far;
  unsigned short bytes;

  AsmInstRET (bool far, unsigned short bytes) : far (far), bytes (bytes) {}
  AsmInstRET (bool far) : far (far), bytes (0) {}
  size_t width (const AsmContext &ctx);
  bool assemble (std::vector <unsigned char> &result,
		 const AsmContext &ctx);
};

class AsmInstROTSHF : public AsmInst
{
public:
  AsmInstROTSHFType type;
  AsmStorage *op;
  unsigned char times;
  bool cl;

  AsmInstROTSHF (AsmInstROTSHFType type, AsmStorage *op) :
    type (type), op (op), times (0), cl (true) {}
  AsmInstROTSHF (AsmInstROTSHFType type, AsmStorage *op, unsigned char times) :
    type (type), op (op), times (times), cl (false) {}
  size_t width (const AsmContext &ctx);
  bool assemble (std::vector <unsigned char> &result,
		 const AsmContext &ctx);
};

class AsmInstTEST : public AsmInst
{
public:
  AsmStorage *dest;
  AsmExpr *src;

  AsmInstTEST (AsmStorage *dest, AsmExpr *src) : dest (dest), src (src) {}
  size_t width (const AsmContext &ctx);
  bool assemble (std::vector <unsigned char> &result, const AsmContext &ctx);
};

class AsmInstXCHG : public AsmInst
{
public:
  AsmStorage *dest;
  AsmStorage *src;

  AsmInstXCHG (AsmStorage *dest, AsmStorage *src) : dest (dest), src (src) {}
  size_t width (const AsmContext &ctx);
  bool assemble (std::vector <unsigned char> &result,
		 const AsmContext &ctx);
};

class AsmInstZO : public AsmInst
{
public:
  AsmInstZOType type;

  AsmInstZO (AsmInstZOType type) : type (type) {}
  size_t width (const AsmContext &ctx);
  bool assemble (std::vector <unsigned char> &result,
		 const AsmContext &ctx);
};

class AsmInstZOS : public AsmStringInst
{
public:
  AsmInstZOSType type;
  size_t size;

  AsmInstZOS (AsmInstZOSType type, size_t size) : type (type), size (size) {}
  size_t width (const AsmContext &ctx);
  bool assemble (std::vector <unsigned char> &result,
		 const AsmContext &ctx);
};

#endif
