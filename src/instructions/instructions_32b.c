#include "types.h"
#include "register.h"
#include "instruction_set.h"
#include "instructions.h"
#include "cpu.h"

void cpu_mov32_rr(struct flags *flags, reg32_t *dst, reg32_t *src)
{
    dst->d = src->d;
    
    flags->cf = 0;
    flags->zf = (dst->d == 0) ? 1 : 0;
    flags->sf = (dst->d & 0x80000000) ? 1 : 0;
    flags->of = 0;

    return;
}

void cpu_mov32_ir(struct flags *flags, reg32_t *dst, dword value)
{
    dst->d = value;

    flags->cf = 0;
    flags->zf = (dst->d == 0) ? 1 : 0;
    flags->sf = (dst->d & 0x80000000) ? 1 : 0;
    flags->of = 0;

    return;
}

void cpu_and32(struct flags *flags, reg32_t *reg1, reg32_t *reg2)
{
    reg1->d &= reg2->d;

    flags->cf = 0;
    flags->zf = (reg1->d == 0) ? 1 : 0;
    flags->sf = (reg1->d & 0x80000000) ? 1 : 0;
    flags->of = 0;

    return;
}

void cpu_or32(struct flags *flags, reg32_t *reg1, reg32_t *reg2)
{
    reg1->d |= reg2->d;

    flags->cf = 0;
    flags->zf = (reg1->d == 0) ? 1 : 0;
    flags->sf = (reg1->d & 0x80000000) ? 1 : 0;
    flags->of = 0;

    return;
}

void cpu_xor32(struct flags *flags, reg32_t *reg1, reg32_t *reg2)
{
    reg1->d ^= reg2->d;

    flags->cf = 0;
    flags->zf = (reg1->d == 0) ? 1 : 0;
    flags->sf = (reg1->d & 0x80000000) ? 1 : 0;
    flags->of = 0;

    return;
}

void cpu_not32(struct flags *flags, reg32_t *reg)
{
    reg->d = ~reg->d;

    flags->cf = 0;
    flags->zf = (reg->d == 0) ? 1 : 0;
    flags->sf = (reg->d & 0x80000000) ? 1 : 0;
    flags->of = 0;

    return;
}

void cpu_nand32(struct flags *flags, reg32_t *reg1, reg32_t *reg2)
{
    reg1->d = ~(reg1->d & reg2->d);

    flags->cf = 0;
    flags->zf = (reg1->d == 0) ? 1 : 0;
    flags->sf = (reg1->d & 0x80000000) ? 1 : 0;
    flags->of = 0;

    return;
}

void cpu_nor32(struct flags *flags, reg32_t *reg1, reg32_t *reg2)
{
    reg1->d = ~(reg1->d | reg2->d);

    flags->cf = 0;
    flags->zf = (reg1->d == 0) ? 1 : 0;
    flags->sf = (reg1->d & 0x80000000) ? 1 : 0;
    flags->of = 0;

    return;
}

void cpu_xnor32(struct flags *flags, reg32_t *reg1, reg32_t *reg2)
{
    reg1->d = ~(reg1->d ^ reg2->d);

    flags->cf = 0;
    flags->zf = (reg1->d == 0) ? 1 : 0;
    flags->sf = (reg1->d & 0x80000000) ? 1 : 0;
    flags->of = 0;

    return;
}

void cpu_shl32(struct flags *flags, reg32_t *reg)
{
    reg->d = (reg->d) << 1;

    flags->cf = (reg->d & 0x80000000) ? 1 : 0;
    flags->zf = (reg->d == 0) ? 1 : 0;
    flags->sf = (reg->d & 0x80000000) ? 1 : 0;
    flags->of = ((reg->d & 0x80000000) && (reg->d & 0x40000000)) ? 1 : 0;

    return;
}

