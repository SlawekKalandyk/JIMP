#include <stdio.h>
#include <stdlib.h>
#include "vector.h"

struct Vector
{
    int *array;
    int size;
    int amountOfElements;
}

void reserve(int *array, int arraySize)
{
    array = (int*) malloc (arraySize * sizeof *array);

}

int size(int *array)
{
    return sizeof(array) / sizeof(int);
}

int capacity(int *array)
{
    return size;
}

int empty(int *array)
{

}

void push_back(int *array)
{

}

void insert(int *array, int position, int element)
{

}

void removeAtPosition(int *array, int position)
{

}

void reverse(int *array)
{

}

int at(int *array, int position)
{

}