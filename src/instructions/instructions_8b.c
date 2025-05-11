#include "types.h"
#include "register.h"
#include "instruction_set.h"
#include "instructions.h"
#include "cpu.h"

void cpu_mov8_rr(struct flags *flags, reg8_t *dst, reg8_t *src)
{
    dst->b = src->b;
    
    flags->cf = 0;
    flags->zf = (dst->b == 0) ? 1 : 0;
    flags->sf = (dst->b & 0x80) ? 1 : 0;
    flags->of = 0;

    return;
}

void cpu_mov8_ir(struct flags *flags, reg8_t *dst, byte value)
{
    dst->b = value;

    flags->cf = 0;
    flags->zf = (dst->b == 0) ? 1 : 0;
    flags->sf = (dst->b & 0x80) ? 1 : 0;
    flags->of = 0;

    return;
}

void cpu_and8(struct flags *flags, reg8_t *reg1, reg8_t *reg2)
{
    reg1->b &= reg2->b;

    flags->cf = 0;
    flags->zf = (reg1->b == 0) ? 1 : 0;
    flags->sf = (reg1->b & 0x80) ? 1 : 0;
    flags->of = 0;

    return;
}

void cpu_or8(struct flags *flags, reg8_t *reg1, reg8_t *reg2)
{
    reg1->b |= reg2->b;

    flags->cf = 0;
    flags->zf = (reg1->b == 0) ? 1 : 0;
    flags->sf = (reg1->b & 0x80) ? 1 : 0;
    flags->of = 0;

    return;
}

void cpu_xor8(struct flags *flags, reg8_t *reg1, reg8_t *reg2)
{
    reg1->b ^= reg2->b;

    flags->cf = 0;
    flags->zf = (reg1->b == 0) ? 1 : 0;
    flags->sf = (reg1->b & 0x80) ? 1 : 0;
    flags->of = 0;

    return;
}

void cpu_not8(struct flags *flags, reg8_t *reg)
{
    reg->b = ~reg->b;

    flags->cf = 0;
    flags->zf = (reg->b == 0) ? 1 : 0;
    flags->sf = (reg->b & 0x80) ? 1 : 0;
    flags->of = 0;

    return;
}

void cpu_nand8(struct flags *flags, reg8_t *reg1, reg8_t *reg2)
{
    reg1->b = ~(reg1->b & reg2->b);

    flags->cf = 0;
    flags->zf = (reg1->b == 0) ? 1 : 0;
    flags->sf = (reg1->b & 0x80) ? 1 : 0;
    flags->of = 0;

    return;
}

void cpu_nor8(struct flags *flags, reg8_t *reg1, reg8_t *reg2)
{
    reg1->b = ~(reg1->b | reg2->b);

    flags->cf = 0;
    flags->zf = (reg1->b == 0) ? 1 : 0;
    flags->sf = (reg1->b & 0x80) ? 1 : 0;
    flags->of = 0;

    return;
}

void cpu_xnor8(struct flags *flags, reg8_t *reg1, reg8_t *reg2)
{
    reg1->b = ~(reg1->b ^ reg2->b);

    flags->cf = 0;
    flags->zf = (reg1->b == 0) ? 1 : 0;
    flags->sf = (reg1->b & 0x80) ? 1 : 0;
    flags->of = 0;

    return;
}

void cpu_shl8(struct flags *flags, reg8_t *reg)
{
    reg->b = (reg->b) << 1;

    flags->cf = (reg->b & 0x80) ? 1 : 0;
    flags->zf = (reg->b == 0) ? 1 : 0;
    flags->sf = (reg->b & 0x80) ? 1 : 0;
    flags->of = ((reg->b & 0x80) && (reg->b & 0x40)) ? 1 : 0;

    return;
}

