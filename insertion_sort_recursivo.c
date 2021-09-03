/*
Programa que utiliza o algoritmo Insertion Sort, retirado do livro "Introduction to Algorithms", modificado para ordenar uma sequência aleatória de números.
Diferentemente da literatura, este algoritmo utiliza recursão no lugar de laços de repetição nos pontos críticos da execução.
Myke Leony dos Santos Amorim. 03 de setembro de 2021.
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
int *ordenaVetorPorInsercao(int *numeros, int tamanhoArray, int primeiroDesordenado) {
	if (primeiroDesordenado >= tamanhoArray)
    return numeros;     // Condição de encerramento da recursividade: o array está ordenado (o último elemento é o fora de ordem).

	int key = numeros[primeiroDesordenado];

	int i = primeiroDesordenado-1;

	while ((i>=0) && (numeros[i]>key)) {
		numeros[i+1] = numeros[i];
		i--;
	}

	numeros[i+1]=key;

  ordenaVetorPorInsercao (numeros, tamanhoArray, primeiroDesordenado+1);

  return numeros;
}

int main () {
  // Testagem de exemplos:
  int tamanho = 10;

  int *exemplo = criaVetor(tamanho);

  imprimeVetor(exemplo, tamanho);

  imprimeVetor(ordenaVetorPorInsercao(exemplo, tamanho, 0), tamanho);

  free(exemplo);  //Destruindo o vetor criado ao liberar sua memória.

  return 0;
}
