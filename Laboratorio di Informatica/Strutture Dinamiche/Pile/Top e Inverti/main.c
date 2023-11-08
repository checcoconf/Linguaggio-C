#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct stackNode {
    int data;
    struct stackNode *nextPtr;
} StackNode;

typedef StackNode *StackNodePtr;

void push(StackNodePtr *, int);
int pop (StackNodePtr *);
int top(StackNodePtr *);
void printStack(StackNodePtr);
void invertiPila(StackNodePtr *);

void push(StackNodePtr *topPtr, int info) {
    StackNodePtr newPtr = malloc(sizeof(StackNode));
    if (newPtr == NULL) {
        printf("%d non è stato inserito.\nNon c'è memoria.\n", info);
        return;
    }
    newPtr->data = info;
    newPtr->nextPtr = *topPtr;
    *topPtr = newPtr;
}

int pop(StackNodePtr *topPtr){
    StackNodePtr tempPtr;
    int popValue;
    tempPtr = *topPtr;
    popValue = (*topPtr)->data;
    *topPtr = (*topPtr)->nextPtr;
    free(tempPtr);

    return popValue;
}

int top(StackNodePtr *topPtr){
    return (*topPtr) ->data;
}

void printStack(StackNodePtr currentPtr){
    if (currentPtr == NULL){
        printf("Lo Stack è vuoto.\n");
    }else{
        while (currentPtr != NULL){
            printf("%d --> ",currentPtr->data);
            currentPtr = currentPtr->nextPtr;
        }
        printf("NULL\n");
    }
}

void invertiPila(StackNodePtr *topPtr){
    StackNodePtr tempPtr = NULL;
    while (*topPtr != NULL){
        int value = pop(topPtr);
        push(&tempPtr,value);
    }
    *topPtr = tempPtr;
}

int main() {
    StackNodePtr S = NULL;
    srand(time(NULL));

    int random = rand() % 20 +1; // totale numeri da inserire

    for (int i = 0; i < random; i++) {
        push(&S,rand()%100+1);
    }

    printf("La pila è: ");
    printStack(S);
    printf("L'elemento in cima è: |%d|\n",top(&S));

    printf("La pila invertita è: ");
    invertiPila(&S);
    printStack(S);
    return 0;
}
