//Sławomir Kalandyk

#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <string.h>

void printLine(char *napis, int *tab, int rozmiarTab);

int main(void)
{
    char *tekst = "Podaj pierwszy bok trójkąta: %dPodaj drugi bok trójkąta: %dPodaj trzeci bok trójkąta: %d\n";
    int *tab;
    int poczatkowyRozmiarTab = 1;

    tab = (int*)malloc(poczatkowyRozmiarTab * sizeof(tab[0]));
    printLine(tekst, tab, poczatkowyRozmiarTab);

    free(tab);

    return 0;
}

void printLine(char *napis, int *tab, int rozmiarTab)
{
    int licznik = 0;
    int index = 0;
    int *check = 0;

    for(unsigned int i = 0; i < strlen(napis) - 1; i++)
    {
        if(napis[i] == '%' && napis[i + 1] == 'd')
        {
            for(unsigned int j = licznik; j < i; j++)
                printf("%c", napis[j]);

            scanf("%d", &tab[index]);
            index += 1;
            licznik = i + 2;
            check = realloc(tab, (rozmiarTab + index) * sizeof(tab[0]));

            if(!check)
            {
                free(tab);
                printf("Wystąpił błąd w zwiększaniu rozmiaru tablicy zmiennych\n");
            }
            
        }
    }

    for(unsigned int j = licznik; j < strlen(napis); j++)
        printf("%c", napis[j]);
}