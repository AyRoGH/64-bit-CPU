#include "types.h"
#include "register.h"
#include "instruction_set.h"
#include "instructions.h"
#include "cpu.h"

#include <stdio.h>

void cpu_nop(void) {}
void cpu_hlt(void) {}

void cpu_mov64_rr(struct flags *flags, reg64_t *dst, reg64_t *src)
{
    dst->q = src->q;
    
    flags->cf = 0;
    flags->zf = (dst->q == 0) ? 1 : 0;
    flags->sf = (dst->q & 0x8000000000000000) ? 1 : 0;
    flags->of = 0;

    return;
}

void cpu_mov64_ir(struct flags *flags, reg64_t *dst, qword value)
{
    dst->q = value;

    flags->cf = 0;
    flags->zf = (dst->q == 0) ? 1 : 0;
    flags->sf = (dst->q & 0x8000000000000000) ? 1 : 0;
    flags->of = 0;

    return;
}

void cpu_and64(struct flags *flags, reg64_t *reg1, reg64_t *reg2)
{
    reg1->q &= reg2->q;

    flags->cf = 0;
    flags->zf = (reg1->q == 0) ? 1 : 0;
    flags->sf = (reg1->q & 0x8000000000000000) ? 1 : 0;
    flags->of = 0;

    return;
}

void cpu_or64(struct flags *flags, reg64_t *reg1, reg64_t *reg2)
{
    reg1->q |= reg2->q;

    flags->cf = 0;
    flags->zf = (reg1->q == 0) ? 1 : 0;
    flags->sf = (reg1->q & 0x8000000000000000) ? 1 : 0;
    flags->of = 0;

    return;
}

void cpu_xor64(struct flags *flags, reg64_t *reg1, reg64_t *reg2)
{
    reg1->q ^= reg2->q;

    flags->cf = 0;
    flags->zf = (reg1->q == 0) ? 1 : 0;
    flags->sf = (reg1->q & 0x8000000000000000) ? 1 : 0;
    flags->of = 0;

    return;
}

void cpu_not64(struct flags *flags, reg64_t *reg)
{
    reg->q = ~reg->q;

    flags->cf = 0;
    flags->zf = (reg->q == 0) ? 1 : 0;
    flags->sf = (reg->q & 0x8000000000000000) ? 1 : 0;
    flags->of = 0;

    return;
}

void cpu_nand64(struct flags *flags, reg64_t *reg1, reg64_t *reg2)
{
    reg1->q = ~(reg1->q & reg2->q);

    flags->cf = 0;
    flags->zf = (reg1->q == 0) ? 1 : 0;
    flags->sf = (reg1->q & 0x8000000000000000) ? 1 : 0;
    flags->of = 0;

    return;
}

void cpu_nor64(struct flags *flags, reg64_t *reg1, reg64_t *reg2)
{
    reg1->q = ~(reg1->q | reg2->q);

    flags->cf = 0;
    flags->zf = (reg1->q == 0) ? 1 : 0;
    flags->sf = (reg1->q & 0x8000000000000000) ? 1 : 0;
    flags->of = 0;

    return;
}

void cpu_xnor64(struct flags *flags, reg64_t *reg1, reg64_t *reg2)
{
    reg1->q = ~(reg1->q ^ reg2->q);

    flags->cf = 0;
    flags->zf = (reg1->q == 0) ? 1 : 0;
    flags->sf = (reg1->q & 0x8000000000000000) ? 1 : 0;
    flags->of = 0;

    return;
}

void cpu_shl64(struct flags *flags, reg64_t *reg)
{
    reg->q = (reg->q) << 1;

    flags->cf = (reg->q & 0x8000000000000000) ? 1 : 0;
    flags->zf = (reg->q == 0) ? 1 : 0;
    flags->sf = (reg->q & 0x8000000000000000) ? 1 : 0;
    flags->of = ((reg->q & 0x8000000000000000) && (reg->q & 0x4000000000000000)) ? 1 : 0;

    return;
}

void cpu_shr64(struct flags *flags, reg64_t *reg)
{
    reg->q = (reg->q) >> 1;

    flags->cf = (reg->q & 0x0000000000000001) ? 1 : 0;
    flags->zf = (reg->q == 0) ? 1 : 0;
    flags->sf = (reg->q & 0x8000000000000000) ? 1 : 0;
    flags->of = ((reg->q & 0x8000000000000000) && (reg->q & 0x4000000000000000)) ? 1 : 0;

    return;
}

