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
    printf("-------\n");

    empty(&vector);

    pushBack(&vector, 10);
    pushBack(&vector, 11);
    pushBack(&vector, 12);
    pushBack(&vector, 13);
    pushBack(&vector, 14);
    insert(&vector, 4, 2137);
    printVector(&vector);
    printf("-------\n");

    reverse(&vector);
    printVector(&vector);
    printf("-------\n");

    free(vector.array);

    return 0;
}