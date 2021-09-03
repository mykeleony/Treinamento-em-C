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
  // A função de complexidade T(n) se dá pelas constantes de tempo utilizada pelo algoritmo em cada comando.

	if (primeiroDesordenado >= tamanhoArray)         //c37
    return numeros;            // Condição de encerramento da recursividade: o array está ordenado (o último elemento é o fora de ordem). //c38

	int key = numeros[primeiroDesordenado];          //c40

	int i = primeiroDesordenado-1;                   //c42

	while ((i>=0) && (numeros[i]>key)) {             //c44*t{primeiroDesordenado}
		numeros[i+1] = numeros[i];                     //c45*t {primeiroDesordenado}-1
		i--;                                           //c46*t {primeiroDesordenado}-1
	}

	numeros[i+1]=key;                                //c49

  ordenaVetorPorInsercao (numeros, tamanhoArray, primeiroDesordenado+1);  //T(n-1)

  return numeros;                                  //c54
}

/*
Função de complexidade de tempo (fórmula de recorrência):
T(n) = c37 + c40 + c42 + c44*t{primeiroDesordenado} + c45*t{primeiroDesordenado}-1 + c46*t{primeiroDesordenado}-1 + c49 + T(n-1) + c54

Complexidade de tempo no melhor caso (array a ser ordenado já está completamente ordenado):

T1(n) = c37 + c40 + c42 + c44*1 + c45*0 + c46*0 + c49 + T1(n-1) + c54
T1(n) = c37 + c40 + c42 + c44 + c49 + T(n-1) + c54
T1(n) = T1(n-1) + (c37 + c40 + c42 + c44 + c49 + c54); c = (c37 + c40 + c42 + c44 + c49 + c54)
T1(n) = T1(n-1) + c

A incógnita c equivale, aproximadamente, à complexidade de tempo da solução trivial (array de tamanho 1):
T1(n) = T1(n-1)+T(1)
T1(n) = \sum_{j=1}^{n} c = n*c

*/

int main () {
  // Testagem de exemplos:
  int tamanho = 10;

  int *exemplo = criaVetor(tamanho);

  imprimeVetor(exemplo, tamanho);

  imprimeVetor(ordenaVetorPorInsercao(exemplo, tamanho, 0), tamanho);

  free(exemplo);  //Destruindo o vetor criado ao liberar sua memória.

  return 0;
}
