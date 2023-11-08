#include <stdbool.h>

// definizione della struttura Nodo
typedef struct {
    unsigned int Matricola;
    char Nome[30];
    char Cognome[30];
    float MediaEsami;
    unsigned int NumeroEsamiSostenuti;
} Studente;

// definizione della struttura Nodo
typedef struct Nodo {
    Studente S;
    struct nodo *nextPtr;
} Nodo;

void inserisciStudente(Nodo**);
void stampaStudenti(const Nodo*);
void cancellaLista(Nodo *head);
bool confrontaStudenti(const Studente *, const Studente *);
Studente sommaStudenti(const Studente *, const Studente *);
void svuotaLista(Nodo **);