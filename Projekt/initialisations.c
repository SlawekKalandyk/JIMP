#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "declarations.h"

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

        if(c == ' ')
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

int dataFormatting(char *rawData, Matrix matrix)
{
    char numberHolder[100];
    char c;
    int rowCounter = 0;
    int columnCounter = 0;
    int charCounter = 0;
    
    for(int i = 1; i < (int)strlen(rawData); i++)
    {
        c = rawData[i];

        if(c == ' ')
        {
            matrix.array[rowCounter][columnCounter] = atoi(numberHolder);
            numberHolder[0] = 0;
            charCounter = 0;
            columnCounter++;
        }
        else if(c == ';' || c == ']')
        {
            matrix.array[rowCounter][columnCounter] = atoi(numberHolder);
            numberHolder[0] = 0;
            charCounter = 0;
            columnCounter = 0;
            rowCounter++;
        }
        else if(c >= 48 && c <= 57)
        {
            numberHolder[charCounter] = c;
            charCounter++;
        }
        else
            return 0;
    }

   return 1;
}

void addition(Matrix matrix1, Matrix matrix2)
{
    printf("Wybrałeś dodawanie\n");
    
    if(matrix1.rows == matrix2.rows && matrix1.columns == matrix2.columns)
    {
        Matrix result;

        for(int i = 0; i < matrix1.rows; i++)
        {
            for(int j = 0; j < matrix2.columns; j++)
            {
                
            }

            printf("\n");
        }
    }
    else
        printf("Ilośc wierszy lub kolumn macierzy pierwszej i drugiej nie są sobie równe!\n");
}