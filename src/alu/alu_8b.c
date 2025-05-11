#include "types.h"
#include "register.h"
#include "cpu.h"
#include "instruction_set.h"
#include "instructions.h"

int alu_8b(cpu_t *cpu)
{
    switch (cpu->ir)
    {
        case AND8:
        {
            reg8_t *reg1 = (reg8_t *)&cpu->registers[cpu->memory[cpu->pc++]];
            reg8_t *reg2 = (reg8_t *)&cpu->registers[cpu->memory[cpu->pc++]];
            cpu_and8(&cpu->flags, reg1, reg2);
            break;
        }
        case OR8:
        {
            reg8_t *reg1 = (reg8_t *)&cpu->registers[cpu->memory[cpu->pc++]];
            reg8_t *reg2 = (reg8_t *)&cpu->registers[cpu->memory[cpu->pc++]];
            cpu_or8(&cpu->flags, reg1, reg2);
            break;
        }
        case XOR8:
        {
            reg8_t *reg1 = (reg8_t *)&cpu->registers[cpu->memory[cpu->pc++]];
            reg8_t *reg2 = (reg8_t *)&cpu->registers[cpu->memory[cpu->pc++]];
            cpu_xor8(&cpu->flags, reg1, reg2);
            break;
        }
        case NOT8:
        {
            reg8_t *reg = (reg8_t *)&cpu->registers[cpu->memory[cpu->pc++]];
            cpu_not8(&cpu->flags, reg);
            break;
        }
        case NAND8:
        {
            reg8_t *reg1 = (reg8_t *)&cpu->registers[cpu->memory[cpu->pc++]];
            reg8_t *reg2 = (reg8_t *)&cpu->registers[cpu->memory[cpu->pc++]];
            cpu_nand8(&cpu->flags, reg1, reg2);
            break;
        }
        case NOR8:
        {
            reg8_t *reg1 = (reg8_t *)&cpu->registers[cpu->memory[cpu->pc++]];
            reg8_t *reg2 = (reg8_t *)&cpu->registers[cpu->memory[cpu->pc++]];
            cpu_nor8(&cpu->flags, reg1, reg2);
            break;
        }
        case XNOR8:
        {
            reg8_t *reg1 = (reg8_t *)&cpu->registers[cpu->memory[cpu->pc++]];
            reg8_t *reg2 = (reg8_t *)&cpu->registers[cpu->memory[cpu->pc++]];
            cpu_xnor8(&cpu->flags, reg1, reg2);
            break;
        }
        case SHL8:
        {
            reg8_t *reg = (reg8_t *)&cpu->registers[cpu->memory[cpu->pc++]];
            cpu_shl8(&cpu->flags, reg);
            break;
        }
        case SHR8:
        {
            reg8_t *reg = (reg8_t *)&cpu->registers[cpu->memory[cpu->pc++]];
            cpu_shr8(&cpu->flags, reg);
            break;
        }

        case ADD8:
        {
            reg8_t *reg1 = (reg8_t *)&cpu->registers[cpu->memory[cpu->pc++]];
            reg8_t *reg2 = (reg8_t *)&cpu->registers[cpu->memory[cpu->pc++]];
            cpu_add8(&cpu->flags, reg1, reg2);
            break;
        }
        case SADD8:
        {
            reg8_t *reg1 = (reg8_t *)&cpu->registers[cpu->memory[cpu->pc++]];
            reg8_t *reg2 = (reg8_t *)&cpu->registers[cpu->memory[cpu->pc++]];
            cpu_sadd8(&cpu->flags, reg1, reg2);
            break;
        }
        case SUB8:
        {
            reg8_t *reg1 = (reg8_t *)&cpu->registers[cpu->memory[cpu->pc++]];
            reg8_t *reg2 = (reg8_t *)&cpu->registers[cpu->memory[cpu->pc++]];
            cpu_sub8(&cpu->flags, reg1, reg2);
            break;
        }
        case SSUB8:
        {
            reg8_t *reg1 = (reg8_t *)&cpu->registers[cpu->memory[cpu->pc++]];
            reg8_t *reg2 = (reg8_t *)&cpu->registers[cpu->memory[cpu->pc++]];
            cpu_ssub8(&cpu->flags, reg1, reg2);
            break;
        }
        case MUL8:
        {
            reg8_t *reg1 = (reg8_t *)&cpu->registers[cpu->memory[cpu->pc++]];
            reg8_t *reg2 = (reg8_t *)&cpu->registers[cpu->memory[cpu->pc++]];
            cpu_mul8(&cpu->flags, reg1, reg2);
            break;
        }
        case SMUL8:
        {
            reg8_t *reg1 = (reg8_t *)&cpu->registers[cpu->memory[cpu->pc++]];
            reg8_t *reg2 = (reg8_t *)&cpu->registers[cpu->memory[cpu->pc++]];
            cpu_smul8(&cpu->flags, reg1, reg2);
            break;
        }
        case DIV8:
        {
            reg8_t *reg1 = (reg8_t *)&cpu->registers[cpu->memory[cpu->pc++]];
            reg8_t *reg2 = (reg8_t *)&cpu->registers[cpu->memory[cpu->pc++]];
            cpu_div8(&cpu->flags, reg1, reg2);
            break;
        }
        case SDIV8:
        {
            reg8_t *reg1 = (reg8_t *)&cpu->registers[cpu->memory[cpu->pc++]];
            reg8_t *reg2 = (reg8_t *)&cpu->registers[cpu->memory[cpu->pc++]];
            cpu_sdiv8(&cpu->flags, reg1, reg2);
            break;
        }
        case MOD8:
        {
            reg8_t *reg1 = (reg8_t *)&cpu->registers[cpu->memory[cpu->pc++]];
            reg8_t *reg2 = (reg8_t *)&cpu->registers[cpu->memory[cpu->pc++]];
            cpu_mod8(&cpu->flags, reg1, reg2);
            break;
        }
        case SMOD8:
        {
            reg8_t *reg1 = (reg8_t *)&cpu->registers[cpu->memory[cpu->pc++]];
            reg8_t *reg2 = (reg8_t *)&cpu->registers[cpu->memory[cpu->pc++]];
            cpu_smod8(&cpu->flags, reg1, reg2);
            break;
        }
        case INC8:
        {
            reg8_t *reg = (reg8_t *)&cpu->registers[cpu->memory[cpu->pc++]];
            cpu_inc8(&cpu->flags, reg);
            break;
        }
        case DEC8:
        {
            reg8_t *reg = (reg8_t *)&cpu->registers[cpu->memory[cpu->pc++]];
            cpu_dec8(&cpu->flags, reg);
            break;
        }

        case CMP8:
        {
            reg8_t *reg1 = (reg8_t *)&cpu->registers[cpu->memory[cpu->pc++]];
            reg8_t *reg2 = (reg8_t *)&cpu->registers[cpu->memory[cpu->pc++]];
            cpu_cmp8(&cpu->flags, reg1, reg2);
            break;
        }

        default:
            return -1;
    }

    return 0;
}
