#include <stdio.h>
#include <string.h> // call function strcpy
#define MAX_SURNAME 21
#define MAX_FIRST_NAME 11
// globally defined struct
struct // remove struct tag
{
    // declare struct members
    int n;
    char s[MAX_SURNAME];
    char fn[MAX_FIRST_NAME];
} s1,s2; // variables after curly
int main()
{
    // read dot notation
    printf("enter number: ");
    scanf("%d",&s1.n); // complex variable s1
    printf("surname : ");
    scanf("%20s",s1.s); // no address operator
    printf("first name: ");
    scanf("%10s",s1.fn); // no address operator
    s2.n=s1.n+1;
    strcpy(s2.s,"Smith");
    strcpy(s2.fn,"Jane");
    // display dot notation
    printf("Student Records:\n");
    puts("================");
    printf("Number: %d\n",s1.n);
    printf("First Name: %s\n",s1.fn);
    printf("Surname: %s\n",s1.s);
    puts("================");
    printf("Number: %d\n",s2.n);
    printf("First Name: %s\n",s2.fn);
    printf("Surname: %s\n",s2.s);
    return 0;
}
