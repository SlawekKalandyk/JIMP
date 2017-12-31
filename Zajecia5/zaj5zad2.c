//Sławomir Kalandyk

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int wyznacznikMacierzy3x3(int macierz[3][3]);
void losowanieElementowMacierzy(int wymiar, int macierz[wymiar][wymiar]);

int main(void)
{
	srand(time(NULL));
	int wymiarMacierzy = 3;
	int macierz[wymiarMacierzy][wymiarMacierzy];

	losowanieElementowMacierzy(wymiarMacierzy, macierz);
	printf("Wyznacznikiem macierzy %dx%d jest %d\n", wymiarMacierzy, wymiarMacierzy, wyznacznikMacierzy3x3(macierz));

	return 0;
}

void losowanieElementowMacierzy(int wymiar, int macierz[wymiar][wymiar])
{
	for(int i = 0; i < wymiar; i++)
	{
		for(int j = 0; j < wymiar; j++)
		{
		macierz[i][j] = rand() % 11;
		printf("macierz[%d][%d] = %d\n", i, j, macierz[i][j]);
		}
	}
}

int wyznacznikMacierzy3x3(int macierz[3][3])
{
	int wyznacznik = (macierz[0][0] * macierz[1][1] * macierz [2][2]) + (macierz[1][0] * macierz[2][1] * macierz[0][2]) + (macierz[2][0] * macierz[0][1] * macierz[1][2])
	- (macierz[1][0] * macierz[0][1] * macierz [2][2]) - (macierz[0][0] * macierz[2][1] * macierz[1][2]) - (macierz[2][0] * macierz[1][1] * macierz[0][2]);

	return wyznacznik;
}