void cpu_shr32(struct flags *flags, reg32_t *reg)
{
    reg->d = (reg->d) >> 1;

    flags->cf = (reg->d & 0x00000001) ? 1 : 0;
    flags->zf = (reg->d == 0) ? 1 : 0;
    flags->sf = (reg->d & 0x80000000) ? 1 : 0;
    flags->of = ((reg->d & 0x80000000) && (reg->d & 0x40000000)) ? 1 : 0;

    return;
}

void cpu_add32(struct flags *flags, reg32_t *reg1, reg32_t *reg2)
{
    dword result = reg1->d + reg2->d;

    flags->cf = (result < reg1->d) ? 1 : 0;
    flags->zf = (result == 0) ? 1 : 0;
    flags->sf = (result & 0x80000000) ? 1 : 0;
    flags->of = ((reg1->d & 0x80000000) == 0 && (reg2->d & 0x80000000) == 0 && (result & 0x80000000)) || 
                ((reg1->d & 0x80000000) && (reg2->d & 0x80000000) && (result & 0x80000000) == 0) ? 1 : 0;

    reg1->d = result;

    return;
}

void cpu_sadd32(struct flags *flags, reg32_t *reg1, reg32_t *reg2)
{
    sdword result = (sdword)reg1->d + (sdword)reg2->d;

    flags->cf = (result < (sdword)reg1->d) ? 1 : 0;
    flags->zf = (result == 0) ? 1 : 0;
    flags->sf = (result & 0x80000000) ? 1 : 0;
    flags->of = ((reg1->d & 0x80000000) == 0 && (reg2->d & 0x80000000) == 0 && (result & 0x80000000)) || 
                ((reg1->d & 0x80000000) && (reg2->d & 0x80000000) && (result & 0x80000000) == 0) ? 1 : 0;

    reg1->d = result;

    return;
}

void cpu_sub32(struct flags *flags, reg32_t *reg1, reg32_t *reg2)
{
    dword result = reg1->d - reg2->d;

    flags->cf = (result > reg1->d) ? 1 : 0;
    flags->zf = (result == 0) ? 1 : 0;
    flags->sf = (result & 0x80000000) ? 1 : 0;
    flags->of = ((reg1->d & 0x80000000) && (reg2->d & 0x80000000) == 0 && (result & 0x80000000) == 0) || 
                ((reg1->d & 0x80000000) == 0 && (reg2->d & 0x80000000) && (result & 0x80000000)) ? 1 : 0;

    reg1->d = result;

    return;
}

void cpu_ssub32(struct flags *flags, reg32_t *reg1, reg32_t *reg2)
{
    sdword result = (sdword)reg1->d - (sdword)reg2->d;
    
    flags->cf = (result > (sdword)reg1->d) ? 1 : 0;
    flags->zf = (result == 0) ? 1 : 0;
    flags->sf = (result & 0x80000000) ? 1 : 0;
    flags->of = ((reg1->d & 0x80000000) && (reg2->d & 0x80000000) == 0 && (result & 0x80000000) == 0) || 
                ((reg1->d & 0x80000000) == 0 && (reg2->d & 0x80000000) && (result & 0x80000000)) ? 1 : 0;

    reg1->d = result;

    return;
}

void cpu_mul32(struct flags *flags, reg32_t *reg1, reg32_t *reg2)
{
    dword result = reg1->d * reg2->d;
    
    flags->cf = ((result < reg1->d) && reg2->d > 1) ? 1 : 0;
    flags->zf = (result == 0) ? 1 : 0;
    flags->sf = (result & 0x80000000) ? 1 : 0;
    flags->of = ((reg1->d * reg2->d) > 0xFFFFFFFF) ? 1 : 0;

    reg1->d = result;

    return;
}

void cpu_smul32(struct flags *flags, reg32_t *reg1, reg32_t *reg2)
{
    sdword result = (sdword)reg1->d * (sdword)reg2->d;
    
    flags->cf = ((result < (sdword)reg1->d) && reg2->d > 1) ? 1 : 0;
    flags->zf = (result == 0) ? 1 : 0;
    flags->sf = (result < 0) ? 1 : 0;
    flags->of = ((reg1->d * reg2->d) > INT32_MAX || (sdword)(reg1->d * reg2->d) < INT32_MIN) ? 1 : 0;

    reg1->d = result;

    return;
}

