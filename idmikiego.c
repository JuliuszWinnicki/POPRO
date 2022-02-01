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
    while (c != '\n' && c != EOF);
}

macierz *znajdzMacierz(char nazwaMacierzy[], Lista *pierwszy)
{
    Lista *ElListy = pierwszy;
    if (pierwszy == NULL)
        return NULL;
    do
    {
        if (strcmp((ElListy->m)->nazwaMacierzy, nazwaMacierzy) == 0)
        {
            printf("Jest juz macierz o takiej nazwie\n");
            return ElListy->m;
        }
        else
        {
            ElListy = ElListy->nastepny;
        }
    } while (ElListy != NULL);
    printf("Element z polem o zadanej wartosci nie znajduje sie na liscie\n");
    return NULL;
}

void sprawdzNazwe(char nazwa[], Lista *pierwszy)
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
        sprawdzNazwe(nazwa, pierwszy);
    }
    printf("Nazwa naczyna sie na mala litere alfabetu lacinskiego +++\n");
    if (znajdzMacierz(nazwa, pierwszy) != NULL)
    {
        printf("Inna macierz juz nosi taka nazwe.\n");
        memset(nazwa, 0, strlen(nazwa));
        printf("wpisz nowa nazwe dla macierzy\n ");
        int i = 0;
        int c = 0;
        while (c != '\n' && c != ' ')
        {
            c = getchar();
            nazwa[i++] = c;
        }
        sprawdzNazwe(nazwa, pierwszy);
    }
    printf("Nazwa nie powtarza sie\n");
    if (znajdzMacierz(nazwa, pierwszy) == NULL && nazwa[0] >= 'a' && nazwa[0] <= 'z')
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
    nowaMacierz->zawartosc = (float *)malloc(sizeof(float) * liczbaEl);
    return nowaMacierz;
}

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
        printf("PIZZA");
        return nowyElListy;
    }
}

void wygenerujSkrypt(char nazwapliku[])
{
    FILE *fptr;
    if ((fptr = fopen(nazwapliku, "r")) != NULL)
    {
        fprintf(stdout, "Plik o podanej nazwie juz istnieje\n");
        fclose(fptr);
    }
    else
    {
        if ((fptr = fopen(nazwapliku, "w")) != NULL) //zabezpieczenie przed nieprawidlowy otwieraniem pliku
        {
            fprintf(fptr, "WITAJ W PROGRAMIE MACIERZE KI_4\n");
            fprintf(fptr, "Polecenie: Exit \nDziałanie: Wyjście z programu\n");
            fprintf(fptr, "Polecenie: Load [nazwa_pliku] > [nazwa_macierzy]\nDziałanie: Załadowanie macierzy z pliku [nazwa_pliku] i nazwanie jej [nazwa_macierzy]\n");
            fprintf(fptr, "Polecenie: Txt [nazwa_macierzy] > [nazwa_pliku]\nDziałanie: Zapisanie konkretnej macierzy [nazwa_macierzy] do pliku [nazwa_pliku]\n");
            fprintf(fptr, "Polecenie: Print [nazwa_macierzy]\nDziałanie: Wypisanie na ekranie macierzy [nazwa_macierzy]\n");
            fprintf(fptr, "Polecenie: Delete [nazwa_macierzy]\nDziałanie: Skasowanie macierzy [nazwa_macierzy]\n");
            fprintf(fptr, "Polecenie: [nazwa_macierzy_1] = [nazwa_macierzy_2] - [nazwa_macierzy_3]\nDziałanie: Obliczenie różnicy między macierzami [nazwa_macierzy_2], a [nazwa_macierzy_3] równą [nazwa_macierzy_1]\n");
            fprintf(fptr, "Polecenie: [nazwa_macierzy_1] = [nazwa_macierzy_2] * [nazwa_macierzy_3]\nDziałanie: Obliczenie iloczynu macierzy [nazwa_macierzy_2] i [nazwa_macierzy_3] równy [nazwa_macierzy_1]\n");
            fprintf(fptr, "Polecenie: [nazwa_macierzy_1] = [nazwa_macierzy_2] # [nazwa_macierzy_3]\nDziałanie: Poziome łączenie macierzy [nazwa_macierzy_2] i [nazwa_macierzy_3] w macierz [nazwa_macierzy_1]\n");
            fprintf(fptr, "Polecenie: List\nDziałanie: Wypisanie w kolejności alfabetycznej wszystkich obecnych w systemie macierzy, informując o ich wymiarach i rozmiarze pamięci (w bajtach)\n");
            fprintf(fptr, "Polecenie: Run instrukcja\nDziałanie: Wypisuje instrukcję poleceń (aktualnie ją czytasz)\n");
            fprintf(fptr, "Polecenie: Quit instrukcja\nDziałanie; Opuszcza instrukcję poleceń (aktualnie ją czytasz)\n");
            fclose(fptr);
        }
        else
        {
            fprintf(stdout, "Blad!");
            fprintf(stdout, "Sprawdz czy wprowadzona nazwa pliku zawiera \".txt\" na koncu\n");
        }
    }
}

