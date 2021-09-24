#include <stdio.h>

// Tamanho máximo do valor estatico:
#define MAX 50

#define VALOR_INVALIDO -1

// Definição do tipo chave utilizando:
typedef int TIPOCHAVE;

typedef struct {
  TIPOCHAVE chave;
  int prox;         // Índice do próximo elemento da lista linear encadeada.
} REGISTRO;

typedef struct {
  REGISTRO A[MAX];
  int inicio;      // Índice do primeiro elemento da lista linear encadeadaa.
  int dispo;       // Índice do primeiro elemento da lista livre, de espaços disponíveis na lista linear.
} LISTA;

// Inicialização de listas:
void inicializarListaEncadeadaEstatica (LISTA *lista) {
  lista->inicio = -1;
  lista->dispo = 0;

  for (int i = 0; i < MAX-1; i++)
    lista->A[i].prox = i+1;

  lista->A[MAX-1].prox = -1;
}

// Imprime todos os elementos de uma determinada lista linear encadeada:
void exibirListaEncadeada (LISTA lista) {
  if (lista.inicio == -1) {
    printf("Lista vazia.\n");
    return;
  }

  int i = lista.inicio;

  while (i > -1) {
    printf("%d ", lista.A[i].chave);
    i = lista.A[i].prox;
  }

  printf("\n");
}

// Retorna o número de elementos de uma dada lista linear encadeada:
int tamanhoListaEncadeada (LISTA lista) {
    int i = lista.inicio, contagem = 0;

    while (i > -1) {
        contagem++;
        i = lista.prox;
    }

    return contagem;
  }
}

// Retorna a chave do primeiro elemento de uma lista linear encadeada:
TIPOCHAVE chavePrimeiroElementoListaEncadeada (LISTA lista) {
  if (lista.inicio > -1)
    return lista.A[lista.inicio];

  printf("Não há elementos nesta lista.\n");
}

// Retorna a chave do último elemento de uma lista linear encadeada:
TIPOCHAVE chaveUltimoElementoListaEncadeada (LISTA lista) {
  if (lista.inicio > -1) {
    int i = lista.inicio;

    while(i > -1) {
      if(lista.A[i].prox == -1)
        return lista.A[i].chave;

      i = lista.A[i].prox;
    }
  }

  printf("Não há elementos nesta lista.\n")
}

// Retorna a chave no enésimo elemento de uma determinada lista linear encadeada:
TIPOCHAVE chaveQualquerElementoListaEncadeada (int posicao, LISTA lista) {
  if (lista.inicio > -1 && posicao >= 0 && posicao < MAX) {
    int i = lista.inicio;

    while (i != posicao)
      i = lista.A[i].prox;

    return lista.A[i].chave;
  }

  else
    printf("Posição inserida inválida ou lista vazia.\n");
}

// Exclui uma determinada lista linear encadeada:
void destruirListaEncadeadaEstatica(LISTA *lista) {
  lista->inicio = -1;
  lista->disp = -1;
}

int posicaoChaveOrdenada(TIPOCHAVE chave, LISTA lista) {
  int i = lista.inicio;

  while(i != -1 && lista.A[i].chave < chave)
    i = lista.A[i].prox;

  if (i != -1 && lista.A[i].chave == chave)
    return i;

  return -1;
}

int main() {

}
