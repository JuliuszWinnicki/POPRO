#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <stdlib.h>
#include <time.h>

//definicje
#define BUFSIZE 250
#define MAX_KOMENDA 500
#define MAX_SLOWO 250
#define MAXNAZWA 250

typedef struct macierz
{
    char nazwaMacierzy[BUFSIZE];
    int liczbaKolumn;
    int liczbaWierszy;
    float *zawartosc;
} macierz;

typedef struct Lista
{
    macierz *m;
    struct Lista *nastepny;
} Lista;

void czyszczenieBufora(void)
//funkcja do czyszczenia bufora
{
    char c;
    do
    c = getchar();
    while ( c!='\n' && c!=EOF );
}

macierz *znajdzMacierz(char nazwaMacierzy[], Lista *pierwszy) {
        Lista *ElListy = pierwszy;
        if(pierwszy==NULL) return NULL;
        do {
            if (strcmp((ElListy->m)->nazwaMacierzy, nazwaMacierzy) == 0) {
                printf("Jest juz macierz o takiej nazwie\n");
                return ElListy->m;
            } else {
                ElListy = ElListy->nastepny;
            }
        } while (ElListy != NULL);
        printf("Element z polem o zadanej wartosci nie znajduje sie na liscie\n");
        return NULL;
    }

void sprawdzNazwe(char nazwa[], Lista *pierwszy) {
            if (nazwa[0] < 'a' || nazwa[0] > 'z') {
                printf("Nazwa macierzy musi zaczynac sie mala litera lacinskiego alfabetu\n");
                printf("Wpisz nowa nazwe dla macierzy\n");
                memset(nazwa, 0, strlen(nazwa));
                int i = 0;
                int c = 0;
                while (c != '\n' && c != ' ') {
                    c = getchar();
                    nazwa[i++] = c;
                }
                sprawdzNazwe(nazwa, pierwszy);
            }
            printf("Nazwa naczyna sie na mala litere alfabetu lacinskiego +++\n");
            if (znajdzMacierz(nazwa, pierwszy) != NULL) {
                printf("Inna macierz juz nosi taka nazwe.\n");
                memset(nazwa, 0, strlen(nazwa));
                printf("wpisz nowa nazwe dla macierzy\n ");
                int i = 0;
                int c = 0;
                while (c != '\n' && c != ' ') {
                    c = getchar();
                    nazwa[i++] = c;
                }
                sprawdzNazwe(nazwa, pierwszy);
            } 
            printf("Nazwa nie powtarza sie\n");
            if(znajdzMacierz(nazwa, pierwszy) == NULL && nazwa[0] >= 'a' && nazwa[0] <= 'z') 
            {
                printf("Nazwa nie zawiera bledow\n");
            }
        printf("tu jestem\n");
    }

macierz *dodajMacierz(int liczbaWierszy, int liczbaKolumn, char nazwaMacierzy[])
{
    printf("jestem w funkcji dodaj Macierz\n");
    int liczbaEl = liczbaKolumn * liczbaWierszy;
    macierz *nowaMacierz = malloc(sizeof(char) * MAXNAZWA + sizeof(macierz *) + 2 * sizeof(int) + sizeof(float) * liczbaEl);
    printf("Poprawnie zaalokowano macierz\n");
    strcpy(nowaMacierz->nazwaMacierzy, nazwaMacierzy);
    //printf("Nazwa macierzy: %s", nowaMacierz->nazwaMacierzy);
    nowaMacierz->liczbaWierszy = liczbaWierszy;
    //printf("Liczba wierszy: %d", nowaMacierz->liczbaWierszy);
    nowaMacierz->liczbaKolumn = liczbaKolumn;
    //printf("Liczba kolumn: %d", nowaMacierz->liczbaKolumn);
    nowaMacierz->zawartosc = (float*)malloc(sizeof(float)*liczbaEl);
    return nowaMacierz;
}

Lista *macierzDoListy(macierz *macierz, Lista *elListy)
    {
        Lista *nowyElListy = (Lista *) malloc(sizeof(Lista));
        if (nowyElListy == NULL) {
            printf("Blad!\n");
            return NULL;
        } else {
            nowyElListy->m = macierz;
            nowyElListy->nastepny = elListy;
            return nowyElListy;
        }
    }

