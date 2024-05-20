#include <stdio.h>
#define STUDENTI 2
#define ESAMI 5

typedef struct {
    int giorno;
    char mese[20];
    int anno;
} Data;

typedef struct {
    char nome[20];
    char cognome[15];
    Data data_di_nascita;
    int voti[ESAMI];
} Studente;

// Prototipo di funzione
void acquisisci_voti_studenti(Studente **);
void stampa_studente(Studente **);

// Funzione per acquisire i dati di ciascuno studente
void acquisisci_voti_studenti(Studente **S) {
    for (int i = 0; i < STUDENTI; i++) {
        printf("Inserisci i dati del %d studente\n", i + 1);
        printf("Nome: ");
        scanf("%s", S[i]->nome);
        printf("Cognome: ");
        scanf("%s", S[i]->cognome);
        printf("Giorno di nascita: ");
        scanf("%d", &S[i]->data_di_nascita.giorno);
        printf("Mese di nascita: ");
        scanf("%s", S[i]->data_di_nascita.mese);
        printf("Anno di nascita: ");
        scanf("%d", &S[i]->data_di_nascita.anno);
        printf("Inserisci %d voti di esame\n", ESAMI);
        for (int j = 0; j < ESAMI; j++) {
            printf("Voto %d: ", j + 1);
            scanf("%d", &S[i]->voti[j]);
        }
    }
}

void stampa_studente(Studente **S) {
    for (int i = 0; i < STUDENTI; i++) {
        printf("\nStudente %d\n", i + 1);
        printf("Nome: %s\n"
               "Cognome: %s\n"
               "Data di nascita: %d %s %d\n",
               S[i]->nome, S[i]->cognome, S[i]->data_di_nascita.giorno, S[i]->data_di_nascita.mese, S[i]->data_di_nascita.anno);
        for (int j = 0; j < ESAMI; j++) {
            printf("Voto %d: %d\n", j + 1, S[i]->voti[j]);
        }
    }
}

int main() {
    Studente S[STUDENTI];
    Studente *pS[STUDENTI];
    for (int i = 0; i < STUDENTI; i++) {
        pS[i] = &S[i];
    }
    acquisisci_voti_studenti(pS);
    stampa_studente(pS);
    return 0;
}
