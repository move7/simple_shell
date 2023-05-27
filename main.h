#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <limits.h>

#define BUFFER 1024
#define PROMPT "(shell)$ "
#define SEPARATORS " \t\n\r"
extern char **environ;
/* errors definition */
#define ERR_MALLOC 1
#define ERR_FORK 2
#define ERR_PATH 3
#define ERR_HOME 4
#define ERR_OLD_PWD 5

#define ERR_MALLOC_MESSAGE "Unable to malloc space\n"
#define ERR_FORK_MESSAGE  "Unable to fork and create child process\n"
#define ERR_PATH_MESSAGE  "No such file or directory\n"
#define ERR_HOME_MESSAGE "HOME environment variable is not set\n"
#define ERR_OLD_PWD_MESSAGE "OLD environment variable is not set\n"
/**
 * struct built_in_command - linked list of built-in commands
 * @name: name of command
 * @func: pointer to function
 *
 * Description: struct for built-in functions.
 */
typedef struct built_in_command
{
	char *name;
	int (*func)(char **args);
} built_in_command;

/*------------------------tools.c ------*/
int _strlen(char *s);
void _puts(char *str);
int _strcmp(char *s1, char *s2);
int _strncmp(char *s1, char *s2, unsigned int n);
char *_strncpy(char *dest, char *src, unsigned int n);
char *_strcpy(char *dest, char *src);
char *_concat_strings(char *s1, char *s2);
char *_strtok(char *line, char *delim);

/*------------------------display_prompt.c -----*/
void display_prompt(void);

/*-----------------------------handl_input.c -----*/
char *read_line(void);
char **get_arguments(char *str);
void remove_comments(char *input);

/*-----------------------------built_in_commands.c -----*/
int shell_cd(char **dir);
int shell_exit(char __attribute__((__unused__)) **var);
int shell_env(char __attribute__((__unused__)) **var);

/*-----------------------------handl_exec.c -----*/
int shell_execute(char **args);
void exec_process(char **arg);
int _atoi(char *s);

/*-----------------------------get_path -----*/
char *get_path_variable();
char *_find_cmd_path(char *path, char *cmd);
char **duplicate_environ();
int is_cmd(char *path);

/*-----------------------------handle_errors -----*/
void _perror(int error);

/*-----------------------------get_env -----*/
char *_getenv(char *var);

void free_all(char **tokens, char *input);

void shell_loop(void);/*(char *path_var);*/
#endif
