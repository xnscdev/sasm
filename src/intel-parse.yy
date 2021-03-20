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

#define _COFF_DISABLE_DEFINES /* Prevent name clashes with Yacc defines */

#include <string>
#include "gen-obj.hh"
#include "intel-parse.hh"

int yylex (void);
void yyerror (const char *s);

extern std::string filename;
extern ObjectFileFormat format;
extern Object *result;

%}

%union
{
  AsmInstARITHType arith;
  AsmInstJFType jf;
  AsmInstZOType zo;
  AsmInstZOSType zos;
  long long number;
  std::string *string;

  std::vector <AsmLine *> *lines;
  AsmImmediate *imm;
  AsmIdentifier *label;
  AsmInst *inst;
  AsmExpr *expr;
  AsmStorage *storage;
  AsmRegister *reg;
  AsmMemoryLoc *mem;
  Object *obj;
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

%token	<arith>		T_ADC "adc"
%token	<arith>		T_ADD "add"
%token	<arith>		T_AND "and"
%token	<arith>		T_CMP "cmp"
%token	<arith>		T_OR "or"
%token	<arith>		T_SBB "sbb"
%token	<arith>		T_SUB "sub"
%token	<arith>		T_XOR "xor"

%token	<jf>		T_JO "jo"
%token	<jf>		T_JNO "jno"
%token	<jf>		T_JC "jc"
%token	<jf>		T_JNC "jnc"
%token	<jf>		T_JZ "jz"
%token	<jf>		T_JNZ "jnz"
%token	<jf>		T_JNA "jna"
%token	<jf>		T_JA "ja"
%token	<jf>		T_JS "js"
%token	<jf>		T_JNS "jns"
%token	<jf>		T_JP "jp"
%token	<jf>		T_JNP "jnp"
%token	<jf>		T_JL "jl"
%token	<jf>		T_JNL "jnl"
%token	<jf>		T_JNG "jng"
%token	<jf>		T_JG "jg"

%token T_AAA "aaa"
%token T_AAD "aad"
%token T_AAM "aam"
%token T_AAS "aas"
%token T_CALL "call"
%token T_CBW "cbw"
%token T_CDQ "cdq"
%token T_CLC "clc"
%token T_CLD "cld"
%token T_CLI "cli"
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
%token T_SCAS "scas"
%token T_SHL "shl"
%token T_SHR "shr"
%token T_STC "stc"
%token T_STD "std"
%token T_STOS "stos"
%token T_STI "sti"
%token T_TEST "test"
%token T_XCHG "xchg"
%token T_XLAT "xlat"

%token T_CS "cs"
%token T_DS "ds"
%token T_ES "es"
%token T_FS "fs"
%token T_GS "gs"
%token T_AL "al"
%token T_CL "cl"
%token T_DL "dl"
%token T_BL "bl"
%token T_AH "ah"
%token T_CH "ch"
%token T_DH "dh"
%token T_BH "bh"
%token T_AX "ax"
%token T_CX "cx"
%token T_DX "dx"
%token T_BX "bx"
%token T_SP "sp"
%token T_BP "bp"
%token T_SI "si"
%token T_DI "di"
%token T_EAX "eax"
%token T_ECX "ecx"
%token T_EDX "edx"
%token T_EBX "ebx"
%token T_ESP "esp"
%token T_EBP "ebp"
%token T_ESI "esi"
%token T_EDI "edi"

%type	<arith>		arith_operator
%type	<label>		label
%type	<lines>		lines
%type	<expr>		expression
%type	<imm>		immediate
%type	<inst>		instruction arith_instruction
%type	<obj>		object
%type	<reg>		reg
%type	<mem>		memloc
%type	<storage>	storage
%type	<number>	size_specifier

%start program

%%

program:        object { result = $1; }
	;

object:		lines
		{
		  $$ = new Object (format, filename);
		  $$->lines = *$1;
		  delete $1;
		}
	;

lines:		instruction
		{
		  $$ = new std::vector <AsmLine *> ();
		  $$->push_back ($1);
		}
	|	label
		{
		  $$ = new std::vector <AsmLine *> ();
		  $$->push_back ($1);
		}
	|	lines terminator instruction { $1->push_back ($3); }
	|	lines terminator label { $1->push_back ($3); }
	|	lines terminator
	;

instruction:	arith_instruction
	;

arith_instruction:
		arith_operator storage ',' expression
		{
		  $$ = new AsmInstARITH ($1, $2, $4);
		}
	;

expression:	immediate { $$ = $1; }
	|	storage { $$ = $1; }
	;

immediate:	T_NUMBER { $$ = new AsmImmediate ($1); }
	;

storage:	reg { $$ = $1; }
	|	memloc { $$ = $1; }
	;

memloc:		size_specifier '[' T_NUMBER ']'
		{
		  $$ = new AsmMemoryLoc (nullptr, nullptr, 0, $3,
					 AsmRegister::DS, $1);
		}
	;

reg:		T_CS { $$ = AsmRegister::CS; }
	|       T_DS { $$ = AsmRegister::DS; }
	|       T_ES { $$ = AsmRegister::ES; }
	|       T_FS { $$ = AsmRegister::FS; }
	|       T_GS { $$ = AsmRegister::GS; }
	|       T_AL { $$ = AsmRegister::AL; }
	|       T_CL { $$ = AsmRegister::CL; }
	|       T_DL { $$ = AsmRegister::DL; }
	|       T_BL { $$ = AsmRegister::BL; }
	|       T_AH { $$ = AsmRegister::AH; }
	|       T_CH { $$ = AsmRegister::CH; }
	|       T_DH { $$ = AsmRegister::DH; }
	|       T_BH { $$ = AsmRegister::BH; }
	|       T_AX { $$ = AsmRegister::AX; }
	|       T_CX { $$ = AsmRegister::CX; }
	|       T_DX { $$ = AsmRegister::DX; }
	|       T_BX { $$ = AsmRegister::BX; }
	|       T_SP { $$ = AsmRegister::SP; }
	|       T_BP { $$ = AsmRegister::BP; }
	|       T_SI { $$ = AsmRegister::SI; }
	|       T_DI { $$ = AsmRegister::DI; }
	|       T_EAX { $$ = AsmRegister::EAX; }
	|       T_ECX { $$ = AsmRegister::ECX; }
	|       T_EDX { $$ = AsmRegister::EDX; }
	|       T_EBX { $$ = AsmRegister::EBX; }
	|       T_ESP { $$ = AsmRegister::ESP; }
	|       T_EBP { $$ = AsmRegister::EBP; }
	|       T_ESI { $$ = AsmRegister::ESI; }
	|       T_EDI { $$ = AsmRegister::EDI; }
	;

size_specifier:	T_BYTE { $$ = 1; }
	|	T_WORD { $$ = 2; }
	|	T_DWORD { $$ = 4; }
	;

terminator:	';'
	|	'\n'
	;

arith_operator:	T_ADC
	|	T_ADD
	|	T_AND
	|	T_CMP
	|	T_OR
	|	T_SBB
	|	T_SUB
	|	T_XOR
	;

label:		T_IDENT ':' { $$ = new AsmIdentifier (*$1); delete $1; }
	;
