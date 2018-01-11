#include <stdio.h>
#include <stdlib.h>
#include <string.h>

long long copyArgumentAndPrintCharByCharReturningSumOfArguments(void *data, int rozmiarDanych);

int main(void)
{
    char argument[255];
    long long argumentPrintAndSum = 0;

    printf("Podaj argument:\n");
    scanf("%s", argument);
    argumentPrintAndSum = copyArgumentAndPrintCharByCharReturningSumOfArguments(argument, strlen(argument));
    printf("Suma w systemie dziesiętnym: %lld\nSuma w systemie szesnastkowym: %0llX\n", argumentPrintAndSum, argumentPrintAndSum);
    
    return 0;
}

long long copyArgumentAndPrintCharByCharReturningSumOfArguments(void *data, int dataSize)
{

    char arrayOfChars[dataSize];
    long long sum = 0;

    memcpy(arrayOfChars, data, dataSize);
    //arrayOfChars[dataSize] = '\0';

    for(int i = 0; i < dataSize; i++)
    {
        printf("%c : %0X\n",arrayOfChars[i], arrayOfChars[i]);
        sum += arrayOfChars[i];
    }

    return sum;
}