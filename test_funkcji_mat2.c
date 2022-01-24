#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAXNAZWA 20

typedef struct macierz
{
    char nazwaMacierzy[MAXNAZWA];
    int liczbaKolumn;
    int liczbaWierszy;
    float zawartosc[];
} macierz;

macierz *dodajMacierz(int liczbaWierszy, int liczbaKolumn, char nazwaMacierzy[])
{
    macierz *nowaMacierz = malloc(sizeof(char) * MAXNAZWA + 2 * sizeof(int) + sizeof(float) * liczbaWierszy * liczbaKolumn);
    strcpy(nowaMacierz->nazwaMacierzy, nazwaMacierzy);
    nowaMacierz->liczbaWierszy = liczbaWierszy;
    nowaMacierz->liczbaKolumn = liczbaKolumn;
    return nowaMacierz;
}

macierz *polaczeniePoziome(macierz *s1, macierz *s2, char nazwaNowejMacierzy[])
{
    int liczbaEl1 = s1->liczbaKolumn * s1->liczbaWierszy;
    int liczbaEl2 = s1->liczbaKolumn * s2->liczbaWierszy;
    if (s1->liczbaWierszy != s2->liczbaWierszy)
    {
        fprintf(stdout, "BLAD\nnie da sie polaczyc szeregowo macierzy o dwoch roznych liczbach wierszy\n\n");
        return NULL;
    }
    else
    {
        int nowaLiczbaElMacierzy = liczbaEl1 + liczbaEl2;
        int nowaLiczbaKolumn = s1->liczbaKolumn + s2->liczbaKolumn;
        macierz *nowaMacierz = dodajMacierz(s1->liczbaWierszy, nowaLiczbaKolumn, nazwaNowejMacierzy);
        for (int i = 0; i < liczbaEl1; i++)
        {
            nowaMacierz->zawartosc[i] = s1->zawartosc[i];
        }
        for (int i = 0; i < liczbaEl2; i++)
        {
            nowaMacierz->zawartosc[i + liczbaEl1] = s2->zawartosc[i];
        }
        nowaMacierz->liczbaWierszy = s1->liczbaWierszy;
        return nowaMacierz;
    }
}

macierz *roznicaMacierzy(macierz *r1, macierz *r2, char nazwaNowejMacierzy[])
{
    if (r1->liczbaWierszy != r2->liczbaWierszy || r1->liczbaKolumn != r2->liczbaKolumn)
    {
        printf("Aby policzyc roznice macierzy obie macierze musza byc tej samej wielkosci\n");
        return NULL;
    }
    else
    {
        macierz *nowaMacierz = dodajMacierz(r1->liczbaWierszy, r1->liczbaKolumn, nazwaNowejMacierzy);
        for (int i = 0; i < (r1->liczbaWierszy) * (r1->liczbaKolumn); i++)
        {
            nowaMacierz->zawartosc[i] = r1->zawartosc[i] - r2->zawartosc[i];
        }
        return nowaMacierz;
    }
}

macierz *iloczynMacierzy(macierz *r1, macierz *r2, char nazwaNowejMacierzy[])
{
    float wynik = 0;
    if (r1->liczbaWierszy != r2->liczbaKolumn || r1->liczbaKolumn != r2->liczbaWierszy)
    {
        printf("Liczba wierszy jednej macierzy musi byc rowna liczbie kolumn drugiej macierzy i na odwrot\n");
        return NULL;
    }
    else
    {
        macierz *nowaMacierz = dodajMacierz(r1->liczbaWierszy, r1->liczbaKolumn, nazwaNowejMacierzy);
        int numerKolumny = 0;
        int numerWiersza = 0;
        int wynik = 0;
        for (numerKolumny = 0; numerKolumny < r1->liczbaKolumn; numerKolumny++)
        {
            for (numerWiersza = 0; numerWiersza < r1->liczbaWierszy; numerWiersza++)
            {
                for (int i = 0; i < r1->liczbaKolumn; i++)
                {
                    wynik = wynik + r1->zawartosc[(r1->liczbaWierszy) * i + numerWiersza] * r2->zawartosc[(r2->liczbaKolumn) * numerKolumny + i];
                }
                nowaMacierz->zawartosc[numerKolumny * (r1->liczbaWierszy) + numerWiersza] = wynik;
                wynik = 0;
            }
        }
        return nowaMacierz;
    }
}

int main()
{
    macierz *s = dodajMacierz(3, 3, "macierz_1");
    macierz *d = dodajMacierz(3, 3, "macierz_2");
    (s->zawartosc)[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    (d->zawartosc)[] = {9, 8, 7, 6, 5, 4, 3, 2, 1};
    macierz *iloczyn = iloczynMacierzy(s, d, "macierz_iloczyn");
    macierz *roznica = roznicaMacierzy(s, d, "macierz_roznica");
    macierz *poziome = polaczeniePoziome(s, d, "macierz_polaczenie szeregowe");
    for (int i = 0; i < 9; i++)
    {
        printf("%f %f %f\n", iloczyn->zawartosc[i], roznica->zawartosc[i]);
    }
    for (int j = 0; j < 18; j++)
    {
        printf("%f ", poziome->zawartosc[j]);
    }
    return 0;
}