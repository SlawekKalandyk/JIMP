#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <errno.h>

void wprowadzenieLiczb(double *tab, int *iloscLiczb);
void sortowanieTablicy(double *tab, int iloscLiczb);
void wyswietlenieTablicy(double *tab, int iloscLiczb);
void wyswietlenieWynikow(double suma, double srednia, double mediana);
int sprawdzenieIlosciElementowTablicy(int iloscLiczb);
double suma(double *tab, int iloscLiczb);
double dominanta(double *tab, int iloscLiczb);
double srednia(int iloscLiczb, double suma);
double mediana(double *tab, int iloscLiczb);

int main(void)
{
    double *tab;
    int iloscLiczb = 0;
    double sumaLiczb = 0;
    double sredniaLiczb = 0;
    double medianaLiczb = 0;

    printf("Podaj ilosc liczb:\n");
    scanf("%d", &iloscLiczb);
    tab = (double*)malloc(sizeof *tab * iloscLiczb);

    if(sprawdzenieIlosciElementowTablicy(iloscLiczb) == 0)
        return 0;
    
    wprowadzenieLiczb(tab, &iloscLiczb);

    if(iloscLiczb == 0)
    {   
        printf("Nie wprowadziłeś żadnej liczby\n");
        return 0;
    }
    
    sortowanieTablicy(tab, iloscLiczb);
    sumaLiczb = suma(tab, iloscLiczb);
    sredniaLiczb = srednia(iloscLiczb, sumaLiczb);
    medianaLiczb = mediana(tab, iloscLiczb);
    wyswietlenieWynikow(sumaLiczb, sredniaLiczb, medianaLiczb);

    free(tab);

    return 0;
}

void wprowadzenieLiczb(double *tab, int *iloscLiczb)
{
    int i = 0;
    int koniecPetli = *iloscLiczb;

    *iloscLiczb = 0;
    printf("Wprowadź liczby:\n");

    while(scanf("%lf", &tab[i]) != EOF && i < koniecPetli - 1)
    {
        *iloscLiczb = i + 1;
        i++;
    }

    if(*iloscLiczb == koniecPetli - 1)
        *iloscLiczb += 1;
}

void sortowanieTablicy(double *tab, int iloscLiczb)
{
    double a = 0;

    for(int i = 0; i < iloscLiczb - 1; i++)
    {
        for(int n = 0; n < iloscLiczb - i - 1; n++)
        {
            if(tab[n] > tab[n + 1])
            {
                a = tab[n];
                tab[n] = tab[n + 1];
                tab[n + 1] = a;
            }
        }
    }
}

void wyswietlenieTablicy(double *tab, int iloscLiczb)
{
    for(int i = 0; i < iloscLiczb; i++)
        printf("tab[%d] = %lf\n", i, tab[i]);
}

void wyswietlenieWynikow(double suma, double srednia, double mediana)
{
    int sumaInt = suma + 1e-9;
    int sredniaInt = srednia + 1e-9;
    int medianaInt = mediana + 1e-9;

    if(suma - sumaInt != 0)
        printf("%lf\n", suma);
    else
        printf("%d %o %0X\n", sumaInt, sumaInt, sumaInt);

    if(srednia - sredniaInt != 0)
        printf("%lf\n", srednia);
    else
        printf("%d %o %0X\n", sredniaInt, sredniaInt, sredniaInt);

    if(mediana - sredniaInt != 0)
        printf("%lf\n", mediana);
    else
        printf("%d %o %0X\n", medianaInt, medianaInt, medianaInt);

}

int sprawdzenieIlosciElementowTablicy(int iloscLiczb)
{
    if(errno != 0)
    {
        printf("Ilośc liczb nie mieści sie w pamięci\n");
        return 0;
    }
    else if(iloscLiczb < 1)
    {
        printf("Ilośc liczb, które chcesz wprowadzić musi być większa od 0\n");
        return 0;
    }

    return 1;
}

double suma(double *tab, int iloscLiczb)
{
    double suma = 0;

    for(int i = 0; i < iloscLiczb; i++)
        suma += tab[i];

    return suma;
}

double dominanta(double *tab, int iloscLiczb)
{
    int licznik[iloscLiczb];

    for(int i = 0, j = 0; i < iloscLiczb; i++)
    {
    
    }

}

double srednia(int iloscLiczb, double suma)
{
    return suma / iloscLiczb;
}

double mediana(double *tab, int iloscLiczb)
{
    if(iloscLiczb % 2 == 1)
        return tab[iloscLiczb / 2];
    else
        return (tab[iloscLiczb / 2 - 1] + tab[iloscLiczb / 2]) / 2;
}