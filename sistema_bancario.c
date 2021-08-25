/* Myke Leony dos Santos Amorim: Bacharelado em Sistemas de Informação na EACH - USP; Número USP 12543721 da Turma 2021102.
EXERCÍCIO DE PROGRAMAÇÃO 3
24 de julho de 2021.
Programa de gerenciamento de banco simplificado:
* Um banco eh composto por gerentes, os quais gerenciam um conjunto de clientes (que podem ou nao ser clientes especiais).
* Ha apenas duas caracteristicas dos clientes a serem gerenciadas: o valor em suas contas correntes e o valor de suas dividas/emprestimos com o banco.
* Um cliente pode estar associado a mais de um gerente. Cada banco pode ter ate 10 gerentes e cada gerente pode gerenciar ate 20 clientes.
*/

#include <stdio.h>

#define dividaMaxima 30000
#define dividaMaximaEspecial 50000

#define true 1
#define false 0

typedef int bool;

typedef struct {
  char* nome;
  int cpf;
} PESSOA;

typedef struct {
  PESSOA pessoa;
  char tipo;        //O tipo pode ser 'C' (cliente regular) ou 'E' (cliente especial)
  int valorContaCorrente, valorDaDivida;
} CLIENTE;

typedef struct {
  PESSOA pessoa;
  CLIENTE* clientes[20];
  int numClientes;
} GERENTE;

typedef struct {
  GERENTE* gerentes[10];
  int numGerentes;
} BANCO;

/* FUNCOES PARA CRIAR CLIENTES, GERENTES E BANCOS: */

// Funcao para criar um novo cliente:
CLIENTE novoCliente(char* nome, int cpf, int valorInicial) {
	CLIENTE novo;
	novo.pessoa.nome = nome;
	novo.pessoa.cpf = cpf;
	novo.valorContaCorrente = valorInicial;
	novo.valorDaDivida = 0;
	novo.tipo = 'C';
	return novo;
}

// Funcao para criar um novo cliente especial:
CLIENTE novoClienteEspecial(char* nome, int cpf, int valorInicial){
	CLIENTE novo = novoCliente(nome, cpf, valorInicial);
	novo.tipo = 'E';
	return novo;
}

// Funcao para criar um novo gerente:
GERENTE novoGerente(char* nome, int cpf) {
  GERENTE novo;
  novo.pessoa.nome = nome;
  novo.pessoa.cpf = cpf;
  novo.numClientes = 0;
  return novo;
}

// Funcao para criar um novo banco:
BANCO novoBanco() {
  BANCO novo;
  novo.numGerentes = 0;
  return novo;
}

/* FUNCOES RELATIVAS AOS CLIENTES */

//Funcao que informa se o cliente esta negativado. Retorna true (1) ou false (0).
bool negativado(CLIENTE* c1) {
  if(c1->valorContaCorrente < c1->valorDaDivida)  //Caso a divida seja maior do que o saldo na conta, o cliente esta negativado.
    return true;

    return false;
}

//Funcao que realiza o emprestimo de um cliente:
bool obterEmprestimo(CLIENTE* c1, int valor) {
  if (valor <= 0)   //Caso o valor desejado seja negativo ou nulo, o emprestimo eh negado.
    return false;

  /*
  Duas possibilidades sao testadas: pedidos de emprestimo por clientes regulares e por clientes especiais.
  Cada tipo possui um valor maximo de divida especifico, que eh considerado na condicional:
  Caso a divida acumulada gerada pelo emprestimo nao ultrapasse a divida maxima do tipo desse cliente, a divida aumenta no valor do emprestimo
  e a conta corrente recebe o valor do emprestimo.
  */

  if( (c1->tipo == 'C' && (valor + c1->valorDaDivida) <= dividaMaxima) || (c1->tipo == 'E' && (valor + c1->valorDaDivida) <= dividaMaximaEspecial)) {
    c1->valorDaDivida += valor;
    c1->valorContaCorrente += valor;
    return true;
  }

    return false;   //Caso os requisitos de emprestimo nao sejam preenchidos, o emprestimo eh negado.
}

//Funcao que quita parte de um emprestimo realizado pelo cliente:

/*
  O pagamento do emprestimo (ou de parte dele) nao eh realizado para valores de pagamento negativos, nulos, maiores que a divida atual do cliente
  ou maiores do que o saldo na conta corrente desse cliente.
  Caso contrario, a divida eh quitada total ou parcialmente no valor do pagamento e esse valor eh subtraido do saldo do cliente.
*/

