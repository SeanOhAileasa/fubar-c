#include <stdio.h>
#define MAX 11 // ten plus '\0' 
int main(int argc, char *argv[])
{
    char s[MAX];
    printf("enter full name (include middle name): ");
    fgets(s,MAX,stdin); // input "jane m smith"
    printf("hello, ");
    puts(s); // output "jane m smi" '\0'
    return 0;
}
