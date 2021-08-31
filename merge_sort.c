/*
Programa que utiliza o algoritmo Merge Sort, retirado do livro "Introduction to Algorithms" para ordenar uma sequência aleatória de números em C.
Myke Leony dos Santos Amorim. 30 de agosto de 2021.
Introdução à Análise de Algoritmos - Sistemas de Informação: USP.
*/

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>   //Biblioteca necessária para utilizar o maior número possível em C como sentinela.

#define TAMANHO 10

//Utiliza alocacao de memoria para criar vetores contendo numeros aleatorios de 1 a 100.
int *criaVetor(int comprimentoVetor) {
  int *vetor = malloc(sizeof(int)*comprimentoVetor);

  for (int i = 0; i < comprimentoVetor; i++)
    vetor[i] = random() % 100;

  return vetor;
}

//Exibe um vetor especificado na tela:
void imprimeVetor(int *vetor, int tamanhoVetor) {
  int i;

  putchar('{');

  for(i = 0; i < tamanhoVetor-1; i++)
    printf("%d, ", vetor[i]);

  printf("%d}\n", vetor[i]);
}

//Ordena os numeros de um vetor por Merge Sort:
void intercala(int *A, int p, int q, int r) {
  int n1 = q-p;   // Difere do livro, pois o primeiro índice de vetores em C é zero, não um.
  int n2 = r-q;
  int i, j, k;

  int *L = malloc(sizeof(int)*n1+1);  // L (left) contém o primeiro elemento de A até o ponto médio (não inclusivamente).
  int *R = malloc(sizeof(int)*n2+1);  // Por outro lado, R (right) armazena os valores do ponto médio (incluindo o ponto médio) até o último elemento.

  L[n1] = R[n2] = INT_MAX;  // A sentinela é o maior número inteiro possível em C e funciona como o infinito.

  // Intercalando L e R:
  for (i = 0; i < n1; i++)
    L[i] = A[p+i];

  for (j = 0; j < n2; j++)
    R[j] = A[q+j];

  i = 0;
  j = 0;

  // Ordenando A (array):
  for (k = p; k < r; k++) {
    if (L[i] <= R[j]) {
      A[k] = L[i];
      i++;
    }

    else {
      A[k] = R[j];
      j++;
    }
  }
}

void ordenaPorIntercalacao(int* A, int p, int r) {
  if (p < r-1) {    //Teste do melhor caso (array de tamanho 1). Porém, difere do livro, pois o primeiro índice de vetores em C é zero.
    int q = (p+r)/2;
    ordenaPorIntercalacao(A, p, q);   // Ordenando até o ponto médio.
    ordenaPorIntercalacao(A, q, r);   // Ordenando do ponto médio até o fim.
    intercala(A, p, q, r);    // Combinando as resoluções dos subproblemas.
  }
}

int main() {
  // Testagem de exemplos:
  int *exemplo = criaVetor(TAMANHO);

  imprimeVetor(exemplo, TAMANHO);

  ordenaPorIntercalacao(exemplo, 0, TAMANHO);

  imprimeVetor(exemplo, TAMANHO);

  return 0;
}
