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

void inicializarLista (int tamanho, LISTA* lista) {
  lista->nroElem = tamanho;
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

  printf("\n");
}

// Fornece o primeiro elemento de uma dada lista:
int primeiroElementoLista(LISTA lista) {
  return lista.elementos[0].chave;
}

// Fornece o último elemento de uma dada lista:
int ultimoElementoLista(LISTA lista) {
  int indice_ultimo_elemento = (lista.nroElem)-1;

  return lista.elementos[indice_ultimo_elemento].chave;
}

// Fornece o n-ésimo elemento de uma dada lista:
int qualquerElementoLista(int n, LISTA lista) {
  return lista.elementos[n-1].chave;
}

// Destrói uma lista. Como a alocação utilizada para os elementos é estática, basta definir o número de elementos como zero.
// OBS: No caso de alocação dinâmica, basta utilizar a função free().
void destroiLista(LISTA* lista) {
  lista->nroElem = 0;
}

int main() {
  // Testando as funções:
  LISTA listaExemplo;
  inicializarLista(10, &listaExemplo);

  printf("Tamanho da lista: %d\n", tamanhoLista(listaExemplo));

  imprimeLista(listaExemplo);

  printf("Primeiro elemento da lista: %d\n", primeiroElementoLista(listaExemplo));

  printf("Ultimo elemento da lista: %d\n", ultimoElementoLista(listaExemplo));

  printf("%do elemento da lista: %d\n", 4, qualquerElementoLista(4, listaExemplo));

  destroiLista(&listaExemplo);

  imprimeLista(listaExemplo);
	
  return 0;
}
