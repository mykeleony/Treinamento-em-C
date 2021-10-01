/* Programa que realiza operações elementares em listas lineares encadeadas com alocação estática.
   17 de setembro de 2021.
   Myke Leony dos Santos Amorim - Bacharelado em Sistemas de Informação - EACH USP.
*/

#include <stdio.h>
#include <stdbool.h>

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
void destruirListaEncadeadaEstatica (LISTA *lista) {
  lista->inicio = -1;
  lista->disp = -1;
}

// Retorna a posição de uma determinada chave na lista.
int buscaSequencialOrdenada (TIPOCHAVE chave, LISTA lista, int *anterior) {
  int i = lista.inicio;

  *anterior = -1;

  while(i != -1) {
    if (lista.A[i].chave >= chave)
      break;

    *anterior = i;

    i = lista.A[i].prox;
  }

  if (i != -1 && lista.A[i].chave == chave)
    return i;

  return -1;
}

// Obter uma posição (nó) disponível - a lista é alterada:
int obterNoDisponivel (LISTA *lista) {
  int resultado = lista->dispo;

  if (lista->dispo > -1)
    lista->dispo = lista->A[lista->dispo].prox;

  return resultado;
}

// Redisponibilizar uma posição (nó) para a lista de disponíveis - a lista é alterada:
void devolverNo (LISTA *lista, int j) {
  lista->A[j].prox = lista->dispo;
  lista->dispo = j;
}

// Insere um elemento em uma lista linear encadeada ordenada sem duplicações:
bool inserirElementoListaEncadeadaOrdenada (TIPOCHAVE chave, LISTA *lista) {
  if (lista->dispo < 0)
    return false;

  int anterior, i;

  i = buscaSequencialOrdenada(chave, *lista, &anterior);

  if (i != -1)
    return false;

  i = obterNoDisponivel(lista);

  lista->A[i].chave = chave;

  if (lista->inicio < 0) {      // Inserção do primeiro elemento de uma lista vazia.
    lista->inicio = i;
    lista->A[i].prox = -1;
  }

  else {
    if (anterior < 0) {         // Inserção no início de uma lista já existente.
      lista->A[i].prox = lista->inicio;
      lista->inicio = i;
    }

    else {                      // Inserção entre dois elementos.
      lista->A[i].prox = lista->A[anterior].prox;
      lista->A[anterior].prox = i;
    }
  }

  return true;
}

// Deleta um dado elemento da lista:
bool excluirElementoListaEncadeada (TIPOCHAVE chave, LISTA *lista) {
  int anterior, i;

  i = buscaSequencialOrdenada(chave, *lista, &anterior);

  if (i < 0)
    return false;

  if (anterior == -1)
    lista->inicio = lista->A[i].prox;

  else
    lista->A[anterior].prox = lista->A[i].prox;

  devolverNo(lista, i);

  return true;
}

int main() {

}
