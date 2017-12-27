//Sławomir Kalandyk
#include <stdio.h>
#include <stdarg.h>

void printLine(int n, ...);

int main(void)
{
    int a = 0;
    printf("Podaj ilość liczb, które chcesz wprowadzić:\n");
    scanf("%d", &a);
    printLine(a);

    return 0;
}

void printLine(int n, ...)
{
    int val;
    va_list vl;
    va_start(vl, n);
    printf("Podaj pierwszą liczbę: ");
    for(int i = 0; i < n; i++)
    {
        val = va_arg(vl, int);
        scanf("%d", &val);
        
        if(i != n-1)
            printf("... i kolejną: ");
    }
    va_end(vl);
}