/* 
   03 de junho de 2021.
   Programa que lê 100 valores inteiros, positivos e distintos e apresenta o maior deles e sua posição.
   Myke Leony dos Santos Amorim: Bacharelado em Sistemas de Informação na EACH - USP. 
*/

#include <stdio.h>

int main() {
	
	int i, numero, maior_num = 0, posicao;
	
	for(i = 1; i<101; i++) { //Criando um looping que se repete 100 vezes
		scanf("%d", &numero); 
		
		if (numero > maior_num) { //A cada repetição, é verificado se o número inserido é maior do que o maior número até o momento anterior.
			maior_num = numero;
			posicao = i; //Cada vez que o maior número for superado no loop, atualiza-se a posição do maior número.
		}
		
	}
	
	printf("%d\n%d\n", maior_num, posicao); //Ao fim do laço de repetição, os resultados são mostrados.
	
	return 0;
	
}
