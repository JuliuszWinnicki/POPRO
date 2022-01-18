#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <stdlib.h>
#include <time.h>

#define MAX_KOMENDA 200;
#define MAX_SLOWO 40;
#define MAXNAZWA 20;
#define MAXLICZBASLOW 5;
#define P_B "Macierze.bin"  //P_B - plik binarny, nazwa pliku


typedef struct macierz
{
    char nazwaMacierzy[MAXNAZWA];
    int liczbaKolumn;
    int liczbaWierszy;
    float *zawartosc;
} macierz;


typedef struct Lista
{
    macierz *m;
    Lista *nastepny;
} Lista;



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

void zapiszBin(char nazwaPliku[], macierz* macierz)
{   //funkcja powinna być aktywowana wpisaniem nazwy macierzy i od razu wychwytywać struct o tej nazwie (1. char)
    char slowoPlikuNazwa[5][20];
    char* token = strtok(nazwaPliku, ".");
    while(token!=NULL)
    {
        strcpy(slowoPlikuNazwa[i++], token);
        token=strtok(NULL, " ");
    }
    if(strcmp(slowoPlikuNazwa[i], "bin")!=0)
    {
        strcat(nazwaPliku, ".bin");
    }
    FILE* fb;
    if ((fb=fopen(nazwaPliku, "wb"))!=NULL);
    {
//      Nie wiem czy jest potrzebny taki komunikat, czy nie wykrzaczy się przez dwie komendy wyświetlania takstu)
//      printf("Zapisano macierz „%s” do pliku Macierze.bin", macierz.nazwaMacierzy);
        fwrite(macierz->nazwaMacierzy, sizeof(macierz->nazwaMacierzy), 1, fb);
        fwrite(macierz->liczbaKolumn, sizeof(macierz->liczbaKolumn), 1, fb);
        fwrite(macierz->liczbaWierzy, sizeof(macierz->liczbaWierszy), 1, fb);
        fwrite(macierz->zawartosc, sizeof(macierz->zawartosc), 1, fb);
    fclose(fb);
    }
    else
    {
        fprintf(stdout, "Blad!\n");
    }

macierz* dodajMacierz(int liczbaWierszy, int liczbaKolumn, char nazwaMacierzy[])
{
    macierz* nowaMacierz = malloc(sizeof(char) * MAXNAZWA + sizeof(wskMacierz) + sizeof(int) + sizeof(float) * liczbaWierszy*liczbaKolumn);
    strcpy(nowaMacierz->nazwaMacierzy, nazwaMacierzy);
    nowaMacierz->liczbaWierszy = liczbaWierszy;
    nowaMacierz->liczbaKolumn = liczbaKolumn;
    return nowaMacierz;
}

//----------znajdowanie macierzy w liscie po nazwie------------
macierz* znajdzMacierz(char nazwaMacierzy[], Lista* pierwszy)
{
    Lista* ElListy=pierwszy;
	do {
        if(strcmp((ElListy->m)->nazwaMacierzy, nazwaMacierzy)==0) {
        	return ElListy->m;
        }
        else{
        ElListy = ElListy->nast;
        }
	} while(ElListy != NULL);
	printf("Element z polem o zadanej wartosci nie znajduje sie na liscie\n");
	return pierwszy->m;
}
//--------------------------------------------------------------

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
//-----------------------------------------------------

//--------------------FUNKCJE MATEMATYCZNE-------------------------------
macierz* polaczeniePoziome(macierz* s1, macierz* s2, nazwaNowejMacierzy)
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
        macierz* nowaMacierz = dodajMacierz(s1->liczbaWierszy, nowaLiczbaKolumn, nazwaNowejMacierzy);
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

macierz* roznicaMacierzy (macierz* r1, macierz* r2, nazwaNowejMacierzy[])
{
    if(r1->liczbaWierszy != r2->liczbaWierszy || r1.liczbaKolumn != r2.liczbaKolumn)
    {
        printf("Aby policzyc roznice macierzy obie macierze musza byc tej samej wielkosci\n")
    }
    else
    {
        macierz* nowaMacierz=dodajMacierz(r1->liczbaWierszy, r1->liczbaKolumn, nazwaNowejMacierzy);
        for(int i=0; i<(r1->liczbaWierszy)*(r1->liczbaKolumn); i++)
        {
            nowaMacierz->zawartosc[i]=r1->zawartosc[i]-r2->zawartosc[i];
        }
    }
    return nowaMacierz;
}

macierz* iloczynMacierzy (macierz* r1, macierz* r2, nazwaNowejMacierzy[])
{
    float wynik=0;
    if(r1->liczbaWierszy!=r2->liczbaKolumn || r1->liczbaKolumn!=r2->liczbaWierszy)
    {
        printf("Liczba wierszy jednej macierzy musi byc rowna liczbie kolumn drugiej macierzy i na odwrot\n");
    }
    else
    {
        macierz* nowaMacierz=dodajMacierz(r1->liczbaWierszy, r1->liczbaKolumn, nazwaNowejMacierzy);
        int numerKolumny=0;
        int numerWiersza=0;
        int wynik=0;
        for(numerKolumny=0; numerKolumny<r1->liczbaKolumn; numerKolumny++)
        {
            for(numerWiersza=0; numerWiersza<r1->liczbaWierszy; numerWiersza++)
            {
                for(int i=0; i<r1->liczbaKolumn; i++)
                {
                    wynik=wynik+r1->zawartosc[(r1->liczbaWierszy)*i+numerWiersza]*r2->zawartosc[(r2->liczbaKolumn)*numerKolumny+i];
                }
            }
            nowaMacierz->zawartosc[numerKolumny*(r1->liczbaWierszy)+numerWiersza]=wynik;
            wynik=0;
        }
    }
    return nowaMacierz;
}

//----------------------------------------------------------------------

//------------dodawanie macierzy do listy------------------
Lista* macierzDoListy(macierz* macierz, Lista* elListy)
{
    Lista* nowyElListy= (Lista*)malloc(sizeof(Lista) );
    if(nowyElListy==NULL)
    {
        printf("Blad!\n");
        return NULL;
    }
    else
    {
        nowyElListy->m=macierz;
        nowyElListy->nastepny=elListy;
        return nowyElListy;
    }
}
//-----------------------------------------------------------

//------------usuwanie macierzy--------------------------------
Lista* usunMacierz(WskElListy pierwszy, char nazwaMacierzy[])  {
	WskElListy ElListy=pierwszy, poprzedniElListy=NULL;
	do {
        if(strcmp((ElListy->m)->nazwaMacierzy, nazwaMacierzy)==0) {
        	if(ElListy==pierwszy) pierwszy = ElListy->nast;
        	else poprzedniElListy->nast = ElListy->nast;
            free(ElListy->m);
        	free(ElListy);
        	return pierwszy;
        }
    	poprzedniElListy = ElListy;
        ElListy = ElListy->nast;
	} while(ElListy != NULL);
	printf("Element z polem o zadanej wartosci nie znajduje sie na liscie\n");
	return pierwszy;
}
//--------------------------------------------------------------


int main()
{
    Lista* pierwszyElement = NULL
    int c = 0;
    int i = 0;
    int j = 0;
    char komenda[MAX_KOMENDA];
    char slowo[8][MAX_SLOWO];
    
    //---------------pobieranie komendy-----------------
    while(c!='\n')
    {
        c=getchar();
        komenda[i++]=c;
    }
    komenda[i++]=' ';
    i=0;
    char* token = strtok(komenda, " ");
    while(token!=NULL)
    {
        strcpy(slowo[i++], token);
        token=strtok(NULL, " ");
    }
    //---------------------------------------------------

    //----------------OPCJE MENU-------------------------
    if (strcmp(slowo[0], "Run") == 0) // Instrukcja obslugi
    {
        wygenerujSkrypt(slowo[2]);
    }

    if (strcmp(slowo[0], "Load") == 0)
    {
        zaladujZBinarnego(slowo[1], slowo[3]); //ta funkcja jeszcze nie istnieje    !!!!!!!!!!!!DO NAPISANIA!!!!!!!!!!!
                                               //slowo[1] - nazwa pliku
                                               //slowo[3] - nazwa macierzy
        /* Załadowanie  macierzy  z  pliku  binarnego  poleceniem  Load  nazwa_pliku  >  nazwa_macierzy. 
        ”nazwa_macierzy”  jest  łańcuchem  znaków  identyfikującym  daną  macierz.  W  systemie  nie  mogą 
        istnieć dwie macierze o takich samych nazwach. Nazwa macierzy musi zaczynać się od małej litery. */
    }
    if (strcmp(slowo[0], "Save") == 0)
    {
        macierz* m1=znajdzMacierz(slowo[1], pierwszyElement);
        zapiszBin(slowo[3], m1); //slowo[1] - nazwa macierzy
                                       //slowo[3] - nazwa pliku 
        // Zapis macierzy do pliku binarnego poleceniem Save nazwa_macierzy > nazwa_pliku
    }
    if (strcmp(slowo[0], "Txt") == 0)
    {
        zapiszTxt (slowo[1], slowo[3]); //ta funkcja jeszcze nie istnieje !!!!!!!!!!DO NAPISANIA!!!!!!!!!!!!
                                       //slowo[1] - nazwa macierzy
                                       //slowo[3] - nazwa pliku
        /* Zapis  macierzy  do  pliku  tekstowego  poleceniem  Txt  nazwa_macierzy  >  nazwa_pliku  w  formie 
        czytelnej dla człowieka (można wprowadzić ograniczenie rozmiarów macierzy). */
    }
    if (strcmp(slowo[0], "Print") == 0)
    {
        wyswietlNaEkranie(slowo[1]); //ta funkcja jeszcze nie istnieje !!!!!!!!!!DO NAPISANIA!!!!!!!!!!!!
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
        macierz* m1 = znajdzMacierz(slowo[2], pierwszyElement);
        macierz* m2 = znajdzMacierz(slowo[4], pierwszyElement);
        roznicaMacierzy(m1, m2, slowo[0]); 
                                                       //slowo[0] - nazwa macierzy nowej
                                                       //slowo[2] - nazwa macierzy 1
                                                       //slowo[4] - nazwa macierzy 2
        /*Obliczenie różnicy macierzy: nazwa_macierzy_1 = nazwa_macierzy_2 - nazwa_macierzy_3*/
    }
    if (strcmp(slowo[3], "*") == 0)
    {
        macierz *m1 = znajdzMacierz(slowo[2], pierwszyElement);
        macierz *m2 = znajdzMacierz(slowo[4], pierwszyElement);
        iloczynMacierzy(m1, m2, slowo[0]); //ta funkcja jeszcze nie istnieje !!!!!!!!!!DO NAPISANIA!!!!!!!!!!!!
                                                       //slowo[0] - nazwa macierzy nowej
                                                       //slowo[2] - nazwa macierzy 1
                                                       //slowo[4] - nazwa macierzy 2
        /*Obliczenie iloczynu macierzy: nazwa_macierzy_1 =  nazwa_macierzy_2 * nazwa_macierzy_3*/
    }
    if (strcmp(slowo[3], "#") == 0)
    {
        macierz* m1=znajdzMacierz(slowo[2], pierwszyElement);
        macierz* m2=znajdzMacierz(slowo[4], pierwszyElement);
        polaczeniePoziome(m1, m2, slowo[0]);
        /*Połączenie „poziome” macierzy:  
        nazwa_macierzy_1 = nazwa_macierzy_2 # nazwa_macierzy_3*/
    }
    if (strcmp(slowo[0], "List") == 0)
    {
        wypiszAlfabetycznie(); //funkcja jeszcze nie istenieje !!!!!!!DO NAPISANIA!!!!!!!!!!!!
        /*Wypisanie  na  ekranie  w  kolejności  alfabetycznej  wszystkich  aktualnie  występujących  w  systemie 
        macierzy  wraz z ich wymiarami i rozmiarem w pamięci w bajtach – polecenie List.*/
    }
    //-------------------------------------------
}
