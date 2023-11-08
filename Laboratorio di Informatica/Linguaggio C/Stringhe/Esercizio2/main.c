#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STR_LEN 50

void insert(char ***);
void scambio(char **, int, int);
int contaparole(char **, char *);
void rimpiazza(char **, const char *, char *);
void stampa(char **);

void insert(char ***pM) {
    int n;
    printf("Inserisci il numero di frasi che vuoi inserire: ");
    scanf("%d", &n);
    getchar(); // Consuma il carattere newline lasciato dallo scanf

    char **M = (char **) malloc(n * sizeof(char *)); // Allocazione dinamica dell'array di puntatori a char
    if (M == NULL) {
        printf("Errore di allocazione della memoria.");
        exit(1);
    }

    for (int i = 0; i < n; i++) {
        printf("Inserisci la frase %d: ", i + 1);

        // Allocazione dinamica della stringa
        char *str = (char *) malloc(MAX_STR_LEN * sizeof(char));
        if (str == NULL) {
            printf("Errore di allocazione della memoria.");
            exit(1);
        }
        scanf("%s",str);
        M[i] = str; // Aggiunge il puntatore alla stringa all'array di puntatori
    }

    *pM = M; // Assegna il puntatore all'array di stringhe alla variabile M nella funzione chiamante
}

void stampa(char **M) {
    int i = 0;
    printf("Stampa Matrice\n");
    while (M[i] != NULL) {
        printf("%d: %s\n", i, M[i]);
        i++;
    }
}

void scambio(char **M, int i, int j) {
    char *temp = M[i];
    M[i] = M[j];
    M[j] = temp;
}

int contaparole(char **M, char *p) {
    int count = 0, i = 0;
    while (M[i] != NULL) { // Fino a quando non scorro tutte le parole
        char *token = strtok(M[i], "\n");
        while (token != NULL) {
            if (strcmp(token, p) == 0) {
                count++;
            }
            token = strtok(NULL, "\n");
        }
        i++;
    }
    return count;
}

void rimpiazza(char **M, const char *p1, char *p2) {
    size_t p1_len = strlen(p1);
    size_t p2_len = strlen(p2);
    for (int i = 0; M[i] != NULL; i++) {
        char *c = M[i];
        while ((c = strstr(c, p1)) != NULL) {
            memmove(c + p2_len, c + p1_len, strlen(c + p1_len) + 1);
            memcpy(c, p2, p2_len);
            c += p2_len;
        }
    }
}


int main() {
    char **M = NULL;
    printf("\t\tBenvenuto!\n");
    insert(&M);

    int scelta = 0, i = 0, j = 0;
    char *parola = (char *) malloc(MAX_STR_LEN * sizeof(char));
    char *parola2 = (char *) malloc(MAX_STR_LEN * sizeof(char));

    do{
        printf("\n\tMENU DI SCELTA:\n");
        printf("1. Cambia le parole inserite\n");
        printf("2. Sostituisci una parola con un'altra\n");
        printf("3. Conta quante volte la parola viene ripetuta\n");
        printf("4. Rimpiazza una parola con un altra\n");
        printf("5. Esci\n");
        printf("Inserisci qui --> ");
        scanf("%d",&scelta);

        switch (scelta) {
            case 1:
                insert(&M);
                break;
            case 2:
                stampa(M);
                printf("Inserisci l'indice che vuoi scambiare: ");
                scanf("%d",&i);
                printf("Inserisci l'indice con cui vuoi scambiare: ");
                scanf("%d",&j);
                scambio(M,i,j);
                stampa(M);
                break;
            case 3:
                printf("Inserisci la parola che vuoi controllare: ");
                scanf("%s",parola);
                printf("La parola compare %d volte.\n", contaparole(M, parola));
                break;
            case 4:
                stampa(M);
                printf("Inserisci la parola che vuoi rimpiazzare: ");
                scanf("%s",parola);
                printf("Inserisci la parola con la quale vuoi rimpiazzare: ");
                scanf("%s",parola2);
                rimpiazza(M,parola,parola2);
                stampa(M);
                break;
            case 5:
                scelta = 5;
                printf("Arrivederci!");
                break;
            default:
                printf("|ERRORE| - scelta %d non accettata",scelta);
        }
    } while (scelta != 5);

    // Deallocazione della memoria
    for (int d = 0; d < sizeof(M) / sizeof(M[0]); d++) {
        free(M[d]);
    }

    return 0;
}