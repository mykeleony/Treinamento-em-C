/* Programa que aplica o algoritmo Heapsort, retirado do livro "Introduction to Algorithms" para ordenar uma sequência aleatória de números.
Myke Leony dos Santos Amorim. 29 de outubro de 2021.
Introdução à Análise de Algoritmos - Sistemas de Informação: USP.
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define n 10

void troca(int* a, int* b) {
  int t = *a;

  a = b;
  *b = t;
}

int *criaVetor (int tamanho) {
  int* vetor = malloc(sizeof(int)*tamanho);

  for (int i = 0; i < tamanho; i++)
    vetor[i] = random() % 20;

  return vetor;
}

int *criaHeap (int tamanho, int* vetor) {
  for (int i = 1; i < tamanho; i++) {
    int j = i+1;

    while (j > 1 && vetor[j/2] < vetor[j]) {
      troca(&vetor[j/2], &vetor[j]);
      j /= 2;
    }
  }

  return vetor;
}

void imprimeHeap(int *heap, int tamanho) {
  int i;

  printf("Heap na forma vetorial: {");

  for(i = 0; i < tamanho-1; i++)
    printf("%d, ", heap[i]);

  printf("%d}\n", heap[i]);
}

void destroiHeap (int* heap) {
  free(heap);
}

void maxHeapify (int* heap, int elemento) {
  int esquerdo = 2*elemento;
  int direito = 2*elemento+1;
  int maior;

  if (esquerdo <= n && heap[esquerdo] > heap[direito])
    maior = esquerdo;

  else
    maior = elemento;

  if (direito <= n && heap[direito] > heap[esquerdo])
    maior = direito;

  if (maior != elemento) {
    troca(&heap[esquerdo], &heap[direito]);
    maxHeapify(heap, maior);
  }
}

void main () {
  int* vetor = criaVetor(n);
  //int* heap = criaHeap(n, vetor);
  imprimeHeap(vetor, n);
  //destroiHeap(heap);
}
