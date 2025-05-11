#include "types.h"
#include "register.h"
#include "cpu.h"
#include "instruction_set.h"
#include "instructions.h"

int alu_64b(cpu_t *cpu)
{
    switch (cpu->ir)
    {
        case AND64:
        {
            reg64_t *reg1 = (reg64_t *)&cpu->registers[cpu->memory[cpu->pc++]];
            reg64_t *reg2 = (reg64_t *)&cpu->registers[cpu->memory[cpu->pc++]];
            cpu_and64(&cpu->flags, reg1, reg2);
            break;
        }
        case OR64:
        {
            reg64_t *reg1 = (reg64_t *)&cpu->registers[cpu->memory[cpu->pc++]];
            reg64_t *reg2 = (reg64_t *)&cpu->registers[cpu->memory[cpu->pc++]];
            cpu_or64(&cpu->flags, reg1, reg2);
            break;
        }
        case XOR64:
        {
            reg64_t *reg1 = (reg64_t *)&cpu->registers[cpu->memory[cpu->pc++]];
            reg64_t *reg2 = (reg64_t *)&cpu->registers[cpu->memory[cpu->pc++]];
            cpu_xor64(&cpu->flags, reg1, reg2);
            break;
        }
        case NOT64:
        {
            reg64_t *reg = (reg64_t *)&cpu->registers[cpu->memory[cpu->pc++]];
            cpu_not64(&cpu->flags, reg);
            break;
        }
        case NAND64:
        {
            reg64_t *reg1 = (reg64_t *)&cpu->registers[cpu->memory[cpu->pc++]];
            reg64_t *reg2 = (reg64_t *)&cpu->registers[cpu->memory[cpu->pc++]];
            cpu_nand64(&cpu->flags, reg1, reg2);
            break;
        }
        case NOR64:
        {
            reg64_t *reg1 = (reg64_t *)&cpu->registers[cpu->memory[cpu->pc++]];
            reg64_t *reg2 = (reg64_t *)&cpu->registers[cpu->memory[cpu->pc++]];
            cpu_nor64(&cpu->flags, reg1, reg2);
            break;
        }
        case XNOR64:
        {
            reg64_t *reg1 = (reg64_t *)&cpu->registers[cpu->memory[cpu->pc++]];
            reg64_t *reg2 = (reg64_t *)&cpu->registers[cpu->memory[cpu->pc++]];
            cpu_xnor64(&cpu->flags, reg1, reg2);
            break;
        }
        case SHL64:
        {
            reg64_t *reg = (reg64_t *)&cpu->registers[cpu->memory[cpu->pc++]];
            cpu_shl64(&cpu->flags, reg);
            break;
        }
        case SHR64:
        {
            reg64_t *reg = (reg64_t *)&cpu->registers[cpu->memory[cpu->pc++]];
            cpu_shr64(&cpu->flags, reg);
            break;
        }

        case ADD64:
        {
            reg64_t *reg1 = (reg64_t *)&cpu->registers[cpu->memory[cpu->pc++]];
            reg64_t *reg2 = (reg64_t *)&cpu->registers[cpu->memory[cpu->pc++]];
            cpu_add64(&cpu->flags, reg1, reg2);
            break;
        }
        case SADD64:
        {
            reg64_t *reg1 = (reg64_t *)&cpu->registers[cpu->memory[cpu->pc++]];
            reg64_t *reg2 = (reg64_t *)&cpu->registers[cpu->memory[cpu->pc++]];
            cpu_sadd64(&cpu->flags, reg1, reg2);
            break;
        }
        case SUB64:
        {
            reg64_t *reg1 = (reg64_t *)&cpu->registers[cpu->memory[cpu->pc++]];
            reg64_t *reg2 = (reg64_t *)&cpu->registers[cpu->memory[cpu->pc++]];
            cpu_sub64(&cpu->flags, reg1, reg2);
            break;
        }
        case SSUB64:
        {
            reg64_t *reg1 = (reg64_t *)&cpu->registers[cpu->memory[cpu->pc++]];
            reg64_t *reg2 = (reg64_t *)&cpu->registers[cpu->memory[cpu->pc++]];
            cpu_ssub64(&cpu->flags, reg1, reg2);
            break;
        }
        case MUL64:
        {
            reg64_t *reg1 = (reg64_t *)&cpu->registers[cpu->memory[cpu->pc++]];
            reg64_t *reg2 = (reg64_t *)&cpu->registers[cpu->memory[cpu->pc++]];
            cpu_mul64(&cpu->flags, reg1, reg2);
            break;
        }
        case SMUL64:
        {
            reg64_t *reg1 = (reg64_t *)&cpu->registers[cpu->memory[cpu->pc++]];
            reg64_t *reg2 = (reg64_t *)&cpu->registers[cpu->memory[cpu->pc++]];
            cpu_smul64(&cpu->flags, reg1, reg2);
            break;
        }
        case DIV64:
        {
            reg64_t *reg1 = (reg64_t *)&cpu->registers[cpu->memory[cpu->pc++]];
            reg64_t *reg2 = (reg64_t *)&cpu->registers[cpu->memory[cpu->pc++]];
            cpu_div64(&cpu->flags, reg1, reg2);
            break;
        }
        case SDIV64:
        {
            reg64_t *reg1 = (reg64_t *)&cpu->registers[cpu->memory[cpu->pc++]];
            reg64_t *reg2 = (reg64_t *)&cpu->registers[cpu->memory[cpu->pc++]];
            cpu_sdiv64(&cpu->flags, reg1, reg2);
            break;
        }
        case MOD64:
        {
            reg64_t *reg1 = (reg64_t *)&cpu->registers[cpu->memory[cpu->pc++]];
            reg64_t *reg2 = (reg64_t *)&cpu->registers[cpu->memory[cpu->pc++]];
            cpu_mod64(&cpu->flags, reg1, reg2);
            break;
        }
        case SMOD64:
        {
            reg64_t *reg1 = (reg64_t *)&cpu->registers[cpu->memory[cpu->pc++]];
            reg64_t *reg2 = (reg64_t *)&cpu->registers[cpu->memory[cpu->pc++]];
            cpu_smod64(&cpu->flags, reg1, reg2);
            break;
        }
        case INC64:
        {
            reg64_t *reg = (reg64_t *)&cpu->registers[cpu->memory[cpu->pc++]];
            cpu_inc64(&cpu->flags, reg);
            break;
        }
        case DEC64:
        {
            reg64_t *reg = (reg64_t *)&cpu->registers[cpu->memory[cpu->pc++]];
            cpu_dec64(&cpu->flags, reg);
            break;
        }

        case CMP64:
        {
            reg64_t *reg1 = (reg64_t *)&cpu->registers[cpu->memory[cpu->pc++]];
            reg64_t *reg2 = (reg64_t *)&cpu->registers[cpu->memory[cpu->pc++]];
            cpu_cmp64(&cpu->flags, reg1, reg2);
            break;
        }

        default:
            return -1;
    }

    return 0;
}
