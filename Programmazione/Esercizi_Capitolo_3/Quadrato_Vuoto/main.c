#include <stdio.h>

int main() {
    unsigned int lato = 0;

    do {
        printf("Inserisci il lato: ");
        scanf("%d", &lato);

        if (lato < 1 || lato > 20) {
            printf("Valore non accettato\nInserire dei valori da 1 a 20.\n");
        } else {
            for (int i = 0; i < lato; i++) {
                for (int j = 0; j < lato; j++) {
                    if (i == 0 || i == lato - 1 || j == 0 || j == lato - 1) {
                        printf(" * ");
                    } else {
                        printf("   ");
                    }
                }
                printf("\n");
            }
        }
    } while (lato < 1 || lato > 20);

    return 0;
}