//Esercizio 5.31 pag.214

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int flip(void);

int main() {
    srand(time(NULL));
    int count_croce = 0, count_testa = 0;
    for (int i = 0; i < 100; i++) {
        if (flip() == 1) {
            printf("\nTesta");
            count_testa++;
        } else {
            printf("\nCroce");
            count_croce++;
        }
    }

    printf("\nLa testa è uscita : %d volte", count_testa);
    printf("\nLa croce è uscita : %d volte", count_croce);
    return 0;
}

int flip(void) {
    return rand() % 2;
}