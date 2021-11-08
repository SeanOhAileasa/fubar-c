#include <stdio.h>
int main(int argc, char *argv[])
{
    int n;
    printf("enter a number: ");
    if (scanf("%d",&n)!=1)
        puts("err");
    else
        puts("Number - Square - Cube");
        for (int i=1;i<=n;i++)
            printf("%4d%9d%8d\n",i,i*i,i*i*i);       
    return 0;
}
