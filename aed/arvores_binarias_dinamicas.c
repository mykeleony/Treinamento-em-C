/* Programa que realiza operações elementares em árvores binárias de implementação dinâmica.
   16 de novembro de 2021.
   Myke Leony dos Santos Amorim - Bacharelado em Sistemas de Informação - EACH USP.
*/

#include <stdio.h>
#include <stdlib.h>

typedef int TIPOCHAVE;

typedef struct estrutura {
  TIPOCHAVE chave;
  struct estrutura* esq;
  struct estrutura* dir;
} NO;

// Cria uma árvore binária dinâmica vazia:
void inicializaArvore (NO* *raiz) {
  *raiz = NULL;
}
