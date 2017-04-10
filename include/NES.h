#ifndef NES_H
#define NES_H

#include <stdint.h>

#define KILOBYTE (1 << 10) /* 2**10 = 1024 */
#define MEGABYTE (KILOBYTE * KILOBYTE)

#define NES_RAM_SIZE (2 * KILOBYTE)

struct nes_regs {
    uint8_t A;		//acumulator register
	uint8_t X;		//index register
	uint8_t Y;		//index register
	struct {
        uint8_t N : 1, V : 1, : 1, B : 1, D : 1, I : 1, Z : 1, C : 1;
    } SR;		//processor status		N V _ B D I Z C 	SEE NOTE*
	uint8_t SP;		//stack pointer
	uint16_t PC;	//program counter
};

/* Not a fan of personally of typedef for struct types. However, there are
 * definitely 2 sides to this battle:
 * https://stackoverflow.com/questions/252780/why-should-we-typedef-a-struct-so-often-in-c
 * https://www.kernel.org/doc/Documentation/process/coding-style.rst
 */
typedef struct nes_state {
    struct nes_regs regs;
    uint8_t ram[2 * KILOBYTE];  /* placeholder for now */

    /* Placeholders until we understand how ROM works */
    uint8_t rom[MEGABYTE];
} Nes; 

/* struct nes_state n = NES_INITIAL_STATE; */
#define NES_INITIAL_STATE {                                             \
    .regs = {                                                           \
        .A = 0,                                                         \
        .X = 0,                                                         \
        .Y = 0,                                                         \
        .SR = {                                                         \
            .N = 0,                                                     \
            .V = 0,                                                     \
            .B = 0,                                                     \
            .D = 0,                                                     \
            .I = 0,                                                     \
            .Z = 0,                                                     \
            .C = 0,                                                     \
        },                                                              \
        .SP = 0,                                                        \
        .PC = 0,                                                        \
    }                                                                   \
}

/*
 * NOTE: flag codes are as follows:
 * N - Negative flag is set if 1
 * V - Overflow flag
 * B - Break flag set if BRK command is executed
 * D - Decimal mode flag
 * I - Interrupt disable
 * Z - Zero flag set if result of last operation was 0
 * C - Carry flag set if overflow or underflow from operation
 */

#endif
