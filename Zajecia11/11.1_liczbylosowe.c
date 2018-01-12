#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void losowanie(int iloscLiczb, FILE *plik);

int main(int argc, char **argv)
{
    srand(time(NULL));
    FILE *plik;

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