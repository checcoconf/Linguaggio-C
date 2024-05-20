// Esercizio pag. 421 n.9.12
#include <stdio.h>

int main() {
    float celsius;
    char c[] = "°C";
    char f[] = "°F";

    printf("Fahrenheit\t\tCelsius\n");
    for (int fahrenheit = 0; fahrenheit <= 212; fahrenheit++) {
        celsius = 5.0 / 9.0 * (fahrenheit - 32);
        printf("%8d%s\t%9.3f%s\n",fahrenheit,f, celsius,c);
    }

    return 0;
}
