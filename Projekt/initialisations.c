#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "declarations.h"

#define charArraySize 200

void initialisation(Matrix *matrix)
{
    matrix->rows = 0;
    matrix->columns = 0;
}

void matrixSize(char *rawData, Matrix *matrix)
{
    int i = 0;
    char c;

    while(c != ']')
    {
        c = rawData[i];
        i++;

        if(c == ',')
            matrix->columns++;
        else if(c == ';')
        {
            matrix->rows++;
            matrix->columns++;
        }
    }

    matrix->rows++;
    matrix->columns = (matrix->columns + 1) / matrix->rows;
}

void memoryAllocation(Matrix *matrix)
{
    matrix->array = (int**)malloc(matrix->rows * sizeof(int*));

    for(int i = 0; i < matrix->rows; i++)
        matrix->array[i] = (int*)malloc(matrix->columns * sizeof(int));
}

int dataFormatting(char *rawData, Matrix *matrix)
{
    char numberHolder[charArraySize];
    char c;
    int rowCounter = 0;
    int columnCounter = 0;
    int charCounter = 0;
    
    for(int i = 1; i < (int)strlen(rawData); i++)
    {
        c = rawData[i];

        if(c == ',')
        {
            matrix->array[rowCounter][columnCounter] = atoi(numberHolder);
            memset(numberHolder, 0, charArraySize);
            charCounter = 0;
            columnCounter++;
        }
        else if(c == ';' || c == ']')
        {
            matrix->array[rowCounter][columnCounter] = atoi(numberHolder);
            memset(numberHolder, 0, charArraySize);
            charCounter = 0;
            columnCounter = 0;
            rowCounter++;
        }
        else if((c >= 48 && c <= 57) || c == 45)
        {
            numberHolder[charCounter] = c;
            charCounter++;
        }
        else
            return 0;
    }

    return 1;
}

void matrixCreation(char *rawData, Matrix *matrix)
{
    initialisation(matrix);
    matrixSize(rawData, matrix);
    memoryAllocation(matrix);
    dataFormatting(rawData, matrix);
}

void addition(void)
{
    Matrix matrix1, matrix2;
    char data1[charArraySize];
    char data2[charArraySize];
    
    printf("Wybrałeś dodawanie\n");
    printf("Wprowadź pierwszą macierz:\n");
    scanf("%s", data1);
    printf("Wprowadź drugą macierz:\n");
    scanf("%s", data2);
    matrixCreation(data1, &matrix1);
    matrixCreation(data2, &matrix2);

    if(matrix1.rows == matrix2.rows && matrix1.columns == matrix2.columns)
    {
        for(int i = 0; i < matrix1.rows; i++)
        {
            for(int j = 0; j < matrix2.columns; j++)
            {
                printf("%d ", matrix1.array[i][j] + matrix2.array[i][j]);
            }

            printf("\n");
        }
    }
    else
        printf("Ilość wierszy lub kolumn macierzy pierwszej i drugiej nie są sobie równe!\n");
}

void subtraction(void)
{
    Matrix matrix1, matrix2;
    char data1[charArraySize];
    char data2[charArraySize];
    
    printf("Wybrałeś odejmowanie\n");
    printf("Wprowadź pierwszą macierz:\n");
    scanf("%s", data1);
    printf("Wprowadź drugą macierz:\n");
    scanf("%s", data2);
    matrixCreation(data1, &matrix1);
    matrixCreation(data2, &matrix2);

    if(matrix1.rows == matrix2.rows && matrix1.columns == matrix2.columns)
    {
        for(int i = 0; i < matrix1.rows; i++)
        {
            for(int j = 0; j < matrix2.columns; j++)
            {
                printf("%d ", matrix1.array[i][j] - matrix2.array[i][j]);
            }

            printf("\n");
        }
    }
    else
        printf("Ilość wierszy lub kolumn macierzy pierwszej i drugiej nie są sobie równe!\n");
}

void multiplication(void)
{
    Matrix matrix1, matrix2;
    char data1[charArraySize];
    char data2[charArraySize];
    int result = 0;

    printf("Wybrałeś mnożenie\n");
    printf("Wprowadź pierwszą macierz:\n");
    scanf("%s", data1);
    printf("Wprowadź drugą macierz:\n");
    scanf("%s", data2);
    matrixCreation(data1, &matrix1);
    matrixCreation(data2, &matrix2);

    if(matrix1.columns == matrix2.rows)
    {
        for(int i = 0; i < matrix1.rows; i++)
        {
            for(int j = 0; j < matrix2.columns; j++)
            {
                for(int n = 0; n < matrix1.columns; n++)
                    result += matrix1.array[i][n] * matrix2.array[n][j];

                printf("%d ", result);
                result = 0;
            }

            printf("\n");
        }
    }
    else
        printf("Ilość kolumn pierwszej macierzy i wierszy drugiej macierzy nie są sobie równe!\n");
}