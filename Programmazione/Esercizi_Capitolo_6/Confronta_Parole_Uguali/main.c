//Date due parole da tastiera, scoprire se sono uguali o diverse.
#include <stdio.h>
#define SIZE 50

int main() {
    char A[SIZE] = {'\0'};
    char B[SIZE] = {'\0'};

    printf("Inserisci la prima parola: ");
    scanf("%s",A);
    printf("Inserisci la seconda parola: ");
    scanf("%s",B);

    int i = 0, f = 0;

    for(i = 0; i < SIZE; i++){
        if(A[i] == '\0' && B[i] == '\0'){
            printf("Le parole sono uguali");
            break;
        }
        if(A[i] != B[i]) {
            printf("La parole sono diverse!");
            f = 1;
            break;
        }
    }

    if((A[i] != '\0') && (B[i] != '\0') && (f == 0)){
        printf("Errore!");
    }

    return 0;
}
