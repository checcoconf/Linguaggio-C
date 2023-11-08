#include <stdio.h>

int main() {
    char C[] = "Nel mezzo del cammin di nostra vita";
    int i = 0, vocali = 0, consonanti = 0, lunghezzafrase = 0;
    while (C[i] != '\0'){
        if(C[i] == 'a' || C[i] == 'e' || C[i] == 'i' || C[i] == 'o' || C[i] == 'u'){
            vocali++;
        } else{
            if (C[i] != ' '){ // Escludo gli spazi
                consonanti++;
            }
        }
        lunghezzafrase++;
        i++; // Vado avanti nella frase
    }
    lunghezzafrase = i;
    printf("La lunghezza del vettore è: %d\nIl numero delle vocali è: %d\nIl numero delle consonanti è: %d\nIl valore medio dei caratteri è: %d",lunghezzafrase,vocali,consonanti,lunghezzafrase/2);
    return 0;
}
