#include <stdio.h>
#include <stdlib.h>
#include "declarations.h"

int main(void)
{
    int choice = 0;

    printf("Witaj w kalkulatorze macierzy.\n"
            "Działania na jednej macierzy:\n"
            "1. Liczenie wyznacznika\n"
            "2. Transpozycja\n"
            "3. Rozkład LU\n"
            "4. Odwracanie\n"
            "Działania na dwóch macierzach:\n"
            "5. Dodawanie\n"
            "6. Odejmowanie\n"
            "7. Mnożenie\n"
            "8. Wyjdź z programu\n"
            "Wybierz działanie:\n");

    scanf("%d", &choice);

    //while(choice != 8)
    //{
        switch(choice)
        {
            case 1:
            break;

            case 2:

            break;

            case 5:
                addition();
            break;

            case 6:
                subtraction();
            break;

            case 7:
                multiplication();
            break;
            
            case 8:
                return 0;
            break;
        }
    //}

    return 0;
}