#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define SIZE_A 19
#define RIGHE 20
#define COLONNE 40

void stampa_retta(char matrice[][COLONNE]);

int main(void) {
    srand(time(NULL));
    int A[SIZE_A] = {};

    //Riempimento del vettore
    for(int i = 0; i <= SIZE_A-1; i++){
        A[i] = rand() %20+1;
    }

    char display[RIGHE][COLONNE];

    // Inizializzazioni della matrice
    for(int i = 0; i < RIGHE; i++){
        for(int j = 0; j < COLONNE; j++){
            display[i][j] = ' ';
        }
    }
    display[0][0] = '^';

    for (int i = 1; i <= 18; i++){
        display[i][0] = '|';
    }

    display[19][0] = '+';

    for(int i = 1; i <= 38; i++){
        display[19][i] = '-';
    }

    display[19][39] = '>';
    // Fine dell'inizializzazione della matrice


    int c;
    for(int i = 0; i < SIZE_A; i++){
        c = 2 +(2*i); // stampa sui numeri pari della matrice escludendo lo 0.
        for (int j = RIGHE - 2; j > RIGHE - 2 - A[i]; j--){
            display[j][c] = '*'; // aggiungo gli asterischi nella matrice
        }
    }

    //Stampa del display matrice
    for(int i = 0; i < RIGHE; i++){
        for(int j = 0; j < COLONNE; j++){
            printf("%2c",display[i][j]);
        }
        printf("\n");
    }

    //Stampa dei numeri del vettore sotto il + --->
    for(int i = 0; i < SIZE_A; i++){
        printf("\t%2d",A[i]);
    }
    return 0;
}