bool pagarEmprestimo(CLIENTE* c1, int valor) {
  if (valor <= 0 || valor > c1->valorDaDivida || valor > c1->valorContaCorrente)
    return false;

  else {
    c1->valorDaDivida -= valor;
    c1->valorContaCorrente -= valor;
    return true;
  }
}

//Funcao que saca a quantia desejada pelo cliente em dinheiro:

/*
  O saque nao pode ser realizado para valores negativos, nulos ou superiores ao saldo atual do cliente.
  Caso o valor obedeca essas condicoes, a conta corrente tem esse valor subtraido.
*/

bool realizarSaque(CLIENTE* c1, int valor) {
  if (valor <= 0 || valor > c1->valorContaCorrente)
    return false;

  else {
    c1->valorContaCorrente -= valor;
    return true;
  }
}

/* FUNCOES RELATIVAS AOS GERENTES */

//Funcao para associar um cliente a um gerente:

/*
* Caso o numero de clientes seja igual a 20, nao se deve adicionar e deve retornar false.
* Caso contrario, ha duas situacoes:
*   1a: o cliente ja consta no arranjo de clientes (que eh verificada usando o numero do cpf),
*       neste caso o cliente nao deve ser reinserido e a funcao deve retornar false;
*   2a: o cliente passado como parametro nao consta no arranjo de clientes: o cliente
*       deve ser adicionado na posicao numClientes, o campo numClientes deve ser
*       incrementado em 1 e a funcao deve retornar true.
*/

bool adicionarCliente(GERENTE* g1, CLIENTE* c1) {
  if (g1->numClientes == 20)
    return false;

  int i;

  for(i = 0; i < g1->numClientes; i++) {
    if(g1->clientes[i]->pessoa.cpf == c1->pessoa.cpf)
      return false;
  }

  g1->clientes[g1->numClientes] = c1;
  g1->numClientes++;
  return true;
}

//Funcao para cobrar todos os emprestimos de todos os clientes de um gerente:

/*
* Para cada um dos clientes presentes no arranjo clientes, este metodo:
*   - nao faz nada ao cliente caso seu valorDaDivida seja igual a zero
*   - caso contrario, ha duas situacoes:
*     1a) se o valorContaCorrente do cliente for maior ou igual ao valorDaDivida,
*         o cliente paga a divida, isto e, o valorContaCorrente eh atualizado,
*         descontando-se o valor da divida e o valorDaDivida eh zerado.
*     2a) se o valorContaCorrente do cliente for menor do que o valorDaDivida,
*         o cliente paga parte da divida, isto e, o valorDaDivida eh atualizado,
*         tendo seu valor diminuido pelo valorContaCorrente e o valorContaCorrente eh zerado.
*/

void cobrarTodosEmprestimos(GERENTE g1) {
  int i;

  for(i = 0; i < g1.numClientes; i++) {

    if(g1.clientes[i]->valorDaDivida > 0) {

      if(g1.clientes[i]->valorContaCorrente >= g1.clientes[i]->valorDaDivida) {
        g1.clientes[i]->valorContaCorrente -= g1.clientes[i]->valorDaDivida;
        g1.clientes[i]->valorDaDivida = 0;
      }

      else {
        g1.clientes[i]->valorDaDivida -= g1.clientes[i]->valorContaCorrente;
        g1.clientes[i]->valorContaCorrente = 0;
      }
    }
  }
}

//Funcao para apresentar as informacoes sobre todos os clientes de um gerente:
void imprimirClientes(GERENTE g) {
  int i;

  printf("Numero de clientes associados a esse gerente: %d\n", g.numClientes);

  CLIENTE* cliente;

  for (i = 0; i < g.numClientes; i++) {
    cliente = g.clientes[i];
    printf("\nCliente N.: %4d \n Tipo: %c\n Nome: %s\n CPF: %11d\n Conta corrente: %8d\n Divida: %8d\n Negativado: %d\n", i+1, cliente->tipo, cliente->pessoa.nome, cliente->pessoa.cpf, cliente->valorContaCorrente, cliente->valorDaDivida, negativado(cliente));
  }
}

/* FUNCOES RELATIVAS AOS BANCOS */

//Funcao para associar um novo gerente ao banco:

