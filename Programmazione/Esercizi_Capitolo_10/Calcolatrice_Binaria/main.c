#include <stdio.h>
#include <stdbool.h>

void displayBits(unsigned);
int AND (int,int);
int OR (int, int);
int XOR (int, int);
bool isBinary(int num);

int main() {
    int scelta,numero,mask;
    printf("Calcolatrice binaria!"
           "\n1 - Per effettuare una AND tra i bit"
           "\n2 - Per effettuare un OR tra i bit"
           "\n3 - Per effetturare uno XOR tra i bit"
           "\nScrivi qui --> ");
    do {
        scanf("%d",&scelta);
        if (scelta <= 0 || scelta > 3){
            printf("|ERRORE| - La scelta %d non è valida!"
                   "\nRiscrivi qui --> ",scelta);
        }
    }while (scelta <= 0 || scelta > 3);

    printf("Inserisci il numero: ");
    do {
        scanf("%d",&numero);
        if(isBinary(numero) == false){
            printf("|ERRORE| - il numero: %d non è in forma binaria!\nReiserisci qui --> ",numero);
        }
    } while (isBinary(numero) == false);

    printf("Inserisci la maschera: ");
    do {
        scanf("%d",&mask);
        if(isBinary(mask) == false){
            printf("|ERRORE| - la maschera: %d non è in forma binaria!\nReiserisci qui --> ",mask);
        }
    } while (isBinary(mask) == false);

    switch (scelta) {
        case 1:
            displayBits(AND(numero,mask));
            break;
        case 2:
            displayBits(OR(numero,mask));
            break;
        case 3:
            displayBits(XOR(numero,mask));
            break;
    }
}

int AND (int n, int mask){
    return n & mask;
}

int OR (int n, int mask){
    return n | mask;
}

int XOR (int n, int mask){
    return n ^ mask;
}

void displayBits (unsigned value){
    int flag = 3; // 3 spazi in totale
    printf("\nIl risultato in base 16 è: (%X)₁₆"
           "\nIl risultato in base 10 è: (%d)₁₀"
           "\nIl risultato in base 8 è: (%o)₈"
           "\nIl risultato in base 2 è: (",value,value,value);
    unsigned displayMask = 1 << 31; // definisci displayMask ed effettua uno spostamento a sinistra di 31 bit quindi tutti i bit a 0
    // scorri tutti i bit
    for (int b = 0; b < 32; b++){
        putchar(value & displayMask ? '1' : '0');
        if(b % 8 == 7 && flag != 0){ // stampa uno spazio dopo 8 bit // flag per togliere l'ultimo spazio inutile
            putchar(' ');
            flag--;
        }
        value <<= 1;// sposta value a sinistra di 1 bit
    }
    printf(")₂");
}

bool isBinary(int num) {
    int digit;
    while (num > 0) {
        digit = num % 10; // operazione di modulo su ogni sigola cifra
        if (digit != 0 && digit != 1) { // controllo se è diversa da 0 e 1 restituisco false.
            return false;
        }
        num /= 10; // altrimenti continuo a dividere e scorrere le altre cifre
    }
    return true;
}