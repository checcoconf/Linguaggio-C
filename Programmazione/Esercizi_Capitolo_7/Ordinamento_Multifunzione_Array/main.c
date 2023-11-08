//Programma multifunzione di ordinamento che usa puntatori a funzioni.
#include <stdio.h>
#define SIZE 10

void bubble(int[],const int, int (*)(int, int)); // Puntatore a funzione int con ingressso due paramentri di tipo int.
int ascending (int,int);
int descending (int,int);
void swap(int*,int*);

int main(void) {
    int order = 0, counter, a[SIZE] = {2,6,4,8,10,12,89,68,45,37};
    printf("Inserisci 1 per l'ordine crescente\nInserisci 2 per l'ordine decrescente\nInserisci qui: --> ");
    do {
        scanf("%d",&order);
        if(order != 1 && order != 2){
            printf("|ERRORE| la scelta: %d non è valida\nInserisci qui: --> ",order);
        }
    } while (order != 1 && order != 2);

    for(counter = 0; counter < SIZE; counter++){
        if(order == 1){
            bubble(a,SIZE,ascending);
            printf("Il vettore in ordine crescente è il seguente: ");
        } else{
            bubble(a,SIZE,descending);
            printf("Il vettore in ordine decrescente è il seguente: ");
        }
        for (counter = 0; counter < SIZE; counter++){
            printf("%3d",a[counter]);
        }
    }
    return 0;
}

void bubble(int work[],const int size, int (*compare)(int, int)){
    int pass, count;
    for(pass = 1; pass < size; pass++){
        for (count = 0; count < size ; count++) {
            if((*compare)(work[count],work[count+1])){
                swap(&work[count],&work[count+1]);
            }
        }
    }
}

void swap (int *element1Prt, int *element2Prt){
    int temp;

    temp = *element1Prt;
    *element1Prt = *element2Prt;
    *element2Prt = temp;
}

int ascending(int a, int b){
    return b < a;
}

int descending (int a, int b){
    return b > a;
}