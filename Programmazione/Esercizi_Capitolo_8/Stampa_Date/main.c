//Esercizio N.8.32 pag.391
#include <stdio.h>
#include <string.h>

int main() {
    int mese = 0,giorno = 0,anno = 0;
    printf("Inserisci una data nel formato |MM/GG/AAAA|");
    printf("\nInserisci il mese: ");
    do {
        scanf("%d",&mese);
        if(mese == 0 || mese > 12){
            printf("|ERRORE| - Il mese: %d non è valido\nReinseriscilo qui --> ",mese);

        }
    } while (mese == 0 || mese > 12);

    printf("Inserisci il giorno: ");
    do {
        scanf("%d",&giorno);
        if(giorno == 0 || giorno > 31){
            printf("|ERRORE| - Il giorno: %d non è valido\nReinseriscilo qui --> ",giorno);
        }
    } while (giorno == 0 || giorno > 31);

    printf("Inserisci l'anno: ");
    do {
        scanf("%d",&anno);
        if(anno < 1900){
            printf("|ERRORE| - L'anno: %d non è valido\nReinseriscilo qui --> ",anno);
        }
    } while (anno < 1900);

    char *mesi[13] = {NULL,"Gennaio","Febbraio","Marzo","Aprile",
                      "Maggio","Giugno","Luglio","Agosto","Settembre",
                      "Ottobre","Novembre","Dicembre"};

    printf("La data è: %s %d, %d",mesi[mese],giorno,anno);
    return 0;
}
