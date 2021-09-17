/* Programa que utiliza macros para realizar rotinas recorrentes.
   09 de setembro de 2021.
   Myke Leony dos Santos Amorim - Bacharelado em Sistemas de Informação - EACH USP.
*/ 

#include <stdio.h>

#define PI 3
#define QUAD(x) (x) * (x)

// Os parênteses são necessários nos parâmetros, pois estes podem ser expressões ao invés de simples números.

int main() {
    printf("Valor de pi = %d\n", PI);

    int piQuadrado = QUAD(PI);
    int doisMaisPiQuadrado = QUAD(2+PI);
    printf("Valor de piQ = %d e (2+pi)Q = %d\n", piQuadrado, doisMaisPiQuadrado);

    return 0;
}
