typedef struct _Matrix
{
    int **array;
    int rows;
    int columns;
} Matrix;

void initialisation(Matrix *matrix);
void matrixSize(char *rawData, Matrix *matrix);
void memoryAllocation(Matrix *matrix);
int dataFormatting(char *rawData, Matrix *matrix);
void matrixCreation(char *rawData, Matrix *matrix);
void transposition(Matrix *matrix);
void addition(Matrix *matrix1, Matrix *matrix2);
void subtraction(Matrix *matrix1, Matrix *matrix2);
void multiplication(Matrix *matrix1, Matrix *matrix2);
void LUdecomposition(Matrix *matrix);