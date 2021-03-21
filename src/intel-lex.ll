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
"aaa"                       yylval.zo = AsmInstZOType::AAA; return T_ZO;
"aad"                       return T_AAD;
"aam"                       return T_AAM;
"aas"                       yylval.zo = AsmInstZOType::AAS; return T_ZO;
"adc"                       yylval.arith = AsmInstARITHType::ADC; return T_ARTH;
"add"                       yylval.arith = AsmInstARITHType::ADD; return T_ARTH;
"and"                       yylval.arith = AsmInstARITHType::AND; return T_ARTH;
"call"                      return T_CALL;
"cbw"                       yylval.zo = AsmInstZOType::CBW; return T_ZO;
"cdq"                       yylval.zo = AsmInstZOType::CDQ; return T_ZO;
"clc"                       yylval.zo = AsmInstZOType::CLC; return T_ZO;
"cld"                       yylval.zo = AsmInstZOType::CLD; return T_ZO;
"cli"                       yylval.zo = AsmInstZOType::CLI; return T_ZO;;
"cmp"                       yylval.arith = AsmInstARITHType::CMP; return T_ARTH;
"cmps"                      yylval.zos = AsmInstZOSType::CMPS; return T_ZOS;
"cwd"                       yylval.zo = AsmInstZOType::CWD; return T_ZO;
"cwde"                      yylval.zo = AsmInstZOType::CWDE; return T_ZO;
"dec"                       return T_DEC;
"div"                       return T_DIV;
"enter"                     yylval.zo = AsmInstZOType::ENTER; return T_ZO;
"hlt"                       yylval.zo = AsmInstZOType::HLT; return T_ZO;
"idiv"                      return T_IDIV;
"imul"                      return T_IMUL;
"in"                        return T_IN;
"inc"                       return T_INC;
"ins"                       yylval.zos = AsmInstZOSType::INS; return T_ZOS;
"int"                       return T_INT;
"int3"                      yylval.zo = AsmInstZOType::INT3; return T_ZO;
"into"                      yylval.zo = AsmInstZOType::INTO; return T_ZO;
"iret"                      yylval.zo = AsmInstZOType::IRET; return T_ZO;
"jo"                        yylval.jf = AsmInstJFType::JO; return T_JF;
"jno"                       yylval.jf = AsmInstJFType::JNO; return T_JF;
"jb"|"jnae"|"jc"            yylval.jf = AsmInstJFType::JC; return T_JF;
"jnb"|"jae"|"jnc"           yylval.jf = AsmInstJFType::JNC; return T_JF;
"jz"|"je"                   yylval.jf = AsmInstJFType::JZ; return T_JF;
"jnz"|"jne"                 yylval.jf = AsmInstJFType::JNZ; return T_JF;
"jna"|"jbe"                 yylval.jf = AsmInstJFType::JNA; return T_JF;
"ja"|"jnbe"                 yylval.jf = AsmInstJFType::JA; return T_JF;
"js"                        yylval.jf = AsmInstJFType::JS; return T_JF;
"jns"                       yylval.jf = AsmInstJFType::JNS; return T_JF;
"jp"|"jpe"                  yylval.jf = AsmInstJFType::JP; return T_JF;
"jnp"|"jpo"                 yylval.jf = AsmInstJFType::JNP; return T_JF;
"jl"|"jnge"                 yylval.jf = AsmInstJFType::JL; return T_JF;
"jnl"|"jge"                 yylval.jf = AsmInstJFType::JNL; return T_JF;
"jle"|"jng"                 yylval.jf = AsmInstJFType::JNG; return T_JF;
"jnle"|"jg"                 yylval.jf = AsmInstJFType::JG; return T_JF;
"jmp"                       return T_JMP;
"lahf"                      yylval.zo = AsmInstZOType::LAHF; return T_ZO;
"lea"                       return T_LEA;
"leave"                     yylval.zo = AsmInstZOType::LEAVE; return T_ZO;
"lods"                      yylval.zos = AsmInstZOSType::LODS; return T_ZOS;
"loop"                      return T_LOOP;
"loopnz"                    return T_LOOPNZ;
"loopz"                     return T_LOOPZ;
"mov"                       return T_MOV;
"movs"                      yylval.zos = AsmInstZOSType::MOVS; return T_ZOS;
"mul"                       return T_MUL;
"neg"                       return T_NEG;
"nop"                       return T_NOP;
"not"                       return T_NOT;
"or"                        yylval.arith = AsmInstARITHType::OR; return T_ARTH;
"out"                       return T_OUT;
"outs"                      yylval.zos = AsmInstZOSType::OUTS; return T_ZOS;
"pop"                       return T_POP;
"popa"                      yylval.zo = AsmInstZOType::POPA; return T_ZO;
"popf"                      yylval.zo = AsmInstZOType::POPF; return T_ZO;
"push"                      return T_PUSH;
"pusha"                     yylval.zo = AsmInstZOType::PUSHA; return T_ZO;
"pushf"                     yylval.zo = AsmInstZOType::PUSHF; return T_ZO;
"rcl"                   yylval.rotshf = AsmInstROTSHFType::RCL; return T_ROTSHF;
"rcr"                   yylval.rotshf = AsmInstROTSHFType::RCR; return T_ROTSHF;
"repnz"                     return T_REPNZ;
"repz"|"rep"                return T_REPZ;
"ret"                       return T_RET;
"rol"                   yylval.rotshf = AsmInstROTSHFType::ROL; return T_ROTSHF;
"ror"                   yylval.rotshf = AsmInstROTSHFType::ROR; return T_ROTSHF;
"sahf"                      yylval.zo = AsmInstZOType::SAHF; return T_ZO;
"sar"                   yylval.rotshf = AsmInstROTSHFType::SAR; return T_ROTSHF;
"sbb"                       yylval.arith = AsmInstARITHType::SBB; return T_ARTH;
"scas"                      yylval.zos = AsmInstZOSType::SCAS; return T_ZOS;
"shl"|"sal"             yylval.rotshf = AsmInstROTSHFType::SHL; return T_ROTSHF;
"shr"                   yylval.rotshf = AsmInstROTSHFType::SHR; return T_ROTSHF;
"stc"                       yylval.zo = AsmInstZOType::STC; return T_ZO;
"std"                       yylval.zo = AsmInstZOType::STD; return T_ZO;
"stos"                      yylval.zos = AsmInstZOSType::STOS; return T_ZOS;
"sti"                       yylval.zo = AsmInstZOType::STI; return T_ZO;
"sub"                       yylval.arith = AsmInstARITHType::SUB; return T_ARTH;
"test"                      return T_TEST;
"xchg"                      return T_XCHG;
"xlat"                      yylval.zo = AsmInstZOType::XLAT; return T_ZO;
"xor"                       yylval.arith = AsmInstARITHType::XOR; return T_ARTH;
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
"db"                        return T_DB;
"dw"                        return T_DW;
"dd"                        return T_DD;
"dq"                        return T_DQ;
"section"                   return T_SECTION;
"global"                    return T_GLOBAL;
[a-zA-Z_][a-zA-Z0-9_]*      SAVE_STRING; return T_IDENT;
"."[a-zA-Z_][a-zA-Z0-9_]*   SAVE_STRING; return T_SECTNAME;
.                           return *yytext;

%%
