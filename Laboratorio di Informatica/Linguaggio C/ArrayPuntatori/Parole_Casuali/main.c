/**
 * Copyright © 2023
 * Francesco Conforti ~ 30/03/23 19.36
 * Tutti i diritti riservati.
 **/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define LUNGHEZZA 10 // lunghezza massima per parola
#define PAROLE 5 // parole generate

char* generaCaratteriCasuale(int);
void stampaParole(char**,int);
void generaParoleCasuali(char**,int);
void bubble_sort(char**,int);
void swap(char*, char*);

char* generaCaratteriCasuale(int lunghezza) {
    char* parola = (char*) malloc((lunghezza + 1) * sizeof(char));
    for (int i = 0; i < lunghezza; i++) {
        *(parola + i) = (char) ('a' + rand() % 26); // generazione caratteri casuali
    }
    *(parola + lunghezza) = '\0'; // terminazione stringa
    return parola;
}

void generaParoleCasuali(char** parole, int num_parole) {
    srand(time(NULL)); // inizializza il generatore di numeri casuali

    // genera le parole casuali
    printf("Generazione di %d parole casuali:\n", num_parole);
    for (int i = 0; i < num_parole; i++) {
        int lunghezza = rand() % LUNGHEZZA + 1; // lunghezza casuale tra 1 e LUNGHEZZA
        char* parola = generaCaratteriCasuale(lunghezza);
        strncpy(*(parole + i), parola,LUNGHEZZA);
        free(parola);
    }
}

void stampaParole(char** parole, int num_parole) {
    for (int i = 0; i < num_parole; i++) {
        printf("%d: %s\n", i + 1, *(parole + i));
    }
}

void bubble_sort(char **parole, int num_parole) {
    for (int i = 0; i < num_parole - 1; i++) {
        for (int j = 0; j < num_parole - i - 1; j++) {
            if (strncmp(parole[j], parole[j + 1],LUNGHEZZA) > 0) {
                swap(parole[j], parole[j + 1]);
            }
        }
    }
}

void swap(char *str1, char *str2) {
    char tmp[LUNGHEZZA] = {"\0"};
    strncpy(tmp, str1,LUNGHEZZA);
    strncpy(str1, str2,LUNGHEZZA);
    strncpy(str2, tmp,LUNGHEZZA);

}

int main() {
    char* parole[PAROLE] = {"\0"};
    for (int i = 0; i < PAROLE; i++) {
        parole[i] = (char*) malloc(LUNGHEZZA * sizeof(char)); // array di puntatori a caratteri malloc per ogni parola
    }
    generaParoleCasuali(parole, PAROLE);
    stampaParole(parole,PAROLE);
    bubble_sort(parole,PAROLE);
    printf("\nParole ordinate in modo lessicografico:\n");
    stampaParole(parole, PAROLE);

    for (int i = 0; i < PAROLE; i++) {
        free(parole[i]); // libero la memoria per ogni parola creata
    }

    return 0;
}