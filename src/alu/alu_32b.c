#include "types.h"
#include "register.h"
#include "cpu.h"
#include "instruction_set.h"
#include "instructions.h"

int alu_32b(cpu_t *cpu)
{
    switch (cpu->ir)
    {
        case AND32:
        {
            reg32_t *reg1 = (reg32_t *)&cpu->registers[cpu->memory[cpu->pc++]];
            reg32_t *reg2 = (reg32_t *)&cpu->registers[cpu->memory[cpu->pc++]];
            cpu_and32(&cpu->flags, reg1, reg2);
            break;
        }
        case OR32:
        {
            reg32_t *reg1 = (reg32_t *)&cpu->registers[cpu->memory[cpu->pc++]];
            reg32_t *reg2 = (reg32_t *)&cpu->registers[cpu->memory[cpu->pc++]];
            cpu_or32(&cpu->flags, reg1, reg2);
            break;
        }
        case XOR32:
        {
            reg32_t *reg1 = (reg32_t *)&cpu->registers[cpu->memory[cpu->pc++]];
            reg32_t *reg2 = (reg32_t *)&cpu->registers[cpu->memory[cpu->pc++]];
            cpu_xor32(&cpu->flags, reg1, reg2);
            break;
        }
        case NOT32:
        {
            reg32_t *reg = (reg32_t *)&cpu->registers[cpu->memory[cpu->pc++]];
            cpu_not32(&cpu->flags, reg);
            break;
        }
        case NAND32:
        {
            reg32_t *reg1 = (reg32_t *)&cpu->registers[cpu->memory[cpu->pc++]];
            reg32_t *reg2 = (reg32_t *)&cpu->registers[cpu->memory[cpu->pc++]];
            cpu_nand32(&cpu->flags, reg1, reg2);
            break;
        }
        case NOR32:
        {
            reg32_t *reg1 = (reg32_t *)&cpu->registers[cpu->memory[cpu->pc++]];
            reg32_t *reg2 = (reg32_t *)&cpu->registers[cpu->memory[cpu->pc++]];
            cpu_nor32(&cpu->flags, reg1, reg2);
            break;
        }
        case XNOR32:
        {
            reg32_t *reg1 = (reg32_t *)&cpu->registers[cpu->memory[cpu->pc++]];
            reg32_t *reg2 = (reg32_t *)&cpu->registers[cpu->memory[cpu->pc++]];
            cpu_xnor32(&cpu->flags, reg1, reg2);
            break;
        }
        case SHL32:
        {
            reg32_t *reg = (reg32_t *)&cpu->registers[cpu->memory[cpu->pc++]];
            cpu_shl32(&cpu->flags, reg);
            break;
        }
        case SHR32:
        {
            reg32_t *reg = (reg32_t *)&cpu->registers[cpu->memory[cpu->pc++]];
            cpu_shr32(&cpu->flags, reg);
            break;
        }

        case ADD32:
        {
            reg32_t *reg1 = (reg32_t *)&cpu->registers[cpu->memory[cpu->pc++]];
            reg32_t *reg2 = (reg32_t *)&cpu->registers[cpu->memory[cpu->pc++]];
            cpu_add32(&cpu->flags, reg1, reg2);
            break;
        }
        case SADD32:
        {
            reg32_t *reg1 = (reg32_t *)&cpu->registers[cpu->memory[cpu->pc++]];
            reg32_t *reg2 = (reg32_t *)&cpu->registers[cpu->memory[cpu->pc++]];
            cpu_sadd32(&cpu->flags, reg1, reg2);
            break;
        }
        case SUB32:
        {
            reg32_t *reg1 = (reg32_t *)&cpu->registers[cpu->memory[cpu->pc++]];
            reg32_t *reg2 = (reg32_t *)&cpu->registers[cpu->memory[cpu->pc++]];
            cpu_sub32(&cpu->flags, reg1, reg2);
            break;
        }
        case SSUB32:
        {
            reg32_t *reg1 = (reg32_t *)&cpu->registers[cpu->memory[cpu->pc++]];
            reg32_t *reg2 = (reg32_t *)&cpu->registers[cpu->memory[cpu->pc++]];
            cpu_ssub32(&cpu->flags, reg1, reg2);
            break;
        }
        case MUL32:
        {
            reg32_t *reg1 = (reg32_t *)&cpu->registers[cpu->memory[cpu->pc++]];
            reg32_t *reg2 = (reg32_t *)&cpu->registers[cpu->memory[cpu->pc++]];
            cpu_mul32(&cpu->flags, reg1, reg2);
            break;
        }
        case SMUL32:
        {
            reg32_t *reg1 = (reg32_t *)&cpu->registers[cpu->memory[cpu->pc++]];
            reg32_t *reg2 = (reg32_t *)&cpu->registers[cpu->memory[cpu->pc++]];
            cpu_smul32(&cpu->flags, reg1, reg2);
            break;
        }
        case DIV32:
        {
            reg32_t *reg1 = (reg32_t *)&cpu->registers[cpu->memory[cpu->pc++]];
            reg32_t *reg2 = (reg32_t *)&cpu->registers[cpu->memory[cpu->pc++]];
            cpu_div32(&cpu->flags, reg1, reg2);
            break;
        }
        case SDIV32:
        {
            reg32_t *reg1 = (reg32_t *)&cpu->registers[cpu->memory[cpu->pc++]];
            reg32_t *reg2 = (reg32_t *)&cpu->registers[cpu->memory[cpu->pc++]];
            cpu_sdiv32(&cpu->flags, reg1, reg2);
            break;
        }
        case MOD32:
        {
            reg32_t *reg1 = (reg32_t *)&cpu->registers[cpu->memory[cpu->pc++]];
            reg32_t *reg2 = (reg32_t *)&cpu->registers[cpu->memory[cpu->pc++]];
            cpu_mod32(&cpu->flags, reg1, reg2);
            break;
        }
        case SMOD32:
        {
            reg32_t *reg1 = (reg32_t *)&cpu->registers[cpu->memory[cpu->pc++]];
            reg32_t *reg2 = (reg32_t *)&cpu->registers[cpu->memory[cpu->pc++]];
            cpu_smod32(&cpu->flags, reg1, reg2);
            break;
        }
        case INC32:
        {
            reg32_t *reg = (reg32_t *)&cpu->registers[cpu->memory[cpu->pc++]];
            cpu_inc32(&cpu->flags, reg);
            break;
        }
        case DEC32:
        {
            reg32_t *reg = (reg32_t *)&cpu->registers[cpu->memory[cpu->pc++]];
            cpu_dec32(&cpu->flags, reg);
            break;
        }

        case CMP32:
        {
            reg32_t *reg1 = (reg32_t *)&cpu->registers[cpu->memory[cpu->pc++]];
            reg32_t *reg2 = (reg32_t *)&cpu->registers[cpu->memory[cpu->pc++]];
            cpu_cmp32(&cpu->flags, reg1, reg2);
            break;
        }

        default:
            return -1;
    }

    return 0;
}
