/*
   23 de junho de 2021.
   Programa que, dada a coluna de certa matriz desejada pelo usuário, fornece a soma ou a média dos valores dessa coluna.
   Myke Leony dos Santos Amorim: Bacharelado em Sistemas de Informação na EACH - USP.
*/

#include <stdio.h>

int main() {

    double soma=0.0, matriz[12][12];  // Declarando a matriz bidimensional quadrada 12x12.
    char operacao;
    int coluna_usuario, linha, coluna;

    scanf("%d", &coluna_usuario);
    scanf(" %c", &operacao);  //O espaço é necessário para a identificação de outro input pelo compilador.

    for(linha=0; linha < 12; linha++) {

        for(coluna = 0; coluna < 12; coluna++) {
          scanf("%lf", &matriz[linha][coluna]);     //Para cada linha da matriz, o programa itera por todas as suas colunas.

          if(coluna == coluna_usuario)
              soma += matriz[linha][coluna];        //Quando a coluna dessa linha equivale à fornecida pelo usuário, o total da soma se atualiza.
        }

    }

    if(operacao == 'S')
        printf("\n%.1lf\n", soma);   //Caso o usuário tenha digitado "S" no início do programa, o retorno é a soma dos números da coluna.

    else if(operacao == 'M') {
        soma=soma/12.0;
        printf("%.1lf\n", soma);    //Caso o caractere digitado seja "M", a média é imprimida na tela.
    }

    return 0;

}
