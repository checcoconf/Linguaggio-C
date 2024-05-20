#include <stdio.h>

#define NUM_INDIVIDUI 5
#define NUM_GIORNI_SETTIMANA 7

//Prototipo di funzione
void acquisisci_calorie_individuo(int,int[][NUM_GIORNI_SETTIMANA]);
float media_calorie_individuo(int,int[][NUM_GIORNI_SETTIMANA]);
float media_calorie_complessiva(int[][NUM_GIORNI_SETTIMANA]);

// Funzione per acquisire le calorie assunte da un individuo in una settimana
void acquisisci_calorie_individuo(int individuo, int calorie[][NUM_GIORNI_SETTIMANA]) {
    printf("Inserisci le calorie assunte dall'individuo |%d| per ogni giorno della settimana.\n", individuo+1);
    for (int giorno = 0; giorno < NUM_GIORNI_SETTIMANA; giorno++) {
        printf("Giorno %d: ",giorno+1);
        scanf("%d", &calorie[individuo][giorno]);
    }
}

// Funzione per calcolare la media delle calorie assunte da un individuo in una settimana
float media_calorie_individuo(int individuo, int calorie[][NUM_GIORNI_SETTIMANA]) {
    int somma = 0;
    for (int giorno = 0; giorno < NUM_GIORNI_SETTIMANA; giorno++) {
        somma += calorie[individuo][giorno];
    }
    return (float) somma / NUM_GIORNI_SETTIMANA;
}

// Funzione per calcolare la media complessiva delle calorie assunte dagli individui in una settimana
float media_calorie_complessiva(int calorie[][NUM_GIORNI_SETTIMANA]) {
    int somma = 0;
    for (int individuo = 0; individuo < NUM_INDIVIDUI; individuo++) {
        for (int giorno = 0; giorno < NUM_GIORNI_SETTIMANA; giorno++) {
            somma += calorie[individuo][giorno];
        }
    }
    return (float) somma / (NUM_INDIVIDUI * NUM_GIORNI_SETTIMANA);
}

int main() {
    int calorie[NUM_INDIVIDUI][NUM_GIORNI_SETTIMANA];

    // Acquisizione delle calorie per ogni individuo
    for (int individuo = 0; individuo < NUM_INDIVIDUI; individuo++) {
        acquisisci_calorie_individuo(individuo, calorie);
    }

    // Calcolo e visualizzazione delle medie individuali
    printf("\nMedie individuali:\n");
    for (int individuo = 0; individuo < NUM_INDIVIDUI; individuo++) {
        float media = media_calorie_individuo(individuo, calorie);
        printf("Individuo %d: %.2f calorie al giorno\n", individuo, media);
    }

    // Calcolo e visualizzazione della media complessiva
    float media_complessiva = media_calorie_complessiva(calorie);
    printf("\nMedia complessiva: %.2f calorie al giorno\n", media_complessiva);

    return 0;
}
