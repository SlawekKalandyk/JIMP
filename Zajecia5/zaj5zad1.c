//Sławomir Kalandyk

#include <stdio.h>
#include <string.h>

int porownanieStringAscii(char *str1, char *str2);
int format24Godzinny(int godzina1[], int godzina2[]);
int porownanie(int godzina1[], int godzina2[]);

int main(void)
{
	int wartoscPorownania = 0;
	int godzina1[3] = {0};
	int godzina2[3] = {0};
	char tmp1[8], tmp2[8];

	printf("Podaj pierwszą godzinę w formacie hh:mm:ss\n");
	scanf("%s", tmp1);
	sscanf(tmp1, "%d:%d:%d", &godzina1[0], &godzina1[1], &godzina1[2]);
	printf("Podaj drugą godzinę w formacie hh:mm:ss\n");
	scanf("%s", tmp2);
	sscanf(tmp2, "%d:%d:%d", &godzina2[0], &godzina2[1], &godzina2[2]);

	if(porownanieStringAscii(tmp1, tmp2) == 1 && format24Godzinny(godzina1, godzina2) == 1)
	{
		wartoscPorownania = porownanie(godzina1, godzina2);
		if(wartoscPorownania == 1)
			printf("Godzina pierwsza jest późniejsza niż godzina druga\n");
		else if(wartoscPorownania == (-1))
			printf("Godzina druga jest późniejsza niż godzina pierwsza\n");
		else
			printf("Podane godziny są sobie równe\n");
	}
	else
		printf("Podałeś błędną godzinę\n");

	return 0;
}

int porownanieStringAscii(char *str1, char *str2)
{
	int licznik = 0;

	for(int i = 0; i < 8; i++) //porównywanie stringa z odpowiednimi kodami ascii
	{
		if(i == 2 || i == 5)
		{
			if(str1[i] == 58 && str2[i] == 58)
				licznik += 1;
		}
		else
		{
			if(str1[i] >= 48 && str1[i] <= 57 && str2[i] >= 48 && str2[i] <= 57)
				licznik += 1;
		}
	}
	if(licznik == 8)
		return 1;
	else
		return 0;

}

int format24Godzinny(int godzina1[], int godzina2[])
{
	if(godzina1[0] >= 0 && godzina1[0] <= 23 && godzina1[1] >=0 && godzina1[1] <=60 && godzina1[2] >= 0 && godzina1[2] <=60
	&& godzina2[0] >= 0 && godzina2[0] <= 23 && godzina2[1] >=0 && godzina2[1] <=60 && godzina2[2] >= 0 && godzina2[2] <=60)
		return 1;
	else
		return 0;
}

int porownanie(int godzina1[], int godzina2[])
{
	if(godzina1[0] > godzina2[0])
		return 1;
	else if(godzina1[0] < godzina2[0])
		return (-1);
	else
	{
		if(godzina1[1] > godzina2[1])
			return 1;
		else if(godzina1[1] < godzina2[1])
			return (-1);
		else
		{
			if(godzina1[2] > godzina2[2])
				return 1;
			else if(godzina1[2] < godzina2[2])
				return (-1);
			else
				return 0;
		}
	}
}

