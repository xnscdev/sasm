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
#include "directive.hh"
#include "error.hh"
#include "gen-obj.hh"
#include "intel-parse.hh"
#include "util.hh"

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
  AsmPointer *addr;
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
%token	<string>	T_SECTNAME "section name"
%token	<number>	T_NUMBER "number"
%token	<number>	T_CHAR "character literal"
%token T_BYTE "byte"
%token T_WORD "word"
%token T_DWORD "dword"
%token T_NEAR "near"
%token T_FAR "far"

%token	<arith>		T_ARTH "instruction mnemonic"
%token	<jf>		T_JF "instruction mnemonic"
%token	<zo>		T_ZO "instruction mnemonic"

%token T_AAD "instruction mnemonic"
%token T_AAM "instruction mnemonic"
%token T_CALL "instruction mnemonic"
%token T_CMPS "instruction mnemonic"
%token T_DEC "instruction mnemonic"
%token T_DIV "instruction mnemonic"
%token T_IDIV "instruction mnemonic"
%token T_IMUL "instruction mnemonic"
%token T_IN "instruction mnemonic"
%token T_INC "instruction mnemonic"
%token T_INS "instruction mnemonic"
%token T_INT "instruction mnemonic"
%token T_JMP "instruction mnemonic"
%token T_LEA "instruction mnemonic"
%token T_LODS "instruction mnemonic"
%token T_LOOP "instruction mnemonic"
%token T_LOOPNZ "instruction mnemonic"
%token T_LOOPZ "instruction mnemonic"
%token T_MOV "instruction mnemonic"
%token T_MOVS "instruction mnemonic"
%token T_MUL "instruction mnemonic"
%token T_NEG "instruction mnemonic"
%token T_NOT "instruction mnemonic"
%token T_OUT "instruction mnemonic"
%token T_OUTS "instruction mnemonic"
%token T_POP "instruction mnemonic"
%token T_PUSH "instruction mnemonic"
%token T_RCL "instruction mnemonic"
%token T_RCR "instruction mnemonic"
%token T_REPNZ "instruction mnemonic"
%token T_REPZ "instruction mnemonic"
%token T_RET "instruction mnemonic"
%token T_ROL "instruction mnemonic"
%token T_ROR "instruction mnemonic"
%token T_SAR "instruction mnemonic"
%token T_SCAS "instruction mnemonic"
%token T_SHL "instruction mnemonic"
%token T_SHR "instruction mnemonic"
%token T_STOS "instruction mnemonic"
%token T_TEST "instruction mnemonic"
%token T_XCHG "instruction mnemonic"

%token T_SECTION "section directive"
%token T_GLOBAL "global directive"

%token T_CS "register"
%token T_DS "register"
%token T_ES "register"
%token T_FS "register"
%token T_GS "register"
%token T_AL "register"
%token T_CL "register"
%token T_DL "register"
%token T_BL "register"
%token T_AH "register"
%token T_CH "register"
%token T_DH "register"
%token T_BH "register"
%token T_AX "register"
%token T_CX "register"
%token T_DX "register"
%token T_BX "register"
%token T_SP "register"
%token T_BP "register"
%token T_SI "register"
%token T_DI "register"
%token T_EAX "register"
%token T_ECX "register"
%token T_EDX "register"
%token T_EBX "register"
%token T_ESP "register"
%token T_EBP "register"
%token T_ESI "register"
%token T_EDI "register"

%type	<label>		label
%type	<lines>		lines
%type	<expr>		expression
%type	<imm>		immediate
%type	<inst>		instruction directive arith_inst jf_inst zo_inst
%type	<obj>		object
%type	<reg>		reg
%type	<mem>		memloc
%type	<storage>	storage
%type	<number>	size_specifier
%type	<addr>		addr

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

instruction:	arith_inst
	|	jf_inst
	|	zo_inst
	|	directive
	;

arith_inst:	T_ARTH storage ',' expression
		{
		  $$ = new AsmInstARITH ($1, $2, $4);
		}
	;

jf_inst:	T_JF addr { $$ = new AsmInstJF ($1, $2, 4); }
	;

zo_inst:	T_ZO { $$ = new AsmInstZO ($1); }
	;

directive:	T_GLOBAL T_IDENT { global_syms.insert (*$2); delete $2; }
	|	T_SECTION T_SECTNAME
		{
		  $$ = new AsmInstSECTION (*$2);
		  delete $2;
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

label:		T_IDENT ':' { $$ = new AsmIdentifier (*$1); delete $1; }
	|	T_IDENT
		{
		  warning ("label alone on a line without a colon");
		  $$ = new AsmIdentifier (*$1);
		  delete $1;
		}
	;

addr:	        T_IDENT { $$ = new AsmIdentifier (*$1); delete $1; }
	|	immediate { $$ = $1; }
	;
