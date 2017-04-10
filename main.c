#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <time.h>
#include "NES.h"


int print(struct nes_state *nes);

int main(){
    Nes nes = NES_INITIAL_STATE;
	print(&nes);
	return 0;
}

int print(struct nes_state *nes){
	return printf("A = %d\nX = %d\nY = %d\n",nes->regs.A, nes->regs.X, nes->regs.Y);
}