void cpu_shr8(struct flags *flags, reg8_t *reg)
{
    reg->b = (reg->b) >> 1;

    flags->cf = (reg->b & 0x01) ? 1 : 0;
    flags->zf = (reg->b == 0) ? 1 : 0;
    flags->sf = (reg->b & 0x80) ? 1 : 0;
    flags->of = ((reg->b & 0x80) && (reg->b & 0x40)) ? 1 : 0;

    return;
}

void cpu_add8(struct flags *flags, reg8_t *reg1, reg8_t *reg2)
{
    byte result = reg1->b + reg2->b;

    flags->cf = (result < reg1->b) ? 1 : 0;
    flags->zf = (result == 0) ? 1 : 0;
    flags->sf = (result & 0x80) ? 1 : 0;
    flags->of = ((reg1->b & 0x80) == 0 && (reg2->b & 0x80) == 0 && (result & 0x80)) || ((reg1->b & 0x80) && (reg2->b & 0x80) && (result & 0x80) == 0) ? 1 : 0;

    reg1->b = result;

    return;
}

void cpu_sadd8(struct flags *flags, reg8_t *reg1, reg8_t *reg2)
{
    sbyte result = (sbyte)reg1->b + (sbyte)reg2->b;

    flags->cf = (result < reg1->b) ? 1 : 0;
    flags->zf = (result == 0) ? 1 : 0;
    flags->sf = (result & 0x80) ? 1 : 0;
    flags->of = ((reg1->b & 0x80) == 0 && (reg2->b & 0x80) == 0 && (result & 0x80)) || ((reg1->b & 0x80) && (reg2->b & 0x80) && (result & 0x80) == 0) ? 1 : 0;

    reg1->b = result;

    return;
}

void cpu_sub8(struct flags *flags, reg8_t *reg1, reg8_t *reg2)
{
    byte result = reg1->b - reg2->b;

    flags->cf = (result > reg1->b) ? 1 : 0;
    flags->zf = (result == 0) ? 1 : 0;
    flags->sf = (result & 0x80) ? 1 : 0;
    flags->of = ((reg1->b & 0x80) && (reg2->b & 0x80) == 0 && (result & 0x80)) || ((reg1->b & 0x80) == 0 && (reg2->b & 0x80) && (result & 0x80) == 0) ? 1 : 0;

    reg1->b = result;

    return;
}

void cpu_ssub8(struct flags *flags, reg8_t *reg1, reg8_t *reg2)
{
    sbyte result = (sbyte)reg1->b - (sbyte)reg2->b;
    
    flags->cf = (result > reg1->b) ? 1 : 0;
    flags->zf = (result == 0) ? 1 : 0;
    flags->sf = (result & 0x80) ? 1 : 0;
    flags->of = ((reg1->b & 0x80) && (reg2->b & 0x80) == 0 && (result & 0x80)) || ((reg1->b & 0x80) == 0 && (reg2->b & 0x80) && (result & 0x80) == 0) ? 1 : 0;

    reg1->b = result;

    return;
}

void cpu_mul8(struct flags *flags, reg8_t *reg1, reg8_t *reg2)
{
    byte result = reg1->b * reg2->b;
    
    flags->cf = ((result < reg1->b) && reg2->b > 1) ? 1 : 0;
    flags->zf = (result == 0) ? 1 : 0;
    flags->sf = (result & 0x80) ? 1 : 0;
    flags->of = ((reg1->b * reg2->b) > 127 || (reg1->b * reg2->b) < -128) ? 1 : 0;

    reg1->b = result;

    return;
}

void cpu_smul8(struct flags *flags, reg8_t *reg1, reg8_t *reg2)
{
    sbyte result = (sbyte)reg1->b * (sbyte)reg2->b;
    
    flags->cf = ((result < reg1->b) && reg2->b > 1) ? 1 : 0;
    flags->zf = (result == 0) ? 1 : 0;
    flags->sf = (result < 0) ? 1 : 0;
    flags->of = ((reg1->b * reg2->b) > INT8_MAX || (reg1->b * reg2->b) < INT8_MIN) ? 1 : 0;

    reg1->b = result;

    return;
}

