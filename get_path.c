#include "main.h"

/**
 * get_path_variable - return PATH
 * 
 * Return:  PATH environment variable
 */
char *get_path_variable() {
    int i = 0;
    while (environ[i] != NULL) {
        
        if (_strncmp(environ[i], "PATH=", 5) == 1) {
            return environ[i] + 5;  
        }
        i++;
    }
    return NULL; 
}


/**
 * _find_cmd_path - return PATH
 * @path: full path
 * @cmd: command to be searcher
 * Return:  PATH environment variable
 */
char *_find_cmd_path(char *path, char *cmd)
{
    char *token, *path_tmp, *separator = ":";
    struct stat st;

    if(cmd[0] == '/')
    {
        if(stat(cmd, &st) == 0 )
            return (cmd);
        else 
            _perror(ERR_PATH);

    }
        

    
        token = strtok(path,separator);
    while (token)
    {
        path_tmp = _concat_strings(token,"/",cmd);

        if (stat(path_tmp, &st) == 0 && st.st_mode & S_IXUSR) {
            return path_tmp;
        }
        free(path_tmp);
        token = strtok(NULL,separator);
    }   
    return (NULL);
}