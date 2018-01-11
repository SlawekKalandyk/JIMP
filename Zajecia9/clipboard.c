#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "clipboard.h"

#define chunkSize 5
#define chunkCount 10

struct TextChunk
{
    char text[chunkSize];
    int size;
    struct TextChunk *previousChunk;
    struct TextChunk *nextChunk;
    int readCounter;
};

static struct TextChunk safe[chunkCount];

int set(const char *text)
{
    int n = 0;

    for(int i = 0; i < (int) strlen(text) && i < capacity(); i++)
    {
        if(safe[n].size == chunkSize)
            n ++;
            
        safe[n].text[i - n * chunkSize] = text[i];
    }

    return 1;
}

void printToStdout(void)
{
    for(int i = 0; i < chunkCount; i++)
    {
        printf("%s", safe[i].text);
    }

    printf("\n");
}

int append(const char *text)
{

}

void clean(void)
{
    for(int i = 0; i < chunkCount; i++)
    {
        safe[i].text[0] = 0;
        safe[i].size = 0;
        safe[i].readCounter = 0;
    }
}

int count(void)
{
    int sum = 0;

    for(int i = 0; i < chunkCount; i++)
        sum += safe[i].size;

    return sum;
}

int capacity(void)
{
    return chunkCount * chunkSize;
}

void initialise(void)
{
    for(int i = 0; i < chunkCount; i++)
    {
        safe[i].text[0] = 0;
        safe[i].size = 0;

        if(i != 0)
            safe[i].previousChunk = &safe[i - 1];
        else
            safe[i].previousChunk = NULL;
        if(i != chunkCount - 1)
            safe[i].nextChunk = &safe[i + 1];
        else
            safe[i].nextChunk = NULL;

        safe[i].readCounter = 0;
    }
}