#include <stdio.h>
#include <string.h>

void czyszczenieBufora(void)
{
    char c;
    do
    c = getchar();
    while ( c!='\n' && c!=EOF );
}

void main()
{
    char komenda[70];
    char slowo[8][20];
    int i=0;
    int c=0; 
    while (c!='\n') //wczytwanie komend
        {
            c = getchar();
            komenda[i++] = c;
        }
        komenda[i++]=' ';
    i=0;
    char* token=strtok(komenda, " ");
    while(token!=NULL){
        strcpy(slowo[i++], token);
        token=strtok(NULL, " ");
    }
    strcpy(slowo[i], "STOP");
    printf("1: %s, 2: %s, 3: %s, 4: %s, 5: %s, 6: %s", slowo[0], slowo[1], slowo[2], slowo[3], slowo[4], slowo[5]);
    if(strcmp(slowo[2], "popro")==0)
    {
        printf("sukces\n");
    }
    else printf("zajebiscie\n");
    
}