void cpu_div8(struct flags *flags, reg8_t *reg1, reg8_t *reg2)
{
    if (reg2->b == 0)
    {
        flags->cf = 1;
        flags->zf = 0;
        flags->sf = 0;
        flags->of = 1;
    }
    else
    {
        byte result = reg1->b / reg2->b;
        
        flags->cf = 0;
        flags->zf = (result == 0) ? 1 : 0;
        flags->sf = (result & 0x80) ? 1 : 0;
        flags->of = 0;

        reg1->b = result;
    }
    return;
}

void cpu_sdiv8(struct flags *flags, reg8_t *reg1, reg8_t *reg2)
{
    if (reg2->b == 0)
    {
        flags->cf = 1;
        flags->zf = 0;
        flags->sf = 0;
        flags->of = 1;
    }
    else
    {
        sbyte a = (sbyte)reg1->b;
        sbyte b = (sbyte)reg2->b;
        sbyte result = a / b;
        
        flags->cf = 0;
        flags->zf = (result == 0) ? 1 : 0;
        flags->sf = (result < 0) ? 1 : 0;
        flags->of = (a == INT8_MIN && b == -1) ? 1 : 0;
        
        reg1->b = result;
    }
    return;
}

void cpu_mod8(struct flags *flags, reg8_t *reg1, reg8_t *reg2)
{
    if (reg2->b == 0)
    {
        flags->cf = 1;
        flags->zf = 0;
        flags->sf = 0;
        flags->of = 1;
    }
    else
    {
        byte result = reg1->b % reg2->b;
        
        flags->cf = 0;
        flags->zf = (result == 0) ? 1 : 0;
        flags->sf = (result & 0x80) ? 1 : 0;
        flags->of = 0;
        
        reg1->b = result;
    }
    return;
}

void cpu_smod8(struct flags *flags, reg8_t *reg1, reg8_t *reg2)
{
    if (reg2->b == 0)
    {
        flags->cf = 1;
        flags->zf = 0;
        flags->sf = 0;
        flags->of = 1;
    }
    else
    {
        sbyte a = (sbyte)reg1->b;
        sbyte b = (sbyte)reg2->b;
        sbyte result = a % b;
        
        flags->cf = 0;
        flags->zf = (result == 0) ? 1 : 0;
        flags->sf = (result < 0) ? 1 : 0;
        flags->of = 0;
        
        reg1->b = result;
    }
    return;
}

void cpu_inc8(struct flags *flags, reg8_t *reg)
{
    byte result = reg->b + 1;

    flags->cf = (result < reg->b) ? 1 : 0;
    flags->zf = (result == 0) ? 1 : 0;
    flags->sf = (result & 0x80) ? 1 : 0;
    flags->of = ((reg->b & 0x80) == 0 && (result & 0x80)) || ((reg->b & 0x80) && (result & 0x80) == 0) ? 1 : 0;

    reg->b = result;

    return;
}

void cpu_dec8(struct flags *flags, reg8_t *reg)
{
    byte result = reg->b - 1;

    flags->cf = (result > reg->b) ? 1 : 0;
    flags->zf = (result == 0) ? 1 : 0;
    flags->sf = (result & 0x80) ? 1 : 0;
    flags->of = ((reg->b & 0x80) && (result & 0x80) == 0) || ((reg->b & 0x80) == 0 && (result & 0x80)) ? 1 : 0;

    reg->b = result;

    return;
}

void cpu_cmp8(struct flags *flags, reg8_t *reg1, reg8_t *reg2)
{
    byte result = reg1->b - reg2->b;

    flags->cf = (result > reg1->b) ? 1 : 0;
    flags->zf = (result == 0) ? 1 : 0;
    flags->sf = (result & 0x80) ? 1 : 0;
    flags->of = ((reg1->b & 0x80) != (reg2->b & 0x80)) && ((result & 0x80) != (reg1->b & 0x80)) ? 1 : 0;

    return;
}
