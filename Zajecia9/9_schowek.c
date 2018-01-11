#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "clipboard.h"

int main(void)
{
    const char *text = "abcdefghij";

    initialise();
    set(text);
    printToStdout();

    return 0;
}