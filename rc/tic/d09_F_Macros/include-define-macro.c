/* the preprocessor processes a ``C`` program and is modified according to preprocessor directives (read by compiler)
 * angle brackets instruct the preprocessor to search for specified files in the ``std`` directory only */
#include <stdio.h>
/* double quotes instructs the preprocessor to search only in the specified directory */
#include "./header/demo.h" //  MS  #include "c:\header\macros.h"
START BEGIN 
    int n;
    DO BEGIN 
        PRINT("Enter a number (0 to end)");
        INPUT(IN_FORMAT,&n); 
        IF n>0 THEN
            PRINT(OUT_FORMAT,n);
    END WHILE ( n>0 );
    RETURN 0;
END 
