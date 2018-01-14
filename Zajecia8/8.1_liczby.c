//  Sławomir Kalandyk
//  Działa, ale z kodu dominanty nie jestem zbyt dumny
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <errno.h>

void wprowadzenieLiczb(double *tab, int *iloscLiczb);
void sortowanieTablicy(double *tab, int iloscLiczb);
void wyswietlenieTablicy(double *tab, int iloscLiczb);
void wyswietlenieWynikow(double suma, double srednia, double mediana, double dominanta, int kontrola);
int sprawdzenieIlosciElementowTablicy(int iloscLiczb);
double suma(double *tab, int iloscLiczb);
void dominanta(double *tab, int iloscLiczb, double *dominantaLiczb, int *kontrola);
double srednia(int iloscLiczb, double suma);
double mediana(double *tab, int iloscLiczb);

int main(void)
{
    double *tab;
    int kontrola = 1;
    int iloscLiczb = 0;
    double sumaLiczb = 0;
    double sredniaLiczb = 0;
    double medianaLiczb = 0;
    double dominantaLiczb = 0;

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
    dominanta(tab, iloscLiczb, &dominantaLiczb, &kontrola);
    wyswietlenieWynikow(sumaLiczb, sredniaLiczb, medianaLiczb, dominantaLiczb, kontrola);

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

void wyswietlenieWynikow(double suma, double srednia, double mediana, double dominanta, int kontrola)
{
    int sumaInt = suma + 1e-9;
    int sredniaInt = srednia + 1e-9;
    int medianaInt = mediana + 1e-9;
    int dominantaInt = dominanta + 1e-9;

    if(suma - sumaInt != 0)
        printf("%lf\n", suma);
    else
        printf("%d %o %0X\n", sumaInt, sumaInt, sumaInt);

    if(srednia - sredniaInt != 0)
        printf("%lf\n", srednia);
    else
        printf("%d %o %0X\n", sredniaInt, sredniaInt, sredniaInt);

    if(mediana - medianaInt != 0)
        printf("%lf\n", mediana);
    else
        printf("%d %o %0X\n", medianaInt, medianaInt, medianaInt);

    if(kontrola == 0)
        printf("Brak dominanty\n");
    else if(dominanta - dominantaInt != 0)
        printf("%lf\n", dominanta);
    else
        printf("%d %o %0X\n", dominantaInt, dominantaInt, dominantaInt);

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

void dominanta(double *tab, int iloscLiczb, double *dominantaLiczb, int *kontrola)
{
    double dominanta = 0;
    double unikalneLiczby[iloscLiczb];
    int iloscWystapien[iloscLiczb];
    int n = 0;
    int max = 0;
    int licznikKontroli = 0;

    for(int i = 0; i < iloscLiczb; i++)
    {
        unikalneLiczby[i] = 0;
        iloscWystapien[i] = 0;
    }

    for(int i = 0, licznik = 0; i < iloscLiczb; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(tab[i] == unikalneLiczby[j])
            {
                iloscWystapien[j]++;
                licznik++;
            }
        }

        if(licznik == 0)
        {
            unikalneLiczby[n] = tab[i];
            iloscWystapien[n]++;
            n++;
        }
        
        licznik = 0;
    }

    max = iloscWystapien[0];

    for(int i = 1; i < n; i++)
    {
        if(max < iloscWystapien[i])
            max = iloscWystapien[i];
    }
    
    for(int i = 0; i < n; i++)
    {
        if(iloscWystapien[i] == max)
            licznikKontroli++;
    }

    if(licznikKontroli != 1)
        *kontrola = 0;

    dominanta = unikalneLiczby[0]; 

    for(int i = 0; i < n; i++)
    {
        if(iloscWystapien[i] < iloscWystapien[i + 1])
            dominanta = unikalneLiczby[i + 1];
    }

    *dominantaLiczb = dominanta;
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