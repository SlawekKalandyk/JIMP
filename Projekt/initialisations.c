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

void transposition(Matrix *matrix)
{
    int a = 0;

    int tab[matrix->rows][matrix->columns];

    for(int i = 0; i < matrix->rows; i++)
    {
        for(int j = 0; j < matrix->columns; j++)
            tab[i][j] = matrix->array[i][j];

        free(matrix->array[i]);
    }

    free(matrix->array);
    a = matrix->rows;
    matrix->rows = matrix->columns;
    matrix->columns = a;

    memoryAllocation(matrix);

    for(int i = 0; i < matrix->rows; i++)
    {
        for(int j = 0; j < matrix->columns; j++)
        {
            matrix->array[i][j] = tab[j][i];
            printf("%d ", matrix->array[i][j]);
        }

        printf("\n");
    }
}

void addition(Matrix *matrix1, Matrix *matrix2)
{
    if(matrix1->rows == matrix2->rows && matrix1->columns == matrix2->columns)
    {
        for(int i = 0; i < matrix1->rows; i++)
        {
            for(int j = 0; j < matrix2->columns; j++)
            {
                printf("%d ", matrix1->array[i][j] + matrix2->array[i][j]);
            }

            printf("\n");
        }
    }
    else
        printf("Ilość wierszy lub kolumn macierzy pierwszej i drugiej nie są sobie równe!\n");
}

void subtraction(Matrix *matrix1, Matrix *matrix2)
{
    if(matrix1->rows == matrix2->rows && matrix1->columns == matrix2->columns)
    {
        for(int i = 0; i < matrix1->rows; i++)
        {
            for(int j = 0; j < matrix2->columns; j++)
            {
                printf("%d ", matrix1->array[i][j] - matrix2->array[i][j]);
            }

            printf("\n");
        }
    }
    else
        printf("Ilość wierszy lub kolumn macierzy pierwszej i drugiej nie są sobie równe!\n");
}

void multiplication(Matrix *matrix1, Matrix *matrix2)
{
    int result = 0;

    if(matrix1->columns == matrix2->rows)
    {
        for(int i = 0; i < matrix1->rows; i++)
        {
            for(int j = 0; j < matrix2->columns; j++)
            {
                for(int n = 0; n < matrix1->columns; n++)
                    result += matrix1->array[i][n] * matrix2->array[n][j];

                printf("%d ", result);
                result = 0;
            }

            printf("\n");
        }
    }
    else
        printf("Ilość kolumn pierwszej macierzy i wierszy drugiej macierzy nie są sobie równe!\n");
}

void LUdecomposition(Matrix *matrix)
{

}