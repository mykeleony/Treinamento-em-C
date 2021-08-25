/* 
   21 de maio de 2021.
   Programa que, dados dois valores de entrada X e Y, mostre a soma dos números ímpares entre eles.
   Myke Leony dos Santos Amorim: Bacharelado em Sistemas de Informação na EACH - USP. 
*/

#include <stdio.h>

int main() {
	int i, num1, num2, soma = 0;
	
	scanf("%d %d", &num1, &num2);
	
	if (num1 < num2) { //Testando se os números foram colocados em ordem (do menor para o maior).
		for(i = num1+1; i < num2; i++) {
			if ( (i % 2) != 0) //Testando a paridade do módulo (abs) de cada número por meio da obtenção do resto da sua divisão por 2.
				soma += i; //Caso o resto seja diferente de zero, o número é ímpar e adentra a soma. Senão, o teste se repete para o número seguinte.
		}
	}
	
	else { //Caso os números estejam fora de ordem (primeiro o maior e em seguida o menor), troca-se a ordem do cálculo.
		for(i = num2+1; i < num1; i++) {
			if ( (i % 2) != 0)
				soma += i;
		}
		
	}
	
	printf("%d", soma); //Depois da soma no loop, o resultado é mostrado.
	
	return 0;
}
