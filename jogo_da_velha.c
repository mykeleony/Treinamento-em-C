/* Myke Leony dos Santos Amorim: Bacharelado em Sistemas de Informação na EACH - USP -> Número USP 12543721 da Turma 2021102.
EXERCÍCIO DE PROGRAMAÇÃO 3
24 de junho de 2021.
Programa que, dada uma matriz representando um tabuleiro de jogo da velha, verifica e retorna o 'status' da partida contida nele.
Os status possíveis são 0 (jogo não iniciado), 1 (jogador de peças X venceu), 2 (jogador de peças O venceu), 3 (empate) e 4 (jogo em andamento).
*/

#include <stdio.h>

int verificaStatus(char tabuleiro[][3]) {   //Função que recebe o tabuleiro como parâmetro (uma matriz de caracteres de 3 colunas) e retorna um valor inteiro (o status).

  int linhas, colunas, campos_preenchidos = 0;

  for (linhas = 0; linhas < 3; linhas++) {    //Criando um loop que passará por todas as linhas do tabuleiro, uma por repetição.

    if(tabuleiro[linhas][0] == 'X' && tabuleiro[linhas][1] == 'X' && tabuleiro[linhas][2] == 'X')
      return 1;     //Caso todas as colunas (0, 1 e 2) da linha em questão estejam preenchida por X's, o jogo foi vencido pelo jogador 1.

    else if(tabuleiro[linhas][0] == 'O' && tabuleiro[linhas][1] == 'O' && tabuleiro[linhas][2] == 'O')
      return 2;     //Por outro lado, caso todas as colunas da linha em questão estejam preenchida por O's, a vitória pertence ao jogador 2.
  }

  for(colunas = 0; colunas < 3; colunas++) {  //Se nenhum jogador ganhou pelas linhas, a próxima etapa é verificar se há vitórias pelas colunas.

    if(tabuleiro[0][colunas] == 'X' && tabuleiro[1][colunas] == 'X' && tabuleiro[2][colunas] == 'X')
      return 1;   //Caso todas as linhas (0, 1 e 2) da coluna em questão estejam preenchida por X's, o jogador 1 ganhou a partida.

    else if(tabuleiro[0][colunas] == 'O' && tabuleiro[1][colunas] == 'O' && tabuleiro[2][colunas] == 'O')
      return 2;   //Senão, caso todas as linhas dessa coluna estejam preenchida por O's, o jogador 2 é o vencedor.
  }

  //Se não existir vitória pelas linhas nem pelas colunas, sobram as vitórias pelas diagonais.

  if(tabuleiro[0][0] == 'X' && tabuleiro[1][1] == 'X' && tabuleiro[2][2] == 'X')
    return 1; //Caso a diagonal principal (0,0; 1,1; e 2;2) esteja totalmente preenchida por X's, o jogo foi vencido pelo jogador 1.

  else if (tabuleiro[0][2] == 'X' && tabuleiro[1][1] == 'X' && tabuleiro[2][0]== 'X')
    return 1; //Ademais, se a diagonal secundária (0,2; 1;1 e 2;0) esteja totalmente preenchida por X's, a vitória pertence ao jogador 1.

  else if(tabuleiro[0][0] == 'O' && tabuleiro[1][1] == 'O' && tabuleiro[2][2] == 'O')
    return 2; //Porém, caso todas as casas da diagonal principal estejam preenchidas por O's, o jogador 2 venceu.

  else if(tabuleiro[0][2] == 'O' && tabuleiro[1][1] == 'O' && tabuleiro[2][0] == 'O')
    return 2; //Por fim, se a diagonal secundária estiver totalmente dominada por O's, o jogador 2 é o vencedor.

  //Após testadas e esgotadas todas as possibilidades de vitória dos dois jogadores, resta decretar tabuleiro vazio, empate ou incompletude do jogo.

  for (linhas = 0; linhas < 3; linhas++) {
    for (colunas = 0; colunas < 3; colunas++) {  //Para isso, é necessário checar a quantidade de casas preenchidas do tabuleiro.

      if(tabuleiro[linhas][colunas] != ' ')
        campos_preenchidos++;   //Para cada elemento da matriz, se nele não houver o caractere de espaço, é adicionado 1 à contagem de casas não vazias do tabuleiro.
    }
  }

  if(campos_preenchidos == 0)
    return 0;   //Caso nenhum campo do tabuleiro esteja preenchido, o jogo ainda não foi iniciado.

  else if(campos_preenchidos == 9)
    return 3;   //Porém, caso todos os campos do tabuleiro (as 9 casas) estejam preenchidos, ocorreu empate - considerando que as vitórias já foram testadas.

  else
    return 4;   //Finalmente, se não houve vitória nem empate e o jogo já se iniciou, a única possibilidade é a de ele ainda estar em andamento.

}

int main() {

  char tabuleiroteste[3][3] = {   //Matriz utilizada nas testagens.
    {'X', 'X', 'O'},
    {'O', 'O', 'X'},
    {'X', 'O', 'X'}
  };

  int status = verificaStatus(tabuleiroteste);

  switch(status) {    //Imprimindo o resultado do teste.
    case 0: printf("0 – Jogo nao iniciado: o tabuleiro esta 'vazio', isto e, sem pecas 'X' e O.\n"); break;
    case 1: printf("1 – Jogo encerrado 1: o primeiro jogador (que usa as pecas X) eh o ganhador.\n"); break;
    case 2: printf("2 – Jogo encerrado 2: o segundo jogador (que usa as pecas O) eh o ganhador.\n"); break;
    case 3: printf("3 – Jogo encerrado 3: empate – todas as casas do tabuleiro estao preenchidas com X e O, mas nenhum dos jogadores ganhou.\n"); break;
    case 4: printf("4 – Jogo ja iniciado e em andamento.\n"); break;
  }

  return 0;

}
