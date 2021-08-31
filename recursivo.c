/*
Programa que utiliza recursividade para imprimir textos diferentemente indentados na tela.
Myke Leony dos Santos Amorim. 31 de agosto de 2021.
Introdução à Análise de Algoritmos - Sistemas de Informação: USP.
*/

#include <stdio.h>
#include <stdlib.h>

// Insere tabs (\t's) por quantas vezes a profundidade indicar:
void indenta(int profundidade) {
  for (int i = 0; i < profundidade; i++)
    putchar('\t');
}

int recursivo (int i, int lim) {
  if (i == lim) {
    indenta(i);
    printf("parada %d\n", i);
    return i;
  }

  indenta(i);

  printf("pré %d\n", i);

  recursivo(i+1, lim);
  indenta(i);

  printf("pós %d\n", i);

  return i;
}

int main() {
  recursivo(0, 7);
}
