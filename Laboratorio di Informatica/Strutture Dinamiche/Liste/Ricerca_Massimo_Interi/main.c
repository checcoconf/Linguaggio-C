#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct Lista{
    int n;
    struct Lista *prt;
};

typedef struct Lista *Lista;

void insertLista (Lista*, int);
void stampaLista (Lista);
int massimoLista(Lista);

void insertLista(Lista *tPtr, int n){
    Lista nuovoPtr, precPrt, corrPtr;
    nuovoPtr = malloc (sizeof (Lista));
    if (nuovoPtr != NULL){
        nuovoPtr->n = n;
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
        printf("%d non inserito. Manca la memoria.\n",n);
    }
}

void stampaLista(Lista corrPtr){
    if (corrPtr == NULL){
        printf("Lista vuota!\n");
    } else{
        printf("I numeri della lista sono: \n");
        while (corrPtr != NULL){
            printf("%d --> ", corrPtr->n);
            corrPtr = corrPtr->prt;
        }
        printf("NULL\n");
    }
}

int massimoLista(Lista corrPtr){
    int max = corrPtr->n;

    if (corrPtr == NULL){
        printf("La lista è vuota!");
    }else{
        while (corrPtr != NULL){
            if (max < corrPtr->n){
                max = corrPtr->n;
            } else{
                corrPtr = corrPtr->prt;
            }
        }
    }
    return max;
}

int main() {
    Lista L = NULL;
    srand(time(NULL));

    int random = rand() % 20 +1; // totale numeri da inserire

    for (int i = 0; i < random; i++) {
        insertLista(&L,rand()%100+1);
    }

    stampaLista(L);

    printf("\nIl massimo della lista è: |%d|", massimoLista(L));

    return 0;
}
