#ifndef MEM_H
#define MEM_H

#include "NES.h"
#include <stdint.h>

uint8_t mem_read(struct nes_state *n, uint16_t addr);
void mem_write(struct nes_state *n, uint16_t addr, uint8_t data);

#endif
