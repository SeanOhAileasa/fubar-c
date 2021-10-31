#include <stdio.h>
#include <math.h> // call function sqrt
#include <stdlib.h> // call function abs
int main()
{
    int n6=25,n7=-25;
    printf("%f\n",sqrt(n6));
    printf("%f\n",sqrt(n7)); // output undefined nan
    printf("%f\n",sqrt(abs(n7)));
    return 0;
}
