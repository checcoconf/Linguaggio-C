#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void mescola (int [][13]);
void distribuisci (const int [][13], const char *[], const char *[]);

int main() {
    const char *semi[4] = {"Cuori","Quadri", "Fiori","Picche"};
    const char *valori[13] = {"Asso", "Due","Tre","Quattro",
                              "Cinque","Sei", "Sette","Otto","Nove",
                              "Dieci", "J","Q","K"};
    int mazzo[4][13] = {0};
    srand(time(NULL));

    mescola(mazzo);
    distribuisci(mazzo,valori,semi);
    return 0;
}

void mescola(int mazzo[][13]){
    int riga, colonna, carta;

    for(carta = 1; carta <= 52; carta++){
        do{
            riga = rand()%4; // ottengo il seme
            colonna = rand()%13; // ottengo il valore della carta
        } while (mazzo[riga][colonna] != 0); // Fino a quando rimepio il mazzo.
        mazzo[riga][colonna] = carta;
    }
}

void distribuisci(const int mazzo[][13], const char *semi[], const char *valori[]){
    int riga, colonna, carta;

    for(carta = 1; carta <= 52; carta++){
        for (riga = 0; riga <= 3; riga++){
            for(colonna = 0; colonna <= 12; colonna++){
                if (mazzo[riga][colonna] == carta){ // Se la carta è contenuta nell'mazzo stampala
                    printf("%5s di %-8s%c",semi[colonna],valori[riga], carta % 8 == 0 ? '\n' : '\t'); // Formato a otto colonne
                }
            }
        }
    }
}
