#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <stdlib.h>
#include <time.h>

#define MAXKOMENDA 5
#define MAXNAZWA 20

int main()
{

    struct macierz
    {
        char nazwamacierzy[MAXNAZWA];
        int cokolwiek;
        char zawartosc[];
    };

    char a[4] = "hej";
    struct macierz *s = malloc(sizeof(*s) + sizeof(char[strlen(a)]));
    strcpy(s->zawartosc, a);
    printf("%s", s->zawartosc);
}