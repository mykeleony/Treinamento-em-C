/* Programa que realiza operações elementares em árvores binárias de implementação dinâmica.
   16 de novembro de 2021.
   Myke Leony dos Santos Amorim - Bacharelado em Sistemas de Informação - EACH USP.
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int TIPOCHAVE;

typedef enum {esq, dir} LADO; // Numeração dos filhos esquerdo e direito de um nó.

typedef struct estrutura {
  TIPOCHAVE chave;
  struct estrutura* esq;
  struct estrutura* dir;
} NO;

// Cria uma árvore binária dinâmica vazia:
void inicializaArvore (NO* *raiz) {
  *raiz = NULL;
}

// Informa se uma árvore está vazia:
bool arvoreVazia (NO* raiz) {
  if (!raiz)
    return true;

  return false;
}

// Insere um nó em uma árvore binária comum (sem ordenação):
bool inserirNo (NO* *raiz, NO* pai, TIPOCHAVE chave, LADO posicao) {
  if (pai && (posicao == esq && pai->esq || posicao == dir && pai->dir)) // Caso a posição a inserir já esteja ocupada, não é possível inserir.
    return false;

  NO* elemento = (NO*) malloc(sizeof(NO));

  elemento->chave = chave;
  elemento->esq = NULL;
  elemento->dir = NULL;

  if (!pai)  // Inserindo uma nova raiz ou atualiza a antiga.
    *raiz = elemento;

  else if (posicao == esq)
    pai->esq = elemento;

  else
    pai->dir = elemento;

  return true;
}

void main() {
}
