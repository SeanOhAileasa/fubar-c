#include <stdio.h>
#define SIZE 12 // symbolic name constant
int main(int argc, char *argv[])
{
    int days[SIZE]={31,28,31,30,31,30,31,31,30,31,30,31},month;
    printf("enter a month (1-Jan, 12-Dec): ");
    do
    {
        if (scanf("%d",&month)!=1 || month<1 ||  month>12)
        {
            puts("err");
            break;
        }
        printf("number of days in month %d is %d\n",month,days[month-1]);
    } while (month<1 || month >12); // exit invalid month
    return 0;
}