void wygenerujSkrypt(char nazwapliku[]) {
        FILE *fptr;
        if ((fptr = fopen(nazwapliku, "r")) != NULL) {
            fprintf(stdout, "Plik o podanej nazwie juz istnieje\n");
            fclose(fptr);
        } else {
            if ((fptr = fopen(nazwapliku, "w")) != NULL) //zabezpieczenie przed nieprawidlowy otwieraniem pliku
            {
                fprintf(fptr, "Wyjscie z programu poleceniem Exit\n");
                fclose(fptr);
            } else {
                fprintf(stdout, "Blad!");
                fprintf(stdout, "Sprawdz czy wprowadzona nazwa pliku zawiera \".txt\" na koncu\n");
            }
        }
    }

macierz *losujMacierz(char nazwaMacierzy[]) {
        int liczbaKolumn, liczbaWierszy;
        int liczbaElementow=0;
        printf("uruchamiam funkcje losujMacierz\n");
        srand(time(NULL));
        printf("Podaj liczbe kolumn\n");
        scanf("%d", &liczbaKolumn);
        printf("Podaj liczbe wierszy\n");
        scanf("%d", &liczbaWierszy);
        printf("Liczba Kolumn: %d, Liczba Wierszy: %d\n", liczbaKolumn, liczbaWierszy);
        liczbaElementow = liczbaKolumn * liczbaWierszy;
        printf("liczba elementow macierzy: %d\n", liczbaElementow);
        macierz *wylosowana = dodajMacierz(liczbaWierszy, liczbaKolumn, nazwaMacierzy);
        //printf("Liczba wierszy: %d, Liczba kolumn: %d, Nazwa macierzy: %s", wylosowana->liczbaWierszy, wylosowana->liczbaKolumn, wylosowana->nazwaMacierzy);
        int random;
        for (int i = 0; i < liczbaElementow; i++) {
            random = rand() % 10;
            wylosowana->zawartosc[i] = random;
        }
        return wylosowana;
    }

void wyswietlNaEkranie (macierz* m)
    {
        printf("%s", m->nazwaMacierzy);
        for(int i=0; i<m->liczbaWierszy;i++){
            for(int j=0; j<m->liczbaKolumn; j++){
                printf("%.2f  ", m->zawartosc[i+j*m->liczbaWierszy]);
            }
            printf("\n\n");
        }
    }

void main (){
    //--------DEKLARACJA ZMIENNYCH FUNKCJI MAIN--------
    Lista *pierwszyElement = NULL;
    int c = 0;
    char komenda[MAX_KOMENDA];
    char slowo[8][MAX_SLOWO];
    int i=0;
    while(1){
    //--------POBIERANIE KOMENDY-----------------------
    memset(komenda, ' ', MAX_KOMENDA*sizeof(char));
    for(int o=0; o<8; o++)
    {
        memset(slowo[o], ' ', MAX_SLOWO*sizeof(char));
    }
     while (c != '\n') {
            c = getchar();
            komenda[i++] = c;
        }
        komenda[i++] = ' ';
        i=0;
        char *token = strtok(komenda, " ");
        while (token != NULL) {
            strcpy(slowo[i++], token);
            token = strtok(NULL, " ");
        }
       i=0;
    //---------OPCJE MENU-------------------------------
    if (strcmp(slowo[0], "Run") == 0) // Wygenerowanie instrukcji obslugi
        {
            wygenerujSkrypt(slowo[1]);
        }
    if (strcmp(slowo[0], "Random") == 0)
        {
            sprawdzNazwe(slowo[1], pierwszyElement);
            macierz *m1 = losujMacierz(slowo[1]);
            pierwszyElement=macierzDoListy(m1, pierwszyElement);
            wyswietlNaEkranie(m1);
        }
    if (strcmp(slowo[0], "Print") == 0)
        {
            macierz *m1 = znajdzMacierz(slowo[1], pierwszyElement);
            wyswietlNaEkranie(m1); //ta funkcja jeszcze nie istnieje !!!!!!!!!!DO NAPISANIA!!!!!!!!!!!!
           //slowo[1] - nazwa macierzy
           /*Wypisanie macierzy na ekranie poleceniem Print nazwa_macierzy (można wprowadzić ograniczenie
           rozmiarów macierzy, żeby zmieściła się na ekranie) */
        }
    if(strcmp(slowo[0], "Exit")==0)
    {
        exit(0);
    }
    }
}