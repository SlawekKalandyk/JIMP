#include <stdio.h>
#include <stdlib.h>
#include "declarations.h"

int main(void)
{
    int choice = 0;
    char rawData[255];
    Matrix matrix1, matrix2;

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
            "Wybierz działanie:\n");

    scanf("%d", &choice);

    switch(choice)
    {
        case 1:
        break;

        case 2:

        break;
    }

    initialisation(&matrix1);
    matrixSize("[1 2;3 4;5 6]", &matrix1);
    memoryAllocation(&matrix1);
    dataFormatting("[1 2;3 4;5 6]", matrix1);

    initialisation(&matrix2);
    matrixSize("[1 2;3 4;5 6]", &matrix2);
    memoryAllocation(&matrix2);
    dataFormatting("[1 2;3 4;5 6]", matrix2);

    for(int i = 0; i < matrix1.rows; i++)
    {
        for(int j = 0; j < matrix1.columns; j++)
            printf("%d ", matrix1.array[i][j]);
        printf("\n");
    }

    for(int i = 0; i < matrix1.rows; i++)
        free(matrix1.array[i]);
    free(matrix1.array);

    return 0;
}