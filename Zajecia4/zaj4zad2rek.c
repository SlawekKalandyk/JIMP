//Sławomir Kalandyk
//Program musi zostać skompilowany z flagą -lm, np. gcc zaj4zad2.c -lm -Wall -Wextra -pedantic
//Jest to wersja rekurencyjna, przesyłam ją tylko do wglądu bo działa dobrze lecz ilość kroków jest błędna
//Odnośnie podpunktu 3., w przedziale [1,10] maksymalną liczba kroków jest 3 *** poprawić bo wychodzi 4 

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

void szukanie(int liczba, int licznik, double poczatekZakresu, double koniecZakresu);
int losowanie();

int main(void)
{
	srand(time(NULL));
	int podanaLiczba;
	int licznikKrokow = 0;
	int poczatek = 1;
	int koniec = 10;
	printf("Podaj liczbę całkowitą z zakresu [1,10]:\n");
	scanf("%d", &podanaLiczba);

	if(podanaLiczba < 1 || podanaLiczba > 10)
	{
		printf("Podałeś liczbę z poza zakresu.\nZostanie wylosowana liczba z przedziału [1,10]\n");
		podanaLiczba = losowanie();
	}
	szukanie(podanaLiczba, licznikKrokow, poczatek - 1, koniec);

	return 0;
}

void szukanie(int liczba, int licznik, double poczatekZakresu, double koniecZakresu)
{
	licznik += 1;
	double srednia = ceil((koniecZakresu + poczatekZakresu) / 2);
	double zmienna = poczatekZakresu + ceil((koniecZakresu - poczatekZakresu) / 2);

	if(srednia == liczba)
		printf("Podana liczba to %lf\nIlość kroków to %d\n", srednia, licznik);
	else if(liczba > zmienna)
	{
		poczatekZakresu = zmienna;
		szukanie(liczba, licznik, poczatekZakresu, koniecZakresu);
	}
	else
	{
		koniecZakresu = zmienna;
		szukanie(liczba, licznik, poczatekZakresu, koniecZakresu);
	}
}

int losowanie()
{
	int tmp = rand() % 10 + 1;
	return tmp;	
}
