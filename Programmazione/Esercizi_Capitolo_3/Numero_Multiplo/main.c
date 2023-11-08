#include <stdio.h>

int main() {
    int n = 0;
    const int m = 1000000;
    printf("I multipli di un %d sono: ",m);

    while (n <= 3000000) {
        n++;
            if (n % m == 0) {
                printf("%d\t", n);
            }
    }
}