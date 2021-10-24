#include <stdio.h>
int main()
{
    int c; // decimal 0 [NULL]
    while((c=getchar())!=EOF) // decimal -1 EOF
    {
        if (c==9) // decimal 9 [HORIZONTAL TAB]
        {
            putchar(92); // decimal 92 '\'
            c='t';
        }
        else if (c=='\b') // decimal 8 [BACKSPACE]
        {
            putchar(92);
            c='b';
        }
        else if (c=='\\')
        {
            putchar(92);
            c='\\';
        }
        putchar(c);
    }
}
