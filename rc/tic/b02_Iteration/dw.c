#include <stdio.h>
int main(int argc, char *argv[])
{
    int ctr=0;
    float n,total=0;
    do
    {
        printf("enter a numnber: ");
        if (scanf("%f",&n)!=1)
        {
            puts("err");
            break; // exit do while
        }
        total+=n;
        printf("running total: %f\n",total);
        ctr++;
    } while (n!=0);
    printf("loop cycles: %d\n",ctr);
    if (total!=0)
        printf("final total: %f\n",total);
    return 0;
}
