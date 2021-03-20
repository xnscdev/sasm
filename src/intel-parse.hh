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
    T_NUMBER = 259,                /* "number"  */
    T_CHAR = 260,                  /* "character literal"  */
    T_BYTE = 261,                  /* "byte"  */
    T_WORD = 262,                  /* "word"  */
    T_DWORD = 263,                 /* "dword"  */
    T_NEAR = 264,                  /* "near"  */
    T_FAR = 265,                   /* "far"  */
    T_AAA = 266,                   /* "aaa"  */
    T_AAD = 267,                   /* "aad"  */
    T_AAM = 268,                   /* "aam"  */
    T_AAS = 269,                   /* "aas"  */
    T_ADC = 270,                   /* "adc"  */
    T_ADD = 271,                   /* "add"  */
    T_AND = 272,                   /* "and"  */
    T_CALL = 273,                  /* "call"  */
    T_CBW = 274,                   /* "cbw"  */
    T_CDQ = 275,                   /* "cdq"  */
    T_CLC = 276,                   /* "clc"  */
    T_CLD = 277,                   /* "cld"  */
    T_CLI = 278,                   /* "cli"  */
    T_CMP = 279,                   /* "cmp"  */
    T_CMPS = 280,                  /* "cmps"  */
    T_CWD = 281,                   /* "cwd"  */
    T_CWDE = 282,                  /* "cwde"  */
    T_DEC = 283,                   /* "dec"  */
    T_DIV = 284,                   /* "div"  */
    T_ENTER = 285,                 /* "enter"  */
    T_HLT = 286,                   /* "hlt"  */
    T_IDIV = 287,                  /* "idiv"  */
    T_IMUL = 288,                  /* "imul"  */
    T_IN = 289,                    /* "in"  */
    T_INC = 290,                   /* "inc"  */
    T_INS = 291,                   /* "ins"  */
    T_INT = 292,                   /* "int"  */
    T_INT3 = 293,                  /* "int3"  */
    T_INTO = 294,                  /* "into"  */
    T_IRET = 295,                  /* "iret"  */
    T_JO = 296,                    /* "jo"  */
    T_JNO = 297,                   /* "jno"  */
    T_JC = 298,                    /* "jc"  */
    T_JNC = 299,                   /* "jnc"  */
    T_JZ = 300,                    /* "jz"  */
    T_JNZ = 301,                   /* "jnz"  */
    T_JNA = 302,                   /* "jna"  */
    T_JA = 303,                    /* "ja"  */
    T_JS = 304,                    /* "js"  */
    T_JNS = 305,                   /* "jns"  */
    T_JP = 306,                    /* "jp"  */
    T_JNP = 307,                   /* "jnp"  */
    T_JL = 308,                    /* "jl"  */
    T_JNL = 309,                   /* "jnl"  */
    T_JNG = 310,                   /* "jng"  */
    T_JG = 311,                    /* "jg"  */
    T_JMP = 312,                   /* "jmp"  */
    T_LAHF = 313,                  /* "lahf"  */
    T_LEA = 314,                   /* "lea"  */
    T_LEAVE = 315,                 /* "leave"  */
    T_LODS = 316,                  /* "lods"  */
    T_LOOP = 317,                  /* "loop"  */
    T_LOOPNZ = 318,                /* "loopnz"  */
    T_LOOPZ = 319,                 /* "loopz"  */
    T_MOV = 320,                   /* "mov"  */
    T_MOVS = 321,                  /* "movs"  */
    T_MUL = 322,                   /* "mul"  */
    T_NEG = 323,                   /* "neg"  */
    T_NOT = 324,                   /* "not"  */
    T_OR = 325,                    /* "or"  */
    T_OUT = 326,                   /* "out"  */
    T_OUTS = 327,                  /* "outs"  */
    T_POP = 328,                   /* "pop"  */
    T_POPA = 329,                  /* "popa"  */
    T_POPF = 330,                  /* "popf"  */
    T_PUSH = 331,                  /* "push"  */
    T_PUSHA = 332,                 /* "pusha"  */
    T_PUSHF = 333,                 /* "pushf"  */
    T_RCL = 334,                   /* "rcl"  */
    T_RCR = 335,                   /* "rcr"  */
    T_REPNZ = 336,                 /* "repnz"  */
    T_REPZ = 337,                  /* "repz"  */
    T_RET = 338,                   /* "ret"  */
    T_ROL = 339,                   /* "rol"  */
    T_ROR = 340,                   /* "ror"  */
    T_SAHF = 341,                  /* "sahf"  */
    T_SAR = 342,                   /* "sar"  */
    T_SBB = 343,                   /* "sbb"  */
    T_SCAS = 344,                  /* "scas"  */
    T_SHL = 345,                   /* "shl"  */
    T_SHR = 346,                   /* "shr"  */
    T_STC = 347,                   /* "stc"  */
    T_STD = 348,                   /* "std"  */
    T_STOS = 349,                  /* "stos"  */
    T_STI = 350,                   /* "sti"  */
    T_SUB = 351,                   /* "sub"  */
    T_TEST = 352,                  /* "test"  */
    T_XCHG = 353,                  /* "xchg"  */
    T_XLAT = 354,                  /* "xlat"  */
    T_XOR = 355,                   /* "xor"  */
    T_CS = 356,                    /* "cs"  */
    T_DS = 357,                    /* "ds"  */
    T_ES = 358,                    /* "es"  */
    T_FS = 359,                    /* "fs"  */
    T_GS = 360,                    /* "gs"  */
    T_AL = 361,                    /* "al"  */
    T_CL = 362,                    /* "cl"  */
    T_DL = 363,                    /* "dl"  */
    T_BL = 364,                    /* "bl"  */
    T_AH = 365,                    /* "ah"  */
    T_CH = 366,                    /* "ch"  */
    T_DH = 367,                    /* "dh"  */
    T_BH = 368,                    /* "bh"  */
    T_AX = 369,                    /* "ax"  */
    T_CX = 370,                    /* "cx"  */
    T_DX = 371,                    /* "dx"  */
    T_BX = 372,                    /* "bx"  */
    T_SP = 373,                    /* "sp"  */
    T_BP = 374,                    /* "bp"  */
    T_SI = 375,                    /* "si"  */
    T_DI = 376,                    /* "di"  */
    T_EAX = 377,                   /* "eax"  */
    T_ECX = 378,                   /* "ecx"  */
    T_EDX = 379,                   /* "edx"  */
    T_EBX = 380,                   /* "ebx"  */
    T_ESP = 381,                   /* "esp"  */
    T_EBP = 382,                   /* "ebp"  */
    T_ESI = 383,                   /* "esi"  */
    T_EDI = 384                    /* "edi"  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif
/* Token kinds.  */
#define YYEMPTY -2
#define YYEOF 0
#define YYerror 256
#define YYUNDEF 257
#define T_IDENT 258
#define T_NUMBER 259
#define T_CHAR 260
#define T_BYTE 261
#define T_WORD 262
#define T_DWORD 263
#define T_NEAR 264
#define T_FAR 265
#define T_AAA 266
#define T_AAD 267
#define T_AAM 268
#define T_AAS 269
#define T_ADC 270
#define T_ADD 271
#define T_AND 272
#define T_CALL 273
#define T_CBW 274
#define T_CDQ 275
#define T_CLC 276
#define T_CLD 277
#define T_CLI 278
#define T_CMP 279
#define T_CMPS 280
#define T_CWD 281
#define T_CWDE 282
#define T_DEC 283
#define T_DIV 284
#define T_ENTER 285
#define T_HLT 286
#define T_IDIV 287
#define T_IMUL 288
#define T_IN 289
#define T_INC 290
#define T_INS 291
#define T_INT 292
#define T_INT3 293
#define T_INTO 294
#define T_IRET 295
#define T_JO 296
#define T_JNO 297
#define T_JC 298
#define T_JNC 299
#define T_JZ 300
#define T_JNZ 301
#define T_JNA 302
#define T_JA 303
#define T_JS 304
#define T_JNS 305
#define T_JP 306
#define T_JNP 307
#define T_JL 308
#define T_JNL 309
#define T_JNG 310
#define T_JG 311
#define T_JMP 312
#define T_LAHF 313
#define T_LEA 314
#define T_LEAVE 315
#define T_LODS 316
#define T_LOOP 317
#define T_LOOPNZ 318
#define T_LOOPZ 319
#define T_MOV 320
#define T_MOVS 321
#define T_MUL 322
#define T_NEG 323
#define T_NOT 324
#define T_OR 325
#define T_OUT 326
#define T_OUTS 327
#define T_POP 328
#define T_POPA 329
#define T_POPF 330
#define T_PUSH 331
#define T_PUSHA 332
#define T_PUSHF 333
#define T_RCL 334
#define T_RCR 335
#define T_REPNZ 336
#define T_REPZ 337
#define T_RET 338
#define T_ROL 339
#define T_ROR 340
#define T_SAHF 341
#define T_SAR 342
#define T_SBB 343
#define T_SCAS 344
#define T_SHL 345
#define T_SHR 346
#define T_STC 347
#define T_STD 348
#define T_STOS 349
#define T_STI 350
#define T_SUB 351
#define T_TEST 352
#define T_XCHG 353
#define T_XLAT 354
#define T_XOR 355
#define T_CS 356
#define T_DS 357
#define T_ES 358
#define T_FS 359
#define T_GS 360
#define T_AL 361
#define T_CL 362
#define T_DL 363
#define T_BL 364
#define T_AH 365
#define T_CH 366
#define T_DH 367
#define T_BH 368
#define T_AX 369
#define T_CX 370
#define T_DX 371
#define T_BX 372
#define T_SP 373
#define T_BP 374
#define T_SI 375
#define T_DI 376
#define T_EAX 377
#define T_ECX 378
#define T_EDX 379
#define T_EBX 380
#define T_ESP 381
#define T_EBP 382
#define T_ESI 383
#define T_EDI 384

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 37 "../../src/intel-parse.yy"

  long long number;
  std::string *string;

  std::vector <AsmInst *> *instlist;
  AsmLabel *label;
  AsmInst *inst;
  AsmExpr *expr;
  AsmStorage *storage;
  AsmRegister *reg;
  AsmMemoryLoc *mem;
  Object *obj;

#line 339 "../../src/intel-parse.hh"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY__SRC_INTEL_PARSE_HH_INCLUDED  */
