#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 5

typedef struct {
    int matricola;
    int voto;
} Studente;

int genera_matricola(void);
int genera_voto(void);
void insert(Studente*);
void stampa(Studente*);
void memorizza_file(Studente*);
void leggi_file(void);

int genera_matricola(void) {
    static int matricole_usate[10000] = {0}; // matricola non utilizzata
    int matricola;

    do {
        matricola = rand() % 10000 + 10000; // genera un numero casuale compreso tra 10000 e 19999
    } while (matricole_usate[matricola - 10000]); // controllo se la matricola è stata usata

    matricole_usate[matricola - 10000] = 1; // 1 = matricola utilizzata
    return matricola;
}


int genera_voto(void) {
    return rand()% 30 + 1;
}

void insert(Studente *S) {
    srand(time(NULL));
    for (int i = 0; i < SIZE; i++){
        S[i].matricola = genera_matricola();
        S[i].voto = genera_voto();
    }
}

void stampa(Studente *S) {
    for (int i = 0; i < SIZE; i++) {
        printf("Studente %d:\tMatricola: |%d|\tVoto: %d\n", i+1, S[i].matricola, S[i].voto);
    }
}

void memorizza_file(Studente *S) {
    FILE *fp;
    fp = fopen("Studenti.txt", "w");
    for (int i = 0; i < SIZE; i++) {
        fprintf(fp, "%d %d\n", S[i].matricola, S[i].voto);
    }
    fclose(fp);
}

void leggi_file() {
    FILE *fp;
    fp = fopen("studenti.txt", "r");
    int matricola, voto;
    printf("\nGli studenti che hanno superato gli esami sono:\n");
    while(fscanf(fp, "%d %d", &matricola, &voto) == 2) { // finchè legge due valori interi
        if(voto >= 18) {
            printf("Matricola: |%d|\tVoto: %d\n",matricola, voto);
        }
    }
    fclose(fp);
}

int main() {
    Studente* S = malloc(SIZE * sizeof(Studente));
    insert(S);
    stampa(S);
    memorizza_file(S);
    leggi_file();
    free(S);
    return 0;
}
