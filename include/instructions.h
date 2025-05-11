#include "types.h"
#include "register.h"
#include "cpu.h"

#ifndef INSTRUCTIONS_H
#define INSTRUCTIONS_H

/* Basic CPU operations */
void cpu_nop(void);
void cpu_hlt(void);

/* 8-bit instructions */
void cpu_mov8_rr(struct flags *flags, reg8_t *dst, reg8_t *src);
void cpu_mov8_ir(struct flags *flags, reg8_t *dst, byte value);
void cpu_and8(struct flags *flags, reg8_t *reg1, reg8_t *reg2);
void cpu_or8(struct flags *flags, reg8_t *reg1, reg8_t *reg2);
void cpu_xor8(struct flags *flags, reg8_t *reg1, reg8_t *reg2);
void cpu_not8(struct flags *flags, reg8_t *reg);
void cpu_nand8(struct flags *flags, reg8_t *reg1, reg8_t *reg2);
void cpu_nor8(struct flags *flags, reg8_t *reg1, reg8_t *reg2);
void cpu_xnor8(struct flags *flags, reg8_t *reg1, reg8_t *reg2);
void cpu_shl8(struct flags *flags, reg8_t *reg);
void cpu_shr8(struct flags *flags, reg8_t *reg);
void cpu_add8(struct flags *flags, reg8_t *reg1, reg8_t *reg2);
void cpu_sadd8(struct flags *flags, reg8_t *reg1, reg8_t *reg2);
void cpu_sub8(struct flags *flags, reg8_t *reg1, reg8_t *reg2);
void cpu_ssub8(struct flags *flags, reg8_t *reg1, reg8_t *reg2);
void cpu_mul8(struct flags *flags, reg8_t *reg1, reg8_t *reg2);
void cpu_smul8(struct flags *flags, reg8_t *reg1, reg8_t *reg2);
void cpu_div8(struct flags *flags, reg8_t *reg1, reg8_t *reg2);
void cpu_sdiv8(struct flags *flags, reg8_t *reg1, reg8_t *reg2);
void cpu_mod8(struct flags *flags, reg8_t *reg1, reg8_t *reg2);
void cpu_smod8(struct flags *flags, reg8_t *reg1, reg8_t *reg2);
void cpu_inc8(struct flags *flags, reg8_t *reg);
void cpu_dec8(struct flags *flags, reg8_t *reg);
void cpu_cmp8(struct flags *flags, reg8_t *reg1, reg8_t *reg2);

/* 16-bit instructions */
void cpu_mov16_rr(struct flags *flags, reg16_t *dst, reg16_t *src);
void cpu_mov16_ir(struct flags *flags, reg16_t *dst, word value);
void cpu_and16(struct flags *flags, reg16_t *reg1, reg16_t *reg2);
void cpu_or16(struct flags *flags, reg16_t *reg1, reg16_t *reg2);
void cpu_xor16(struct flags *flags, reg16_t *reg1, reg16_t *reg2);
void cpu_not16(struct flags *flags, reg16_t *reg);
void cpu_nand16(struct flags *flags, reg16_t *reg1, reg16_t *reg2);
void cpu_nor16(struct flags *flags, reg16_t *reg1, reg16_t *reg2);
void cpu_xnor16(struct flags *flags, reg16_t *reg1, reg16_t *reg2);
void cpu_shl16(struct flags *flags, reg16_t *reg);
void cpu_shr16(struct flags *flags, reg16_t *reg);
void cpu_add16(struct flags *flags, reg16_t *reg1, reg16_t *reg2);
void cpu_sadd16(struct flags *flags, reg16_t *reg1, reg16_t *reg2);
void cpu_sub16(struct flags *flags, reg16_t *reg1, reg16_t *reg2);
void cpu_ssub16(struct flags *flags, reg16_t *reg1, reg16_t *reg2);
void cpu_mul16(struct flags *flags, reg16_t *reg1, reg16_t *reg2);
void cpu_smul16(struct flags *flags, reg16_t *reg1, reg16_t *reg2);
void cpu_div16(struct flags *flags, reg16_t *reg1, reg16_t *reg2);
void cpu_sdiv16(struct flags *flags, reg16_t *reg1, reg16_t *reg2);
void cpu_mod16(struct flags *flags, reg16_t *reg1, reg16_t *reg2);
void cpu_smod16(struct flags *flags, reg16_t *reg1, reg16_t *reg2);
void cpu_inc16(struct flags *flags, reg16_t *reg);
void cpu_dec16(struct flags *flags, reg16_t *reg);
void cpu_cmp16(struct flags *flags, reg16_t *reg1, reg16_t *reg2);

