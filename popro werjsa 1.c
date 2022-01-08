#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <stdlib.h>
#include <time.h>

#define MAXKOMENDA 50;
#define MAXNAZWA 20;

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
        FILE *fptr;
        fopen("Instrukcja.txt", "w");
        fprintf(fptr, "Wyjście z programu poleceniem Exit");
        fclose(fptr);
    }

    int wiersz, kolumna;
    int d = (wiersz * kolumna); //liczba elementow macierzy

    scanf("%d", &wiersz);
    scanf("%d", &kolumna);

    int *macierz;

    macierz = malloc(sizeof(int) * d);
    for (i = 0; i < d, i++)
    {
        macierz[i] = i + 1;
    }

    struct macierz
    {
        char nazwamacierzy[MAXNAZWA];
        int cokolwiek;
        char zawartosc[];
    }

    struct macierz *s = malloc(sizeof(*s) + sizeof(char[strlen(zawartosc)]));
}
