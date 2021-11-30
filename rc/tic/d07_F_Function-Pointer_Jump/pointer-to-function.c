/* possible to take the address of a function and assign it to a pointer */
#include <stdio.h>
void func();
int main(int argc, char *argv[])
{
    /* void is the return type of the function pointer ``fp`` and must match ``func`` assigned */
    void (*fp)()=&func; // parentheses operator precedence
    /* the ``&`` is optional (has to do with how types are promoted) */
    void (*fp1)()=func;
    /* using function pointer ``fp`` to call function ``func``
     * dereference operator to dereference the pointer (parentheses necessary) */
    (*fp)(); // explicit function pointer
    (fp)();
    return 0;
} 
void func()
{
    puts("func()-Hello!");
}
