#ifndef ALU_H
#define ALU_H

#include "cpu.h"

int alu_8b(cpu_t *cpu);
int alu_16b(cpu_t *cpu);
int alu_32b(cpu_t *cpu);
int alu_64b(cpu_t *cpu);

#endif // ALU_H