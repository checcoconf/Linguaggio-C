#include <stdio.h>
#include <string.h>

int cont_consonanti(char*,int);

int main() {
    char str[] = "buongiorno";
    int l = strlen(str);
    return cont_consonanti(str,l);
}

int cont_consonanti(char* str,int len){
    int cont = 0;

    if (len == 0)
        return cont;

    if (str[len-1] != 'a' && str[len-1] != 'e' && str[len-1] != 'i' && str[len-1] != 'o' && str[len-1] != 'u')
        cont = 1;
    return cont + cont_consonanti(str,len-1);
}


