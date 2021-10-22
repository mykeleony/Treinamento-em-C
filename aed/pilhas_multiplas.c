/* Programa que realiza operações elementares em pilhas múltiplas de implementação estática.
   15 de outubro de 2021.
   Myke Leony dos Santos Amorim - Bacharelado em Sistemas de Informação - EACH USP.
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define VALOR_INVALIDO -1
#define MAX 50

typedef int TIPOCHAVE;

typedef struct {
	TIPOCHAVE chave;
	// Futuros possíveis campos...
} REGISTRO;

typedef struct {
	int topo1;
  int topo2;
	REGISTRO A[MAX];
} PILHADUPLA;

// Inicializa uma pilha dupla vazia:
void inicializaPilhaDupla (PILHADUPLA* pilha) {
  pilha->topo1 == -1;
  pilha->topo2 == MAX;
}

// Retorna quantos elementos há ao todo nas duas pilhas:
int tamanhoPilhaDupla (PILHADUPLA pilha) {
  return pilha.topo1+1 + MAX-pilha.topo2;
}

// Imprime os elementos da pilha desejada (1 ou 2) na tela:
bool imprimePilhaDupla (PILHADUPLA* pilha, int n) {
  if (n < 1 || n > 2)
    return false;   // Pilha inexistente.

  printf("Pilha %d: \"", n);

  if (n == 1)
    for (int i = pilha->topo1; i >= 0; i--)
      printf("%d ", pilha->A[i].chave);

  else
    for (int i = pilha->topo2; i < MAX; i++)
      printf("%d ", pilha->A[i].chave);

  return true;
}

// Insere um elemento no topo da pilha estática dupla (empilha):
bool push (TIPOCHAVE chave, PILHADUPLA* pilha, int n) {
  if (n < 1 || n > 2 || tamanhoPilhaDupla(*pilha) == MAX) // Pilha inexistente ou pilha cheia.
    return false;

  if (n == 1) {
    pilha->topo1++;
    pilha->A[pilha->topo1].chave = chave;
  }

  else {
    pilha->topo2--;
    pilha->A[pilha->topo2].chave = chave;
  }

  return true;
}

// Remove o elemento do topo da pilha estática dupla (desempilha):
bool pop (PILHADUPLA* pilha, REGISTRO* registro, int n) {
  if (n < 1 || n > 2) // Pilha inexistente.
    return false;

  if (n == 1) {
    if(pilha->topo1 == -1)
      return false; // A pilha está vazia.

    *registro = pilha->A[pilha->topo1];

    pilha->topo1--;
  }

  else {
    if(pilha->topo2 == MAX)
      return false; // A pilha está vazia.

    *registro = pilha->A[pilha->topo2];

    pilha->topo1++;
  }

  return true;
}

// Reinicializa uma pilha existente do zero:
void reinicializaPilhaDupla (PILHADUPLA* pilha) {
  inicializaPilhaDupla(pilha);
}

void main() {
}
