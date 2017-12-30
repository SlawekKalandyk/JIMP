//Sławomir Kalandyk

#include <stdio.h>
#include <math.h>

double stopnieNaRadiany(double stopnie);
double radianyNaStopnie(double radiany);

int main(void)
{
	int wybor = 0;
	double kat = 0;
	printf("Podaj wymiar kąta:\n");
	scanf("%lf", &kat);
	printf("Konwersja stopnie -> radiany wciśnij 1, radiany -> stopnie wciśnij 2:\n");
	scanf("%d", &wybor);
	
	switch(wybor)
	{
		case 1:
		printf("Podany kąt w radianach to %lf radianów\n", stopnieNaRadiany(kat));
		break;

		case 2:
		printf("Podany kąt w stopniach to %lf stopni\n", radianyNaStopnie(kat));
		break;
	}

	return 0;
}

double stopnieNaRadiany(double stopnie)
{
	double radiany = (stopnie * M_PI) / 180;
	return radiany;
}

double radianyNaStopnie(double radiany)
{
	double stopnie = radiany * (180 / M_PI);
	return stopnie;
}
