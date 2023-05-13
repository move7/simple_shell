#include "main.h"

int main()
{
    char *input;
    char ** tokens;
    int i;
    while (1) {
        display_prompt(); 
        input = read_line();     
        tokens= get_arguments(input);
        for(i=0;tokens[i];i++)
            printf("%s\n",tokens[i]);
        
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