#include <stdio.h>
#include <stdlib.h> // call function malloc
int main(int argc, char *argv[])
{
    struct date // declare structure template
    {
        int m,y;
    };
    struct date *bd; // is memory location
    bd=(struct date *)malloc(sizeof(struct date)); // structure storage allocation
    if (bd==NULL)
    {
        puts("memory full");
        return 1;
    }
    printf("enter birth year: ");
    if (scanf("%d",&(*bd).y)!=1) // selection operator dereference
    {
        puts("err"); // number not input
        return 1;
    }
    printf("enter birth month: ");
    if (scanf("%d",&bd->m)!=1 || bd->m<1 || bd->m>12) // arroy notation instead
    {
        puts("err - [1,12]");
        return 1;
    }
    printf("birth month: %d\nbirth year :%d\n",(*bd).m,bd->y);
    return 0;
}
