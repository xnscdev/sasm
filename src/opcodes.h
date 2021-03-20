/*************************************************************************
 * opcodes.h -- This file is part of sasm.                               *
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

#ifndef _OPCODES_H
#define _OPCODES_H

#define ASM_OPCODE_ADD_RM_R8       0x00
#define ASM_OPCODE_ADD_RM_RX       0x01
#define ASM_OPCODE_ADD_R_RM8       0x02
#define ASM_OPCODE_ADD_R_RMX       0x03
#define ASM_OPCODE_ADD_AL_IMM8     0x04
#define ASM_OPCODE_ADD_AX_IMMX     0x05
#define ASM_OPCODE_PUSH_ES         0x06
#define ASM_OPCODE_POP_ES          0x07
#define ASM_OPCODE_OR_RM_R8        0x08
#define ASM_OPCODE_OR_RM_RX        0x09
#define ASM_OPCODE_OR_R_RM8        0x0a
#define ASM_OPCODE_OR_R_RMX        0x0b
#define ASM_OPCODE_OR_AL_IMM8      0x0c
#define ASM_OPCODE_OR_AX_IMMX      0x0d
#define ASM_OPCODE_PUSH_CS         0x0e
#define ASM_OPCODE_ADC_RM_R8       0x10
#define ASM_OPCODE_ADC_RM_RX       0x11
#define ASM_OPCODE_ADC_R_RM8       0x12
#define ASM_OPCODE_ADC_R_RMX       0x13
#define ASM_OPCODE_ADC_AL_IMM8     0x14
#define ASM_OPCODE_ADC_AX_IMMX     0x15
#define ASM_OPCODE_PUSH_SS         0x16
#define ASM_OPCODE_POP_SS          0x17
#define ASM_OPCODE_SBB_RM_R8       0x18
#define ASM_OPCODE_SBB_RM_RX       0x19
#define ASM_OPCODE_SBB_R_RM8       0x1a
#define ASM_OPCODE_SBB_R_RMX       0x1b
#define ASM_OPCODE_SBB_AL_IMM8     0x1c
#define ASM_OPCODE_SBB_AX_IMMX     0x1d
#define ASM_OPCODE_PUSH_DS         0x1e
#define ASM_OPCODE_POP_DS          0x1f
#define ASM_OPCODE_AND_RM_R8       0x20
#define ASM_OPCODE_AND_RM_RX       0x21
#define ASM_OPCODE_AND_R_RM8       0x22
#define ASM_OPCODE_AND_R_RMX       0x23
#define ASM_OPCODE_AND_AL_IMM8     0x24
#define ASM_OPCODE_AND_AX_IMMX     0x25
#define ASM_OPCODE_ES_SGMT_OVR     0x26
#define ASM_OPCODE_DAA             0x27
#define ASM_OPCODE_SUB_RM_R8       0x28
#define ASM_OPCODE_SUB_RM_RX       0x29
#define ASM_OPCODE_SUB_R_RM8       0x2a
#define ASM_OPCODE_SUB_R_RMX       0x2b
#define ASM_OPCODE_SUB_AL_IMM8     0x2c
#define ASM_OPCODE_SUB_AX_IMMX     0x2d
#define ASM_OPCODE_CS_SGMT_OVR     0x2e
#define ASM_OPCODE_DAS             0x2f
#define ASM_OPCODE_XOR_RM_R8       0x30
#define ASM_OPCODE_XOR_RM_RX       0x31
#define ASM_OPCODE_XOR_R_RM8       0x32
#define ASM_OPCODE_XOR_R_RMX       0x33
#define ASM_OPCODE_XOR_AL_IMM8     0x34
#define ASM_OPCODE_XOR_AX_IMMX     0x35
#define ASM_OPCODE_SS_SGMT_OVR     0x36
#define ASM_OPCODE_AAA             0x37
#define ASM_OPCODE_CMP_RM_R8       0x38
#define ASM_OPCODE_CMP_RM_RX       0x39
#define ASM_OPCODE_CMP_R_RM8       0x3a
#define ASM_OPCODE_CMP_R_RMX       0x3b
#define ASM_OPCODE_CMP_AL_IMM8     0x3c
#define ASM_OPCODE_CMP_AX_IMMX     0x3d
#define ASM_OPCODE_DS_SGMT_OVR     0x3e
#define ASM_OPCODE_AAS             0x3f

#define ASM_OPCODE_INC_BASE        0x40
#define ASM_OPCODE_DEC_BASE        0x48
#define ASM_OPCODE_PUSH_BASE       0x50
#define ASM_OPCODE_POP_BASE        0x58

#define ASM_OPCODE_PUSHA           0x60
#define ASM_OPCODE_POPA            0x61
#define ASM_OPCODE_BOUND           0x62
#define ASM_OPCODE_ARPL            0x63
#define ASM_OPCODE_FS_SGMT_OVR     0x64
#define ASM_OPCODE_GS_SGMT_OVR     0x65
#define ASM_OPCODE_OPSIZE_OVR      0x66
#define ASM_OPCODE_ADDRSIZE_OVR    0x67
#define ASM_OPCODE_PUSH_IMMX       0x68
#define ASM_OPCODE_IMUL_R_RM_IMMX  0x69
#define ASM_OPCODE_PUSH_IMM8       0x6a
#define ASM_OPCODE_IMUL_R_RM_IMM8  0x6b
#define ASM_OPCODE_INSB            0x6c
#define ASM_OPCODE_OUTSB           0x6e
#define ASM_OPCODE_JO              0x70
#define ASM_OPCODE_JNO             0x71
#define ASM_OPCODE_JC              0x72
#define ASM_OPCODE_JNC             0x73
#define ASM_OPCODE_JZ              0x74
#define ASM_OPCODE_JNZ             0x75
#define ASM_OPCODE_JNA             0x76
#define ASM_OPCODE_JA              0x77
#define ASM_OPCODE_JS              0x78
#define ASM_OPCODE_JNS             0x79
#define ASM_OPCODE_JP              0x7a
#define ASM_OPCODE_JNP             0x7b
#define ASM_OPCODE_JL              0x7c
#define ASM_OPCODE_JNL             0x7d
#define ASM_OPCODE_JNG             0x7e
#define ASM_OPCODE_JG              0x7f

#define ASM_OPCODE_ARITH_RM_IMM8   0x80
#define ASM_OPCODE_ARITH_RM_IMMX   0x81
#define ASM_OPCODE_ARITH_RMX_IMM8  0x83

#define ASM_OPCODE_TEST_RM_R8      0x84
#define ASM_OPCODE_TEST_RM_RX      0x85
#define ASM_OPCODE_XCHG_R_RM8      0x86
#define ASM_OPCODE_XCHG_R_RMX      0x87
#define ASM_OPCODE_MOV_RM_R8       0x88
#define ASM_OPCODE_MOV_RM_RX       0x89
#define ASM_OPCODE_MOV_R_RM8       0x8a
#define ASM_OPCODE_MOV_R_RMX       0x8b
#define ASM_OPCODE_MOV_RM16_SREG   0x8c
#define ASM_OPCODE_LEA             0x8d
#define ASM_OPCODE_MOV_SREG_RM16   0x8e
#define ASM_OPCODE_POP_RMX         0x8f
#define ASM_OPCODE_NOP             0x90

/* XCHG EAX, EAX is NOP */
#define ASM_OPCODE_XCHG_BASE       0x90

