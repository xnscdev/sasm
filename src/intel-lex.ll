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

#include "expr.hh"
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
[a-zA-Z_][a-zA-Z0-9_]*      SAVE_STRING; return T_IDENT;
.                           return *yytext;

%%
