#include <stdio.h>
#include <string.h>

//--------------DEFINICJE--------------------------
#define MAX_KOMENDA 200;
#define MAX_SLOWO 40;
#define MAXNAZWA 20;
#define MAXLICZBASLOW 5;

//--------------STRUKTURY--------------------------

typedef struct macierz
{
    char nazwaMacierzy[20];
    int liczbaKolumn;
    int liczbaWierszy;
    float *zawartosc;
} macierz;

typedef struct Lista
{
    macierz *m;
    Lista *nastepny;
} Lista;

//--------------FUNKCJE------------------------------
void wygenerujSkrypt(char nazwapliku[]);
void zapiszBin(char nazwaPliku[], macierz *macierz);
//----------znajdowanie macierzy w liscie po nazwie------------
macierz *znajdzMacierz(char nazwaMacierzy[], Lista *pierwszy);
//--------------------------------------------------------------
macierz *polaczeniePoziome();
macierz *roznicaMacierzy();
macierz *iloczynMacierzy();
Lista *macierzDoListy();
Lista *usunMacierz();
macierz *losujMacierz();