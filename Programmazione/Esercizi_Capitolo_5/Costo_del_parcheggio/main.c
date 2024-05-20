// Esercizio pagina 211 pag. 5.9
#include <stdio.h>

float calculateCharges(double);

int main() {
    double oretotali = 0.0, prezzototale = 0.00;

    for (int i = 1; i <= 3; i++) {
        double ora;
        printf("Inserisci l' ora della %d auto: ", i);
        do {
            scanf("%lf", &ora);
            if (ora <= 0.0 || ora > 24.0) {
                printf("|ERRORE| impossibile parcheggiare l'auto per %.1lf ore\nReinserisci l'ora qui ---> ", ora);
            }
        } while (ora <= 0.0 || ora > 24.0);

        oretotali += ora;

        if (i == 1) {
            printf("%s%15s%15s\n", "Car", "Hours", "Charge");
        }

        double prezzo;
        prezzototale += (prezzo = calculateCharges(ora));
        printf("%0d%15.1f%15.2f\n", i, ora, prezzo);
    }
    printf("%5s%11.1f%15.2f\n", "TOTAL", oretotali, prezzototale);
}

float calculateCharges(double ora) {
    const double tariffa_minima = 2.00;
    const double tariffa_aggiuntiva = 0.50;
    const double tariffa_massima = 10.00;
    double prezzo = 0.00;

    // Per un massimo di 3 ore
    if (ora <= 3.00) {
        prezzo = tariffa_minima;
    }

    // Aggiunta della tariffa aggiuntiva nel caso in cui le ore siano maggiori di 3 fino alle ore 23:5.
    if (ora > 3.00 && ora <= 23.5) {
        prezzo = (((ora - 3) * tariffa_aggiuntiva) + tariffa_minima);
    }

    // Parcheggio per l'intera giornata
    if (ora == 24.00) {
        prezzo = tariffa_massima;
    }
    return prezzo;
}