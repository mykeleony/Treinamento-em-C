/* 
   13 de maio de 2021.
   Programa que informa a cidade que é representada pelo DDD inserido.
   Myke Leony dos Santos Amorim: Bacharelado em Sistemas de Informação na EACH - USP.	
*/

#include <stdio.h>

int main() {
	int ddd;
	
	scanf("%d", &ddd);
	
	switch(ddd) { //Comando que compacta if's encadeados.
		case 61: printf("Brasilia\n");
		break;
		
		case 71: printf("Salvador\n");
		break;
		
		case 11: printf("Sao Paulo\n");
		break;
		
		case 21: printf("Rio de Janeiro\n");
		break;
		
		case 32: printf("Juiz de Fora\n");
		break;
		
		case 19: printf("Campinas\n");
		break;
		
		case 27: printf("Vitoria\n");
		break;
		
		case 31: printf("Belo Horizonte\n");
		break;
		
		default: printf("DDD nao cadastrado\n"); //Caso não haja DDD correspondente à entrada, a mensagem "DDD nao cadastrado" é mostrada.
		break;
	}
	
	return 0;
	
}
