/* Programa que realiza operações elementares em matrizes esparsas ordenadas por linhas.
   29 de outubro de 2021.
   Myke Leony dos Santos Amorim - Bacharelado em Sistemas de Informação - EACH USP.
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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

// Retorna se a matriz esparsa é a melhor escolha de estrutura em uma determinada situação:
bool matrizEsparsaEficiente (int max_linhas, int max_colunas, int elementos_nao_nulos) {
	int t_matriz_tradicional = max_linhas * max_colunas * sizeof(TIPOINFO);	// Memória ocupada por uma matriz tradicional
	int t_matriz_linhas = elementos_nao_nulos*(2*sizeof(int) + sizeof(TIPOINFO) + sizeof(struct estrutura*));

	printf("%d\n", t_matriz_tradicional);
	printf("%d\n", t_matriz_linhas);

	if (t_matriz_tradicional < t_matriz_linhas || t_matriz_tradicional == t_matriz_linhas)
		return false;

	return true;
}

void main() {
}