/*
 * Caso o numero de gerentes seja igual a 10, nao se deve adicionar e o retorno eh false.
 * Caso contrario, ha duas situacoes:
 *   1a: o gerente ja consta no arranjo de gerentes (verificada usando o numero do cpf),
 *       neste caso o gerente nao eh reinserido e a funcao retorna false;
 *   2a: o gerente passado como parametro nao consta no arranjo de gerentes: o gerente
 *       eh adicionado na posicao numGerentes, o campo numGerentes eh incrementado em 1
 *       e a funcao retorna true.
*/

bool adicionarGerente(BANCO* b1, GERENTE* gerente) {
  if (b1->numGerentes == 10)
    return false;

  int z;

  for (z = 0; z < b1->numGerentes; z++) {

    if (b1->gerentes[z]->pessoa.cpf == gerente->pessoa.cpf)
      return false;

  }

  b1->gerentes[b1->numGerentes] = gerente;
  b1->numGerentes++;
  return true;
}

// Funcao para imprimir as informacoes de um banco:
void imprimirDadosBanco(BANCO b1) {

	printf("Ha %d gerente(s) neste banco.\n", b1.numGerentes);

	GERENTE* ger;
  int g;

	for (g=0; g < b1.numGerentes; g++) {
		ger = b1.gerentes[g];
		printf("\nGerente: %s\tCPF: %d\n", ger->pessoa.nome, ger->pessoa.cpf);
		imprimirClientes(*ger);
	}
}

