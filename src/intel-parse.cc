/* A Bison parser, made by GNU Bison 3.7.5.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30705

/* Bison version string.  */
#define YYBISON_VERSION "3.7.5"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 19 "../../src/intel-parse.yy"


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


#line 90 "../../src/intel-parse.cc"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
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
    T_ROTSHF = 271,                /* T_ROTSHF  */
    T_AAD = 272,                   /* T_AAD  */
    T_AAM = 273,                   /* T_AAM  */
    T_CALL = 274,                  /* T_CALL  */
    T_CMPS = 275,                  /* T_CMPS  */
    T_DEC = 276,                   /* T_DEC  */
    T_DIV = 277,                   /* T_DIV  */
    T_IDIV = 278,                  /* T_IDIV  */
    T_IMUL = 279,                  /* T_IMUL  */
    T_IN = 280,                    /* T_IN  */
    T_INC = 281,                   /* T_INC  */
    T_INS = 282,                   /* T_INS  */
    T_INT = 283,                   /* T_INT  */
    T_JMP = 284,                   /* T_JMP  */
    T_LEA = 285,                   /* T_LEA  */
    T_LODS = 286,                  /* T_LODS  */
    T_LOOP = 287,                  /* T_LOOP  */
    T_LOOPNZ = 288,                /* T_LOOPNZ  */
    T_LOOPZ = 289,                 /* T_LOOPZ  */
    T_MOV = 290,                   /* T_MOV  */
    T_MOVS = 291,                  /* T_MOVS  */
    T_MUL = 292,                   /* T_MUL  */
    T_NEG = 293,                   /* T_NEG  */
    T_NOP = 294,                   /* T_NOP  */
    T_NOT = 295,                   /* T_NOT  */
    T_OUT = 296,                   /* T_OUT  */
    T_OUTS = 297,                  /* T_OUTS  */
    T_POP = 298,                   /* T_POP  */
    T_PUSH = 299,                  /* T_PUSH  */
    T_RCL = 300,                   /* T_RCL  */
    T_RCR = 301,                   /* T_RCR  */
    T_REPNZ = 302,                 /* T_REPNZ  */
    T_REPZ = 303,                  /* T_REPZ  */
    T_RET = 304,                   /* T_RET  */
    T_ROL = 305,                   /* T_ROL  */
    T_ROR = 306,                   /* T_ROR  */
    T_SAR = 307,                   /* T_SAR  */
    T_SCAS = 308,                  /* T_SCAS  */
    T_SHL = 309,                   /* T_SHL  */
    T_SHR = 310,                   /* T_SHR  */
    T_STOS = 311,                  /* T_STOS  */
    T_TEST = 312,                  /* T_TEST  */
    T_XCHG = 313,                  /* T_XCHG  */
    T_DB = 314,                    /* "directive"  */
    T_DW = 315,                    /* T_DW  */
    T_DD = 316,                    /* T_DD  */
    T_DQ = 317,                    /* T_DQ  */
    T_SECTION = 318,               /* "section directive"  */
    T_GLOBAL = 319,                /* "global directive"  */
    T_CS = 320,                    /* "register"  */
    T_DS = 321,                    /* T_DS  */
    T_ES = 322,                    /* T_ES  */
    T_FS = 323,                    /* T_FS  */
    T_GS = 324,                    /* T_GS  */
    T_AL = 325,                    /* T_AL  */
    T_CL = 326,                    /* T_CL  */
    T_DL = 327,                    /* T_DL  */
    T_BL = 328,                    /* T_BL  */
    T_AH = 329,                    /* T_AH  */
    T_CH = 330,                    /* T_CH  */
    T_DH = 331,                    /* T_DH  */
    T_BH = 332,                    /* T_BH  */
    T_AX = 333,                    /* T_AX  */
    T_CX = 334,                    /* T_CX  */
    T_DX = 335,                    /* T_DX  */
    T_BX = 336,                    /* T_BX  */
    T_SP = 337,                    /* T_SP  */
    T_BP = 338,                    /* T_BP  */
    T_SI = 339,                    /* T_SI  */
    T_DI = 340,                    /* T_DI  */
    T_EAX = 341,                   /* T_EAX  */
    T_ECX = 342,                   /* T_ECX  */
    T_EDX = 343,                   /* T_EDX  */
    T_EBX = 344,                   /* T_EBX  */
    T_ESP = 345,                   /* T_ESP  */
    T_EBP = 346,                   /* T_EBP  */
    T_ESI = 347,                   /* T_ESI  */
    T_EDI = 348                    /* T_EDI  */
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
#define T_ROTSHF 271
#define T_AAD 272
#define T_AAM 273
#define T_CALL 274
#define T_CMPS 275
#define T_DEC 276
#define T_DIV 277
#define T_IDIV 278
#define T_IMUL 279
#define T_IN 280
#define T_INC 281
#define T_INS 282
#define T_INT 283
#define T_JMP 284
#define T_LEA 285
#define T_LODS 286
#define T_LOOP 287
#define T_LOOPNZ 288
#define T_LOOPZ 289
#define T_MOV 290
#define T_MOVS 291
#define T_MUL 292
#define T_NEG 293
#define T_NOP 294
#define T_NOT 295
#define T_OUT 296
#define T_OUTS 297
#define T_POP 298
#define T_PUSH 299
#define T_RCL 300
#define T_RCR 301
#define T_REPNZ 302
#define T_REPZ 303
#define T_RET 304
#define T_ROL 305
#define T_ROR 306
#define T_SAR 307
#define T_SCAS 308
#define T_SHL 309
#define T_SHR 310
#define T_STOS 311
#define T_TEST 312
#define T_XCHG 313
#define T_DB 314
#define T_DW 315
#define T_DD 316
#define T_DQ 317
#define T_SECTION 318
#define T_GLOBAL 319
#define T_CS 320
#define T_DS 321
#define T_ES 322
#define T_FS 323
#define T_GS 324
#define T_AL 325
#define T_CL 326
#define T_DL 327
#define T_BL 328
#define T_AH 329
#define T_CH 330
#define T_DH 331
#define T_BH 332
#define T_AX 333
#define T_CX 334
#define T_DX 335
#define T_BX 336
#define T_SP 337
#define T_BP 338
#define T_SI 339
#define T_DI 340
#define T_EAX 341
#define T_ECX 342
#define T_EDX 343
#define T_EBX 344
#define T_ESP 345
#define T_EBP 346
#define T_ESI 347
#define T_EDI 348

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 39 "../../src/intel-parse.yy"

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

