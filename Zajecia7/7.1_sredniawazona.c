//Sławomir Kalandyk
//Program losuje liczby od 1 do 10 i liczy z nich średnią ważoną
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void losowanieTablicy(int dlugoscTablicy, int tab[dlugoscTablicy]);
void wyswietlenieTablicy(int dlugoscTablicy, int tab[dlugoscTablicy]);
double srednia(int *poczatek, int *koniec);

int main(void)
{
    srand(time(NULL));
    int dlugoscTablicy = 0;
    printf("Podaj długość tablicy:\n");
    scanf("%d", &dlugoscTablicy);
    int tab[dlugoscTablicy];

    losowanieTablicy(dlugoscTablicy, tab);
    wyswietlenieTablicy(dlugoscTablicy, tab);
    printf("Srednia ważona wynosi %lf\n", srednia(&tab[0], &tab[dlugoscTablicy - 1]));

    return 0;
}

void losowanieTablicy(int dlugoscTablicy, int tab[dlugoscTablicy])
{
    for(int i = 0; i < dlugoscTablicy; i++)
        tab[i] = rand() % 10 + 1;
}

void wyswietlenieTablicy(int dlugoscTablicy, int tab[dlugoscTablicy])
{
    for(int i = 0; i < dlugoscTablicy; i++)
        printf("tab[%d] = %d\n", i, tab[i]);
}

double srednia(int *poczatek, int *koniec)
{
    double dzielnik = 0;
    double suma = 0;
    int waga = 0;

    for(int *i = poczatek; i <= koniec; i += 1)
    {
        dzielnik += waga;
        suma += *i * waga;
        waga++;
    }

    return suma / dzielnik;
}