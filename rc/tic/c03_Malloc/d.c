#include <stdio.h>
#include <stdlib.h> // call function malloc
int main(int argc, char *argv[])
{
    int n,b,*a,i;
    printf("a.) enter number of elements: ");
    if (scanf("%d",&n)!=1) // input not number
    {
        puts("err");
        return 1;
    }
    printf("b.) calculate bytes required: %d\n",b=sizeof(int)*n); // by the array
    printf("c.) allocate memory required: %p\n",a=(int *)malloc(b)); // change pointer returned
    puts("d.) test memory is available"); // success point start     
    if (a==NULL)
        puts("cannot allocate memory");
    else // memory allocated successfully
    {
        for (i=0;i<n;i++)
        {
            printf("e.)  enter element number %d: ",i);
            if (scanf("%d",a+i)!=1) // input not number
            {
                puts("err");
                return 1;
            }
        }
        for (i=0;i<n;i++)
            printf("f.) [%d] element input: %d\n",i,*(a+i));
    }
    puts("g.) free allocated memory");
    free(a); // free previously allocated
    return 0;
}
