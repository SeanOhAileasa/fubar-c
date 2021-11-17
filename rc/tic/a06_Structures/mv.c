#include <stdio.h>
#define MAX_SURNAME 21
#define MAX_FIRST_NAME 11
// globally defined struct
struct sRecord // struct tag optional
{
    // declare struct members
    int n;
    char s[MAX_SURNAME];
    char fn[MAX_FIRST_NAME];
};
int main()
{
    struct sRecord s1; // type struct sRecord
    // read dot notation
    printf("enter number: ");
    scanf("%d",&s1.n); // complex variable s1
    printf("surname : ");
    scanf("%20s",s1.s); // no address operator
    printf("first name: ");
    scanf("%10s",s1.fn); // no address operator
    // display dot notation
    printf("Add Student Record:\n");
    printf("Number: %d\n",s1.n);
    printf("First Name: %s\n",s1.fn);
    printf("Surname: %s \n",s1.s);
    return 0;
}
