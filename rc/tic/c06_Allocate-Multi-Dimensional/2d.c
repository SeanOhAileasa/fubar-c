#include <stdio.h>
#include <stdlib.h> // call function malloc
int main(int argc, char *argv[])
{
    int nRows=3,nColumns=2,iRow,jColumn;
    int **ptr=(int **)malloc(sizeof(int *)*nRows); // 2d allocate memory
    for (iRow=0;iRow<nRows;iRow++)
    {
        ptr[iRow]=(int *)malloc(sizeof(int)*nColumns); // 1d allocate memory
        if (ptr[iRow]==NULL)
        {
            puts("cannot allocate memory");
            return 1;
        }
    }
    for (iRow=0;iRow<nRows;iRow++) // row by row
    {
        for (jColumn=0;jColumn<nColumns;jColumn++)
        {
            printf("enter element [%d,%d]: ",iRow,jColumn);
            if (scanf("%d",&ptr[iRow][jColumn])!=1) // not a number
            {
                puts("err");
                return 1;
            }
        } // execute next row
    }
    for (iRow=0;iRow<nRows;iRow++) // display each element
    {
        for (jColumn=0;jColumn<nColumns;jColumn++)
            printf("element [%d,%d] is %d]\n",iRow,jColumn,ptr[iRow][jColumn]);
    }
    for (iRow=0;iRow<nRows;iRow++)
        free(ptr[iRow]); // free 1d memory
    free(ptr); // free 2d memory
    return 0;
}
