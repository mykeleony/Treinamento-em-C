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

// Inicialização:
void inicializarListaEncadeadaEstatica(LISTA *lista) {
  lista->inicio = -1;
  lista->dispo = 0;

  for(int i = 0; i < MAX-1; i++)
    lista->A[i].prox = i+1;

  lista->A[MAX-1].prox = -1;
}

int main() {

}
