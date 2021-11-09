#include <stdio.h>
#define SIZE 5 // array a dimension  
int main(int argc, char *argv[])
{
    int a[SIZE],t,y,o;
    printf("enter ages of %d people: ",SIZE);
    /*
        i.  read in values
        ii. total the ages
    */
    for (int i=0;i<SIZE;i++)
    {
        if (scanf("%d",&a[i])!=1 || a[i]<1 || a[i]>130) // check input error
        {
            puts("err");
            t=0;
            break;
        }
        t+=a[i]; // add element value
    }
    /*
        i.   access compare elements
        ii.  assign youngest oldest
        iii. display the results
    */
    if (t!=0) // check for errors
    {
        y=a[0]; // youngest first element
        o=a[0]; // oldest first element
        for (int j=0;j<SIZE;j++)
        {
            if (a[j]<y) // element less youngest
                y=a[j]; // youngest assign current
            else if (a[j]>o)
                o=a[j];
        }
    printf("youngest age is %d\n",y);
    printf("oldest age is %d\n",o);
    printf("average age is %.1f\n",(float)t/SIZE);
    }
    return 0;
}
