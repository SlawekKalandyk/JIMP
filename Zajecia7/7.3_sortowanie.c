#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void sortowanie(int *tab[10]);

int main(void)
{
    srand(time(NULL));
    int A[10] = {0};
    int *B[10] = {0};

    printf("Nieposortowana:\n");

    for(int i = 0; i < 10; i++)
    {
        A[i] = rand() % 50 + 1;
        B[i] = &A[i];
        printf("A[%d] = %d\n", i, A[i]);
    }

    sortowanie(B);
    printf("Posortowana:\n");

    for(int i = 0; i < 10; i++)
        printf("A[%d] = %d\n", i, *B[i]);

    return 0;
}

void sortowanie(int *tab[10])
{
    int *a = 0;

    for(int i = 0; i < 9; i++)
    {
        for(int n = 0; n < 9 - i; n++)
        {
            if(*tab[n] > *tab[n + 1])
            {
                a = tab[n];
                tab[n] = tab[n + 1];
                tab[n + 1] = a;
            }
        }
    }
    
}