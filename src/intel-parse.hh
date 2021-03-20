/* A Bison parser, made by GNU Bison 3.7.5.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY__SRC_INTEL_PARSE_HH_INCLUDED
# define YY_YY__SRC_INTEL_PARSE_HH_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    T_IDENT = 258,                 /* "identifier"  */
    T_SECTNAME = 259,              /* "section name"  */
    T_NUMBER = 260,                /* "number"  */
    T_CHAR = 261,                  /* "character literal"  */
    T_BYTE = 262,                  /* "byte"  */
    T_WORD = 263,                  /* "word"  */
    T_DWORD = 264,                 /* "dword"  */
    T_NEAR = 265,                  /* "near"  */
    T_FAR = 266,                   /* "far"  */
    T_ARTH = 267,                  /* "instruction mnemonic"  */
    T_JF = 268,                    /* T_JF  */
    T_ZO = 269,                    /* T_ZO  */
    T_ZOS = 270,                   /* T_ZOS  */
    T_AAD = 271,                   /* T_AAD  */
    T_AAM = 272,                   /* T_AAM  */
    T_CALL = 273,                  /* T_CALL  */
    T_CMPS = 274,                  /* T_CMPS  */
    T_DEC = 275,                   /* T_DEC  */
    T_DIV = 276,                   /* T_DIV  */
    T_IDIV = 277,                  /* T_IDIV  */
    T_IMUL = 278,                  /* T_IMUL  */
    T_IN = 279,                    /* T_IN  */
    T_INC = 280,                   /* T_INC  */
    T_INS = 281,                   /* T_INS  */
    T_INT = 282,                   /* T_INT  */
    T_JMP = 283,                   /* T_JMP  */
    T_LEA = 284,                   /* T_LEA  */
    T_LODS = 285,                  /* T_LODS  */
    T_LOOP = 286,                  /* T_LOOP  */
    T_LOOPNZ = 287,                /* T_LOOPNZ  */
    T_LOOPZ = 288,                 /* T_LOOPZ  */
    T_MOV = 289,                   /* T_MOV  */
    T_MOVS = 290,                  /* T_MOVS  */
    T_MUL = 291,                   /* T_MUL  */
    T_NEG = 292,                   /* T_NEG  */
    T_NOT = 293,                   /* T_NOT  */
    T_OUT = 294,                   /* T_OUT  */
    T_OUTS = 295,                  /* T_OUTS  */
    T_POP = 296,                   /* T_POP  */
    T_PUSH = 297,                  /* T_PUSH  */
    T_RCL = 298,                   /* T_RCL  */
    T_RCR = 299,                   /* T_RCR  */
    T_REPNZ = 300,                 /* T_REPNZ  */
    T_REPZ = 301,                  /* T_REPZ  */
    T_RET = 302,                   /* T_RET  */
    T_ROL = 303,                   /* T_ROL  */
    T_ROR = 304,                   /* T_ROR  */
    T_SAR = 305,                   /* T_SAR  */
    T_SCAS = 306,                  /* T_SCAS  */
    T_SHL = 307,                   /* T_SHL  */
    T_SHR = 308,                   /* T_SHR  */
    T_STOS = 309,                  /* T_STOS  */
    T_TEST = 310,                  /* T_TEST  */
    T_XCHG = 311,                  /* T_XCHG  */
    T_DB = 312,                    /* "directive"  */
    T_DW = 313,                    /* T_DW  */
    T_DD = 314,                    /* T_DD  */
    T_DQ = 315,                    /* T_DQ  */
    T_SECTION = 316,               /* "section directive"  */
    T_GLOBAL = 317,                /* "global directive"  */
    T_CS = 318,                    /* "register"  */
    T_DS = 319,                    /* T_DS  */
    T_ES = 320,                    /* T_ES  */
    T_FS = 321,                    /* T_FS  */
    T_GS = 322,                    /* T_GS  */
    T_AL = 323,                    /* T_AL  */
    T_CL = 324,                    /* T_CL  */
    T_DL = 325,                    /* T_DL  */
    T_BL = 326,                    /* T_BL  */
    T_AH = 327,                    /* T_AH  */
    T_CH = 328,                    /* T_CH  */
    T_DH = 329,                    /* T_DH  */
    T_BH = 330,                    /* T_BH  */
    T_AX = 331,                    /* T_AX  */
    T_CX = 332,                    /* T_CX  */
    T_DX = 333,                    /* T_DX  */
    T_BX = 334,                    /* T_BX  */
    T_SP = 335,                    /* T_SP  */
    T_BP = 336,                    /* T_BP  */
    T_SI = 337,                    /* T_SI  */
    T_DI = 338,                    /* T_DI  */
    T_EAX = 339,                   /* T_EAX  */
    T_ECX = 340,                   /* T_ECX  */
    T_EDX = 341,                   /* T_EDX  */
    T_EBX = 342,                   /* T_EBX  */
    T_ESP = 343,                   /* T_ESP  */
    T_EBP = 344,                   /* T_EBP  */
    T_ESI = 345,                   /* T_ESI  */
    T_EDI = 346                    /* T_EDI  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif
/* Token kinds.  */
#define YYEMPTY -2
#define YYEOF 0
#define YYerror 256
#define YYUNDEF 257
#define T_IDENT 258
#define T_SECTNAME 259
#define T_NUMBER 260
#define T_CHAR 261
#define T_BYTE 262
#define T_WORD 263
#define T_DWORD 264
#define T_NEAR 265
#define T_FAR 266
#define T_ARTH 267
#define T_JF 268
#define T_ZO 269
#define T_ZOS 270
#define T_AAD 271
#define T_AAM 272
#define T_CALL 273
#define T_CMPS 274
#define T_DEC 275
#define T_DIV 276
#define T_IDIV 277
#define T_IMUL 278
#define T_IN 279
#define T_INC 280
#define T_INS 281
#define T_INT 282
#define T_JMP 283
#define T_LEA 284
#define T_LODS 285
#define T_LOOP 286
#define T_LOOPNZ 287
#define T_LOOPZ 288
#define T_MOV 289
#define T_MOVS 290
#define T_MUL 291
#define T_NEG 292
#define T_NOT 293
#define T_OUT 294
#define T_OUTS 295
#define T_POP 296
#define T_PUSH 297
#define T_RCL 298
#define T_RCR 299
#define T_REPNZ 300
#define T_REPZ 301
#define T_RET 302
#define T_ROL 303
#define T_ROR 304
#define T_SAR 305
#define T_SCAS 306
#define T_SHL 307
#define T_SHR 308
#define T_STOS 309
#define T_TEST 310
#define T_XCHG 311
#define T_DB 312
#define T_DW 313
#define T_DD 314
#define T_DQ 315
#define T_SECTION 316
#define T_GLOBAL 317
#define T_CS 318
#define T_DS 319
#define T_ES 320
#define T_FS 321
#define T_GS 322
#define T_AL 323
#define T_CL 324
#define T_DL 325
#define T_BL 326
#define T_AH 327
#define T_CH 328
#define T_DH 329
#define T_BH 330
#define T_AX 331
#define T_CX 332
#define T_DX 333
#define T_BX 334
#define T_SP 335
#define T_BP 336
#define T_SI 337
#define T_DI 338
#define T_EAX 339
#define T_ECX 340
#define T_EDX 341
#define T_EBX 342
#define T_ESP 343
#define T_EBP 344
#define T_ESI 345
#define T_EDI 346

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 40 "../../src/intel-parse.yy"

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

#line 269 "../../src/intel-parse.hh"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY__SRC_INTEL_PARSE_HH_INCLUDED  */
