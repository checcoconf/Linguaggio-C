#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct carta{
    const char *valore;
    const char *seme;
};

typedef struct carta Carta;

void creaMazzo(Carta * const, const char *[], const char *[]);
void mescola (Carta * const);
void distribuisci (const Carta * const);

int main() {
    Carta mazzo [52];
    const char *valori[] = {"Asso", "Due","Tre","Quattro",
                          "Cinque","Sei", "Sette","Otto","Nove",
                          "Dieci", "J","Q","K"};

    const char *semi[] = {"Cuori","Quadri", "Fiori","Picche"};
    srand(time(NULL));

    creaMazzo(mazzo,valori,semi);
    mescola(mazzo);
    distribuisci(mazzo);
    return 0;
}

void creaMazzo(Carta * const mazzo, const char * valore[], const char * seme[]){
    for (int i = 0; i <= 51; i++){
        mazzo[i].valore = valore[i % 13]; // posizione array valore
        mazzo[i].seme = seme[i / 13]; // posizione array seme
    }
}

void mescola(Carta * const mazzo){
    int j = 0;
    Carta temp;

    for(int i = 0; i < 51; i++){
        j = rand() % 52;
        temp = mazzo[i];
        mazzo[i] = mazzo[j];
        mazzo[j] = temp;
    }
}

void distribuisci (const Carta* const mazzo){
    for(int i = 0; i <= 51; i++){
        printf("%5s di %-8s%c", mazzo[i].valore,mazzo[i].seme,(i+1) % 4 ? '\t' : '\n');
    }
}
