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


#line 91 "../../src/intel-parse.cc"

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

#line 346 "../../src/intel-parse.cc"

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
  YYSYMBOL_T_AAD = 16,                     /* T_AAD  */
  YYSYMBOL_T_AAM = 17,                     /* T_AAM  */
  YYSYMBOL_T_CALL = 18,                    /* T_CALL  */
  YYSYMBOL_T_CMPS = 19,                    /* T_CMPS  */
  YYSYMBOL_T_DEC = 20,                     /* T_DEC  */
  YYSYMBOL_T_DIV = 21,                     /* T_DIV  */
  YYSYMBOL_T_IDIV = 22,                    /* T_IDIV  */
  YYSYMBOL_T_IMUL = 23,                    /* T_IMUL  */
  YYSYMBOL_T_IN = 24,                      /* T_IN  */
  YYSYMBOL_T_INC = 25,                     /* T_INC  */
  YYSYMBOL_T_INS = 26,                     /* T_INS  */
  YYSYMBOL_T_INT = 27,                     /* T_INT  */
  YYSYMBOL_T_JMP = 28,                     /* T_JMP  */
  YYSYMBOL_T_LEA = 29,                     /* T_LEA  */
  YYSYMBOL_T_LODS = 30,                    /* T_LODS  */
  YYSYMBOL_T_LOOP = 31,                    /* T_LOOP  */
  YYSYMBOL_T_LOOPNZ = 32,                  /* T_LOOPNZ  */
  YYSYMBOL_T_LOOPZ = 33,                   /* T_LOOPZ  */
  YYSYMBOL_T_MOV = 34,                     /* T_MOV  */
  YYSYMBOL_T_MOVS = 35,                    /* T_MOVS  */
  YYSYMBOL_T_MUL = 36,                     /* T_MUL  */
  YYSYMBOL_T_NEG = 37,                     /* T_NEG  */
  YYSYMBOL_T_NOT = 38,                     /* T_NOT  */
  YYSYMBOL_T_OUT = 39,                     /* T_OUT  */
  YYSYMBOL_T_OUTS = 40,                    /* T_OUTS  */
  YYSYMBOL_T_POP = 41,                     /* T_POP  */
  YYSYMBOL_T_PUSH = 42,                    /* T_PUSH  */
  YYSYMBOL_T_RCL = 43,                     /* T_RCL  */
  YYSYMBOL_T_RCR = 44,                     /* T_RCR  */
  YYSYMBOL_T_REPNZ = 45,                   /* T_REPNZ  */
  YYSYMBOL_T_REPZ = 46,                    /* T_REPZ  */
  YYSYMBOL_T_RET = 47,                     /* T_RET  */
  YYSYMBOL_T_ROL = 48,                     /* T_ROL  */
  YYSYMBOL_T_ROR = 49,                     /* T_ROR  */
  YYSYMBOL_T_SAR = 50,                     /* T_SAR  */
  YYSYMBOL_T_SCAS = 51,                    /* T_SCAS  */
  YYSYMBOL_T_SHL = 52,                     /* T_SHL  */
  YYSYMBOL_T_SHR = 53,                     /* T_SHR  */
  YYSYMBOL_T_STOS = 54,                    /* T_STOS  */
  YYSYMBOL_T_TEST = 55,                    /* T_TEST  */
  YYSYMBOL_T_XCHG = 56,                    /* T_XCHG  */
  YYSYMBOL_T_DB = 57,                      /* "directive"  */
  YYSYMBOL_T_DW = 58,                      /* T_DW  */
  YYSYMBOL_T_DD = 59,                      /* T_DD  */
  YYSYMBOL_T_DQ = 60,                      /* T_DQ  */
  YYSYMBOL_T_SECTION = 61,                 /* "section directive"  */
  YYSYMBOL_T_GLOBAL = 62,                  /* "global directive"  */
  YYSYMBOL_T_CS = 63,                      /* "register"  */
  YYSYMBOL_T_DS = 64,                      /* T_DS  */
  YYSYMBOL_T_ES = 65,                      /* T_ES  */
  YYSYMBOL_T_FS = 66,                      /* T_FS  */
  YYSYMBOL_T_GS = 67,                      /* T_GS  */
  YYSYMBOL_T_AL = 68,                      /* T_AL  */
  YYSYMBOL_T_CL = 69,                      /* T_CL  */
  YYSYMBOL_T_DL = 70,                      /* T_DL  */
  YYSYMBOL_T_BL = 71,                      /* T_BL  */
  YYSYMBOL_T_AH = 72,                      /* T_AH  */
  YYSYMBOL_T_CH = 73,                      /* T_CH  */
  YYSYMBOL_T_DH = 74,                      /* T_DH  */
  YYSYMBOL_T_BH = 75,                      /* T_BH  */
  YYSYMBOL_T_AX = 76,                      /* T_AX  */
  YYSYMBOL_T_CX = 77,                      /* T_CX  */
  YYSYMBOL_T_DX = 78,                      /* T_DX  */
  YYSYMBOL_T_BX = 79,                      /* T_BX  */
  YYSYMBOL_T_SP = 80,                      /* T_SP  */
  YYSYMBOL_T_BP = 81,                      /* T_BP  */
  YYSYMBOL_T_SI = 82,                      /* T_SI  */
  YYSYMBOL_T_DI = 83,                      /* T_DI  */
  YYSYMBOL_T_EAX = 84,                     /* T_EAX  */
  YYSYMBOL_T_ECX = 85,                     /* T_ECX  */
  YYSYMBOL_T_EDX = 86,                     /* T_EDX  */
  YYSYMBOL_T_EBX = 87,                     /* T_EBX  */
  YYSYMBOL_T_ESP = 88,                     /* T_ESP  */
  YYSYMBOL_T_EBP = 89,                     /* T_EBP  */
  YYSYMBOL_T_ESI = 90,                     /* T_ESI  */
  YYSYMBOL_T_EDI = 91,                     /* T_EDI  */
  YYSYMBOL_92_ = 92,                       /* ','  */
  YYSYMBOL_93_ = 93,                       /* ':'  */
  YYSYMBOL_94_ = 94,                       /* '['  */
  YYSYMBOL_95_ = 95,                       /* ']'  */
  YYSYMBOL_96_ = 96,                       /* ';'  */
  YYSYMBOL_97_n_ = 97,                     /* '\n'  */
  YYSYMBOL_YYACCEPT = 98,                  /* $accept  */
  YYSYMBOL_program = 99,                   /* program  */
  YYSYMBOL_object = 100,                   /* object  */
  YYSYMBOL_lines = 101,                    /* lines  */
  YYSYMBOL_instruction = 102,              /* instruction  */
  YYSYMBOL_ascii_inst = 103,               /* ascii_inst  */
  YYSYMBOL_call_inst = 104,                /* call_inst  */
  YYSYMBOL_directive = 105,                /* directive  */
  YYSYMBOL_expression = 106,               /* expression  */
  YYSYMBOL_immediate = 107,                /* immediate  */
  YYSYMBOL_storage = 108,                  /* storage  */
  YYSYMBOL_memloc = 109,                   /* memloc  */
  YYSYMBOL_reg = 110,                      /* reg  */
  YYSYMBOL_size_specifier = 111,           /* size_specifier  */
  YYSYMBOL_terminator = 112,               /* terminator  */
  YYSYMBOL_label = 113,                    /* label  */
  YYSYMBOL_addr = 114,                     /* addr  */
  YYSYMBOL_define_size = 115               /* define_size  */
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
typedef yytype_int8 yy_state_t;

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
#define YYFINAL  87
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   293

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  98
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  18
/* YYNRULES -- Number of rules.  */
#define YYNRULES  83
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  111

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   346


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
      97,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,    92,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    93,    96,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    94,     2,    95,     2,     2,     2,     2,     2,     2,
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
      85,    86,    87,    88,    89,    90,    91
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   173,   173,   176,   184,   189,   194,   195,   196,   199,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   217,   218,   219,   220,   223,   224,   225,   226,
     230,   231,   232,   235,   236,   241,   244,   245,   248,   251,
     252,   255,   262,   263,   264,   265,   266,   267,   268,   269,
     270,   271,   272,   273,   274,   275,   276,   277,   278,   279,
     280,   281,   282,   283,   284,   285,   286,   287,   288,   289,
     290,   293,   294,   295,   298,   299,   302,   303,   311,   312,
     315,   316,   317,   318
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
  "instruction mnemonic", "T_JF", "T_ZO", "T_ZOS", "T_AAD", "T_AAM",
  "T_CALL", "T_CMPS", "T_DEC", "T_DIV", "T_IDIV", "T_IMUL", "T_IN",
  "T_INC", "T_INS", "T_INT", "T_JMP", "T_LEA", "T_LODS", "T_LOOP",
  "T_LOOPNZ", "T_LOOPZ", "T_MOV", "T_MOVS", "T_MUL", "T_NEG", "T_NOT",
  "T_OUT", "T_OUTS", "T_POP", "T_PUSH", "T_RCL", "T_RCR", "T_REPNZ",
  "T_REPZ", "T_RET", "T_ROL", "T_ROR", "T_SAR", "T_SCAS", "T_SHL", "T_SHR",
  "T_STOS", "T_TEST", "T_XCHG", "directive", "T_DW", "T_DD", "T_DQ",
  "section directive", "global directive", "register", "T_DS", "T_ES",
  "T_FS", "T_GS", "T_AL", "T_CL", "T_DL", "T_BL", "T_AH", "T_CH", "T_DH",
  "T_BH", "T_AX", "T_CX", "T_DX", "T_BX", "T_SP", "T_BP", "T_SI", "T_DI",
  "T_EAX", "T_ECX", "T_EDX", "T_EBX", "T_ESP", "T_EBP", "T_ESI", "T_EDI",
  "','", "':'", "'['", "']'", "';'", "'\\n'", "$accept", "program",
  "object", "lines", "instruction", "ascii_inst", "call_inst", "directive",
  "expression", "immediate", "storage", "memloc", "reg", "size_specifier",
  "terminator", "label", "addr", "define_size", YY_NULLPTR
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
     345,   346,    44,    58,    91,    93,    59,    10
};
#endif

