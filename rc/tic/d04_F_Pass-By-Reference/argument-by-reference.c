/* passing function arguments by reference */
#include <stdio.h>
void any_function(int *formal_arg); // variable name optional
int main(int argc, char *argv[])
{
    int actual_arg=1;
    printf("calling function main actual_arg is %d\n",actual_arg);
    /* passing address of ``actual_arg`` to become ``formal_arg`` */
    any_function(&actual_arg); // pass actual_arg address
    /* given an address of ``actual_arg`` is passed to the function ``printf`` this allows for change */
    printf("calling function main actual_arg is now %d\n",actual_arg);
    return 0;
}
void any_function(int *formal_arg) // receives an addres
{
    printf("formal_arg passed to function is %d\n",*formal_arg);
    *formal_arg=2; // dereference operator change
    printf("formal_arg passed to function is now %d\n",*formal_arg);
    /* nothing needs to be returned because the variable value passed is directly assessed in memory */
}
