/*
   27 de junho de 2021.
   Programa que faz uso de estruturas padrões e de funções built-in relativas à manipulação do tempo em C.
   Myke Leony dos Santos Amorim: Bacharelado em Sistemas de Informação na EACH - USP.
*/

#include <stdio.h>
#include <time.h>

typedef struct {
    int dia;
    int mes;
    int ano;
} Data;

typedef struct {
  char nome[50];
  Data dataNascimento; 
  // .... outros campos
} Pessoa;

Data dataDeHoje (void) {

    time_t now; // `time_t` é um tipo para tempo (data e hora)
    time(&now); // Obtem tempo corrente
 
    // localtime converte um `time_t` para um `tm` de tempo de calendario
    struct tm *local = localtime(&now);

    Data hoje;
    hoje.dia = local->tm_mday;         // pega dia do mes (1 a 31)
    hoje.mes = local->tm_mon + 1;      // pega mês do ano (0 to 11)     
    hoje.ano = local->tm_year + 1900;  // pega ano desde 1900     

    return hoje;
}

int calculaIdadeAproximada(Pessoa p) {
    int idade;
    Data hoje = dataDeHoje();
    idade = hoje.ano - p.dataNascimento.ano; 
    return (idade);
}

void alteraAnoNascimento(Pessoa* p, int novoAno) {
  p->dataNascimento.ano = novoAno;
  return;
}

int main() {
  //Manipulação de dados das estruturas
  Pessoa p1;
  p1.dataNascimento.dia = 27;
  p1.dataNascimento.mes = 9;
  p1.dataNascimento.ano = 2000;

  int idadeP1 = calculaIdadeAproximada(p1);
  printf("Idade: %d\n", idadeP1);

  alteraAnoNascimento(&p1, 1990);
  idadeP1 = calculaIdadeAproximada(p1);
  printf("Idade: %d\n", idadeP1);

  return 0;
}
