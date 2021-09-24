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
void inicializarListaEncadeadaEstatica(LISTA *lista) {
  lista->inicio = -1;
  lista->dispo = 0;

  for(int i = 0; i < MAX-1; i++)
    lista->A[i].prox = i+1;

  lista->A[MAX-1].prox = -1;
}

// Imprime todos os elementos de uma determinada lista linear encadeada:
void exibirListaEncadeada(LISTA lista) {
  int i = lista.inicio;

  while (i > -1) {
    printf("%d ", lista.A[i].chave);
    i = lista.A[i].prox;
  }

  printf("\n");

}

// Retorna o número de elementos de uma dada lista linear encadeada:
int tamanhoListaEncadeada(LISTA lista) {
    int i = lista.inicio, contagem = 0;

    while (i > -1) {
        contagem++;
        i = lista.prox;
    }

    return contagem;
  }
}

// Retorna a chave do primeiro elemento de uma lista linear encadeada:
int chavePrimeiroElementoListaEncadeada(TIPOCHAVE chave, LISTA lista) {
  if (lista.inicio > -1)
    return lista.A[lista.inicio];
}

int main() {

}
