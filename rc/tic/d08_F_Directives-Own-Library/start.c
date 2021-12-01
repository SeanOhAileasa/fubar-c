#include <stdio.h>
#include <stdlib.h>
/* extend functionality beyond whats built-in by ``C`` 
 * ``.h`` (linking code) and ``.c`` (actual code) */
#include "./headers/myLibrary.h"
#define MAX 21
int main(int argc, char *argv[])
{
    function1(MAX);
    function2();
    return 0;
}
