#include "ops.h"

int exec_adc_common(struct nes_state *state, uint8_t operand, int pc_increment) {
    /* Increment PC */
    state->regs.PC += pc_increment; 

    /* sum = A + M + C */
    unsigned int sum = state->regs.A + operand + state->regs.SR.C;
    /* Set carry if sum is greater than 255 (0xff) */
    state->regs.SR.C = sum > 0xff;
    /* Set overflow if bit 7 was toggled */
    state->regs.SR.V = ((sum ^ state->regs.A) & 0x80) >> 7;
    /* Set negative flag if bit 7 is set */
    state->regs.SR.N = (sum & 0x80) >> 7;
    /* Set zero flag */
    state->regs.SR.Z = (sum & 0xff) == 0;
    
    /* store sum in accumulator */
    state->regs.A = sum & 0xff;

    return 0;
}

int exec_inc_common(struct nes_state *state, uint16_t operand, int pc_increment){
	
	state->regs.PC += pc_increment;

	/* Increment Memory by One: INC */
	/* M + 1 -> M */
	uint16_t address = operand;
	/* increment value at memory */
	state->ram[address]++;

	/* set negative flag if bit 7 is set */
	state->regs.SR.N = ((state->ram[address]) & 0x80) >> 7;
	/* set zero flag */
	state->regs.SR.Z = (state->ram[address]) == 0;
	return 0;
}

int exec_adc_imm(struct nes_state *state) {
    return exec_adc_common(state, state->rom[state->regs.PC + 1], 2);
}
