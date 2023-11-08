#include <stdio.h>
#include <stdlib.h>

struct Coda {
    char data;
    struct Coda* nextPtr;
};

typedef struct Coda* CodaPtr;

void printCoda(CodaPtr);
int isEmpty(CodaPtr);
char rimuovi(CodaPtr*, CodaPtr*);
void inserisci(CodaPtr*, CodaPtr*, char);
void istruzioni(void);
void rimuoviDuplicati(CodaPtr*);
void invertiCoda(CodaPtr*);

void istruzioni(void){
    printf("Effettua la tua scelta:\n"
           "1 - Per inserire un elemento\n"
           "2 - Per rimuovere un elemento\n"
           "3 - Per rimuovere i duplicati nella coda\n"
           "4 - Per invertire la coda\n"
           "5 - Per uscire\n");
}

void inserisci(CodaPtr* testa, CodaPtr* coda, char valore){
    CodaPtr newPtr;
    newPtr = malloc(sizeof(struct Coda));

    if (newPtr != NULL){
        newPtr->data = valore;
        newPtr->nextPtr = NULL;

        if (isEmpty(*coda)){
            *testa = newPtr;
        }
        else{
            (*coda)->nextPtr = newPtr;
        }

        *coda = newPtr;
    }
    else{
        printf("%c non inserito. Nessuna memoria allocata.\n", valore);
    }
}

char rimuovi(CodaPtr* testa, CodaPtr* coda){
    char valore;
    CodaPtr tempPtr;

    valore = (*testa)->data;
    tempPtr = *testa;
    *testa = (*testa)->nextPtr;

    if (*testa == NULL){
        *coda = NULL;
    }

    free(tempPtr);
    return valore;
}

int isEmpty(CodaPtr testa){
    return testa == NULL;
}

void printCoda(CodaPtr currentPtr){
    if (currentPtr == NULL){
        printf("La coda è vuota.\n");
    }
    else{
        printf("La coda è: ");
        while (currentPtr != NULL){
            printf("%c --> ", currentPtr->data);
            currentPtr = currentPtr->nextPtr;
        }
        printf("NULL\n");
    }
}

void rimuoviDuplicati(CodaPtr* testa){
    if (!isEmpty(*testa)){
        CodaPtr corrente = *testa, successivo, temp;
        while (corrente != NULL){
            successivo = corrente;
            while (successivo->nextPtr != NULL){
                if (successivo->nextPtr->data == corrente->data){
                    temp = successivo->nextPtr;
                    successivo->nextPtr = successivo->nextPtr->nextPtr;
                    free(temp);
                }
                else{
                    successivo = successivo->nextPtr;
                }
            }
            corrente = corrente->nextPtr;
        }
    }
}

void invertiCoda(CodaPtr* testa){
    CodaPtr precedente = NULL;
    CodaPtr corrente = *testa;
    CodaPtr prossimo = NULL;

    if (!isEmpty(*testa)){
        while (corrente != NULL){
            prossimo = corrente->nextPtr;
            corrente->nextPtr = precedente;
            precedente = corrente;
            corrente = prossimo;
        }
        *testa = precedente;
    }
}

int main(){
    CodaPtr testa = NULL;
    CodaPtr coda = NULL;

    int scelta;
    char input;

    istruzioni();
    printf("Inserisci qui --> ");
    scanf("%d", &scelta);

    while (scelta != 5){
        switch (scelta){
            case 1:
                printf("Inserisci un carattere: ");
                scanf(" %c", &input);
                inserisci(&testa, &coda, input);
                printCoda(testa);
                break;

            case 2:
                if (!isEmpty(testa)){
                    input = rimuovi(&testa, &coda);
                    printf("%c è stato eliminato", input);
                }
                printCoda(testa);
                break;

            case 3:
                rimuoviDuplicati(&testa);
                printCoda(testa);
                break;

            case 4:
                invertiCoda(&testa);
                printCoda(testa);
                break;

            default:
                printf("Scelta: %d non valida!\n", scelta);
                istruzioni();
                break;
        }
        printf("Inserisci qui --> ");
        scanf("%d", &scelta);
    }

    printf("Arrivederci!");

    return 0;
}