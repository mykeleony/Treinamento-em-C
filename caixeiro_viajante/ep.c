#include "ep.h"

int *grauDoVertice;
int *arestaUsada;  // flag que informa se uma aresta está sendo usada no caminho que está sendo construído ou não. Ao final, se o algoritmo chegar a uma solução, este array conterá essa solução.

char *autor (void) {
	return "Myke Leony dos Santos Amorim; 12543721";
}

int ehSolucao (struct grafo *G) {
	for (int i = 0; i < G->N; i++)
		if (grauDoVertice[i] != 2)
			return 0; // não coberto ou completou o circuito com vértice errado.

	return 1;
}

int ehAceitavel (struct grafo *G, int arestaATestar, int verticeAtual) {
	if (arestaUsada[arestaATestar])
		return 0;   // aresta a testar está em uso. Não é aceitável

	if (G->A[3*arestaATestar] == verticeAtual) // arestaATestar conecta no vértice atual
		if (grauDoVertice[G->A[3*arestaATestar+1]] < 2) // vértice no outro extremo da aresta não é coberto.
			return 1; // é aceitável

	if (G->A[3*arestaATestar+1] == verticeAtual) // arestaATestar conecta no vértice atual.
		if (grauDoVertice[G->A[3*arestaATestar]] < 2) // vértice no outro extremo da aresta não é coberto.
			return 1; // é aceitável

	return 0;
}

/* Parte do pressuposto que arestaAcrescentar é aceitável. */
int aumentaCaminho (struct grafo *G, int arestaAcrescentar, int verticeAtual) {  // registra movimento
	arestaUsada[arestaAcrescentar]=1;   // TRUE: agora está em uso.

	grauDoVertice[G->A[3*arestaAcrescentar+1]]++;
	grauDoVertice[G->A[3*arestaAcrescentar]]++;

	if (G->A[3*arestaAcrescentar] == verticeAtual) // ajusta o lado
		return G->A[3*arestaAcrescentar+1];

	return G->A[3*arestaAcrescentar];
}

int backtrack (struct grafo *G, int verticeAtual) {
  /* inicializa seleção de movimentos; */
  int iAresta = 0;

	if (ehAceitavel (G, iAresta, verticeAtual)) {
		/* registra movimento; */
		verticeAtual = aumentaCaminho (G, iAresta, verticeAtual);

		if (ehSolucao(G)) {
			puts ("Achou solução");
			return 1;
		}
	}

	else {
		for(int i = iAresta; i < G->M; i++) {
			iAresta++;
			backtrack(G, iAresta);
		}
	}
}

/*
int backtrack (struct grafo *G, int verticeAtual ) {
  // inicializa seleção de movimentos;
  int iAresta=0;

	if (ehAceitavel (G, iAresta, verticeAtual) ) {
		// registra movimento;
		verticeAtual = aumentaCaminho (G, iAresta, verticeAtual);

		if (ehSolucao(G)) {
			puts ("Achou solução");
			return 1;
		}
	}

	else {
		for(int i = iAresta; i < G->M; i++) {
			iAresta++;
			backtrack(G, iAresta);
		}
	}
}
*/

int iniciaEexecuta(struct grafo *G, int verticeInicial) {
	grauDoVertice = calloc(G->N, sizeof(int)); // necessário inicializar com zeros;
  arestaUsada = calloc(G->M, sizeof(int));    // necessário inicializar com zeros;

	// Como o circuito Hamiltoniano inclui todos os vértices do grafo, tanto faz por onde começa.
  int r = backtrack(G, verticeInicial);

	for (int i=0; i<G->M; i++) {  /**< ATENÇÃO: TEM QUE TER ESTA PARTE PARA A RESPOSTA PODER SER CORRIGIDA!! */
	// como arestausada não é restaurada no retorno da recursão, quando acha o circuito, posso passar para o imprimeMermaid.
		G->S[i]=arestaUsada[i];
	}

	return r;
}

void termina() {
	free (grauDoVertice);
	free (arestaUsada);
}
