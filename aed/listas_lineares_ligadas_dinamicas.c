/* Programa que realiza operações elementares em listas lineares encadeadas com alocação dinâmica.
   17 de setembro de 2021.
   Myke Leony dos Santos Amorim - Bacharelado em Sistemas de Informação - EACH USP.
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Tamanho máximo do valor estatico:
#define MAX 50

#define VALOR_INVALIDO -1

// Definição do tipo chave utilizando:
typedef int TIPOCHAVE;

typedef struct estrutura {
  TIPOCHAVE chave;
  struct estrutura *prox;
  // Outros campos...
} NO;

typedef struct {
  NO* inicio;
  NO* sentinela;    // Sentinela utilizada na busca com sentinela.
} LISTA;

// Cria uma lista vazia:
void inicializarListaEncadeadaDinamica (LISTA* lista) {
  lista->sentinela = (NO*) malloc(sizeof(NO));
  lista->inicio = lista->sentinela;
}

// Imprime o conteúdo de uma lista:
void imprimeListaEncadeadaDinamica (LISTA lista) {
  if (lista.inicio != lista.sentinela) {
    NO* i = lista.inicio;

    while (i != lista.sentinela) {         // Equivalente ao comando while(i != NULL).
      printf("%d ", i->chave);
      i = i->prox;
    }
  }

  else
    printf("Lista vazia.");

  printf("\n");
}

// Retorna a chave do primeiro elemento da lista linear encadeada:
TIPOCHAVE chavePrimeiroElementoListaEncadeada (LISTA lista) {
  if (lista.inicio == lista.sentinela)
    return NULL;

  return lista.inicio->chave;
}

// Retorna a chave do último elemento da lista linear encadeada:
TIPOCHAVE chaveUltimoElementoListaEncadeada (LISTA lista) {
  if (lista.inicio != lista.sentinela) {
    NO* i = lista.inicio;

    if (i == lista.sentinela) {
      printf("A lista está vazia.\n");
      return;
    }

    while (i->prox != lista.sentinela)
      i = i->prox;

    return i->chave;
  }
}

// Retorna o tamanho de uma lista linear encadeada com sentinela:
int tamanhoLista (LISTA lista) {
  int n = 0;
  NO* i = lista.inicio;

  while (i != lista.sentinela) {
    n++;

    i = i->prox;
  }

  return n;
}

// Retorna a chave do elemento em uma dada posição da lista linear encadeada com nó sentinela:
TIPOCHAVE chaveEnesimoElementoListaEncadeada (LISTA lista, int posicao) {
  NO* i = lista.inicio;
  int j = 1;

  if (i == lista.sentinela) {
    printf("Lista vazia.\n");
    return;
  }

    while (i->prox != lista.sentinela && j < posicao) {
      i = i->prox;
      j++;
    }

  if (j != posicao) {
    printf("A posição inserida é inválida ou a lista está vazia.\n");
    return;
  }

  else
    return i->chave;
}

// Busca uma chave na lista linear encadeada dinâmica com sentinela e retorna sua posição (além do elemento anterior):
NO* buscaSequencialOrdenada (TIPOCHAVE chave, LISTA lista, NO* *anterior) {
  NO* i = lista.inicio;
  *anterior = NULL;

  lista.sentinela->chave = chave;

  while (i->chave < chave) {
    *anterior = i;
    i = i->prox;
  }

  if (i != lista.sentinela && i->chave == chave)
    return i;

  else
    return NULL;
}

// Insere um elemento na lista linear encadeada sem repetição com sentinela:
bool inserirElementoListaEncadeadaOrdenada (TIPOCHAVE chave, LISTA lista*) {
  NO* elemento, anterior;

  elemento = buscaSequencialOrdenada(chave, *lista, &anterior);

  if(elemento)
    return false;

  novo = (NO*) malloc(sizeof(NO));

  novo->chave = chave;

  if(lista->inicio == lista->sentinela) {
    // O elemento inserido será o primeiro elemento de uma lista recém inicicializada:
    lista->inicio = novo;
    novo->prox = lista->sentinela;
  }

  else {
    if(anterior == NULL) {
      // O elemento inserido será o primeiro elemento de uma lista já existente, por ser o menor deles:
      novo->prox = lista->inicio;
      lista->inicio = novo;
    }

    else {
      // O elemento será inserido no meio de dois elementos:
      novo->prox = anterior->inicio;
      anterior->inicio = novo;
    }
  }

  return true;
}

// Exclui um elemento específico da lista linear encadeada:
bool excluirElementoListaEncadeada(TIPOCHAVE chave, LISTA* lista) {
  NO* elemento, anterior;

  elemento = buscaSequencialOrdenada(chave, *lista, &anterior);

  if(elemento == NULL)
    return false;

  if(anterior == NULL)
    lista->inicio = elemento->prox;

  else
    anterior->prox = elemento->prox;

  free(elemento);

  return true;
}

// Insere um elemento na última posição da lista linear encadeada:
void anexarElementoListaEncadeada (TIPOCHAVE chave, LISTA *lista) {
  NO* elemento, anterior;

  anterior = ultimoElementoLista(*l);

  elemento = (NO*) malloc(sizeof(NO));

  elemento->chave = chave;
  elemento->prox = lista->sentinela;

  if(anterior == NULL)
    lista->inicio = novo;

  else
    anterior->prox = novo;
}


// Destrói uma lista linear encadeada com sentinela:
void destruirListaEncadeadaDinamica (LISTA* lista) {
  NO* atual = lista->inicio, prox;

  while (atual != lista->sentinela) {
    prox = atual->prox;   // Preserva a posição seguinte.

    free(atual);          // Libera a memória alocada pela estrutura atual.

    atual = prox;         // Ajusta o início da lista (vazia).
  }

  lista->inicio = lista->sentinela;
}

int main() {
}
