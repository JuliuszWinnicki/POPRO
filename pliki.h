
//--------------DEFINICJE--------------------------
#define MAX_KOMENDA 200;
#define MAX_SLOWO 40;
#define MAXNAZWA 20;
#define MAXLICZBASLOW 5;
#define P_B "Macierze.bin" //P_B - plik binarny, nazwa pliku

//--------------STRUKTURY--------------------------

typedef struct macierz
{
    char nazwaMacierzy[MAXNAZWA];
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
void wygenerujSkrypt(char);
void zapiszBin(char nazwaPliku[], macierz *macierz);
//----------znajdowanie macierzy w liscie po nazwie------------
macierz *znajdzMacierz(char nazwaMacierzy[], Lista *pierwszy);
//--------------------------------------------------------------
macierz *polaczeniePoziome();
macierz *roznicaMacierzy();
macierz *iloczynMacierzy();
Lista *macierzDoListy();
Lista *usunMacierz();