#include <stdio.h>

// Tamanho máximo do valor estatico:
#define MAX 50

// Definição do tipo chave utilizando:
typedef int TIPOCHAVE;

typedef struct {
	TIPOCHAVE chave;
	// Futuros novos campos...
} REGISTRO;

// Implementação de listas lineares sequenciais estáticas:
typedef struct {
	REGISTRO A[MAX];
	int nroElem;     // Número de elementos da lista naquele determinado instante.
} LISTA;

// Estabelece o número de elementos inicial da lista (0):
void inicializarListaVazia (LISTA* l) {   // O ponteiro é utilizado para a lista copiada (por ser passagem por valor) não ser destruída ao término da função.
  l->nroElem = 0;
}

// Fornece o número de elementos de uma dada lista linear sequencial:
int tamanhoLista(LISTA l) {
  return l.nroElem;
}

// Imprime cada elemento de uma dada lista:
void imprimeLista(LISTA l) {
  if(l.nroElem <= 0)
    printf("Lista vazia.\n");

  for(int i = 0; i < l.nroElem; i++) {
    printf("%d, ", l.A[i].chave);
  }
}

int main() {
  // Testando a função de inicialização da lista linear sequencial:
  LISTA listaExemplo;
  inicializarListaVazia(&listaExemplo);

  // Testando a função de tamanho da lista linear sequencial:
  printf("Tamanho da lista: %d\n", tamanhoLista(listaExemplo));

  // Testando a função de impressão de elementos da lista linear sequencial:
  imprimeLista(listaExemplo);

  return 0;
}
