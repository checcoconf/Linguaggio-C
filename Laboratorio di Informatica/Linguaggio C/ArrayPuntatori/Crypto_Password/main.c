/**
 * Copyright © 2023
 * Francesco Conforti ~ 30/03/23 17.34
 * Tutti i diritti riservati.
 **/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char *hidePassword(char *);

char *hidePassword(char *str) {
    char vocal[] = {'a', 'e', 'i', 'o', 'u','A','E','I','O','U','\0'};
    char *password = (char *) malloc(strlen(str) * sizeof(char));

    for (int i = 0; i < str[i] != '\0'; i++) {
        for (int j = 0; j < vocal[j] != '\0'; j++) {
            if (isalpha(str[i]) == 1) { // se è un carattere dell'alfabeto
                if (str[i] == vocal[j]) {
                    password[i] = '$';
                    break;
                } else {
                    password[i] = '*';
                }
            }else{
                password[i] = str[i]; // inserisco il caratere letto non appartenente all'alfabeto.
            }
        }
        password[strlen(str)] = '\0';
    }
    return password;
}

int main() {
    printf("%s", hidePassword("ciAo a tutti! Sono Francesco,"));
}
