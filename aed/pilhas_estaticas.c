/* Programa que realiza operações elementares em pilhas de aplicação estática (com vetores).
   15 de outubro de 2021.
   Myke Leony dos Santos Amorim - Bacharelado em Sistemas de Informação - EACH USP.
*/

#include <stdio.h>
#include <stdbool.h>

#define VALOR_INVALIDO -1
#define MAX 50

typedef int TIPOCHAVE;

typedef struct {
	TIPOCHAVE chave;
	// Futuros possíveis campos...
} REGISTRO;

typedef struct {
	int topo;
	REGISTRO A[MAX];
} PILHA;

// Inicializa uma pilha estática vazia:
void inicializaPilhaEstatica (PILHA *pilha) {
  pilha->topo = -1;
}

// Imprime as chaves dos elementos de uma pilha:
void imprimePilhaEstatica (PILHA pilha) {
  for (int i = pilha.topo; i > -1; i--)
    printf("%d\n", pilha.A[i].chave);

  printf("------------------------------\n");
}

// Informa se uma pilha estática está ou não completa:
bool pilhaCheia (PILHA pilha) {
  if (pilha.topo >= MAX-1)
    return true;

  return false;
}

// Insere um elemento no topo da pilha estática (empilha):
bool push (TIPOCHAVE chave, PILHA* pilha) {
  if (pilhaCheia(*pilha)) // Se a pilha está cheia, não é possível inserir nenhum elemento a mais.
    return false;

  pilha->topo++;
  pilha->A[pilha->topo].chave = chave;

  return true;
}

// Remove o elemento do topo da pilha estática (desempilha):
TIPOCHAVE pop (PILHA* pilha) {
  if (pilha->topo < 0)  // Se a pilha está vazia, não há nada a excluir.
    return VALOR_INVALIDO;

  TIPOCHAVE chave_excluida = pilha->A[pilha->topo].chave;

  pilha->topo--;

  return chave_excluida;
}

void main() {
  // Testagem das funções:
  PILHA pilha;

  inicializaPilhaEstatica(&pilha);

  for(int i = 1; i < 11; i++)
    push(i, &pilha);

  imprimePilhaEstatica(pilha);

  printf("%d\n\n", pop(&pilha));

  imprimePilhaEstatica(pilha);
}
