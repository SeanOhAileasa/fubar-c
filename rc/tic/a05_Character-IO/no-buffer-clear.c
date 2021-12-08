/* ``fflush(stdin)`` is required only in certain compilers */
#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[])
{
    char s[20];
    for (int i=0;i<2;i++)
    {
        puts("enter string:");
        scanf("%[^\n]s",s); // input is "test" "another test"
        printf("%s\n",s); // output "test" "another test"
        /* clearing the buffer and accept the next string */
        fflush(stdin);
    }
    return 0;
}
