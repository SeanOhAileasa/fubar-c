#include <stdio.h>
#include <stdlib.h> // function call malloc
int main()
{
    int *m;
    m=(int*)malloc(sizeof(int)*16);
    if (m==NULL)
        puts("memory full");
    else
        puts("storage for 16 integers allocated");
    return 0;
}
