//Sławomir Kalandyk
//do zrobienia
#include <stdio.h>
#include <stdarg.h>

void printLine(char *napis, ...);

int main(void)
{
    char *n = "Podaj pierwszy bok trójkąta: %d\n\
    Podaj drugi bok trójkąta: %d\n\
    Podaj trzeci bok trójkąta: %d\n";
    printLine(n);

    return 0;
}

void printLine(char *napis, ...)
{
    //double val;
    //va_list vl;
    //va_start(vl, napis);

    //scanf("%d", &val);

    //va_end(vl);
}