void cpu_div32(struct flags *flags, reg32_t *reg1, reg32_t *reg2)
{
    if (reg2->d == 0)
    {
        flags->cf = 1;
        flags->zf = 0;
        flags->sf = 0;
        flags->of = 1;
    }
    else
    {
        dword result = reg1->d / reg2->d;
        
        flags->cf = 0;
        flags->zf = (result == 0) ? 1 : 0;
        flags->sf = (result & 0x80000000) ? 1 : 0;
        flags->of = 0;

        reg1->d = result;
    }
    return;
}

void cpu_sdiv32(struct flags *flags, reg32_t *reg1, reg32_t *reg2)
{
    if (reg2->d == 0)
    {
        flags->cf = 1;
        flags->zf = 0;
        flags->sf = 0;
        flags->of = 1;
    }
    else
    {
        sdword a = (sdword)reg1->d;
        sdword b = (sdword)reg2->d;
        sdword result = a / b;
        
        flags->cf = 0;
        flags->zf = (result == 0) ? 1 : 0;
        flags->sf = (result < 0) ? 1 : 0;
        flags->of = (a == INT32_MIN && b == -1) ? 1 : 0;
        
        reg1->d = result;
    }
    return;
}

void cpu_mod32(struct flags *flags, reg32_t *reg1, reg32_t *reg2)
{
    if (reg2->d == 0)
    {
        flags->cf = 1;
        flags->zf = 0;
        flags->sf = 0;
        flags->of = 1;
    }
    else
    {
        dword result = reg1->d % reg2->d;
        
        flags->cf = 0;
        flags->zf = (result == 0) ? 1 : 0;
        flags->sf = (result & 0x80000000) ? 1 : 0;
        flags->of = 0;
        
        reg1->d = result;
    }
    return;
}

void cpu_smod32(struct flags *flags, reg32_t *reg1, reg32_t *reg2)
{
    if (reg2->d == 0)
    {
        flags->cf = 1;
        flags->zf = 0;
        flags->sf = 0;
        flags->of = 1;
    }
    else
    {
        sdword a = (sdword)reg1->d;
        sdword b = (sdword)reg2->d;
        sdword result = a % b;
        
        flags->cf = 0;
        flags->zf = (result == 0) ? 1 : 0;
        flags->sf = (result < 0) ? 1 : 0;
        flags->of = 0;
        
        reg1->d = result;
    }
    return;
}

void cpu_inc32(struct flags *flags, reg32_t *reg)
{
    dword result = reg->d + 1;

    flags->cf = (result < reg->d) ? 1 : 0;
    flags->zf = (result == 0) ? 1 : 0;
    flags->sf = (result & 0x80000000) ? 1 : 0;
    flags->of = ((reg->d & 0x80000000) == 0 && (result & 0x80000000)) ? 1 : 0;

    reg->d = result;

    return;
}

void cpu_dec32(struct flags *flags, reg32_t *reg)
{
    dword result = reg->d - 1;

    flags->cf = (result > reg->d) ? 1 : 0;
    flags->zf = (result == 0) ? 1 : 0;
    flags->sf = (result & 0x80000000) ? 1 : 0;
    flags->of = ((reg->d & 0x80000000) && (result & 0x80000000) == 0) ? 1 : 0;

    reg->d = result;

    return;
}

void cpu_cmp32(struct flags *flags, reg32_t *reg1, reg32_t *reg2)
{
    dword result = reg1->d - reg2->d;

    flags->cf = (result > reg1->d) ? 1 : 0;
    flags->zf = (result == 0) ? 1 : 0;
    flags->sf = (result & 0x80000000) ? 1 : 0;
    flags->of = ((reg1->d & 0x80000000) != (reg2->d & 0x80000000)) && ((result & 0x80000000) != (reg1->d & 0x80000000)) ? 1 : 0;

    return;
}
