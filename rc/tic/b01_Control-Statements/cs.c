#include <stdio.h>
int main(int argc, char *argv[])
{
    float balance,interest,odRate=10.0;
    printf("enter account balance: ");
    if (scanf("%f",&balance)!=1)
        puts("err\n");
    else if (balance<0) // compound statement x3
    {
        puts("red");
        interest=-balance*odRate/100; // unary minus used
        printf("o/d rate %6.2f\n",interest);
    }
    else
    {
        puts("black");
        puts("no o/d charge");
    }
    return 0;
}
