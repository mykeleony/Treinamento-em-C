/* Programa que realiza operações elementares em árvores balanceadas AVL.
   26 de novembro de 2021.
   Myke Leony dos Santos Amorim - Bacharelado em Sistemas de Informação - EACH USP.
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int TIPOCHAVE;
typedef char BOOL;

#define VALOR_INVALIDO -2
#define TRUE 'V'
#define FALSE 'F'

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

// Percorre a árvore AVL (raiz, esquerda e direita) de maneira recursiva:
void preOrdem (NO* no) {
  if (no) {
    printf("%d ", no->chave);  // Visita ao nó.
    preOrdem(no->esq);
    preOrdem(no->dir);
  }
}

// Percorre a árvore em ordem simétrica (esquerda, raiz e direita):
void emOrdem (NO* no) {
  if (no) {
    emOrdem(no->esq);
    printf("%d ", no->chave);
    emOrdem(no->dir);
  }
}

// Percorre a árvoreem pós-ordem (esquerda, direita e raiz):
void posOrdem (NO* no) {
  if (no) {
    posOrdem(no->esq);
    posOrdem(no->dir);
    printf("%d ", no->chave);
  }
}

// Retorna a altura de uma árvore ou subárvore:
int h (NO* raiz) {
  if (raiz == NULL)
    return 0;  // Árvore ou subárvore vazia.

  else {
    // A altura é dada pela MAIOR das subárvores:
    if (h(raiz->esq) > h(raiz->dir))
      return h(raiz->esq)+1;   // A adição é necessária pois o valor retornado na visita ao último elemento da subárvore é -1.

    else
      return h(raiz->dir)+1;
  }
}

// Retorna o fator de balanceamento de um nó, calculado pela diferença entre as alturas da subárvore direita e esquerda deste.
int balanceamento (NO* no) {
  return h(no->dir) - h(no->esq);
}

void imprimeAVL (NO* raiz) {
  if (!raiz) {

    return;
  }

  printf("%d", raiz->chave);

  if (raiz->esq || raiz->dir) {
    printf("(");

    if (!raiz->esq)
      printf(")");

    imprimeAVL(raiz->esq);

    if (!raiz->dir)
      printf("()");

    else
      printf("(");

    imprimeAVL(raiz->dir);

    printf(")");
  }

  else
    printf(")");
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

// Funções auxiliares à inserção:

// Para preservar o fator de balanceamento AVL, rotaciona à direita do nó p e retorna a nova raiz:
NO* rotacaoDireita(NO* p) {
  NO* u = p->esq; // A árvore esquerda está desbalanceada.

  p->esq = u->dir;
  u->dir = p;

  p->bal = 0;
  u->bal = 0;

  return u;
}

// Rotaciona à esquerda do nó p e retorna a nova raiz:
NO* rotacaoEsquerda(NO* p) {
  NO* u = p->dir;

  p->dir = u->esq;
  u->esq = p;

  p->bal = 0;
  u->bal = 0;

  return u;
}

NO* rotacaoAuxiliarEsquerda (NO* p) {
  NO* u = p->esq;
  u->dir = p;
  u->bal = 1;

  return u;
}

NO* rotacaoAuxiliarDireita (NO* p) {
  NO* u = p->dir;

  p->dir = u->esq;
  u->esq = p;

  u->bal = -1;

  return u;
}

// Rotaciona à direita e, em seguida, à esquerda do nó p e retorna a nova raiz:
NO* duplaRotacaoDE(NO* p) {
  NO* u = p->dir;
  NO* v = u->esq;

  u->esq = v->dir;
  p->dir = v->esq;
  v->esq = p;
  v->dir = u;

  // Atualizando o balanceamento em função do nó v:
  switch (v->bal) {
    case -1:  p->bal = 0;
              u->bal = 1;

              break;

    case 0:   p->bal = 0;
              u->bal = 0;

              break;

    case 1:   p->bal = -1;
              u->bal = 0;

              break;
  }

  v->bal = 0;

  return v;
}

NO* duplaRotacaoED(NO* p) {
  NO* u = p->esq;
  NO* v = u->dir;

  u->dir = v->esq;
  p->esq = v->dir;
  v->dir = p;
  v->esq = u;

  // Atualizando o balanceamento em função do nó v:
  switch (v->bal) {
    case -1:  p->bal = 1;
              u->bal = 0;
              break;

    case 0:   p->bal = 0;
              u->bal = 0;
              break;

    case 1:   p->bal = 0;
              u->bal = -1;
              break;
  }

  v->bal = 0;


  return v;
}

NO* insereAVL (NO* p, TIPOCHAVE chave, bool* ajustar) {
  if (!p) {
    p = (NO*) malloc(sizeof(NO));

    p->esq = NULL;
    p->dir = NULL;    // Todo novo nó é uma folha.
    p->chave = chave;
    p->bal = 0;

    *ajustar = true;
  }

  else {
    if (chave == p->chave)
      *ajustar = false;

    else if (chave < p->chave) {
      p->esq = insereAVL(p->esq, chave, ajustar);

      if(*ajustar)
        switch(p->bal) {
          case -1:  if (p->esq->bal == -1)
                      p = rotacaoDireita(p);

                    else if (p->esq->bal == 1)
                      p = duplaRotacaoED(p);

                    else
                      p = rotacaoAuxiliarEsquerda(p);

                    *ajustar = false;

                    break;

          case 0:   p->bal = -1;
                    break;

          case 1:   p->bal = 0;
                    *ajustar = false;

                    break;
        }
    }

    else {
      p->dir = insereAVL(p->dir, chave, ajustar);

      if(*ajustar) {
        switch(p->bal) {
          case 1:  if (p->dir->bal == 1)
                      p = rotacaoEsquerda(p);

                    else if (p->dir->bal == -1)
                      p = duplaRotacaoDE(p);

                    else
                      p = rotacaoAuxiliarDireita(p);

                    *ajustar = false;
                    break;

          case 0:   p->bal = 1;
                    break;

          case -1:  p->bal = 0;
                    *ajustar = false;

                    break;
        }
      }
    }
  }

  return p;
}

void removeAVL() {
  
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
  // Testagens:
  NO* raiz;

  inicializaAVL(&raiz);

  bool ajustar = false;

  /*
  // Árvore 1:
  raiz = insereAVL(raiz, 65, &ajustar);

  printf("%d\n", raiz->chave);

  raiz = insereAVL(raiz, 34, &ajustar);
  raiz = insereAVL(raiz, 83, &ajustar);
  raiz = insereAVL(raiz, 15, &ajustar);
  raiz = insereAVL(raiz, 50, &ajustar);
  raiz = insereAVL(raiz, 22, &ajustar);
  raiz = insereAVL(raiz, 72, &ajustar);
  raiz = insereAVL(raiz, 88, &ajustar);
  raiz = insereAVL(raiz, 96, &ajustar);
  raiz = insereAVL(raiz, 43, &ajustar);
  */

  /*
  // Árvore 2:
  raiz = insereAVL(raiz, 3, &ajustar);
  raiz = insereAVL(raiz, 2, &ajustar);
  raiz = insereAVL(raiz, 1, &ajustar);
  raiz = insereAVL(raiz, 4, &ajustar);
  raiz = insereAVL(raiz, 5, &ajustar);
  raiz = insereAVL(raiz, 6, &ajustar);
  raiz = insereAVL(raiz, 7, &ajustar);

  //printf("%d\n", ehAVL(raiz));
  printf("("); imprimeAVL(raiz);
  printf("\n");
  */

  /*
  //Árvore 3:
  raiz = insereAVL(raiz, 10, &ajustar);
  raiz = insereAVL(raiz, 9, &ajustar);
  raiz = insereAVL(raiz, 8, &ajustar);
  raiz = insereAVL(raiz, 7, &ajustar);
  raiz = insereAVL(raiz, 11, &ajustar);
  raiz = insereAVL(raiz, 12, &ajustar);
  raiz = insereAVL(raiz, 13, &ajustar);
  raiz = insereAVL(raiz, 6, &ajustar);
  raiz = insereAVL(raiz, 5, &ajustar);
  raiz = insereAVL(raiz, 14, &ajustar);
  raiz = insereAVL(raiz, 0, &ajustar);
  raiz = insereAVL(raiz, 50, &ajustar);
  */

  /*
  // Árvore 4:
  raiz = insereAVL(raiz, 3, &ajustar);
  raiz = insereAVL(raiz, 5, &ajustar);
  raiz = insereAVL(raiz, 15, &ajustar);
  raiz = insereAVL(raiz, 4, &ajustar);
  raiz = insereAVL(raiz, 2, &ajustar);
  raiz = insereAVL(raiz, 18, &ajustar);
  raiz = insereAVL(raiz, 7, &ajustar);
  raiz = insereAVL(raiz, 21, &ajustar);
  raiz = insereAVL(raiz, 8, &ajustar);
  raiz = insereAVL(raiz, 22, &ajustar);

  printf("("); imprimeAVL(raiz); printf("\n");

  removeAVL(&raiz, 5, &ajustar);

  printf("("); imprimeAVL(raiz); printf("\n");

  printf("%c\n", ehAVL(raiz));
  */


  // Árvore 5:
  NO* a = criaNO(3);
  a->esq = criaNO(2);
  a->esq->esq = criaNO(1);

  printf("("); imprimeAVL(a); printf("\n");

  printf("%c", ehAVL(a));
  printf("\n");


  destroiAVL(&raiz);
}
