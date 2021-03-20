/*************************************************************************
 * intel-parse.yy -- This file is part of sasm.                          *
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

#include <string>
#include "expr.hh"
#include "intel-parse.hh"

int yylex (void);
void yyerror (const char *s);

extern std::string filename;
extern AsmTranslationUnit *result;

%}

%union
{
  long long number;
  std::string *string;

  AsmLabel *label;
  AsmExpr *expr;
  AsmTranslationUnit *transunit;
}

%define parse.error detailed

%token	<string>	T_IDENT "identifier"
%token	<number>	T_NUMBER "number"
%token	<number>	T_CHAR "character literal"
%token T_BYTE "byte"
%token T_WORD "word"
%token T_DWORD "dword"
%token T_NEAR "near"
%token T_FAR "far"
%token T_AAA "aaa"
%token T_AAD "aad"
%token T_AAM "aam"
%token T_AAS "aas"
%token T_ADC "adc"
%token T_ADD "add"
%token T_AND "and"
%token T_CALL "call"
%token T_CBW "cbw"
%token T_CDQ "cdq"
%token T_CLC "clc"
%token T_CLD "cld"
%token T_CLI "cli"
%token T_CMP "cmp"
%token T_CMPS "cmps"
%token T_CWD "cwd"
%token T_CWDE "cwde"
%token T_DEC "dec"
%token T_DIV "div"
%token T_ENTER "enter"
%token T_HLT "hlt"
%token T_IDIV "idiv"
%token T_IMUL "imul"
%token T_IN "in"
%token T_INC "inc"
%token T_INS "ins"
%token T_INT "int"
%token T_INT3 "int3"
%token T_INTO "into"
%token T_IRET "iret"
%token T_JO "jo"
%token T_JNO "jno"
%token T_JC "jc"
%token T_JNC "jnc"
%token T_JZ "jz"
%token T_JNZ "jnz"
%token T_JNA "jna"
%token T_JA "ja"
%token T_JS "js"
%token T_JNS "jns"
%token T_JP "jp"
%token T_JNP "jnp"
%token T_JL "jl"
%token T_JNL "jnl"
%token T_JNG "jng"
%token T_JG "jg"
%token T_JMP "jmp"
%token T_LAHF "lahf"
%token T_LEA "lea"
%token T_LEAVE "leave"
%token T_LODS "lods"
%token T_LOOP "loop"
%token T_LOOPNZ "loopnz"
%token T_LOOPZ "loopz"
%token T_MOV "mov"
%token T_MOVS "movs"
%token T_MUL "mul"
%token T_NEG "neg"
%token T_NOT "not"
%token T_OR "or"
%token T_OUT "out"
%token T_OUTS "outs"
%token T_POP "pop"
%token T_POPA "popa"
%token T_POPF "popf"
%token T_PUSH "push"
%token T_PUSHA "pusha"
%token T_PUSHF "pushf"
%token T_RCL "rcl"
%token T_RCR "rcr"
%token T_REPNZ "repnz"
%token T_REPZ "repz"
%token T_RET "ret"
%token T_ROL "rol"
%token T_ROR "ror"
%token T_SAHF "sahf"
%token T_SAR "sar"
%token T_SBB "sbb"
%token T_SCAS "scas"
%token T_SHL "shl"
%token T_SHR "shr"
%token T_STC "stc"
%token T_STD "std"
%token T_STOS "stos"
%token T_STI "sti"
%token T_SUB "sub"
%token T_TEST "test"
%token T_XCHG "xchg"
%token T_XLAT "xlat"
%token T_XOR "xor"

%type	<label>		label
%type	<expr>		lines expression immediate
%type	<transunit>	translation_unit

%start program

%%

program:        translation_unit { result = $1; }
	;

translation_unit:
	|	lines { $$ = new AsmTranslationUnit (filename); }
	;

lines:		expression '\n'
	|	lines expression '\n'
	;

expression:	immediate
	;

immediate:	T_NUMBER { $$ = new AsmImmediate ($1); printf ("%lld\n", $1); }
	;
