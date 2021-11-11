#include <stdio.h>
#include <stdlib.h>

typedef int TIPOINFO;

typedef struct estrutura {
	int linha;	// Os nós são organizados pela linha, depois pela coluna.
	int coluna;
	TIPOINFO info;
	struct estrutura *prox;
} NO;

typedef struct {
	NO* inicio;
} MATRIZ;
