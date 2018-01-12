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
void addition(void);
void subtraction(void);
void multiplication(void);