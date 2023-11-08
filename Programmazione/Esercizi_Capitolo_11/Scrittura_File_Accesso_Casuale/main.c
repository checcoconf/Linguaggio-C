#include <stdio.h>

struct clientData{
    int acctNum;
    char lastName[15];
    char firstName[10];
    double balance;
};

int main() {
    struct clientData client = {0,"","",0.0};
    FILE *cfPtr;

    if((cfPtr = fopen("/Users/checcoconf/Desktop/Programmazione/Esercizi_Capitolo_11/Creazione_File_Accesso_Casuale/cmake-build-debug/credit.dat","r+"))==NULL){
        printf("|ERRORE| impossibile creare il file.\n");
    }else{
        printf("Inserisci un numero da 1 a 100 e 0 per terminare.\n? ");
        scanf("%d",&client.acctNum);

        while (client.acctNum != 0){
            printf("Inserisci il cognome, il nome e il saldo\n? ");
            fscanf(stdin,"%s%s%lf",client.lastName,client.firstName,&client.balance);
            fseek(cfPtr,(client.acctNum-1)*sizeof (struct clientData),SEEK_SET);
            fwrite(&client,sizeof (struct clientData),1,cfPtr);
            printf("Inserisci un nuovo numero dell'account\n? ");
            scanf("%d",&client.acctNum);
        }
        fclose(cfPtr);
    }
    return 0;
}