#define ASM_OPCODE_CWDE            0x98
#define ASM_OPCODE_CDQ             0x99
#define ASM_OPCODE_CALLF_PX        0x9a
#define ASM_OPCODE_WAIT            0x9b
#define ASM_OPCODE_PUSHF           0x9c
#define ASM_OPCODE_POPF            0x9d
#define ASM_OPCODE_SAHF            0x9e
#define ASM_OPCODE_LAHF            0x9f
#define ASM_OPCODE_MOV_AL_MOFFS8   0xa0
#define ASM_OPCODE_MOV_AX_MOFFSX   0xa1
#define ASM_OPCODE_MOV_MOFFS8_AL   0xa2
#define ASM_OPCODE_MOV_MOFFSX_AX   0xa3
#define ASM_OPCODE_MOVSB           0xa4
#define ASM_OPCODE_CMPSB           0xa6
#define ASM_OPCODE_TEST_AL_IMM8    0xa8
#define ASM_OPCODE_TEST_AX_IMMX    0xa9
#define ASM_OPCODE_STOSB           0xaa
#define ASM_OPCODE_LODSB           0xac
#define ASM_OPCODE_SCASB           0xae

#define ASM_OPCODE_MOV_R_IMM8_BASE 0xb0
#define ASM_OPCODE_MOV_R_IMMX_BASE 0xb8

