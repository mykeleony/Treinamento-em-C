/* Programa que aplica o algoritmo Quicksort, retirado do livro "Introduction to Algorithms" para ordenar uma sequência aleatória de números.
   A complexidade do Quicksort é Θ(n*lg(n)) no melhor caso e Θ(n²) no pior caso.
   Myke Leony dos Santos Amorim. 12 de novembro de 2021.
   Introdução à Análise de Algoritmos - Sistemas de Informação: USP.
*/

#include <stdio.h>
#include <stdlib.h>

#define n 10  // Tamanho do array-teste.

int* criaVetor (int tamanho) {
  int* vetor = malloc(sizeof(int)*tamanho);

  for (int i = 0; i < tamanho; i++)
    vetor[i] = random() % 20;

  return vetor;
}

void imprimeVetor (int* vetor, int tamanho) {
  int i;

  printf("{");

  for(i = 0; i < tamanho-1; i++)
    printf("%d, ", vetor[i]);

  printf("%d}\n", vetor[i]);
}

void destroiVetor (int* vetor) {
  free(vetor);
}

void main() {
}
