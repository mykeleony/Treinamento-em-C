/* 
   09 de junho de 2021.
   Programa que lê as notas (0 a 10) de duas avaliações e calcula a nota semestral.
   Myke Leony dos Santos Amorim: Bacharelado em Sistemas de Informação na EACH - USP. 
*/

#include <stdio.h>

int main() {
	
	double nota1, nota2, media;
	int escolha;
	
	do { //O looping de repetição voluntária do programa pelo usuário é inicializado e seu código é executado no mínimo uma vez.
			
		scanf("%lf", &nota1);
				
		 while (nota1 < 0 || nota1 > 10) { //Enquanto a nota for inválida, a mensagem é apresentada e um novo valor é requisitado.
		 	printf("nota invalida\n");
			scanf("%lf", &nota1);
		 }
		
		scanf("%lf", &nota2);
		
		while (nota2 < 0 || nota2 > 10) { //Enquanto a nota for inválida, a mensagem é apresentada e um novo valor é requisitado.
			printf("nota invalida\n");
			scanf("%lf", &nota2);
		}
			
		media = (nota1+nota2)/2; //Calculando a média semestral.
		
		printf("media = %.2f\n", media);
		printf("novo calculo (1-sim 2-nao)\n"); //Imprimindo o resultado com duas casas decimais e oferecendo a opção de realizar um novo cálculo.
		
		scanf("%d", &escolha);
		
		while (escolha != 1 && escolha != 2) { //Sempre que um número fora das opções for inserido (diferentes de 1 e 2), a mensagem se repete e um novo valor é requisitado.
			printf("novo calculo (1-sim 2-nao)\n");
			scanf("%d", &escolha);
		}
		
	} while (escolha == 1); // O código se repete sempre que o usuário escolher a opção (1). No caso de a opção ser 2, o programa é encerrado.
	
	return 0;
	
}
