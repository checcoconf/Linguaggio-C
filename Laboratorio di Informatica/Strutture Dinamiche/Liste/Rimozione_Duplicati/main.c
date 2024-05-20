#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct Lista{
    char c;
    struct Lista *prt;
};

typedef struct Lista *Lista;

void insertLista (Lista*, char);
void stampaLista (Lista);
void rimuoviDuplicati(struct Lista*);

void insertLista(Lista *tPtr, char c){
    Lista nuovoPtr, precPrt, corrPtr;
    nuovoPtr = malloc (sizeof (Lista));
    if (nuovoPtr != NULL){
        nuovoPtr->c = c;
        nuovoPtr->prt = NULL;
        precPrt = NULL;
        corrPtr = *tPtr;

        while (corrPtr != NULL){
            precPrt = corrPtr;
            corrPtr = corrPtr->prt;
        }
        if(precPrt == NULL){
            nuovoPtr->prt = *tPtr;
            *tPtr = nuovoPtr;
        } else{
            precPrt->prt = nuovoPtr;
            nuovoPtr->prt = corrPtr;
        }
    } else{
        printf("%c non inserito. Manca la memoria.\n",c);
    }
}

void stampaLista(Lista corrPtr){
    if (corrPtr == NULL){
        printf("Lista vuota!\n");
    } else{
        printf("\nI caratteri della lista sono: \n");
        while (corrPtr != NULL){
            printf("%c --> ", corrPtr->c);
            corrPtr = corrPtr->prt;
        }
        printf("NULL\n");
    }
}

void rimuoviDuplicati(struct Lista* head) {
    struct Lista *current = head, *temp = NULL, *duplicate = NULL;

    // Ciclo esterno per scorrere la lista dall'inizio alla fine
    while (current != NULL && current->prt != NULL) {
        temp = current;

        // Ciclo interno per confrontare il valore del carattere del nodo corrente con i nodi successivi
        while (temp->prt != NULL) {
            // Se viene trovato un duplicato, il puntatore del nodo precedente viene impostato al nodo successivo del duplicato
            if (current->c == temp->prt->c) {
                duplicate = temp->prt;
                temp->prt = temp->prt->prt;
                // Libera la memoria occupata dal nodo duplicato
                free(duplicate);
            } else {
                // Se non viene trovato un duplicato, il ciclo interno continua a scorrere i nodi successivi
                temp = temp->prt;
            }
        }
        // Il ciclo esterno passa al nodo successivo
        current = current->prt;
    }
}

int main() {
    Lista L = NULL;
    srand(time(NULL));

    int scelta = 0;
    char elemento;

    printf("Quanti caratteri vuoi inserire?\nScrivi qui --> ");
    scanf("%d",&scelta);
    puts("");

    for (int i = 0; i < scelta; i++) {
        printf("Inserisci il %d carattere: ",i+1);
        scanf("\n%c",&elemento);
        insertLista(&L,elemento);
    }

    stampaLista(L);
    puts("----------------------------------");
    printf("Rimuovo i duplicati dalla lista!");
    rimuoviDuplicati(L);

    stampaLista(L);

    return 0;
}
