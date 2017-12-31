//Sławomir Kalandyk

#include <stdio.h>
#include <string.h>

int porownanieGodzinyzAscii(int rozmiarStringa, char strGodzina[rozmiarStringa]);
int format24Godzinny(int rozmiarTablicy, int godzina[rozmiarTablicy]);
int porownanieGodzin(int rozmiarTablicy, int godzina1[rozmiarTablicy], int godzina2[rozmiarTablicy]);

int main(void)
{
	int wartoscPorownania = 0;
	int dlugoscGodzinaTab = 3;
	int dlugoscGodzinaString = 8;
	int godzina1[dlugoscGodzinaTab], godzina2[dlugoscGodzinaTab];
	char strGodzina1[dlugoscGodzinaString], strGodzina2[dlugoscGodzinaString];

	printf("Podaj pierwszą godzinę w formacie hh:mm:ss\n");
	scanf("%s", strGodzina1);
	sscanf(strGodzina1, "%d:%d:%d", &godzina1[0], &godzina1[1], &godzina1[2]);
	printf("Podaj drugą godzinę w formacie hh:mm:ss\n");
	scanf("%s", strGodzina2);
	sscanf(strGodzina2, "%d:%d:%d", &godzina2[0], &godzina2[1], &godzina2[2]);

	if(porownanieGodzinyzAscii(dlugoscGodzinaString, strGodzina1) //dla czytelności 4 linijki
	&& porownanieGodzinyzAscii(dlugoscGodzinaString, strGodzina2)
	&& format24Godzinny(dlugoscGodzinaTab, godzina1)
	&& format24Godzinny(dlugoscGodzinaTab, godzina2))
	{
		wartoscPorownania = porownanieGodzin(dlugoscGodzinaTab, godzina1, godzina2);
		
		if(wartoscPorownania == 1)
			printf("Godzina pierwsza jest późniejsza niż godzina druga\n");
		else if(wartoscPorownania == -1)
			printf("Godzina druga jest późniejsza niż godzina pierwsza\n");
		else
			printf("Podane godziny są sobie równe\n");
	}
	else
		printf("Podałeś błędną godzinę\n");

	return 0;
}

int porownanieGodzinyzAscii(int rozmiarStringa, char strGodzina[rozmiarStringa])
{
	int licznik = 0;

	for(int i = 0; i < rozmiarStringa; i++)
	{
		if(i % 3 == 2)
		{
			if(strGodzina[i] == 58)
				licznik += 1;
		}
		else
		{
			if(strGodzina[i] >= 48 && strGodzina[i] <= 57)
				licznik += 1;
		}
	}
	if(licznik == rozmiarStringa)
		return 1;
	else
		return 0;
}

int format24Godzinny(int rozmiarTablicy, int godzina[rozmiarTablicy])
{
	if(godzina[0] >= 0 && godzina[0] <= 23 && godzina[1] >= 0 && godzina[1] <= 60 && godzina[2] >= 0 && godzina[2] <= 60)
		return 1;
	else
		return 0;
}

int porownanieGodzin(int rozmiarTablicy, int godzina1[rozmiarTablicy], int godzina2[rozmiarTablicy])
{
	for(int i = 0; i < rozmiarTablicy; i++)
	{
		if(godzina1[i] > godzina2[i])
			return 1;
		else if(godzina1[i] < godzina2[i])
			return -1;
	}
	
	return 0;
}