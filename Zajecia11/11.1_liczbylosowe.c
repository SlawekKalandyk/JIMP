// Sławomir Kalandyk
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void losowanie(int iloscLiczb, FILE *plik);

int main(int argc, char **argv)
{
    srand(time(NULL));
    FILE *plik;

    if(argc < 2)
    {
        printf("Nie podałeś argumentów podczas uruchamiania programu\n");
        return 0;
    }
    else if(argc < 3)
    {  
        printf("Podałes tylko 1 argument podczas uruchamiania programu\n");
        return 0;
    }

    plik = fopen(argv[2], "a");
    losowanie(atoi(argv[1]), plik);

    fclose(plik);

    return 0;
}

void losowanie(int iloscLiczb, FILE *plik)
{
    for(int i = 0; i < iloscLiczb; i++)
        fprintf(plik, "%d\n", rand() % 1001);
}