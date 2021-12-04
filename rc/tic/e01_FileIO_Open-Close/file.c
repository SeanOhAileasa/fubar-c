#include <stdio.h>
int main(int argc, char *argv[])
{ 
    FILE *fp; // pointer to FILE
    /* i. open file for reading and ii. check for errors 
     * its common in ``C`` to combine: i. opening of file and ii. testing the file pointer */
    if ((fp=fopen("f.txt","r"))==NULL)  // parenthesis highest precedence
        puts("error opening file");
    else
    {
        puts("file f.txt opened");
        fclose(fp); // iii. close file
    }
    return 0;
}
