#include <stdio.h>
#include <stdlib.h> // call function rand
#include <time.h> // call function time
int main()
{
    srand((unsigned)time(NULL));
    printf("%d\n",rand());
    return 0;
}
