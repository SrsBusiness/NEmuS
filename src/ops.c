#include "ops.h"
#include "mem.h"

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

int exec_clc(struct nes_state *state){
    /* Clear carry flag */

    state->regs.SR.C = 0;
    state->regs.PC++;
    return 0;
}

int exec_cld(struct nes_state *state){
    /* Clear decimal flag */

    state->regs.SR.D = 0;
    state->regs.PC++;
    return 0;
}

int exec_cli(struct nes_state *state){
    /* Clear interupt disable flag */

    state->regs.SR.I = 0;
    state->regs.PC++;
    return 0;
}

int exec_clv(struct nes_state *state){
    /* Clear overflow flag */

    state->regs.SR.V = 0;
    state->regs.PC++;
    return 0;
}

int exec_dex(struct nes_state *state) {
    /* Decrement X */
    state->regs.X--;
    state->regs.SR.N = (state->regs.X & 0x80) >> 7;
    state->regs.SR.Z = (state->regs.X & 0xff) == 0;
    state->regs.PC++;

    return 0;
}

int exec_dey(struct nes_state *state) {
    /* Decrement Y */
    state->regs.Y--;
    state->regs.SR.N = (state->regs.Y & 0x80) >> 7;
    state->regs.SR.Z = (state->regs.Y & 0xff) == 0;
    state->regs.PC++;

    return 0;
}

int exec_inc(struct nes_state *state, uint16_t operand, int pc_increment) {
    /* Increment Memory by One: INC */

    /* Increment PC */
    state->regs.PC += pc_increment;
    /* M + 1 -> M */
    uint16_t address = operand;
    /* increment value at memory */
    uint8_t value = mem_read(state, address) + 1;
    mem_write(state, address, value);
    /* set negative flag if bit 7 is set */
    state->regs.SR.N = (value & 0x80) >> 7;
    /* set zero flag */
    state->regs.SR.Z = (value) == 0;
    return 0;
}

int exec_inx(struct nes_state *state) {
    /* Increment X */
    state->regs.X++;
    state->regs.SR.N = (state->regs.X & 0x80) >> 7;
    state->regs.SR.Z = (state->regs.X & 0xff) == 0;
    state->regs.PC++;
    return 0;
}

int exec_iny(struct nes_state *state) {
    /* Increment Y */
    state->regs.Y++;
    state->regs.SR.N = (state->regs.Y & 0x80) >> 7;
    state->regs.SR.Z = (state->regs.Y & 0xff) == 0;
    state->regs.PC++;
    return 0;
}

int exec_nop(struct nes_state *state){
    state->regs.PC++;
    return 0;
}

int exec_sec(struct nes_state *state){
    /* Set carry flag */

    state->regs.SR.C = 1;
    state->regs.PC++;
    return 0;
}

int exec_sed(struct nes_state *state){
    /* Set decimal flag */

    state->regs.SR.D = 1;
    state->regs.PC++;
    return 0;
}

int exec_sei(struct nes_state *state){
    /* Set interupt disable flag */

    state->regs.SR.I = 1;
    state->regs.PC++;
    return 0;
}

int exec_tax(struct nes_state *state){
    /* Transfer Accumulator to X */

    state->regs.X = state->regs.A;
    state->regs.SR.N = (state->regs.X & 0x80) >> 7;
    state->regs.SR.Z = (state->regs.X & 0xff) == 0;
    state->regs.PC++;
    return 0;
}

int exec_tay(struct nes_state *state){
    /* Transfer Accumulator to Y */

    state->regs.Y = state->regs.A;
    state->regs.SR.N = (state->regs.Y & 0x80) >> 7;
    state->regs.SR.Z = (state->regs.Y & 0xff) == 0;
    state->regs.PC++;
    return 0;
}

int exec_tsx(struct nes_state *state){
    /* Transfer Stack Pointer to X */

    state->regs.X = state->regs.SP;
    state->regs.SR.N = (state->regs.X & 0x80) >> 7;
    state->regs.SR.Z = (state->regs.X & 0xff) == 0;
    state->regs.PC++;
    return 0;
}

int exec_txa(struct nes_state *state){
    /* Transfer X to Accumulator  */

    state->regs.A = state->regs.X;
    state->regs.SR.N = (state->regs.A & 0x80) >> 7;
    state->regs.SR.Z = (state->regs.A & 0xff) == 0;
    state->regs.PC++;
    return 0;
}

int exec_txs(struct nes_state *state){
    /* Transfer X to Stack Pointer */

    state->regs.SP = state->regs.X;
    state->regs.SR.N = (state->regs.SP & 0x80) >> 7;
    state->regs.SR.Z = (state->regs.SP & 0xff) == 0;
    state->regs.PC++;
    return 0;
}

int exec_tya(struct nes_state *state){
    /* Transfer Y to Accumulator  */

    state->regs.A = state->regs.Y;
    state->regs.SR.N = (state->regs.A & 0x80) >> 7;
    state->regs.SR.Z = (state->regs.A & 0xff) == 0;
    state->regs.PC++;
    return 0;
}

int exec_adc_imm(struct nes_state *state) {
    return exec_adc_common(state, state->rom[state->regs.PC + 1], 2);
}

uint16_t address_mode_imm(struct nes_state *state) {
    return state->rom[state->regs.PC + 1];
}
