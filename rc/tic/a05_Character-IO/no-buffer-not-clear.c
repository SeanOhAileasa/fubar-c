/* ``fflush(stdin)`` is required only in certain compilers */
#include <stdio.h>
int main(int argc, char *argv[])
{
    char s[20];
    for (int i=0;i<2;i++)
    {
        puts("enter string:");
        scanf("%[^\n]s",s); // input is "test"
        printf("%s\n",s); // output "test" "test"
    }
    return 0;
}
