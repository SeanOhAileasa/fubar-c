#include <stdio.h>
#define MAX 11 // ten plus '\0' 
int main(int argc, char *argv[])
{
    char s[MAX];
    printf("enter full name (include middle name): ");
    scanf("%10s",s); // input "jane smith"
    printf("hello, ");
    puts(s); // output "jane" '\0'
    return 0;
}
