/* 
   16 de junho de 2021.
   Programa que lê um vetor com 20 valores e troca mutuamente os valores adjacentes de posição.
   Myke Leony dos Santos Amorim: Bacharelado em Sistemas de Informação na EACH - USP.
*/

#include <stdio.h>

int main() {

	int vetor[20], i;

	for(i = 19; i > -1; i--) { //Por meio de um laço de repetição, o vetor é preenchido de trás para frente - da posição 19 à 0.
		scanf("%d", &vetor[i]);
	}

	for(i = 0; i < 20; i++)
		printf("N[%d] = %d\n", i, vetor[i]); //Imprimindo os resultados na ordem crescente de posição vetorial.

	return 0;

}
