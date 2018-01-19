#include <stdio.h>
#include <stdlib.h>
#include "declarations.h"

#define charArraySize 200

int main(void)
{
    int choice = 0;
    Matrix matrix1, matrix2;
    char data1[charArraySize];
    char data2[charArraySize];

    printf("Witaj w kalkulatorze macierzy.\n"
            "Działania na jednej macierzy:\n"
            "1. Liczenie wyznacznika\n"
            "2. Transpozycja\n"
            "3. \n"
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
                printf("Wybrałeś liczenie wyznacznika\n");
                printf("Wprowadź macierz:\n");
                scanf("%s", data1);
                matrixCreation(data1, &matrix1);
                determinant(matrix1);
            break;

            case 2:
                printf("Wybrałeś transpozycję macierzy\n");
                printf("Wprowadź macierz:\n");
                scanf("%s", data1);
                matrixCreation(data1, &matrix1);
                transposition(&matrix1);
            break;

            case 3:

            break;

            case 5:
                printf("Wybrałeś dodawanie\n");
                printf("Wprowadź pierwszą macierz:\n");
                scanf("%s", data1);
                printf("Wprowadź drugą macierz:\n");
                scanf("%s", data2);
                matrixCreation(data1, &matrix1);
                matrixCreation(data2, &matrix2);
                addition(&matrix1, &matrix2);
            break;

            case 6:
                printf("Wybrałeś odejmowanie\n");
                printf("Wprowadź pierwszą macierz:\n");
                scanf("%s", data1);
                printf("Wprowadź drugą macierz:\n");
                scanf("%s", data2);
                matrixCreation(data1, &matrix1);
                matrixCreation(data2, &matrix2);
                subtraction(&matrix1, &matrix2);
            break;

            case 7:
                printf("Wybrałeś mnożenie\n");
                printf("Wprowadź pierwszą macierz:\n");
                scanf("%s", data1);
                printf("Wprowadź drugą macierz:\n");
                scanf("%s", data2);
                matrixCreation(data1, &matrix1);
                matrixCreation(data2, &matrix2);
                multiplication(&matrix1, &matrix2);
            break;
            
            case 8:
                return 0;
            break;
        }
    //}

    return 0;
}