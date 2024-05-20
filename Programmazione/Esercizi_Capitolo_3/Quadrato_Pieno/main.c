#include <stdio.h>

int main() {
    unsigned int lato = 0;

    do{
        printf("Inserisci il lato: ");
        scanf("%d",&lato);

        if (lato < 1 || lato > 20){
            printf("Valori non accettati\nInserire dei valori da 1 a 20.\n");
        }else {
            for (int i = 0; i < lato; i++){
                if (i!=0){
                    printf("\n");
                }
                for(int j = 0; j < lato; j++){
                    printf("* ");
                }
            }
        }
    }while(lato < 1 || lato > 20);

    return 0;
}