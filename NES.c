#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <time.h>
#include "NES.h"

Nes nes;

int init();
int print();

int main(){
	init();
	print();
	return 0;
}

int init(){
	
	nes.A = 0;
	nes.X = 0;
	nes.Y = 0;
	return 0;
}

int print(){
	printf("A = %d\nX = %d\nY = %d\n",nes.A, nes.X, nes.Y);
}