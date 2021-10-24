#include <stdio.h>
#define IN 1 // inside a word
#define OUT 0 // outside a word
int main()
{
    int state=OUT;
    int c,nc,nl,nWord;
    nc=nl=nWord=0;
    while ((c=getchar())!=EOF)
    {
        ++nc; // add character count
        if (c=='\n')
            ++nl; // add line count
        if (c==' ' || c =='\n' || c=='\t')
            state=OUT; // not a word
        else if (state==OUT)
        {
            state=IN; // is a word
            ++nWord; // add word count
        }
    }
    printf("Characters: %d\nLines: %1d\nWords:%d\n",nc,nl,nWord);
}
