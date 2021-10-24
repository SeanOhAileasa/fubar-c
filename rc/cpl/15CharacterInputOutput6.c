#include <stdio.h>
#define IN 1
#define OUT 2
int main()
{
    int c;
    int state=OUT; // not a word
    while((c=getchar())!=EOF)
    {
        if (c==' ' || c=='\t')
        {
            if (state==IN) // is a word
                putchar('\n'); // print a newline
            state=OUT; // reinitialise not word
        }
        else
        {
            putchar(c);
            state=IN;
        }
    }
}
