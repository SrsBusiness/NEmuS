#ifndef OPS_H
#define OPS_H

#include "NES.h"

/* TODO: Define ISA prototype functions */

/* Addressing Modes:
 * ----------------------
 * | Mode     | SUFFIX  |
 * |----------|---------| 
 * | A        | A       |
 * | abs      | ABS     |
 * | abs,X    | ABS_X   |
 * | abs,Y    | ABS_Y   |
 * | #        | IMM     |
 * | impl     | IMPL    |
 * | ind      | IND     |
 * | X,ind    | IND_X   |
 * | ind,Y    | IND_Y   |
 * | rel      | REL     |
 * | zpg      | ZPG     |
 * | zpg,X    | ZPG_X   |
 * | zpg,Y    | ZPG_Y   |
 * ----------------------
 */

/* TODO: There are patterns here */
enum NES_OPCODES {
    /* ADC - Add Memory to Accumulator with Carry */
    ADC_IND_X   = 0x61,
    ADC_ZPG     = 0x65,
    ADC_IMM     = 0x69,
    ADC_ABS     = 0x6d,
    ADC_IND_Y   = 0x71,
    ADC_ZPG_X   = 0x75,
    ADC_ABS_Y   = 0x79,
    ADC_ABS_X   = 0x7d,
    /* ADC - Add Memory to Accumulator with Carry */
    AND_IND_X   = 0x21,
    AND_ZPG     = 0x25,
    AND_IMM     = 0x29,
    AND_ABS     = 0x2d,
    AND_IND_Y   = 0x31,
    AND_ZPG_X   = 0x35,
    AND_ABS_Y   = 0x39,
    AND_ABS_X   = 0x3d,
    /* ASL - Shift Left One Bit (Memory or Accumulator) */
    ASL_ZPG     = 0x06,
    ASL_A       = 0x0a,
    ASL_ABS     = 0x0e,
    ASL_ZPG_X   = 0x16,
    ASL_ABS_X   = 0x1e,
    /* BCC - Branch on Carry Clear */
    BCC_REL     = 0x90,
    /* BCS - Branch on Carry Set */
    BCS_REL     = 0xb0,
    /* BEQ - Branch on Result Zero */
    BEQ_REL     = 0xf0,
    /* BIT - Test Bits in Memory with Accumulator */
    BIT_ZPG     = 0x24,
    BIT_ABS     = 0x2c,
    /* BMI - Branch on Result Minus */
    BMI_REL     = 0x30,
    /* BNE - Branch on Result not Zero */
    BNE_REL     = 0xd0,
    /* BPL - Branch on Result Plus */
    BPL_REL     = 0x10,
    /* BRK - Force Break */
    BRK_IMPL    = 0x00,
    /* BVC - Branch on Overflow Clear */
    BVC_REL     = 0x50,
    /* BVS - Branch on Overflow Set */
    BVS_REL     = 0x70,
    /* CLC - Clear Carry Flag */
    CLC_IMPL    = 0x18,
    /* CLD - Clear Decimal Mode */
    CLD_IMPL    = 0xd8,
    /* CLI - Clear Interrupt Disable Bit */
    CLI_IMPL    = 0x58,
    /* CLV - Clear Overflow Flag */
    CLV_IMPL    = 0xb8,
    /* CMP - Compare Memory with Accumulator */
    CMP_IND_X   = 0xc1,
    CMP_ZPG     = 0xc5,
    CMP_IMM     = 0xc9,
    CMP_ABS     = 0xcd,
    CMP_IND_Y   = 0xd1,
    CMP_ZPG_X   = 0xd5,
    CMP_ABS_Y   = 0xd9,
    CMP_ABS_X   = 0xdd,
    /* CPX - Compare Memory and Index X */
    CPX_IMM     = 0xe0,
    CPX_ZPG     = 0xe4,
    CPX_ABS     = 0xec,
    /* CPY - Compare Memory and Index Y */
    CPY_IMM     = 0xc0,
    CPY_ZPG     = 0xc4,
    CPY_ABS     = 0xcc,
    /* DEC - Decrement Memory by One */
    DEC_ZPG     = 0xc6,
    DEC_ZPG_X   = 0xd6,
    DEC_ABS     = 0xce,
    DEC_ABS_X   = 0xde,
    /* DEX - Decrement Index X by One */
    DEX_IMPL    = 0xca,
    /* DEY - Decrement Index Y by One */
    DEY_IMPL    = 0x88,
    /* EOR - XOR Memory with Accumulator */
    EOR_IND_X   = 0x41,
    EOR_ZPG     = 0x45,
    EOR_IMM     = 0x49,
    EOR_ABS     = 0x4d,
    EOR_IND_Y   = 0x51,
    EOR_ZPG_X   = 0x55,
    EOR_ABS_Y   = 0x59,
    EOR_ABS_X   = 0x5d,
    /* INC - Increment Memory by One */
    INC_ZPG     = 0xe6,
    INC_ZPG_X   = 0xf6,
    INC_ABS     = 0xee,
    INC_ABS_X   = 0xfe,
    /* INX - Increment Index X by One */
    INX_IMPL    = 0xe8,
    /* INY - Increment Index Y by One */
    INY_IMPL    = 0xc8,
    /* JMP - Jump to New Location */
    JMP_ABS     = 0x4c,
    JMP_IND     = 0x6c,
    /* JSR - Jump to New Location Saving Return Address */
    JSR_ABS     = 0x20,
    /* LDA - Load Accumulator with Memory */
    LDA_IND_X   = 0xa1,
    LDA_ZPG     = 0xa5,
    LDA_IMM     = 0xa9,
    LDA_ABS     = 0xad,
    LDA_IND_Y   = 0xb1,
    LDA_ZPG_X   = 0xb5,
    LDA_ABS_Y   = 0xb9,
    LDA_ABS_X   = 0xbd,
    /* LDX - Load Index X with Memory */
    LDX_IMM     = 0xa2,
    LDX_ZPG     = 0xa6,
    LDX_ABS     = 0xae,
    LDX_ZPG_Y   = 0xb6,
    LDX_ABS_Y   = 0xbe,
    /* LDY - Load Index Y with Memory */
    LDY_IMM     = 0xa0,
    LDY_ZPG     = 0xa4,
    LDY_ABS     = 0xac,
    LDY_ZPG_X   = 0xb4,
    LDY_ABS_X   = 0xbc,
    /* LSR - Shift One Bit Right (Memory or Accumulator) */
    LSR_A       = 0x4a,
    LSR_ZPG     = 0x46,
    LSR_ZPG_X   = 0x56,
    LSR_ABS     = 0x4e,
    LSR_ABS_X   = 0x5e,
    /* NOP - No Operation */
    NOP_IMPL    = 0xea,
    /* ORA - Or Memory with Accumulator */
    ORA_IND_X   = 0x01,
    ORA_ZPG     = 0x05,
    ORA_IMM     = 0x09,
    ORA_ABS     = 0x0d,
    ORA_IND_Y   = 0x11,
    ORA_ZPG_X   = 0x15,
    ORA_ABS_Y   = 0x19,
    ORA_ABS_X   = 0x1d,
    /* PHA - Push Accumulator on Stack */
    PHA_IMPL    = 0x48,
    /* PHP - Push Processor Status on Stack */
    PHP_IMPL    = 0x08,
    /* PLA - Pull Accumulator from Stack */
    PLA_IMPL    = 0x68,
    /* PLP - Pull Processor Status from Stack */
    PLP_IMPL    = 0x28,
    /* ROL - Rotate One Bit Left (Memory or Accumulator) */
    ROL_ZPG     = 0x26,
    ROL_A       = 0x2a,
    ROL_ABS     = 0x2e,
    ROL_ZPG_X   = 0x36,
    ROL_ABS_X   = 0x3e,
    /* ROR - Rotate One Bit Right (Memory or Accumulator) */
    ROR_ZPG     = 0x66,
    ROR_A       = 0x6a,
    ROR_ABS     = 0x6e,
    ROR_ZPG_X   = 0x76,
    ROR_ABS_X   = 0x7e,
    /* RTI - Return from Interrupt */
    RTI_IMPL    = 0x40,
    /* RTS - Return from Subroutine */
    RTS_IMPL    = 0x60,
    /* SBC - Subtract Memory from Accumulator with Borrow */
    SBC_IND_X   = 0xe1,
    SBC_ZPG     = 0xe5,
    SBC_IMM     = 0xe9,
    SBC_ABS     = 0xed,
    SBC_IND_Y   = 0xf1,
    SBC_ZPG_X   = 0xf5,
    SBC_ABS_Y   = 0xf9,
    SBC_ABS_X   = 0xfd,
    /* SEC - Set Carry Flag */
    SEC_IMPL    = 0x38,
    /* SED - Set Decimal Flag */
    SED_IMPL    = 0xf8,
    /* SEI - Set Interrupt Disable Status */
    SEI_IMPL    = 0x78,
    /* STA - Store Accumulator in Memory */
    STA_IND_X   = 0x81,
    STA_ZPG     = 0x85,
    STA_ABS     = 0x8d,
    STA_IND_Y   = 0x91,
    STA_ZPG_X   = 0x95,
    STA_ABS_Y   = 0x99,
    STA_ABS_X   = 0x9d,
    /* STX - Store Index X in Memory */
    STX_ZPG     = 0x86,
    STX_ZPG_Y   = 0x96,
    STX_ABS     = 0x8e,
    /* STY - Store Index Y in Memory */
    STY_ZPG     = 0x84,
    STY_ZPG_X   = 0x94,
    STY_ABS     = 0x8c,
    /* TAX - Transfer Accumulator to Index X */
    TAX_IMPL    = 0xaa,
    /* TAY - Transfer Accumulator to Index Y */
    TAY_IMPL    = 0xa8,
    /* TSX - Transfer Stack Pointer to Index X */
    TSX_IMPL    = 0xba,
    /* TXA - Transfer Index X to Accumulator */
    TXA_IMPL    = 0x8a,
    /* TXS - Transfer Index X to Stack Pointer */
    TXS_IMPL    = 0x9a,
    /* TYA - Transfer Index Y to Accumulator */
    TYA_IMPL    = 0x98,
};

int exec_adc_imm(struct nes_state *state);

#endif
