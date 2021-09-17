/* Conjunto de programas que utilizam Makefile e múltiplas compilações para estruturar projetos em C.
   Arquivo cabeçalho contendo as declarações das variáveis a serem utilizadas no arquivo C "pessoa" e as funções desse mesmo arquivo.
   08 de setembro de 2021.
   Myke Leony dos Santos Amorim - Bacharelado em Sistemas de Informação - EACH USP.
*/

#include <stdio.h>
#include "data.h"

// DECLARAÇÃO das variáveis externas desse módulo
extern char varPessoa[10];

// Definições dos tipos
typedef struct{
  char nome[50];
  Data dataNascimento;
  // Conterá novos campos no futuro.
} Pessoa;

// Protótipos de funções:

int calculaIdadeAproximada(Pessoa p);
void imprimeVariaveisGlobaisPessoa(void);
