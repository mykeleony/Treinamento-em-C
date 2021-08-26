/* Myke Leony dos Santos Amorim: Bacharelado em Sistemas de Informação na EACH - USP.
24 de julho de 2021.
Programa que informa o número de adesivos carimbados que faltam para completar um álbum de firuginhas.
*/

#include <stdio.h>

int main() {

  int i, j, espacos, tot_carimbadas, falta, tot_compradas;

  scanf("%d %d %d", &espacos, &tot_carimbadas, &tot_compradas);

  int carimbadas[tot_carimbadas], compradas[tot_compradas];

  for(i = 0; i < tot_carimbadas; i++)
    scanf("%d", &carimbadas[i]);

  falta = tot_carimbadas;

  for(i = 0; i < tot_compradas; i++) {
    scanf("%d", &compradas[i]);

    for(j = 0; j < tot_carimbadas; j++) {
      if(compradas[i] == carimbadas[j])
        falta--;
    }

  }

  printf("%d\n", falta);

  return 0;

}