void cpu_add64(struct flags *flags, reg64_t *reg1, reg64_t *reg2)
{
    qword result = reg1->q + reg2->q;

    flags->cf = (result < reg1->q) ? 1 : 0;
    flags->zf = (result == 0) ? 1 : 0;
    flags->sf = (result & 0x8000000000000000) ? 1 : 0;
    flags->of = ((reg1->q & 0x8000000000000000) == 0 && (reg2->q & 0x8000000000000000) == 0 && (result & 0x8000000000000000)) || ((reg1->q & 0x8000000000000000) && (reg2->q & 0x8000000000000000) && (result & 0x8000000000000000) == 0) ? 1 : 0;

    reg1->q = result;

    return;
}

void cpu_sadd64(struct flags *flags, reg64_t *reg1, reg64_t *reg2)
{
    sqword result = (sqword)reg1->q + (sqword)reg2->q;

    flags->cf = (result < (sqword)reg1->q) ? 1 : 0;
    flags->zf = (result == 0) ? 1 : 0;
    flags->sf = (result & 0x8000000000000000) ? 1 : 0;
    flags->of = ((reg1->q & 0x8000000000000000) == 0 && (reg2->q & 0x8000000000000000) == 0 && (result & 0x8000000000000000)) || ((reg1->q & 0x8000000000000000) && (reg2->q & 0x8000000000000000) && (result & 0x8000000000000000) == 0) ? 1 : 0;

    reg1->q = result;

    return;
}

void cpu_sub64(struct flags *flags, reg64_t *reg1, reg64_t *reg2)
{
    qword result = reg1->q - reg2->q;

    flags->cf = (result > reg1->q) ? 1 : 0;
    flags->zf = (result == 0) ? 1 : 0;
    flags->sf = (result & 0x8000000000000000) ? 1 : 0;
    flags->of = ((reg1->q & 0x8000000000000000) && (reg2->q & 0x8000000000000000) == 0 && (result & 0x8000000000000000) == 0) || ((reg1->q & 0x8000000000000000) == 0 && (reg2->q & 0x8000000000000000) && (result & 0x8000000000000000)) ? 1 : 0;

    reg1->q = result;

    return;
}

void cpu_ssub64(struct flags *flags, reg64_t *reg1, reg64_t *reg2)
{
    sqword result = (sqword)reg1->q - (sqword)reg2->q;
    
    flags->cf = (result > (sqword)reg1->q) ? 1 : 0;
    flags->zf = (result == 0) ? 1 : 0;
    flags->sf = (result & 0x8000000000000000) ? 1 : 0;
    flags->of = ((reg1->q & 0x8000000000000000) && (reg2->q & 0x8000000000000000) == 0 && (result & 0x8000000000000000) == 0) || ((reg1->q & 0x8000000000000000) == 0 && (reg2->q & 0x8000000000000000) && (result & 0x8000000000000000)) ? 1 : 0;

    reg1->q = result;

    return;
}

void cpu_mul64(struct flags *flags, reg64_t *reg1, reg64_t *reg2)
{
    qword result = reg1->q * reg2->q;
    
    flags->cf = ((result < reg1->q) && reg2->q > 1) ? 1 : 0;
    flags->zf = (result == 0) ? 1 : 0;
    flags->sf = (result & 0x8000000000000000) ? 1 : 0;
    flags->of = ((reg1->q * reg2->q) > 0xFFFFFFFFFFFFFFFF) ? 1 : 0;

    reg1->q = result;

    return;
}

void cpu_smul64(struct flags *flags, reg64_t *reg1, reg64_t *reg2)
{
    sqword result = (sqword)reg1->q * (sqword)reg2->q;
    
    flags->cf = ((result < (sqword)reg1->q) && reg2->q > 1) ? 1 : 0;
    flags->zf = (result == 0) ? 1 : 0;
    flags->of = ((reg1->q * reg2->q) > INT64_MAX || (sqword)(reg1->q * reg2->q) < INT64_MIN) ? 1 : 0;

    reg1->q = result;

    return;
}

void cpu_div64(struct flags *flags, reg64_t *reg1, reg64_t *reg2)
{
    if (reg2->q == 0)
    {
        flags->cf = 1;
        flags->zf = 0;
        flags->sf = 0;
        flags->of = 1;
    }
    else
    {
        qword result = reg1->q / reg2->q;
        
        flags->cf = 0;
        flags->zf = (result == 0) ? 1 : 0;
        flags->sf = (result & 0x8000000000000000) ? 1 : 0;
        flags->of = 0;

        reg1->q = result;
    }
    return;
}

void cpu_sdiv64(struct flags *flags, reg64_t *reg1, reg64_t *reg2)
{
    if (reg2->q == 0)
    {
        flags->cf = 1;
        flags->zf = 0;
        flags->sf = 0;
        flags->of = 1;
    }
    else
    {
        sqword a = (sqword)reg1->q;
        sqword b = (sqword)reg2->q;
        sqword result = a / b;
        
        flags->cf = 0;
        flags->zf = (result == 0) ? 1 : 0;
        flags->sf = (result < 0) ? 1 : 0;
        flags->of = (a == INT64_MIN && b == -1) ? 1 : 0;
        
        reg1->q = result;
    }
    return;
}

