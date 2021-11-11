#include <stdio.h>
#define MEALS 3
int main(int argc, char *argv[])
{
    int calories[MEALS]; // via array notation
    int x,total=0;
    puts("--- Calorie Counter ---");
    for (x=0;x<MEALS;x++)
    {
        printf("calories at meal %d: ",x+1);
        scanf("%d",&calories[x]); // via array notation
        total=total+calories[x]; // via array notation
    }
    puts("------ Contents -------");
    for (x=0;x<MEALS;x++)
        printf("subscript/index: %d (element: %d)\n",x,calories[x]); // via array notation
    printf("total meal calories: %d\n",total);
    return 0;
}
