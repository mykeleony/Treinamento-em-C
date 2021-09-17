/* Conjunto de programas que utilizam Makefile e múltiplas compilações para estruturar projetos em C.
   Arquivo que reúne as variáveis e as funções relacionadas à manipulação de datas e que importa seu respectivo cabeçalho.
   08 de setembro de 2021.
   Myke Leony dos Santos Amorim - Bacharelado em Sistemas de Informação - EACH USP.
*/

#include <stdio.h>
#include <time.h>
#include "data.h"

// DECLARAÇÃO de uma variável externa que está só no main:
extern char varMain[10];

// DECLARAÇÃO de uma variável externa que está em Pessoa:
extern char varPessoa[10];

// DEFINIÇÃO da variável desse módulo que será global a todos (externa) QUE FIZEREM O INCLUDE DO DATA.H
char varData[10] = "Data";

Data dataDeHoje(void) {

    time_t now; // `time_t` é um tipo para tempo (data e hora)
    time(&now); // Obtem tempo corrente

    // localtime converte um `time_t` para um `tm` de tempo de calendario
    struct tm *local = localtime(&now);

    Data hoje;
    hoje.dia = local->tm_mday;         // Pega dia do mes (1 a 31)
    hoje.mes = local->tm_mon + 1;      // Pega mês do ano (0 to 11)
    hoje.ano = local->tm_year + 1900;  // Pega ano desde 1900

    return hoje;
}

void imprimeVariaveisGlobaisData(void) {
    printf("\nChamando de data.c:");
    printf("varPessoa = %s\n", varPessoa);
    printf("varData = %s\n", varData);
    printf("varMain = %s\n", varMain);
}
