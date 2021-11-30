#include <stdio.h>
#include <time.h>
#include <stdlib.h>
int *generate(); // array random numbers
void generateMemory(int *);
int main(int argc, char *argv[])
{
    /* pointer variable ``arr`` is used to hold the array and references the array returned */
    int *arr=generate(10); // ten random values
    for (int i=0;i<10;i++)
        printf("%4d",arr[i]);
    putchar('\n');
    /* best practice is to declare array in ``main`` then call manipulation function ``generateMemory`` */
    int a[10];
    generateMemory(a);
    for (int i=0;i<10;i++)
        printf("%4d",a[i]);
    putchar('\n');
    return 0;
}
int *generate()
{
    static int a[10]; // ensure contents remain
    srand((unsigned)time(NULL));
    for (int i=0;i<10;i++)
        a[i]=rand()%100+1; // random value [1,100]
    return a;
}
void generateMemory(int *a)
{
    srand((unsigned)time(NULL));
    for (int i=0;i<10;i++)
        *(a+i)=rand()%100+1; // random value [1.100]
    /* nothing has to be returned given the array is manipulated in memory */
}
