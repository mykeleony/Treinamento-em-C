/* Programa que realiza operações elementares em listas lineares encadeadas circulares com alocação dinâmica e nó cabeça.
   01 de outubro de 2021.
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
  NO* cabeca;    // Sentinela utilizada na busca com sentinela.
} LISTA;

// Cria uma lista vazia:
void inicializarListaEncadeadaDinamica (LISTA* lista) {
  lista->cabeca = (NO*) malloc(sizeof(NO));
  lista->cabeca->prox = lista->cabeca;  // Marca de uma lista vazia.
}

// Imprime o conteúdo de uma lista:
void imprimeListaEncadeadaDinamica (LISTA lista) {
  if (lista.cabeca->prox != lista.cabeca) {
    NO* i = lista.cabeca->prox;

    while (i != lista.cabeca) {
      printf("%d ", i->chave);  // Nesse caso, a chave é um número inteiro.
      i = i->prox;
    }
  }

  else
    printf("Lista vazia.");

  printf("\n");
}

// Retorna a chave do primeiro elemento da lista linear encadeada circular:
TIPOCHAVE chavePrimeiroElementoListaEncadeada (LISTA lista) {
  if (lista.cabeca->prox == lista.cabeca) {
    printf("Não há chaves na lista, pois ela está vazia.\n");
    return;
  }

  return lista.cabeca->prox->chave;
}

// Retorna a chave do último elemento da lista linear encadeada circular:
TIPOCHAVE chaveUltimoElementoListaEncadeada (LISTA lista) {
  NO* i = lista.cabeca->prox;

  if (i == lista.cabeca) {
    printf("Não há chaves na lista, pois ela está vazia.\n");
    return;
  }

  while (i->prox != lista.cabeca)
    i = i->prox;

  return i->chave;
  }
}

// Retorna o tamanho de uma lista linear encadeada circular com nó cabeça:
int tamanhoLista (LISTA lista) {
  int n = 0;
  NO* i = lista.cabeca->prox;

  while (i != lista.cabeca) {
    n++;

    i = i->prox;
  }

  return n;
}

// Retorna a chave do elemento em uma dada posição da lista linear encadeada circular com nó cabeça:
TIPOCHAVE chaveEnesimoElementoListaEncadeada (LISTA lista, int posicao) {
  NO* i = lista.cabeca->prox;
  int j = 1;

  while (i->prox != lista.cabeca && j < posicao) {
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

// Busca uma chave na lista linear encadeada dinâmica circular com nó cabeça e retorna sua posição (além do elemento anterior):
NO* buscaSequencialOrdenada (TIPOCHAVE chave, LISTA lista, NO* *anterior) {
  NO* i = lista.cabeca->prox;

  *anterior = lista.cabeca;

  lista.cabeca->chave = chave;

  while (i->chave < chave) {
    *anterior = i;
    i = i->prox;
  }

  if (i != lista.cabeca && i->chave == chave)
    return i;

  else {
    printf("A chave %d não foi encontrada na lista.\n", chave);
    return NULL;
  }
}

// Insere um elemento na lista linear encadeada sem repetição com sentinela:
bool inserirElementoListaEncadeadaOrdenada (TIPOCHAVE chave, LISTA lista*) {
  NO* elemento, anterior;

  elemento = buscaSequencialOrdenada(chave, *lista, &anterior);

  if(elemento)
    return false;

  novo = (NO*) malloc(sizeof(NO));
  novo->chave = chave;

  // Como a lista é circular e possui nó cabeça, não é necessária nenhuma testagem para inserir a chave - basta ajustar os ponteiros:
  novo->prox = anterior->prox;
  anterior->prox = novo;

  return true;
}

// Exclui um elemento específico da lista linear encadeada:
bool excluirElementoListaEncadeada(TIPOCHAVE chave, LISTA* lista) {
  NO* elemento, anterior;

  elemento = buscaSequencialOrdenada(chave, *lista, &anterior);

  if(elemento == NULL)
    return false;

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
