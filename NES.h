#include <stdint.h>

typedef struct{
	uint8_t A;		//acumulator register
	uint8_t X;		//index register
	uint8_t Y;		//index register
	uint8_t P;		//processor status		N V _ B D I Z C 	SEE NOTE*
	uint8_t sp;		//stack pointer
	uint16_t pc;	//program counter

} Nes;

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

//TODO: Define ISA prototype functions