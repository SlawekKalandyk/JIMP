//Sławomir Kalandyk
//Występuje błąd numeryczny przy obliczaniu średniej, nie wiem jak się go pozbyć
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void losowanieTablicy(int rozmiarTablicy, float tab[rozmiarTablicy]);
void wyswietlenieTablicy(int rozmiarTablicy, float tab[rozmiarTablicy]);
void srednia(int rozmiarTablicy, float tab[rozmiarTablicy]);
void mediana(int rozmiarTablicy, float tmp[rozmiarTablicy]);
void minmax(int rozmiarTablicy, float tmp[rozmiarTablicy]);
void sortowanie(int rozmiarTablicy, float tab[rozmiarTablicy], float tmp[rozmiarTablicy]);

int main(void)
{
    srand(time(NULL));
    int wybor = 0;
    int rozmiarTablicy = 10;
    float tab[rozmiarTablicy];
    float tmp[rozmiarTablicy];

    printf("1. Losowanie tablicy %d liczb\n"
    "2. Wyświetlanie jej\n"
    "3. Liczenie średniej liczb\n"
    "4. Liczenie mediany liczb\n"
    "5. Maksymalny/minimalny element tablicy\n"
    "6. Wyjście\n", rozmiarTablicy);
    
    while(wybor != 6)
    {  
        printf("Wybierz opcję:\n");
        scanf("%d", &wybor);
        switch(wybor)
        {
            case 1:
                losowanieTablicy(rozmiarTablicy, tab);
                sortowanie(rozmiarTablicy, tab, tmp);
            break;

            case 2:
                wyswietlenieTablicy(rozmiarTablicy, tab);
            break;
            
            case 3:
                srednia(rozmiarTablicy, tab);
            break;

            case 4:
                mediana(rozmiarTablicy, tmp);
            break;

            case 5:
                minmax(rozmiarTablicy, tmp);
            break;

            case 6:
            break;

            default:
                printf("Podałeś błędną opcję\n");
            break;
        }
    }
    return 0;
}

void losowanieTablicy(int rozmiarTablicy, float tab[rozmiarTablicy])
{
    for(int i = 0; i < rozmiarTablicy; i++)
        tab[i] = rand() % 100;
}

void wyswietlenieTablicy(int rozmiarTablicy, float tab[rozmiarTablicy])
{
    for(int i = 0; i < rozmiarTablicy; i++)
        printf("tab[%d] = %f\n", i, tab[i]);
}

void srednia(int rozmiarTablicy, float tab[rozmiarTablicy])
{
    float srednia = 0;

    for(int i = 0; i < rozmiarTablicy; i++)
        srednia += tab[i];

    srednia /= rozmiarTablicy;
    printf("Średnia wynosi: %f\n", srednia);
}

void mediana(int rozmiarTablicy, float tmp[rozmiarTablicy])
{
    float mediana = 0;

    if(rozmiarTablicy % 2 == 1)
        mediana = tmp[rozmiarTablicy / 2];
    else
        mediana = (tmp[rozmiarTablicy / 2 - 1] + tmp[rozmiarTablicy / 2]) / 2;

    printf("Mediana wynosi: %f\n", mediana);
}

void minmax(int rozmiarTablicy, float tmp[rozmiarTablicy])
{
    printf("Minimalny element tablicy to: %f\nMaksymalny element tablicy to: %f\n", tmp[0], tmp[rozmiarTablicy - 1]);
}

void sortowanie(int rozmiarTablicy, float tab[rozmiarTablicy], float tmp[rozmiarTablicy])
{
    float a = 0;
    for(int i = 0; i < rozmiarTablicy; i++)
        tmp[i] = tab[i];

    for(int j = 0; j < rozmiarTablicy - 1; j++)
    {
        for(int n = 0; n < rozmiarTablicy - 1 - j; n++)
        {
            if(tmp[n] > tmp[n + 1])
            {
                a = tmp[n];
                tmp[n] = tmp[n + 1];
                tmp[n + 1] = a;
            }
        }
    }
    
}