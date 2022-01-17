#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <stdlib.h>
#include <time.h>

#define MAX_KOMENDA 200;
#define MAX_SLOWO 40;
#define MAXNAZWA 20;
#define MAXLICZBASLOW 5;
#define P_B "Macierze.bin"  //P_B - plik binarny, nazwa pliku


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



void wygenerujSkrypt(char nazwapliku[])
{

    FILE *fptr;
    if (fptr = fopen(nazwapliku, "r") != NULL)
    {
        fprintf(stdout, "Plik o podanej nazwie juz istnieje\n");
        fclose(fptr);
    }
    else
    {
        if (fptr = fopen(nazwapliku, "w") != NULL) //zabezpieczenie przed nieprawidlowym otwieraniem pliku
        {
            fprintf(fptr, "Wyjscie z programu poleceniem Exit\n");
            fclose(fptr);
        }
        else
        {
            fprintf(stdout, "Blad!");
            fprintf(stdout, "Sprawdz czy wprowadzona nazwa pliku zawiera \".txt\" na koncu.\n");
        }
    }
}

void zapiszBin(void)
{   //funkcja powinna być aktywowana wpisaniem nazwy macierzy i od razu wychwytywać struct o tej nazwie (1. char)
    char nmbin = macierz.nazwaMacierzy; //nmbin czyli zapis nazwy macierzy do binarnej
    int lkbin = macierz.liczbaKolumn; //lkb -//- liczby kolumn
    char zbin = macierz.zawartosc;   //zbin -//- zawartosc
    FILE* fb;
    if ((fb=fopen(P_B, "wb"))!=NULL);
    {
//      Nie wiem czy jest potrzebny taki komunikat, czy nie wykrzaczy się przez dwie komendy wyświetlania takstu)
//      printf("Zapisano macierz „%s” do pliku Macierze.bin", macierz.nazwaMacierzy);
        fwrite(nmbin, sizeof(mnbin), 1, fb);
        fwrite(lkbin, sizeof(lkbin), 1, fb);
        fwrite(zbin, sizeof(zbin), 1, fb);
    fclose(fb);
    }
    // else
    // {
    // fprintf(stdout, "Blad!");
    // }

macierz* dodajMacierz(int liczbaElementow)
{
    macierz* nowaMacierz = malloc(sizeof(char) * MAXNAZWA + sizeof(wskMacierz) + sizeof(int) + sizeof(float) * liczbaElementow);
    return nowaMacierz;
}

//----------znajdowanie macierzy w liscie po nazwie------------
macierz* znajdzMacierz(char nazwaMacierzy[], Lista* pierwszy)
{
    Lista* ElListy=pierwszy;
	do {
        if(strcmp((ElListy->m)->nazwaMacierzy, nazwaMacierzy)==0) {
        	return ElListy->m;
        }
        else{
        ElListy = ElListy->nast;
        }
	} while(ElListy != NULL);
	printf("Element z polem o zadanej wartosci nie znajduje sie na liscie\n");
	return pierwszy->m;
}
//--------------------------------------------------------------

//-------chyba ta funkcja nie bedzie potrzebna--------
/*int liczElTabeli(char tab[])
{
    int i = 0;
    int liczbaEl = 0;
    while (tab[i] != NULL)
    {
        i++;
        liczbaEl++;
    }
    return liczbaEl;
}*/
//-----------------------------------------------------

macierz* polaczeniePoziome(macierz* s1, macierz* s2, nazwaNowejMacierzy)
{
    int liczbaEl1 = s1->liczbaKolumn * s1->liczbaWierszy;
    int liczbaEl2 = s1->liczbaKolumn * s2->liczbaWierszy;
    if (s1->liczbaWierszy != s2->liczbaWierszy)
    {
        fprintf(stdout, "BLAD\nnie da sie polaczyc szeregowo macierzy o dwoch roznych liczbach wierszy\n\n");
    }
    else
    {
        int nowaLiczbaElMacierzy = liczbaEl1 + liczbaEl2;
        macierz* nowaMacierz = dodajMacierz(nowaLiczbaElMacierzy);
        int nowaMacierz.liczbaKolumn = (s1->liczbaKolumn) + (s2->liczbaKolumn);
        strcpy(nowaMacierz->nazwaMacierzy, nazwaNowejMacierzy);
        for (int i = 0; i < liczbaEl1, i++)
        {
            nowaMacierz->zawartosc[i] = s1->zawartosc[i];
        }
        for (int i = 0; i < liczbaEl2, i++)
        {
            nowaMacierz->zawartosc[i + liczbaEl1] = s2->zawartosc[i];
        }
        nowaMacierz->liczbaWierszy = s1->liczbaWierszy;
        return nowaMacierz;
    }
}

Lista* macierzDoListy(macierz* macierz, Lista* elListy)
{
    Lista* nowyElListy= (Lista*)malloc(sizeof(Lista) );
    if(nowyElListy==NULL)
    {
        printf("Blad!\n");
        return NULL;
    }
    else
    {
        nowyElListy->m=macierz;
        nowyElListy->nastepny=elListy;
        return nowyElListy;
    }
}

int main()
{
    Lista* pierwszyElement = NULL
    int c = 0;
    int i = 0;
    int j = 0;
    char komenda[MAX_KOMENDA];
    char slowo[8][MAX_SLOWO];
    
    //---------------pobieranie komendy-----------------
    while(c!='\n')
    {
        c=getchar();
        komenda[i++]=c;
    }
    char* token = strtok(komenda, " ");
    while(token!=NULL)
    {
        strcpy(slowo[i++], token);
        token=strtok(NULL, " ");
    }
    slowo[i+1]="STOP";
    //---------------------------------------------------

    //----------------OPCJE MENU-------------------------
    if (strcmp(slowo[0], "Run") == 0) // Instrukcja obslugi
    {
        wygenerujSkrypt(slowo[2]);
    }

    if (strcmp(slowo[0], "Load") == 0)
    {
        zaladujZBinarnego(slowo[1], slowo[3]); //ta funkcja jeszcze nie istnieje    !!!!!!!!!!!!DO NAPISANIA!!!!!!!!!!!
                                               //slowo[1] - nazwa pliku
                                               //slowo[3] - nazwa macierzy
        /* Załadowanie  macierzy  z  pliku  binarnego  poleceniem  Load  nazwa_pliku  >  nazwa_macierzy. 
        ”nazwa_macierzy”  jest  łańcuchem  znaków  identyfikującym  daną  macierz.  W  systemie  nie  mogą 
        istnieć dwie macierze o takich samych nazwach. Nazwa macierzy musi zaczynać się od małej litery. */
    }
    if (strcmp(slowo[0], "Save") == 0)
    {
        zapiszBin(slowo[1], slowo[3]); //slowo[1] - nazwa macierzy
                                       //slowo[3] - nazwa pliku 
        // Zapis macierzy do pliku binarnego poleceniem Save nazwa_macierzy > nazwa_pliku
    }
    if (strcmp(slowo[0], "Txt") == 0)
    {
        zapiszTxt (slowo[1], slowo[3]); //ta funkcja jeszcze nie istnieje !!!!!!!!!!DO NAPISANIA!!!!!!!!!!!!
                                       //slowo[1] - nazwa macierzy
                                       //slowo[3] - nazwa pliku
        /* Zapis  macierzy  do  pliku  tekstowego  poleceniem  Txt  nazwa_macierzy  >  nazwa_pliku  w  formie 
        czytelnej dla człowieka (można wprowadzić ograniczenie rozmiarów macierzy). */
    }
    if (strcmp(slowo[0], "Print") == 0)
    {
        wyswietlNaEkranie(slowo[1]); //ta funkcja jeszcze nie istnieje !!!!!!!!!!DO NAPISANIA!!!!!!!!!!!!
                                    //slowo[1] - nazwa macierzy
        /*Wypisanie macierzy na ekranie poleceniem Print nazwa_macierzy (można wprowadzić ograniczenie 
        rozmiarów macierzy, żeby zmieściła się na ekranie) */
    }
    if (strcmp(slowo[0], "Delete") == 0)
    {
        usunMacierz(slowo[1]); //ta funkcja jeszcze nie istnieje !!!!!!!!!!DO NAPISANIA!!!!!!!!!!!!
                                //slowo[1] - nazwa macierzy
        /*Skasowanie macierzy poleceniem Delete nazwa_macierzy*/
    }
    if (strcmp(slowo[3], "-") == 0)
    {
        roznicaMacierzy(slowo[0], slowo[2], slowo[4]); //ta funkcja jeszcze nie istnieje !!!!!!!!!!DO NAPISANIA!!!!!!!!!!!!
                                                       //slowo[0] - nazwa macierzy nowej
                                                       //slowo[2] - nazwa macierzy 1
                                                       //slowo[4] - nazwa macierzy 2
        /*Obliczenie różnicy macierzy: nazwa_macierzy_1 = nazwa_macierzy_2 - nazwa_macierzy_3*/
    }
    if (strcmp(slowo[3], "*") == 0)
    {
        iloczynMacierzy(slowo[0], slowo[2], slowo[4]); //ta funkcja jeszcze nie istnieje !!!!!!!!!!DO NAPISANIA!!!!!!!!!!!!
                                                       //slowo[0] - nazwa macierzy nowej
                                                       //slowo[2] - nazwa macierzy 1
                                                       //slowo[4] - nazwa macierzy 2
        /*Obliczenie iloczynu macierzy: nazwa_macierzy_1 =  nazwa_macierzy_2 * nazwa_macierzy_3*/
    }
    if (strcmp(slowo[3], "#") == 0)
    {
        znajdzMacierz(slowo[2]);
        znajdzMacierz(slowo[4]);
        polaczeniePoziome(slowo[0], slowo[2], slowo[4]);
        /*Połączenie „poziome” macierzy:  
        nazwa_macierzy_1 = nazwa_macierzy_2 # nazwa_macierzy_3*/
    }
    if (strcmp(kom, "") == 0)
    {
        /*Wypisanie  na  ekranie  w  kolejności  alfabetycznej  wszystkich  aktualnie  występujących  w  systemie 
        macierzy  wraz z ich wymiarami i rozmiarem w pamięci w bajtach – polecenie List.*/
    }
    //-------------------------------------------
}
