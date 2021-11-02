// system header files
#include <stdio.h>
#include <limits.h>
#include <float.h>
// symbolic name constant
#define BITS 8
#define ZERO 0
int main()
{
    printf("Data Type                              Bytes (Bits) (Range)\n");
    printf("---------                              --------------------\n" );
    printf("char(default signed)                   %lu (%lu) (%d to %d)\n",
            sizeof(char),sizeof(char)*BITS,CHAR_MIN,CHAR_MAX);
    printf("unsigned char                          %lu (%lu) (%d to %u)\n",
            sizeof(unsigned char),sizeof(unsigned char)*BITS,ZERO,UCHAR_MAX); 
    printf("short\nshort int\nsigned short\nsigned short int                       %lu (%lu) (%d to %d)\n",
            sizeof(short),sizeof(short int)*BITS,SHRT_MIN,SHRT_MAX);
    printf("unsigned short\nunsigned short int                     %lu (%lu) (%d to %u)\n",
            sizeof(unsigned short),sizeof(unsigned short int)*BITS,ZERO,USHRT_MAX);
    printf("int\nsigned\nsigned int                             %lu (%lu) (%d to %d)\n",
            sizeof(int),sizeof(signed)*BITS,INT_MIN,INT_MAX);
    printf("unsigned\nunsigned int                           %lu (%lu) (%d to %u)\n",
            sizeof(unsigned),sizeof(unsigned int)*BITS,ZERO,UINT_MAX);
    printf("long\nlong int\nsigned long\nsigned long int                        %lu (%lu) (%ld to %ld)\n",
            sizeof(long),sizeof(long int)*BITS,LONG_MIN,LONG_MAX);
    printf("unsigned long\nunsigned long int                      %lu (%lu) (%d to %lu)\n",
            sizeof(unsigned long),sizeof(unsigned long int)*BITS,ZERO,ULONG_MAX);
    printf("long long\nlong long int\nsigned long long\nsigned long long int                   %lu (%lu) (%lli to %lli)\n",
            sizeof(long long),sizeof(long long int)*BITS,LLONG_MIN,LLONG_MAX);
    printf("unsigned long long\nunsigned long long int                 %lu (%lu) (%d to %llu)\n",
            sizeof(unsigned long long),sizeof(unsigned long long int)*BITS,ZERO,ULLONG_MAX);

    printf("float                                  %lu (%lu) (%g to %g)\n%f\n",
            sizeof(float),sizeof(float)*BITS,FLT_MIN,FLT_MAX,FLT_MAX);
    printf("double                                 %lu (%lu) (%g to %g)\n%lf\n",
            sizeof(double),sizeof(double)*BITS,DBL_MIN,DBL_MAX,DBL_MAX);
    printf("long double                            %lu (%lu) (%Lg to %Lg)\n%Lf\n", 
            sizeof(long double),sizeof(long double)*BITS,LDBL_MIN,LDBL_MAX,LDBL_MAX);
    return 0;
}
