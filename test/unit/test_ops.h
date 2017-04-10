#include "ops.h"
#include <stdint.h>

/* Normal add: 0x17 + 0x1c + 1 */
void test_exec_adc_imm(void **state) {
    struct nes_state nes_state = NES_INITIAL_STATE; 
    nes_state.rom[0] = 0x69;
    nes_state.rom[1] = 0x17; /* 23 */
    nes_state.regs.A = 28;
    nes_state.regs.SR.C = 1;

    exec_adc_imm(&nes_state);

    assert_int_equal(nes_state.regs.PC, 0x02);
    assert_int_equal(nes_state.regs.A, 52); 
    assert_int_equal(nes_state.regs.SR.C, 0);
    assert_int_equal(nes_state.regs.SR.V, 0);
    assert_int_equal(nes_state.regs.SR.N, 0);
    assert_int_equal(nes_state.regs.SR.Z, 0);
}

/* 248 + 28 = 28 - 8 */
void test_exec_adc_imm_carry(void **state) {
    struct nes_state nes_state = NES_INITIAL_STATE; 
    nes_state.rom[0] = 0x69;
    nes_state.rom[1] = 0xf8; /* 248 (-8) */
    nes_state.regs.A = 28;
    nes_state.regs.SR.C = 0;

    exec_adc_imm(&nes_state);

    assert_int_equal(nes_state.regs.PC, 0x02);
    assert_int_equal(nes_state.regs.A, 0x14); 
    assert_int_equal(nes_state.regs.SR.C, 1);
    assert_int_equal(nes_state.regs.SR.V, 0);
    assert_int_equal(nes_state.regs.SR.N, 0);
    assert_int_equal(nes_state.regs.SR.Z, 0);
}

/* 248 + 7 = 7 - 8 */
void test_exec_adc_imm_overflow_negative(void **state) {
    struct nes_state nes_state = NES_INITIAL_STATE; 
    nes_state.rom[0] = 0x69;
    nes_state.rom[1] = 0xf8; /* 248 (-8) */
    nes_state.regs.A = 7;
    nes_state.regs.SR.C = 0;

    exec_adc_imm(&nes_state);

    assert_int_equal(nes_state.regs.PC, 0x02);
    assert_int_equal(nes_state.regs.A, 0xff); 
    assert_int_equal(nes_state.regs.SR.C, 0);
    assert_int_equal(nes_state.regs.SR.V, 1);
    assert_int_equal(nes_state.regs.SR.N, 1);
    assert_int_equal(nes_state.regs.SR.Z, 0);
}

/* 248 + 8 = 8 - 8 */
void test_exec_adc_imm_zero(void **state) {
    struct nes_state nes_state = NES_INITIAL_STATE; 
    nes_state.rom[0] = 0x69;
    nes_state.rom[1] = 0xf8; /* 248 (-8) */
    nes_state.regs.A = 8;
    nes_state.regs.SR.C = 0;

    exec_adc_imm(&nes_state);

    assert_int_equal(nes_state.regs.PC, 0x02);
    assert_int_equal(nes_state.regs.A, 0x00); 
    assert_int_equal(nes_state.regs.SR.C, 1);
    assert_int_equal(nes_state.regs.SR.V, 0);
    assert_int_equal(nes_state.regs.SR.N, 0);
    assert_int_equal(nes_state.regs.SR.Z, 1);
}
