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

// Retorna o índice do elemento pivô após seu posicionamento correto no array:
int partition (int* vetor, int inicio, int fim) {
  int pivo = vetor[fim], i = inicio-1;

  for (int j = inicio; j < fim-1; j++)
    if (vetor[j] <= pivo) {
      i += 1;

      int auxiliar1 = vetor[i];
      vetor[i] = vetor[j];
      vetor[j] = auxiliar1;
    }

  int auxiliar2 = vetor[i+1];
  vetor[i+1] = vetor[fim];
  vetor[fim] = auxiliar2;

  return i+1;
}

void main() {
}
