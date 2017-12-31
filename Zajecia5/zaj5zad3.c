//Sławomir Kalandyk

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void losowanieElementowMacierzy(int wymiar, int macierz[2][2]);
void polaczMacierze2d(int macierz3d[2][2][2], int macierz2d1[2][2], int macierz2d2[2][2]);
void mnozenieMacierzy2x2(int macierz[2][2][2]);

int main(void)
{
	srand(time(NULL));
	int wymiarMacierzy = 2;
	int macierz3d[2][wymiarMacierzy][wymiarMacierzy];
	int macierz2d1[wymiarMacierzy][wymiarMacierzy];
	int macierz2d2[wymiarMacierzy][wymiarMacierzy];

	losowanieElementowMacierzy(wymiarMacierzy, macierz2d1);
	losowanieElementowMacierzy(wymiarMacierzy, macierz2d2);
	polaczMacierze2d(macierz3d, macierz2d1, macierz2d2);
	mnozenieMacierzy2x2(macierz3d);

	return 0;
}

void losowanieElementowMacierzy(int wymiar, int macierz[wymiar][wymiar])
{
	for(int i = 0; i < wymiar; i++)
	{
		for(int j = 0; j < wymiar; j++)
			macierz[i][j] = rand() % 201 - 100;
	}
}

void polaczMacierze2d(int macierz3d[2][2][2], int macierz2d1[2][2], int macierz2d2[2][2])
{
	for(int i = 0; i < 2; i++)
	{
		for(int j = 0; j < 2; j++)
		{
			macierz3d[0][i][j] = macierz2d1[i][j];
			macierz3d[1][i][j] = macierz2d2[i][j];
		}
	}
}

void mnozenieMacierzy2x2(int macierz[2][2][2])
{
	int wynikMnozenia[2][2];

	for(int i = 0; i < 2; i++)
	{
		for(int j = 0; j < 2; j++)
		{	
			wynikMnozenia[i][j] = macierz[0][i][0] * macierz[1][0][j] + macierz[0][i][1] * macierz[1][1][j];
			printf("wynikMnozenia[%d][%d] = %d\n", i, j, wynikMnozenia[i][j]);
		}
	}
}

