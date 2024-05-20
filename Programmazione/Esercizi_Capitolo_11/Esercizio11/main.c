#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct person {
    int record;
    char lastName[15];
    char firstName[15];
    char age[4];
};
struct person P = {0,"unassigned", "", "0"};

void initialization_file();

void insert_file();

void read_file();

void start ();


int main() {
    start();
    return 0;
}

void start(){
    unsigned int scelta = 0;

    printf("Effettua la tua scelta!\n\n1 - per inizializzare il file.\n2 - per inserire i dati nel file.\n3 - per leggere il file.\n4 - per uscire.\n\nScrivi qui --> ");
    scanf("%ud",&scelta);

    switch (scelta) {
        case 1:
            initialization_file();
            break;
        case 2:
            insert_file();
            break;
        case 3:
            read_file();
            break;
        case 4:
            exit(0);
        default:
            printf("|ERRORE| - scelta %d non valida!\n",scelta);
            start();
    }
}

void initialization_file() {
    FILE *cfPtr;

    if ((cfPtr = fopen("nameage.dat", "wb")) == NULL) {
        puts("|ERRORE| - impossibile aprire il file!");
    } else {
        for (int i = 1; i <= 100; i++) {
            fwrite(&P, sizeof(P), 1, cfPtr);
        }
        printf("File inizializzato correttamente!\n");
        fclose(cfPtr);
    }
}

void insert_file() {
    FILE *cfPtr;
    if ((cfPtr = fopen("nameage.dat", "a+")) == NULL) {
        puts("|ERRORE| - impossibile aprire il file!");
    } else {
        printf("Quanti utenti vuoi inserire: ");
        int scelta = 0;
        do {
            if (scelta < 0) {
                printf("|ERRORE| - impossibile inserire %d utenti!\nReinserisci un nuovo numero --> ", scelta);
            }
            scanf("%d", &scelta);
        } while (scelta < 0);;

        for (int i = 1; i <= scelta; i++) {
            printf("Inserisci l'ID, il cognome, il nome e l'età: ");
            fscanf(stdin, "%d%s%s%s", &P.record, P.lastName, P.firstName, P.age);
            //fseek(cfPtr,P.record*sizeof(P),SEEK_SET);
            fwrite(&P, sizeof(P), 1, cfPtr);
        }
        fclose(cfPtr);
    }
}

void read_file() {
    FILE *cfPtr;

    if ((cfPtr = fopen("nameage.dat", "r")) == NULL) {
        puts("|ERRORE| - impossibile aprire il file!");
    } else {
        printf("%-5s%-20s%-20s%s\n", "ID","Cognome", "Nome", "Anni");
        while (1) {
            if (!fread(&P, sizeof(P), 1, cfPtr)) {
                break;
            } else {
                if (strcmp(P.lastName, "unassigned") != 0) {
                    printf("%-5d%-20s%-20s%s\n", P.record, P.lastName, P.firstName, P.age);
                }
            }
        }
        fclose(cfPtr);
    }
}