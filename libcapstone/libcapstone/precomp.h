/* Capstone Disassembler Engine */
/* By Nguyen Anh Quynh <aquynh@gmail.com>, 2013> */

#ifndef _CS_PRECOMP
#define _CS_PRECOMP
#ifdef _MSC_VER
#pragma once
#pragma warning(disable:4100)
#endif

/* General CRT Headers */
#include <ctype.h>
#include <inttypes.h>
#include <stddef.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#ifdef _MSC_VER
#include <intrin.h>
#endif

/* Public Capstone Header */
#include <capstone.h>

/* Internal LLVM Headers */
#include "MCInst.h"
#include "MCInstrDesc.h"
#include "MCRegisterInfo.h"
#include "MCFixedLenDisassembler.h"
#include "MCDisassembler.h"
#include "MathExtras.h"
#include "SubtargetFeature.h"

/* Internal Helper Library Headers */
#include "SStream.h"
#include "utils.h"
#include "LEB128.h"

/* Private Capstone Header */
#include "cs_priv.h"

/* Private X86 Capstone Headers */
#ifdef CAPSTONE_HAS_X86
#include "arch\x86\X86Mapping.h"
#include "arch\x86\X86Disassembler.h"
#define INSTRUCTION_SPECIFIER_FIELDS \
    uint16_t operands;
#define INSTRUCTION_IDS               \
    uint16_t instructionIDs;
#include "arch\x86\X86DisassemblerDecoderCommon.h"
#undef INSTRUCTION_SPECIFIER_FIELDS
#undef INSTRUCTION_IDS
#include "arch\x86\X86DisassemblerDecoder.h"
#include "arch\x86\X86InstPrinter.h"
#endif

/* Private PPC Capstone Headers */
#ifdef CAPSTONE_HAS_POWERPC
#include "arch\powerpc\PPCInstPrinter.h"
#include "arch\powerpc\PPCPredicates.h"
#include "arch\powerpc\PPCDisassembler.h"
#include "arch\powerpc\PPCMapping.h"
#endif

/* Private MIPS Capstone Headers */
#ifdef CAPSTONE_HAS_MIPS
#include "arch\mips\MipsDisassembler.h"
#include "arch\mips\MipsInstPrinter.h"
#include "arch\mips\MipsMapping.h"
#endif

/* Private ARM Capstone Headers */
#ifdef CAPSTONE_HAS_ARM
#include "arch\arm\ARMAddressingModes.h"
#include "arch\arm\ARMBaseInfo.h"
#include "arch\arm\ARMDisassembler.h"
#include "arch\arm\ARMInstPrinter.h"
#include "arch\arm\ARMMapping.h"
#endif

/* Private AARCH64 Capstone Headers */
#ifdef CAPSTONE_HAS_AARCH64
#include "arch\aarch64\AArch64BaseInfo.h"
#include "arch\aarch64\AArch64InstPrinter.h"
#include "arch\aarch64\AArch64BaseInfo.h"
#include "arch\aarch64\AArch64Mapping.h"
#include "arch\aarch64\AArch64Disassembler.h"
#endif

#endif
