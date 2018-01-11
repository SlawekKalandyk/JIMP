#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "clipboard.h"

int main(void)
{
    const char *text = "abcdefghij";
    const char *text2 = "aaaaaaaaaafefeffefsefeggeeeeeeeeeewgwgwegdvddgewgegggergregegsdgerrsehhrtdhjegergberburelugiegluierlgureslu";  
    initialise();
    printToStdout();
    set(text);
    printToStdout();
    append(text);
    printToStdout();
    append(text2);
    printToStdout();
    clean();
    printToStdout();

    return 0;
}