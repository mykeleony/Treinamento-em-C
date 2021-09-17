/* Conjunto de programas que utilizam Makefile e múltiplas compilações para estruturar projetos em C.
   Arquivo que contém as variáveis e funções relativas às pessoas e que importa o cabeçalho contendo seus protótipos.
   08 de setembro de 2021.
   Myke Leony dos Santos Amorim - Bacharelado em Sistemas de Informação - EACH USP.
*/

#include <stdio.h>
#include "pessoa.h"

// DECLARAÇÃO de uma variável externa que está só no main:
extern char varMain[10];

// DEFINIÇÃO da variável desse módulo que será global a todos (externa):
char varPessoa[10] = "Pessoa";

int calculaIdadeAproximada(Pessoa p) {
    int idade;
    Data hoje = dataDeHoje();
    idade = hoje.ano - p.dataNascimento.ano;
    return (idade);
}

void imprimeVariaveisGlobaisPessoa(void) {
    printf("\nChamando de pessoa.c: ");
    printf("varPessoa = %s\n", varPessoa);
    printf("varData = %s\n", varData);
    printf("varMain = %s\n", varMain);
}
