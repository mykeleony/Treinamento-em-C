/*
   23 de junho de 2021.
   Programa que faz as operações principais com a biblioteca "stdbool.h", envolvendo variáveis booleanas (true e false).
   Myke Leony dos Santos Amorim: Bacharelado em Sistemas de Informação na EACH - USP.
*/

#include <stdio.h>
#include <stdbool.h>

int main() {
  bool x = 10 > 18;

  printf("%d = ", x);

  printf("%s", x ? "true" : "false");

  bool y = true;

  printf("\n%d = ", y);

  printf("%s", y ? "true" : "false");

  printf("\nTamanho do tipo bool em bytes: %ld\n", sizeof(bool));

  return 0;
}
