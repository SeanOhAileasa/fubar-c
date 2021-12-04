/* includes i. data structure ``FILE`` and ii. ``NULL`` */
#include <stdio.h> 
void openFile()
{
    /* i. open file (for reading) and establish link between pointer and particular area in storage */
    FILE *fp; // pointer to FILE
    /* refer to the file via file pointer (``fp``) and establish link (``file.txt``) via function ``fopen`` 
     * function ``fopen`` takes two arguments: i. location and ii. mode 
     * as data is read or written to the file the file pointer (``fp``) will automatically point to the next byte of storage */
    fp=fopen("README.md","r"); // within directory "../../../README.md"
    /* ii. checking for errors with the file - if unable to open file the the file pointer (``fp``) is ``NULL`` */
    if (fp==NULL) 
        puts("error opening file (perhaps the file does not exist!)"); 
    else
    {
        puts("file is opened (read-only!)"); 
        /* iii. close the file via function ``fclose`` */
        fclose(fp);
        puts("file is now closed!");
    }
}
