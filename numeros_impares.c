/* 
   21 de maio de 2021.
   Programa que, dado um valor de entrada X, mostre todos os números ímpares entre 1 e X.
   Myke Leony dos Santos Amorim: Bacharelado em Sistemas de Informação na EACH - USP. 
*/

#include <stdio.h>

int main() {
	
	int numero, i;
	
	scanf("%d", &numero);
	
	for(i = 1; i < numero+1; i++) { //Testando a poridade de cada número de 1 até X por meio do resto da sua divisão por 2. 
		if ((i%2)!=0) //Caso o resto seja diferente de zero, o número é ímpar e é imprimido na tela. Senão, o teste se repete para o próximo número.
			printf("%d\n", i);
	}

	return 0;
}
