#include <stdio.h>

int main() {
    int a;
    int *aPtr;

    a = 7;
    aPtr = &a;

    printf("Indirizzi: %p, %p",&a,aPtr);
    //fflush(stdout); // Svota forzamente il buffer in out.
    printf("\nIndirizzi: %d, %d",a,*aPtr);

    printf("\nIndirizzi: %p, %p",&*aPtr,aPtr);

    return 0;
}
