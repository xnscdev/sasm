/*************************************************************************
 * intel-lex.ll -- This file is part of sasm.                            *
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

%{

#define _COFF_DISABLE_DEFINES /* Prevent name clashes with Yacc defines */

#include <string>
#include "gen-obj.hh"
#include "intel-parse.hh"

#define SAVE_NUMBER (yylval.number = std::stoll (yytext, nullptr, 0))
#define SAVE_STRING (yylval.string = new std::string (yytext, yyleng))

%}

%option noyywrap
%option nounput

%%

[ \t\v\r]                   ;
\n                          yylineno++; return '\n';
[0-9]+                      SAVE_NUMBER; return T_NUMBER;
0[xX][0-9a-fA-F]+           SAVE_NUMBER; return T_NUMBER;
"'"[^'\\]"'"                yylval.number = *(yytext + 1); return T_CHAR;
"byte"                      return T_BYTE;
"word"                      return T_WORD;
"dword"|"lword"             return T_DWORD;
"near"                      return T_NEAR;
"far"                       return T_FAR;
"aaa"                       return T_AAA;
"aad"                       return T_AAD;
"aam"                       return T_AAM;
"aas"                       return T_AAS;
"adc"                       yylval.arith = AsmInstARITHType::ADC; return T_ADC;
"add"                       yylval.arith = AsmInstARITHType::ADD; return T_ADD;
"and"                       yylval.arith = AsmInstARITHType::AND; return T_AND;
"call"                      return T_CALL;
"cbw"                       return T_CBW;
"cdq"                       return T_CDQ;
"clc"                       return T_CLC;
"cld"                       return T_CLD;
"cli"                       return T_CLI;
"cmp"                       yylval.arith = AsmInstARITHType::CMP; return T_CMP;
"cmps"                      return T_CMPS;
"cwd"                       return T_CWD;
"cwde"                      return T_CWDE;
"dec"                       return T_DEC;
"div"                       return T_DIV;
"enter"                     return T_ENTER;
"hlt"                       return T_HLT;
"idiv"                      return T_IDIV;
"imul"                      return T_IMUL;
"in"                        return T_IN;
"inc"                       return T_INC;
"ins"                       return T_INS;
"int"                       return T_INT;
"int3"                      return T_INT3;
"into"                      return T_INTO;
"iret"                      return T_IRET;
"jo"                        return T_JO;
"jno"                       return T_JNO;
"jb"|"jnae"|"jc"            return T_JC;
"jnb"|"jae"|"jnc"           return T_JNC;
"jz"|"je"                   return T_JZ;
"jnz"|"jne"                 return T_JNZ;
"jna"|"jbe"                 return T_JNA;
"ja"|"jnbe"                 return T_JA;
"js"                        return T_JS;
"jns"                       return T_JNS;
"jp"|"jpe"                  return T_JP;
"jnp"|"jpo"                 return T_JNP;
"jl"|"jnge"                 return T_JL;
"jnl"|"jge"                 return T_JNL;
"jle"|"jng"                 return T_JNG;
"jnle"|"jg"                 return T_JG;
"jmp"                       return T_JMP;
"lahf"                      return T_LAHF;
"lea"                       return T_LEA;
"leave"                     return T_LEAVE;
"lods"                      return T_LODS;
"loop"                      return T_LOOP;
"loopnz"                    return T_LOOPNZ;
"loopz"                     return T_LOOPZ;
"mov"                       return T_MOV;
"movs"                      return T_MOVS;
"mul"                       return T_MUL;
"neg"                       return T_NEG;
"not"                       return T_NOT;
"or"                        yylval.arith = AsmInstARITHType::OR; return T_OR;
"out"                       return T_OUT;
"outs"                      return T_OUTS;
"pop"                       return T_POP;
"popa"                      return T_POPA;
"popf"                      return T_POPF;
"push"                      return T_PUSH;
"pusha"                     return T_PUSHA;
"pushf"                     return T_PUSHF;
"rcl"                       return T_RCL;
"rcr"                       return T_RCR;
"repnz"                     return T_REPNZ;
"repz"|"rep"                return T_REPZ;
"ret"                       return T_RET;
"rol"                       return T_ROL;
"ror"                       return T_ROR;
"sahf"                      return T_SAHF;
"sar"                       return T_SAR;
"sbb"                       yylval.arith = AsmInstARITHType::SBB; return T_SBB;
"scas"                      return T_SCAS;
"shl"|"sal"                 return T_SHL;
"shr"                       return T_SHR;
"stc"                       return T_STC;
"std"                       return T_STD;
"stos"                      return T_STOS;
"sti"                       return T_STI;
"sub"                       yylval.arith = AsmInstARITHType::SUB; return T_SUB;
"test"                      return T_TEST;
"xchg"                      return T_XCHG;
"xlat"                      return T_XLAT;
"xor"                       yylval.arith = AsmInstARITHType::XOR; return T_XOR;
"cs"                        return T_CS;
"ds"                        return T_DS;
"es"                        return T_ES;
"fs"                        return T_FS;
"gs"                        return T_GS;
"al"                        return T_AL;
"cl"                        return T_CL;
"dl"                        return T_DL;
"bl"                        return T_BL;
"ah"                        return T_AH;
"ch"                        return T_CH;
"dh"                        return T_DH;
"bh"                        return T_BH;
"ax"                        return T_AX;
"cx"                        return T_CX;
"dx"                        return T_DX;
"bx"                        return T_BX;
"sp"                        return T_SP;
"bp"                        return T_BP;
"si"                        return T_SI;
"di"                        return T_DI;
"eax"                       return T_EAX;
"ecx"                       return T_ECX;
"edx"                       return T_EDX;
"ebx"                       return T_EBX;
"esp"                       return T_ESP;
"ebp"                       return T_EBP;
"esi"                       return T_ESI;
"edi"                       return T_EDI;
[a-zA-Z_][a-zA-Z0-9_]*      SAVE_STRING; return T_IDENT;
.                           return *yytext;

%%
