#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <stdlib.h>
#include <time.h>

#define MAXKOMENDA 50;
#define MAXNAZWA 20;
#define MAXLICZBASLOW 5;
#define P_B "Macierze.bin"  //P_B - plik binarny, nazwa pliku


typedef struct macierz
{
    char nazwaMacierzy[];
    int liczbaKolumn;
    int liczbaWierszy;
    float *zawartosc;
} macierz;


typedef struct Lista
{
    macierz *m;
    Lista *nastepny;
} Lista;


void wygenerujSkrypt()
{
    FILE *fptr;
    if (fptr = fopen("Instrukcja.txt", "r") != NULL)
    {
        fprintf(stdout, "Plik ze skryptem zostal juz wygenerowany wczesniej\n");
        fclose(fptr);
    }
    else
    {
        if (fptr = fopen("Instrukcja.txt", "w") != NULL) //zabezpieczenie przed nieprawidlowym otwieraniem pliku
        {
            fprintf(fptr, "Wyjscie z programu poleceniem Exit\n");
            fclose(fptr);
        }
        else
        {
            fprintf(stdout, "Blad!");
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
    wskMacierz nowaMacierz = malloc(sizeof(char) * MAXNAZWA + sizeof(wskMacierz) + sizeof(int) + sizeof(float) * liczbaElementow);
    return nowaMacierz;
}

int liczElTabeli(char tab[])
{
    int i = 0;
    int liczbaEl = 0;
    while (tab[i] != NULL)
    {
        i++;
        liczbaEl++;
    }
    return liczbaEl;
}

wskMacierz polaczenieSzeregowe(wskMacierz s1, wskMacierz s2, nazwaNowejMacierzy)
{
    int liczbaEl1 = liczElTabeli(s1->zawartosc);
    int liczbaEl2 = liczElTabeli(s2->zawartosc);
    int liczbaWierszy1 = liczbaArg1 / (s1->liczbakolumn);
    int liczbaWierszy2 = liczbaArg2 / (s2->liczbakolumn);
    if (liczbaWierszy1 != liczbaWierszy2)
    {
        fprintf(stdout, "BLAD\nnie da sie polaczyc szeregowo macierzy o dwoch roznych liczbach wierszy\n\n");
    }
    else
    {
        int nowaLiczbaElMacierzy = liczbaEl1 + liczbaEl2;
        wskMacierz nowaMacierz = dodajMacierz(nowaLiczbaElMacierzy);
        int nowaMacierz.liczbakolumn = (s1->liczbakolumn) + (s2->liczbakolumn);
        strcpy(nowaMacierz->nazwaMacierzy, nazwaNowejMacierzy);
        for (int i = 0; i < liczbaArg1, i++)
        {
            nowaMacierz->zawartosc[i] = s1->zawartosc[i];
        }
        for (int i = 0; i < liczbaArg2, i++)
        {
            nowaMacierz->zawartosc[i + liczbaArg1] = s2->zawartosc[i];
        }
        return nowaMacierz;
    }
}

int main()
{
    int c = 0;
    int i = 0;
    int j = 0;

    char kom[MAXLICZBASLOW][MAXKOMENDA];

    

    if (strcmp(kom[0], "Run") == 0) // Instrukcja obslugi
    {
        wygenerujSkrypt();
    }

    if (strcmp(kom, "") == 0)
    {
        /* Załadowanie  macierzy  z  pliku  binarnego  poleceniem  Load  nazwa_pliku  >  nazwa_macierzy. 
        ”nazwa_macierzy”  jest  łańcuchem  znaków  identyfikującym  daną  macierz.  W  systemie  nie  mogą 
        istnieć dwie macierze o takich samych nazwach. Nazwa macierzy musi zaczynać się od małej litery. */
    }
    if (strcmp(kom, "") == 0)
    {
        // Zapis macierzy do pliku binarnego poleceniem Save nazwa_macierzy > nazwa_pliku
    }
    if (strcmp(kom, "") == 0)
    {
        /* Zapis  macierzy  do  pliku  tekstowego  poleceniem  Txt  nazwa_macierzy  >  nazwa_pliku  w  formie 
        czytelnej dla człowieka (można wprowadzić ograniczenie rozmiarów macierzy). */
    }
    if (strcmp(kom, "") == 0)
    {
        /*Wypisanie macierzy na ekranie poleceniem Print nazwa_macierzy (można wprowadzić ograniczenie 
        rozmiarów macierzy, żeby zmieściła się na ekranie) */
    }
    if (strcmp(kom, "") == 0)
    {
        /*Skasowanie macierzy poleceniem Delete nazwa_macierzy*/
    }
    if (strcmp(kom, "") == 0)
    {
        /*Obliczenie różnicy macierzy: nazwa_macierzy_1 = nazwa_macierzy_2 - nazwa_macierzy_3*/
    }
    if (strcmp(kom, "") == 0)
    {
        /*Obliczenie iloczynu macierzy: nazwa_macierzy_1 =  nazwa_macierzy_2 * nazwa_macierzy_3*/
    }
    if (strcmp(kom, "") == 0)
    {
        /*Połączenie „poziome” macierzy:  
        nazwa_macierzy_1 = nazwa_macierzy_2 # nazwa_macierzy_3*/
    }
    if (strcmp(kom, "") == 0)
    {
        /*Wypisanie  na  ekranie  w  kolejności  alfabetycznej  wszystkich  aktualnie  występujących  w  systemie 
        macierzy  wraz z ich wymiarami i rozmiarem w pamięci w bajtach – polecenie List.*/
    }
}
