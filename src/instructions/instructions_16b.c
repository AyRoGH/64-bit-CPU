#include "types.h"
#include "register.h"
#include "instruction_set.h"
#include "instructions.h"
#include "cpu.h"

void cpu_mov16_rr(struct flags *flags, reg16_t *dst, reg16_t *src)
{
    dst->w = src->w;
    
    flags->cf = 0;
    flags->zf = (dst->w == 0) ? 1 : 0;
    flags->sf = (dst->w & 0x8000) ? 1 : 0;
    flags->of = 0;

    return;
}

void cpu_mov16_ir(struct flags *flags, reg16_t *dst, word value)
{
    dst->w = value;

    flags->cf = 0;
    flags->zf = (dst->w == 0) ? 1 : 0;
    flags->sf = (dst->w & 0x8000) ? 1 : 0;
    flags->of = 0;

    return;
}

void cpu_and16(struct flags *flags, reg16_t *reg1, reg16_t *reg2)
{
    reg1->w &= reg2->w;

    flags->cf = 0;
    flags->zf = (reg1->w == 0) ? 1 : 0;
    flags->sf = (reg1->w & 0x8000) ? 1 : 0;
    flags->of = 0;

    return;
}

void cpu_or16(struct flags *flags, reg16_t *reg1, reg16_t *reg2)
{
    reg1->w |= reg2->w;

    flags->cf = 0;
    flags->zf = (reg1->w == 0) ? 1 : 0;
    flags->sf = (reg1->w & 0x8000) ? 1 : 0;
    flags->of = 0;

    return;
}

void cpu_xor16(struct flags *flags, reg16_t *reg1, reg16_t *reg2)
{
    reg1->w ^= reg2->w;

    flags->cf = 0;
    flags->zf = (reg1->w == 0) ? 1 : 0;
    flags->sf = (reg1->w & 0x8000) ? 1 : 0;
    flags->of = 0;

    return;
}

void cpu_not16(struct flags *flags, reg16_t *reg)
{
    reg->w = ~reg->w;

    flags->cf = 0;
    flags->zf = (reg->w == 0) ? 1 : 0;
    flags->sf = (reg->w & 0x8000) ? 1 : 0;
    flags->of = 0;

    return;
}

void cpu_nand16(struct flags *flags, reg16_t *reg1, reg16_t *reg2)
{
    reg1->w = ~(reg1->w & reg2->w);

    flags->cf = 0;
    flags->zf = (reg1->w == 0) ? 1 : 0;
    flags->sf = (reg1->w & 0x8000) ? 1 : 0;
    flags->of = 0;

    return;
}

void cpu_nor16(struct flags *flags, reg16_t *reg1, reg16_t *reg2)
{
    reg1->w = ~(reg1->w | reg2->w);

    flags->cf = 0;
    flags->zf = (reg1->w == 0) ? 1 : 0;
    flags->sf = (reg1->w & 0x8000) ? 1 : 0;
    flags->of = 0;

    return;
}

void cpu_xnor16(struct flags *flags, reg16_t *reg1, reg16_t *reg2)
{
    reg1->w = ~(reg1->w ^ reg2->w);

    flags->cf = 0;
    flags->zf = (reg1->w == 0) ? 1 : 0;
    flags->sf = (reg1->w & 0x8000) ? 1 : 0;
    flags->of = 0;

    return;
}

void cpu_shl16(struct flags *flags, reg16_t *reg)
{
    reg->w = (reg->w) << 1;

    flags->cf = (reg->w & 0x8000) ? 1 : 0;
    flags->zf = (reg->w == 0) ? 1 : 0;
    flags->sf = (reg->w & 0x8000) ? 1 : 0;
    flags->of = ((reg->w & 0x8000) && (reg->w & 0x4000)) ? 1 : 0;

    return;
}

