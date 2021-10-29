/* Programa que realiza operações elementares em deques (Double Ended Queues - Fila Duplamente Terminada) de implementação dinâmica.
   22 de outubro de 2021.
   Myke Leony dos Santos Amorim - Bacharelado em Sistemas de Informação - EACH USP.
*/

#include <stdio.h>
#include <stdlib.h>

#define VALOR_INVALIDO -1

typedef int TIPOCHAVE;

typedef struct estrutura {
  TIPOCHAVE chave;
  struct estrutura *ant;
  struct estrutura *prox;
  // Outros campos...
} NO;

typedef struct {
  NO* inicio1;
  NO* inicio2;
} DEQUE;

// Cria um deque vazio:
void inicializaDeque (DEQUE* deque) {
  deque->inicio1 = NULL;
  deque->inicio2 = NULL;
}

// Retorna o número de elementos existentes em um deque:
int tamanhoDeque (DEQUE deque) {
  int n = 0;

  NO* i = deque.inicio1;

  while (i) {
    n++;
    i = i->prox;
  }

  return n;
}

// Insere um elemento na primeira ponta (inicio1) de um deque:
void inserirDeque1 (TIPOCHAVE chave, DEQUE* deque) {
  NO* novo = (NO*) malloc(sizeof(NO));

  novo->chave = chave;
  novo->ant = NULL;
  novo->prox = deque->inicio1;

  if (deque->inicio1)
    deque->inicio1->ant = novo; // O deque não estava vazio antes da inserção.

  else
    deque->inicio2 = novo;  // Primeira inserção no deque.

  deque->inicio1 = novo;
}

// Remove um elemento da primeira ponta (inicio1) de um deque e retorna a chave do elemento excluído:
TIPOCHAVE retirarDeque1 (DEQUE* deque) {
  if (deque->inicio1 == NULL)
    return VALOR_INVALIDO;

  NO* elemento_a_excluir = deque->inicio1;
  TIPOCHAVE chave_a_excluir = elemento_a_excluir->chave;

  deque->inicio1 = deque->inicio1->prox;

  free(elemento_a_excluir);

  if (deque->inicio1 == NULL)
    deque->inicio2 = NULL;  // Após a remoção, o deque ficou vazio.

  else
    deque->inicio1->ant == NULL;  // O deque ainda possui elementos após a remoção.

  return chave_a_excluir;
}

// Exclui todos os elementos de um deque:
void destroiDeque (DEQUE* deque) {
  while (deque->inicio1)
    retirarDeque1(deque);
}

void main() {
}
