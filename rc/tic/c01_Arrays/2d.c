#include <stdio.h>
#define COL_LABS 2
#define ROW_DAYS 3
int main(int argc, char *argv[])
{
    int usage[ROW_DAYS][COL_LABS];
    int dayIndex,labIndex,tu;
    /*
        i.  each day
        ii. read lab usage    
    */
    for (dayIndex=0;dayIndex<ROW_DAYS;dayIndex++) // row outer loop
    {
        printf("DAY (%d)\n",dayIndex+1);
        for (labIndex=0;labIndex<COL_LABS;labIndex++) // column inner loop
        {
            printf("LAB (%d): ",labIndex+1);
            scanf("%d",&usage[dayIndex][labIndex]);
        } // execute to completion
    }
    /*
        i.  each lab
        ii. calculate average usage
    */
    for (labIndex=0;labIndex<COL_LABS;labIndex++)
    {
        tu=0;
        for (dayIndex=0;dayIndex<ROW_DAYS;dayIndex++)
            tu+=usage[dayIndex][labIndex]; // execute to completion
         printf("LAB (%d) average: %d\n",labIndex+1,tu/ROW_DAYS);
    }
    return 0;
}
