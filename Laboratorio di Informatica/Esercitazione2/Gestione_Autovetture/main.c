#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct Autovettura {
    int NumeroTelaio;
    char Marca[31];
    int Cilindrata;
    int AnnoImmatricolazione;
    struct Autovettura *nextPtr;
} Autovettura;

void acquisizioneDati(Autovettura**);
void stampaAutovettura(Autovettura*);
void eliminaAutovettura(Autovettura**,int);
void rimuoviDuplicati(Autovettura*);
void swap(Autovettura*,Autovettura*);
void bubbleSort(Autovettura*);

void acquisizioneDati(Autovettura **headPtr) {
    Autovettura *newPtr = malloc(sizeof(Autovettura));
    if (newPtr == NULL) {
        printf("ERRRORE: memoria insufficiente.\n");
        return;
    }
    printf("Inserisci il numero di telaio: ");
    scanf("%d", &newPtr->NumeroTelaio);
    printf("Inserisci la marca: ");
    scanf("%30s", newPtr->Marca);
    printf("Inserisci la cilindrata: ");
    scanf("%d", &newPtr->Cilindrata);
    printf("Inserisci l'anno di immatricolazione: ");
    scanf("%d", &newPtr->AnnoImmatricolazione);
    newPtr->nextPtr = NULL;

    if (*headPtr == NULL) {
        *headPtr = newPtr;
    } else {
        Autovettura *currPtr = *headPtr;
        while (currPtr->nextPtr != NULL) {
            currPtr = currPtr->nextPtr;
        }
        currPtr->nextPtr = newPtr;
    }
}

void stampaAutovettura(Autovettura *headPtr) {
    if (headPtr == NULL) {
        printf("La lista di autovetture è vuota.\n");
    } else {
        printf("\nElenco auto:\n");
        while (headPtr != NULL) {
            printf("Numero Telaio: %d\n"
                   "Marca: %s\n"
                   "Cilindrata: %d\n"
                   "Anno Immatricolazione: %d\n\n",
                   headPtr->NumeroTelaio, headPtr->Marca, headPtr->Cilindrata, headPtr->AnnoImmatricolazione);
            headPtr = headPtr->nextPtr;
        }
    }
}

void eliminaAutovettura(Autovettura **headPtr, int anno) {
    Autovettura *current = *headPtr;
    Autovettura *previous = NULL;
    bool autoEliminata = false;

    while (current != NULL) {
        if (current->AnnoImmatricolazione < anno) {
            autoEliminata = true;
            if (previous == NULL) {
                *headPtr = current->nextPtr;
            } else {
                previous->nextPtr = current->nextPtr;
            }
            Autovettura *temp = current;
            current = current->nextPtr;
            free(temp);
        } else {
            previous = current;
            current = current->nextPtr;
        }
    }
    if (!autoEliminata) {
        printf("Non ci sono autovetture con anno di immatricolazione inferiore a %d\n", anno);
    }
}

void rimuoviDuplicati(Autovettura *head) {
    Autovettura *current, *successivo, *temp;
    current = head;
    while (current != NULL && current->nextPtr != NULL) {
        successivo = current;
        while (successivo->nextPtr != NULL) {
            if (strcmp(current->Marca, successivo->nextPtr->Marca) == 0 && current->Cilindrata == successivo->nextPtr->Cilindrata) {
                temp = successivo->nextPtr;
                successivo->nextPtr = successivo->nextPtr->nextPtr;
                free(temp);
            } else {
                successivo = successivo->nextPtr;
            }
        }
        current = current->nextPtr;
    }
}

// Funzione che scambia due elementi in una lista
void swap(Autovettura* a, Autovettura* b) {
    int tempNT = a->NumeroTelaio;
    char tempMarca[31];
    strcpy(tempMarca, a->Marca);
    int tempCil = a->Cilindrata;
    int tempAnno = a->AnnoImmatricolazione;

    a->NumeroTelaio = b->NumeroTelaio;
    strcpy(a->Marca, b->Marca);
    a->Cilindrata = b->Cilindrata;
    a->AnnoImmatricolazione = b->AnnoImmatricolazione;

    b->NumeroTelaio = tempNT;
    strcpy(b->Marca, tempMarca);
    b->Cilindrata = tempCil;
    b->AnnoImmatricolazione = tempAnno;
}

// Funzione che esegue il bubble sort sulla lista
void bubbleSort(Autovettura* head) {
    int swapped = 1;
    Autovettura* ptr1;
    Autovettura* lptr = NULL;

    // Se la lista è vuota o ha solo un elemento, non serve ordinare
    if (head == NULL || head->nextPtr == NULL) {
        return;
    }

    while (swapped) {
        swapped = 0;
        ptr1 = head;

        while (ptr1->nextPtr != lptr) {
            // Se le due auto sono in ordine inverso, scambiale
            if ((ptr1->Cilindrata > ptr1->nextPtr->Cilindrata) ||
                ((ptr1->Cilindrata == ptr1->nextPtr->Cilindrata) &&
                 (ptr1->AnnoImmatricolazione > ptr1->nextPtr->AnnoImmatricolazione))) {
                swap(ptr1, ptr1->nextPtr);
                swapped = 1;
            }
            ptr1 = ptr1->nextPtr;
        }
        lptr = ptr1;
    }
}

int main() {
    Autovettura *A = NULL;
    int scelta = 0, anno = 0;
    while (scelta != 6) {
        printf("\t\tMenu\n1. Per inserire una nuova autovettura."
               "\n2. Per eliminare delle autovetture."
               "\n3. Per rimuovere eventuali duplicati."
               "\n4. Per ordinare la lista."
               "\n5. Per stampare la lista."
               "\n6. Per uscire."
               "\n\nScelta: ");
        scanf("%d", &scelta);
        switch (scelta) {
            case 1:
                acquisizioneDati(&A);
                break;
            case 2:
                printf("Inserisci l'anno di immatricolazione per eliminare le autovetture: ");
                scanf("%d",&anno);
                eliminaAutovettura(&A,anno);
                break;
            case 3:
                rimuoviDuplicati(A);
                break;
            case 4:
                bubbleSort(A);
                break;
            case 5:
                stampaAutovettura(A);
                break;
            case 6:
                printf("\nArrivederci!\n");
                break;
            default:
                printf("Scelta non valida.\n");
        }
    }

    // deallocazione della memoria
    while (A != NULL) {
        Autovettura *tempPtr = A;
        A = A->nextPtr;
        free(tempPtr);
    }

    return 0;
}