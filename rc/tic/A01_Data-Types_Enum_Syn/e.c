#include <stdio.h>
int main()
{
    enum res{no,yes,none,unsure}; // data type res
    enum res ans; // variable of res
    puts("Enter - 0 (no) - 1 (yes) - 2 (none) - 3 (unsure)");
    scanf("%d",&ans);
    printf("You entered: %d\n",ans);
    switch(ans)
    {
        case 0:
            puts("NO!");
            break;
        case 1:
            puts("YES!");
            break;
        case 2:
            puts("NONE!");
            break;
        case 3:
            puts("UNSURE!");
            break;
    } 
    return 0;
}
