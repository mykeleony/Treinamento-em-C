/* Programa que realiza operações elementares em árvores balanceadas AVL.
   26 de novembro de 2021.
   Myke Leony dos Santos Amorim - Bacharelado em Sistemas de Informação - EACH USP.
*/

typedef struct estrutura {
  TIPOCHAVE chave;
  int bal;  // Fator de balanceamento com os valores (-1, 0, 1) possíveis.
  struct estrutura *esq;
  struct estrutura *dir;
} NO;
