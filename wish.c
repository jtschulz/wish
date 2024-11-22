    #include <stdio.h>
    #include <string.h>
    #include <stdlib.h>
    #include <readline/readline.h>
    #include <readline/history.h>
    
    int main()
    {

        char *input;
        while (1){

            // puts("wish> ");
            input = readline("wish>");

            if (strcmp(input,"exit") == 0)
                exit(0);
            else
                puts(input);
        }

      return 0;
    }

// == fedora usage ==
//  gcc -o wish wish.c -Wall -Werror -lreadline                                                                                                                             ░▒▓ ✔  ≡  03:42:01 PM ▓▒░

