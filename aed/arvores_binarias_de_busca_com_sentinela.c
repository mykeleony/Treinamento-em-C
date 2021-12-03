/* Programa que realiza operações elementares em árvores binárias de busca com nó sentinela.
   19 de novembro de 2021.
   Myke Leony dos Santos Amorim - Bacharelado em Sistemas de Informação - EACH USP.
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define VALOR_INVALIDO -1

typedef int TIPOCHAVE;

typedef enum {esq, dir} LADO; // Numeração dos filhos esquerdo e direito de um nó.

typedef struct estrutura {
  TIPOCHAVE chave;
  struct estrutura* esq;
  struct estrutura* dir;
} NO;

typedef struct {
  NO* raiz;
  NO* sentinela;
} ARVORE;

// Estruturas auxiliares:
typedef struct estruct {
  NO* no;
  struct estruct* prox;
} F;

typedef struct {
  F* inicio;
  F* fim;
} FILA;

// Cria uma fila dinâmica vazia:
void inicializaFila (FILA* fila) {
  fila->inicio = NULL;
  fila->fim = NULL;
}

// Insere um elemento no fim da fila de nós:
void entrarFila (NO* no, FILA* fila) {
  F* novo = (F*) malloc(sizeof(F));

  novo->no = no;
  novo->prox = NULL;

  if (fila->fim)
    fila->fim->prox = novo; // A fila não está vazia.

  else
    fila->inicio = novo;  // O elemento a ser inserido é o primeiro da fila (a fila, antes da inserção, está vazia).

  fila->fim = novo;
}

// Remove um elemento da fila de nós:
NO* retirarFila (FILA* fila) {
  F* primeiro;
  NO* elemento;

  if (fila->inicio == NULL)
    return NULL;

  elemento = fila->inicio->no;
  primeiro = fila->inicio;

  fila->inicio = fila->inicio->prox;

  free(primeiro);

  if (fila->inicio == NULL)
    fila->fim == NULL;  // A fila ficou vazia após a remoção.

  return elemento;
}

// Cria uma árvore binária dinâmica vazia:
void inicializaArvore (ARVORE* arv) {
  arv->sentinela = (NO*) malloc(sizeof(NO));
  arv->sentinela->esq = NULL;
  arv->sentinela->dir = NULL;

  arv->raiz = arv->sentinela;
}

// Informa se uma árvore está vazia:
bool arvoreVazia (ARVORE arv) {
  return (arv.raiz == arv.sentinela);
}

// Percorre a árvore binária em pré-ordem (raiz, esquerda e direita) de maneira recursiva:
void preOrdem (ARVORE arv, NO* no) {
  if (no != arv.sentinela) {
    printf("%d ", no->chave);  // Visita ao nó.
    preOrdem(arv, no->esq);
    preOrdem(arv, no->dir);
  }
}

// Percorre a árvore binária em ordem simétrica (esquerda, raiz e direita):
void emOrdem (NO* no) {
  if (no) {
    emOrdem(no->esq);
    printf("%d ", no->chave);
    emOrdem(no->dir);
  }
}

// Percorre a árvore binária em pós-ordem (esquerda, direita e raiz):
void posOrdem (NO* no) {
  if (no) {
    posOrdem(no->esq);
    posOrdem(no->dir);
    printf("%d ", no->chave);
  }
}

// Percorre a árvore binária em largura (por níveis):
void emLargura (ARVORE arv, NO* raiz) {
  FILA fila;
  inicializaFila(&fila);

  NO* i = raiz;

  while (i != arv.sentinela) {
    printf("%d ", i->chave);  // Visita ao nó é a impressão de sua chave.

    if (i->esq) // Os nós de cada nível são visitados sempre da esquerda para a direita.
      entrarFila(i->esq, &fila);

    if (i->dir)
      entrarFila(i->dir, &fila);

    i = retirarFila(&fila); // Saída retorna um NO* (não vazia) ou NULL (vazia).
  }
}

// Retorna o menor elemento nas subárvores de um dado nó:
NO* menorElemento (ARVORE arv, NO* raiz) {
  NO* i = raiz;

  while (i->esq != arv.sentinela)
    i = i->esq;

  return i;
}

// Retorna o maior elemento nas subárvores de um dado nó:
NO* maiorElemento (ARVORE arv, NO* raiz) {
  NO* i = raiz; // Caso a árvore esteja vazia, o nó sentinela é retornado.

  while (i->dir != arv.sentinela)
    i = i->dir;

  return i;
}


// Função auxiliar à função de busca pelo nível de um nó:
void travessia (NO* atual, int *nivel, TIPOCHAVE chave, bool *achou) {
  if (atual) {
    *nivel += 1;

    if (atual->chave == chave)
      *achou = true;

    else {
      travessia(atual->esq, nivel, chave, achou);

      if ((!*achou))
        travessia(atual->dir, nivel, chave, achou);

      if ((!*achou))
        *nivel -= 1;
    }
  }
}

// Retorna o nível ao qual o nó de uma determinada chave pertence:
int nivel (NO* raiz, TIPOCHAVE chave) {
  int nivel = 0;
  bool achou = false;

  travessia(raiz, &nivel, chave, &achou);

  return nivel;
}

// Função semelhante à travessia, mas que armazena o nó pai do nó que contém a chave buscada:
void travessiaPai (NO* atual, TIPOCHAVE chave, NO* *pai, bool *achou) {
  if (atual) {
    if (atual->esq)
      if (atual->esq->chave == chave) {
        *achou = true;
        *pai = atual;
      }

    if (!*achou)
      if (atual->dir)
        if (atual->dir->chave) {
          *achou = true;
          *pai = atual;
        }

    if (!*achou)
      travessiaPai(atual->esq, chave, pai, achou);

    if(!*achou)
      travessiaPai(atual->dir, chave, pai, achou);
  }
}

// Retorna o nó pai do nó que contém uma dada chave:
NO* buscaPai (NO* raiz, TIPOCHAVE chave) {
  bool achou = false;
  NO* pai;

  if (raiz) {
    if (raiz->chave == chave)
      return NULL;

    travessiaPai(raiz, chave, &pai, &achou);

    return pai;
  }
}

// Retorna o nó que contém uma dada chave ao realizar uma busca binária com sentinela (também armazena o nó pai).
NO* buscaNo(ARVORE arv, TIPOCHAVE chave, NO* *pai) {
  NO* atual = arv.raiz;

  *pai = NULL;

  while (atual->chave != chave) {
    *pai = atual;

    if (chave < atual->chave)
      atual = atual->esq;

    else
      atual = atual->dir;
  }

  if (atual == arv.sentinela)
    return NULL;

  else
    return atual;
}

// Insere um nó em uma árvore binária de busca (sem repetição):
NO* insereNo (ARVORE arv, NO* raiz, TIPOCHAVE chave) {
  if (raiz == arv.sentinela) {
    NO* novo = (NO*) malloc(sizeof(NO));

    novo->chave = chave;
    novo->esq = arv.sentinela;
    novo->dir = arv.sentinela;

    return novo;
  }

  if (chave < raiz->chave)
    raiz->esq = insereNo(arv, raiz->esq, chave);

  else if (chave > raiz->chave) // Duplicatas de chaves são ignoradas. Para permití-las, basta mudar o operador ">" para ">=".
    raiz->dir = insereNo(arv, raiz->dir, chave);

  return raiz;
}

// Exclui o nó de uma dada chave iterativamente e retorna a "nova" raiz da árvore com nó sentinela.
NO* removeNo (ARVORE arv, NO* raiz, TIPOCHAVE chave) {
  NO* pai;
  NO* no;
  NO* p;
  NO* q;

  no = buscaNo(arv, chave, &pai);

  if (!no)
    return raiz;  // A chave buscada não existe na árvore.

  if (no->esq == arv.sentinela || no->dir == arv.sentinela) { // Verifica se o elemento a excluir possui 1 ou nenhum filho.
    if (no->esq == arv.sentinela)
      q = no->dir;

    else
      q = no->esq;
  }

  else {  // O elemento a excluir possui 2 filhos.
    p = no;
    q = no->esq;  // Buscando o maior elemento da subárvore esquerda ao elemento a excluir.

    while (q->dir != arv.sentinela) {
      p = q;
      q = q->dir;
    }

    if (p != no) {
      p->dir = q->esq;
      q->esq = no->esq;
    }

    q->dir = no->dir;
  }

  if (!pai) {
    free(no);
    return q;
  }

  if (chave < pai->chave)
    pai->esq = q;

  else
    pai->dir = q;

  free(no);

  return raiz;
}


// Descarta uma árvore binária:
void destroiArvore (ARVORE arv, NO* *atual) {
  if (*atual != arv.sentinela) {  // Evita ponteiro para endereço inválido.
    destroiArvore(arv, &(*atual)->esq);
    destroiArvore(arv, &(*atual)->dir);
    printf("Nó de chave %d destruído.\n", (*atual)->chave);
    free(*atual);  // A visita realiza uma liberação de memória.
  }

  *atual = NULL;  // Ao fim, o nó sentinela é destruído.
}

void main() {
  /*
  // Testagens:
  ARVORE a;

  inicializaArvore(&a);

  for (int i = 1; i < 10; i++)
    a.raiz = insereNo(a, a.raiz, i);

  printf("Árvore binária em forma de vetor: ");
  preOrdem(a, a.raiz);
  printf("\n");
  printf("Removendo elemento de: %d\n", removeNo(a, a.raiz, 2)->chave);
  printf("Maior chave da árvore: %d\n", maiorElemento(a, a.raiz)->chave);
  printf("Menor chave da árvore: %d\n", menorElemento(a, a.raiz)->chave);

  destroiArvore(a, &(a.raiz));
  */
}