#line 352 "../../src/intel-parse.cc"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY__SRC_INTEL_PARSE_HH_INCLUDED  */
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_T_IDENT = 3,                    /* "identifier"  */
  YYSYMBOL_T_SECTNAME = 4,                 /* "section name"  */
  YYSYMBOL_T_NUMBER = 5,                   /* "number"  */
  YYSYMBOL_T_CHAR = 6,                     /* "character literal"  */
  YYSYMBOL_T_BYTE = 7,                     /* "byte"  */
  YYSYMBOL_T_WORD = 8,                     /* "word"  */
  YYSYMBOL_T_DWORD = 9,                    /* "dword"  */
  YYSYMBOL_T_NEAR = 10,                    /* "near"  */
  YYSYMBOL_T_FAR = 11,                     /* "far"  */
  YYSYMBOL_T_ARTH = 12,                    /* "instruction mnemonic"  */
  YYSYMBOL_T_JF = 13,                      /* T_JF  */
  YYSYMBOL_T_ZO = 14,                      /* T_ZO  */
  YYSYMBOL_T_ZOS = 15,                     /* T_ZOS  */
  YYSYMBOL_T_ROTSHF = 16,                  /* T_ROTSHF  */
  YYSYMBOL_T_AAD = 17,                     /* T_AAD  */
  YYSYMBOL_T_AAM = 18,                     /* T_AAM  */
  YYSYMBOL_T_CALL = 19,                    /* T_CALL  */
  YYSYMBOL_T_CMPS = 20,                    /* T_CMPS  */
  YYSYMBOL_T_DEC = 21,                     /* T_DEC  */
  YYSYMBOL_T_DIV = 22,                     /* T_DIV  */
  YYSYMBOL_T_IDIV = 23,                    /* T_IDIV  */
  YYSYMBOL_T_IMUL = 24,                    /* T_IMUL  */
  YYSYMBOL_T_IN = 25,                      /* T_IN  */
  YYSYMBOL_T_INC = 26,                     /* T_INC  */
  YYSYMBOL_T_INS = 27,                     /* T_INS  */
  YYSYMBOL_T_INT = 28,                     /* T_INT  */
  YYSYMBOL_T_JMP = 29,                     /* T_JMP  */
  YYSYMBOL_T_LEA = 30,                     /* T_LEA  */
  YYSYMBOL_T_LODS = 31,                    /* T_LODS  */
  YYSYMBOL_T_LOOP = 32,                    /* T_LOOP  */
  YYSYMBOL_T_LOOPNZ = 33,                  /* T_LOOPNZ  */
  YYSYMBOL_T_LOOPZ = 34,                   /* T_LOOPZ  */
  YYSYMBOL_T_MOV = 35,                     /* T_MOV  */
  YYSYMBOL_T_MOVS = 36,                    /* T_MOVS  */
  YYSYMBOL_T_MUL = 37,                     /* T_MUL  */
  YYSYMBOL_T_NEG = 38,                     /* T_NEG  */
  YYSYMBOL_T_NOP = 39,                     /* T_NOP  */
  YYSYMBOL_T_NOT = 40,                     /* T_NOT  */
  YYSYMBOL_T_OUT = 41,                     /* T_OUT  */
  YYSYMBOL_T_OUTS = 42,                    /* T_OUTS  */
  YYSYMBOL_T_POP = 43,                     /* T_POP  */
  YYSYMBOL_T_PUSH = 44,                    /* T_PUSH  */
  YYSYMBOL_T_RCL = 45,                     /* T_RCL  */
  YYSYMBOL_T_RCR = 46,                     /* T_RCR  */
  YYSYMBOL_T_REPNZ = 47,                   /* T_REPNZ  */
  YYSYMBOL_T_REPZ = 48,                    /* T_REPZ  */
  YYSYMBOL_T_RET = 49,                     /* T_RET  */
  YYSYMBOL_T_ROL = 50,                     /* T_ROL  */
  YYSYMBOL_T_ROR = 51,                     /* T_ROR  */
  YYSYMBOL_T_SAR = 52,                     /* T_SAR  */
  YYSYMBOL_T_SCAS = 53,                    /* T_SCAS  */
  YYSYMBOL_T_SHL = 54,                     /* T_SHL  */
  YYSYMBOL_T_SHR = 55,                     /* T_SHR  */
  YYSYMBOL_T_STOS = 56,                    /* T_STOS  */
  YYSYMBOL_T_TEST = 57,                    /* T_TEST  */
  YYSYMBOL_T_XCHG = 58,                    /* T_XCHG  */
  YYSYMBOL_T_DB = 59,                      /* "directive"  */
  YYSYMBOL_T_DW = 60,                      /* T_DW  */
  YYSYMBOL_T_DD = 61,                      /* T_DD  */
  YYSYMBOL_T_DQ = 62,                      /* T_DQ  */
  YYSYMBOL_T_SECTION = 63,                 /* "section directive"  */
  YYSYMBOL_T_GLOBAL = 64,                  /* "global directive"  */
  YYSYMBOL_T_CS = 65,                      /* "register"  */
  YYSYMBOL_T_DS = 66,                      /* T_DS  */
  YYSYMBOL_T_ES = 67,                      /* T_ES  */
  YYSYMBOL_T_FS = 68,                      /* T_FS  */
  YYSYMBOL_T_GS = 69,                      /* T_GS  */
  YYSYMBOL_T_AL = 70,                      /* T_AL  */
  YYSYMBOL_T_CL = 71,                      /* T_CL  */
  YYSYMBOL_T_DL = 72,                      /* T_DL  */
  YYSYMBOL_T_BL = 73,                      /* T_BL  */
  YYSYMBOL_T_AH = 74,                      /* T_AH  */
  YYSYMBOL_T_CH = 75,                      /* T_CH  */
  YYSYMBOL_T_DH = 76,                      /* T_DH  */
  YYSYMBOL_T_BH = 77,                      /* T_BH  */
  YYSYMBOL_T_AX = 78,                      /* T_AX  */
  YYSYMBOL_T_CX = 79,                      /* T_CX  */
  YYSYMBOL_T_DX = 80,                      /* T_DX  */
  YYSYMBOL_T_BX = 81,                      /* T_BX  */
  YYSYMBOL_T_SP = 82,                      /* T_SP  */
  YYSYMBOL_T_BP = 83,                      /* T_BP  */
  YYSYMBOL_T_SI = 84,                      /* T_SI  */
  YYSYMBOL_T_DI = 85,                      /* T_DI  */
  YYSYMBOL_T_EAX = 86,                     /* T_EAX  */
  YYSYMBOL_T_ECX = 87,                     /* T_ECX  */
  YYSYMBOL_T_EDX = 88,                     /* T_EDX  */
  YYSYMBOL_T_EBX = 89,                     /* T_EBX  */
  YYSYMBOL_T_ESP = 90,                     /* T_ESP  */
  YYSYMBOL_T_EBP = 91,                     /* T_EBP  */
  YYSYMBOL_T_ESI = 92,                     /* T_ESI  */
  YYSYMBOL_T_EDI = 93,                     /* T_EDI  */
  YYSYMBOL_94_ = 94,                       /* ','  */
  YYSYMBOL_95_ = 95,                       /* ':'  */
  YYSYMBOL_96_ = 96,                       /* '['  */
  YYSYMBOL_97_ = 97,                       /* ']'  */
  YYSYMBOL_98_ = 98,                       /* '+'  */
  YYSYMBOL_99_ = 99,                       /* '*'  */
  YYSYMBOL_100_ = 100,                     /* ';'  */
  YYSYMBOL_101_n_ = 101,                   /* '\n'  */
  YYSYMBOL_YYACCEPT = 102,                 /* $accept  */
  YYSYMBOL_program = 103,                  /* program  */
  YYSYMBOL_object = 104,                   /* object  */
  YYSYMBOL_lines = 105,                    /* lines  */
  YYSYMBOL_instruction = 106,              /* instruction  */
  YYSYMBOL_ascii_inst = 107,               /* ascii_inst  */
  YYSYMBOL_call_inst = 108,                /* call_inst  */
  YYSYMBOL_port_inst = 109,                /* port_inst  */
  YYSYMBOL_jmp_inst = 110,                 /* jmp_inst  */
  YYSYMBOL_string_inst = 111,              /* string_inst  */
  YYSYMBOL_rep_inst = 112,                 /* rep_inst  */
  YYSYMBOL_directive = 113,                /* directive  */
  YYSYMBOL_expression = 114,               /* expression  */
  YYSYMBOL_immediate = 115,                /* immediate  */
  YYSYMBOL_storage = 116,                  /* storage  */
  YYSYMBOL_memloc = 117,                   /* memloc  */
  YYSYMBOL_deref = 118,                    /* deref  */
  YYSYMBOL_reg = 119,                      /* reg  */
  YYSYMBOL_segment = 120,                  /* segment  */
  YYSYMBOL_size_specifier = 121,           /* size_specifier  */
  YYSYMBOL_terminator = 122,               /* terminator  */
  YYSYMBOL_label = 123,                    /* label  */
  YYSYMBOL_addr = 124,                     /* addr  */
  YYSYMBOL_define_size = 125               /* define_size  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if 1

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* 1 */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  140
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   573

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  102
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  24
/* YYNRULES -- Number of rules.  */
#define YYNRULES  139
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  215

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   348


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     101,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,    99,    98,    94,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    95,   100,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    96,     2,    97,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   180,   180,   183,   191,   196,   201,   202,   203,   206,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   249,   250,   251,   252,   255,   256,   257,
     258,   261,   262,   263,   264,   268,   269,   270,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     287,   288,   289,   290,   294,   295,   296,   299,   302,   303,
     306,   312,   317,   320,   321,   324,   327,   328,   331,   332,
     340,   345,   351,   357,   363,   369,   375,   383,   384,   385,
     386,   387,   388,   389,   390,   391,   392,   393,   394,   395,
     396,   397,   398,   399,   400,   401,   402,   403,   404,   405,
     406,   407,   410,   411,   412,   413,   414,   417,   418,   419,
     422,   423,   426,   427,   435,   436,   439,   440,   441,   442
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if 1
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  static const char *const yy_sname[] =
  {
  "end of file", "error", "invalid token", "identifier", "section name",
  "number", "character literal", "byte", "word", "dword", "near", "far",
  "instruction mnemonic", "T_JF", "T_ZO", "T_ZOS", "T_ROTSHF", "T_AAD",
  "T_AAM", "T_CALL", "T_CMPS", "T_DEC", "T_DIV", "T_IDIV", "T_IMUL",
  "T_IN", "T_INC", "T_INS", "T_INT", "T_JMP", "T_LEA", "T_LODS", "T_LOOP",
  "T_LOOPNZ", "T_LOOPZ", "T_MOV", "T_MOVS", "T_MUL", "T_NEG", "T_NOP",
  "T_NOT", "T_OUT", "T_OUTS", "T_POP", "T_PUSH", "T_RCL", "T_RCR",
  "T_REPNZ", "T_REPZ", "T_RET", "T_ROL", "T_ROR", "T_SAR", "T_SCAS",
  "T_SHL", "T_SHR", "T_STOS", "T_TEST", "T_XCHG", "directive", "T_DW",
  "T_DD", "T_DQ", "section directive", "global directive", "register",
  "T_DS", "T_ES", "T_FS", "T_GS", "T_AL", "T_CL", "T_DL", "T_BL", "T_AH",
  "T_CH", "T_DH", "T_BH", "T_AX", "T_CX", "T_DX", "T_BX", "T_SP", "T_BP",
  "T_SI", "T_DI", "T_EAX", "T_ECX", "T_EDX", "T_EBX", "T_ESP", "T_EBP",
  "T_ESI", "T_EDI", "','", "':'", "'['", "']'", "'+'", "'*'", "';'",
  "'\\n'", "$accept", "program", "object", "lines", "instruction",
  "ascii_inst", "call_inst", "port_inst", "jmp_inst", "string_inst",
  "rep_inst", "directive", "expression", "immediate", "storage", "memloc",
  "deref", "reg", "segment", "size_specifier", "terminator", "label",
  "addr", "define_size", YY_NULLPTR
  };
  return yy_sname[yysymbol];
}
#endif

#ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   331,   332,   333,   334,
     335,   336,   337,   338,   339,   340,   341,   342,   343,   344,
     345,   346,   347,   348,    44,    58,    91,    93,    43,    42,
      59,    10
};
#endif

#define YYPACT_NINF (-133)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     509,   -54,   418,    63,  -133,    56,   418,    40,    54,    64,
     418,   418,   418,   418,   -39,   418,    65,   155,   363,    63,
      63,    63,   418,   418,   418,  -133,   418,    -3,   418,   418,
      39,    39,    38,   418,   418,  -133,  -133,  -133,  -133,    72,
      75,    82,  -133,   -97,  -133,  -133,  -133,  -133,  -133,  -133,
    -133,  -133,  -133,    78,  -133,  -133,  -133,  -133,  -133,  -133,
    -133,  -133,  -133,  -133,  -133,  -133,  -133,  -133,  -133,  -133,
    -133,  -133,  -133,  -133,  -133,  -133,  -133,  -133,  -133,  -133,
    -133,  -133,  -133,  -133,  -133,  -133,  -133,   -10,  -133,  -133,
    -133,    -9,  -133,  -133,  -133,  -133,  -133,    -8,  -133,  -133,
      -6,   184,    48,  -133,  -133,  -133,  -133,  -133,  -133,     0,
       2,     3,  -133,  -133,    -4,   184,    53,  -133,  -133,     4,
    -133,  -133,  -133,     7,  -133,  -133,  -133,     9,    10,  -133,
    -133,  -133,  -133,  -133,    87,    88,    11,    12,  -133,  -133,
    -133,  -133,  -133,   509,  -133,   273,   302,    19,    97,  -133,
    -133,    13,  -133,     1,     8,    15,   102,  -133,  -133,    14,
    -133,    56,   273,   -36,   -34,  -133,  -133,   273,   418,  -133,
    -133,  -133,  -133,  -133,  -133,    18,    20,    16,  -133,  -133,
    -133,   105,  -133,  -133,  -133,  -133,  -133,  -133,  -133,   107,
    -133,  -133,  -133,  -133,  -133,  -133,  -133,  -133,  -133,  -133,
    -133,   331,   302,  -133,  -133,  -133,   -61,    22,   111,   112,
    -133,  -133,    23,   115,  -133
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,   133,     0,     0,    11,     0,     0,    48,    50,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    30,     0,     0,     0,     0,
       0,     0,    35,     0,     0,   136,   137,   138,   139,     0,
       0,     0,     2,     3,     4,    13,    14,    20,    22,    12,
      34,    46,     5,     0,   132,   127,   128,   129,   122,   123,
     124,   125,   126,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,     0,    87,    86,
      97,     0,   134,    85,   135,    10,    77,    41,    47,    49,
      85,     0,     0,    55,    51,    15,    16,    17,    18,     0,
       0,     0,    19,    21,    85,     0,     0,    74,    70,     0,
      24,    25,    26,     0,    28,    29,    31,     0,     0,    32,
      33,    78,    79,    37,    36,    39,     0,     0,    81,    80,
       1,   130,   131,     8,    82,     0,     0,     0,     0,    56,
      52,     0,    57,     0,     0,     0,     0,    75,    71,     0,
      76,     0,     0,     0,     0,    38,    40,     0,     0,     6,
       7,     9,    83,    84,    90,     0,    91,    97,    42,    43,
      53,     0,    58,    59,    60,    61,    62,    63,    72,     0,
      23,    27,    64,    66,    68,    65,    67,    69,    44,    45,
      88,     0,     0,    54,    73,    92,    93,     0,     0,     0,
      89,    94,    95,     0,    96
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -133,  -133,  -133,  -133,   -21,  -133,  -133,  -133,  -133,    49,
    -133,  -133,  -132,  -116,    -1,   -76,   -79,   -18,   -22,   120,
    -133,   -17,    -2,  -133
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,   171,    94,   173,    88,   175,    89,    90,    91,
     143,    52,    95,    53
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
     119,    87,   127,   141,   142,    97,   182,   104,   103,   105,
     106,   107,   108,   184,   112,   118,   117,   120,   121,   122,
     186,   123,   124,   125,   178,   126,   152,   129,   130,   172,
     191,   109,   136,   137,   192,   198,   195,   208,   209,   110,
     160,    54,   193,   133,   196,    98,   172,   111,   134,   135,
     194,   172,   197,   151,     5,    55,    56,    57,   159,    99,
      55,    56,    57,    55,    56,    57,    92,    92,    93,   100,
     113,    55,    56,    57,   101,   102,   138,   128,   139,   131,
     132,   183,   140,   144,   145,   190,   147,   146,   185,   148,
     179,   156,   165,   166,   153,   187,   154,   155,   161,   150,
     149,   162,   180,   163,   164,   167,   168,   188,   181,   189,
     203,   202,   204,   158,   157,   200,   211,   212,   201,   210,
     214,   213,   169,   207,   177,    96,   170,     0,   176,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      69,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    92,     0,
     114,     0,    55,    56,    57,   115,   116,   199,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   206,   176,     0,     0,    92,     0,    93,
       0,    55,    56,    57,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      69,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    93,     0,
      55,    56,    57,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   174,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   205,     0,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,     1,     0,     0,     0,     0,     0,     0,     0,
       0,     2,     3,     4,     5,     6,     7,     8,     9,     0,
      10,    11,    12,    13,    14,    15,     0,    16,    17,    18,
       0,    19,    20,    21,    22,     0,    23,    24,    25,    26,
      27,     0,    28,    29,     0,     0,    30,    31,    32,     0,
       0,     0,     0,     0,     0,     0,    33,    34,    35,    36,
      37,    38,    39,    40
};

