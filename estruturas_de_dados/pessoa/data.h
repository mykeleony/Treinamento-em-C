/* Conjunto de programas que utilizam Makefile e múltiplas compilações para estruturar projetos em C.
   Arquivo cabeçalho contendo as declarações das variáveis a serem utilizadas no arquivo C "data" e as funções desse mesmo arquivo.
   08 de setembro de 2021.
   Myke Leony dos Santos Amorim - Bacharelado em Sistemas de Informação - EACH USP.
*/

#include <stdio.h>

// DECLARAÇÃO das variáveis externas desse módulo
extern char varData[10];

// Definições dos tipos
typedef struct{
    int dia;
    int mes;
    int ano;
} Data;

// Protótipos de funções

Data dataDeHoje(void);
void imprimeVariaveisGlobaisData(void);
