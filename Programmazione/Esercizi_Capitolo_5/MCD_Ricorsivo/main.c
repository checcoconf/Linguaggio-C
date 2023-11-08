//Esercizi pag 217 N: 5.39
#include <stdio.h>

int gcd (int,int);

int main() {
    int x = 0, y = 0;
    printf("|Calcolo del Massimo Comune Divisore|\nInserisci il primo numero: ");
    scanf("%d",&x);
    printf("Inserisci il secondo numero: ");
    scanf("%d",&y);
    printf("Il MCD è: %d ",gcd(x,y));
    return 0;
}

int gcd (int x, int y){
    if (y == 0)
        return x;
    return gcd(y,x%y);
}
