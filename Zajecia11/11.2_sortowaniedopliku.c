// Sławomir Kalandyk
#include <stdio.h>
#include <stdlib.h>

void tworzenieTablicy(int *tab, FILE *plik);
void sortowanie(int *tab, int iloscLiczb);
void wpisanieDoPliku(int *tab, int iloscLiczb, FILE *plik);
void wyswietleniePosortowanegoPliku(int *tab, int iloscLiczb);
int iloscLiniiWPliku(FILE *plik);

int main(int argc, char **argv)
{
    FILE *plikIn;
    FILE *plikOut;
    int *tab;
    int iloscLiczb;

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
    else if(argc == 3)
    {
        plikIn = fopen(argv[1], "r");

        if(plikIn == NULL)
        {
                printf("Plik który podałeś do odczytu prawdopodobnie nie istnieje\n");
                return 0;
        }
        plikOut = fopen(argv[2], "a");
        iloscLiczb = iloscLiniiWPliku(plikIn);
        tab = (int*) malloc (iloscLiczb * sizeof *tab);
        tworzenieTablicy(tab, plikIn);
        sortowanie(tab, iloscLiczb);
        wpisanieDoPliku(tab, iloscLiczb, plikOut);
        fclose(plikIn);
        fclose(plikOut);
    }
    else
    {
        plikIn = fopen(argv[1], "r");
        iloscLiczb = iloscLiniiWPliku(plikIn);
        tab = (int*) malloc (iloscLiczb * sizeof *tab);
        tworzenieTablicy(tab, plikIn);
        sortowanie(tab, iloscLiczb);
        wyswietleniePosortowanegoPliku(tab, iloscLiczb);
        fclose(plikIn);
    }

    free(tab);

    return 0;
}

void tworzenieTablicy(int *tab, FILE *plik)
{
    char trescLinii[255];
    char c;
    int licznikCyfr = 0;
    int licznikElementowTablicy = 0;

    while(c != EOF)
    {
        c = getc(plik);

        if(c != '\n')
        {
            trescLinii[licznikCyfr] = c;
            licznikCyfr++;
        }
        else
        {
            tab[licznikElementowTablicy] = atoi(trescLinii);
            licznikElementowTablicy++;
            trescLinii[0] = 0;
            licznikCyfr = 0;
        }
    }

    fseek(plik, 0, 0);
}

void sortowanie(int *tab, int iloscLiczb)
{
    int a = 0;

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

void wpisanieDoPliku(int *tab, int iloscLiczb, FILE *plik)
{
    for(int i = 0; i < iloscLiczb; i++)
        fprintf(plik, "%d\n", tab[i]);
}

void wyswietleniePosortowanegoPliku(int *tab, int iloscLiczb)
{
    for(int i = 0; i < iloscLiczb; i++)
        printf("tab[%d] = %d\n", i, tab[i]);
}

int iloscLiniiWPliku(FILE *plik)
{
    int iloscLinii = 0;
    char c;

    while(c != EOF)
    {
        c = getc(plik);

        if(c == '\n')
            iloscLinii++;
    }

    fseek(plik, 0, 0);

    return iloscLinii;
}