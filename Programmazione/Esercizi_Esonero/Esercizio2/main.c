#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main() {
    int A[100] = {0}, B[50] = {0}, j = 0, max = 0;
    srand(time(NULL));

    // Riempimento del vettore A con numeri random
    for(int i = 0; i < 100; i++){
        A[i] = (rand()%101)-50;
    }

    // Riempimento del vettore B
    for(int i = 0; i < 100; i+=2){
        B[j] = A[i]+A[i+1];
        j++;
    }

    // Massimo degli elementi in posizione dispari
    max = B[1];
    for(int i = 3 ;i < 50; i+=2){
        if(max < B[i]){
            max = B[i];
        }
    }
    printf("Il massimo degli elementi di B in posizione dispari è: %d",max);
    return 0;
}
