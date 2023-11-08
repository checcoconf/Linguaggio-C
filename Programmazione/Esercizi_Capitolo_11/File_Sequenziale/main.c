#include <stdio.h>
#include <ctype.h>

int main() {
    int account;
    char nome [30];
    double balance;
    FILE *cfPtr;

    if((cfPtr = fopen("Clients.tsv","a")) == NULL){
        printf("|ERRORE| Non è stato possibile aprire il file\n");
    } else{
        puts("Inserisci una matricola, un nome e i soldi.");
        puts("Inserisci l'EOF per terminare l'inserimento dei dati.");
        printf("? ");
        scanf("%d%s%lf",&account,nome,&balance);
        nome[0] = toupper(nome[0]);

        while (!feof(stdin)){
            fprintf(cfPtr, "%.4d %-5s %5.2f€\n",account,nome,balance);
            printf("? ");
            scanf("%d%s%lf",&account,nome,&balance);
            nome[0] = toupper(nome[0]);
        }
        fclose(cfPtr);
    }
    return 0;
}
