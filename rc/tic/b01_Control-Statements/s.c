#include <stdio.h>
int main(int argc, char *argv[])
{
    char op;
    float n1,n2,ans;
    printf("enter an arithmetic expression (e.g. 1 + 2): ");
    scanf("%f%1s%f",&n1,&op,&n2); // operand operator operand
    switch(op) // compare each case
    {
        case '+':
            ans=n1+n2;
            printf("%f %c %f = %f\n",n1,op,n2,ans);
            break; // terminate end block
        case '-':
            ans=n1-n2;
            printf("%f %c %f = %f\n",n1,op,n2,ans);
            break;
        case '*':
        case 'x':
        case 'X':
            ans=n1*n2;
            printf("%f %c %f = %f\n",n1,op,n2,ans);
            break;
        case '/':
            ans=n1/n2;
            printf("%f %c %f = %f\n",n1,op,n2,ans);
            break;
        default: // no case match
            puts("invalid operator");
    }
    return 0;
}
