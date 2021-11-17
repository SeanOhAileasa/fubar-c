#include <stdio.h>
#include <stdlib.h> // call function realloc
int main(int argc, char *argv[])
{
    int n=0; // number of elements
    int s=sizeof(float); // initally four bytes
    float *ptr=(float *)malloc(s); // allocation one element
    char r; // represent user reply
    if (ptr==NULL)
    {
        puts("cannot allocate memory");
        return 1;
    } 
    else 
        do
        {
            printf("enter a numeric value: ");
            if (scanf("%f",ptr+n)!=1) // not a number
            {
                puts("err");
                return 1;
            }
            n++;
            printf("move values? (y or n): ");
            if (scanf("%1s",&r)>='0' || r<='9') // test for number
            {
                break;
            }
            if (r=='y' || r=='Y')
            {    
                ptr=(float *)realloc(ptr,s*n+1); // enlarge array size
                if (ptr==NULL)
                {
                    puts("cannot allocate additional memory");
                    break;
                }
            }    
        } while (r=='y' || r=='Y');  
        for (int i=0;i<n;i++) // display values entered 
            printf("element [%d] is %1f\n",i+1,*(ptr+i));
    return 0;
}