static const yytype_int16 yycheck[] =
{
      18,     2,     5,   100,   101,     6,     5,     9,     9,    10,
      11,    12,    13,     5,    15,    17,    17,    19,    20,    21,
       5,    22,    23,    24,     5,    26,   102,    28,    29,   145,
     162,    70,    33,    34,    70,   167,    70,    98,    99,    78,
     116,    95,    78,     5,    78,     5,   162,    86,    10,    11,
      86,   167,    86,     5,    15,     7,     8,     9,     5,     5,
       7,     8,     9,     7,     8,     9,     3,     3,     5,     5,
       5,     7,     8,     9,    10,    11,     4,    80,     3,    30,
      31,    80,     0,     5,    94,   161,    94,    96,    80,    95,
      71,    95,     5,     5,    94,    80,    94,    94,    94,   101,
     101,    94,     5,    94,    94,    94,    94,     5,    95,    95,
       5,    95,     5,   115,   115,    97,     5,     5,    98,    97,
       5,    98,   143,   202,   146,     5,   143,    -1,   146,    65,
      66,    67,    68,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    93,     3,    -1,
       5,    -1,     7,     8,     9,    10,    11,   168,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   201,   202,    -1,    -1,     3,    -1,     5,
      -1,     7,     8,     9,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    65,
      66,    67,    68,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    93,     5,    -1,
       7,     8,     9,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,     5,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,     5,    -1,    65,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    92,    93,    65,    66,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    65,    66,    67,    68,
      69,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    91,    92,    93,     7,     8,     9,    65,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    92,    93,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    93,     3,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    12,    13,    14,    15,    16,    17,    18,    19,    -1,
      21,    22,    23,    24,    25,    26,    -1,    28,    29,    30,
      -1,    32,    33,    34,    35,    -1,    37,    38,    39,    40,
      41,    -1,    43,    44,    -1,    -1,    47,    48,    49,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    57,    58,    59,    60,
      61,    62,    63,    64
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,    12,    13,    14,    15,    16,    17,    18,    19,
      21,    22,    23,    24,    25,    26,    28,    29,    30,    32,
      33,    34,    35,    37,    38,    39,    40,    41,    43,    44,
      47,    48,    49,    57,    58,    59,    60,    61,    62,    63,
      64,   103,   104,   105,   106,   107,   108,   109,   110,   111,
     112,   113,   123,   125,    95,     7,     8,     9,    65,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    92,    93,   116,   117,   119,
     120,   121,     3,     5,   115,   124,   121,   116,     5,     5,
       5,    10,    11,   116,   124,   116,   116,   116,   116,    70,
      78,    86,   116,     5,     5,    10,    11,   116,   124,   119,
     124,   124,   124,   116,   116,   116,   116,     5,    80,   116,
     116,   111,   111,     5,    10,    11,   116,   116,     4,     3,
       0,   100,   101,   122,     5,    94,    96,    94,    95,   116,
     124,     5,   117,    94,    94,    94,    95,   116,   124,     5,
     117,    94,    94,    94,    94,     5,     5,    94,    94,   106,
     123,   114,   115,   116,     5,   118,   119,   120,     5,    71,
       5,    95,     5,    80,     5,    80,     5,    80,     5,    95,
     117,   114,    70,    78,    86,    70,    78,    86,   114,   116,
      97,    98,    95,     5,     5,     5,   119,   118,    98,    99,
      97,     5,     5,    98,     5
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,   102,   103,   104,   105,   105,   105,   105,   105,   106,
     106,   106,   106,   106,   106,   106,   106,   106,   106,   106,
     106,   106,   106,   106,   106,   106,   106,   106,   106,   106,
     106,   106,   106,   106,   106,   106,   106,   106,   106,   106,
     106,   106,   106,   106,   106,   106,   106,   107,   107,   107,
     107,   108,   108,   108,   108,   108,   108,   108,   109,   109,
     109,   109,   109,   109,   109,   109,   109,   109,   109,   109,
     110,   110,   110,   110,   110,   110,   110,   111,   112,   112,
     113,   113,   113,   114,   114,   115,   116,   116,   117,   117,
     118,   118,   118,   118,   118,   118,   118,   119,   119,   119,
     119,   119,   119,   119,   119,   119,   119,   119,   119,   119,
     119,   119,   119,   119,   119,   119,   119,   119,   119,   119,
     119,   119,   120,   120,   120,   120,   120,   121,   121,   121,
     122,   122,   123,   123,   124,   124,   125,   125,   125,   125
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     1,     1,     3,     3,     2,     4,
       2,     1,     1,     1,     1,     2,     2,     2,     2,     2,
       1,     2,     1,     4,     2,     2,     2,     4,     2,     2,
       1,     2,     2,     2,     1,     1,     2,     2,     3,     2,
       3,     2,     4,     4,     4,     4,     1,     2,     1,     2,
       1,     2,     3,     4,     5,     2,     3,     3,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       2,     3,     4,     5,     2,     3,     3,     2,     2,     2,
       2,     2,     2,     1,     1,     1,     1,     1,     4,     6,
       1,     1,     3,     3,     5,     5,     7,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     2,     1,     1,     1,     1,     1,     1,     1
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
# ifndef YY_LOCATION_PRINT
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif


# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yykind < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yykind], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


/* Context of a parse error.  */
typedef struct
{
  yy_state_t *yyssp;
  yysymbol_kind_t yytoken;
} yypcontext_t;

/* Put in YYARG at most YYARGN of the expected tokens given the
   current YYCTX, and return the number of tokens stored in YYARG.  If
   YYARG is null, return the number of expected tokens (guaranteed to
   be less than YYNTOKENS).  Return YYENOMEM on memory exhaustion.
   Return 0 if there are more than YYARGN expected tokens, yet fill
   YYARG up to YYARGN. */
static int
yypcontext_expected_tokens (const yypcontext_t *yyctx,
                            yysymbol_kind_t yyarg[], int yyargn)
{
  /* Actual size of YYARG. */
  int yycount = 0;
  int yyn = yypact[+*yyctx->yyssp];
  if (!yypact_value_is_default (yyn))
    {
      /* Start YYX at -YYN if negative to avoid negative indexes in
         YYCHECK.  In other words, skip the first -YYN actions for
         this state because they are default actions.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;
      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yyx;
      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
        if (yycheck[yyx + yyn] == yyx && yyx != YYSYMBOL_YYerror
            && !yytable_value_is_error (yytable[yyx + yyn]))
          {
            if (!yyarg)
              ++yycount;
            else if (yycount == yyargn)
              return 0;
            else
              yyarg[yycount++] = YY_CAST (yysymbol_kind_t, yyx);
          }
    }
  if (yyarg && yycount == 0 && 0 < yyargn)
    yyarg[0] = YYSYMBOL_YYEMPTY;
  return yycount;
}




#ifndef yystrlen
# if defined __GLIBC__ && defined _STRING_H
#  define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
# else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
# endif
#endif

#ifndef yystpcpy
# if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#  define yystpcpy stpcpy
# else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
# endif
#endif



static int
yy_syntax_error_arguments (const yypcontext_t *yyctx,
                           yysymbol_kind_t yyarg[], int yyargn)
{
  /* Actual size of YYARG. */
  int yycount = 0;
  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yyctx->yytoken != YYSYMBOL_YYEMPTY)
    {
      int yyn;
      if (yyarg)
        yyarg[yycount] = yyctx->yytoken;
      ++yycount;
      yyn = yypcontext_expected_tokens (yyctx,
                                        yyarg ? yyarg + 1 : yyarg, yyargn - 1);
      if (yyn == YYENOMEM)
        return YYENOMEM;
      else
        yycount += yyn;
    }
  return yycount;
}

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return -1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return YYENOMEM if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                const yypcontext_t *yyctx)
{
  enum { YYARGS_MAX = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  yysymbol_kind_t yyarg[YYARGS_MAX];
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

  /* Actual size of YYARG. */
  int yycount = yy_syntax_error_arguments (yyctx, yyarg, YYARGS_MAX);
  if (yycount == YYENOMEM)
    return YYENOMEM;

  switch (yycount)
    {
#define YYCASE_(N, S)                       \
      case N:                               \
        yyformat = S;                       \
        break
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
#undef YYCASE_
    }

  /* Compute error message size.  Don't count the "%s"s, but reserve
     room for the terminator.  */
  yysize = yystrlen (yyformat) - 2 * yycount + 1;
  {
    int yyi;
    for (yyi = 0; yyi < yycount; ++yyi)
      {
        YYPTRDIFF_T yysize1
          = yysize + yystrlen (yysymbol_name (yyarg[yyi]));
        if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
          yysize = yysize1;
        else
          return YYENOMEM;
      }
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return -1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp = yystpcpy (yyp, yysymbol_name (yyarg[yyi++]));
          yyformat += 2;
        }
      else
        {
          ++yyp;
          ++yyformat;
        }
  }
  return 0;
}


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2: /* program: object  */
#line 180 "../../src/intel-parse.yy"
                       { result = (yyvsp[0].obj); }
#line 1921 "../../src/intel-parse.cc"
    break;

  case 3: /* object: lines  */
#line 184 "../../src/intel-parse.yy"
                {
		  (yyval.obj) = new Object (format, filename);
		  (yyval.obj)->lines = *(yyvsp[0].lines);
		  delete (yyvsp[0].lines);
		}
#line 1931 "../../src/intel-parse.cc"
    break;

  case 4: /* lines: instruction  */
#line 192 "../../src/intel-parse.yy"
                {
		  (yyval.lines) = new std::vector <AsmLine *> ();
		  (yyval.lines)->push_back ((yyvsp[0].inst));
		}
