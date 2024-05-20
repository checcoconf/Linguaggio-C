#include "Corso_Universitario.h"
#include "../Gestione_File/File.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Lista *CreaLista(Corso_Universitario cu){
    Lista *L = (Lista*) malloc(sizeof (Lista));
    L -> CU = cu;
    L -> nextPtr = NULL;
    return L;
}

void InserisciLista(Lista **testaPtr, Corso_Universitario cu){
    Lista *nuovoNodo = CreaLista(cu);
    if (*testaPtr == NULL) {
        *testaPtr = nuovoNodo;
    } else {
        Lista *current = *testaPtr;
        while (current->nextPtr != NULL) {
            current = (Lista *) current->nextPtr;
        }
        current->nextPtr = (struct nodo *) nuovoNodo;
    }
}

void StampaListaTipoCorso(Lista*testaPtr, const char*nomeCorso){
    Lista *corrente = testaPtr;
    int flag = 0;
    while (corrente != NULL) {
        if (strcmp(corrente->CU.NomeCorso, nomeCorso) == 0) {
            printf("Identificativo: %u\n", corrente->CU.Identificativo);
            printf("Nome Corso: %s\n", corrente->CU.NomeCorso);
            printf("Nome Docente: %s\n", corrente->CU.NomeDocente);
            printf("Numero CFU: %u\n", corrente->CU.NumeroCFU);
            printf("Numero Studenti: %u\n", corrente->CU.NumeroStudenti);
            printf("----------------------\n");
            flag = 1;
        }
        corrente = (Lista *) corrente->nextPtr;
    }

    if(!flag){
        printf("Nessun corso |%s| trovato.",nomeCorso);
    }
}

void LiberaLista(Lista *testaPtr){
    Lista *corrente = testaPtr;
    while (corrente != NULL){
        Lista *temp = corrente;
        corrente = (Lista *) corrente->nextPtr;
        free(temp);
    }
}

void RiempiLista(Lista**testaPtr){
    Lettura_File();

    Corso_Universitario cu;
    while (fscanf(getPtrFile(), "%u*%49[^*]*%49[^*]*%u*%u",
                  &cu.Identificativo,
                  cu.NomeCorso,
                  cu.NomeDocente,
                  &cu.NumeroCFU,
                  &cu.NumeroStudenti) == 5) // fino a quando leggi 5 elementi
    {
        InserisciLista(testaPtr, cu);
        // Ignora il carattere asterisco
        fgetc(getPtrFile());
    }
    fclose(getPtrFile());
}

void TrovaMinimo(Lista *testa) {
    Lista *minimo = NULL;

    Lista *temp = testa;
    while (temp != NULL) {
        if (minimo == NULL || (temp->CU.NumeroStudenti < minimo->CU.NumeroStudenti) ||
            (temp->CU.NumeroStudenti == minimo->CU.NumeroStudenti && temp->CU.NumeroCFU < minimo->CU.NumeroCFU)) {
            minimo = temp;
        }
        temp = (Lista *) temp->nextPtr;
    }
    StampaMinimo(minimo);
}

void TrovaMassimo(Lista *testa) {
    Lista *massimo = NULL;

    Lista *temp = testa;
    while (temp != NULL) {
        if (massimo == NULL || (temp->CU.NumeroStudenti > massimo->CU.NumeroStudenti) ||
            (temp->CU.NumeroStudenti == massimo->CU.NumeroStudenti && temp->CU.NumeroCFU > massimo->CU.NumeroCFU)) {
            massimo = temp;
        }
        temp = (Lista *) temp->nextPtr;
    }
    StampaMassimo(massimo);
}

void StampaMinimo(Lista *testa){
    StampaLista(testa);

    FILE *fp = fopen("../MinMax.txt","w");
    fprintf(fp,"%u*",testa->CU.Identificativo);
    fprintf(fp,"%s*", testa->CU.NomeCorso);
    fprintf(fp,"%s*", testa->CU.NomeDocente);
    fprintf(fp,"%u*", testa->CU.NumeroCFU);
    fprintf(fp,"%u\n", testa->CU.NumeroStudenti);

    fclose(fp);
}

void StampaMassimo(Lista *testa){
    StampaLista(testa);

    FILE *fp = fopen("../MinMax.txt","a");
    fprintf(fp,"%u*",testa->CU.Identificativo);
    fprintf(fp,"%s*", testa->CU.NomeCorso);
    fprintf(fp,"%s*", testa->CU.NomeDocente);
    fprintf(fp,"%u*", testa->CU.NumeroCFU);
    fprintf(fp,"%u", testa->CU.NumeroStudenti);

    fclose(fp);
}

void Swap(Lista *a, Lista *b) {
    Corso_Universitario temp = a->CU;
    a->CU = b->CU;
    b->CU = temp;
}

void BubbleSort(Lista *testa){
    int swapped;
    Lista* ptr1;
    Lista* lptr = NULL;

    // Controllo se la lista è vuota
    if (testa == NULL){
        printf("La lista è vuota");
    }

    do {
        swapped = 0;
        ptr1 = testa;

        while (ptr1->nextPtr != lptr) {
            if (strcmp(ptr1->CU.NomeCorso, ptr1->nextPtr->CU.NomeCorso) < 0 ||
                (strcmp(ptr1->CU.NomeCorso, ptr1->nextPtr->CU.NomeCorso) == 0 &&
                 strcmp(ptr1->CU.NomeDocente, ptr1->nextPtr->CU.NomeDocente) < 0)) {
                Swap(ptr1, ptr1->nextPtr);
                swapped = 1;
            }
            ptr1 = ptr1->nextPtr;
        }
        lptr = ptr1;
    } while (swapped);
}

void StampaLista(Lista *testa){

    if(testa == NULL){
        printf("La lista è vuota!");
    }

    while (testa != NULL) {
        printf("Identificativo: %u\n", testa->CU.Identificativo);
        printf("Nome Corso: %s\n", testa->CU.NomeCorso);
        printf("Nome Docente: %s\n", testa->CU.NomeDocente);
        printf("Numero CFU: %u\n", testa->CU.NumeroCFU);
        printf("Numero Studenti: %u\n", testa->CU.NumeroStudenti);
        printf("------------------------\n");

        testa = testa->nextPtr;
    }
}

void SalvaSuFile(Lista *testa){
    FILE *fp = fopen("../Ordinati.txt","w");

    while (testa != NULL){
        fprintf(fp,"%u*",testa->CU.Identificativo);
        fprintf(fp,"%s*", testa->CU.NomeCorso);
        fprintf(fp,"%s*", testa->CU.NomeDocente);
        fprintf(fp,"%u*", testa->CU.NumeroCFU);
        fprintf(fp,"%u\n", testa->CU.NumeroStudenti);

        testa = testa ->nextPtr;
    }
    fclose(fp);
}