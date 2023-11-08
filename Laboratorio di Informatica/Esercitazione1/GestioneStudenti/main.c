#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// definizione della struttura Studente
typedef struct {
    int Matricola;
    char Nome[30];
    char Cognome[30];
    float MediaEsami;
    int NumeroEsamiSostenuti;
} Studente;

// definizione della struttura Nodo
typedef struct nodo {
    Studente S;
    struct nodo *nextPtr;
} Nodo;

// funzione per acquisizione dati di un nuovo studente e inserimento in un nuovo nodo della lista
void acquisizioneDati(Nodo **head) {
    Nodo *new_node = (Nodo *)malloc(sizeof(Nodo));
    printf("Inserisci i dati dello studente:\n");
    printf("Matricola: ");
    scanf("%d", &new_node->S.Matricola);
    printf("Nome: ");
    scanf("%s", new_node->S.Nome);
    printf("Cognome: ");
    scanf("%s", new_node->S.Cognome);
    printf("Media esami: ");
    scanf("%f", &new_node->S.MediaEsami);
    printf("Numero esami sostenuti: ");
    scanf("%d", &new_node->S.NumeroEsamiSostenuti);
    new_node->nextPtr = NULL;

    // inserimento del nuovo nodo nella lista ordinata
    if (*head == NULL || new_node->S.NumeroEsamiSostenuti < (*head)->S.NumeroEsamiSostenuti
        || (new_node->S.NumeroEsamiSostenuti == (*head)->S.NumeroEsamiSostenuti
        && strcmp(new_node->S.Cognome, (*head)->S.Cognome) < 0)) {
        // Se la testa è vuota, il nuovo nodo diventa la testa
        // Se il numero di esami del nuovo nodo è minore del numero di esami della testa, il nuovo nodo diventa la testa
        // Se il numero di esami del nuovo nodo è uguale al numero di esami della testa, ma il cognome del nuovo nodo viene prima in ordine alfabetico, il nuovo nodo diventa la testa
        new_node->nextPtr = *head;
        *head = new_node;
    } else {
        // Altrimenti, scorri la lista e trova la posizione corretta in base al numero di esami e all'ordine alfabetico del cognome
        Nodo *current = *head;
        while (current->nextPtr != NULL && (current->nextPtr->S.NumeroEsamiSostenuti < new_node->S.NumeroEsamiSostenuti
                                            || (current->nextPtr->S.NumeroEsamiSostenuti == new_node->S.NumeroEsamiSostenuti
                                            && strcmp(current->nextPtr->S.Cognome, new_node->S.Cognome) < 0))) {
            current = current->nextPtr;
        }
        // Inserisci il nuovo nodo nella posizione corretta
        new_node->nextPtr = current->nextPtr;
        current->nextPtr = new_node;
    }
}

// funzione per stampare tutti gli studenti nella lista
void stampaStudenti(Nodo *head) {
    if (head == NULL){
        printf("|ERRORE|: la pila è vuota.\n\n");
    }else{
        printf("\nElenco studenti:\n");
        while (head != NULL) {
            printf("Matricola: %d\n"
                   "Nome: %s\n"
                   "Cognome: %s\n"
                   "Media esami: %.2f\n"
                   "Numero esami sostenuti: %d\n\n", head->S.Matricola, head->S.Nome, head->S.Cognome, head->S.MediaEsami, head->S.NumeroEsamiSostenuti);
            head = head->nextPtr;
        }
    }
}

// funzione per ricerca dello studente con media esami più alta
void ricercaMediaEsami(Nodo *head) {
    if (head == NULL){
        printf("|ERRORE|: impossibile effettuare la ricerca la pila è vuota!\n\n");
    }else{
        Nodo *max_node = head;
        while (head != NULL) {
            if (head->S.MediaEsami > max_node->S.MediaEsami) {
                max_node = head;
            }
            head = head->nextPtr;
        }
        printf("\nStudente con media esami più alta"
               "\nMatricola: %d\n"
               "Nome: %s\n"
               "Cognome: %s\n"
               "Media esami: %.2f\n"
               "Numero esami sostenuti: %d\n", max_node->S.Matricola, max_node->S.Nome, max_node->S.Cognome, max_node->S.MediaEsami, max_node->S.NumeroEsamiSostenuti);
    }
}

// funzione per ricerca dello studente con Matricola fornita in input
void ricercaMatricola(Nodo *head) {
    if (head == NULL){
        printf("|ERRORE|: impossibile effettuare la ricerca la pila è vuota!\n\n");
    }else{
        int matricola;
        printf("Inserisci la matricola dello studente da cercare: ");
        scanf("%d", &matricola);
        while (head != NULL) {
            if (head->S.Matricola == matricola) {
                printf("Studente corrispondente"
                       "\nMatricola: %d\n"
                       "Nome: %s\n"
                       "Cognome: %s\n"
                       "Media esami: %.2f\n"
                       "Numero esami sostenuti: %d\n", head->S.Matricola, head->S.Nome, head->S.Cognome, head->S.MediaEsami, head->S.NumeroEsamiSostenuti);
                return;
            }
            head = head->nextPtr;
        }
        printf("\nNessuno studente trovato con la matricola: |%d|.\n",matricola);
    }
}

// funzione principale per il menu dell'utente
int main() {
    Nodo *head = NULL;
    int scelta = 0;
    while (scelta != 5) {
        printf("\t\tMenu\n1. Acquisizione dati studente"
               "\n2. Visualizzazione studente con media esami più alta"
               "\n3. Visualizzazione studente con matricola fornita"
               "\n4. Per stampare la pila"
               "\n5. Per uscire."
               "\n\nScelta: ");
        scanf("%d", &scelta);
        switch (scelta) {
            case 1:
                acquisizioneDati(&head);
                break;
            case 2:
                ricercaMediaEsami(head);
                break;
            case 3:
                ricercaMatricola(head);
                break;
            case 4:
                stampaStudenti(head);
                break;
            case 5:
                printf("\nArrivederci!");
                break;
            default:
                printf("Scelta non valida.\n");
        }
    }
    return 0;
}