/*
   25 de junho de 2021.
   Programa que utiliza o tipo de dado "enum", a fins de treinamentos.
   Myke Leony dos Santos Amorim: Bacharelado em Sistemas de Informação na EACH - USP.
*/

#include <stdio.h>

int main() {
    typedef enum {DOMINGO = 1, SEGUNDA, TERCA, QUARTA, QUINTA, SEXTA, SABADO} DiaDaSemana;

    DiaDaSemana hoje = SEXTA;

    float temperaturasDaSemana[7]; 
    temperaturasDaSemana[DOMINGO] = 28.5;
    temperaturasDaSemana[SEGUNDA] = 30.1;  
    temperaturasDaSemana[2] = 0.5; 
    temperaturasDaSemana[3] = 3.1; 
    temperaturasDaSemana[hoje] = 19.0;

    printf("%.1f, %.1f\n", temperaturasDaSemana[hoje], temperaturasDaSemana[TERCA]);
    
    return 0;
} 
