#include <stdio.h>
int main()
{
    int c,b=0,t=0,l=0;
    while ((c=getchar())!=EOF)
    {
        if (c==' ')
            ++b;
        else if (c=='\t')
            ++t;
        else if (c=='\n')
            ++l;
    }
    printf("Blanks: %d\nTabs: %d\nNewline: %d\n",b,t,l);
}
