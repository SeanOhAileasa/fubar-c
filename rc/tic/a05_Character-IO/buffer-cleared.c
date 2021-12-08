/* ``while((getchar())!='\n')``after ``scanf`` flushes the input buffer */
#include <stdio.h>
int main(int argc, char *argv[])
{
    char s[80],c;
    scanf("%s",s); // scan user input
    /* flushes the standard input */
    while ((getchar())!='\n'); // clears input buffer
    c=getchar(); // scan user character
    printf("string = %s\n",s);
    printf("character = %c\n",c); // not printing character
    return 0;
}
