// Sławomir Kalandyk
#include <stdio.h>
#include <stdlib.h>
#include "vector.h"

int main(void)
{
    Vector vector;

    initialise(&vector);
    printf("%d %d\n", size(&vector), capacity(&vector));
    reserve(&vector, 115);
    printf("%d %d\n", size(&vector), capacity(&vector));
    empty(&vector);
    pushBack(&vector, 10); printf("%d\n-----\n", vector.array[0]);
    pushBack(&vector, 11);
    pushBack(&vector, 12);
    pushBack(&vector, 13);
    pushBack(&vector, 14);

    insert(&vector, 4, 2137);

    for(int i = 0; i < vector.amountOfElements; i++)
        printf("%d\n", vector.array[i]);

    printf("-------\n");

    reverse(&vector);

    for(int i = 0; i < vector.amountOfElements; i++)
        printf("%d\n", vector.array[i]);

    printf("-------\n");

    free(vector.array);

    return 0;
}