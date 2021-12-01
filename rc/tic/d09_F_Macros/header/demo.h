/* define symbolic constants such as number of elements in an array */
#ifndef DEMO_H_
#define DEMO_H_
/* replaces all occurences of the macro within the source file with its macro expansion */
#define START int main(int argc, char *argv[])
#define BEGIN {
#define END } 
#define IN_FORMAT "%d" 
#define OUT_FORMAT "You entered the number %d\n"
#define PRINT printf 
#define DO do
#define INPUT scanf 
#define THEN )
#define IF if(
#define WHILE while
#define RETURN return
#endif
