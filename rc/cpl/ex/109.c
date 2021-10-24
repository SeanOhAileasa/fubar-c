#include <stdio.h>
int main()
{
    int current; // character constant [SPACE]
    int previous; // decimal 32 [SPACE]
    while((current=getchar())!=EOF)
    {
        if (current!=' '||previous!=32)
            putchar(current);
        previous=current;
    }
}
