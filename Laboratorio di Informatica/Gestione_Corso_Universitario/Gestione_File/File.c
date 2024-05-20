#include "File.h"
#include <string.h>

FILE *fp;

int Se_Esiste(const char* Nome_File){
    fp = fopen(Nome_File, "r");

    if(fp == NULL){
        return 0; //falso
    } else{
        fclose(fp);
        return 1; // vero [ESISTE]
    }
}

void Lettura_File(){
    char nome_file[30] = {'.','.','/'};
    printf("Inserisci il nome del file, completo di estensione: ");
    scanf("%s",&nome_file[3]);

    do {
        if (Se_Esiste(nome_file) == 0) {
            printf("|ERRORE| - nome del file sbagliato!\nRiprova: ");
            scanf("%s", &nome_file[3]);
        }
    } while (Se_Esiste(nome_file) == 0);

    fp = fopen(nome_file,"r");
}

void Visualizza_File(void){
    Lettura_File();
    int c;
    printf("Il contenuto del file è: \n");
    while ((c = fgetc(fp)) != EOF) {
        printf("%c",c);
    }
    Chiusura_File();
}

FILE *getPtrFile(void){
    return fp;
}

void Chiusura_File(void){
    fclose(fp);
}