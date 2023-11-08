#include <stdio.h>

int main(){
    unsigned int eta = 0;
    printf("Inserisci la tua eta': ");
    scanf("%d",&eta);

    if (eta >= 18){
        printf("Sei maggiorenne.\n");
    }else{
        printf("Sei minorenne.");
    }

    if (eta >= 65){
        printf("Sei un pensionato.");
    }else if(eta >= 18 && eta <= 64){
        printf("Sei un lavoratore.");
    }
    return 0;
}
