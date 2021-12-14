/* Programa que aplica o algoritmo Heapsort, retirado do livro "Introduction to Algorithms" para ordenar uma sequência aleatória de números.
Myke Leony dos Santos Amorim. 29 de outubro de 2021.
Introdução à Análise de Algoritmos - Sistemas de Informação: USP.
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#define tam 10

int *criaVetor (int tamanho) {
  int* vetor = malloc(sizeof(int)*tamanho);

  for (int i = 0; i < tamanho; i++)
    vetor[i] = random() % 20;

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

void heapsort(int* a, int n) {
   int i = n/2, pai, filho, t;

   while(true) {

      if (i > 0) {
          i--;
          t = a[i];
      }

      else {
          n--;

          if (n <= 0)
            return;

          t = a[n];

          a[n] = a[0];
      }

      pai = i;
      filho = i * 2 + 1;

      while (filho < n) {
          if (filho + 1 < n  &&  a[filho + 1] > a[filho])
              filho++;

          if (a[filho] > t) {
             a[pai] = a[filho];
             pai = filho;
             filho = pai * 2 + 1;
          }

          else {
             break;
          }
      }

      a[pai] = t;
   }
}

void main () {
  int* vetor = criaVetor(tam);
  imprimeHeap(vetor, tam);
  heapsort(vetor, tam);
  imprimeHeap(vetor, tam);
  destroiHeap(vetor);
}