#define YYPACT_NINF (-93)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     231,   -92,   142,    14,   -93,     7,    13,    17,    -3,   142,
     142,   142,   142,   142,   142,   -93,   -93,   -93,   -93,    19,
      21,    25,   -93,   -76,   -93,   -93,   -93,   -93,   -93,    22,
     -93,   -93,   -93,   -93,   -93,   -93,   -93,   -93,   -93,   -93,
     -93,   -93,   -93,   -93,   -93,   -93,   -93,   -93,   -93,   -93,
     -93,   -93,   -93,   -93,   -93,   -93,   -93,   -93,   -93,   -93,
     -93,   -93,   -93,   -66,   -93,   -93,   -64,   -93,   -93,   -93,
     -93,   -93,   -93,   -93,   -65,    26,     4,   -93,   -93,   -93,
     -93,   -93,   -93,   -93,   -60,   -93,   -93,   -93,   -93,   -93,
     231,   -93,   113,    31,    32,   -93,   -93,   -55,   -93,   113,
     -93,   -93,   -93,   -93,   -93,   -56,   -93,    35,   -93,   -93,
     -93
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,    77,     0,     0,    11,     0,    23,    25,     0,     0,
       0,     0,     0,     0,     0,    80,    81,    82,    83,     0,
       0,     0,     2,     3,     4,    13,    14,    21,     5,     0,
      76,    71,    72,    73,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    69,    70,     0,    40,    39,     0,    78,    38,    79,
      10,    12,    22,    24,    38,     0,     0,    30,    26,    15,
      16,    17,    18,    19,     0,    34,    33,     1,    74,    75,
       8,    35,     0,     0,     0,    31,    27,     0,    32,     0,
       6,     7,     9,    36,    37,     0,    28,     0,    20,    41,
      29
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -93,   -93,   -93,   -93,   -49,   -93,   -93,   -93,   -57,   -89,
      44,   -33,   -93,    39,   -93,   -45,    51,   -93
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,    21,    22,    23,    24,    25,    26,    27,   102,    69,
     104,    64,    65,    66,    90,    28,    70,    29
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      67,    30,    74,   103,    31,    32,    33,    75,    76,    97,
     103,    31,    32,    33,    31,    32,    33,    67,    72,    68,
      88,    89,    73,    85,    86,    87,    92,    91,    94,    67,
      93,    68,    99,    31,    32,    33,   105,   106,   107,   109,
     110,   100,   108,    98,    71,   101,    63,     0,     0,     0,
       0,     0,    77,    79,    80,    81,    82,    83,    84,    78,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    68,    95,
      31,    32,    33,     0,     0,     0,    96,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    31,
      32,    33,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,     1,     0,     0,     0,     0,     0,
       0,     0,     0,     2,     3,     4,     5,     6,     7,     8,
       0,     9,    10,    11,    12,     0,    13,     0,     0,     0,
       0,     0,     0,     0,     0,    14,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    15,    16,
      17,    18,    19,    20
};

