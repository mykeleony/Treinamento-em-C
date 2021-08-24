/*
Programa que utiliza o algoritmo Insertion Sort, retirado do livro "Introduction to Algorithms" para ordenar uma sequência aleatória de números.
Myke Leony dos Santos Amorim. 24 de agosto de 2021.
Introdução à Análise de Algoritmos - Sistemas de Informação: USP.
*/

#include <stdio.h>
#include <stdlib.h>

//Utiliza alocacao de memoria para criar vetores contendo numeros aleatorios de 1 a 20.
int *criaVetor(int comprimentoVetor) {
  int *vetor = malloc(sizeof(int)*comprimentoVetor);

  for (int i = 0; i < comprimentoVetor; i++)
    vetor[i] = random() % 20;

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

//Ordenando os numeros de um vetor por Insertion Sort:
int *ordenaVetorPorInsercao(int *numeros, int tamanhoVetor) {
  for (int i = 1; i < tamanhoVetor; i++) {
    int key = numeros[i];

    int j = i-1;

    while ((j >= 0) && (numeros[j] > key)) {
        numeros[j+1] = numeros[j];
        j--;
    }

    numeros[j+1] = key;
  }

  return numeros;
}

int main () {
  // Testagem de exemplos:
  int tamanho = 5;

  int *exemplo = criaVetor(tamanho);

  imprimeVetor(exemplo, tamanho);

  imprimeVetor(ordenaVetorPorInsercao(exemplo, tamanho), tamanho);

  free(exemplo);  //Destruindo o vetor criado ao liberar sua memória.

  return 0;
}
