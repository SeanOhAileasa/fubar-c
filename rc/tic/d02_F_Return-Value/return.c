/* function return values are copied to the stack and returned on the stack */
#include <stdio.h>
int minimum(int,int); // returns integer value
void displayLine(char,int); 
int main(int argc, char *argv[]) // returns integer value
{
    int val1,val2;
    printf("enter two integers: ");
    if (scanf("%d",&val1)!=1 || scanf("%d",&val2)!=1) // not a number
    {
        puts("err");
        return 1;
    }
    /* variables ``val1`` and ``val2`` are copied onto the stack and passed to the function ``minimum`` */
    printf("minimum of %d and %d is %d\n",val1,val2,minimum(val1,val2));
    displayLine('=',23);
    printf("minimum of %c(%d) and %c(%d) is %d\n",'A','A','a','a',minimum('A','a'));
    displayLine('=',6);
    return 0; 
}
int minimum(int num1,int num2)
{
    if (num1<num2)
        return num1; // return value ``main``
    return num2; // return caller `` main``
    /* value is copied onto the stack and returned to the caller function ``main`` */
}
void displayLine(char equal_sign,int length_of_line)
{
    for (int i=0;i<length_of_line;i++)
        printf("%c",equal_sign);
    putchar('\n');
    return; // optional void function
}
