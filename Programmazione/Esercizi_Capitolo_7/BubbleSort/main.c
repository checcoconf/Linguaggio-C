#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 20

void bubbleSort(int *, const int);
void swap(int *, int *);

int main() {
    int a[SIZE];
    srand(time(NULL));

    for(int i = 0; i < SIZE; i++) {
        a[i] = (rand()%401)-200;
    }

    printf("Stampa del vettore\n");
    for(int i = 0; i < SIZE; i++){
        printf("Indice %d: %d\n",i,a[i]);
    }

    bubbleSort(a,SIZE);
    printf("\nStampa del vettore ordinato\n");
    for(int i = 0; i < SIZE; i++){
        printf("Indice %d: %d\n",i,a[i]);
    }
    return 0;
}

void bubbleSort(int *array, const int size){

    for(int pass = 0; pass < size-1; pass++){
        for (int j = 0; j < size-1; j++) {
            if(array[j] > array[j+1]){
                swap(&array[j],&array[j+1]);
            }
        }
    }
}

void swap (int *element1Ptr, int *element2Prt){
    int hold = *element1Ptr;
    *element1Ptr = *element2Prt;
    *element2Prt = hold;
}
