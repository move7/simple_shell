#include "main.h"

int main()
{
    char *input;
    char ** tokens;
    int statut;
    char *path = get_path_variable();
    char *path_cmd;
    pid_t pid;

    while (1) {
        display_prompt(); 
        input = read_line();     
        tokens= get_arguments(input);
        statut  = shell_execute(tokens);
        if (statut == -1)
            exit(EXIT_SUCCESS);
        
        if (statut == 1)
        {
            char *envp[] = {NULL};
            path_cmd = _find_cmd_path(path,tokens[0]);
            
            if(path_cmd)
            {
                pid = fork(); 
            if (pid < 0) 
                _perror(ERR_FORK);
            else if (pid == 0) 
            {printf("path = %s ", path_cmd);
                execve(path_cmd, tokens, envp);}
            else 
                wait(NULL);
            }
            
        }

        free(input);
    }
    return 0;
}