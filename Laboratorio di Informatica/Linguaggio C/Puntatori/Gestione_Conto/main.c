#include <stdio.h>
#include <string.h>
#define SIZE 3

typedef struct {
    unsigned int id;
    char cognome[30];
    char nome[30];
    float saldo;
} conto;

void insert(conto*);
void print_conto(conto*);
void swap (conto*, conto*);
int order_relation(conto*, conto*, int);
void choice_swap(conto*);

void insert(conto* C) {
    for (int i = 0; i < SIZE; i++) {
        printf("Inserisci i dati del %d conto corrente\n", i + 1);
        (C + i)->id = i + 1; // ID progressivo
        printf("Cognome: ");
        scanf("%30s", (C + i)->cognome);
        printf("Nome: ");
        scanf("%30s", (C + i)->nome);
        printf("Saldo: ");
        scanf("%f", &(C + i)->saldo);
    }
}

void print_conto(conto* C) {
    for (int i = 0; i < SIZE; i++) {
        printf("\nDati del %d conto corrente.\n", i + 1);
        printf("ID: %d\n", (C+i)->id);
        printf("Cognome: %s\n", (C+i)->cognome);
        printf("Nome: %s\n", (C+i)->nome);
        printf("Saldo: %.2f\n", (C+i)->saldo);
    }
}

void swap(conto *a, conto *b) {
    conto temp = *a;
    *a = *b;
    *b = temp;
}

int order_relation(conto* a, conto *b, int scelta) {
    switch (scelta) {
        case 1: // ordinamento per cognome
            return strcmp(a->cognome, b->cognome) < 0;
        case 2: // ordinamento per nome
            return strcmp(a->nome, b->nome) < 0;
        case 3: // ordinamento per saldo
            return a->saldo < b->saldo;
        case 4: // ordinamento per id
            return a->id < b->id;
        default: // campo di ordinamento non valido
            return 0;
    }
}

void choice_swap(conto* C){
    int field = -1;
    printf("Scegli il campo di ordinamento.\n1 - Cognome\n2 - Nome\n3 - Saldo\n4 - ID\nScrivi qui --> ");
    scanf("%d", &field);
    for (int i = 0; i < SIZE - 1; i++) {
        for (int j = i + 1; j < SIZE; j++) {
            if (order_relation(&C[j], &C[i], field)) {
                swap(C + i, C + j);
            }
        }
    }
}

int main() {
    conto C[SIZE];
    insert(C);
    choice_swap(C);
    print_conto(C);
}
