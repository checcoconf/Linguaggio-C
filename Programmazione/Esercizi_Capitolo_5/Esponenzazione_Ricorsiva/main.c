// Eserizio 5.34 pag. 215
#include <stdio.h>

long int power(int, int);

int main() {
    int base = 0, esponente = 0;
    printf("Calcolo di una potenza.\nInserisci qui la base: ");
    scanf("%d", &base);
    printf("Inserisci qui l'esponente: ");
    do {
        scanf("%d", &esponente);
        if (esponente < 0) {
            printf("|ERRORE| impossibile avere %d come esponente.\nRiscrivi l'esponente qui --> ", esponente);
        }
    } while (esponente < 0);
    if (base == 0 && esponente == 0) {
        printf("Il numero %d elevato a %d: NON HA SIGNIFICATO.", base, esponente);
    } else {
        printf("Il numero %d elevato a %d è = %ld", base, esponente, power(base, esponente));
    }

    return 0;
}

long int power(int base, int esponente) {

    if (esponente == 0) {
        return 1;
    } else {
        return base * power(base, esponente - 1);
    }
}