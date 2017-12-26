//Sławomir Kalandyk
//Występuje błąd numeryczny przy obliczaniu średniej, nie wiem jak się go pozbyć
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void losowanieTablicy(float tab[10]);
void wyswietlenieTablicy(float tab[10]);
void srednia(float tab[10]);
void mediana(float tmp[10]);
void minmax(float tmp[10]);
void sortowanie(float tab[10], float tmp[10]);

int main(void)
{
    srand(time(NULL));
    int wybor = 0;
    float tab[10] = {0};
    float tmp[10] = {0};

    printf("1. Losowanie tablicy 10 liczb\n\
2. Wyświetlanie jej\n\
3. Liczenie średniej liczb\n\
4. Liczebnie mediany liczb\n\
5. Maksymalny/minimalny element tablicy\n\
6. Wyjście\n");
    
    while(wybor != 6)
    {  
        printf("Wybierz opcję:\n");
        scanf("%d", &wybor);
        switch(wybor)
        {
            case 1:
                losowanieTablicy(tab);
                sortowanie(tab, tmp);
            break;

            case 2:
                wyswietlenieTablicy(tab);
            break;
            
            case 3:
                srednia(tab);
            break;

            case 4:
                mediana(tmp);
            break;

            case 5:
                minmax(tmp);
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

void losowanieTablicy(float tab[10])
{
    for(int i = 0; i < 10; i++)
        tab[i] = rand() % 100;
}

void wyswietlenieTablicy(float tab[10])
{
    for(int i = 0; i < 10; i++)
        printf("tab[%d] = %f\n", i, tab[i]);
}

void srednia(float tab[10])
{
    float srednia = 0;

    for(int i = 0; i < 10; i++)
        srednia += tab[i];

    srednia /= 10;
    printf("Średnia wynosi: %f\n", srednia);
}

void mediana(float tmp[10])
{
    float mediana = (tmp[4] + tmp[5]) / 2;
    printf("Mediana wynosi: %f\n", mediana);
}

void minmax(float tmp[10])
{
    printf("Minimalny element tablicy to: %f\nMaksymalny element tablicy to: %f\n", tmp[0], tmp[9]);
}

void sortowanie(float tab[10], float tmp[10])
{
    float a = 0;
    for(int i = 0; i < 10; i++)
        tmp[i] = tab[i];

    for(int j = 0; j < 9; j++)
    {
        for(int n = 0; n < 9 - j; n++)
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