#line 1940 "../../src/intel-parse.cc"
    break;

  case 5: /* lines: label  */
#line 197 "../../src/intel-parse.yy"
                {
		  (yyval.lines) = new std::vector <AsmLine *> ();
		  (yyval.lines)->push_back ((yyvsp[0].label));
		}
#line 1949 "../../src/intel-parse.cc"
    break;

  case 6: /* lines: lines terminator instruction  */
#line 201 "../../src/intel-parse.yy"
                                             { (yyvsp[-2].lines)->push_back ((yyvsp[0].inst)); }
#line 1955 "../../src/intel-parse.cc"
    break;

  case 7: /* lines: lines terminator label  */
#line 202 "../../src/intel-parse.yy"
                                       { (yyvsp[-2].lines)->push_back ((yyvsp[0].label)); }
#line 1961 "../../src/intel-parse.cc"
    break;

  case 9: /* instruction: "instruction mnemonic" storage ',' expression  */
#line 207 "../../src/intel-parse.yy"
                {
		  (yyval.inst) = new AsmInstARITH ((yyvsp[-3].arith), (yyvsp[-2].storage), (yyvsp[0].expr));
		}
#line 1969 "../../src/intel-parse.cc"
    break;

  case 10: /* instruction: T_JF addr  */
#line 210 "../../src/intel-parse.yy"
                          { (yyval.inst) = new AsmInstJF ((yyvsp[-1].jf), (yyvsp[0].addr), 4); }
#line 1975 "../../src/intel-parse.cc"
    break;

  case 11: /* instruction: T_ZO  */
#line 211 "../../src/intel-parse.yy"
                     { (yyval.inst) = new AsmInstZO ((yyvsp[0].zo)); }
#line 1981 "../../src/intel-parse.cc"
    break;

  case 12: /* instruction: string_inst  */
#line 212 "../../src/intel-parse.yy"
                            { (yyval.inst) = (yyvsp[0].strinst); }
#line 1987 "../../src/intel-parse.cc"
    break;

  case 15: /* instruction: T_DEC storage  */
#line 215 "../../src/intel-parse.yy"
                              { (yyval.inst) = new AsmInstDEC ((yyvsp[0].storage)); }
#line 1993 "../../src/intel-parse.cc"
    break;

  case 16: /* instruction: T_DIV storage  */
#line 216 "../../src/intel-parse.yy"
                              { (yyval.inst) = new AsmInstDIV ((yyvsp[0].storage)); }
#line 1999 "../../src/intel-parse.cc"
    break;

  case 17: /* instruction: T_IDIV storage  */
#line 217 "../../src/intel-parse.yy"
                               { (yyval.inst) = new AsmInstIDIV ((yyvsp[0].storage)); }
#line 2005 "../../src/intel-parse.cc"
    break;

  case 18: /* instruction: T_IMUL storage  */
#line 218 "../../src/intel-parse.yy"
                               { (yyval.inst) = new AsmInstIMUL ((yyvsp[0].storage)); }
#line 2011 "../../src/intel-parse.cc"
    break;

  case 19: /* instruction: T_INC storage  */
#line 219 "../../src/intel-parse.yy"
                              { (yyval.inst) = new AsmInstINC ((yyvsp[0].storage)); }
#line 2017 "../../src/intel-parse.cc"
    break;

  case 21: /* instruction: T_INT "number"  */
#line 221 "../../src/intel-parse.yy"
                               { (yyval.inst) = new AsmInstINT ((yyvsp[0].number)); }
#line 2023 "../../src/intel-parse.cc"
    break;

  case 23: /* instruction: T_LEA reg ',' memloc  */
#line 223 "../../src/intel-parse.yy"
                                     { (yyval.inst) = new AsmInstLEA ((yyvsp[-2].reg), (yyvsp[0].mem)); }
#line 2029 "../../src/intel-parse.cc"
    break;

  case 24: /* instruction: T_LOOP addr  */
#line 224 "../../src/intel-parse.yy"
                            { (yyval.inst) = new AsmInstLOOP ((yyvsp[0].addr)); }
#line 2035 "../../src/intel-parse.cc"
    break;

  case 25: /* instruction: T_LOOPNZ addr  */
#line 225 "../../src/intel-parse.yy"
                              { (yyval.inst) = new AsmInstLOOPNZ ((yyvsp[0].addr)); }
#line 2041 "../../src/intel-parse.cc"
    break;

  case 26: /* instruction: T_LOOPZ addr  */
#line 226 "../../src/intel-parse.yy"
                             { (yyval.inst) = new AsmInstLOOPZ ((yyvsp[0].addr)); }
#line 2047 "../../src/intel-parse.cc"
    break;

  case 27: /* instruction: T_MOV storage ',' expression  */
#line 227 "../../src/intel-parse.yy"
                                             { (yyval.inst) = new AsmInstMOV ((yyvsp[-2].storage), (yyvsp[0].expr)); }
#line 2053 "../../src/intel-parse.cc"
    break;

  case 28: /* instruction: T_MUL storage  */
#line 228 "../../src/intel-parse.yy"
                              { (yyval.inst) = new AsmInstMUL ((yyvsp[0].storage)); }
#line 2059 "../../src/intel-parse.cc"
    break;

  case 29: /* instruction: T_NEG storage  */
#line 229 "../../src/intel-parse.yy"
                              { (yyval.inst) = new AsmInstNEG ((yyvsp[0].storage)); }
#line 2065 "../../src/intel-parse.cc"
    break;

  case 30: /* instruction: T_NOP  */
#line 231 "../../src/intel-parse.yy"
                {
		  (yyval.inst) = new AsmInstXCHG (AsmRegister::EAX, AsmRegister::EAX);
		}
#line 2073 "../../src/intel-parse.cc"
    break;

  case 31: /* instruction: T_NOT storage  */
#line 234 "../../src/intel-parse.yy"
                              { (yyval.inst) = new AsmInstNOT ((yyvsp[0].storage)); }
#line 2079 "../../src/intel-parse.cc"
    break;

  case 32: /* instruction: T_POP storage  */
#line 235 "../../src/intel-parse.yy"
                              { (yyval.inst) = new AsmInstPOP ((yyvsp[0].storage)); }
#line 2085 "../../src/intel-parse.cc"
    break;

  case 33: /* instruction: T_PUSH storage  */
#line 236 "../../src/intel-parse.yy"
                               { (yyval.inst) = new AsmInstPUSH ((yyvsp[0].storage)); }
#line 2091 "../../src/intel-parse.cc"
    break;

  case 35: /* instruction: T_RET  */
#line 238 "../../src/intel-parse.yy"
                      { (yyval.inst) = new AsmInstRET (false); }
#line 2097 "../../src/intel-parse.cc"
    break;

  case 36: /* instruction: T_RET "near"  */
#line 239 "../../src/intel-parse.yy"
                             { (yyval.inst) = new AsmInstRET (false); }
#line 2103 "../../src/intel-parse.cc"
    break;

  case 37: /* instruction: T_RET "number"  */
#line 240 "../../src/intel-parse.yy"
                               { (yyval.inst) = new AsmInstRET (false, (yyvsp[0].number)); }
#line 2109 "../../src/intel-parse.cc"
    break;

  case 38: /* instruction: T_RET "near" "number"  */
#line 241 "../../src/intel-parse.yy"
                                      { (yyval.inst) = new AsmInstRET (false, (yyvsp[0].number)); }
#line 2115 "../../src/intel-parse.cc"
    break;

  case 39: /* instruction: T_RET "far"  */
#line 242 "../../src/intel-parse.yy"
                            { (yyval.inst) = new AsmInstRET (true); }
#line 2121 "../../src/intel-parse.cc"
    break;

  case 40: /* instruction: T_RET "far" "number"  */
#line 243 "../../src/intel-parse.yy"
                                     { (yyval.inst) = new AsmInstRET (true, (yyvsp[0].number)); }
#line 2127 "../../src/intel-parse.cc"
    break;

  case 41: /* instruction: T_ROTSHF storage  */
#line 244 "../../src/intel-parse.yy"
                                 { (yyval.inst) = new AsmInstROTSHF ((yyvsp[-1].rotshf), (yyvsp[0].storage), 1); }
#line 2133 "../../src/intel-parse.cc"
    break;

  case 42: /* instruction: T_ROTSHF storage ',' "number"  */
#line 246 "../../src/intel-parse.yy"
                {
		  (yyval.inst) = new AsmInstROTSHF ((yyvsp[-3].rotshf), (yyvsp[-2].storage), (yyvsp[0].number));
		}
