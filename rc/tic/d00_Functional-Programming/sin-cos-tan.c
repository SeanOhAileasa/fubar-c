/* functions ``sin`` and ``cos`` and ``tan``
 * the angle (in degrees) may be:
 * i.  typed at the command line (cmd) or
 * ii. input when the program is running */
#include <stdio.h>
/* need to convert numeric ASCII string to binary equivalent (ignoring whitespace)
 * ``atoi`` str to int (stop at decimal pointer)
 * ``atol`` str to long int		
 * ``atof`` str to double float */
#include <stdlib.h>
/* to compile/link program containing ``math`` functions:
 * ``cc -o sin-cos-tan sin-cos-tan.c -lm`` 
 * ``./sin-cos-tan <degrees> */
#include <math.h> // double values required
#define RADS_TO_DEGS 57.29578
int main(int argc, char *argv[])
{
    double degrees,radians;
    if (argc<2) // cmd no input 
    {
        printf("input angle: ");
        if (scanf("%lf",&degrees)!=1) // check number input
        {
            puts("err");
            return 1;
        }
    } 
    else
    {
        // printf("%s\n",argv[0]); // name of program
        /* angle input at cmd must be converted from ASCII string to floating-point value */
        degrees=atof(argv[1]); // string to double
    }
    radians=degrees/RADS_TO_DEGS; // degrees to radians
    printf("sin(%.3lf)=%.3lf\n",degrees,sin(radians));
    printf("cos(%.3lf)=%.3lf\n",degrees,cos(radians));
    printf("tan(%.3lf)=%.3lf\n",degrees,tan(radians));
    return 0;
}
