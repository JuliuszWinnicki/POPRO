#include "pliki.h"
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <stdlib.h>
#include <time.h>

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

macierz *zaladujZBinarnego(char nazwaPliku[], macierz *macierz)
{

    int i = 0;

    macierz *wgrywana = dodajMacierz char slowoPlikuNazwa[5][20];
    char *token = strtok(nazwaPliku, ".");
    while (token != NULL)
    {
        strcpy(slowoPlikuNazwa[i++], token);
        token = strtok(NULL, ".");
    }
    if (strcmp(slowoPlikuNazwa[i], "bin") != 0)
    {
        strcat(nazwaPliku, ".bin");
    }
    int liczbaKolumn;
    int liczbaWierszy;
    char nazwaMacierzy[BUFSIZE];
    FILE *fb;
    if ((fb = fopen(nazwaPliku, "rb")) != NULL)
    {
        fread(*liczbaKolumn, sizeof(int), 1, fb);
        fread(nazwaMacierzy, sizeof(char) * BUFSIZE, 1, fb);
        macierz *wgrywana = dodajMacierz(liczbaWierszy, liczbaKolumn, nazwaMacierzy);
        fread(wgrywana->zawartosc, sizeof(float) * liczbaWierszy * liczbaKolumn, 1, fb);
        fclose(fb);
        fread(*liczbaWierszy, sizeof(int), 1, fb);
    }

    return wgrywana;
}

void zapiszBin(char nazwaPliku[], macierz *macierz)
{ //funkcja powinna być aktywowana wpisaniem nazwy macierzy i od razu wychwytywać struct o tej nazwie (1. char)
    //zabezpieczenie przed tworzeniem pliku o tej samej nazwie
    char slowoPlikuNazwa[5][20];
    char *token = strtok(nazwaPliku, ".");
    while (token != NULL)
    {
        strcpy(slowoPlikuNazwa[i++], token);
        token = strtok(NULL, ".");
    }
    if (strcmp(slowoPlikuNazwa[i], "bin") != 0)
    {
        strcat(nazwaPliku, ".bin");
    }
    FILE *fb;
    if ((fb = fopen(nazwaPliku, "wr")) != NULL)
    {
        fprintf(stdout, "Juz istnieje plik o danej nazwie\n");
    }
    else
    {
        if ((fb = fopen(nazwaPliku, "wb")) != NULL)
        {
            //      Nie wiem czy jest potrzebny taki komunikat, czy nie wykrzaczy się przez dwie komendy wyświetlania tekstu)
            //      printf("Zapisano macierz „%s” do pliku Macierze.bin", macierz.nazwaMacierzy);
            fwrite(macierz->liczbaKolumn, sizeof(int), 1, fb);
            fwrite(macierz->liczbaWierszy, sizeof(int), 1, fb);
            fwrite(macierz->zawartosc, sizeof(macierz->zawartosc fwrite(macierz->nazwaMacierzy, sizeof(char) * BUFSIZE, 1, fb); c), 1, fb);
            fwrite(macierz->nazwaMacierzy, sizeof(float * macierz->liczbaKolumn * macierz->liczbaWierszymacierzy),
        }
        else
        {
            fprintf(stdout, "Blad!\n");
        }
    }
}

//----------znajdowanie macierzy w liscie po nazwie------------

macierz *znajdzMacierz(char nazwaMacierzy[], Lista *pierwszy)
{
    Lista *ElListy = pierwszy;
    do
    {
        if (strcmp((ElListy->m)->nazwaMacierzy, nazwaMacierzy) == 0)
        {
            return ElListy->m;
        }
        else
        {
            ElListy = ElListy->nastepny;
        }
    } while (ElListy != NULL);
    printf("Element z polem o zadanej wartosci nie znajduje sie na liscie\n");
    return pierwszy->m;
}
//--------------------------------------------------------------

macierz *LosujMacierz(int liczbaKolumn, int Liczba Wierszy, char nazwaMacierzy[])
{
    srand(time(NULL));
    int lZaw = liczbaKolumn * liczbaWierszy;
    macierz *wylosowana = dodajMacierz(liczbaWierszy, liczbaKolumn, nazwaMacierzy);
    int random;
    for (int i = 0; i < lZaw; i++)
    {
        random = rand() % 10;
        macierz->zawartosc[i] = random;
    }
    return wylosowana;
}

while ()st()strcpty()el-Listy->nazwa[]0]><elnowyElListy->nazwaMaciezrzyMacierzy[]0]
            for()int i            while()int
            int i=0;
i <= 0;
i < BUZSIFSIZE;
i++
{
}

while (elListy->nazwaMacierzy[0] < nowyElListy->nazwaMacierzy[0])
    iii &&elListaMacierzy
    {
    }

elListy->m = t int tempmacierz * templ;
= NULLmacierztemp = elListy->m;
elListy-- > = m = elListy->nastepny;
poprzednipoprzedni1 if () elListy > wdo {}

elListy->m = poprzedni = elListy->m;
;
elListy = ListaelLsisty->nastepny;()while()elListy->nazwaMAcieacierzy[]i]>naznowyElListy->nazwaMacierzy[]i]<;
i++;

licz = 0;
itnt
    licz++;