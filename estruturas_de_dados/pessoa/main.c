/* Conjunto de programas que utilizam Makefile e múltiplas compilações para estruturar projetos em C.
   Arquivo principal.
   08 de setembro de 2021.
   Myke Leony dos Santos Amorim - Bacharelado em Sistemas de Informação - EACH USP.
*/

#include <stdio.h>
#include "pessoa.h"

// DEFINIÇÃO da variável do módulo main:
char varMain[10] = "main";

void imprimeVariaveisGlobaisMain(void)
{
    printf("\nChamando de main.c:");
    printf("varPessoa = %s\n", varPessoa);
    printf("varData = %s\n", varData);
    printf("varMain = %s\n", varMain);
}


int main() {
  Pessoa p1;
  p1.dataNascimento.dia = 27;
  p1.dataNascimento.mes = 9;
  p1.dataNascimento.ano = 2000;

  int idadeP1 = calculaIdadeAproximada(p1);

  printf("Idade: %d\n", idadeP1);

  imprimeVariaveisGlobaisPessoa();
  imprimeVariaveisGlobaisData();
  imprimeVariaveisGlobaisMain();

  return 0;
}
