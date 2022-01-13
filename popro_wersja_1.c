#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <stdlib.h>
#include <time.h>

#define MAXKOMENDA 50;
#define MAXNAZWA 20;



struct macierz
{
    char nazwamacierzy[MAXNAZWA];
    int liczbaKolumn;
    char zawartosc[];
    struct macierz* nastepny;
};

typedef struct macierz macierz;
typedef struct macierz* wskMacierz;

void wynegerujSkrypt()
{
    FILE *fptr;
    if(fptr=fopen("Instrukcja.txt", "r")!=NULL)
    {
        fprintf(stdout, "Plik ze skryptem zostal juz wygenerowany wczesniej\n");
        fclose(fptr);
    }
    else
    {
        if(fptr=fopen("Instrukcja.txt", "w")!=NULL) //zabezpieczenie przed nieprawidlowym otwieraniem pliku
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

wskMacierz dodajMacierz (int liczbaElementow)
{
    wskMacierz nowaMacierz = malloc(sizeof(char)*MAXNAZWA+sizeof(wskMacierz)+sizeof(int)+sizeof(char)*liczbaElementow);
    return nowaMacierz;
}

void polaczenieSzeregowe (macierz s1, macierz s2)
{
    int nowaLiczbaKolumn = s1.liczbakolumn + s2.liczbakolumn;
    wskMacierz nowaMacierz
}


int main()
{
    int c = 0;
    int i = 0;

    char kom[MAXKOMENDA];

    while (c != '') //wczytwanie komend
    {
        c = getchar();
        kom[i++] = c;
    }

    if (strcmp(kom, "Run") == 0) // Instrukcja obslugi
    {
        wygenerujSkrypt();
    }

    int wiersz, kolumna;
    int d;

    scanf("%d", &wiersz);
    scanf("%d", &kolumna);
    d=wiersz*kolumna;

    macierz *macierz;

    macierz = malloc(sizeof(char)*MAXNAZWA+sizeof(wskMacierz)+sizeof(int)+sizeof(int) * d);
    for (i = 0; i < d, i++)
    {
        macierz[i] = i + 1;
    }


    struct macierz *s = malloc(sizeof(*s) + sizeof(char[strlen(zawartosc)]));
}
