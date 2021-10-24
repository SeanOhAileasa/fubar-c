#include <stdio.h>
int main()
{
    int c,l;
    l=0;
    while ((c=getchar())!=EOF)
        if (c=='\n') // "\n" string constant
            ++l;
    printf("%d\n",l);
}
