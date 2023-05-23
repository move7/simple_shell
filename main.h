#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>

#define BUFFER 1024
#define PROMPT "(shell)$ "
#define SEPARATORS " \t\n\r"
extern char **environ;
#define ERRORS_MESSAGE { "No such file or directory\n", "Unable to malloc space\n", "Unable to fork and create child process\n" };
/* errors definition */
#define ERR_MALLOC 1
#define ERR_FORK 2
#define ERR_PATH 3

#define ERR_MALLOC_MESSAGE "Unable to malloc space\n"
#define ERR_FORK_MESSAGE  "Unable to fork and create child process\n"
#define ERR_PATH_MESSAGE  "No such file or directory\n"
/**
 * struct built_in_command - linked list of built-in commands
 * @name: name of command
 * @p: pointer to function 
 *
 * Description: struct for built-in functions.
 */
typedef struct {
    char *name;
    int (*func)(void);
} built_in_command;

#define BUILT_IN_COMMANDS \
    { "cd", shell_cd }, \
    { "exit", shell_exit }, \
    { "env", shell_env }, \
    { NULL, NULL }


/*------------------------tools.c ------*/
int _strlen(char *s);
void _puts(char *str);
int _strcmp(char *s1, char *s2);
int _strncmp(char *s1, char *s2, unsigned int n);
char *_strncpy(char *dest, char *src, unsigned int n);
char *_strcpy(char *dest, char *src);
char *_concat_strings(char* s1, char* s2, char* s3);

/*------------------------display_prompt.c -----*/
void display_prompt(void);

/*-----------------------------handl_input.c -----*/
char *read_line(void);
char **get_arguments(char *str);

/*-----------------------------built_in_commands.c -----*/
int shell_cd(void);
int shell_exit(void);
int shell_env(void);

/*-----------------------------handl_exec.c -----*/
int shell_execute(char **args);

/*-----------------------------get_path -----*/
char *get_path_variable();
char *_find_cmd_path(char *path, char *cmd);
char **duplicate_environ();

void _perror(int error);
#endif