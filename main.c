#include "main.h"

int main()
{
    pid_t parent_pid = getpid();
    char *input;

    while (1) {
        display_prompt(); 
        input = read_line();     
        input[strlen(input) - 1] = '\0';
        
        
      
        pid_t pid = fork(); 
        
        if (pid < 0) { 
            fprintf(stderr, "Fork failed.\n");
            exit(EXIT_FAILURE);
        }
        else if (pid == 0) { 
            char *args[] = {input, NULL}; 
            execvp(args[0], args); 
        }
        else { 
            wait(NULL);
        }
    }
    return 0;
}