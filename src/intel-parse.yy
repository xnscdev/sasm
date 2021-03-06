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
  AsmInstROTSHFType rotshf;
  AsmInstZOType zo;
  AsmInstZOSType zos;
  long long number;
  std::string *string;

  std::vector <AsmLine *> *lines;
  AsmPointer *addr;
  AsmImmediate *imm;
  AsmIdentifier *label;
  AsmDirective *directive;
  AsmInst *inst;
  AsmStringInst *strinst;
  AsmExpr *expr;
  AsmStorage *storage;
  AsmRegister *reg;
  AsmMemoryLoc *mem;
  Object *obj;
}

%define parse.error detailed
%locations

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
%token	<zos>		T_ZOS "instruction mnemonic"
%token	<rotshf>	T_ROTSHF "instruction mnemonic"

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
%token T_NOP "instruction mnemonic"
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

%token T_DB "directive"
%token T_DW "directive"
%token T_DD "directive"
%token T_DQ "directive"

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
%type	<directive>	directive
%type	<inst>		instruction ascii_inst call_inst port_inst
%type	<inst>		jmp_inst rep_inst
%type	<strinst>	string_inst
%type	<obj>		object
%type	<reg>		reg segment
%type	<mem>		memloc deref
%type	<storage>	storage
%type	<number>	size_specifier define_size
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

instruction:	T_ARTH storage ',' expression
		{
		  $$ = new AsmInstARITH ($1, $2, $4);
		}
	|	T_JF addr { $$ = new AsmInstJF ($1, $2, 4); }
	|	T_ZO { $$ = new AsmInstZO ($1); }
	|	string_inst { $$ = $1; }
	|	ascii_inst
	|	call_inst
	|	T_DEC storage { $$ = new AsmInstDEC ($2); }
	|	T_DIV storage { $$ = new AsmInstDIV ($2); }
	|	T_IDIV storage { $$ = new AsmInstIDIV ($2); }
	|	T_IMUL storage { $$ = new AsmInstIMUL ($2); }
	|	T_INC storage { $$ = new AsmInstINC ($2); }
	|	port_inst
	|	T_INT T_NUMBER { $$ = new AsmInstINT ($2); }
	|	jmp_inst
	|	T_LEA reg ',' memloc { $$ = new AsmInstLEA ($2, $4); }
	|	T_LOOP addr { $$ = new AsmInstLOOP ($2); }
	|	T_LOOPNZ addr { $$ = new AsmInstLOOPNZ ($2); }
	|	T_LOOPZ addr { $$ = new AsmInstLOOPZ ($2); }
	|	T_MOV storage ',' expression { $$ = new AsmInstMOV ($2, $4); }
	|	T_MUL storage { $$ = new AsmInstMUL ($2); }
	|	T_NEG storage { $$ = new AsmInstNEG ($2); }
	|	T_NOP
		{
		  $$ = new AsmInstXCHG (AsmRegister::EAX, AsmRegister::EAX);
		}
	|	T_NOT storage { $$ = new AsmInstNOT ($2); }
	|	T_POP storage { $$ = new AsmInstPOP ($2); }
	|	T_PUSH storage { $$ = new AsmInstPUSH ($2); }
	|	rep_inst
	|	T_RET { $$ = new AsmInstRET (false); }
	|	T_RET T_NEAR { $$ = new AsmInstRET (false); }
	|	T_RET T_NUMBER { $$ = new AsmInstRET (false, $2); }
	|	T_RET T_NEAR T_NUMBER { $$ = new AsmInstRET (false, $3); }
	|	T_RET T_FAR { $$ = new AsmInstRET (true); }
	|	T_RET T_FAR T_NUMBER { $$ = new AsmInstRET (true, $3); }
	|	T_ROTSHF storage { $$ = new AsmInstROTSHF ($1, $2, 1); }
	|	T_ROTSHF storage ',' T_NUMBER
		{
		  $$ = new AsmInstROTSHF ($1, $2, $4);
		}
	|	T_ROTSHF storage ',' T_CL { $$ = new AsmInstROTSHF ($1, $2); }
	|	T_TEST storage ',' expression { $$ = new AsmInstTEST ($2, $4); }
	|	T_XCHG storage ',' storage { $$ = new AsmInstXCHG ($2, $4); }
	|	directive { $$ = $1; }
	;

ascii_inst:	T_AAD T_NUMBER { $$ = new AsmInstAAD ($2); }
	|	T_AAD { $$ = new AsmInstAAD (); }
	|	T_AAM T_NUMBER { $$ = new AsmInstAAM ($2); }
	|	T_AAM { $$ = new AsmInstAAM (); }
	;

call_inst:	T_CALL addr { $$ = new AsmInstCALL ($2, 4); }
	|	T_CALL T_NEAR addr { $$ = new AsmInstCALL ($3, 4); }
	|	T_CALL T_NUMBER ':' T_NUMBER { $$ = new AsmInstCALLF ($2, $4); }
	|	T_CALL T_FAR T_NUMBER ':' T_NUMBER
		{
		  $$ = new AsmInstCALLF ($3, $5);
		}
	|	T_CALL storage { $$ = new AsmInstCALL ($2); }
	|	T_CALL T_NEAR storage { $$ = new AsmInstCALL ($3); }
	|	T_CALL T_FAR memloc { $$ = new AsmInstCALLF ($3); }
	;

