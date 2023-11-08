#include <stdio.h>
#define SIZE 2

typedef struct persona{
    char nome[30];
    unsigned short int eta;
    unsigned short int matricola;
} Persona;


int main() {
    Persona p[SIZE] = {0};

    //Inserimento dati
    for (int i = 0; i < SIZE; i++){
        printf("Inserisci il nome della %d persona: ",i+1);
        scanf("%s",p[i].nome);
        printf("Inserisci l'età della %d persona ",i+1);
        scanf("%hu",&p[i].eta);
        printf("Inserisci la matricola della %d persona ",i+1);
        scanf("%hu",&p[i].matricola);
        puts("");
    }

    //Stampa dati vettore
    for(int i = 0; i < SIZE; i++){
        printf("La %d persona è nome: %s - età: %hu - matricola: %.4hu\n",i+1, p[i].nome, p[i].eta, p[i].matricola);
    }

    return 0;
}