macierz *losujMacierz(char nazwaMacierzy[])
{
    int liczbaKolumn, liczbaWierszy;
    int liczbaElementow = 0;
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
    for (int i = 0; i < liczbaElementow; i++)
    {
        random = rand() % 10;
        wylosowana->zawartosc[i] = random;
    }
    return wylosowana;
}

void wyswietlNaEkranie(macierz *m)
{
    printf("%s", m->nazwaMacierzy);
    for (int i = 0; i < m->liczbaWierszy; i++)
    {
        for (int j = 0; j < m->liczbaKolumn; j++)
        {
            printf("%.2f  ", m->zawartosc[i + j * m->liczbaWierszy]);
        }
        printf("\n\n");
    }
}

//----------------------połączenie poziome-------------------------------------
macierz *polaczeniePoziome(macierz *s1, macierz *s2, char nazwaNowejMacierzy[])
{
    int liczbaEl1 = s1->liczbaKolumn * s1->liczbaWierszy;
    int liczbaEl2 = s1->liczbaKolumn * s2->liczbaWierszy;
    if (s1->liczbaWierszy != s2->liczbaWierszy)
    {
        fprintf(stdout, "BLAD\nnie da sie polaczyc szeregowo macierzy o dwoch roznyc liczbach wierszy\n\n");
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

    return NULL; // DODAŁEM JJJJ
}
//-------------------ILOCZYN MACIERZY------------------------------------------
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

//-------------------RÓŻNICA MACIERZY----------------------------------------------

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
Lista *usunMacierz(Lista *pierwszy, char nazwaMacierzy[])
{
    Lista *ElListy = pierwszy, *poprzedniElListy;
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
    return pierwszy;
}
void zapiszBin(char nazwaPliku[], macierz *macierz)
{ //funkcja powinna być aktywowana wpisaniem nazwy macierzy i od razu wychwytywać struct o tej nazwie (1. char)
    //zabezpieczenie przed tworzeniem pliku o tej samej nazwie
    char slowoPlikuNazwa[5][20];
    char *token = strtok(nazwaPliku, ".");
    int i;
    while (token != NULL)
    {
        strcpy(slowoPlikuNazwa[i++], token);
        token = strtok(NULL, ".");
    }
    if (strcmp(slowoPlikuNazwa[i], "bin") != 0)
    {
        strcat(nazwaPliku, ".bin");
    }
    int tab[2];
    tab[0] = macierz->liczbaKolumn;
    tab[1] = macierz->liczbaWierszy;
    FILE *fb;
    if ((fb = fopen(nazwaPliku, "wb")) != NULL)
    {
        //      Nie wiem czy jest potrzebny taki komunikat, czy nie wykrzaczy się przez dwi komendy wyświetlania tekstu)
        //      printf("Zapisano macierz „%s” do pliku Macierze.bin", macierz.nazwaMacierzy);
        printf("Tutaj!!\n");
        fwrite(tab, sizeof(int), 2, fb);
        fwrite(macierz->zawartosc, sizeof(float), macierz->liczbaKolumn * macierz->liczbaWierszy, fb);
        fclose(fb);
    }
    else
    {
        fprintf(stdout, "Blad!\n");
    }
}
macierz *zaladujZBinarnego(char nazwaPliku[], char nazwaMacierzy[])
{
    macierz *wgrywana;
    int i = 0;
    int liczbaKolumn;
    int liczbaWierszy;
    FILE *fb;
    if ((fb = fopen(nazwaPliku, "rb")) != NULL)
    {
        fread(&liczbaKolumn, sizeof(int), 1, fb);
        fread(&liczbaWierszy, sizeof(int), 1, fb);
        wgrywana = dodajMacierz(liczbaWierszy, liczbaKolumn, nazwaMacierzy);
        fread(wgrywana->zawartosc, sizeof(float), liczbaWierszy * liczbaKolumn, fb);
        fclose(fb);
    }
    return wgrywana;
}
void main()
{
    //--------DEKLARACJA ZMIENNYCH FUNKCJI MAIN--------
    Lista *pierwszyElement = NULL;
    int c = 0;
    char komenda[MAX_KOMENDA];
    char slowo[8][MAX_SLOWO];
    int i = 0;
    while (1)
    {
        printf("Nowa petla!\n");
        //--------POBIERANIE KOMENDY-----------------------
        memset(komenda, ' ', MAX_KOMENDA * sizeof(char));
        for (int o = 0; o < 8; o++)
        {
            memset(slowo[o], ' ', MAX_SLOWO * sizeof(char));
        }
        c = 0;
        i = 0;
        while (c != '\n')
        {
            c = getchar();
            komenda[i++] = c;
        }
        strcpy(strchr(komenda, '\n'), " ");
        komenda[i++] = ' ';
        i = 0;
        char *token = strtok(komenda, " ");
        while (token != NULL)
        {
            strcpy(slowo[i++], token);
            token = strtok(NULL, " ");
        }
        i = 0;
        //---------OPCJE MENU-------------------------------
        if (strcmp(slowo[0], "Run") == 0) // Wygenerowanie instrukcji obslugi
        {
            wygenerujSkrypt(slowo[1]);
        }
        if (strcmp(slowo[0], "Random") == 0)
        {
            sprawdzNazwe(slowo[1], pierwszyElement);
            macierz *m1 = losujMacierz(slowo[1]);
            pierwszyElement = macierzDoListy(m1, pierwszyElement);
            wyswietlNaEkranie(m1);
            continue;
        }
        if (strcmp(slowo[0], "Print") == 0)
        {
            macierz *m1 = znajdzMacierz(slowo[1], pierwszyElement);
            wyswietlNaEkranie(m1); //ta funkcja jeszcze nie istnieje !!!!!!!!!!DO NAPISANIA!!!!!!!!!!!!
                                   //slowo[1] - nazwa macierzy
                                   /*Wypisanie macierzy na ekranie poleceniem Print nazwa_macierzy (można wprowadzić ograniczenie
           rozmiarów macierzy, żeby zmieściła się na ekranie) */
        }
        if (strcmp(slowo[0], "Exit") == 0)
        {
            exit(0);
        }
        if (strcmp(slowo[3], "#") == 0)
        {
            sprawdzNazwe(slowo[0], pierwszyElement);
            macierz *m1 = znajdzMacierz(slowo[2], pierwszyElement);
            macierz *m2 = znajdzMacierz(slowo[4], pierwszyElement);
            macierz *m3 = polaczeniePoziome(m1, m2, slowo[0]);
            pierwszyElement = macierzDoListy(m3, pierwszyElement);
            continue;
        }
        if (strcmp(slowo[3], "*") == 0)
        {
            sprawdzNazwe(slowo[0], pierwszyElement);
            macierz *m1 = znajdzMacierz(slowo[2], pierwszyElement);
            macierz *m2 = znajdzMacierz(slowo[4], pierwszyElement);
            macierz *m3 = iloczynMacierzy(m1, m2, slowo[0]);
            pierwszyElement = macierzDoListy(m3, pierwszyElement);
            continue;
            //slowo[0] - nazwa macierzy nowej
            //slowo[2] - nazwa macierzy 1
            //slowo[4] - nazwa macierzy 2
        }
        if (strcmp(slowo[3], "-") == 0)
        {
            sprawdzNazwe(slowo[0], pierwszyElement);
            macierz *m1 = znajdzMacierz(slowo[2], pierwszyElement);
            macierz *m2 = znajdzMacierz(slowo[4], pierwszyElement);
            macierz *m3 = roznicaMacierzy(m1, m2, slowo[0]); //slowo[0] - nazwa macierzy nowej
            pierwszyElement = macierzDoListy(m3, pierwszyElement);
            continue; //slowo[2] - nazwa macierzy 1
                      //slowo[4] - nazwa macierzy 2
        }
        if (strcmp(slowo[0], "Delete") == 0)
        {
            pierwszyElement = usunMacierz(pierwszyElement, slowo[1]);
            //slowo[1] - nazwa macierzy
            /*Skasowanie macierzy poleceniem Delete nazwa_macierzy*/
        }
        if (strcmp(slowo[0], "Save") == 0)
        {
            macierz *m1 = znajdzMacierz(slowo[1], pierwszyElement);
            zapiszBin(slowo[3], m1); //slowo[1] - nazwa macierzy
            continue;
            //slowo[3] - nazwa pliku
            // Zapis macierzy do pliku binarnego poleceniem Save nazwa_macierzy > nazwa_pliku
        }

        if (strcmp(slowo[0], "Load") == 0)
        {
            sprawdzNazwe(slowo[3], pierwszyElement); //pamietac o ogranizeniu nazwy macierz;y!

            macierz *m1 = zaladujZBinarnego(slowo[1], slowo[3]);
            pierwszyElement = macierzDoListy(m1, pierwszyElement);
            //slowo[1] - nazwa pliku
            //slowo[3] - nazwa macierzy
            /* Załadowanie  macierzy  z  pliku  binarnego  poleceniem  Load  nazwa_pliku  >  nazwa_macierzy.
        ”nazwa_macierzy”  jest  łańcuchem  znaków  identyfikującym  daną  macierz.  W  systemie  nie  mogą
        istnieć dwie macierze o takich samych nazwach. Nazwa macierzy musi zaczynać się od małej litery. */
        }
    }
}