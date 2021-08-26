/* 
   17 de junho de 2021.
   Programa que, fornecidos os produtos desejados e suas quantidades, calcula o valor total da conta a ser paga.
   Myke Leony dos Santos Amorim: Bacharelado em Sistemas de Informação na EACH - USP.
*/

#include <stdio.h>

int main() {

	int qtd_produtos, qtd_itens, cod_produto;
	int i;
	double valor_compra;

	scanf("%d", &qtd_produtos);

	for(i = 0; i < qtd_produtos; i++) {
		scanf("%d %d", &cod_produto, &qtd_itens);

		/* São requisitados o código do produto desejado e sua respectiva quantidade por um
		número de vezes igual à quantidade de tipos de produtos diferentes informada. */

		switch(cod_produto) {

			case 1001:
				valor_compra += qtd_itens*1.5;
			break;

			case 1002:
				valor_compra += qtd_itens*2.5;
			break;

			case 1003:
				valor_compra += qtd_itens*3.5;
			break;

			case 1004:
				valor_compra += qtd_itens*4.5;
			break;

			case 1005:
				valor_compra += qtd_itens*5.5;
			break;

			/* Para cada código de produto inserido, é adicionado ao total o cálculo
			do valor desse produto multiplicado pela quantidade desejada. */

		}

	}

	printf("%.2f\n", valor_compra); //Imprimindo o valor total da compra com precisão de duas casas decimais.

	return 0;

}
