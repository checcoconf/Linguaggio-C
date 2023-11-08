// Esercizio 4.11 pagina 155
#include <stdio.h>

int main() {
     int scelta = 0;
     unsigned int minimo = 0, n = 0;

    do{
        printf("Quanti numeri vuoi inserire?\nScrivi qui --> ");
        scanf("%d",&scelta);

        if (scelta <= 0){
            printf("|ERRORE|: non è possibile il valore: %d\n",scelta);
        }
    } while (scelta <= 0);

    for (int i = 1; i <= scelta; i++){
        printf("Inserisci il %d valore: ",i);
        scanf("%d",&n);

        if (i == 1){
            minimo = n;
        }
            if (n <= minimo) {
                minimo = n;
            }
    }

    printf("Il numero più piccolo inserito è: %d",minimo);
    return 0;
}