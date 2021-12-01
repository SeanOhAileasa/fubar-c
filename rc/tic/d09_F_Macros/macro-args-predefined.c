/* conditional directives */
#include <stdio.h>
#include <stdlib.h>
#include "./header/myHeaders.h"
/* undefine ``MAX_PRICE`` albeit defined $45$ */
#undef MAX_PRICE
/* define ``MAX_PRICE`` at $100$ and is only valid in this file */
#define MAX_PRICE 100
/* if not defined (not have a ``macro`` called ``THRESHOLD`` then define */
#ifndef THRESHOLD
    #define THRESHOLD 23.751
#endif
/* defining function ``greet`` which receives one parameter ``name`` */
#define greet(name) \
	puts("Thank you for shopping here, "#name"\n")
int main(int argc, char *argv[])
{
    printf("MAX_PRICE = %d\n",MAX_PRICE);
    printf("THRESHOLD = %f\n",THRESHOLD);
    /* call function ``greet`` with string ``"ns"`` albeit string double qoutes not required (special to macros) */
    greet(ns);
    /* predefined macros in ``C`` (processor directives) */
    printf("File : %s\n",__FILE__);
    printf("Date : %s\n",__DATE__);
    printf("Time : %s\n",__TIME__);
    printf("Line : %d\n",__LINE__); // is line number
    printf("ANSI : %d\n",__STDC__); // current standard value
    return 0;
}
