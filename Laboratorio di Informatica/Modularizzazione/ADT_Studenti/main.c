#include "Studente/Studente.h"
#include <stdio.h>

int main() {
    Nodo* head = NULL;
    int scelta;

    do {
        printf("\tMenu\n");
        printf("1. Inserisci dati studente\n");
        printf("2. Confronta due studenti\n");
        printf("3. Somma due studenti\n");
        printf("4. Stampa lista studenti\n");
        printf("0. Esci\n");
        printf("Scelta: ");
        scanf("%d", &scelta);

        switch (scelta) {
            case 1:
                svuotaLista(&head);
                for (int i = 1; i <= 2; i++) {
                    printf("\t|Studente %d|\n",i);
                    inserisciStudente(&head);
                }
                break;
            case 2: {
                if (head == NULL || head->nextPtr == NULL) {
                    printf("|ERRORE| - Devi inserire almeno due studenti per confrontarli.\n");
                } else {
                    Nodo *current = head;
                    Studente studente1 = current->S;
                    current = (Nodo *) current->nextPtr;
                    Studente studente2 = current->S;
                    if (confrontaStudenti(&studente1, &studente2)){
                        printf("I due studenti sono uguali.\n");
                    }
                    else{
                        printf("I due studenti sono diversi.\n");
                    }
                }
                break;
            }
            case 3: {
                if (head == NULL || head->nextPtr == NULL) {
                    printf("|ERRORE| - Devi inserire almeno due studenti per effettuare la somma.\n");
                } else {
                    Nodo *current = head;
                    Studente studente1 = current->S;
                    current = (Nodo *) current->nextPtr;
                    Studente studente2 = current->S;
                    Studente risultato = sommaStudenti(&studente1, &studente2);
                    printf("Risultato della somma:\n");
                    printf("Media esami: %.2f\n", risultato.MediaEsami);
                    printf("Numero esami sostenuti: %u\n", risultato.NumeroEsamiSostenuti);
                }
                break;
            }
            case 4:
            if (head != NULL){
                stampaStudenti(head);
            } else{
                printf("|ERRORE| - La lista è vuota!\n");
            }
                break;
            case 0:
                printf("Arrivederci!\n");
                break;
            default:
                printf("Scelta non valida.\n");
                break;
        }
    } while (scelta != 0);

    cancellaLista(head);

    return 0;
}