#define ASM_OPCODE_ROTSHF_RM8_IMM  0xc0
#define ASM_OPCODE_ROTSHF_RMX_IMM  0xc1
#define ASM_OPCODE_RETN_IMM16      0xc2
#define ASM_OPCODE_RETN            0xc3
#define ASM_OPCODE_LES_R_MX        0xc4
#define ASM_OPCODE_LDS_R_MX        0xc5
#define ASM_OPCODE_MOV_RM_IMM8     0xc6
#define ASM_OPCODE_MOV_RM_IMMX     0xc7
#define ASM_OPCODE_ENTER           0xc8
#define ASM_OPCODE_LEAVE           0xc9
#define ASM_OPCODE_RETF_IMM16      0xca
#define ASM_OPCODE_RETF            0xcb
#define ASM_OPCODE_INT3            0xcc
#define ASM_OPCODE_INT             0xcd
#define ASM_OPCODE_INTO            0xce
#define ASM_OPCODE_IRET            0xcf
#define ASM_OPCODE_ROTSHF_RM8_1    0xd0
#define ASM_OPCODE_ROTSHF_RMX_1    0xd1
#define ASM_OPCODE_ROTSHF_RM8_CL   0xd2
#define ASM_OPCODE_ROTSHF_RMX_CL   0xd3
#define ASM_OPCODE_AAM             0xd4
#define ASM_OPCODE_AAD             0xd5
#define ASM_OPCODE_SALC            0xd6
#define ASM_OPCODE_XLAT            0xd7

/* TODO x87 FPU opcodes */

#define ASM_OPCODE_LOOPNZ          0xe0
#define ASM_OPCODE_LOOPZ           0xe1
#define ASM_OPCODE_LOOP            0xe2
#define ASM_OPCODE_JCXZ            0xe3
#define ASM_OPCODE_IN_AL_IMM8      0xe4
#define ASM_OPCODE_IN_AX_IMM8      0xe5
#define ASM_OPCODE_OUT_IMM8_AL     0xe6
#define ASM_OPCODE_OUT_IMM8_AX     0xe7
#define ASM_OPCODE_CALL_RELX       0xe8
#define ASM_OPCODE_JMP_RELX        0xe9
#define ASM_OPCODE_JMPF_PX         0xea
#define ASM_OPCODE_JMP_REL8        0xeb
#define ASM_OPCODE_IN_AL_DX        0xec
#define ASM_OPCODE_IN_AX_DX        0xed
#define ASM_OPCODE_OUT_DX_AL       0xee
#define ASM_OPCODE_OUT_DX_AX       0xef
#define ASM_OPCODE_LOCK_PFX        0xf0
#define ASM_OPCODE_INT1            0xf1
#define ASM_OPCODE_REPNZ           0xf2
#define ASM_OPCODE_REPZ            0xf3
#define ASM_OPCODE_HLT             0xf4
#define ASM_OPCODE_CMC             0xf5

#define ASM_OPCODE_TEST_RM_IMM8    0xf6
#define ASM_OPCODE_NOT_RM8         0xf6
#define ASM_OPCODE_NEG_RM8         0xf6
#define ASM_OPCODE_MUL_AX_AL       0xf6
#define ASM_OPCODE_IMUL_AX_AL      0xf6
#define ASM_OPCODE_DIV_AL_AH       0xf6
#define ASM_OPCODE_IDIV_AL_AH      0xf6
#define ASM_OPCODE_TEST_RM_IMMX    0xf7
#define ASM_OPCODE_NOT_RMX         0xf7
#define ASM_OPCODE_NEG_RMX         0xf7
#define ASM_OPCODE_MUL_DX_AX       0xf7
#define ASM_OPCODE_IMUL_DX_AX      0xf7
#define ASM_OPCODE_DIV_DX_AX       0xf7
#define ASM_OPCODE_IDIV_DX_AX      0xf7

#define ASM_OPCODE_CLC             0xf8
#define ASM_OPCODE_STC             0xf9
#define ASM_OPCODE_CLI             0xfa
#define ASM_OPCODE_STI             0xfb
#define ASM_OPCODE_CLD             0xfc
#define ASM_OPCODE_STD             0xfd
#define ASM_OPCODE_INCDEC_RM8      0xfe

#define ASM_OPCODE_INCDEC_RMX      0xff
#define ASM_OPCODE_CALL_RMX        0xff
#define ASM_OPCODE_JMP_RMX         0xff
#define ASM_OPCODE_PUSH_RMX        0xff

#define ASM_OPCODE_2BYTE_INST      0x0f

#endif