void cpu_shr16(struct flags *flags, reg16_t *reg)
{
    reg->w = (reg->w) >> 1;

    flags->cf = (reg->w & 0x0001) ? 1 : 0;
    flags->zf = (reg->w == 0) ? 1 : 0;
    flags->sf = (reg->w & 0x8000) ? 1 : 0;
    flags->of = ((reg->w & 0x8000) && (reg->w & 0x4000)) ? 1 : 0;

    return;
}

void cpu_add16(struct flags *flags, reg16_t *reg1, reg16_t *reg2)
{
    word result = reg1->w + reg2->w;

    flags->cf = (result < reg1->w) ? 1 : 0;
    flags->zf = (result == 0) ? 1 : 0;
    flags->sf = (result & 0x8000) ? 1 : 0;
    flags->of = ((reg1->w & 0x8000) == 0 && (reg2->w & 0x8000) == 0 && (result & 0x8000)) || ((reg1->w & 0x8000) && (reg2->w & 0x8000) && (result & 0x8000) == 0) ? 1 : 0;

    reg1->w = result;

    return;
}

void cpu_sadd16(struct flags *flags, reg16_t *reg1, reg16_t *reg2)
{
    sword result = (sword)reg1->w + (sword)reg2->w;

    flags->cf = (result < reg1->w) ? 1 : 0;
    flags->zf = (result == 0) ? 1 : 0;
    flags->sf = (result & 0x8000) ? 1 : 0;
    flags->of = ((reg1->w & 0x8000) == 0 && (reg2->w & 0x8000) == 0 && (result & 0x8000)) || ((reg1->w & 0x8000) && (reg2->w & 0x8000) && (result & 0x8000) == 0) ? 1 : 0;

    reg1->w = result;

    return;
}

void cpu_sub16(struct flags *flags, reg16_t *reg1, reg16_t *reg2)
{
    word result = reg1->w - reg2->w;

    flags->cf = (result > reg1->w) ? 1 : 0;
    flags->zf = (result == 0) ? 1 : 0;
    flags->sf = (result & 0x8000) ? 1 : 0;
    flags->of = ((reg1->w & 0x8000) && (reg2->w & 0x8000) == 0 && (result & 0x8000) == 0) || ((reg1->w & 0x8000) == 0 && (reg2->w & 0x8000) && (result & 0x8000)) ? 1 : 0;

    reg1->w = result;

    return;
}

void cpu_ssub16(struct flags *flags, reg16_t *reg1, reg16_t *reg2)
{
    sword result = (sword)reg1->w - (sword)reg2->w;
    
    flags->cf = (result > reg1->w) ? 1 : 0;
    flags->zf = (result == 0) ? 1 : 0;
    flags->sf = (result & 0x8000) ? 1 : 0;
    flags->of = ((reg1->w & 0x8000) && (reg2->w & 0x8000) == 0 && (result & 0x8000) == 0) || ((reg1->w & 0x8000) == 0 && (reg2->w & 0x8000) && (result & 0x8000)) ? 1 : 0;

    reg1->w = result;

    return;
}

void cpu_mul16(struct flags *flags, reg16_t *reg1, reg16_t *reg2)
{
    word result = reg1->w * reg2->w;
    
    flags->cf = ((result < reg1->w) && reg2->w > 1) ? 1 : 0;
    flags->zf = (result == 0) ? 1 : 0;
    flags->sf = (result & 0x8000) ? 1 : 0;
    flags->of = ((reg1->w * reg2->w) > 65535) ? 1 : 0;

    reg1->w = result;

    return;
}

void cpu_smul16(struct flags *flags, reg16_t *reg1, reg16_t *reg2)
{
    sword result = (sword)reg1->w * (sword)reg2->w;
    
    flags->cf = ((result < reg1->w) && reg2->w > 1) ? 1 : 0;
    flags->zf = (result == 0) ? 1 : 0;
    flags->sf = (result < 0) ? 1 : 0;
    flags->of = ((reg1->w * reg2->w) > INT16_MAX || (reg1->w * reg2->w) < INT16_MIN) ? 1 : 0;

    reg1->w = result;

    return;
}

