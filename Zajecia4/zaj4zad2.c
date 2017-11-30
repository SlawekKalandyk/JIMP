//Sławomir Kalandyk

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void printLiczba(int liczba);
int losowanie();

int main(void)
{
	srand(time(NULL));
	int podanaLiczba;
	printf("Podaj liczbę z przedziału [1,10]:\n");
	scanf("%d", &podanaLiczba);

	if(podanaLiczba > 10 || podanaLiczba < 1)
	{
		printf("Liczba którą podałeś leży poza dozwolonym przedziałem.\nZostanie wylosowana liczba z przedziału [1,10]\n");
		podanaLiczba = losowanie();
	}
	if(podanaLiczba > 5)
	{
		if(podanaLiczba > 8)
		{
			if(podanaLiczba > 9)
				printLiczba(10);
			else
				printLiczba(9);
		}
		else if(podanaLiczba < 8)
		{
			if(podanaLiczba > 6)
				printLiczba(7);
			else
				printLiczba(6);
		}
		else
			printLiczba(8);
	}
	else if(podanaLiczba < 5)
	{
		if(podanaLiczba > 3)
			printLiczba(4);
		else if(podanaLiczba < 3)
		{
			if(podanaLiczba > 1)
				printLiczba(2);
			else
				printLiczba(1);
		}
		else
			printLiczba(3);
	}
	else
		printLiczba(5);

	return 0;
}

void printLiczba(int liczba)
{
	printf("Podana liczba to %d\n", liczba);
}

int losowanie()
{
	int tmp = rand() % 10 + 1;
	return tmp;
}
