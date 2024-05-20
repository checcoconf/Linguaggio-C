#include <stdio.h>

int main() {
    unsigned int n = 0;
    const unsigned int limite_largo = 99999;
    const unsigned int limite_stretto = 10000;

    do {
        printf("Inserisci un numero: ");
        scanf("%d", &n);

        if (n > limite_largo){
            printf("Inserire un numero <= di %d.\n",limite_largo);
        }
        else if (n < limite_stretto){
            printf("Inserire un numero >= di %d.\n",limite_stretto);
        }
    } while (n < limite_stretto || n >= limite_largo);

    const unsigned int unità = n / 10000;
    const unsigned int decina = (n % 10000) / 1000;
    const unsigned int centinaio = ((n % 10000) % 1000) / 100;
    const unsigned int migliaio = (((n % 10000) % 1000) % 100) / 10;
    const unsigned int decina_di_migliaia = (((n % 10000) % 1000) % 100) % 10;

    if ((unità == decina_di_migliaia) && (decina == migliaio)){
        printf("Il numero %d è palindromo!",n);
    } else{
        printf("Il numero %d non è palindromo!",n);
    }

    return 0;
}