#include <stdio.h>
#include <ctype.h>
#define SIZE 40

int check_password(char []);

int check_password(char passw[]){
    int flag = -1; //flag = 0 false | 1 true
    for (int i = 0; i < passw[i] != '\0'; i++) {
        if(isupper(passw[i]) == 1){
            flag++;
        }
        if(isnumber(passw[i]) == 1){
            flag++;
        }
        if (flag == 1){
            break;
        }
    }
    return flag;
}

int main() {
    char str[SIZE];
    printf("Inserisci una password: ");
    scanf("%39s",str);

    if (check_password(str) == 1){
        printf("|CORRETTO| - la password soddisfa i requisiti!");
    }else{
        printf("|ERRORE| - la password non soddisfa i requisiti!");
    }
    return 0;
}
