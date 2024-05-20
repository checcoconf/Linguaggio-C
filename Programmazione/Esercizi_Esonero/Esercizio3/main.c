#include <stdio.h>
long int f (long int);

int main(){
    long int n = 0;
    printf("Inserisci un numero: ");
    scanf("%ld", &n);
    n = f(n);
    printf("%ld", n);
}

long int f(long int n){
    int z = 0;
    long int y, m = 1;
    y = n; // copia di n
    // contatore delle cifre di n, ignorando l'ultima
    while (n / 10 != 0){
        n = n / 10;
        z++;
    }
    n = y; //ripristino di n
    // aggiunta degli zeri in base al contatore
    for (int h = 0; h < z; h++){
        n = n * 10;
    }
    for (int u = 0; u < z + 1; u++){
        if (u == 0){
            y = y / 10; // eliminazione dell'ultima cifra
        }
        else{
            for (int h = u; h < z; h++){
                m = m * 10; // moltiplicatore
            }
            n = n + ((y % 10) * m); // aggiunge la cifra
            m = 1;                  // reset di m
            y = y / 10;             // eliminazione cifra
        }
    }
    return n;
}