#include <stdio.h>
#include <string.h> // call function strlen
/* the prototype informs the compiler that the function ``display_chars`` will receive an ``int`` and a ``char`` */
void display_chars(int,char); // variable names optional 
void stars_only(); // void type optional
int main(int argc, char *argv[])
{
    char text[]="some text"; // using array notation
    char *endProgram="Program Complete"; // using pointer notation
    display_chars(35,' '); // display 35 blanks
    display_chars(11,'*');
    putchar( '\n' );
    display_chars(35,' ');
    display_chars(1,'*');
    
    // printf(text); // display via string
    
    for(int counter=0;counter<strlen(text);++counter) // display via character
        // printf("%c",text[counter]); // using array notation
        printf("%c",*(text+counter)); // using pointer notation
    
    display_chars(1,'*');
    putchar('\n');
    display_chars(35,' ');
    display_chars(11,'*');
    putchar('\n');
    stars_only();
    putchar('\n');
    display_chars(33,' ');
    printf(endProgram);
    putchar('\n');
    stars_only();
    putchar('\n');
    return 0;
}
/* formal arguments ``num`` and ``ch`` are local to ``display_chars`` (receives actual arguments from ``main`` */
void display_chars(int num,char ch)
{
    for (int counter=0;counter<num; ++counter)
        putchar(ch);
}
void stars_only() // void type optional
{
    int n=81;
    for(int counter=0;counter<n;++counter)
        putchar('*');
}
