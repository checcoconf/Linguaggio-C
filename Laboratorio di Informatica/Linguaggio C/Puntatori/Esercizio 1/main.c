#include <stdio.h>
#include <stdlib.h> // per abs()

void calcolaMinimo(const int* a, const int* b, int* risultato);
void calcolaMassimo(const int* a, const int* b, int* risultato);
void calcolaMedia(const int* a, const int* b, float* risultato);
void calcolaValoreAssoluto(const int* a, int* risultato);

int main() {
    int scelta = -1;
    printf("Effettua la tua scelta!"
           "\n1 - per calcolare il minimo tra due interi."
           "\n2 - per calcolare il massimo tra due interi."
           "\n3 - per calcolare la media tra due interi."
           "\n4 - per calcolare il valore assoluto."
           "\n0 - per uscire."
           "\n\nScrivi qui --> ");
    scanf("%ud",&scelta);

    int n1 = 0, n2 = 0;
    int risultato = 0;
    float media = 0;

    switch (scelta) {
        case 1:
            printf("Inserisci il 1° numero: ");
            scanf("%d",&n1);
            printf("Inserisci il 2° numero: ");
            scanf("%d",&n2);
            calcolaMinimo(&n1,&n2,&risultato);
            printf("Il minimo tra %d e %d è: %d",n1,n2,risultato);
            break;
        case 2:
            printf("Inserisci il 1° numero: ");
            scanf("%d",&n1);
            printf("Inserisci il 2° numero: ");
            scanf("%d",&n2);
            calcolaMassimo(&n1,&n2,&risultato);
            printf("Il massimo tra %d e %d è: %d",n1,n2,risultato);
            break;
        case 3:
            printf("Inserisci il 1° numero: ");
            scanf("%d",&n1);
            printf("Inserisci il 2° numero: ");
            scanf("%d",&n2);
            calcolaMedia(&n1,&n2,&media);
            printf("La media tra %d e %d è: %.2f",n1,n2,media);
            break;
        case 4:
            printf("Inserisci un numero: ");
            scanf("%d",&n1);
            calcolaValoreAssoluto(&n1,&risultato);
            printf("Il valore assoluto di %d è: |%d|",n1,risultato);
        case 0:
            exit(0);
        default:
            printf("|ERRORE| - scelta %d non valida!\n",scelta);
    }
}


void calcolaMinimo(const int* a, const int* b, int* risultato) {
    *risultato = (*a < *b) ? *a : *b;
}

void calcolaMassimo(const int* a, const int* b, int* risultato) {
    *risultato = (*a > *b) ? *a : *b;
}

void calcolaMedia(const int* a, const int* b, float* risultato) {
    *risultato = (*a + *b) / 2.0;
}

void calcolaValoreAssoluto(const int* a, int* risultato) {
    *risultato = abs(*a);
}