#include "main.h"

int main()
{
    char *input;
    char ** tokens;
    int i, statut;
    char *path = get_path_variable();
    char *path_cmd;
    //printf("%s",path);
    while (1) {
        display_prompt(); 
        input = read_line();     
        tokens= get_arguments(input);
        statut  = shell_execute(tokens);
        if (statut == -1)
            exit(EXIT_SUCCESS);
        
        if (statut == 1)
        {
            pid_t pid = fork(); 
           
        if (pid < 0) { 
            fprintf(stderr, "Fork failed.\n");
            exit(EXIT_FAILURE);
        }
        else if (pid == 0) { 
            char *envp[] = {NULL};
            
            path_cmd = _find_cmd_path(path,tokens[0]);
            //printf("ttt%s\n%s\n",path_cmd,tokens[0]);
            //execvp(tokens[0], tokens); 
            execve(path_cmd, tokens, envp);
        }
        else { 
            wait(NULL);
        }  
        }
        
        
        free(input);
    }
    return 0;
}