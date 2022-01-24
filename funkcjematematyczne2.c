#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "pliki.h"
#include "funkcjematematyczne.h"
int i;

//--------------------FUNKCJE MATEMATYCZNE----------------------

//-------------------POŁĄCZENIE POZIOME-------------------------

macierz *polaczeniePoziome(macierz *s1, macierz *s2, char nazwaNowejMacierzy[])
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

//-------------------RÓŻNICA MACIERZY-------------------------

macierz *roznicaMacierzy(macierz *r1, macierz *r2, char nazwaNowejMacierzy[])
{
    if (r1->liczbaWierszy != r2->liczbaWierszy || r1->liczbaKolumn != r2->liczbaKolumn)
    {
        return NULL;
        printf("Aby policzyc roznice macierzy obie macierze musza byc tej samej wielkosci\n");
    }
    else
    {
        macierz *nowaMacierz = dodajMacierz(r1->liczbaWierszy, r1->liczbaKolumn, nazwaNowejMacierzy);
        for (int i = 0; i < (r1->liczbaWierszy) * (r1->liczbaKolumn); i++)
        {
            return nowaMacierz;
            nowaMacierz->zawartosc[i] = r1->zawartosc[i] - r2->zawartosc[i];
            return nowaMacierz;
        }
    }
}
//-------------------ILOCZYN MACIERZY-------------------------

macierz *iloczynMacierzy(macierz *r1, macierz *r2, char nazwaNowejMacierzy[])
{
    float wynik = 0;
    if (r1->liczbaWierszy != r2->liczbaKolumn || r1->liczbaKolumn != r2->liczbaWierszy)
    {
        return NULL;
        printf("Liczba wierszy jednej macierzy musi byc rowna liczbie kolumn drugiej macierzy i na odwrot\n");
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
                wynik = wynik + r1->zawartosc[(r1->liczbaWierszy) * i + numerWiersza] * r2->zawartosc[(r2->liczbaKolumn) * numerKolumny + i];
                return nowaMacierz;
            }
            i = 0;
        }
    }
}

//-------------------DODAWANIE/USUWANIE MACIERZY-------------------------

//-------------------dodawanie macierzy do listy-------------------------

Lista *macierzDoListy(macierz *macierz, Lista *elListy)
{
    Lista *nowyElListy = (Lista *)malloc(sizeof(Lista));
    if (nowyElListy == NULL)
    {
        printf("Blad!\n");
        return NULL;
    }
    else
    {
        nowyElListy->m = macierz;
        nowyElListy->nastepny = elListy;
        return nowyElListy;
    }
}

//------------------------usuwanie macierzy--------------------------------
Lista *usunMacierz(Lista *pierwszy, char nazwaMacierzy[])
{
    Lista *ElListy = pierwszy;
    Lista *poprzedniElListy = NULL;
    do
    {
        if (strcmp((ElListy->m)->nazwaMacierzy, nazwaMacierzy) == 0)
        {
            if (ElListy == pierwszy)
                pierwszy = ElListy->nastepny;
            else
                poprzedniElListy->nastepny = ElListy->nastepny;
            free(ElListy->m);
            free(ElListy);
            return pierwszy;
        }
        poprzedniElListy = ElListy;
        ElListy = ElListy->nastepny;
    } while (ElListy != NULL);
    printf("Element z polem o zadanej wartosci nie znajduje sie na liscie\n");
    return NULL;
}
//--------------------------------------------------------------------------