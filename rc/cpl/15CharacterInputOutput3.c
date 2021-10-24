#include <stdio.h>
int main()
{
    double n;
    for (n=0;getchar()!=EOF;++n)
        ;
    printf("%.0f\n",n);
}
