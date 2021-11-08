#include <stdio.h>
int main(int argc, char *argv[])
{
    float balance,interest,odRate=10.0;
    printf("enter account balance: ");
    if (scanf("%f",&balance)!=1)
        printf("err\n");
    else if (balance<0) // compound statement x3
    {
        printf("red\n");
        interest=-balance*odRate/100; // unary minus used
        printf("o/d rate %6.2f\n",interest);
    }
    else
    {
        printf("black\n");
        printf("no o/d charge\n");
    }
    return 0;
}
