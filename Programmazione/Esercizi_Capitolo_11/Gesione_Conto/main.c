#include <stdio.h>

int main(void) {
    FILE *cfPtr;

    if((cfPtr = fopen("Clients.txt", "r"))==NULL){
        puts("|ERRORE| non è possibile aprire il file");
    }else{
        printf("%s","Scegli un numero\n"
                    "1 - Lista account con 0,00 €\n"
                    "2 - Lista account con del debito\n"
                    "3 - Lista account con del credito\n"
                    "4 - Esci\n");
        unsigned int scelta;
        printf("\nScrivi qui --> ");
        scanf("%u",&scelta);

        while (scelta != 4){
            unsigned int account;
            double saldo;
            char nome [30];

            fscanf(cfPtr,"%d %s %lf",&account,nome,&saldo);
            switch (scelta){
                case 1:
                    puts("\nLista con account = 0,00€");
                    printf("%9s","Matricola");
                    printf("%6s","Nome");
                    printf("%19s","Saldo\n");

                    while (!feof(cfPtr)) {
                        if (saldo == 0) {
                            printf("%-10u %-13s %8.2f\n",account,nome,saldo);
                        }
                        fscanf(cfPtr, "%d %s %lf", &account, nome, &saldo);
                    }
                    break;
                case 2:
                    puts("\nLista con account < 0,00€");
                    printf("%9s","Matricola");
                    printf("%6s","Nome");
                    printf("%18s","Saldo\n");
                    while (!feof(cfPtr)){
                        if (saldo < 0){
                            printf("%-10d %-13s %7.2f\n",account,nome,saldo);
                        }
                        fscanf(cfPtr,"%d%s%lf",&account,nome,&saldo);
                    }
                    break;
                case 3:
                    puts("\nLista con account > 0,00€");
                    printf("%9s","Matricola");
                    printf("%6s","Nome");
                    printf("%18s","Saldo\n");
                    while (!feof(cfPtr)){
                        if (saldo > 0){
                            printf("%-10d %-13s %7.2f\n",account,nome,saldo);
                        }
                        fscanf(cfPtr,"%d%s%lf",&account,nome,&saldo);
                    }
                    break;
            }
            rewind(cfPtr); //Riporta il puntatore all'inizio del file
            printf("%s","\nScrivi qui --> ");
            scanf("%u",&scelta);
        }
        puts("Uscita.");
        fclose(cfPtr);
    }
    return 0;
}