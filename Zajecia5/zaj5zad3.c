//Sławomir Kalandyk

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int losowanie();
void elementyMacierzy(int macierz[2][2]);
void dwadNa3d(int macierz3d[2][2][2], int macierz2d1[2][2], int macierz2d2[2][2]);
void mnozenieMacierzy(int macierz[2][2][2]);

int main(void)
{
	srand(time(NULL));
	int macierz3d[2][2][2] = {0};
	int macierz2d1[2][2] = {0};
	int macierz2d2[2][2] = {0};

	elementyMacierzy(macierz2d1);
	elementyMacierzy(macierz2d2);
	dwadNa3d(macierz3d, macierz2d1, macierz2d2);
	mnozenieMacierzy(macierz3d);

	return 0;
}

int losowanie()
{
	int tmp = rand() % 201 - 100;
	return tmp;
}

void elementyMacierzy(int macierz[2][2])
{
	for(int i = 0; i < 2; i++)
	{
		for(int j = 0; j < 2; j++)
			macierz[i][j] = losowanie();
	}
}

void dwadNa3d(int macierz3d[2][2][2], int macierz2d1[2][2], int macierz2d2[2][2])
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

void mnozenieMacierzy(int macierz[2][2][2])
{
	int wynikMnozenia[2][2] = {0};

	for(int i = 0; i < 2; i++)
	{
		for(int j = 0; j < 2; j++)
		{	
			wynikMnozenia[i][j] = macierz[0][i][0] * macierz[1][0][j] + macierz[0][i][1] * macierz[1][1][j];
			printf("wynikMnozenia[%d][%d] = %d\n", i, j, wynikMnozenia[i][j]);
		}
	}
	/*	wynikMnozenia[0][0] = macierz[0][0][0] * macierz[1][0][0] + macierz[0][0][1] * macierz[1][1][0];
		wynikMnozenia[0][1] = macierz[0][0][0] * macierz[1][0][1] + macierz[0][0][1] * macierz[1][1][1];
		wynikMnozenia[1][0] = macierz[0][1][0] * macierz[1][0][0] + macierz[0][1][1] * macierz[1][1][0];
		wynikMnozenia[1][1] = macierz[0][1][0] * macierz[1][0][1] + macierz[0][1][1] * macierz[1][1][1]; */

	
}