static const yytype_int8 yycheck[] =
{
       3,    93,     5,    92,     7,     8,     9,    10,    11,     5,
      99,     7,     8,     9,     7,     8,     9,     3,     5,     5,
      96,    97,     5,     4,     3,     0,    92,     5,    93,     3,
      94,     5,    92,     7,     8,     9,     5,     5,    93,    95,
       5,    90,    99,    76,     5,    90,     2,    -1,    -1,    -1,
      -1,    -1,     8,     9,    10,    11,    12,    13,    14,     8,
      63,    64,    65,    66,    67,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    63,
      64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,     5,    75,
       7,     8,     9,    -1,    -1,    -1,    75,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     7,
       8,     9,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    63,    64,    65,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    63,    64,    65,    66,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,     3,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    12,    13,    14,    15,    16,    17,    18,
      -1,    20,    21,    22,    23,    -1,    25,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    34,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    57,    58,
      59,    60,    61,    62
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,    12,    13,    14,    15,    16,    17,    18,    20,
      21,    22,    23,    25,    34,    57,    58,    59,    60,    61,
      62,    99,   100,   101,   102,   103,   104,   105,   113,   115,
      93,     7,     8,     9,    63,    64,    65,    66,    67,    68,
      69,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    91,   108,   109,   110,   111,     3,     5,   107,
     114,   111,     5,     5,     5,    10,    11,   108,   114,   108,
     108,   108,   108,   108,   108,     4,     3,     0,    96,    97,
     112,     5,    92,    94,    93,   108,   114,     5,   109,    92,
     102,   113,   106,   107,   108,     5,     5,    93,   106,    95,
       5
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    98,    99,   100,   101,   101,   101,   101,   101,   102,
     102,   102,   102,   102,   102,   102,   102,   102,   102,   102,
     102,   102,   103,   103,   103,   103,   104,   104,   104,   104,
     104,   104,   104,   105,   105,   105,   106,   106,   107,   108,
     108,   109,   110,   110,   110,   110,   110,   110,   110,   110,
     110,   110,   110,   110,   110,   110,   110,   110,   110,   110,
     110,   110,   110,   110,   110,   110,   110,   110,   110,   110,
     110,   111,   111,   111,   112,   112,   113,   113,   114,   114,
     115,   115,   115,   115
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     1,     1,     3,     3,     2,     4,
       2,     1,     2,     1,     1,     2,     2,     2,     2,     2,
       4,     1,     2,     1,     2,     1,     2,     3,     4,     5,
       2,     3,     3,     2,     2,     2,     1,     1,     1,     1,
       1,     4,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     2,     1,     1,     1,
       1,     1,     1,     1
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
#line 173 "../../src/intel-parse.yy"
                       { result = (yyvsp[0].obj); }
#line 1799 "../../src/intel-parse.cc"
    break;

  case 3: /* object: lines  */
#line 177 "../../src/intel-parse.yy"
                {
		  (yyval.obj) = new Object (format, filename);
		  (yyval.obj)->lines = *(yyvsp[0].lines);
		  delete (yyvsp[0].lines);
		}
#line 1809 "../../src/intel-parse.cc"
    break;

  case 4: /* lines: instruction  */
#line 185 "../../src/intel-parse.yy"
                {
		  (yyval.lines) = new std::vector <AsmLine *> ();
		  (yyval.lines)->push_back ((yyvsp[0].inst));
		}
#line 1818 "../../src/intel-parse.cc"
    break;

  case 5: /* lines: label  */
#line 190 "../../src/intel-parse.yy"
                {
		  (yyval.lines) = new std::vector <AsmLine *> ();
		  (yyval.lines)->push_back ((yyvsp[0].label));
		}
#line 1827 "../../src/intel-parse.cc"
    break;

  case 6: /* lines: lines terminator instruction  */
#line 194 "../../src/intel-parse.yy"
                                             { (yyvsp[-2].lines)->push_back ((yyvsp[0].inst)); }
#line 1833 "../../src/intel-parse.cc"
    break;

  case 7: /* lines: lines terminator label  */
#line 195 "../../src/intel-parse.yy"
                                       { (yyvsp[-2].lines)->push_back ((yyvsp[0].label)); }
#line 1839 "../../src/intel-parse.cc"
    break;

  case 9: /* instruction: "instruction mnemonic" storage ',' expression  */
#line 200 "../../src/intel-parse.yy"
                {
		  (yyval.inst) = new AsmInstARITH ((yyvsp[-3].arith), (yyvsp[-2].storage), (yyvsp[0].expr));
		}
#line 1847 "../../src/intel-parse.cc"
    break;

  case 10: /* instruction: T_JF addr  */
#line 203 "../../src/intel-parse.yy"
                          { (yyval.inst) = new AsmInstJF ((yyvsp[-1].jf), (yyvsp[0].addr), 4); }
#line 1853 "../../src/intel-parse.cc"
    break;

  case 11: /* instruction: T_ZO  */
#line 204 "../../src/intel-parse.yy"
                     { (yyval.inst) = new AsmInstZO ((yyvsp[0].zo)); }
#line 1859 "../../src/intel-parse.cc"
    break;

  case 12: /* instruction: T_ZOS size_specifier  */
#line 205 "../../src/intel-parse.yy"
                                     { (yyval.inst) = new AsmInstZOS ((yyvsp[-1].zos), (yyvsp[0].number)); }
#line 1865 "../../src/intel-parse.cc"
    break;

  case 15: /* instruction: T_DEC storage  */
#line 208 "../../src/intel-parse.yy"
                              { (yyval.inst) = new AsmInstDEC ((yyvsp[0].storage)); }
#line 1871 "../../src/intel-parse.cc"
    break;

  case 16: /* instruction: T_DIV storage  */
#line 209 "../../src/intel-parse.yy"
                              { (yyval.inst) = new AsmInstDIV ((yyvsp[0].storage)); }
#line 1877 "../../src/intel-parse.cc"
    break;

  case 17: /* instruction: T_IDIV storage  */
#line 210 "../../src/intel-parse.yy"
                               { (yyval.inst) = new AsmInstIDIV ((yyvsp[0].storage)); }
#line 1883 "../../src/intel-parse.cc"
    break;

  case 18: /* instruction: T_IMUL storage  */
#line 211 "../../src/intel-parse.yy"
                               { (yyval.inst) = new AsmInstIMUL ((yyvsp[0].storage)); }
#line 1889 "../../src/intel-parse.cc"
    break;

  case 19: /* instruction: T_INC storage  */
#line 212 "../../src/intel-parse.yy"
                              { (yyval.inst) = new AsmInstINC ((yyvsp[0].storage)); }
#line 1895 "../../src/intel-parse.cc"
    break;

  case 20: /* instruction: T_MOV storage ',' expression  */
#line 213 "../../src/intel-parse.yy"
                                             { (yyval.inst) = new AsmInstMOV ((yyvsp[-2].storage), (yyvsp[0].expr)); }
#line 1901 "../../src/intel-parse.cc"
    break;

  case 22: /* ascii_inst: T_AAD "number"  */
#line 217 "../../src/intel-parse.yy"
                               { (yyval.inst) = new AsmInstAAD ((yyvsp[0].number)); }
#line 1907 "../../src/intel-parse.cc"
    break;

  case 23: /* ascii_inst: T_AAD  */
#line 218 "../../src/intel-parse.yy"
                      { (yyval.inst) = new AsmInstAAD (); }
#line 1913 "../../src/intel-parse.cc"
    break;

  case 24: /* ascii_inst: T_AAM "number"  */
#line 219 "../../src/intel-parse.yy"
                               { (yyval.inst) = new AsmInstAAM ((yyvsp[0].number)); }
#line 1919 "../../src/intel-parse.cc"
    break;

  case 25: /* ascii_inst: T_AAM  */
#line 220 "../../src/intel-parse.yy"
                      { (yyval.inst) = new AsmInstAAM (); }
#line 1925 "../../src/intel-parse.cc"
    break;

  case 26: /* call_inst: T_CALL addr  */
#line 223 "../../src/intel-parse.yy"
                            { (yyval.inst) = new AsmInstCALL ((yyvsp[0].addr), 4); }
#line 1931 "../../src/intel-parse.cc"
    break;

  case 27: /* call_inst: T_CALL "near" addr  */
#line 224 "../../src/intel-parse.yy"
                                   { (yyval.inst) = new AsmInstCALL ((yyvsp[0].addr), 4); }
#line 1937 "../../src/intel-parse.cc"
    break;

  case 28: /* call_inst: T_CALL "number" ':' "number"  */
#line 225 "../../src/intel-parse.yy"
                                             { (yyval.inst) = new AsmInstCALLF ((yyvsp[-2].number), (yyvsp[0].number)); }
#line 1943 "../../src/intel-parse.cc"
    break;

  case 29: /* call_inst: T_CALL "far" "number" ':' "number"  */
#line 227 "../../src/intel-parse.yy"
                {
		  (yyval.inst) = new AsmInstCALLF ((yyvsp[-2].number), (yyvsp[0].number));
		}
#line 1951 "../../src/intel-parse.cc"
    break;

  case 30: /* call_inst: T_CALL storage  */
#line 230 "../../src/intel-parse.yy"
                               { (yyval.inst) = new AsmInstCALL ((yyvsp[0].storage)); }
#line 1957 "../../src/intel-parse.cc"
    break;

  case 31: /* call_inst: T_CALL "near" storage  */
#line 231 "../../src/intel-parse.yy"
                                      { (yyval.inst) = new AsmInstCALL ((yyvsp[0].storage)); }
#line 1963 "../../src/intel-parse.cc"
    break;

  case 32: /* call_inst: T_CALL "far" memloc  */
#line 232 "../../src/intel-parse.yy"
                                    { (yyval.inst) = new AsmInstCALLF ((yyvsp[0].mem)); }
#line 1969 "../../src/intel-parse.cc"
    break;

  case 33: /* directive: "global directive" "identifier"  */
#line 235 "../../src/intel-parse.yy"
                                 { global_syms.insert (*(yyvsp[0].string)); delete (yyvsp[0].string); }
#line 1975 "../../src/intel-parse.cc"
    break;

  case 34: /* directive: "section directive" "section name"  */
#line 237 "../../src/intel-parse.yy"
                {
		  (yyval.inst) = new AsmInstSECTION (*(yyvsp[0].string));
		  delete (yyvsp[0].string);
		}
#line 1984 "../../src/intel-parse.cc"
    break;

  case 35: /* directive: define_size "number"  */
#line 241 "../../src/intel-parse.yy"
                                     { (yyval.inst) = new AsmInstDEFINE ((yyvsp[-1].number), (yyvsp[0].number)); }
#line 1990 "../../src/intel-parse.cc"
    break;

  case 36: /* expression: immediate  */
#line 244 "../../src/intel-parse.yy"
                          { (yyval.expr) = (yyvsp[0].imm); }
#line 1996 "../../src/intel-parse.cc"
    break;

  case 37: /* expression: storage  */
#line 245 "../../src/intel-parse.yy"
                        { (yyval.expr) = (yyvsp[0].storage); }
#line 2002 "../../src/intel-parse.cc"
    break;

  case 38: /* immediate: "number"  */
#line 248 "../../src/intel-parse.yy"
                         { (yyval.imm) = new AsmImmediate ((yyvsp[0].number)); }
#line 2008 "../../src/intel-parse.cc"
    break;

  case 39: /* storage: reg  */
#line 251 "../../src/intel-parse.yy"
                    { (yyval.storage) = (yyvsp[0].reg); }
#line 2014 "../../src/intel-parse.cc"
    break;

  case 40: /* storage: memloc  */
#line 252 "../../src/intel-parse.yy"
                       { (yyval.storage) = (yyvsp[0].mem); }
#line 2020 "../../src/intel-parse.cc"
    break;

  case 41: /* memloc: size_specifier '[' "number" ']'  */
#line 256 "../../src/intel-parse.yy"
                {
		  (yyval.mem) = new AsmMemoryLoc (nullptr, nullptr, 0, (yyvsp[-1].number),
					 AsmRegister::DS, (yyvsp[-3].number));
		}
#line 2029 "../../src/intel-parse.cc"
    break;

  case 42: /* reg: "register"  */
#line 262 "../../src/intel-parse.yy"
                     { (yyval.reg) = AsmRegister::CS; }
#line 2035 "../../src/intel-parse.cc"
    break;

  case 43: /* reg: T_DS  */
#line 263 "../../src/intel-parse.yy"
                     { (yyval.reg) = AsmRegister::DS; }
#line 2041 "../../src/intel-parse.cc"
    break;

  case 44: /* reg: T_ES  */
#line 264 "../../src/intel-parse.yy"
                     { (yyval.reg) = AsmRegister::ES; }
#line 2047 "../../src/intel-parse.cc"
    break;

  case 45: /* reg: T_FS  */
#line 265 "../../src/intel-parse.yy"
                     { (yyval.reg) = AsmRegister::FS; }
#line 2053 "../../src/intel-parse.cc"
    break;

  case 46: /* reg: T_GS  */
#line 266 "../../src/intel-parse.yy"
                     { (yyval.reg) = AsmRegister::GS; }
#line 2059 "../../src/intel-parse.cc"
    break;

  case 47: /* reg: T_AL  */
#line 267 "../../src/intel-parse.yy"
                     { (yyval.reg) = AsmRegister::AL; }
#line 2065 "../../src/intel-parse.cc"
    break;

  case 48: /* reg: T_CL  */
#line 268 "../../src/intel-parse.yy"
                     { (yyval.reg) = AsmRegister::CL; }
#line 2071 "../../src/intel-parse.cc"
    break;

  case 49: /* reg: T_DL  */
#line 269 "../../src/intel-parse.yy"
                     { (yyval.reg) = AsmRegister::DL; }
#line 2077 "../../src/intel-parse.cc"
    break;

  case 50: /* reg: T_BL  */
#line 270 "../../src/intel-parse.yy"
                     { (yyval.reg) = AsmRegister::BL; }
#line 2083 "../../src/intel-parse.cc"
    break;

  case 51: /* reg: T_AH  */
#line 271 "../../src/intel-parse.yy"
                     { (yyval.reg) = AsmRegister::AH; }
#line 2089 "../../src/intel-parse.cc"
    break;

  case 52: /* reg: T_CH  */
#line 272 "../../src/intel-parse.yy"
                     { (yyval.reg) = AsmRegister::CH; }
#line 2095 "../../src/intel-parse.cc"
    break;

  case 53: /* reg: T_DH  */
#line 273 "../../src/intel-parse.yy"
                     { (yyval.reg) = AsmRegister::DH; }
#line 2101 "../../src/intel-parse.cc"
    break;

  case 54: /* reg: T_BH  */
#line 274 "../../src/intel-parse.yy"
                     { (yyval.reg) = AsmRegister::BH; }
#line 2107 "../../src/intel-parse.cc"
    break;

  case 55: /* reg: T_AX  */
#line 275 "../../src/intel-parse.yy"
                     { (yyval.reg) = AsmRegister::AX; }
#line 2113 "../../src/intel-parse.cc"
    break;

  case 56: /* reg: T_CX  */
#line 276 "../../src/intel-parse.yy"
                     { (yyval.reg) = AsmRegister::CX; }
#line 2119 "../../src/intel-parse.cc"
    break;

  case 57: /* reg: T_DX  */
#line 277 "../../src/intel-parse.yy"
                     { (yyval.reg) = AsmRegister::DX; }
#line 2125 "../../src/intel-parse.cc"
    break;

  case 58: /* reg: T_BX  */
#line 278 "../../src/intel-parse.yy"
                     { (yyval.reg) = AsmRegister::BX; }
#line 2131 "../../src/intel-parse.cc"
    break;

  case 59: /* reg: T_SP  */
#line 279 "../../src/intel-parse.yy"
                     { (yyval.reg) = AsmRegister::SP; }
#line 2137 "../../src/intel-parse.cc"
    break;

  case 60: /* reg: T_BP  */
#line 280 "../../src/intel-parse.yy"
                     { (yyval.reg) = AsmRegister::BP; }
#line 2143 "../../src/intel-parse.cc"
    break;

  case 61: /* reg: T_SI  */
#line 281 "../../src/intel-parse.yy"
                     { (yyval.reg) = AsmRegister::SI; }
#line 2149 "../../src/intel-parse.cc"
    break;

  case 62: /* reg: T_DI  */
#line 282 "../../src/intel-parse.yy"
                     { (yyval.reg) = AsmRegister::DI; }
#line 2155 "../../src/intel-parse.cc"
    break;

  case 63: /* reg: T_EAX  */
#line 283 "../../src/intel-parse.yy"
                      { (yyval.reg) = AsmRegister::EAX; }
#line 2161 "../../src/intel-parse.cc"
    break;

  case 64: /* reg: T_ECX  */
#line 284 "../../src/intel-parse.yy"
                      { (yyval.reg) = AsmRegister::ECX; }
#line 2167 "../../src/intel-parse.cc"
    break;

  case 65: /* reg: T_EDX  */
#line 285 "../../src/intel-parse.yy"
                      { (yyval.reg) = AsmRegister::EDX; }
#line 2173 "../../src/intel-parse.cc"
    break;

  case 66: /* reg: T_EBX  */
#line 286 "../../src/intel-parse.yy"
                      { (yyval.reg) = AsmRegister::EBX; }
#line 2179 "../../src/intel-parse.cc"
    break;

  case 67: /* reg: T_ESP  */
#line 287 "../../src/intel-parse.yy"
                      { (yyval.reg) = AsmRegister::ESP; }
#line 2185 "../../src/intel-parse.cc"
    break;

  case 68: /* reg: T_EBP  */
#line 288 "../../src/intel-parse.yy"
                      { (yyval.reg) = AsmRegister::EBP; }
#line 2191 "../../src/intel-parse.cc"
    break;

  case 69: /* reg: T_ESI  */
#line 289 "../../src/intel-parse.yy"
                      { (yyval.reg) = AsmRegister::ESI; }
#line 2197 "../../src/intel-parse.cc"
    break;

  case 70: /* reg: T_EDI  */
#line 290 "../../src/intel-parse.yy"
                      { (yyval.reg) = AsmRegister::EDI; }
#line 2203 "../../src/intel-parse.cc"
    break;

  case 71: /* size_specifier: "byte"  */
#line 293 "../../src/intel-parse.yy"
                       { (yyval.number) = 1; }
#line 2209 "../../src/intel-parse.cc"
    break;

  case 72: /* size_specifier: "word"  */
#line 294 "../../src/intel-parse.yy"
                       { (yyval.number) = 2; }
#line 2215 "../../src/intel-parse.cc"
    break;

  case 73: /* size_specifier: "dword"  */
#line 295 "../../src/intel-parse.yy"
                        { (yyval.number) = 4; }
#line 2221 "../../src/intel-parse.cc"
    break;

  case 76: /* label: "identifier" ':'  */
#line 302 "../../src/intel-parse.yy"
                            { (yyval.label) = new AsmIdentifier (*(yyvsp[-1].string)); delete (yyvsp[-1].string); }
#line 2227 "../../src/intel-parse.cc"
    break;

  case 77: /* label: "identifier"  */
#line 304 "../../src/intel-parse.yy"
                {
		  warning ("label alone on a line without a colon");
		  (yyval.label) = new AsmIdentifier (*(yyvsp[0].string));
		  delete (yyvsp[0].string);
		}
#line 2237 "../../src/intel-parse.cc"
    break;

  case 78: /* addr: "identifier"  */
#line 311 "../../src/intel-parse.yy"
                        { (yyval.addr) = new AsmIdentifier (*(yyvsp[0].string)); delete (yyvsp[0].string); }
#line 2243 "../../src/intel-parse.cc"
    break;

  case 79: /* addr: immediate  */
#line 312 "../../src/intel-parse.yy"
                          { (yyval.addr) = (yyvsp[0].imm); }
#line 2249 "../../src/intel-parse.cc"
    break;

  case 80: /* define_size: "directive"  */
#line 315 "../../src/intel-parse.yy"
                     { (yyval.number) = 1; }
#line 2255 "../../src/intel-parse.cc"
    break;

  case 81: /* define_size: T_DW  */
#line 316 "../../src/intel-parse.yy"
                     { (yyval.number) = 2; }
#line 2261 "../../src/intel-parse.cc"
    break;

  case 82: /* define_size: T_DD  */
#line 317 "../../src/intel-parse.yy"
                     { (yyval.number) = 4; }
#line 2267 "../../src/intel-parse.cc"
    break;

  case 83: /* define_size: T_DQ  */
#line 318 "../../src/intel-parse.yy"
                     { (yyval.number) = 8; }
#line 2273 "../../src/intel-parse.cc"
    break;


#line 2277 "../../src/intel-parse.cc"

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

