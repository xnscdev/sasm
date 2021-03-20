/*************************************************************************
 * registers.cc -- This file is part of sasm.                            *
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

#include "expr.hh"

/* Segment registers */
AsmRegister *AsmRegister::CS = new AsmRegister ("cs", -2, 2);
AsmRegister *AsmRegister::DS = new AsmRegister ("ds", -4, 2);
AsmRegister *AsmRegister::ES = new AsmRegister ("es", -1, 2);
AsmRegister *AsmRegister::FS = new AsmRegister ("fs", -5, 2);
AsmRegister *AsmRegister::GS = new AsmRegister ("gs", -6, 2);
AsmRegister *AsmRegister::SS = new AsmRegister ("ss", -3, 2);

/* 8-bit registers */
AsmRegister *AsmRegister::AL = new AsmRegister ("al", 0, 1);
AsmRegister *AsmRegister::CL = new AsmRegister ("cl", 1, 1);
AsmRegister *AsmRegister::DL = new AsmRegister ("dl", 2, 1);
AsmRegister *AsmRegister::BL = new AsmRegister ("bl", 3, 1);
AsmRegister *AsmRegister::AH = new AsmRegister ("ah", 4, 1);
AsmRegister *AsmRegister::CH = new AsmRegister ("ch", 5, 1);
AsmRegister *AsmRegister::DH = new AsmRegister ("dh", 6, 1);
AsmRegister *AsmRegister::BH = new AsmRegister ("bh", 7, 1);

/* 16-bit registers */
AsmRegister *AsmRegister::AX = new AsmRegister ("ax", 0, 2);
AsmRegister *AsmRegister::CX = new AsmRegister ("cx", 1, 2);
AsmRegister *AsmRegister::DX = new AsmRegister ("dx", 2, 2);
AsmRegister *AsmRegister::BX = new AsmRegister ("bx", 3, 2);
AsmRegister *AsmRegister::SP = new AsmRegister ("sp", 4, 2);
AsmRegister *AsmRegister::BP = new AsmRegister ("bp", 5, 2);
AsmRegister *AsmRegister::SI = new AsmRegister ("si", 6, 2);
AsmRegister *AsmRegister::DI = new AsmRegister ("di", 7, 2);

/* 32-bit registers */
AsmRegister *AsmRegister::EAX = new AsmRegister ("eax", 0, 4);
AsmRegister *AsmRegister::ECX = new AsmRegister ("ecx", 1, 4);
AsmRegister *AsmRegister::EDX = new AsmRegister ("edx", 2, 4);
AsmRegister *AsmRegister::EBX = new AsmRegister ("ebx", 3, 4);
AsmRegister *AsmRegister::ESP = new AsmRegister ("esp", 4, 4);
AsmRegister *AsmRegister::EBP = new AsmRegister ("ebp", 5, 4);
AsmRegister *AsmRegister::ESI = new AsmRegister ("esi", 6, 4);
AsmRegister *AsmRegister::EDI = new AsmRegister ("edi", 7, 4);

/* Opcode extensions */
AsmRegister *AsmOpcodeExt::OE0 = new AsmRegister ("", 0, 0);
AsmRegister *AsmOpcodeExt::OE1 = new AsmRegister ("", 1, 0);
AsmRegister *AsmOpcodeExt::OE2 = new AsmRegister ("", 2, 0);
AsmRegister *AsmOpcodeExt::OE3 = new AsmRegister ("", 3, 0);
AsmRegister *AsmOpcodeExt::OE4 = new AsmRegister ("", 4, 0);
AsmRegister *AsmOpcodeExt::OE5 = new AsmRegister ("", 5, 0);
AsmRegister *AsmOpcodeExt::OE6 = new AsmRegister ("", 6, 0);
AsmRegister *AsmOpcodeExt::OE7 = new AsmRegister ("", 7, 0);

size_t
AsmRegister::width (void)
{
  return size;
}
