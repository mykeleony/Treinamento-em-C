/* Programa que realiza operações elementares em árvores balanceadas AVL.
   26 de novembro de 2021.
   Myke Leony dos Santos Amorim - Bacharelado em Sistemas de Informação - EACH USP.
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int TIPOCHAVE;

typedef struct estrutura {
  TIPOCHAVE chave;
  int bal;  // Fator de balanceamento com os valores (-1, 0, 1) possíveis.
  struct estrutura *esq;
  struct estrutura *dir;
} NO;

// Cria uma árvore AVL vazia:
void inicializaAVL (NO* *raiz) {
  *raiz = NULL;
}

// Informa se uma árvore AVL está vazia:
bool avlVazia (NO* raiz) {
  if (raiz)
    return false;

  return true;
}

// Verifica se uma árvore é AVL:
bool ehAVL (NO* raiz) {
  if (raiz) {
    if(raiz->bal < -1 || raiz->bal > 1)
      return false;

    if(raiz->esq)
      if(raiz->esq->chave > raiz->chave)
        return false;

    if(raiz->dir)
      if(raiz->dir->chave < raiz->chave)
        return false;

    ehAVL(raiz->esq);
    ehAVL(raiz->dir);
  }

  return true;
}

// Destrói uma árvore AVL:
void destroiAVL (NO* *atual) {
  if (*atual) {  // Evita ponteiro para endereço inválido.
    destroiAVL(&(*atual)->esq);
    destroiAVL(&(*atual)->dir);
    printf("Nó de chave %d destruído.\n", (*atual)->chave);
    free(*atual);  // A visita realiza uma liberação de memória.
  }

  *atual = NULL;  // Ao fim, a raíz da árvore é destruída.
}

void main() {
  /*
  // Testagens:
  NO* raiz;

  inicializaAVL(&raiz);

  printf("%d\n", ehAVL(raiz));

  destroiAVL(&raiz);
  */
}
