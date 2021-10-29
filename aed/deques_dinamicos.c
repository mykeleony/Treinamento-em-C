/* Programa que realiza operações elementares em deques de implementação dinâmica.
   22 de outubro de 2021.
   Myke Leony dos Santos Amorim - Bacharelado em Sistemas de Informação - EACH USP.
*/

#include <stdio.h>
#include <stdlib.h>

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

  NO* i = deque->inicio1;

  while (i) {
    n++;
    i = i->prox;
  }

  return n;
}

// Insere um elemento na primeira ponta (inicio1) de um deque:
void inserirDeque1 (TIPOCHAVE chave, DEQUE* deque) {
}

void main() {
}
