//Esercizio 4.12 pag. 155
#include <stdio.h>

int main() {
    unsigned int somma = 0;
    for (int i = 2; i <= 30; i+=2){
        somma+=i;
    }
    printf("La somma dei numeri interi pari da 2 a 30 è: %d",somma);
    return 0;
}