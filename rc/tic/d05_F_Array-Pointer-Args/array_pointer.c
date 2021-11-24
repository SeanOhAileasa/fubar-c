/* passing i. ``int`` array and ii. ``int`` pointer to a function */
#include <stdio.h>
#define SIZE 5
/* passing an array to a function is actually passing its base address in memory (same as a pointer) */
void func1(int[]); // same as pointer
void func2(int*); // same as array
int main(int argc, char *argv[])
{
    int list[SIZE]={1,2,3,4,5};
    // functions called by specifying array name only - cannot use empty ``[]`` as this generates a compiler error (expects a value)
    func1(list);
    func2(list);
    return 0;
}
/* no arrays are returned given that an array is a pointer (all manipulations are made in memory) */
void func1(int collection[])
{
    for (int i=0;i<SIZE;i++)
        printf("%3d",collection[i]);
    printf("\nlast element of collection (func1) is %d\n",collection[4]);
}
void func2(int *c)
{
    printf("last element of collection (func2) is %d\n",c[4]);
} 
