// Esercizio 4.16 pag.155
#include <stdio.h>

void triangolo_A();
void triangolo_B();
void triangolo_C();
void triangolo_D();

int main() {
    int scelta = 0;

    printf("Scegliere un numero da 1 a 4.\nScrivi qui --> ");
    do {
        scanf("%d",&scelta);
        if (scelta < 1 || scelta > 4){
            printf("|ERRORE| - scelta non valida - Inserire dei valori da 1 a 4.\nScrivi qui --> ");
        }
    } while (scelta < 1 || scelta > 4);

    switch (scelta) {
        case 1:
            triangolo_A();
            break;
        case 2:
            triangolo_B();
            break;
        case 3:
            triangolo_C();
            break;
        case 4:
            triangolo_D();
            break;
    }
    return 0;
}

void triangolo_A() {
    printf("(A)\n");
    //Ciclo di incremento per gli asterischi
    for (int i = 0; i < 10; i++) {
        if (i != 0) {
            printf("\n");
        }
        //Stampa degli asterischi
        for (int j = 0; j <= i; j++) {
            if (j <= i) {
                printf("%s", "*");
            }
        }
    }
}

void triangolo_B(){
    printf("(B)\n");
    //Ciclo di decremento per gli asterischi
    for (int i = 10; i >= 1; i--) {
        if (i != 10) {
            printf("\n");
        }
        //Stampa degli asterischi
        for (int j = 1; j <= i; j++) {
            if (j <= i) {
                printf("%s", "*");
            }
        }
    }
}

void triangolo_C(){
    printf("(C)\n");
    //Ciclo di decremento per gli asterischi
    for (int i = 10; i >= 1; i--) {
        // Stampa 10 - righe di spazi
        for (int j = 1; j <= 10 - i ; j++) {
            printf("%s"," ");
        }
        //Stampa asterischi delle righe
        for (int k = 1; k <= i; k++){
            printf("%s","*");
        }
        if (i != 1){
            printf("\n");
        }
    }
}

void triangolo_D(){
    printf("(D)\n");
    //Ciclo di incremento per gli asterischi
    for (int i = 1; i <= 10; i++) {
        // Stampa 10 - righe di spazi
        for (int j = 1; j <= 10 - i ; j++) {
            printf("%s"," ");
        }
        //Stampa asterischi delle righe
        for (int k = 1; k <= i; k++){
            printf("%s","*");
        }
        if (i != 10){
            printf("\n");
        }
    }
}