    #define _GNU_SOURCE
    #include <stdio.h>
    #include <string.h>
    #include <stdlib.h>
    #include <readline/readline.h>
    #include <readline/history.h>
    #include <unistd.h>
    
    int main()
    {

        char *input;
        while (1){
            
            input = readline("wish>");

            // strsep mutates original string

            // built in commands

            // exit
            if (strcmp(input,"exit") == 0)
                exit(0);
            
            // cd & path
            char* found = 0;
            int cd_flag = 0;
            int path_flag = 0;
            int arg_count = 0;
            char * cd_path;
            size_t max_size;
            char* pwd;
            // size_t max_path_size = strlen("/home/mia_bobia/Documents/wish/test_dir/other_dir") + 1;

            max_size = strlen(input) + 1;
            cd_path = malloc(sizeof(*cd_path) * max_size);

            while((found = strsep(&input," ")) != NULL){
                arg_count++;

                if (cd_flag == 1){
                    if (arg_count > 2){
                        puts("invalid amount of args. usage: cd <path>");
                        readline("press any key to exit..");
                        exit(0);
                    }else{
                        puts("copying str");
                        // correct arg here
                        strcpy(cd_path, found);
                        puts("finished copying");
                    }
                }
                else if (path_flag == 1){

                }

                puts("comparing found");
                if (strcmp("cd", found) == 0){
                    cd_flag = 1;
                }else if (strcmp(found, "path") == 0){
                    path_flag = 1;
                }
            }


            printf("attempting to change to directory: %s\n", cd_path);
            chdir(cd_path);

            pwd = get_current_dir_name();

            printf("current directory: %s\n", pwd);
            
        }

      return 0;
    }

// == fedora usage ==
//  gcc -o wish wish.c -Wall -Werror -lreadline

