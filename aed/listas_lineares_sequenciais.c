/* Programa que realiza operações elementares em listas lineares sequenciais.
   13 de setembro de 2021.
   Myke Leony dos Santos Amorim - Bacharelado em Sistemas de Informação - EACH USP.
*/ 

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
	REGISTRO elementos[MAX];
	int nroElem;     // Número de elementos da lista naquele determinado instante.
} LISTA;

// Estabelece o número de elementos inicial da lista (0):
void inicializarListaVazia (LISTA* lista) {   // O ponteiro é utilizado para a lista copiada (por ser passagem por valor) não ser destruída ao término da função.
  lista->nroElem = 0;
}

// Fornece o número de elementos de uma dada lista linear sequencial:
int tamanhoLista(LISTA lista) {
  return lista.nroElem;
}

// Imprime cada elemento de uma dada lista:
void imprimeLista(LISTA lista) {
  if(lista.nroElem <= 0)
    printf("Lista vazia.\n");

  for(int i = 0; i < lista.nroElem; i++) {
    printf("%d, ", lista.elementos[i].chave);
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
