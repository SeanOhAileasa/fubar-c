#include <stdio.h>
int main(int argc, char *argv[])
{
    char s[11]; // ten plus '\0'
    printf("enter name: ");
    gets(s);
    return 0;
}
