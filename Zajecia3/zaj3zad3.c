//Sławomir Kalandyk

#include <stdio.h>
#include <math.h>

double deeToRad(double dee)
{
	double rad = (dee * M_PI) / 180;
	return rad;
}

double radToDee(double rad)
{
	double dee = rad * (180 / M_PI);
	return dee;
}

int main(void)
{
	int wybor;
	double kat;
	printf("Podaj wymiar kąta:\n");
	scanf("%lf", &kat);
	printf("Konwersja stopnie -> radiany wciśnij 1, radiany -> stopnie wciśnij 2:\n");
	scanf("%d", &wybor);
	
	switch(wybor)
	{
		case 1:
		printf("Podany kąt w radianach to %lf radianów\n", deeToRad(kat));
		break;

		case 2:
		printf("Podany kąt w stopniach to %lf stopni\n", radToDee(kat));
		break;
	}

	return 0;
}
