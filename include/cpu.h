#ifndef CPU_H
#define CPU_H

#include "register.h"

#define NB_REGISTERS 16
#define MEMORY_SIZE (1024 / sizeof(qword)) // 1 KB

typedef struct
{
    reg64_t registers[NB_REGISTERS];
    qword pc;               // Program counter
    qword ir;               // Instruction register
    struct flags
    {
        unsigned cf : 1;    // Carry flag
        unsigned zf : 1;    // Zero flag
        unsigned sf : 1;    // Sign flag
        unsigned of : 1;    // Overflow flag
    } flags;
    qword memory[MEMORY_SIZE];
} cpu_t;

#endif // CPU_H