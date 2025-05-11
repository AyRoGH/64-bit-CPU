#include "types.h"
#include "register.h"
#include "cpu.h"
#include "instruction_set.h"
#include "instructions.h"

int alu_16b(cpu_t *cpu)
{
    switch (cpu->ir)
    {
        case AND16:
        {
            reg16_t *reg1 = (reg16_t *)&cpu->registers[cpu->memory[cpu->pc++]];
            reg16_t *reg2 = (reg16_t *)&cpu->registers[cpu->memory[cpu->pc++]];
            cpu_and16(&cpu->flags, reg1, reg2);
            break;
        }
        case OR16:
        {
            reg16_t *reg1 = (reg16_t *)&cpu->registers[cpu->memory[cpu->pc++]];
            reg16_t *reg2 = (reg16_t *)&cpu->registers[cpu->memory[cpu->pc++]];
            cpu_or16(&cpu->flags, reg1, reg2);
            break;
        }
        case XOR16:
        {
            reg16_t *reg1 = (reg16_t *)&cpu->registers[cpu->memory[cpu->pc++]];
            reg16_t *reg2 = (reg16_t *)&cpu->registers[cpu->memory[cpu->pc++]];
            cpu_xor16(&cpu->flags, reg1, reg2);
            break;
        }
        case NOT16:
        {
            reg16_t *reg = (reg16_t *)&cpu->registers[cpu->memory[cpu->pc++]];
            cpu_not16(&cpu->flags, reg);
            break;
        }
        case NAND16:
        {
            reg16_t *reg1 = (reg16_t *)&cpu->registers[cpu->memory[cpu->pc++]];
            reg16_t *reg2 = (reg16_t *)&cpu->registers[cpu->memory[cpu->pc++]];
            cpu_nand16(&cpu->flags, reg1, reg2);
            break;
        }
        case NOR16:
        {
            reg16_t *reg1 = (reg16_t *)&cpu->registers[cpu->memory[cpu->pc++]];
            reg16_t *reg2 = (reg16_t *)&cpu->registers[cpu->memory[cpu->pc++]];
            cpu_nor16(&cpu->flags, reg1, reg2);
            break;
        }
        case XNOR16:
        {
            reg16_t *reg1 = (reg16_t *)&cpu->registers[cpu->memory[cpu->pc++]];
            reg16_t *reg2 = (reg16_t *)&cpu->registers[cpu->memory[cpu->pc++]];
            cpu_xnor16(&cpu->flags, reg1, reg2);
            break;
        }
        case SHL16:
        {
            reg16_t *reg = (reg16_t *)&cpu->registers[cpu->memory[cpu->pc++]];
            cpu_shl16(&cpu->flags, reg);
            break;
        }
        case SHR16:
        {
            reg16_t *reg = (reg16_t *)&cpu->registers[cpu->memory[cpu->pc++]];
            cpu_shr16(&cpu->flags, reg);
            break;
        }

        case ADD16:
        {
            reg16_t *reg1 = (reg16_t *)&cpu->registers[cpu->memory[cpu->pc++]];
            reg16_t *reg2 = (reg16_t *)&cpu->registers[cpu->memory[cpu->pc++]];
            cpu_add16(&cpu->flags, reg1, reg2);
            break;
        }
        case SADD16:
        {
            reg16_t *reg1 = (reg16_t *)&cpu->registers[cpu->memory[cpu->pc++]];
            reg16_t *reg2 = (reg16_t *)&cpu->registers[cpu->memory[cpu->pc++]];
            cpu_sadd16(&cpu->flags, reg1, reg2);
            break;
        }
        case SUB16:
        {
            reg16_t *reg1 = (reg16_t *)&cpu->registers[cpu->memory[cpu->pc++]];
            reg16_t *reg2 = (reg16_t *)&cpu->registers[cpu->memory[cpu->pc++]];
            cpu_sub16(&cpu->flags, reg1, reg2);
            break;
        }
        case SSUB16:
        {
            reg16_t *reg1 = (reg16_t *)&cpu->registers[cpu->memory[cpu->pc++]];
            reg16_t *reg2 = (reg16_t *)&cpu->registers[cpu->memory[cpu->pc++]];
            cpu_ssub16(&cpu->flags, reg1, reg2);
            break;
        }
        case MUL16:
        {
            reg16_t *reg1 = (reg16_t *)&cpu->registers[cpu->memory[cpu->pc++]];
            reg16_t *reg2 = (reg16_t *)&cpu->registers[cpu->memory[cpu->pc++]];
            cpu_mul16(&cpu->flags, reg1, reg2);
            break;
        }
        case SMUL16:
        {
            reg16_t *reg1 = (reg16_t *)&cpu->registers[cpu->memory[cpu->pc++]];
            reg16_t *reg2 = (reg16_t *)&cpu->registers[cpu->memory[cpu->pc++]];
            cpu_smul16(&cpu->flags, reg1, reg2);
            break;
        }
        case DIV16:
        {
            reg16_t *reg1 = (reg16_t *)&cpu->registers[cpu->memory[cpu->pc++]];
            reg16_t *reg2 = (reg16_t *)&cpu->registers[cpu->memory[cpu->pc++]];
            cpu_div16(&cpu->flags, reg1, reg2);
            break;
        }
        case SDIV16:
        {
            reg16_t *reg1 = (reg16_t *)&cpu->registers[cpu->memory[cpu->pc++]];
            reg16_t *reg2 = (reg16_t *)&cpu->registers[cpu->memory[cpu->pc++]];
            cpu_sdiv16(&cpu->flags, reg1, reg2);
            break;
        }
        case MOD16:
        {
            reg16_t *reg1 = (reg16_t *)&cpu->registers[cpu->memory[cpu->pc++]];
            reg16_t *reg2 = (reg16_t *)&cpu->registers[cpu->memory[cpu->pc++]];
            cpu_mod16(&cpu->flags, reg1, reg2);
            break;
        }
        case SMOD16:
        {
            reg16_t *reg1 = (reg16_t *)&cpu->registers[cpu->memory[cpu->pc++]];
            reg16_t *reg2 = (reg16_t *)&cpu->registers[cpu->memory[cpu->pc++]];
            cpu_smod16(&cpu->flags, reg1, reg2);
            break;
        }
        case INC16:
        {
            reg16_t *reg = (reg16_t *)&cpu->registers[cpu->memory[cpu->pc++]];
            cpu_inc16(&cpu->flags, reg);
            break;
        }
        case DEC16:
        {
            reg16_t *reg = (reg16_t *)&cpu->registers[cpu->memory[cpu->pc++]];
            cpu_dec16(&cpu->flags, reg);
            break;
        }

        case CMP16:
        {
            reg16_t *reg1 = (reg16_t *)&cpu->registers[cpu->memory[cpu->pc++]];
            reg16_t *reg2 = (reg16_t *)&cpu->registers[cpu->memory[cpu->pc++]];
            cpu_cmp16(&cpu->flags, reg1, reg2);
            break;
        }

        default:
            return -1;
    }

    return 0;
}