port_inst:	T_IN T_AL ',' T_NUMBER { $$ = new AsmInstIN ($4, 1); }
	|	T_IN T_AL ',' T_DX { $$ = new AsmInstIN (1); }
	|	T_IN T_AX ',' T_NUMBER { $$ = new AsmInstIN ($4, 2); }
	|	T_IN T_AX ',' T_DX { $$ = new AsmInstIN (2); }
	|	T_IN T_EAX ',' T_NUMBER { $$ = new AsmInstIN ($4, 4); }
	|	T_IN T_EAX ',' T_DX { $$ = new AsmInstIN (4); }
	|	T_OUT T_NUMBER ',' T_AL { $$ = new AsmInstOUT ($2, 1); }
	|	T_OUT T_DX ',' T_AL { $$ = new AsmInstOUT (1); }
	|	T_OUT T_NUMBER ',' T_AX { $$ = new AsmInstOUT ($2, 2); }
	|	T_OUT T_DX ',' T_AX { $$ = new AsmInstOUT (2); }
	|	T_OUT T_NUMBER ',' T_EAX { $$ = new AsmInstOUT ($2, 4); }
	|	T_OUT T_DX ',' T_EAX { $$ = new AsmInstOUT (4); }
	;

jmp_inst:	T_JMP addr { $$ = new AsmInstJMP ($2, 4); }
	|	T_JMP T_NEAR addr { $$ = new AsmInstJMP ($3, 4); }
	|	T_JMP T_NUMBER ':' T_NUMBER { $$ = new AsmInstJMPF ($2, $4); }
	|	T_JMP T_FAR T_NUMBER ':' T_NUMBER
		{
		  $$ = new AsmInstJMPF ($3, $5);
		}
	|	T_JMP storage { $$ = new AsmInstJMP ($2); }
	|	T_JMP T_NEAR storage { $$ = new AsmInstJMP ($3); }
	|	T_JMP T_FAR memloc { $$ = new AsmInstJMPF ($3); }
	;

string_inst:	T_ZOS size_specifier { $$ = new AsmInstZOS ($1, $2); }
	;

rep_inst:	T_REPNZ string_inst { $$ = new AsmInstREPNZ ($2); }
	|	T_REPZ string_inst { $$ = new AsmInstREPZ ($2); }
	;

directive:	T_GLOBAL T_IDENT
		{
		  $$ = nullptr;
		  global_syms.insert (*$2);
		  delete $2;
		}
	|	T_SECTION T_SECTNAME
		{
		  $$ = new AsmInstSECTION (*$2);
		  delete $2;
		}
	|	define_size T_NUMBER { $$ = new AsmInstDEFINE ($1, $2); }
	;

expression:	immediate { $$ = $1; }
	|	storage { $$ = $1; }
	;

immediate:	T_NUMBER { $$ = new AsmImmediate ($1); }
	;

storage:	reg { $$ = $1; }
	|	memloc { $$ = $1; }
	;

memloc:		size_specifier '[' deref ']' { $$ = $3; $$->size = $1; }
	|	size_specifier '[' segment ':' deref ']'
		{
		  $$ = $5;
		  $$->segment = $3;
		  $$->size = $1;
		}
	;

deref:		T_NUMBER
	        {
		  $$ = new AsmMemoryLoc (nullptr, nullptr, 0, $1,
					 AsmRegister::DS, 0);
		}
	|	reg
		{
		  $$ = new AsmMemoryLoc ($1, nullptr, 0, 0,
					 $1->id == AsmRegister::EBP->id ?
					 AsmRegister::SS : AsmRegister::DS, 0);
		}
	|	reg '+' T_NUMBER
	        {
		  $$ = new AsmMemoryLoc ($1, nullptr, 0, $3,
					 $1->id == AsmRegister::EBP->id ?
					 AsmRegister::SS : AsmRegister::DS, 0);
		}
	|	reg '+' reg
		{
		  $$ = new AsmMemoryLoc ($1, $3, 1, 0,
					 $1->id == AsmRegister::EBP->id ?
					 AsmRegister::SS : AsmRegister::DS, 0);
		}
	|	reg '+' reg '+' T_NUMBER
		{
		  $$ = new AsmMemoryLoc ($1, $3, 1, $5,
					 $1->id == AsmRegister::EBP->id ?
					 AsmRegister::SS : AsmRegister::DS, 0);
		}
	|	reg '+' reg '*' T_NUMBER
		{
		  $$ = new AsmMemoryLoc ($1, $3, $5, 0,
					 $1->id == AsmRegister::EBP->id ?
					 AsmRegister::SS : AsmRegister::DS, 0);
		}
	|	reg '+' reg '*' T_NUMBER '+' T_NUMBER
		{
		  $$ = new AsmMemoryLoc ($1, $3, $5, $7,
					 $1->id == AsmRegister::EBP->id ?
					 AsmRegister::SS : AsmRegister::DS, 0);
		}
	;

reg:	        segment
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

segment:	T_CS { $$ = AsmRegister::CS; }
	|       T_DS { $$ = AsmRegister::DS; }
	|       T_ES { $$ = AsmRegister::ES; }
	|       T_FS { $$ = AsmRegister::FS; }
	|       T_GS { $$ = AsmRegister::GS; }
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

define_size:	T_DB { $$ = 1; }
	|	T_DW { $$ = 2; }
	|	T_DD { $$ = 4; }
	|	T_DQ { $$ = 8; }
	;
