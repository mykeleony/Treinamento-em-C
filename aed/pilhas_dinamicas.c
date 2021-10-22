/* Programa que realiza operações elementares em pilhas de implementação dinâmica.
   15 de outubro de 2021.
   Myke Leony dos Santos Amorim - Bacharelado em Sistemas de Informação - EACH USP.
*/

#include <stdio.h>
#include <stdlib.h>

#define VALOR_INVALIDO -1;

typedef int TIPOCHAVE;

typedef struct estrutura {
  TIPOCHAVE chave;
  struct estrutura *prox;
} NO;

typedef struct {
  NO* topo;
} PILHA;

// Cria uma pilha vazia:
void inicializaPilha (PILHA* pilha) {
  pilha->topo = NULL;
}

// Retorna o número de elementos de uma pilha:
int tamanhoPilha (PILHA pilha) {
  int n = 0;
  NO* i = pilha.topo;

  while (i) {
    n++;
    i = i->prox;
  }

  return n;
}

// Insere um elemento no topo da pilha (empilha):
void push (TIPOCHAVE chave, PILHA* pilha) {
  NO* novo = (NO*) malloc(sizeof(NO));

  novo->chave = chave;
  novo->prox = pilha->topo;

  pilha->topo = novo;
}

// Remove o elemento do topo da pilha (desempilha):
TIPOCHAVE pop (PILHA* pilha) {
  if (pilha->topo == NULL)  // Se a pilha está vazia, nada há a desempilhar.
    return VALOR_INVALIDO;

  TIPOCHAVE chave_excluida = pilha->topo->chave;
  NO* topo_antigo = pilha->topo;

  pilha->topo = pilha->topo->prox;

  free(topo_antigo);

  return chave_excluida;
}

void main() {
}
