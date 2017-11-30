//Sławomir Kalandyk

#include <stdio.h>

double celsToFahr(double cels);
double fahrToCels(double fahr);

int main(void)
{
	int wybor;
	double temperatura;
	printf("Podaj temperaturę:\n");
	scanf("%lf", &temperatura);
	printf("Konwersja Celsjusz -> Fahrenheit wciśnij 1, Fahrenheit -> Celsjusz wciśnij 2:\n");
	scanf("%d", &wybor);

	switch(wybor)
	{
		case 1:
		printf("Podana temperatura w stopniach Fahrenheita to: %lf\n", celsToFahr(temperatura));
		break;
		
		case 2:
		printf("Podana temperatura w stopniach Celsjusza to: %lf\n", fahrToCels(temperatura));
		break;
	}

	return 0;
}

double celsToFahr(double cels)
{
	double fahr = 32 + (9 * cels) / 5;
	return fahr;
}

double fahrToCels(double fahr)
{
	double cels = (5 * (fahr - 32)) / 9;
	return cels;
}
