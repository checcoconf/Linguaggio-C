//Esercizio 5.35 pag. 215
#include <stdio.h>

unsigned long long int fibonacci(unsigned int);
unsigned long long int fibonacci_ricorsivo(unsigned int);

int main() {
    printf("Inserisci un numero: ");
    int n = 0;
    do {
        scanf("%d",&n);
        if (n < 0){
            printf("|ERRORE| - non sono ammessi numeri negativi.\nInserisci un numero positivo --> ");
        }
    } while (n < 0);

    printf("Fibonacci (%d) = %llu",n, fibonacci_ricorsivo(n));
    return 0;
}
// Caso iterativo
unsigned long long fibonacci(unsigned int n) {
    int f0 = 0, f1 = 1, fn;
    if (n == 0) {
        return n;
    }

    for (int i = 2; i <= n; i++) {
        fn = f0 + f1;
        f0 = f1;
        f1 = fn;
    }
    return f1;
}

// Caso ricorsivo
unsigned long long int fibonacci_ricorsivo(unsigned int n){
    if (0 == n || 1 == n){
        return n;
    } else{
        return fibonacci(n-1)+ fibonacci(n-2);
    }
}