#include <stdio.h> // call function fgets
#include <stdlib.h> // call function malloc
#define SIZE 10 
int main(int argc, char *argv[])
{
    char *ptr; // ptr pointer char
    ptr=(char *)malloc(sizeof(char)*SIZE); // type cast location
    if (ptr==NULL)
        puts("memory full");
    else
        printf("ptr contents: %p\n",ptr);
    printf("type a string: "); // input string "0123456789"
    fgets(ptr,SIZE,stdin); // nine characters null
    printf("string output: %s\n",ptr);  // output string "012345678"
    return 0;
}