int main() {
  //Testagem das funcoes de criacao de clientes (regulares e especiais), gerentes e bancos:
  CLIENTE cc1 = novoCliente("Myke\0", 11111, 1500);
  CLIENTE ce1 = novoClienteEspecial("Maique\0", 22222, 3200);
  GERENTE g1 = novoGerente("Maiki\0", 33333);
  GERENTE g2 = novoGerente("Maiqui\0", 44444);
  BANCO MykeBank = novoBanco();

  //Testagem da funcao de adicao de clientes aos gerentes:
  if (adicionarCliente(&g1, &cc1)) printf("Cliente '%s' adicionado corretamente.\n", cc1.pessoa.nome);
	else printf("Cliente '%s' nao pode ser adicionado.\n", cc1.pessoa.nome);

  if (adicionarCliente(&g1, &ce1)) printf("Cliente '%s' adicionado corretamente.\n", ce1.pessoa.nome);
	else printf("Cliente '%s' nao pode ser adicionado.\n", ce1.pessoa.nome);

  if (adicionarCliente(&g2, &ce1)) printf("Cliente '%s' adicionado corretamente.\n", ce1.pessoa.nome);
	else printf("Cliente '%s' nao pode ser adicionado.\n", ce1.pessoa.nome);

  //Testagem da funcao de adicao de gerentes a um banco e da impressao dos dados de um banco:
  adicionarGerente(&MykeBank, &g1);
	adicionarGerente(&MykeBank, &g2);

	imprimirDadosBanco(MykeBank);

  /* Testagem da funcao de obtencao de emprestimo a clientes.
  Testando valores limites, excedentes, nulos e negativos para os dois tipos de clientes: */

  if (obterEmprestimo(&cc1, 30001))  printf("\nCliente '%s' obteve o emprestimo solicitado.\n", cc1.pessoa.nome);
	else  printf("\nCliente '%s' nao obteve o emprestimo solicitado.\n", cc1.pessoa.nome);

  if (obterEmprestimo(&cc1, 0))  printf("\nCliente '%s' obteve o emprestimo solicitado.\n", cc1.pessoa.nome);
	else  printf("\nCliente '%s' nao obteve o emprestimo solicitado.\n", cc1.pessoa.nome);

  if (obterEmprestimo(&cc1, -15))  printf("\nCliente '%s' obteve o emprestimo solicitado.\n", cc1.pessoa.nome);
	else  printf("\nCliente '%s' nao obteve o emprestimo solicitado.\n", cc1.pessoa.nome);

  if (obterEmprestimo(&cc1, 30000))  printf("\nCliente '%s' obteve o emprestimo solicitado.\n", cc1.pessoa.nome);
  else  printf("\nCliente '%s' nao obteve o emprestimo solicitado.\n", cc1.pessoa.nome);

  if (obterEmprestimo(&ce1, 50001))  printf("\nCliente '%s' obteve o emprestimo solicitado.\n", ce1.pessoa.nome);
	else  printf("\nCliente '%s' nao obteve o emprestimo solicitado.\n", ce1.pessoa.nome);

  if (obterEmprestimo(&ce1, 0))  printf("\nCliente '%s' obteve o emprestimo solicitado.\n", ce1.pessoa.nome);
	else  printf("\nCliente '%s' nao obteve o emprestimo solicitado.\n", ce1.pessoa.nome);

  if (obterEmprestimo(&ce1, -15))  printf("\nCliente '%s' obteve o emprestimo solicitado.\n", ce1.pessoa.nome);
	else  printf("\nCliente '%s' nao obteve o emprestimo solicitado.\n", ce1.pessoa.nome);

  if (obterEmprestimo(&ce1, 50000))  printf("\nCliente '%s' obteve o emprestimo solicitado.\n", ce1.pessoa.nome);
  else  printf("\nCliente '%s' nao obteve o emprestimo solicitado.\n", ce1.pessoa.nome);

  //Testando a funcao de realizacao de saques pelo cliente:

  printf("\n\n****************** Testando a funcao realizarSaque ****************************\n");

  if (realizarSaque(&cc1, 0)) printf("Cliente '%s' realizou o saque solicitado.\n", cc1.pessoa.nome);
	else printf("Cliente '%s' nao pode realizar o saque solicitado.\n", cc1.pessoa.nome);

  if (realizarSaque(&cc1, -1)) printf("Cliente '%s' realizou o saque solicitado.\n", cc1.pessoa.nome);
	else printf("Cliente '%s' nao pode realizar o saque solicitado.\n", cc1.pessoa.nome);

  // O cliente cc1 realizou um emprestimo de 30000. Portanto, ele possui 31500 na conta corrente.
	if (realizarSaque(&cc1, 31501)) printf("Cliente '%s' realizou o saque solicitado.\n", cc1.pessoa.nome);
	else printf("Cliente '%s' nao pode realizar o saque solicitado.\n", cc1.pessoa.nome);

  if (realizarSaque(&cc1, 31400)) printf("Cliente '%s' realizou o saque solicitado.\n", cc1.pessoa.nome);
	else printf("Cliente '%s' nao pode realizar o saque solicitado.\n", cc1.pessoa.nome);

  /* Testagem da funcao de pagamento de emprestimos pelo cliente.
  Testando valores nulos, negativos, maiores que a divida, maiores que o saldo do cliente e valores validos. */

  printf("\n\n****************** Testando a funcao pagarEmprestimo ***************************\n");

  if (pagarEmprestimo(&cc1, 0))  printf("Cliente '%s' pagou (parte de) sua divida.\n", cc1.pessoa.nome);
	else  printf("Cliente '%s' nao pode pagar (parte de) sua divida.\n", cc1.pessoa.nome);

  if (pagarEmprestimo(&cc1, -1))  printf("Cliente '%s' pagou (parte de) sua divida.\n", cc1.pessoa.nome);
	else  printf("Cliente '%s' nao pode pagar (parte de) sua divida.\n", cc1.pessoa.nome);

  if (pagarEmprestimo(&cc1, 30001))  printf("Cliente '%s' pagou (parte de) sua divida.\n", cc1.pessoa.nome);
	else  printf("Cliente '%s' nao pode pagar (parte de) sua divida.\n", cc1.pessoa.nome);

  //O cliente cc1 sacou 31400 reais dos 31500 de sua conta. Portanto, ha 100 reais na conta corrente.

  if (pagarEmprestimo(&cc1, 101))  printf("Cliente '%s' pagou (parte de) sua divida.\n", cc1.pessoa.nome);
	else  printf("Cliente '%s' nao pode pagar (parte de) sua divida.\n", cc1.pessoa.nome);

  if (pagarEmprestimo(&cc1, 50))  printf("Cliente '%s' pagou (parte de) sua divida.\n", cc1.pessoa.nome);
	else  printf("Cliente '%s' nao pode pagar (parte de) sua divida.\n", cc1.pessoa.nome);

  /* Testagem da funcao de cobranca dos emprestimos realizados por todos os clientes de um gerente.
  Testando... */

  imprimirDadosBanco(MykeBank);

  printf("\n\n****************** Testando a funcao cobrarTodosEmprestimos ***************************\n");
  cobrarTodosEmprestimos(g1);
  imprimirDadosBanco(MykeBank);

}
