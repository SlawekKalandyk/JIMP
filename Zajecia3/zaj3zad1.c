//Sławomir Kalandyk
//Program należy skompilować z flagą -lm, np. gcc zaj3zad1.c -lm -Wall -Wextra -pedantic

#include <stdio.h>
#include <math.h>

double obwodKwadratu(double bokKwadratu);
double poleKwadratu(double bokKwadratu);
double obwodProstokata(double bokProstokata1, double bokProstokata2);
double poleProstokata(double bokProstokata1, double bokProstokata2);
double obwodTrojkata(double bokTrojkata1, double bokTrojkata2, double bokTrojkata3);
double poleTrojkata(double bokTrojkata1, double bokTrojkata2, double bokTrojkata3);
double obwodKola(double promien);
double poleKola(double promien);
int sprawdzanieWymiarowWzgledem0(double wymiary[]);

int main(void)
{
	int wybor = 0;
	double wymiary[3] = {1, 1, 1};
	printf("Program wypisze pola i obwody:\n1. Kwadrat\n2. Prostokąt\n3. Trójkąt\n4. Koło\n");
	scanf("%d", &wybor);
	
	switch(wybor)
	{
		case 1:
			printf("Podaj bok kwadratu:\n");
			scanf("%lf", &wymiary[0]);

			if(sprawdzanieWymiarowWzgledem0(wymiary))
				printf("Bok kwadratu nie może być mniejszy lub równy 0\n");
			else
				printf("Pole: %lf\nObwód: %lf\n", poleKwadratu(wymiary[0]), obwodKwadratu(wymiary[0]));
		break;
		
		case 2:
			printf("Podaj boki prostokąta:\n");
			scanf("%lf %lf", &wymiary[0], &wymiary[1]);

			if(sprawdzanieWymiarowWzgledem0(wymiary))
				printf("Bok prostokąta nie może być mniejszy lub równy 0\n");
			else
				printf("Pole: %lf\nObwód: %lf\n", poleProstokata(wymiary[0], wymiary[1]), obwodProstokata(wymiary[0], wymiary[1]));
		break;
		
		case 3:
			printf("Podaj boki trójkąta:\n");
			scanf("%lf %lf %lf", &wymiary[0], &wymiary[1], &wymiary[2]);

			if(sprawdzanieWymiarowWzgledem0(wymiary))
				printf("Bok trójkąta nie może być mniejszy lub równy 0\n");
			else if(wymiary[0] + wymiary[1] > wymiary[2] && wymiary[0] + wymiary[2] > wymiary[1] && wymiary[1] + wymiary[2] > wymiary[0])
				printf("Pole: %lf\nObwód: %lf\n", poleTrojkata(wymiary[0], wymiary[1], wymiary[2]), obwodTrojkata(wymiary[0], wymiary[1], wymiary[2]));
			else
				printf("Podane wymiary nie spełniają warunku powstania trójkąta\n");
		break;

		case 4:
			printf("Podaj promień koła:\n");
			scanf("%lf", &wymiary[0]);

			if(sprawdzanieWymiarowWzgledem0(wymiary))
				printf("Promień koła nie może być mniejszy lub równy 0\n");
			else
				printf("Pole:%lf\nObwód:%lf\n", poleKola(wymiary[0]), obwodKola(wymiary[0]));
		break;

		default:
			printf("Błędna opcja\n");
		break;
	}

	return 0;
}

double obwodKwadratu(double bokKwadratu)
{
	return 4 * bokKwadratu;
}

double poleKwadratu(double bokKwadratu)
{
	return bokKwadratu * bokKwadratu;
}

double obwodProstokata(double bokProstokata1, double bokProstokata2)
{
	return 2 * (bokProstokata1 + bokProstokata2);
}

double poleProstokata(double bokProstokata1, double bokProstokata2)
{
	return bokProstokata1 * bokProstokata2;
}

double obwodTrojkata(double bokTrojkata1, double bokTrojkata2, double bokTrojkata3)
{
	return bokTrojkata1 + bokTrojkata2 + bokTrojkata3;
}

double poleTrojkata(double bokTrojkata1, double bokTrojkata2, double bokTrojkata3)
{
	double polowaObwodu = obwodTrojkata(bokTrojkata1, bokTrojkata2, bokTrojkata3) / 2;
	return sqrt(polowaObwodu * (polowaObwodu - bokTrojkata1) * (polowaObwodu - bokTrojkata2) * (polowaObwodu - bokTrojkata3));
}

double obwodKola(double promien)
{
	return 2 * M_PI * promien;
}
 
double poleKola(double promien)
{
	return M_PI * promien * promien;
}
int sprawdzanieWymiarowWzgledem0(double wymiary[])
{
	for(int i = 0; i < 3; i++)
	{
		if(wymiary[i] <= 0)
			return 1;	
	}

	return 0;
}

