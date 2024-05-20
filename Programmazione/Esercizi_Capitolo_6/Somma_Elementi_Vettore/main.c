// Popolare un vettore di 100 interi con valori casuali compresi tra -100 e 100 e sommare i primi elementi fino ad ottenere un valore >= 200.
// Stampare il numero di elementi sommati.

#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#define SIZE 100

int main() {
    srand(time(NULL));
    int A[SIZE];
    int somma = 0;
    for (int i = 0; i < SIZE; i++){
        A[i] = ((rand()%201)-100);
    }
    for(int i = 0; i < SIZE; i++){
        somma+=A[i];
        if(somma >= 200){
            printf("La somma del vettore è: %d\nGli elementi sommmati sono: %d",somma,i);
            break;
        }
    }
    if(somma < 200){
        printf("|Condizione non rispettata!| la somma è: %d",somma);
    }
    return 0;
}
