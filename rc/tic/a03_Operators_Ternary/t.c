#include <stdio.h>
int main()
{
    float a,b,max;
    printf("enter two ages: ");
    if ((scanf("%f%f",&a,&b))!=2) // sanity error check
    {
        puts("ERR");
        return 1; // exit fully program
        puts("restart"); // not called exited
    } else
        max=(a>b)?a:b; // max two inputs
    printf("larger age is %0.0f\n",max);
    printf("larger variable is %c\n",(a>b)?'a':'b');
    printf("age classification is %s\n",((max<19)?"child":(max<65?"adult":"pensioner")));
    return 0;
}
