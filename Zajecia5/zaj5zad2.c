//Sławomir Kalandyk

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int losowanie()
{
	int tmp = rand() % 11;
	return tmp;
}

void elementyMacierzy(int macierz[3][3])
{
	for(int i = 0; i < 3; i++)
	{
		for(int j = 0; j < 3; j++)
		{
		macierz[i][j] = losowanie();
		printf("macierz[%d][%d] = %d\n", i, j, macierz[i][j]);
		}
	}
}

int wyznacznikMacierzy(int macierz[3][3])
{
	int wyznacznik = (macierz[0][0] * macierz[1][1] * macierz [2][2]) + (macierz[1][0] * macierz[2][1] * macierz[0][2]) + (macierz[2][0] * macierz[0][1] * macierz[1][2])
			- (macierz[1][0] * macierz[0][1] * macierz [2][2]) - (macierz[0][0] * macierz[2][1] * macierz[1][2]) - (macierz[2][0] * macierz[1][1] * macierz[0][2]);
	return wyznacznik;
}

int main(void)
{
	srand(time(NULL));
	int macierz[3][3] = {0};
	elementyMacierzy(macierz);
	printf("Wyznacznikiem macierzy 3x3 jest %d\n", wyznacznikMacierzy(macierz));

	return 0;
}
