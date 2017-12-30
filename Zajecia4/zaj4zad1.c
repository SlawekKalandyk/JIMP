//Sławomir Kalandyk
//Program musi zostać skompilowany z flagą -lm, np. gcc zaj4zad1.c -lm -Wall -Wextra -pedantic

#include <stdio.h>
#include <math.h>

double liczDelte(double a, double b, double c);
double liczPierwiastek1(double a, double b, double delta);
double liczPierwiastek2(double a, double b, double delta);

int main(void)
{
	double wspolczynnik1 = 0, wspolczynnik2 = 0, wspolczynnik3 = 0;
	printf("Wprowadź wspolczynniki równania kwadratowego:\n");

	do
	{
            scanf("%lf %lf %lf", &wspolczynnik1, &wspolczynnik2, &wspolczynnik3);

            if(wspolczynnik1)
                break;
            else
            	printf("Podane równanie nie jest równaniem kwadratowym, współczynnik a musi być różny od 0.\nWprowadź współczynniki ponownie:\n");
	}
	while(1);

	double delta = liczDelte(wspolczynnik1, wspolczynnik2, wspolczynnik3);

	if(delta > 0)
		printf("Delta większa od 0, rozwiązaniami równania kwadratowego są %lf i %lf\n",
			liczPierwiastek1(wspolczynnik1, wspolczynnik2, delta), liczPierwiastek2(wspolczynnik1, wspolczynnik2, delta));
	else if(delta == 0)
		printf("Delta równa 0, rozwiązaniem równania kwadratowego jest %lf\n", liczPierwiastek1(wspolczynnik1, wspolczynnik2, delta));
	else
		printf("Delta mniejsza od 0, brak rozwiązań równania kwadratowego\n");

	return 0;
}

double liczDelte(double a, double b, double c)
{
	return b * b - 4 * a * c;
}

double liczPierwiastek1(double a, double b, double delta)
{
	return (-b + sqrt(delta)) / (2 * a);
}

double liczPierwiastek2(double a, double b, double delta)
{
	return (-b - sqrt(delta)) / (2 * a);
}
