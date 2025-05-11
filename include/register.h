#ifndef REGISTER_H
#define REGISTER_H

#include "types.h"

typedef union
{
    byte b;
} reg8_t;

#define R0_B    0
#define R1_B    1
#define R2_B    2
#define R3_B    3
#define R4_B    4
#define R5_B    5
#define R6_B    6
#define R7_B    7
#define R8_B    8
#define R9_B    9
#define R10_B   10
#define R11_B   11
#define R12_B   12
#define R13_B   13
#define R14_B   14
#define R15_B   15

typedef union
{
    word w;
    byte b;
} reg16_t;

#define R0_W    0
#define R1_W    1
#define R2_W    2
#define R3_W    3
#define R4_W    4
#define R5_W    5
#define R6_W    6
#define R7_W    7
#define R8_W    8
#define R9_W    9
#define R10_W   10
#define R11_W   11
#define R12_W   12
#define R13_W   13
#define R14_W   14
#define R15_W   15

typedef union
{
    dword d;
    word w;
    byte b;
} reg32_t;

#define R0_D    0
#define R1_D    1
#define R2_D    2
#define R3_D    3
#define R4_D    4
#define R5_D    5
#define R6_D    6
#define R7_D    7
#define R8_D    8
#define R9_D    9
#define R10_D   10
#define R11_D   11
#define R12_D   12
#define R13_D   13
#define R14_D   14
#define R15_D   15

typedef union
{
    qword q;
    dword d;
    word w;
    byte b;
} reg64_t;

#define R0      0
#define R1      1
#define R2      2
#define R3      3
#define R4      4
#define R5      5
#define R6      6
#define R7      7
#define R8      8
#define R9      9
#define R10     10
#define R11     11
#define R12     12
#define R13     13
#define R14     14
#define R15     15

#endif // REGISTER_H