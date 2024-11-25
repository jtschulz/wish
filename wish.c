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

            // ==BUILT=IN=COMMANDS==

            // exit
            if (strcmp(input,"exit") == 0)
                exit(0);
            
            // cd & path
            char* found = 0;

            // flags to determine which in built command is being triggered
            int cd_flag = 0;
            int path_flag = 0;

            // increments for each arg
            int arg_count = 0;

            // stores path where changing dir to
            char * cd_path;


            // max size commands can be
            size_t max_size;
            char* pwd;


            max_size = strlen(input) + 1;

            // stores PATH values being passed
            char * path[max_size];
            // char * path[max_size][max_size];
            
            cd_path = malloc(sizeof(*cd_path) * max_size);

            // path[0] = "hello";
            // path[1] = "world";

            // puts(path[0]);
            // how do i know what size to make an array of strings to store each different path value?
            // i could make it way too big to start? ?

            // path = malloc(sizeof(*path) * max_size);


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
                } else if (path_flag == 1){
                    path[arg_count - 2] = found;
                }

                if (strcmp("cd", found) == 0){
                    cd_flag = 1;
                }else if (strcmp(found, "path") == 0){
                    path_flag = 1;
                }
            }


            if (cd_flag == 1){
                chdir(cd_path);
                pwd = get_current_dir_name();
                printf("current directory: %s\n", pwd);
            }

            if (path_flag == 1){
                puts("==PATH==");
                for (int i = 0; i < arg_count - 1; i++){
                    puts(path[i]);
                }
            }



            
        }

      return 0;
    }

// == fedora usage ==
//  gcc -o wish wish.c -Wall -Werror -lreadline

