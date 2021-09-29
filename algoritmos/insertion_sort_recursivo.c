/*
Programa que utiliza o algoritmo Insertion Sort, retirado do livro "Introduction to Algorithms", modificado para ordenar uma sequência aleatória de números.
Diferentemente da literatura, este algoritmo utiliza recursão no lugar de laços de repetição nos pontos críticos da execução.
Myke Leony dos Santos Amorim. 03 de setembro de 2021.
Introdução à Análise de Algoritmos - Sistemas de Informação: USP.
*/

#include <stdio.h>
#include <stdlib.h>

//Utiliza alocacao de memoria para criar vetores contendo numeros aleatorios de 1 a 20.
int *criaVetor(int comprimentoVetor) {
  int *vetor = malloc(sizeof(int)*comprimentoVetor);

  for (int i = 0; i < comprimentoVetor; i++)
    vetor[i] = random() % 20;

  return vetor;
}

//Exibe um vetor especificado na tela:
void imprimeVetor(int *vetor, int tamanhoVetor) {
  int i;

  putchar('{');

  for(i = 0; i < tamanhoVetor-1; i++)
    printf("%d, ", vetor[i]);

  printf("%d}\n", vetor[i]);
}

//Ordenando os numeros de um vetor por Insertion Sort:
int *ordenaVetorPorInsercao(int *numeros, int tamanhoArray, int primeiroDesordenado) {
  // A função de complexidade T(n) se dá pelas constantes de tempo utilizada pelo algoritmo em cada comando.

	if (primeiroDesordenado >= tamanhoArray)         //c37
    return numeros;            // Condição de encerramento da recursividade: o array está ordenado (o último elemento é o fora de ordem). //c38

	int key = numeros[primeiroDesordenado];          //c40

	int i = primeiroDesordenado-1;                   //c42

	while ((i>=0) && (numeros[i]>key)) {             //c44*t{primeiroDesordenado}
		numeros[i+1] = numeros[i];                     //c45*t{primeiroDesordenado}-1
		i--;                                           //c46*t{primeiroDesordenado}-1
	}

	numeros[i+1]=key;                                //c49

  ordenaVetorPorInsercao (numeros, tamanhoArray, primeiroDesordenado+1);  //T(n-1)

  return numeros;                                  //c54
}

/*
Função de complexidade de tempo (fórmula de recorrência):
T(n) = c37 + c40 + c42 + c44*t{primeiroDesordenado} + c45*t{primeiroDesordenado}-1 + c46*t{primeiroDesordenado}-1 + c49 + T(n-1) + c54

Complexidade de tempo no melhor caso (array a ser ordenado já está completamente ordenado):

T1(n) = c37 + c38 + c40 + c42 + c44*1 + c45*0 + c46*0 + c49 + T1(n-1) + c54
T1(n) = c37 + c38 + c40 + c42 + c44 + c49 + T(n-1) + c54
T1(n) = T1(n-1) + (c37 + c38 + c40 + c42 + c44 + c49 + c54); c = (c37 + c38 + c40 + c42 + c44 + c49 + c54)
T1(n) = T1(n-1) + c

A incógnita c equivale, aproximadamente, à complexidade de tempo da solução trivial (array de tamanho 1):
T1(n) = T1(n-1)+T(1)
T1(n) = \sum_{j=1}^{n} c = n*c

Complexidade de tempo no pior caso:
T(n) = c37 + c38 + c40 + c42 + c44*(n-1) + c45*(n-2) + c46*(n-2) + c49 + T(n-1) + c54
T(n) = T(n-1) + c44*(n-1) + c45*(n-2) + c46*(n-2) + c38 + c40 + c42 + c49 + c54

c1*n = c44*(n-1) + c45*(n-2) + c46*(n-2)
c2 = c38 + c40 + c42 + c49 + c54

T(n) = T(n-1) + c1*n + c2
T(n) = T(n-1) + [c1*n + c2]

Assumindo c1 = c2 = c:

T(n) = T(n-1) + [c*n + c]

Como T(1) = c:

T(1) = c
T(2) = c + [c*2 + c] = 4c
T(3) = T(2) + [c*3 + c] = 4c + 5c = 8c
T(4) = T(3) + [c*4 + c] = 8c + 5c = 13c
T(5) = T(4) + [c*5 + c] = 13c + 6c = 19c
                ...
T(n) = 2n-1+(n*(n-1))/2
T(n) = 2n-1+n²/2-n/2
T(n) = n²/2+3n/2-1

Portanto, a função de complexidade de tempo do pior caso do insertion sort recursivo realmente é quadrática.

PROVANDO POR INDUÇÃO:


Iniciando pelo caso base:
base : para n = 1
(pela def.) T(n) = c
(pela conj.) T(n) = c


Como os resultados são iguais, para o caso base, definição e conjectura são
equivalentes.
Escolhe-se a estratégia de demonstração do passo: Supondo que vale para
n-1, demonstre que vale para n. Desta forma, a hipótese de indução:
T(n − 1) = c∗(2(n-1)-1+[(n-1)(n-2)]/2)


A hipótese de indução pode ser usada na demonstração do passo indutivo,
quantas vezes for necessária e quando for conveniente.
Seguindo para a demonstração, inicia-se com alguma verdade, por exemplo,
pela definição:

T(n) = T(n−1)+c∗n+c


Substituindo T(n − 1) pela hipótese de indução e calculando, obtém-se:

T(n) = c*[2(n-1)-1+((n-1)*(n-2))/2+n+1]
T(n) = c*[3n-2+((n-1)*(n-2))/2]
*/

int main () {
  // Testagem de exemplos:
  int tamanho = 10;

  int *exemplo = criaVetor(tamanho);

  imprimeVetor(exemplo, tamanho);

  imprimeVetor(ordenaVetorPorInsercao(exemplo, tamanho, 0), tamanho);

  free(exemplo);  //Destruindo o vetor criado ao liberar sua memória.

  return 0;
}
