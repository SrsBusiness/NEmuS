#include "mem.h"
#include "NES.h"

#define RAM_ADDR_MASK 0x07ff

/*
 * $0000-$07FF  $0800   2KB internal RAM
 * $0800-$0FFF  $0800   Mirrors of $0000-$07FF
 * $1000-$17FF  $0800
 * $1800-$1FFF  $0800
 * $2000-$2007  $0008   NES PPU registers
 * $2008-$3FFF  $1FF8   Mirrors of $2000-2007 (repeats every 8 bytes)
 * $4000-$4017  $0018   NES APU and I/O registers
 * $4018-$401F  $0008   APU and I/O functionality that is normally disabled. See CPU Test Mode.
 * $4020-$FFFF  $BFE0   Cartridge space: PRG ROM, PRG RAM, and mapper registers (See Note)
 *
 */
uint8_t mem_read(struct nes_state *n, uint16_t addr) {
    switch(addr >> 12) { /* Switch on the most significant nibble */
        case 0:
            return n->ram[addr & RAM_ADDR_MASK];
        case 2:
            /* PPU registers */
            return 0;
        default: /* 0x4000 and above */
            if (addr < 0x4018) {
                /* NES APU and I/O Registers */
                return 0;
            } else if (addr < 0x4020) {
                /* More APU and I/O stuff */
                return 0;
            } else {
                /* Cartridge/Mapper space */
                return n->mapper_read(n, addr);
            }
            break;
    }
}

void mem_write(struct nes_state *n, uint16_t addr, uint8_t data) {
    switch(addr >> 12) { /* Switch on the most significant nibble */
        case 0:
            n->ram[addr & RAM_ADDR_MASK] = data;
            break;
        case 2:
            /* PPU registers */
            break;
        default: /* 0x4000 and above */
            if (addr < 0x4018) {
                /* NES APU and I/O Registers */
            } else if (addr < 0x4020) {
                /* More APU and I/O stuff */
            } else {
                /* Cartridge/Mapper space */
                n->mapper_write(n, addr, data);
            }
            break;
    }
}
