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

    if((cfPtr = fopen("/Users/checcoconf/Desktop/Programmazione/Esercizi_Capitolo_11/Creazione_File_Accesso_Casuale/cmake-build-debug/credit.dat","r"))==NULL){
        printf("|ERRORE| impossibile leggere il file.\n");
    }else{
        printf("%-10s%-16s%-11s%8s\n","Account","Cognome","Nome","Saldo");
        while (!feof(cfPtr)){
            fread(&client,sizeof (struct clientData),1,cfPtr);
            if(client.acctNum != 0){
                printf("%-10d%-16s%-11s%10.2f\n",client.acctNum,client.lastName,client.firstName,client.balance);
            }
        }
        fclose(cfPtr);
    }
    return 0;
}
