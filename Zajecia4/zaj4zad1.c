//Sławomir Kalandyk
//Program musi zostać skompilowany z flagą -lm, np. gcc zaj1zad4.c -lm -Wall -Wextra -pedantic

#include <stdio.h>
#include <math.h>

double liczDelte(double a, double b, double c)
{
	return b * b - 4 * a * c;
}

double pierwiastek1(double a, double b, double delta)
{
	return (-b + sqrt(delta)) / (2 * a);
}

double pierwiastek2(double a, double b, double delta)
{
	return (-b - sqrt(delta)) / (2 * a);
}

int main(void)
{
	double wspolczynnik1, wspolczynnik2, wspolczynnik3;
	printf("Wprowadź wspolczynniki równania kwadratowego:\n");
	scanf("%lf %lf %lf", &wspolczynnik1, &wspolczynnik2, &wspolczynnik3);
	double delta = liczDelte(wspolczynnik1, wspolczynnik2, wspolczynnik3);

	if(delta > 0)
		printf("Delta większa od 0, rozwiązaniami równania są %lf i %lf\n",
		 pierwiastek1(wspolczynnik1, wspolczynnik2, delta), pierwiastek2(wspolczynnik1, wspolczynnik2, delta));
	else if(delta == 0)
		printf("Delta równa 0, rozwiązaniem jest %lf\n", pierwiastek1(wspolczynnik1, wspolczynnik2, delta));
	else
		printf("Delta mniejsza od 0, brak rozwiązań równania\n");

	return 0;
}
