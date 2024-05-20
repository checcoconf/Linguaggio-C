#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 50000

void bubbleSort(int *, const int);
void swap(int *, int *);

int main() {
    int a[SIZE] = {0};
    srand(time(NULL));

    //Riempimento vettore
    for(int i = 0; i < SIZE; i++) {
        a[i] = (rand()%401)-200;
    }
    float t1 = clock();
    //Ordinamento vettore
    bubbleSort(a,SIZE);
    float t2 = clock();
    float t3 = (t2-t1)/(float)CLOCKS_PER_SEC;
    printf("Il tempo impiegato per l'ordinamento è: %f",t3);

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
