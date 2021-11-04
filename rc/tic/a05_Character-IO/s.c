#include <stdio.h>
int main()
{
    char ch;
    printf("press a key and then press enter: ");
    fflush(stdout);
    scanf("%c",&ch); // capture whitespace character
    printf("you pressed the %c key\n",ch);
    return 0;
}
