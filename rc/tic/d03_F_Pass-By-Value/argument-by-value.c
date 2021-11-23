/* passing function arguments by value */
#include <stdio.h>
void any_function(int);
int main(int argc, char *argv[])
{
    int actual_arg=1;
    printf("calling function main actual_arg is %d\n",actual_arg);
    /* passing copy of ``actual_arg`` to become ``formal_arg`` */
    any_function(actual_arg); // pass a copy 
    /* as a copy of ``actual_arg`` is sent to function ``printf`` then the value of ``actual_arg`` cannot change */
    printf("calling function main actual_arg is still %d\n",actual_arg);
    return 0;
}
void any_function(int formal_arg)
{
    printf("formal_arg passed to function is %d\n",formal_arg);
    formal_arg=2; // change the value
    printf("formal_arg passed to function is now %d\n",formal_arg);
}