#line 2141 "../../src/intel-parse.cc"
    break;

  case 43: /* instruction: T_ROTSHF storage ',' T_CL  */
#line 249 "../../src/intel-parse.yy"
                                          { (yyval.inst) = new AsmInstROTSHF ((yyvsp[-3].rotshf), (yyvsp[-2].storage)); }
#line 2147 "../../src/intel-parse.cc"
    break;

  case 44: /* instruction: T_TEST storage ',' expression  */
#line 250 "../../src/intel-parse.yy"
                                              { (yyval.inst) = new AsmInstTEST ((yyvsp[-2].storage), (yyvsp[0].expr)); }
#line 2153 "../../src/intel-parse.cc"
    break;

  case 45: /* instruction: T_XCHG storage ',' storage  */
#line 251 "../../src/intel-parse.yy"
                                           { (yyval.inst) = new AsmInstXCHG ((yyvsp[-2].storage), (yyvsp[0].storage)); }
#line 2159 "../../src/intel-parse.cc"
    break;

  case 46: /* instruction: directive  */
#line 252 "../../src/intel-parse.yy"
                          { (yyval.inst) = (yyvsp[0].directive); }
#line 2165 "../../src/intel-parse.cc"
    break;

  case 47: /* ascii_inst: T_AAD "number"  */
#line 255 "../../src/intel-parse.yy"
                               { (yyval.inst) = new AsmInstAAD ((yyvsp[0].number)); }
#line 2171 "../../src/intel-parse.cc"
    break;

  case 48: /* ascii_inst: T_AAD  */
#line 256 "../../src/intel-parse.yy"
                      { (yyval.inst) = new AsmInstAAD (); }
#line 2177 "../../src/intel-parse.cc"
    break;

  case 49: /* ascii_inst: T_AAM "number"  */
#line 257 "../../src/intel-parse.yy"
                               { (yyval.inst) = new AsmInstAAM ((yyvsp[0].number)); }
#line 2183 "../../src/intel-parse.cc"
    break;

  case 50: /* ascii_inst: T_AAM  */
#line 258 "../../src/intel-parse.yy"
                      { (yyval.inst) = new AsmInstAAM (); }
#line 2189 "../../src/intel-parse.cc"
    break;

  case 51: /* call_inst: T_CALL addr  */
#line 261 "../../src/intel-parse.yy"
                            { (yyval.inst) = new AsmInstCALL ((yyvsp[0].addr), 4); }
#line 2195 "../../src/intel-parse.cc"
    break;

  case 52: /* call_inst: T_CALL "near" addr  */
#line 262 "../../src/intel-parse.yy"
                                   { (yyval.inst) = new AsmInstCALL ((yyvsp[0].addr), 4); }
#line 2201 "../../src/intel-parse.cc"
    break;

  case 53: /* call_inst: T_CALL "number" ':' "number"  */
#line 263 "../../src/intel-parse.yy"
                                             { (yyval.inst) = new AsmInstCALLF ((yyvsp[-2].number), (yyvsp[0].number)); }
#line 2207 "../../src/intel-parse.cc"
    break;

  case 54: /* call_inst: T_CALL "far" "number" ':' "number"  */
#line 265 "../../src/intel-parse.yy"
                {
		  (yyval.inst) = new AsmInstCALLF ((yyvsp[-2].number), (yyvsp[0].number));
		}
#line 2215 "../../src/intel-parse.cc"
    break;

  case 55: /* call_inst: T_CALL storage  */
#line 268 "../../src/intel-parse.yy"
                               { (yyval.inst) = new AsmInstCALL ((yyvsp[0].storage)); }
#line 2221 "../../src/intel-parse.cc"
    break;

  case 56: /* call_inst: T_CALL "near" storage  */
#line 269 "../../src/intel-parse.yy"
                                      { (yyval.inst) = new AsmInstCALL ((yyvsp[0].storage)); }
#line 2227 "../../src/intel-parse.cc"
    break;

  case 57: /* call_inst: T_CALL "far" memloc  */
#line 270 "../../src/intel-parse.yy"
                                    { (yyval.inst) = new AsmInstCALLF ((yyvsp[0].mem)); }
#line 2233 "../../src/intel-parse.cc"
    break;

  case 58: /* port_inst: T_IN T_AL ',' "number"  */
#line 273 "../../src/intel-parse.yy"
                                       { (yyval.inst) = new AsmInstIN ((yyvsp[0].number), 1); }
#line 2239 "../../src/intel-parse.cc"
    break;

  case 59: /* port_inst: T_IN T_AL ',' T_DX  */
#line 274 "../../src/intel-parse.yy"
                                   { (yyval.inst) = new AsmInstIN (1); }
#line 2245 "../../src/intel-parse.cc"
    break;

  case 60: /* port_inst: T_IN T_AX ',' "number"  */
#line 275 "../../src/intel-parse.yy"
                                       { (yyval.inst) = new AsmInstIN ((yyvsp[0].number), 2); }
#line 2251 "../../src/intel-parse.cc"
    break;

  case 61: /* port_inst: T_IN T_AX ',' T_DX  */
#line 276 "../../src/intel-parse.yy"
                                   { (yyval.inst) = new AsmInstIN (2); }
#line 2257 "../../src/intel-parse.cc"
    break;

  case 62: /* port_inst: T_IN T_EAX ',' "number"  */
#line 277 "../../src/intel-parse.yy"
                                        { (yyval.inst) = new AsmInstIN ((yyvsp[0].number), 4); }
#line 2263 "../../src/intel-parse.cc"
    break;

  case 63: /* port_inst: T_IN T_EAX ',' T_DX  */
#line 278 "../../src/intel-parse.yy"
                                    { (yyval.inst) = new AsmInstIN (4); }
#line 2269 "../../src/intel-parse.cc"
    break;

  case 64: /* port_inst: T_OUT "number" ',' T_AL  */
#line 279 "../../src/intel-parse.yy"
                                        { (yyval.inst) = new AsmInstOUT ((yyvsp[-2].number), 1); }
#line 2275 "../../src/intel-parse.cc"
    break;

  case 65: /* port_inst: T_OUT T_DX ',' T_AL  */
#line 280 "../../src/intel-parse.yy"
                                    { (yyval.inst) = new AsmInstOUT (1); }
#line 2281 "../../src/intel-parse.cc"
    break;

  case 66: /* port_inst: T_OUT "number" ',' T_AX  */
#line 281 "../../src/intel-parse.yy"
                                        { (yyval.inst) = new AsmInstOUT ((yyvsp[-2].number), 2); }
#line 2287 "../../src/intel-parse.cc"
    break;

  case 67: /* port_inst: T_OUT T_DX ',' T_AX  */
#line 282 "../../src/intel-parse.yy"
                                    { (yyval.inst) = new AsmInstOUT (2); }
#line 2293 "../../src/intel-parse.cc"
    break;

  case 68: /* port_inst: T_OUT "number" ',' T_EAX  */
#line 283 "../../src/intel-parse.yy"
                                         { (yyval.inst) = new AsmInstOUT ((yyvsp[-2].number), 4); }
#line 2299 "../../src/intel-parse.cc"
    break;

  case 69: /* port_inst: T_OUT T_DX ',' T_EAX  */
#line 284 "../../src/intel-parse.yy"
                                     { (yyval.inst) = new AsmInstOUT (4); }
#line 2305 "../../src/intel-parse.cc"
    break;

  case 70: /* jmp_inst: T_JMP addr  */
#line 287 "../../src/intel-parse.yy"
                           { (yyval.inst) = new AsmInstJMP ((yyvsp[0].addr), 4); }
#line 2311 "../../src/intel-parse.cc"
    break;

  case 71: /* jmp_inst: T_JMP "near" addr  */
#line 288 "../../src/intel-parse.yy"
                                  { (yyval.inst) = new AsmInstJMP ((yyvsp[0].addr), 4); }
#line 2317 "../../src/intel-parse.cc"
    break;

  case 72: /* jmp_inst: T_JMP "number" ':' "number"  */
#line 289 "../../src/intel-parse.yy"
                                            { (yyval.inst) = new AsmInstJMPF ((yyvsp[-2].number), (yyvsp[0].number)); }
#line 2323 "../../src/intel-parse.cc"
    break;

  case 73: /* jmp_inst: T_JMP "far" "number" ':' "number"  */
#line 291 "../../src/intel-parse.yy"
                {
		  (yyval.inst) = new AsmInstJMPF ((yyvsp[-2].number), (yyvsp[0].number));
		}
#line 2331 "../../src/intel-parse.cc"
    break;

  case 74: /* jmp_inst: T_JMP storage  */
