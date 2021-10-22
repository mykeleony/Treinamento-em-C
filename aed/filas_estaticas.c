/* Programa que realiza operações elementares em filas de aplicação estática, com vetores.
   08 de outubro de 2021.
   Myke Leony dos Santos Amorim - Bacharelado em Sistemas de Informação - EACH USP.
*/

#include <stdio.h>
#include <stdbool.h>

#define MAX 50  // Número máximo de elementos da fila estática.
#define VALOR_INVALIDO -1

typedef int TIPOCHAVE;  // As chaves serão inteiras.

typedef struct {
  TIPOCHAVE chave;
  // Possíveis futuros campos...
} REGISTRO;

typedef struct {
  int inicio, fim;
  REGISTRO A[MAX];
} FILA;

// Cria uma fila estática vazia:
void inicializaFilaEstatica (FILA *fila) {
  fila->inicio = -1;
  fila->fim = -1;
}

// Retorna o número de elementos de uma fila:
int tamanhoFilaEstatica (FILA fila) {
  int n;

  if (fila.inicio == -1) // A fila está vazia.
    n = 0;

  else if (fila.inicio <= fila.fim)
    n = fila.fim - fila.inicio+1; // A ordem dos índices não está invertida (o início é anterior ao fim).

  else
    n = MAX - fila.inicio + fila.fim+1; // A ordem dos índices está invertida.

  return n;
}

// Insere um elemento no fim da fila estática:
bool inserirFilaEstatica (TIPOCHAVE chave, FILA *fila) {
  if (tamanhoFilaEstatica(*fila) >= MAX)  // Caso a fila esteja cheia, não é possível inserir.
    return false;

  if (fila->inicio < 0) // Se a fila está vazia antes da inserção, é necessário ajustar o início.
    fila->inicio == 0;

  fila->fim = (fila->fim+1) % MAX;  // Ajustando o fim da lista.

  fila->A[fila->fim].chave = chave;

  return true;
}

// Remove o primeiro elemento da fila estática e retorna sua chave:
TIPOCHAVE retirarFilaEstatica (FILA* fila) {
  if (fila->inicio == -1) // Se a fila está vazia, nada há a retirar.
    return VALOR_INVALIDO;

  chave_primeiro = fila->A[fila->inicio].chave;

  // Ajustando os índices para a simulação de vetor circular:
  if (fila->inicio != fila->fim)  // Há mais de um elemento na fila.
    fila->inicio = (fila->inicio+1) % MAX;

  else {  // Após a remoção, a fila ficará vazia.
    fila->inicio = -1;
    fila->fim = -1;
  }

  return chave_primeiro;
}
