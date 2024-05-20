#include <stdio.h>
typedef struct {
    unsigned int Identificativo;
    char NomeCorso [50];
    char NomeDocente [50];
    unsigned int NumeroCFU;
    unsigned int NumeroStudenti;
}Corso_Universitario;

// definizione della struttura Lista
typedef struct Lista {
    Corso_Universitario CU;
    struct Lista *nextPtr;
} Lista;

Lista *CreaLista(Corso_Universitario);
void InserisciLista(Lista **, Corso_Universitario);
void StampaListaTipoCorso(Lista*,const char*);
void LiberaLista(Lista *);
void RiempiLista(Lista**);
void TrovaMinimo(Lista *);
void TrovaMassimo(Lista *);
void StampaMinimo(Lista *);
void StampaMassimo(Lista *);
void Swap(Lista*,Lista*);
void BubbleSort(Lista*);
void StampaLista(Lista*);
void SalvaSuFile(Lista*);