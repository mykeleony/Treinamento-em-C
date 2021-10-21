/* Programa que realiza operações elementares em filas de aplicação dinâmica.
   08 de outubro de 2021.
   Myke Leony dos Santos Amorim - Bacharelado em Sistemas de Informação - EACH USP.
*/

#include <stdio.h>
#include <stdlib.h>

#define VALOR_INVALIDO -1

typedef int TIPOCHAVE;

typedef struct estrutura {
  TIPOCHAVE chave;
  struct estrutura *prox;
} NO;

typedef struct {
  NO* inicio;
  NO* fim;
} FILA;

// Cria uma fila dinâmica vazia:
void inicializaFila (FILA* fila) {
  fila->inicio = NULL;
  fila->fim = NULL;
}

// Informa quantos elementos existem em uma fila dinâmica:
int tamanhoFila (FILA fila) {
  int n = 0;

  NO* i = fila.inicio;

  while(i) {
    n++;
    i = i->prox;
  }

  return n;
}

// Insere um elemento no fim da fila:
void entrarElemento (TIPOCHAVE chave, FILA* fila) {
  novo = (NO*) malloc(sizeof(NO));

  novo->chave = chave;
  novo->prox = NULL;

  if (fim->prox)
    fila->fim->prox = novo; // A fila não está vazia.

  else
    fila->inicio = novo;  // O elemento a ser inserido é o primeiro da fila (a fila, antes da inserção, está vazia).

  fila->fim = novo;
}

// Remove o primeiro elemento da fila e retorna sua chave (se a remoção a ser feita é em uma lista vazia, o retorno é -1 - o valor inválido):
TIPOCHAVE retiraElemento (FILA* fila) {
  NO* primeiro;
  TIPOCHAVE chave;

  if (fila->inicio == NULL)
    return VALOR_INVALIDO;

  primeiro = fila->inicio;
  chave = primeiro->chave;

  fila->inicio = fila->inicio->prox;

  free(primeiro);

  if (fila->inicio == NULL)
    fila->fim == NULL;  // A fila ficou vazia após a remoção.

  return chave;
}
