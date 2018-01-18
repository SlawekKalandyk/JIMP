//Sławomir Kalandyk
//Nie potrafię usunąc newline'a przy scanfie, przez co przy każdym wczytaniu liczby 
//program przechodzi do nowej linii.
//Nie zastosowałem też ..., ponieważ nie znalazłem sposobu na przypisanie wartości 
//do argumentów z listy i po wielu próbach zostawiłem to i wybrałem prostszą dla mnie metodę rozwiązania.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void printLine(char *napis, int *tab, int *rozmiarTab);

int main(void)
{
    char *tekst = "Podaj pierwszy bok trójkąta: %dPodaj drugi bok trójkąta: %dPodaj trzeci bok trójkąta: %d";
    int *tab = NULL;
    int rozmiarTab = 0;
    
    tab = (int*)malloc(rozmiarTab * sizeof(tab[0]));
    printLine(tekst, tab, &rozmiarTab);
    
    free(tab);

    return 0;
}

void printLine(char *napis, int *tab, int *rozmiarTab)
{
    int licznikZnakow = 0;
    int index = 0;
    int *check = 0;

    for(unsigned int i = 0; i < strlen(napis) - 1; i++)
    {
        if(napis[i] == '%' && napis[i + 1] == 'd')
        {
            for(unsigned int j = licznikZnakow; j < i; j++)
                printf("%c", napis[j]);

            scanf("%d", &tab[index]);
            index += 1;
            *rozmiarTab += 1;
            licznikZnakow = i + 2;
            check = realloc(tab, *rozmiarTab * sizeof(tab[0]));

            if(!check)
            {
                free(tab);
                printf("Wystąpił błąd w zwiększaniu rozmiaru tablicy zmiennych\n");
            }
        }
    }

    for(unsigned int j = licznikZnakow; j < strlen(napis); j++)
        printf("%c", napis[j]);
}