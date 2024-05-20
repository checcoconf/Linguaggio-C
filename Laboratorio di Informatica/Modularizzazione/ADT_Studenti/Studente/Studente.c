#include "Studente.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

void inserisciStudente(Nodo **head) {
    Nodo *nuovoNodo = malloc(sizeof(Nodo));
    printf("Inserisci la matricola: ");
    scanf("%u", &(nuovoNodo->S.Matricola));
    printf("Inserisci il nome: ");
    scanf("%s", nuovoNodo->S.Nome);
    printf("Inserisci il cognome: ");
    scanf("%s", nuovoNodo->S.Cognome);
    printf("Inserisci la media degli esami: ");
    scanf("%f", &(nuovoNodo->S.MediaEsami));
    printf("Inserisci il numero di esami sostenuti: ");
    scanf("%u", &(nuovoNodo->S.NumeroEsamiSostenuti));

    nuovoNodo->nextPtr = NULL;

    if (*head == NULL) {
        *head = nuovoNodo;
    } else {
        Nodo *current = *head;
        while (current->nextPtr != NULL) {
            current = (Nodo *) current->nextPtr;
        }
        current->nextPtr = (struct nodo *) nuovoNodo;
    }
}

void stampaStudenti(const Nodo *head) {
    const Nodo *current = head;
    unsigned int index = 1;

    while (current != NULL) {
        printf("\n|Dati studente %d|\n", index);
        printf("Matricola: %u\n", current->S.Matricola);
        printf("Nome: %s\n", current->S.Nome);
        printf("Cognome: %s\n", current->S.Cognome);
        printf("Media esami: %.2f\n", current->S.MediaEsami);
        printf("Numero esami sostenuti: %u\n", current->S.NumeroEsamiSostenuti);

        current = (const Nodo *) current->nextPtr;
        index++;
    }
}

void cancellaLista(Nodo *head) {
    Nodo *current = head;
    while (current != NULL) {
        Nodo *temp = current;
        current = (Nodo *) current->nextPtr;
        free(temp);
    }
}

bool confrontaStudenti(const Studente *studente1, const Studente *studente2) {
    if (strcmp(studente1->Nome, studente2->Nome) == 0 && studente1->MediaEsami == studente2->MediaEsami)
        return true;
    else
        return false;
}

Studente sommaStudenti(const Studente *studente1, const Studente *studente2) {
    Studente somma;
    somma.MediaEsami = (studente1->MediaEsami + studente2->MediaEsami) / 2;
    somma.NumeroEsamiSostenuti = studente1->NumeroEsamiSostenuti + studente2->NumeroEsamiSostenuti;
    return somma;
}

void svuotaLista(Nodo **head) {
    Nodo *current = *head;
    Nodo *next;

    while (current != NULL) {
        next = (Nodo *) current->nextPtr;
        free(current);
        current = next;
    }

    *head = NULL;
}
