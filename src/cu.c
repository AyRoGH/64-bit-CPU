#include "instruction_set.h"
#include "instructions.h"
#include "cpu.h"
#include "alu.h"

#define ALU_OPCODE_MASK_8B 0x00000000000000FF
#define ALU_OPCODE_MASK_16B 0x000000000000FF00
#define ALU_OPCODE_MASK_32B 0x00000000FF000000
#define ALU_OPCODE_MASK_64B 0xFF00000000000000

int cu(cpu_t *cpu)
{
    switch (cpu->ir)
    {
        case NOP:
            return 0;
        case HLT:
            return 1;

        case MOV8_RR:
        {
            qword reg1_index = cpu->memory[cpu->pc] >= NB_REGISTERS ? NB_REGISTERS + 1 : cpu->memory[cpu->pc];
            cpu->pc++;
            qword reg2_index = cpu->memory[cpu->pc] >= NB_REGISTERS ? NB_REGISTERS + 1 : cpu->memory[cpu->pc];
            cpu->pc++;

            if (reg1_index == NB_REGISTERS + 1 || reg2_index == NB_REGISTERS + 1)
                return -1;

            reg8_t *reg1 = (reg8_t *)&cpu->registers[reg1_index];
            reg8_t *reg2 = (reg8_t *)&cpu->registers[reg2_index];

            if (reg1 == reg2)
                return 0;

            cpu_mov8_rr(&cpu->flags, reg1, reg2);
            
            break;
        }
        case MOV8_IR:
        {
            qword reg_index = cpu->memory[cpu->pc] >= NB_REGISTERS ? NB_REGISTERS + 1 : cpu->memory[cpu->pc];
            cpu->pc++;
        
            if (reg_index == NB_REGISTERS + 1)
                return -1;
        
            reg8_t *reg = (reg8_t *)&cpu->registers[reg_index];
            byte value = (byte)cpu->memory[cpu->pc++];
        
            cpu_mov8_ir(&cpu->flags, reg, value);
            break;
        }
        case MOV16_RR:
        {
            qword reg1_index = cpu->memory[cpu->pc] >= NB_REGISTERS ? NB_REGISTERS + 1 : cpu->memory[cpu->pc];
            cpu->pc++;
            qword reg2_index = cpu->memory[cpu->pc] >= NB_REGISTERS ? NB_REGISTERS + 1 : cpu->memory[cpu->pc];
            cpu->pc++;

            if (reg1_index == NB_REGISTERS + 1 || reg2_index == NB_REGISTERS + 1)
                return -1;

            reg16_t *reg1 = (reg16_t *)&cpu->registers[reg1_index];
            reg16_t *reg2 = (reg16_t *)&cpu->registers[reg2_index];

            if (reg1 == reg2)
                return 0;

            cpu_mov16_rr(&cpu->flags, reg1, reg2);
            break;
        }
        case MOV16_IR:
        {
            qword reg_index = cpu->memory[cpu->pc] >= NB_REGISTERS ? NB_REGISTERS + 1 : cpu->memory[cpu->pc];
            cpu->pc++;
        
            if (reg_index == NB_REGISTERS + 1)
                return -1;
        
            reg16_t *reg = (reg16_t *)&cpu->registers[reg_index];
            word value = (word)cpu->memory[cpu->pc++];
        
            cpu_mov16_ir(&cpu->flags, reg, value);
            break;
        }
        case MOV32_RR:
        {
            qword reg1_index = cpu->memory[cpu->pc] >= NB_REGISTERS ? NB_REGISTERS + 1 : cpu->memory[cpu->pc];
            cpu->pc++;
            qword reg2_index = cpu->memory[cpu->pc] >= NB_REGISTERS ? NB_REGISTERS + 1 : cpu->memory[cpu->pc];
            cpu->pc++;

            if (reg1_index == NB_REGISTERS + 1 || reg2_index == NB_REGISTERS + 1)
                return -1;

            reg32_t *reg1 = (reg32_t *)&cpu->registers[reg1_index];
            reg32_t *reg2 = (reg32_t *)&cpu->registers[reg2_index];

            if (reg1 == reg2)
                return 0;

            cpu_mov32_rr(&cpu->flags, reg1, reg2);
            break;
        }
        case MOV32_IR:
        {
            qword reg_index = cpu->memory[cpu->pc] >= NB_REGISTERS ? NB_REGISTERS + 1 : cpu->memory[cpu->pc];
            cpu->pc++;
        
            if (reg_index == NB_REGISTERS + 1)
                return -1;
        
            reg32_t *reg = (reg32_t *)&cpu->registers[reg_index];
            dword value = (dword)cpu->memory[cpu->pc++];
        
            cpu_mov32_ir(&cpu->flags, reg, value);
            break;
        }
        case MOV64_RR:
        {
            qword reg1_index = cpu->memory[cpu->pc] >= NB_REGISTERS ? NB_REGISTERS + 1 : cpu->memory[cpu->pc];
            cpu->pc++;
            qword reg2_index = cpu->memory[cpu->pc] >= NB_REGISTERS ? NB_REGISTERS + 1 : cpu->memory[cpu->pc];
            cpu->pc++;

            if (reg1_index == NB_REGISTERS + 1 || reg2_index == NB_REGISTERS + 1)
                return -1;

            reg64_t *reg1 = (reg64_t *)&cpu->registers[reg1_index];
            reg64_t *reg2 = (reg64_t *)&cpu->registers[reg2_index];

            if (reg1 == reg2)
                return 0;

            cpu_mov64_rr(&cpu->flags, reg1, reg2);
            break;
        }
        case MOV64_IR:
        {
            qword reg_index = cpu->memory[cpu->pc] >= NB_REGISTERS ? NB_REGISTERS + 1 : cpu->memory[cpu->pc];
            cpu->pc++;
        
            if (reg_index == NB_REGISTERS + 1)
                return -1;
        
            reg64_t *reg = (reg64_t *)&cpu->registers[reg_index];
            qword value = (qword)cpu->memory[cpu->pc++];
        
            cpu_mov64_ir(&cpu->flags, reg, value);
            break;
        }
        
        case JMP:
        {
            byte register_index = cpu->memory[cpu->pc];
            cpu->pc++;
            cpu->pc = cpu->registers[register_index].q;

            cpu->flags.cf = 0;
            cpu->flags.zf = 0;
            cpu->flags.sf = 0;
            cpu->flags.of = 0;

            break;
        }
        case JE:
            if (cpu->flags.zf)
            {
                byte register_index = cpu->memory[cpu->pc];
                cpu->pc++;
                cpu->pc = cpu->registers[register_index].q;
            }
            else
                cpu->pc++;

            cpu->flags.cf = 0;
            cpu->flags.zf = 0;
            cpu->flags.sf = 0;
            cpu->flags.of = 0;

            break;
        case JNE:
            if (!cpu->flags.zf)
            {
                byte register_index = cpu->memory[cpu->pc];
                cpu->pc++;
                cpu->pc = cpu->registers[register_index].q;
            }
            else
            cpu->pc++;

            cpu->flags.cf = 0;
            cpu->flags.zf = 0;
            cpu->flags.sf = 0;
            cpu->flags.of = 0;

            break;
        case JZ:
            if (cpu->flags.zf)
            {
                byte register_index = cpu->memory[cpu->pc];
                cpu->pc++;
                cpu->pc = cpu->registers[register_index].q;
            }
            else
                cpu->pc++;

            cpu->flags.cf = 0;
            cpu->flags.zf = 0;
            cpu->flags.sf = 0;
            cpu->flags.of = 0;

            break;
        case JNZ:
            if (!cpu->flags.zf)
            {
                byte register_index = cpu->memory[cpu->pc];
                cpu->pc++;
                cpu->pc = cpu->registers[register_index].q;
            }
            else
                cpu->pc++;

            cpu->flags.cf = 0;
            cpu->flags.zf = 0;
            cpu->flags.sf = 0;
            cpu->flags.of = 0;

            break;
        case JL:
            if (cpu->flags.sf != cpu->flags.of)
            {
                byte register_index = cpu->memory[cpu->pc];
                cpu->pc++;
                cpu->pc = cpu->registers[register_index].q;
            }
            else
                cpu->pc++;

            cpu->flags.cf = 0;
            cpu->flags.zf = 0;
            cpu->flags.sf = 0;
            cpu->flags.of = 0;

            break;
        case JLE:
            if (cpu->flags.sf != cpu->flags.of || cpu->flags.zf) {
                byte register_index = cpu->memory[cpu->pc];
                cpu->pc++;
                cpu->pc = cpu->registers[register_index].q;
            }
            else
                cpu->pc++;

            cpu->flags.cf = 0;
            cpu->flags.zf = 0;
            cpu->flags.sf = 0;
            cpu->flags.of = 0;

            break;
        case JG:
            if (cpu->flags.sf == cpu->flags.of && !cpu->flags.zf)
            {
                byte register_index = cpu->memory[cpu->pc];
                cpu->pc++;
                cpu->pc = cpu->registers[register_index].q;
            }
            else
                cpu->pc++;

            cpu->flags.cf = 0;
            cpu->flags.zf = 0;
            cpu->flags.sf = 0;
            cpu->flags.of = 0;

            break;
        case JGE:
            if (cpu->flags.sf == cpu->flags.of)
            {
                byte register_index = cpu->memory[cpu->pc];
                cpu->pc++;
                cpu->pc = cpu->registers[register_index].q;
            }
            else
                cpu->pc++;
    
            cpu->flags.cf = 0;
            cpu->flags.zf = 0;
            cpu->flags.sf = 0;
            cpu->flags.of = 0;

            break;

        default:
            if (cpu->ir & ALU_OPCODE_MASK_8B)
                return alu_8b(cpu);
            else if (cpu->ir & ALU_OPCODE_MASK_16B)
                return alu_16b(cpu);
            else if (cpu->ir & ALU_OPCODE_MASK_32B)
                return alu_32b(cpu);
            else if (cpu->ir & ALU_OPCODE_MASK_64B)
                return alu_64b(cpu);
            else
                return -1;
    }

    return 0;
}
