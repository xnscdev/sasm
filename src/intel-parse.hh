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
    T_ADC = 266,                   /* "adc"  */
    T_ADD = 267,                   /* "add"  */
    T_AND = 268,                   /* "and"  */
    T_CMP = 269,                   /* "cmp"  */
    T_OR = 270,                    /* "or"  */
    T_SBB = 271,                   /* "sbb"  */
    T_SUB = 272,                   /* "sub"  */
    T_XOR = 273,                   /* "xor"  */
    T_JO = 274,                    /* "jo"  */
    T_JNO = 275,                   /* "jno"  */
    T_JC = 276,                    /* "jc"  */
    T_JNC = 277,                   /* "jnc"  */
    T_JZ = 278,                    /* "jz"  */
    T_JNZ = 279,                   /* "jnz"  */
    T_JNA = 280,                   /* "jna"  */
    T_JA = 281,                    /* "ja"  */
    T_JS = 282,                    /* "js"  */
    T_JNS = 283,                   /* "jns"  */
    T_JP = 284,                    /* "jp"  */
    T_JNP = 285,                   /* "jnp"  */
    T_JL = 286,                    /* "jl"  */
    T_JNL = 287,                   /* "jnl"  */
    T_JNG = 288,                   /* "jng"  */
    T_JG = 289,                    /* "jg"  */
    T_AAA = 290,                   /* "aaa"  */
    T_AAD = 291,                   /* "aad"  */
    T_AAM = 292,                   /* "aam"  */
    T_AAS = 293,                   /* "aas"  */
    T_CALL = 294,                  /* "call"  */
    T_CBW = 295,                   /* "cbw"  */
    T_CDQ = 296,                   /* "cdq"  */
    T_CLC = 297,                   /* "clc"  */
    T_CLD = 298,                   /* "cld"  */
    T_CLI = 299,                   /* "cli"  */
    T_CMPS = 300,                  /* "cmps"  */
    T_CWD = 301,                   /* "cwd"  */
    T_CWDE = 302,                  /* "cwde"  */
    T_DEC = 303,                   /* "dec"  */
    T_DIV = 304,                   /* "div"  */
    T_ENTER = 305,                 /* "enter"  */
    T_HLT = 306,                   /* "hlt"  */
    T_IDIV = 307,                  /* "idiv"  */
    T_IMUL = 308,                  /* "imul"  */
    T_IN = 309,                    /* "in"  */
    T_INC = 310,                   /* "inc"  */
    T_INS = 311,                   /* "ins"  */
    T_INT = 312,                   /* "int"  */
    T_INT3 = 313,                  /* "int3"  */
    T_INTO = 314,                  /* "into"  */
    T_IRET = 315,                  /* "iret"  */
    T_JMP = 316,                   /* "jmp"  */
    T_LAHF = 317,                  /* "lahf"  */
    T_LEA = 318,                   /* "lea"  */
    T_LEAVE = 319,                 /* "leave"  */
    T_LODS = 320,                  /* "lods"  */
    T_LOOP = 321,                  /* "loop"  */
    T_LOOPNZ = 322,                /* "loopnz"  */
    T_LOOPZ = 323,                 /* "loopz"  */
    T_MOV = 324,                   /* "mov"  */
    T_MOVS = 325,                  /* "movs"  */
    T_MUL = 326,                   /* "mul"  */
    T_NEG = 327,                   /* "neg"  */
    T_NOT = 328,                   /* "not"  */
    T_OUT = 329,                   /* "out"  */
    T_OUTS = 330,                  /* "outs"  */
    T_POP = 331,                   /* "pop"  */
    T_POPA = 332,                  /* "popa"  */
    T_POPF = 333,                  /* "popf"  */
    T_PUSH = 334,                  /* "push"  */
    T_PUSHA = 335,                 /* "pusha"  */
    T_PUSHF = 336,                 /* "pushf"  */
    T_RCL = 337,                   /* "rcl"  */
    T_RCR = 338,                   /* "rcr"  */
    T_REPNZ = 339,                 /* "repnz"  */
    T_REPZ = 340,                  /* "repz"  */
    T_RET = 341,                   /* "ret"  */
    T_ROL = 342,                   /* "rol"  */
    T_ROR = 343,                   /* "ror"  */
    T_SAHF = 344,                  /* "sahf"  */
    T_SAR = 345,                   /* "sar"  */
    T_SCAS = 346,                  /* "scas"  */
    T_SHL = 347,                   /* "shl"  */
    T_SHR = 348,                   /* "shr"  */
    T_STC = 349,                   /* "stc"  */
    T_STD = 350,                   /* "std"  */
    T_STOS = 351,                  /* "stos"  */
    T_STI = 352,                   /* "sti"  */
    T_TEST = 353,                  /* "test"  */
    T_XCHG = 354,                  /* "xchg"  */
    T_XLAT = 355,                  /* "xlat"  */
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
#define T_ADC 266
#define T_ADD 267
#define T_AND 268
#define T_CMP 269
#define T_OR 270
#define T_SBB 271
#define T_SUB 272
#define T_XOR 273
#define T_JO 274
#define T_JNO 275
#define T_JC 276
#define T_JNC 277
#define T_JZ 278
#define T_JNZ 279
#define T_JNA 280
#define T_JA 281
#define T_JS 282
#define T_JNS 283
#define T_JP 284
#define T_JNP 285
#define T_JL 286
#define T_JNL 287
#define T_JNG 288
#define T_JG 289
#define T_AAA 290
#define T_AAD 291
#define T_AAM 292
#define T_AAS 293
#define T_CALL 294
#define T_CBW 295
#define T_CDQ 296
#define T_CLC 297
#define T_CLD 298
#define T_CLI 299
#define T_CMPS 300
#define T_CWD 301
#define T_CWDE 302
#define T_DEC 303
#define T_DIV 304
#define T_ENTER 305
#define T_HLT 306
#define T_IDIV 307
#define T_IMUL 308
#define T_IN 309
#define T_INC 310
#define T_INS 311
#define T_INT 312
#define T_INT3 313
#define T_INTO 314
#define T_IRET 315
#define T_JMP 316
#define T_LAHF 317
#define T_LEA 318
#define T_LEAVE 319
#define T_LODS 320
#define T_LOOP 321
#define T_LOOPNZ 322
#define T_LOOPZ 323
#define T_MOV 324
#define T_MOVS 325
#define T_MUL 326
#define T_NEG 327
#define T_NOT 328
#define T_OUT 329
#define T_OUTS 330
#define T_POP 331
#define T_POPA 332
#define T_POPF 333
#define T_PUSH 334
#define T_PUSHA 335
#define T_PUSHF 336
#define T_RCL 337
#define T_RCR 338
#define T_REPNZ 339
#define T_REPZ 340
#define T_RET 341
#define T_ROL 342
#define T_ROR 343
#define T_SAHF 344
#define T_SAR 345
#define T_SCAS 346
#define T_SHL 347
#define T_SHR 348
#define T_STC 349
#define T_STD 350
#define T_STOS 351
#define T_STI 352
#define T_TEST 353
#define T_XCHG 354
#define T_XLAT 355
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

#line 344 "../../src/intel-parse.hh"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY__SRC_INTEL_PARSE_HH_INCLUDED  */
