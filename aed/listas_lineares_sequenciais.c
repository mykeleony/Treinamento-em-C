/* Programa que realiza operações elementares em listas lineares sequenciais.
   13 de setembro de 2021.
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
	// Futuros novos campos...
} REGISTRO;

// Implementação de listas lineares sequenciais estáticas:
typedef struct {
	REGISTRO elementos[MAX];
	int nroElem;     // Número de elementos da lista naquele determinado instante.
} LISTA;

// Estabelece o número de elementos inicial da lista (0):
void inicializarListaVazia (LISTA* lista) {   // O ponteiro é utilizado para a lista copiada (por ser passagem por valor) não ser destruída ao término da função.
  lista->nroElem = 0;
}

void inicializarLista (int tamanho, LISTA* lista) {
  lista->nroElem = tamanho;
}

// Fornece o número de elementos de uma dada lista linear sequencial:
int tamanhoLista(LISTA lista) {
  return lista.nroElem;
}

// Imprime cada elemento de uma dada lista:
void imprimeLista(LISTA lista) {
  if(lista.nroElem <= 0) {
    printf("Lista vazia.\n");
    return;
  }

  int i;

  putchar('{');

  for(i = 0; i < ((lista.nroElem)-1); i++)
    printf("%d, ", lista.elementos[i].chave);

  printf("%d}\n", lista.elementos[i].chave);
}

// Fornece o primeiro elemento de uma dada lista:
TIPOCHAVE primeiroElementoLista(LISTA lista) {
  if(lista.nroElem > 0)
    return lista.elementos[0].chave;

  else
    return VALOR_INVALIDO;   // Lista vazia.
}

// Fornece o último elemento de uma dada lista:
TIPOCHAVE ultimoElementoLista(LISTA lista) {
  if(lista.nroElem > 0)
    return lista.elementos[lista.nroElem-1].chave;

  else
    return VALOR_INVALIDO;  // Lista vazia.
}

// Fornece o n-ésimo elemento de uma dada lista:
TIPOCHAVE qualquerElementoLista(int n, LISTA lista) {
  if (lista.nroElem >= 0)
    return lista.elementos[n].chave;

  else
    return VALOR_INVALIDO;
}

// Insere um elemento qualquer diretamente em uma posição específica:
bool inserirElementoLista(TIPOCHAVE chave, int posicao, LISTA* lista) {
  if(lista->nroElem >= MAX || posicao > lista->nroElem || posicao < 0)
    return false; // Lista cheia (ou que excede o tamanho máximo) ou posição inserida inválida.

  if(lista->nroElem > 0 && posicao < lista->nroElem)
    for(int i = lista->nroElem; i >= posicao+1; i--)
      lista->elementos[i] = lista->elementos[i-1];

  lista->elementos[posicao].chave = chave;
  lista->nroElem++;

  return true;
}

// Retorna a posição da lista sequencial em que se encontra determinada chave:
int buscaSequencial(TIPOCHAVE chave, LISTA lista) {
  for(int i = 0; i < lista.nroElem; i++) {
    if(lista.elementos[i].chave == chave)
      return i;
  }

    return VALOR_INVALIDO;
}

// Exclui determinado elemento da lista sequencial:
bool excluirElementoLista(TIPOCHAVE chave, LISTA* lista) {
  int posicao = buscaSequencial(chave, *lista);

  if(posicao == VALOR_INVALIDO)
    return false;

  for(int i = posicao; i < lista->nroElem-1; i++)
    lista->elementos[i] = lista->elementos[i+1];

  lista->nroElem--;

  return true;
}

// Destrói uma lista. Como a alocação utilizada para os elementos é estática, basta definir o número de elementos como zero.
// OBS: No caso de alocação dinâmica, basta utilizar a função free().
void destroiLista(LISTA* lista) {
  lista->nroElem = 0;
  printf("Lista destruída.\n");
}

int main() {
  // Testando as funções:
  LISTA listaExemplo;
  inicializarLista(8, &listaExemplo);

  printf("Tamanho da lista: %d\n", tamanhoLista(listaExemplo));

  imprimeLista(listaExemplo);

  inserirElementoLista(2, 3, &listaExemplo);

  imprimeLista(listaExemplo);

  printf("A posição do número 2 na lista é %d.\n", buscaSequencial(2, listaExemplo));

  printf("Primeiro elemento da lista: %d\n", primeiroElementoLista(listaExemplo));

  printf("Ultimo elemento da lista: %d\n", ultimoElementoLista(listaExemplo));

  printf("%do elemento da lista: %d\n", 2, qualquerElementoLista(2, listaExemplo));

  excluirElementoLista(2, &listaExemplo);

  imprimeLista(listaExemplo);

  destroiLista(&listaExemplo);

  imprimeLista(listaExemplo);

  return 0;
}
