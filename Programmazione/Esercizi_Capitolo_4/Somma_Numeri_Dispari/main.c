//Esercizio 4.13 pag. 155
#include <stdio.h>

int main() {
    unsigned int somma = 0;
    for (int i = 1; i <= 15; i+=2){
        somma+=i;
    }
    printf("La somma dei numeri interi dispari da 1 a 15 è: %d",somma);
    return 0;
}