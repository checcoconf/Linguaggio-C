//Esercizio pag. 387 n. 8.11
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include <ctype.h>

#define SIZE_ARTICLE 5
#define SIZE_NOUN 5
#define SIZE_VERB 5
#define SIZE_PREPOSITION 5
#define SIZE_FRASE 35

char add_space(char*);

int main() {
    const char * article[SIZE_ARTICLE] = {"the","a","one","some","any"};
    const char * noun[SIZE_NOUN] = {"boy","girl","dog","town","car"};
    const char * verb[SIZE_VERB] = {"drove","jumped","ran","walked","skipped"};
    const char * preposition[SIZE_PREPOSITION] = {"to","from","over","under","on"};
    srand(time(NULL));

    for (int i = 1; i <= 20; i++){
        char frase [SIZE_FRASE] = {"\0"};
        strcat(frase,article[rand()%SIZE_ARTICLE]); // concateno alla frase la prima parola (l'articolo).
        frase[0] = toupper(frase[0]); // rendo la prima lettera maiuscola.
        add_space(frase); // aggiungo lo spazio
        strcat(frase,noun[rand()%SIZE_NOUN]); // concateno il sostantivo
        add_space(frase); // aggiungo lo spazio
        strcat(frase,verb[rand()%SIZE_VERB]); // concateno il verbo
        add_space(frase); // aggiungo lo spazio
        strcat(frase,preposition[rand()%SIZE_PREPOSITION]); // concateno la preposizione
        add_space(frase); // concateno lo spazio
        strcat(frase,article[rand()%SIZE_ARTICLE]); // concateno l'articolo
        add_space(frase); // concateno lo spazio
        strcat(frase,noun[rand()%SIZE_NOUN]); // concateno il sostantivo
        strcat(frase,".");
        printf("Frase n.%d - %s\n",i,frase);
    }
    return 0;
}

char add_space(char* str){
    int l = strlen(str);
    str[l] = ' ';
    return *str;
}