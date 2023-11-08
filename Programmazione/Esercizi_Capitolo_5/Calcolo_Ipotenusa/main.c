// Esercizio 5.15 pag.212
#include <stdio.h>
#include <math.h>

double hypotenuse (double cateto1, double cateto2){
    if (cateto1 <= 0.00 || cateto2 <= 0.00){
        printf("|ERRORE| i cateti non possono assumere valori <= 0.00\n");
        return 0.00;
    }else{
        double ipotenusa = sqrt((cateto1*cateto1)+(cateto2*cateto2));
        return ipotenusa;
    }
}

int main() {
    double cateto1 = 0.00, cateto2 = 0.00;
    printf("Calcolo dell'ipotenusa di un triangolo rettangolo!\nInserire il valore dei due cateti\nCateto 1: ");
    scanf("%lf",&cateto1);
    printf("Cateto 2: ");
    scanf("%lf",&cateto2);

    printf("L'ipotenusa vale: %.2lf",hypotenuse(cateto1,cateto2));

    return 0;
}