/* jump table (array): 
 * i.  take function addresses and put into an array 
 * ii. use the array to call whichever function is called based on user input */
#include <stdio.h>
const char *prompt();
int jump(const char *);
// function definition here
void fa()
{
    puts("this is fa()");
}
void fb()
{
    puts("this is fb()");
}
void fc()
{
    puts("this is fc()");
}
void fd()
{
    puts("this is fd()");
}
void fe()
{
    puts("this is fe()");
}
/* prototype of an array of function pointers
 * initialise address of the five functions using ``'\0'`` (or ``NULL``) to terminate */
void (*funcs[])()={&fa,&fb,&fc,&fd,&fe,'\0'}; // operator ``&`` optional
int main(int argc, char *argv[])
{
    /* i.  function ``prompt`` returns a constant character pointer
     * ii. function ``jump`` gets called with the ``response`` from function ``prompt`` */
    while (jump(prompt()))
        ; // empty while loop
    puts("\n--- END --");
    return 0;
}
const char *prompt()
{
    puts("Choose an option:");
    puts("1. Function fa()");
    puts("2. Function fb()");
    puts("3. Function fc()");
    puts("4. Function fd()");
    puts("5. Function fe()");
    puts("Q. Quit." );
    printf(">> ");
    /* flushing the ``stdout`` buffer after prompt */
    fflush(stdout);
    /* static storage for response buffer */
    static char response[16];
    /* get string response from console: i. actual response input and ii. response buffer and iii. from ``stdin`` */
    fgets(response,16,stdin);
    return response;
}
/* accepts constant ``char`` pointer (``rs``) from function ``prompt`` */
int jump(const char *rs)
{
    /* obtain first ``char`` in the string input because anything after is irrelvant */
    char code=rs[0];
    if (code=='q' || code=='Q')
        /* if the ``while`` loop in ``main`` see zero then ends the loop */
        return 0;
    /* every other ``rs`` that is not ``'q'`` or ``'Q'`` then count the length of the array ``funcs``
     * looking for the ``'\0'`` at the end of the list of function pointers (``funcs``) */
    int l=0;
    while (funcs[l]!='\0') // not at end
        l++;
    /* trick to convert ASCII digit or numeral into an ``int`` */
    int i=(int)code-'0';
    i--; // option 0th element
    if (i<0 || i>=l)
    {
        puts("invalid choice!");
        return 1; // continue main loop
    }
    else
    {
        /* calling function ``func`` the array of function pointers subscripted based on user input */
        (*funcs[i])();
        return 1;
    }
}
