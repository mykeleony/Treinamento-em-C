/**************************************************************/
/* Gerador de números aleatórios portado de Java 8 para C.
/* 
/* Myke Leony dos Santos Amorim. 10 de janeiro de 2021.
/**************************************************************/

#include <stdio.h>
#include <stdlib.h>

long long seed;   // A seed é um inteiro de 64 bits (long long).

void setSeed (long long newSeed) {
  seed = (newSeed ^ 0x5DEECE66DLL) & ((1LL << 48) - 1);
}

int next(int bits) {
 seed = (seed * 0x5DEECE66DL + 0xBL) & ((1L << 48) - 1);
 return (int) (seed >> (48 - bits));
}

void main () {
  // Testagens:
	setSeed(8);

	for (int i=0; i < 16; i++)
	 printf ("%d\n", next(8));

	setSeed(0x0000000200000000LL);

	for (int i=0; i < 16; i++)
		printf ("%d\n", next(8));

	setSeed(0xFFFFFFFE00000000LL);

	for (int i=0; i < 16; i++)
		printf ("%d\n", next(8));
}
