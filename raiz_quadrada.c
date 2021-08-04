/*
   10 de junho de 2021.
   Programa que, dado um número x e uma precisão epsilon (0 < E < 1), calcula a raiz quadrada desse número pelo metodo iterativo de Newton.
   Myke Leony dos Santos Amorim: Bacharelado em Sistemas de Informação na EACH - USP.
*/

#include <stdio.h>

double x, xi, modulo_diferenca; //Declarando as variáveis a serem utilizadas na função que calcula a raiz.

double raizQuadrada(double a, double epsilon) {

	if (a < 0 || epsilon <= 0 || epsilon >= 1)
		return -1; //Nos casos em que o número que se deseja calcular a raiz é negativo e em que a precisão está fora do intervalo [0,1], é retornado o valor -1.

	if(a == 0)
		return 0; //Caso o número inserido seja zero, a função instantaneamente retorna zero.

	x = a/2; //Antes de iniciar a iteratividade em si, é necessário calcular o marco inicial.

	do { //A inserção do "do" antes da condição de repetição é necessária para executar os comandos do laço pelo menos uma vez.
		xi = x; //Ao (re)iniciar o loop, define-se o valor anterior à repetição.

		x = ( xi+(a/xi) )/2; //Calculando o valor do xi subsequente.

		modulo_diferenca = x - xi; //Obtendo a distância entre o valor anterior e o atual para delimitar a precisão.

		if(modulo_diferenca < 0)
			modulo_diferenca = modulo_diferenca*(-1); //Para obter o valor absoluto da diferença, é necessário trocar o sinal nos casos de valores negativos.

	} while (modulo_diferenca >= epsilon); //O laço se repete até a diferença entre os valores de x calculados superar a precisão epsilon.

	return x; //Retornando o valor da raiz quadrada do número inserido.

}

int main() {

  double valor, precisao;
  int escolha;

  do {
	  printf("\nInsira o numero a ter a raiz quadrada calculada e a precisao do calculo: ");
    scanf("%lf %lf", &valor, &precisao);


    printf("\nA raiz quadrada de %f vale %f\n", valor, raizQuadrada(valor, precisao)); //Imprimindo o resultado (teste).

    printf("\nDeseja calcular outra raiz? 1 - Sim  2 - Nao\n");
    scanf("%i", &escolha);
  } while (escolha == 1);

  return 0;
}