void cpu_mod64(struct flags *flags, reg64_t *reg1, reg64_t *reg2)
{
    if (reg2->q == 0)
    {
        flags->cf = 1;
        flags->zf = 0;
        flags->sf = 0;
        flags->of = 1;
    }
    else
    {
        qword result = reg1->q % reg2->q;
        
        flags->cf = 0;
        flags->zf = (result == 0) ? 1 : 0;
        flags->sf = (result & 0x8000000000000000) ? 1 : 0;
        flags->of = 0;
        
        reg1->q = result;
    }
    return;
}

void cpu_smod64(struct flags *flags, reg64_t *reg1, reg64_t *reg2)
{
    if (reg2->q == 0)
    {
        flags->cf = 1;
        flags->zf = 0;
        flags->sf = 0;
        flags->of = 1;
    }
    else
    {
        sqword a = (sqword)reg1->q;
        sqword b = (sqword)reg2->q;
        sqword result = a % b;
        
        flags->cf = 0;
        flags->zf = (result == 0) ? 1 : 0;
        flags->sf = (result < 0) ? 1 : 0;
        flags->of = 0;
        
        reg1->q = result;
    }
    return;
}

void cpu_inc64(struct flags *flags, reg64_t *reg)
{
    qword result = reg->q + 1;

    flags->cf = (result < reg->q) ? 1 : 0;
    flags->zf = (result == 0) ? 1 : 0;
    flags->sf = (result & 0x8000000000000000) ? 1 : 0;
    flags->of = ((reg->q & 0x8000000000000000) == 0 && (result & 0x8000000000000000)) ? 1 : 0;

    reg->q = result;

    return;
}

void cpu_dec64(struct flags *flags, reg64_t *reg)
{
    qword result = reg->q - 1;

    flags->cf = (result > reg->q) ? 1 : 0;
    flags->zf = (result == 0) ? 1 : 0;
    flags->sf = (result & 0x8000000000000000) ? 1 : 0;
    flags->of = ((reg->q & 0x8000000000000000) && (result & 0x8000000000000000) == 0) ? 1 : 0;

    reg->q = result;

    return;
}

void cpu_cmp64(struct flags *flags, reg64_t *reg1, reg64_t *reg2)
{
    qword result = reg1->q - reg2->q;

    flags->cf = (result > reg1->q) ? 1 : 0;
    flags->zf = (result == 0) ? 1 : 0;
    flags->sf = (result & 0x8000000000000000) ? 1 : 0;
    flags->of = ((reg1->q & 0x8000000000000000) != (reg2->q & 0x8000000000000000)) && ((result & 0x8000000000000000) != (reg1->q & 0x8000000000000000)) ? 1 : 0;

    return;
}

void cpu_jmp(cpu_t *cpu, qword addr)
{
    cpu->pc = addr;

    return;
}

void cpu_je(cpu_t *cpu, qword addr)
{
    if (cpu->flags.zf)
        cpu->pc = addr;
    else
        cpu->pc += 8;

    return;
}

void cpu_jne(cpu_t *cpu, qword addr)
{
    if (!cpu->flags.zf)
        cpu->pc = addr;
    else
        cpu->pc += 8;

    return;
}

void cpu_jz(cpu_t *cpu, qword addr)
{
    if (cpu->flags.zf)
        cpu->pc = addr;
    else
        cpu->pc += 8;

    return;
}

void cpu_jnz(cpu_t *cpu, qword addr)
{
    if (!cpu->flags.zf)
        cpu->pc = addr;
    else
        cpu->pc += 8;

    return;
}

void cpu_jl(cpu_t *cpu, qword addr)
{
    if (cpu->flags.sf != cpu->flags.of)
        cpu->pc = addr;
    else
        cpu->pc += 8;

    return;
}

void cpu_jle(cpu_t *cpu, qword addr)
{
    if (cpu->flags.sf != cpu->flags.of || cpu->flags.zf)
        cpu->pc = addr;
    else
        cpu->pc += 8;

    return;
}

void cpu_jg(cpu_t *cpu, qword addr)
{
    if (cpu->flags.sf == cpu->flags.of && !cpu->flags.zf)
        cpu->pc = addr;
    else
        cpu->pc += 8;

    return;
}

void cpu_jge(cpu_t *cpu, qword addr)
{
    if (cpu->flags.sf == cpu->flags.of)
        cpu->pc = addr;
    else
        cpu->pc += 8;

    return;
}