#line 294 "../../src/intel-parse.yy"
                              { (yyval.inst) = new AsmInstJMP ((yyvsp[0].storage)); }
#line 2337 "../../src/intel-parse.cc"
    break;

  case 75: /* jmp_inst: T_JMP "near" storage  */
#line 295 "../../src/intel-parse.yy"
                                     { (yyval.inst) = new AsmInstJMP ((yyvsp[0].storage)); }
#line 2343 "../../src/intel-parse.cc"
    break;

  case 76: /* jmp_inst: T_JMP "far" memloc  */
#line 296 "../../src/intel-parse.yy"
                                   { (yyval.inst) = new AsmInstJMPF ((yyvsp[0].mem)); }
#line 2349 "../../src/intel-parse.cc"
    break;

  case 77: /* string_inst: T_ZOS size_specifier  */
#line 299 "../../src/intel-parse.yy"
                                     { (yyval.strinst) = new AsmInstZOS ((yyvsp[-1].zos), (yyvsp[0].number)); }
#line 2355 "../../src/intel-parse.cc"
    break;

  case 78: /* rep_inst: T_REPNZ string_inst  */
#line 302 "../../src/intel-parse.yy"
                                    { (yyval.inst) = new AsmInstREPNZ ((yyvsp[0].strinst)); }
#line 2361 "../../src/intel-parse.cc"
    break;

  case 79: /* rep_inst: T_REPZ string_inst  */
#line 303 "../../src/intel-parse.yy"
                                   { (yyval.inst) = new AsmInstREPZ ((yyvsp[0].strinst)); }
#line 2367 "../../src/intel-parse.cc"
    break;

  case 80: /* directive: "global directive" "identifier"  */
#line 307 "../../src/intel-parse.yy"
                {
		  (yyval.directive) = nullptr;
		  global_syms.insert (*(yyvsp[0].string));
		  delete (yyvsp[0].string);
		}
#line 2377 "../../src/intel-parse.cc"
    break;

  case 81: /* directive: "section directive" "section name"  */
#line 313 "../../src/intel-parse.yy"
                {
		  (yyval.directive) = new AsmInstSECTION (*(yyvsp[0].string));
		  delete (yyvsp[0].string);
		}
#line 2386 "../../src/intel-parse.cc"
    break;

  case 82: /* directive: define_size "number"  */
#line 317 "../../src/intel-parse.yy"
                                     { (yyval.directive) = new AsmInstDEFINE ((yyvsp[-1].number), (yyvsp[0].number)); }
#line 2392 "../../src/intel-parse.cc"
    break;

  case 83: /* expression: immediate  */
#line 320 "../../src/intel-parse.yy"
                          { (yyval.expr) = (yyvsp[0].imm); }
#line 2398 "../../src/intel-parse.cc"
    break;

  case 84: /* expression: storage  */
#line 321 "../../src/intel-parse.yy"
                        { (yyval.expr) = (yyvsp[0].storage); }
#line 2404 "../../src/intel-parse.cc"
    break;

  case 85: /* immediate: "number"  */
#line 324 "../../src/intel-parse.yy"
                         { (yyval.imm) = new AsmImmediate ((yyvsp[0].number)); }
#line 2410 "../../src/intel-parse.cc"
    break;

  case 86: /* storage: reg  */
#line 327 "../../src/intel-parse.yy"
                    { (yyval.storage) = (yyvsp[0].reg); }
#line 2416 "../../src/intel-parse.cc"
    break;

  case 87: /* storage: memloc  */
#line 328 "../../src/intel-parse.yy"
                       { (yyval.storage) = (yyvsp[0].mem); }
#line 2422 "../../src/intel-parse.cc"
    break;

  case 88: /* memloc: size_specifier '[' deref ']'  */
#line 331 "../../src/intel-parse.yy"
                                             { (yyval.mem) = (yyvsp[-1].mem); (yyval.mem)->size = (yyvsp[-3].number); }
#line 2428 "../../src/intel-parse.cc"
    break;

  case 89: /* memloc: size_specifier '[' segment ':' deref ']'  */
#line 333 "../../src/intel-parse.yy"
                {
		  (yyval.mem) = (yyvsp[-1].mem);
		  (yyval.mem)->segment = (yyvsp[-3].reg);
		  (yyval.mem)->size = (yyvsp[-5].number);
		}
#line 2438 "../../src/intel-parse.cc"
    break;

  case 90: /* deref: "number"  */
#line 341 "../../src/intel-parse.yy"
                {
		  (yyval.mem) = new AsmMemoryLoc (nullptr, nullptr, 0, (yyvsp[0].number),
					 AsmRegister::DS, 0);
		}
#line 2447 "../../src/intel-parse.cc"
    break;

  case 91: /* deref: reg  */
#line 346 "../../src/intel-parse.yy"
                {
		  (yyval.mem) = new AsmMemoryLoc ((yyvsp[0].reg), nullptr, 0, 0,
					 (yyvsp[0].reg)->id == AsmRegister::EBP->id ?
					 AsmRegister::SS : AsmRegister::DS, 0);
		}
#line 2457 "../../src/intel-parse.cc"
    break;

  case 92: /* deref: reg '+' "number"  */
#line 352 "../../src/intel-parse.yy"
                {
		  (yyval.mem) = new AsmMemoryLoc ((yyvsp[-2].reg), nullptr, 0, (yyvsp[0].number),
					 (yyvsp[-2].reg)->id == AsmRegister::EBP->id ?
					 AsmRegister::SS : AsmRegister::DS, 0);
		}
#line 2467 "../../src/intel-parse.cc"
    break;

  case 93: /* deref: reg '+' reg  */
#line 358 "../../src/intel-parse.yy"
                {
		  (yyval.mem) = new AsmMemoryLoc ((yyvsp[-2].reg), (yyvsp[0].reg), 1, 0,
					 (yyvsp[-2].reg)->id == AsmRegister::EBP->id ?
					 AsmRegister::SS : AsmRegister::DS, 0);
		}
#line 2477 "../../src/intel-parse.cc"
    break;

  case 94: /* deref: reg '+' reg '+' "number"  */
#line 364 "../../src/intel-parse.yy"
                {
		  (yyval.mem) = new AsmMemoryLoc ((yyvsp[-4].reg), (yyvsp[-2].reg), 1, (yyvsp[0].number),
					 (yyvsp[-4].reg)->id == AsmRegister::EBP->id ?
					 AsmRegister::SS : AsmRegister::DS, 0);
		}
#line 2487 "../../src/intel-parse.cc"
    break;

  case 95: /* deref: reg '+' reg '*' "number"  */
#line 370 "../../src/intel-parse.yy"
                {
		  (yyval.mem) = new AsmMemoryLoc ((yyvsp[-4].reg), (yyvsp[-2].reg), (yyvsp[0].number), 0,
					 (yyvsp[-4].reg)->id == AsmRegister::EBP->id ?
					 AsmRegister::SS : AsmRegister::DS, 0);
		}
#line 2497 "../../src/intel-parse.cc"
    break;

  case 96: /* deref: reg '+' reg '*' "number" '+' "number"  */
#line 376 "../../src/intel-parse.yy"
                {
		  (yyval.mem) = new AsmMemoryLoc ((yyvsp[-6].reg), (yyvsp[-4].reg), (yyvsp[-2].number), (yyvsp[0].number),
					 (yyvsp[-6].reg)->id == AsmRegister::EBP->id ?
					 AsmRegister::SS : AsmRegister::DS, 0);
		}
#line 2507 "../../src/intel-parse.cc"
    break;

  case 98: /* reg: T_AL  */
#line 384 "../../src/intel-parse.yy"
                     { (yyval.reg) = AsmRegister::AL; }
#line 2513 "../../src/intel-parse.cc"
    break;

  case 99: /* reg: T_CL  */
#line 385 "../../src/intel-parse.yy"
                     { (yyval.reg) = AsmRegister::CL; }
#line 2519 "../../src/intel-parse.cc"
    break;

  case 100: /* reg: T_DL  */
#line 386 "../../src/intel-parse.yy"
                     { (yyval.reg) = AsmRegister::DL; }
#line 2525 "../../src/intel-parse.cc"
    break;

  case 101: /* reg: T_BL  */
#line 387 "../../src/intel-parse.yy"
                     { (yyval.reg) = AsmRegister::BL; }
#line 2531 "../../src/intel-parse.cc"
    break;

  case 102: /* reg: T_AH  */
