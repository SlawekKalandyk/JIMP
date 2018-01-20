#ifndef DECLARATIONS_H
#define DECLARATIONS_H

typedef struct _Matrix
{
    double **array;
    int rows;
    int columns;
} Matrix;

void printMatrix(Matrix matrix);
void swapDouble(double *a, double *b);
void swapInt(int *a, int *b);
void initialisation(Matrix *matrix);
void matrixSize(char *rawData, Matrix *matrix);
void memoryAllocation(Matrix *matrix);
int dataFormatting(char *rawData, Matrix *matrix);
void matrixCreation(char *rawData, Matrix *matrix);
double determinant(Matrix matrix);
void transposition(Matrix *matrix);
void inversion(Matrix *matrix);
void addition(Matrix *matrix1, Matrix *matrix2);
void subtraction(Matrix *matrix1, Matrix *matrix2);
void multiplication(Matrix *matrix1, Matrix *matrix2);

#endif