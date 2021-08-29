/*
   30 de junho de 2021.
   Programa que manipula o tipo de dado "union", a fim de explorar suas limitações e possíveis problemas.
   Myke Leony dos Santos Amorim: Bacharelado em Sistemas de Informação na EACH - USP.
*/

#include <stdio.h>

int main() {
    union medidas {
        double volume; /* medido em litros */
        int peso;     /* medido em gramas */
    };
    
    union medidas pv;

    pv.volume = 44444444.55555555;    
    pv.peso = 200;
    
    printf("\nVolume: %.2f, peso: %d\n", pv.volume, pv.peso);

    pv.peso = 800;
    pv.volume = 0.2;
  
    printf("\nVolume: %.2f, peso: %d\n", pv.volume, pv.peso);

    printf("\nTamanho em bytes do double é %ld\n", sizeof(double));
    printf("\nTamanho em bytes do int é %ld\n", sizeof(int));
    printf("\nTamanho em bytes da union é %ld\n", sizeof(union pesoVolume));
    
    return 0;
}
