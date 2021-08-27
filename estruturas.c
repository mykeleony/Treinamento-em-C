/*
   24 de junho de 2021.
   Programa que utiliza estruturas simples, a fins de prática.
   Myke Leony dos Santos Amorim: Bacharelado em Sistemas de Informação na EACH - USP.
*/

#include <stdio.h>

int main() {
  typedef struct {
    long nUSP;
    float notaEP1, notaEP2;
    float mediaProvas;
  } Aluno;

  Aluno aluno1;

  aluno1.nUSP = 1234567;
  aluno1.notaEP1 = 10;
  aluno1.notaEP2 = 10;
  aluno1.mediaProvas = (aluno1.notaEP1 + aluno1.notaEP2)/2.0;

  printf("Média do aluno: %.2f\n", aluno1.mediaProvas);

  return 0;
}