/* 32-bit instructions */
void cpu_mov32_rr(struct flags *flags, reg32_t *dst, reg32_t *src);
void cpu_mov32_ir(struct flags *flags, reg32_t *dst, dword value);
void cpu_and32(struct flags *flags, reg32_t *reg1, reg32_t *reg2);
void cpu_or32(struct flags *flags, reg32_t *reg1, reg32_t *reg2);
void cpu_xor32(struct flags *flags, reg32_t *reg1, reg32_t *reg2);
void cpu_not32(struct flags *flags, reg32_t *reg);
void cpu_nand32(struct flags *flags, reg32_t *reg1, reg32_t *reg2);
void cpu_nor32(struct flags *flags, reg32_t *reg1, reg32_t *reg2);
void cpu_xnor32(struct flags *flags, reg32_t *reg1, reg32_t *reg2);
void cpu_shl32(struct flags *flags, reg32_t *reg);
void cpu_shr32(struct flags *flags, reg32_t *reg);
void cpu_add32(struct flags *flags, reg32_t *reg1, reg32_t *reg2);
void cpu_sadd32(struct flags *flags, reg32_t *reg1, reg32_t *reg2);
void cpu_sub32(struct flags *flags, reg32_t *reg1, reg32_t *reg2);
void cpu_ssub32(struct flags *flags, reg32_t *reg1, reg32_t *reg2);
void cpu_mul32(struct flags *flags, reg32_t *reg1, reg32_t *reg2);
void cpu_smul32(struct flags *flags, reg32_t *reg1, reg32_t *reg2);
void cpu_div32(struct flags *flags, reg32_t *reg1, reg32_t *reg2);
void cpu_sdiv32(struct flags *flags, reg32_t *reg1, reg32_t *reg2);
void cpu_mod32(struct flags *flags, reg32_t *reg1, reg32_t *reg2);
void cpu_smod32(struct flags *flags, reg32_t *reg1, reg32_t *reg2);
void cpu_inc32(struct flags *flags, reg32_t *reg);
void cpu_dec32(struct flags *flags, reg32_t *reg);
void cpu_cmp32(struct flags *flags, reg32_t *reg1, reg32_t *reg2);

/* 64-bit instructions */
void cpu_mov64_rr(struct flags *flags, reg64_t *dst, reg64_t *src);
void cpu_mov64_ir(struct flags *flags, reg64_t *dst, qword value);
void cpu_and64(struct flags *flags, reg64_t *reg1, reg64_t *reg2);
void cpu_or64(struct flags *flags, reg64_t *reg1, reg64_t *reg2);
void cpu_xor64(struct flags *flags, reg64_t *reg1, reg64_t *reg2);
void cpu_not64(struct flags *flags, reg64_t *reg);
void cpu_nand64(struct flags *flags, reg64_t *reg1, reg64_t *reg2);
void cpu_nor64(struct flags *flags, reg64_t *reg1, reg64_t *reg2);
void cpu_xnor64(struct flags *flags, reg64_t *reg1, reg64_t *reg2);
void cpu_shl64(struct flags *flags, reg64_t *reg);
void cpu_shr64(struct flags *flags, reg64_t *reg);
void cpu_add64(struct flags *flags, reg64_t *reg1, reg64_t *reg2);
void cpu_sadd64(struct flags *flags, reg64_t *reg1, reg64_t *reg2);
void cpu_sub64(struct flags *flags, reg64_t *reg1, reg64_t *reg2);
void cpu_ssub64(struct flags *flags, reg64_t *reg1, reg64_t *reg2);
void cpu_mul64(struct flags *flags, reg64_t *reg1, reg64_t *reg2);
void cpu_smul64(struct flags *flags, reg64_t *reg1, reg64_t *reg2);
void cpu_div64(struct flags *flags, reg64_t *reg1, reg64_t *reg2);
void cpu_sdiv64(struct flags *flags, reg64_t *reg1, reg64_t *reg2);
void cpu_mod64(struct flags *flags, reg64_t *reg1, reg64_t *reg2);
void cpu_smod64(struct flags *flags, reg64_t *reg1, reg64_t *reg2);
void cpu_inc64(struct flags *flags, reg64_t *reg);
void cpu_dec64(struct flags *flags, reg64_t *reg);
void cpu_cmp64(struct flags *flags, reg64_t *reg1, reg64_t *reg2);

/* Jump instructions */
void cpu_je(cpu_t *cpu, qword addr);
void cpu_jne(cpu_t *cpu, qword addr);
void cpu_jz(cpu_t *cpu, qword addr);
void cpu_jnz(cpu_t *cpu, qword addr);
void cpu_jl(cpu_t *cpu, qword addr);
void cpu_jle(cpu_t *cpu, qword addr);
void cpu_jg(cpu_t *cpu, qword addr);
void cpu_jge(cpu_t *cpu, qword addr);

#endif /* INSTRUCTIONS_H */

