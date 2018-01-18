// Sławomir Kalandyk
#include <stdio.h>
#include <stdlib.h>
#include "vector.h"

#define basicCapacity 50

void initialise(Vector *vector)
{
    vector->capacity = basicCapacity;
    vector->amountOfElements = 0;
    vector->array = (int*)malloc(vector->capacity * sizeof(int));
}

void reserve(Vector *vector, int size)
{
    if(vector->amountOfElements <= size)
    {
        vector->capacity = size;
        int *newMemory = (int*)realloc(vector->array, vector->capacity * sizeof(int));
    }
    else
    {
        printf("Na liście jest więcej elementów niż podany rozmiar listy na to pozwala. Część elementów z końca listy zostanie usunięta\n");

        for(int i = size; i < vector->amountOfElements; i++)
            vector->array[i] = 0;

        vector->capacity = size;
        vector->amountOfElements = size;
        int *newMemory = (int*)realloc(vector->array, vector->capacity * sizeof(int));
    }
}  

int size(Vector *vector)
{
    return vector->amountOfElements;
}

int capacity(Vector *vector)
{
    return vector->capacity;
}

void empty(Vector *vector)
{
    if(vector->amountOfElements)
        printf("Lista nie jest pusta\n");
    else
        printf("Lista jest pusta\n");
}

void pushBack(Vector *vector, int element)
{
    if(vector->amountOfElements == vector->capacity)
    {
        vector->capacity += basicCapacity;
        reserve(vector, vector->capacity);
    }
    
    vector->array[vector->amountOfElements] = element;
    vector->amountOfElements++;
}

void insert(Vector *vector, int position, int element)
{
    if(position < vector->amountOfElements )
    {
        if(vector->amountOfElements == vector->capacity)
        {
            vector->capacity += basicCapacity;
            reserve(vector, vector->capacity);
        }

        for(int i = vector->amountOfElements - 1; i >= position; i--)
            vector->array[i + 1] = vector->array[i];

        vector->array[position] = element;
        vector->amountOfElements++;
    }
    else if(position >= vector->amountOfElements)
        printf("Nie możesz dodać elementu dla tej pozycji\n");
}

void removeFromEnd(Vector *vector)
{
    if(vector->amountOfElements > 0)
    {    
        vector->array[vector->amountOfElements] = 0;
        vector->amountOfElements--;
    }
    else
        printf("Brak elementów w tablicy, nie można usunąć ostatniego elementu\n");
}

void reverse(Vector *vector)
{
    int swapper = 0;

    for(int i = 0; i < vector->amountOfElements / 2; i++)
    {
        swapper = vector->array[i];
        vector->array[i] = vector->array[vector->amountOfElements - 1 - i];
        vector->array[vector->amountOfElements - 1 - i] = swapper;
    }
}

int at(Vector *vector, int position)
{
    if(position < vector->amountOfElements)
        printf("%d\n", vector->array[position]);
    else
        printf("Brak elementu na tej pozycji\n");
}

void printVector(Vector *vector)
{
    for(int i = 0; i < vector->amountOfElements; i++)
        printf("%d\n", vector->array[i]);
}