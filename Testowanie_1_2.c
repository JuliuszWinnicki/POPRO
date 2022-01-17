#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <stdlib.h>
#include <time.h>

int main ()
{
    #define MAXNAZWA 20;
    #define p_b "M.bin"

    struct macierz
{
    char nazwaMacierzy[MAXNAZWA];
    int liczbaKolumn;
    char zawartosc[];
};

    struct macierz a;

    printf("nazwa /n");
    scanf("%s", a.nazwaMacierzy);
    printf("kolumny /n");
    scanf("%d", a.liczbaKolumn);
    printf("zawartosc /n");
    scanf("%s", a.zawartosc);

    printf("%s, %d, %s/n",a.nazwaMacierzy, a.liczbaKolumn, a.zawartosc);

    FILE* fb;
    if ((fb=fopen({Z KOMENDY}, "wb"))!=NULL);
    {
     printf("Zapisano macierz „%s” do pliku Macierze.bin", a.nazwaMacierzy);

        fwrite(a.nazwaMacierzy, sizeof(a.nazwaMacierzy), 1, fb);
        fwrite(a.liczbaKolumn, sizeof(a.liczbaKolumn), 1, fb);
        fwrite(a.zawartosc, sizeof(a.zawartosc), 1, fb);
    fclose(fb);
    }

    return 0;
}
