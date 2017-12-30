//Sławomir Kalandyk

#include <stdio.h>

double celsjuszNaFahrenheit(double celsjusz);
double fahrenheitNaCelsjusz(double fahrenheit);

int main(void)
{
	int wybor = 0;
	double temperatura = 0;
	printf("Podaj temperaturę:\n");
	scanf("%lf", &temperatura);
	printf("Konwersja Celsjusz -> Fahrenheit wciśnij 1, Fahrenheit -> Celsjusz wciśnij 2:\n");
	scanf("%d", &wybor);

	switch(wybor)
	{
		case 1:
		printf("Podana temperatura w stopniach Fahrenheita to: %lf\n", celsjuszNaFahrenheit(temperatura));
		break;
		
		case 2:
		printf("Podana temperatura w stopniach Celsjusza to: %lf\n", fahrenheitNaCelsjusz(temperatura));
		break;
	}

	return 0;
}

double celsjuszNaFahrenheit(double celsjusz)
{
	double fahrenheit = 32 + (9 * celsjusz) / 5;
	return fahrenheit;
}

double fahrenheitNaCelsjusz(double fahrenheit)
{
	double celsjusz = (5 * (fahrenheit - 32)) / 9;
	return celsjusz;
}
