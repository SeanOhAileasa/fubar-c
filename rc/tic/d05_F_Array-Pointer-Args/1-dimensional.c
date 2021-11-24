/* passing a one-dimensional array to a function */
#include <stdio.h>
#define SIZE 10
int sum_array(const int[], const int); // using array notation
int sum_pointer(int*, int); // using pointer notation
int main(int argc, char *argv[])
{
    int values[SIZE]={1,2,3,4,5,6,7,8,9,10}; // declare actual arguments
    printf("first element is %d\n",*values); // using pointer notation
    printf("second element is %d\n",values[1]); // using array notation
    printf("last element is %d\n",*(values+9)); // using pointer notation
    /* array is passed to the function using its name only as the actual argument */
    printf("sum total: %d\n",sum_array(values,SIZE)); // same as pointer
    printf("sum total: %d\n",sum_pointer(values,SIZE)); // same as array
    return 0;
}
/* including modifier ``const`` informs the compiler that the formal arguments are read-only (safe) */
int sum_array(const int collection[], const int no_els) // collection pointer first
{
    int s=0; // local return value
    for (int i=0;i<no_els;i++)
        s+=*(collection+i); // using pointer notation
        // s+=collection[i]; // using array notation
    return s;
}
int sum_pointer(int* a, int n) // a pointer first
{
    /* total sum of array elements passed by caller ``main`` is distorted (should use modifier ``const``) */
    int s=0;
    n=9; // changing array size
    a[0]=10; // change first element
    *(a+1)=20; // change second element
    for (int i=0;i<n;i++)
        s+=*(a+i);
    return s;
}
