//Sławomir Kalandyk
//Najpierw dzielę 9 kulek na 3 grupy po 3 kulki. 2 grupy ważę na wadze, jeśli ta się przechyli, to grupa będąca niżej zawiera najcięższą kulkę.
//Jeśli nie, to grupa którą pozostawiłem ją zawiera. Powtarzam to samo dla grupy w której ona jest: 2 kulki ważę, 1 zostawiam. Jeśli waga się przechyli,
//to kulka będąca niżej jest najcięższa, a jeśli nie, to ta która odłożyłem na bok jest najcięższa.
//W kodzie najcięższa kulka to ta, dla której wartość jest równa 1.

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int suma(int kulki[], int poczatek, int ilosc);
int waga(int kulki[], int poczatek, int ilosc);

int main(void)
{	
	srand(time(NULL));	
	int najciezsza;
	int losowanieNr = rand() % 9;
	int kulki[9] = {0};
	kulki[losowanieNr] = 1;

	najciezsza = waga(kulki, waga(kulki, 0, 3), 1); //dwa "ważenia" - jedno na podstawie danych z drugiego
	printf("Najcięższa kulka ma nr %d\n", najciezsza);

	printf("Sprawdzenie:\n");
	for(int j = 0; j < 9; j++)
		printf("kulki[%d] = %d\n", j, kulki[j]);

	return 0;
}

int suma(int kulki[], int poczatek, int ilosc)
{
	int grupa = 0;

	for(int i = poczatek; i < poczatek + ilosc; i++)
		grupa += kulki[i];

	return grupa;	
}

int waga(int kulki[], int poczatek, int ilosc)
{
	int grupa1 = suma(kulki, poczatek, ilosc);
	int grupa2 = suma(kulki, poczatek + ilosc, ilosc);

	if(grupa1 > grupa2)
		return poczatek;
	else if(grupa1 < grupa2)
		return poczatek + ilosc;
	else
		return poczatek + 2 * ilosc;
}
