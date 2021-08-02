/*
   14 de maio de 2021.
   Programa que, dado o valor de Bits (B$) desejado pelo usuario, determina a quantia de cada nota (B$50, B$20, B$5 e B$1) necessaria para totalizar esse valor,
   de modo a minimizar a quantidade de cedulas entregues.
   Myke Leony dos Santos Amorim: Bacharelado em Sistemas de Informacao na EACH - USP.
*/

#include <stdio.h>
#include <stdlib.h>

int n1, n5, n20, n50; //Variaveis globais nX's, nas quais "n" simboliza a palavra nota e X representa o valor da cedula correspondente.

void fazRetirada(int valor) {

	if(valor <= 0)
		valor = n1 = n5 = n20 = n50 = -1; //Caso o valor seja invalido (igual ou menor a zero), o valor e as quantidades de cedulas serao substituidos por -1.


	n50 = valor/50; //A quantidade de notas de B$50 equivale ao resultado inteiro (ignorando as casas decimais) da divisao do valor total por 50.
	n20 = (valor-(n50*50))/20; //A quantidade de notas de B$20 equivale ao resultado inteiro da divisao do valor restante por 20.
	n5 = (valor-(n50*50)-(n20*20))/5; //A quantidade de notas de B$5 equivale ao resultado inteiro da divisao da sobra do valor (apos as retiradas) por 5.
	n1 = (valor-(n50*50)-(n20*20)-(n5*5)); //A quantidade de notas de B$1 equivale ao restante do valor apos retiradas todas as maiores cedulas possiveis.
}

int main() {

	int valor, escolha;

	do {
		printf("\nInsira o valor do saque: ");
		scanf("%i", &valor);

		fazRetirada(valor);

		printf("Notas de 50: %d\nNotas de 20: %d\nNotas de 5: %d\nNotas de 1: %d\n", n50, n20, n5, n1);

		printf("\nDeseja realizar outro saque? 1 - Sim  2 - Não\n");
		scanf("%i", &escolha);
	} while (escolha == 1);

	return 0;
}
