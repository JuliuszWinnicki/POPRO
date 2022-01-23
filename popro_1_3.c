#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <stdlib.h>
#include <time.h>
#include "pliki.h"
#include "funkcje.c"

macierz *zaladujZBinarnego(char nazwaPliku[], macierz *macierz)
{ //funkcja weryfikująca czy komenta prowadzi do pliku
    FILE *fb;
    if ((fb = fopen(nazwaPliku, "rb")) != NULL)
        ;
        fread(


        macierz *dodajMacierz(int liczbaWierszy, int liczbaKolumn, char nazwaMacierzy[])
        {
        macierz *nowaMacierz = malloc(sizeof(char) * MAXNAZWA + sizeof(wskMacierz) + sizeof(int) + sizeof(float) * liczbaWierszy * liczbaKolumn);
        strcpy(nowaMacierz->nazwaMacierzy, nazwaMacierzy);
        nowaMacierz->liczbaWierszy = liczbaWierszy;
        nowaMacierz->liczbaKolumn = liczbaKolumn;
        return nowaMacierz;
        }


        void sprawdzNazwe(char nazwa[], Lista *pierwszy)
        {
        while (1)
        {
            if (nazwa[0] < 'a' || nazwa[0] > 'z')
            {
                printf("Nazwa macierzy musi zaczynac sie mala litera lacinskiego alfabetu\n");
                printf("Wpisz nowa nazwe dla macierzy\n");
                memset(nazwa, 0, strlen(nazwa));
                int i = 0;
                int c = 0;
                while (c != '\n' && c != ' ')
                {
                    c = getchar();
                    nazwa[i++] = c;
                }
            }
            if (znajdzMacierz(nazwa, pierwszy) != NULL)
            {
                printf("Inna macierz juz nosi taka nazwe.")
                    memset(nazwa, 0, strlen(nazwa));
                int i = 0;
                int c = 0;
                while (c != '\n' && c != ' ')
                {
                    c = getchar();
                    nazwa[i++] = c;
                }
            }
            else
                break;
        }
        }

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
      
                                                                                                                                                                                                                                             
        int main()
        {
        Lista *pierwszyElement = NULL int c = 0;
        int i = 0;
        int j = 0;
        char komenda[MAX_KOMENDA];
        char slowo[8][MAX_SLOWO];

        //---------------pobieranie komendy-----------------
        while (c != '\n')
        {
            c = getchar();
            komenda[i++] = c;
        }
        komenda[i++] = ' ';
        i = 0;
        char *token = strtok(komenda, " ");
        while (token != NULL)
        {
            strcpy(slowo[i++], token);
            token = strtok(NULL, " ");
        }
        //---------------------------------------------------

        //----------------OPCJE MENU-------------------------
        if (strcmp(slowo[0], "Run") == 0) // Instrukcja obslugi
        {
            wygenerujSkrypt(slowo[2]);
        }

        if (strcmp(slowo[0], "Load") == 0)
        {
            //pamietac o ograniczeniu nazwy macierzy!
            zaladujZBinarnego(slowo[1], slowo[3]); //ta funkcja jeszcze nie istnieje    !!!!!!!!!!!!DO NAPISANIA!!!!!!!!!!!
                                                   //slowo[1] - nazwa pliku
                                                   //slowo[3] - nazwa macierzy
            /* Załadowanie  macierzy  z  pliku  binarnego  poleceniem  Load  nazwa_pliku  >  nazwa_macierzy. 
        ”nazwa_macierzy”  jest  łańcuchem  znaków  identyfikującym  daną  macierz.  W  systemie  nie  mogą 
        istnieć dwie macierze o takich samych nazwach. Nazwa macierzy musi zaczynać się od małej litery. */
        }
        if (strcmp(slowo[0], "Save") == 0)
        {
            macierz *m1 = znajdzMacierz(slowo[1], pierwszyElement);
            zapiszBin(slowo[3], m1); //slowo[1] - nazwa macierzy
                                     //slowo[3] - nazwa pliku
            // Zapis macierzy do pliku binarnego poleceniem Save nazwa_macierzy > nazwa_pliku
        }
        if (strcmp(slowo[0], "Txt") == 0)
        {
            macierz *m1 = znajdzMacierz(slowo[1]);
            zapiszTxt(m1, slowo[3]); //ta funkcja jeszcze nie istnieje !!!!!!!!!!DO NAPISANIA!!!!!!!!!!!!
                                     //slowo[1] - nazwa macierzy
                                     //slowo[3] - nazwa pliku
            /* Zapis  macierzy  do  pliku  tekstowego  poleceniem  Txt  nazwa_macierzy  >  nazwa_pliku  w  formie 
        czytelnej dla człowieka (można wprowadzić ograniczenie rozmiarów macierzy). */
        }
        if (strcmp(slowo[0], "Print") == 0)
        {
            macierz *m1 = znajdzMacierz(slowo[1], pierwszyElement);
        wyswietlNaEkranie(m1)); //ta funkcja jeszcze nie istnieje !!!!!!!!!!DO NAPISANIA!!!!!!!!!!!!
                                    //slowo[1] - nazwa macierzy
        /*Wypisanie macierzy na ekranie poleceniem Print nazwa_macierzy (można wprowadzić ograniczenie 
        rozmiarów macierzy, żeby zmieściła się na ekranie) */
        }
        if (strcmp(slowo[0], "Delete") == 0)
        {
            usunMacierz(slowo[1]);
            //slowo[1] - nazwa macierzy
            /*Skasowanie macierzy poleceniem Delete nazwa_macierzy*/
        }
        if (strcmp(slowo[3], "-") == 0)
        {
            if (slowo[0][0] >= 'a' && slowo[0][0] <= 'z')
            {
                macierz *m1 = znajdzMacierz(slowo[2], pierwszyElement);
                macierz *m2 = znajdzMacierz(slowo[4], pierwszyElement);
                roznicaMacierzy(m1, m2, slowo[0]); //slowo[0] - nazwa macierzy nowej
                                                   //slowo[2] - nazwa macierzy 1
                                                   //slowo[4] - nazwa macierzy 2
            }
            else
            {
                printf("Nazwa macierzy musi zaczynac sie od malej litery alfabetu lacinskiego\n");
            }
            /*Obliczenie różnicy macierzy: nazwa_macierzy_1 = nazwa_macierzy_2 - nazwa_macierzy_3*/
        }
        if (strcmp(slowo[3], "*") == 0)
        {
            if (slowo[0][0] >= 'a' && slowo[0][0] <= 'z')
            {
                macierz *m1 = znajdzMacierz(slowo[2], pierwszyElement);
                macierz *m2 = znajdzMacierz(slowo[4], pierwszyElement);
                iloczynMacierzy(m1, m2, slowo[0]);
                //slowo[0] - nazwa macierzy nowej
                //slowo[2] - nazwa macierzy 1
                //slowo[4] - nazwa macierzy 2
            }
            else
            {
                printf("Nazwa macierzy musi zaczynac sie od malej litery alfabetu lacinskiego\n");
            }
            /*Obliczenie iloczynu macierzy: nazwa_macierzy_1 =  nazwa_macierzy_2 * nazwa_macierzy_3*/
        }
        if (strcmp(slowo[3], "#") == 0)
        {
            if (slowo[0][0] >= 'a' && slowo[0][0] <= 'z')
            {
                macierz *m1 = znajdzMacierz(slowo[2], pierwszyElement);
                macierz *m2 = znajdzMacierz(slowo[4], pierwszyElement);
                polaczeniePoziome(m1, m2, slowo[0]);
            }
            else
            {
                printf("Nazwa macierzy musi zaczynac sie od malej litery alfabetu lacinskiego\n");
            }
            /*Połączenie „poziome” macierzy:  
        nazwa_macierzy_1 = nazwa_macierzy_2 # nazwa_macierzy_3*/
        }
        if (strcmp(slowo[0], "List") == 0)
        {
            wypiszAlfabetycznie(); //funkcja jeszcze nie istenieje !!!!!!!DO NAPISANIA!!!!!!!!!!!!
            /*Wypisanie  na  ekranie  w  kolejności  alfabetycznej  wszystkich  aktualnie  występujących  w  systemie 
        macierzy  wraz z ich wymiarami i rozmiarem w pamięci w bajtach – polecenie List.*/
        }

        if (strcmp(slowo[0], "Random") == 0)
        {
            macierz *m1 = losujMacierz(slowo[1])
        /* po wpisaniu "Random "nazwaNowejMacierzy
    }
    //-------------------------------------------
}