#line 388 "../../src/intel-parse.yy"
                     { (yyval.reg) = AsmRegister::AH; }
#line 2537 "../../src/intel-parse.cc"
    break;

  case 103: /* reg: T_CH  */
#line 389 "../../src/intel-parse.yy"
                     { (yyval.reg) = AsmRegister::CH; }
#line 2543 "../../src/intel-parse.cc"
    break;

  case 104: /* reg: T_DH  */
#line 390 "../../src/intel-parse.yy"
                     { (yyval.reg) = AsmRegister::DH; }
#line 2549 "../../src/intel-parse.cc"
    break;

  case 105: /* reg: T_BH  */
#line 391 "../../src/intel-parse.yy"
                     { (yyval.reg) = AsmRegister::BH; }
#line 2555 "../../src/intel-parse.cc"
    break;

  case 106: /* reg: T_AX  */
#line 392 "../../src/intel-parse.yy"
                     { (yyval.reg) = AsmRegister::AX; }
#line 2561 "../../src/intel-parse.cc"
    break;

  case 107: /* reg: T_CX  */
#line 393 "../../src/intel-parse.yy"
                     { (yyval.reg) = AsmRegister::CX; }
#line 2567 "../../src/intel-parse.cc"
    break;

  case 108: /* reg: T_DX  */
#line 394 "../../src/intel-parse.yy"
                     { (yyval.reg) = AsmRegister::DX; }
#line 2573 "../../src/intel-parse.cc"
    break;

  case 109: /* reg: T_BX  */
#line 395 "../../src/intel-parse.yy"
                     { (yyval.reg) = AsmRegister::BX; }
#line 2579 "../../src/intel-parse.cc"
    break;

  case 110: /* reg: T_SP  */
#line 396 "../../src/intel-parse.yy"
                     { (yyval.reg) = AsmRegister::SP; }
#line 2585 "../../src/intel-parse.cc"
    break;

  case 111: /* reg: T_BP  */
#line 397 "../../src/intel-parse.yy"
                     { (yyval.reg) = AsmRegister::BP; }
#line 2591 "../../src/intel-parse.cc"
    break;

  case 112: /* reg: T_SI  */
#line 398 "../../src/intel-parse.yy"
                     { (yyval.reg) = AsmRegister::SI; }
#line 2597 "../../src/intel-parse.cc"
    break;

  case 113: /* reg: T_DI  */
#line 399 "../../src/intel-parse.yy"
                     { (yyval.reg) = AsmRegister::DI; }
#line 2603 "../../src/intel-parse.cc"
    break;

  case 114: /* reg: T_EAX  */
#line 400 "../../src/intel-parse.yy"
                      { (yyval.reg) = AsmRegister::EAX; }
#line 2609 "../../src/intel-parse.cc"
    break;

  case 115: /* reg: T_ECX  */
#line 401 "../../src/intel-parse.yy"
                      { (yyval.reg) = AsmRegister::ECX; }
#line 2615 "../../src/intel-parse.cc"
    break;

  case 116: /* reg: T_EDX  */
#line 402 "../../src/intel-parse.yy"
                      { (yyval.reg) = AsmRegister::EDX; }
#line 2621 "../../src/intel-parse.cc"
    break;

  case 117: /* reg: T_EBX  */
#line 403 "../../src/intel-parse.yy"
                      { (yyval.reg) = AsmRegister::EBX; }
#line 2627 "../../src/intel-parse.cc"
    break;

  case 118: /* reg: T_ESP  */
#line 404 "../../src/intel-parse.yy"
                      { (yyval.reg) = AsmRegister::ESP; }
#line 2633 "../../src/intel-parse.cc"
    break;

  case 119: /* reg: T_EBP  */
#line 405 "../../src/intel-parse.yy"
                      { (yyval.reg) = AsmRegister::EBP; }
#line 2639 "../../src/intel-parse.cc"
    break;

  case 120: /* reg: T_ESI  */
#line 406 "../../src/intel-parse.yy"
                      { (yyval.reg) = AsmRegister::ESI; }
#line 2645 "../../src/intel-parse.cc"
    break;

  case 121: /* reg: T_EDI  */
#line 407 "../../src/intel-parse.yy"
                      { (yyval.reg) = AsmRegister::EDI; }
#line 2651 "../../src/intel-parse.cc"
    break;

  case 122: /* segment: "register"  */
#line 410 "../../src/intel-parse.yy"
                     { (yyval.reg) = AsmRegister::CS; }
#line 2657 "../../src/intel-parse.cc"
    break;

  case 123: /* segment: T_DS  */
#line 411 "../../src/intel-parse.yy"
                     { (yyval.reg) = AsmRegister::DS; }
#line 2663 "../../src/intel-parse.cc"
    break;

  case 124: /* segment: T_ES  */
#line 412 "../../src/intel-parse.yy"
                     { (yyval.reg) = AsmRegister::ES; }
#line 2669 "../../src/intel-parse.cc"
    break;

  case 125: /* segment: T_FS  */
#line 413 "../../src/intel-parse.yy"
                     { (yyval.reg) = AsmRegister::FS; }
#line 2675 "../../src/intel-parse.cc"
    break;

  case 126: /* segment: T_GS  */
#line 414 "../../src/intel-parse.yy"
                     { (yyval.reg) = AsmRegister::GS; }
#line 2681 "../../src/intel-parse.cc"
    break;

  case 127: /* size_specifier: "byte"  */
#line 417 "../../src/intel-parse.yy"
                       { (yyval.number) = 1; }
#line 2687 "../../src/intel-parse.cc"
    break;

  case 128: /* size_specifier: "word"  */
#line 418 "../../src/intel-parse.yy"
                       { (yyval.number) = 2; }
#line 2693 "../../src/intel-parse.cc"
    break;

  case 129: /* size_specifier: "dword"  */
#line 419 "../../src/intel-parse.yy"
                        { (yyval.number) = 4; }
#line 2699 "../../src/intel-parse.cc"
    break;

  case 132: /* label: "identifier" ':'  */
#line 426 "../../src/intel-parse.yy"
                            { (yyval.label) = new AsmIdentifier (*(yyvsp[-1].string)); delete (yyvsp[-1].string); }
#line 2705 "../../src/intel-parse.cc"
    break;

  case 133: /* label: "identifier"  */
#line 428 "../../src/intel-parse.yy"
                {
		  warning ("label alone on a line without a colon");
		  (yyval.label) = new AsmIdentifier (*(yyvsp[0].string));
		  delete (yyvsp[0].string);
		}
#line 2715 "../../src/intel-parse.cc"
    break;

  case 134: /* addr: "identifier"  */
#line 435 "../../src/intel-parse.yy"
                        { (yyval.addr) = new AsmIdentifier (*(yyvsp[0].string)); delete (yyvsp[0].string); }
#line 2721 "../../src/intel-parse.cc"
    break;

  case 135: /* addr: immediate  */
#line 436 "../../src/intel-parse.yy"
                          { (yyval.addr) = (yyvsp[0].imm); }
#line 2727 "../../src/intel-parse.cc"
    break;

  case 136: /* define_size: "directive"  */
#line 439 "../../src/intel-parse.yy"
                     { (yyval.number) = 1; }
#line 2733 "../../src/intel-parse.cc"
    break;

  case 137: /* define_size: T_DW  */
#line 440 "../../src/intel-parse.yy"
                     { (yyval.number) = 2; }
#line 2739 "../../src/intel-parse.cc"
    break;

  case 138: /* define_size: T_DD  */
#line 441 "../../src/intel-parse.yy"
                     { (yyval.number) = 4; }
#line 2745 "../../src/intel-parse.cc"
    break;

  case 139: /* define_size: T_DQ  */
#line 442 "../../src/intel-parse.yy"
                     { (yyval.number) = 8; }
#line 2751 "../../src/intel-parse.cc"
    break;


#line 2755 "../../src/intel-parse.cc"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      {
        yypcontext_t yyctx
          = {yyssp, yytoken};
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = yysyntax_error (&yymsg_alloc, &yymsg, &yyctx);
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == -1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = YY_CAST (char *,
                             YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
            if (yymsg)
              {
                yysyntax_error_status
                  = yysyntax_error (&yymsg_alloc, &yymsg, &yyctx);
                yymsgp = yymsg;
              }
            else
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = YYENOMEM;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == YYENOMEM)
          goto yyexhaustedlab;
      }
    }

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;


#if 1
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturn;
#endif


/*-------------------------------------------------------.
| yyreturn -- parsing is finished, clean up and return.  |
`-------------------------------------------------------*/
yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
  return yyresult;
}

