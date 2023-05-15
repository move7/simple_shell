#include "main.h"

int main()
{
    char *input;
    char ** tokens;
    int i, statut;
    while (1) {
        display_prompt(); 
        input = read_line();     
        tokens= get_arguments(input);
        statut  = shell_execute(tokens);
        if (statut == -1)
            exit(EXIT_SUCCESS);
        
        pid_t pid = fork(); 
        
        if (pid < 0) { 
            fprintf(stderr, "Fork failed.\n");
            exit(EXIT_FAILURE);
        }
        else if (pid == 0) { 
            execvp(tokens[0], tokens); 
        }
        else { 
            wait(NULL);
        }
        free(input);
    }
    return 0;
}