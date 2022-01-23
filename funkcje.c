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
        s
    }
}

macierz *zaladujZBinarnego(char nazwaPliku[], macierz *macierz)
{ //funkcja weryfikująca czy komenta prowadzi do pliku
    FILE *fb;
    if ((fb = fopen(nazwaPliku, "rb")) != NULL)

    32 fread(void * buffer 

void zapiszBin(char nazwaPliku[], macierz *macierz)
{ //funkcja powinna być aktywowana wpisaniem nazwy macierzy i od razu wychwytywać struct o tej nazwie (1. char)
            //zabezpieczenie przed tworzeniem pliku o tej samej nazwie
            char slowoPlikuNazwa[5][20];
            char *token = strtok(nazwaPliku, ".");
            while (token != NULL)
            {
                strcpy(slowoPlikuNazwa[i++], token);
                token = strtok(NULL, " ");
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
                    ;
                {
                    //      Nie wiem czy jest potrzebny taki komunikat, czy nie wykrzaczy się przez dwie komendy wyświetlania tekstu)
                    //      printf("Zapisano macierz „%s” do pliku Macierze.bin", macierz.nazwaMacierzy);
                    fwrite(macierz->liczbaKolumn, sizeof(int), 1, fb);
                    fwrite(macierz->liczbaWierszy, sizeof(int), 1, fb);
                    fwrite(macierz->zawartosc, sizeof(macierz->zawartosc), 1, fb);
                    fwrite(macierz->nazwaMacierzy, sizeof(macierz->nazwaMacierzy), 1, fb);
                    fclose(fb);
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
                    ElListy = ElListy->nast;
                }
            } while (ElListy != NULL);
            printf("Element z polem o zadanej wartosci nie znajduje sie na liscie\n");
            return pierwszy->m;
}
//--------------------------------------------------------------
//--------------------FUNKCJE MATEMATYCZNE----------------------

//-------------------POŁĄCZENIE POZIOME-------------------------
macierz *polaczeniePoziome(macierz *s1, macierz *s2, nazwaNowejMacierzy)

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

//-------------------RÓŻNICA MACIERZY-------------------------
macierz *roznicaMacierzy(macierz *r1, macierz *r2, nazwaNowejMacierzy[])
{
            if (r1->liczbaWierszy != r2->liczbaWierszy || r1.liczbaKolumn != r2.liczbaKolumn)
            {
                printf("Aby policzyc roznice macierzy obie macierze musza byc tej samej wielkosci\n")
            }
            else
            {
                macierz *nowaMacierz = dodajMacierz(r1->liczbaWierszy, r1->liczbaKolumn, nazwaNowejMacierzy);
                for (int i = 0; i < (r1->liczbaWierszy) * (r1->liczbaKolumn); i++)
                {
                    nowaMacierz->zawartosc[i] = r1->zawartosc[i] - r2->zawartosc[i];
                }
            }
            return nowaMacierz;
}

//-------------------ILOCZYN MACIERZY-------------------------
macierz *iloczynMacierzy(macierz *r1, macierz *r2, nazwaNowejMacierzy[])
{
            float wynik = 0;
            if (r1->liczbaWierszy != r2->liczbaKolumn || r1->liczbaKolumn != r2->liczbaWierszy)
            {
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
                        for (int i = 0; i < r1->liczbaKolumn; i++)
                        {
                            wynik = wynik + r1->zawartosc[(r1->liczbaWierszy) * i + numerWiersza] * r2->zawartosc[(r2->liczbaKolumn) *
                                                                                                                      numerKolumny +
                                                                                                                  i];
                        }
                        nowaMacierz->zawartosc[numerKolumny * (r1->liczbaWierszy) + numerWiersza] = wynik;
                        wynik = 0;
                    }
                }
            }
            return nowaMacierz;
}

//-------------------DODAWANIE/USUWANIE MACIERZY-------------------------
//dodawanie macierzy do listy------------------
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
//-----------------------------------------------------------
//------------usuwanie macierzy--------------------------------
Lista *usunMacierz(WskElListy pierwszy, char nazwaMacierzy[])
{
            WskElListy ElListy = pierwszy, poprzedniElListy = NULL;
            do
            {
                if (strcmp((ElListy->m)->nazwaMacierzy, nazwaMacierzy) == 0)
                {
                    if (ElListy == pierwszy)
                        pierwszy = ElListy->nast;
                    else
                        poprzedniElListy->nast = ElListy->nast;
                    free(ElListy->m);
                    free(ElListy);
                    return pierwszy;
                }
                poprzedniElListy = ElListy;
                ElListy = ElListy->nast;
            } while (ElListy != NULL);
            printf("Element z polem o zadanej wartosci nie znajduje sie na liscie\n");
            return pierwszy;
}
    //--------------------------------------------------------------