#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define SIZE 10

void somma_vettori(int[],int[],int);
void prodotto_vettori(int[],int[],int);

int main() {
int a[SIZE],b[SIZE];
srand(time(NULL));
    for (int i = 0;i < SIZE; i++){
        a[i] = rand() %100+1;
        b[i] = rand() %100+1;
    }
    somma_vettori(a,b,SIZE);
    prodotto_vettori(a,b,SIZE);
}

void somma_vettori(int a[], int b[], int size){
    int somma[SIZE];
        printf("|SOMMA TRA DUE VETTORI|\n");

        for (int i = 0; i < SIZE; i++) {
            somma[i] = a[i]+b[i];
            printf("Elementi in posizione %d | %d + %d = %d\n", i,a[i],b[i],somma[i]);
        }
}

void prodotto_vettori(int a[], int b[],int size){
    int prodotto[SIZE];
    printf("|PRODOTTO TRA DUE VETTORI|\n");

    for (int i = 0; i < SIZE; i++) {
        prodotto[i] = a[i]*b[i];
        printf("Elementi in posizione %d | %d * %d = %d\n", i,a[i],b[i],prodotto[i]);
    }
}