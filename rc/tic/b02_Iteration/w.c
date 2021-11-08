#include <stdio.h>
int main(int argc, char *argv[])
{
    int ctr=0;
    float n=1; // non-zero value true
    float total=0;
    while (n!=0) // evaluate control expression
    {
        printf("enter a number: ");
        if (scanf("%f",&n)!=1)
        {
            puts("err");
            break; // exit while loop
        }
        total+=n;
        printf("running total : %f\n",total);
        ctr++;
    }
    printf("loop cycles: %d\n",ctr);
    if (total!=0)
        printf("final total: %f\n",total);
    return 0;
}
