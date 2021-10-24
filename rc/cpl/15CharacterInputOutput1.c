#include <stdio.h>
int main()
{
    int c;
    while ((c=getchar())!=EOF) // != higher precedence
    {
        putchar(c);
    }
}
