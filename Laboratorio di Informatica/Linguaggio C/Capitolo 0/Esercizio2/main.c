#include <stdio.h>

int main() {
    int scelta, num1, num2, risultato;

    printf("Scegli l'operazione aritmetica da svolgere\n");
    printf("1. Somma\n"
           "2. Sottrazione\n"
           "3. Moltiplicazione\n"
           "4. Divisione\n");
    printf("\nInserisci il numero corrispondente all'operazione: ");
    scanf("%d", &scelta);

    printf("Inserisci il primo numero: ");
    scanf("%d", &num1);
    printf("Inserisci il secondo numero: ");
    scanf("%d", &num2);

    switch(scelta) {
        case 1:  // Somma
            risultato = num1 + num2;
            printf("Il risultato della somma e': %d", risultato);
            break;
        case 2:  // Sottrazione
            risultato = num1 - num2;
            printf("Il risultato della sottrazione e': %d", risultato);
            break;
        case 3:  // Moltiplicazione
            risultato = num1 * num2;
            printf("Il risultato della moltiplicazione e': %d", risultato);
            break;
        case 4:  // Divisione
            if(num2 == 0) {
                printf("|Errore|: divisione per zero non consentita");
            } else {
                risultato = num1 / num2;
                printf("Il risultato della divisione e': %d", risultato);
            }
            break;
        default:
            printf("Errore: scelta non valida");
    }

    return 0;
}
