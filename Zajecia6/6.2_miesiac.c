//Sławomir Kalandyk
//Nie jestem pewny czy dobrze zinterpretowałem zadanie, moje rozwiązanie pokazuje
//aktualny miesiąc w formacie !!! pon wt śr czw pią sob nie !!! w każdej linijce,
//gdzie x oznacza dni z przeszłego lub kolejnego miesiąca.
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
    time_t liczba_sekund;
    struct tm strukt;
    time(&liczba_sekund);
    localtime_r(&liczba_sekund, &strukt);

    int miesiac = strukt.tm_mon + 1; // od 1 do 12
    int rok = strukt.tm_year + 1900;
    int dzienTygodnia = strukt.tm_wday; // od 0 do 6 niedziela 0, sobota 6
    int dzienMiesiaca = strukt.tm_mday; // od 1 do 31
    int liczbaDni = 0;
    int dniPoprzedniMiesiac = (7 + dzienTygodnia - (dzienMiesiaca % 7 - 1) - 1) % 7;

    if(miesiac == 2)
        if((rok % 4 == 0 && rok % 100 != 0) || rok % 400 == 0)
            liczbaDni = 29;
        else
            liczbaDni = 28;
    else if(miesiac == 4 || miesiac == 6 || miesiac == 9 || miesiac == 11)
        liczbaDni = 30;
    else
        liczbaDni = 31;

    if(dniPoprzedniMiesiac != 0) // x z poprzedniego miesiąca
    {
        for(int i = 0; i < dniPoprzedniMiesiac; i++)
            printf("x ");
    }

    for(int i = 1 + dniPoprzedniMiesiac; i <= liczbaDni + dniPoprzedniMiesiac; i++) // dni 1 - 28/29/30/31
    {
        printf("%d ", i - dniPoprzedniMiesiac);
        if(i % 7 == 0)
            printf("\n");
    }

    if((liczbaDni + dniPoprzedniMiesiac) % 7 != 0) // x z kolejnego miesiąca
    {
        for(int i = 0; i < (7 - liczbaDni % 7 - dniPoprzedniMiesiac); i++)
            printf("x ");
        printf("\n");
    }

    return 0;
}