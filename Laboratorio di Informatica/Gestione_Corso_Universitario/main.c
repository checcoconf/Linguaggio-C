#include <stdio.h>
#include "Corso_Universitario/Corso_Universitario.h"
#include "Gestione_File/File.h"
int main() {
    Lista *testa = NULL;

    RiempiLista(&testa);
    StampaListaTipoCorso(testa,"Informatica");
    TrovaMinimo(testa);
    TrovaMassimo(testa);
    BubbleSort(testa);
    StampaLista(testa);
    SalvaSuFile(testa);
    LiberaLista(testa);
    return 0;
}
