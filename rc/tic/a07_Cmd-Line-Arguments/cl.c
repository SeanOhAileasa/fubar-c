#include <stdio.h>
int main(int argc, char *argv[])
{
    for (int i=0; i<argc; i++)
        printf("argument: %d is %s\n",i,argv[i]);
    if (argc<2)
    {
        puts("provide a filename!");
        return 1;
    }
    printf("examining file: %s\n",argv[1]);
    return 0;
}