void cpu_div16(struct flags *flags, reg16_t *reg1, reg16_t *reg2)
{
    if (reg2->w == 0)
    {
        flags->cf = 1;
        flags->zf = 0;
        flags->sf = 0;
        flags->of = 1;
    }
    else
    {
        word result = reg1->w / reg2->w;
        
        flags->cf = 0;
        flags->zf = (result == 0) ? 1 : 0;
        flags->sf = (result & 0x8000) ? 1 : 0;
        flags->of = 0;

        reg1->w = result;
    }
    return;
}

void cpu_sdiv16(struct flags *flags, reg16_t *reg1, reg16_t *reg2)
{
    if (reg2->w == 0)
    {
        flags->cf = 1;
        flags->zf = 0;
        flags->sf = 0;
        flags->of = 1;
    }
    else
    {
        sword a = (sword)reg1->w;
        sword b = (sword)reg2->w;
        sword result = a / b;
        
        flags->cf = 0;
        flags->zf = (result == 0) ? 1 : 0;
        flags->sf = (result < 0) ? 1 : 0;
        flags->of = (a == INT16_MIN && b == -1) ? 1 : 0;
        
        reg1->w = result;
    }
    return;
}

void cpu_mod16(struct flags *flags, reg16_t *reg1, reg16_t *reg2)
{
    if (reg2->w == 0)
    {
        flags->cf = 1;
        flags->zf = 0;
        flags->sf = 0;
        flags->of = 1;
    }
    else
    {
        word result = reg1->w % reg2->w;
        
        flags->cf = 0;
        flags->zf = (result == 0) ? 1 : 0;
        flags->sf = (result & 0x8000) ? 1 : 0;
        flags->of = 0;
        
        reg1->w = result;
    }
    return;
}

void cpu_smod16(struct flags *flags, reg16_t *reg1, reg16_t *reg2)
{
    if (reg2->w == 0)
    {
        flags->cf = 1;
        flags->zf = 0;
        flags->sf = 0;
        flags->of = 1;
    }
    else
    {
        sword a = (sword)reg1->w;
        sword b = (sword)reg2->w;
        sword result = a % b;
        
        flags->cf = 0;
        flags->zf = (result == 0) ? 1 : 0;
        flags->sf = (result < 0) ? 1 : 0;
        flags->of = 0;
        
        reg1->w = result;
    }
    return;
}

void cpu_inc16(struct flags *flags, reg16_t *reg)
{
    word result = reg->w + 1;

    flags->cf = (result < reg->w) ? 1 : 0;
    flags->zf = (result == 0) ? 1 : 0;
    flags->sf = (result & 0x8000) ? 1 : 0;
    flags->of = ((reg->w & 0x8000) == 0 && (result & 0x8000)) ? 1 : 0;

    reg->w = result;

    return;
}

void cpu_dec16(struct flags *flags, reg16_t *reg)
{
    word result = reg->w - 1;

    flags->cf = (result > reg->w) ? 1 : 0;
    flags->zf = (result == 0) ? 1 : 0;
    flags->sf = (result & 0x8000) ? 1 : 0;
    flags->of = ((reg->w & 0x8000) && (result & 0x8000) == 0) ? 1 : 0;

    reg->w = result;

    return;
}

void cpu_cmp16(struct flags *flags, reg16_t *reg1, reg16_t *reg2)
{
    word result = reg1->w - reg2->w;

    flags->cf = (result > reg1->w) ? 1 : 0;
    flags->zf = (result == 0) ? 1 : 0;
    flags->sf = (result & 0x8000) ? 1 : 0;
    flags->of = ((reg1->w & 0x8000) != (reg2->w & 0x8000)) && ((result & 0x8000) != (reg1->w & 0x8000)) ? 1 : 0;

    return;
}
