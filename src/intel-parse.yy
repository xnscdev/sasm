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
