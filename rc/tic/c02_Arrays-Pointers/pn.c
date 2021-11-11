#include <stdio.h>
#define MEALS 3
int main(int argc, char *argv[])
{
    int *calories; // via pointer notation
    int x,total=0;
    puts("--- Calorie Counter ---");
    for (x=0;x<MEALS;x++)
    {
        printf("calories at meal %d: ",x+1);
        scanf("%d",calories+x); // via pointer notation
        total=total+*(calories+x); // via pointer notation
    }
    puts("------ Contents -------");
    for (x=0;x<MEALS;x++)
        printf("subscript/index: %d (element: %d)\n",x,*(calories+x)); // via pointer notation
    printf("total meal calories: %d\n",total);
    return 0;
}
