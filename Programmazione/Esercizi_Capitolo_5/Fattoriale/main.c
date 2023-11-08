#include <stdio.h>

unsigned long long int fattoriale(unsigned int n);
unsigned long long int fattoriale_iterativo(unsigned int n);

int main() {
    return fattoriale(3);
}

// Ricorsivo
unsigned long long int fattoriale(unsigned int n){
    if (n <= 1){
        return 1;
    } else{
        return (n * fattoriale(n-1));
    }
}

// Iterativo
unsigned long long int fattoriale_iterativo(unsigned int n){
    unsigned long long  int risultato = 1;
    for(long long  int i = 2; i <= n; i++){
        risultato*=i;
    }
    return risultato;
}