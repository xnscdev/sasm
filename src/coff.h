/*************************************************************************
 * coff.h -- This file is part of sasm.                                  *
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

#ifndef _COFF_H
#define _COFF_H

#ifndef _COFF_DISABLE_DEFINES

#define COFF_MAGIC0 0x4c
#define COFF_MAGIC1 0x01

#define E_SYMNMLEN 8

#define IMAGE_SCN_TYPE_REG               0x00000000
#define IMAGE_SCN_TYPE_DSECT             0x00000001
#define IMAGE_SCN_TYPE_NOLOAD            0x00000002
#define IMAGE_SCN_TYPE_GROUP             0x00000004
#define IMAGE_SCN_TYPE_NO_PAD            0x00000008
#define IMAGE_SCN_TYPE_COPY              0x00000010
#define IMAGE_SCN_CNT_CODE               0x00000020
#define IMAGE_SCN_CNT_INITIALIZED_DATA   0x00000040
#define IMAGE_SCN_CNT_UNINITIALIZED_DATA 0x00000080
#define IMAGE_SCN_LNK_OTHER              0x00000100
#define IMAGE_SCN_LNK_INFO               0x00000200
#define IMAGE_SCN_TYPE_OVER              0x00000400
#define IMAGE_SCN_LNK_REMOVE             0x00000800
#define IMAGE_SCN_LNK_COMDAT             0x00001000
#define IMAGE_SCN_MEM_FARDATA            0x00008000
#define IMAGE_SCN_MEM_PURGEABLE          0x00020000
#define IMAGE_SCN_MEM_16BIT              0x00020000
#define IMAGE_SCN_MEM_LOCKED             0x00040000
#define IMAGE_SCN_MEM_PRELOAD            0x00080000
#define IMAGE_SCN_ALIGN_1BYTES           0x00100000
#define IMAGE_SCN_ALIGN_2BYTES           0x00200000
#define IMAGE_SCN_ALIGN_4BYTES           0x00300000
#define IMAGE_SCN_ALIGN_8BYTES           0x00400000
#define IMAGE_SCN_ALIGN_16BYTES          0x00500000
#define IMAGE_SCN_ALIGN_32BYTES          0x00600000
#define IMAGE_SCN_ALIGN_64BYTES          0x00700000
#define IMAGE_SCN_ALIGN_128BYTES         0x00800000
#define IMAGE_SCN_ALIGN_256BYTES         0x00900000
#define IMAGE_SCN_ALIGN_512BYTES         0x00a00000
#define IMAGE_SCN_ALIGN_1024BYTES        0x00b00000
#define IMAGE_SCN_ALIGN_2048BYTES        0x00c00000
#define IMAGE_SCN_ALIGN_4096BYTES        0x00d00000
#define IMAGE_SCN_ALIGN_8192BYTES        0x00e00000
#define IMAGE_SCN_LNK_NRELOC_OVFL        0x01000000
#define IMAGE_SCN_MEM_DISCARDABLE        0x02000000
#define IMAGE_SCN_MEM_NOT_CACHED         0x04000000
#define IMAGE_SCN_MEM_NOT_PAGED          0x08000000
#define IMAGE_SCN_MEM_SHARED             0x10000000
#define IMAGE_SCN_MEM_EXECUTE            0x20000000
#define IMAGE_SCN_MEM_READ               0x40000000
#define IMAGE_SCN_MEM_WRITE              0x80000000

#define IMAGE_REL_I386_ABSOLUTE 0x00
#define IMAGE_REL_I386_DIR16    0x01
#define IMAGE_REL_I386_REL16    0x02
#define IMAGE_REL_I386_DIR32    0x06
#define IMAGE_REL_I386_DIR32NB  0x07
#define IMAGE_REL_I386_SEG12    0x09
#define IMAGE_REL_I386_SECTION  0x0a
#define IMAGE_REL_I386_SECREL   0x0b
#define IMAGE_REL_I386_REL32    0x14

#define N_UNDEF 0
#define N_ABS   -1
#define N_DEBUG -2

#define N_BTSHIFT 4

#define T_NULL   0x0
#define T_VOID   0x1
#define T_CHAR   0x2
#define T_SHORT  0x3
#define T_INT    0x4
#define T_LONG   0x5
#define T_FLOAT  0x6
#define T_DOUBLE 0x7
#define T_STRUCT 0x8
#define T_UNION  0x9
#define T_ENUM   0xa
#define T_MOE    0xb
#define T_UCHAR  0xc
#define T_USHORT 0xd
#define T_UINT   0xe
#define T_ULONG  0xf
#define T_LNGDBL 0x10

#define DT_NON   0
#define DT_PTR   1
#define DT_FCN   2
#define DT_ARY   3

#define C_NULL    0
#define C_AUTO    1
#define C_EXT     2
#define C_STAT    3
#define C_REG     4
#define C_EXTDEF  5
#define C_LABEL   6
#define C_ULABEL  7
#define C_MOS     8
#define C_ARG     9
#define C_STRTAG  10
#define C_MOU     11
#define C_UNTAG   12
#define C_TPDEF   13
#define C_USTATIC 14
#define C_ENTAG   15
#define C_MOE     16
#define C_REGPARM 17
#define C_FIELD   18
#define C_AUTOARG 19
#define C_LASTENT 20
#define C_BLOCK   100
#define C_FCN     101
#define C_EOS     102
#define C_FILE    103
#define C_LINE    104
#define C_ALIAS   105
#define C_HIDDEN  106
#define C_EFCN    255

#endif

typedef union
{
  unsigned char e_name[8];
  struct
  {
    uint32_t e_zeroes;
    uint32_t e_offset;
  } e_long;
} coff_str;

typedef struct
{
  unsigned char f_magic[2];
  uint16_t f_nscns;
  int32_t f_timdat;
  uint32_t f_symptr;
  uint32_t f_nsyms;
  unsigned short f_opthdr;
  unsigned short f_flags;
} coff_filehdr;

typedef struct
{
  coff_str s_name;
  uint32_t s_paddr;
  uint32_t s_vaddr;
  uint32_t s_size;
  uint32_t s_scnptr;
  uint32_t s_relptr;
  uint32_t s_lnnoptr;
  uint16_t s_nreloc;
  uint16_t s_nlnno;
  uint32_t s_flags;
} coff_scnhdr;

typedef struct
{
  uint32_t r_vaddr;
  uint32_t r_symndx;
  uint16_t r_type;
} coff_reloc;

typedef struct
{
  union
  {
    uint32_t l_symndx;
    uint32_t l_paddr;
  } l_addr;
  uint16_t l_lnno;
} coff_linenum;

typedef struct
{
  coff_str n_name;
  uint32_t n_value;
  int16_t n_scnum;
  uint16_t n_type;
  unsigned char n_sclass;
  unsigned char n_numaux;
} coff_syms;

#endif
