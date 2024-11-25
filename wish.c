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
            
            // stores current token while iterating over user input
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

            // stores non built-in commands
            char * commands[max_size];
            
            cd_path = malloc(sizeof(*cd_path) * max_size);


            // NEXT WE NEED TO BE ABLE TO SEARCH PATH FOR USER COMMANDS
            // access("/bin/ls", X_OK)

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
                    // clear path here
                    for (int i = 0; i < sizeof(path)/sizeof(path[0]); i++){
                        path[i] = "";
                    }
                }

                if (!cd_flag & !path_flag){
                    // regular command
                    commands[arg_count - 2] = found;
                }

            }


            if (cd_flag == 1){
                chdir(cd_path);
                pwd = get_current_dir_name();
                printf("current directory: %s\n", pwd);
            } else if (path_flag == 1){
                puts("==PATH==");
                for (int i = 0; i < arg_count - 1; i++){
                    puts(path[i]);
                }
            }else{
                // user put in non built in command
                for (int i = 0; i < arg_count - 1; i++){
                    if (strcmp(commands[i], "&")){
                        continue;
                    }else if (path_flag != 1){
                        // path was never set so no non built-in commands can be run
                        break;
                    }
                    for (int j = 0; j < sizeof(path)/sizeof(path[0]); j++){
                        if (access(path[j], *commands[i]) == 0){
                            // command is good
                            puts("command is good!");
                        }
                    }

                }
            }



            
        }

      return 0;
    }

// == fedora usage ==
//  gcc -o wish wish.c -Wall -Werror -lreadline

