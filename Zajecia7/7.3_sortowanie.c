#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void losowanieTablicy(int iloscLiczb, int tab[iloscLiczb], int *tabWsk[iloscLiczb]);
void sortowanie(int iloscLiczb, int *tab[iloscLiczb]);
void wyswietlenieTablicy(int iloscLiczb, int tab[iloscLiczb]);
void wyswietlenieTablicyWskaznikow(int iloscLiczb, int *tab[iloscLiczb]);

int main(void)
{
    srand(time(NULL));
    int iloscLiczb = 10;
    int A[iloscLiczb];
    int *B[iloscLiczb];

    printf("Nieposortowana:\n");
    losowanieTablicy(iloscLiczb, A, B);
    wyswietlenieTablicy(iloscLiczb, A);
    
    sortowanie(iloscLiczb, B);
    printf("Posortowana:\n");
    wyswietlenieTablicyWskaznikow(iloscLiczb, B);

    return 0;
}

void losowanieTablicy(int iloscLiczb, int tab[iloscLiczb], int *tabWsk[iloscLiczb])
{
    for(int i = 0; i < iloscLiczb; i++)
    {
        tab[i] = rand() % 50 + 1;
        tabWsk[i] = &tab[i];
    }
}

void sortowanie(int iloscLiczb, int *tab[iloscLiczb])
{
    int *a = 0;

    for(int i = 0; i < iloscLiczb - 1; i++)
    {
        for(int n = 0; n < iloscLiczb - 1 - i; n++)
        {
            if(*tab[n] > *tab[n + 1])
            {
                a = tab[n];
                tab[n] = tab[n + 1];
                tab[n + 1] = a;
            }
        }
    }
}

void wyswietlenieTablicy(int iloscLiczb, int tab[iloscLiczb])
{
    for(int i = 0; i < iloscLiczb; i++)
        printf("A[%d] = %d\n", i, tab[i]);
}

void wyswietlenieTablicyWskaznikow(int iloscLiczb, int *tab[iloscLiczb])
{
    for(int i = 0; i < iloscLiczb; i++)
        printf("A[%d] = %d\n", i, *tab[i]);
}