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
    { NULL, NULL }


//------------------------tools.c
int _strlen(char *s);
void _puts(char *str);
int _strcmp(char *s1, char *s2);
int _strncmp(char *s1, char *s2, unsigned int n);

//------------------------display_prompt.c
void display_prompt(void);

//-----------------------------handl_input.c
char *read_line(void);
char **get_arguments(char *str);

//-----------------------------built_in_commands.c
int shell_cd(void);
int shell_exit(void);

//-----------------------------handl_exec.c
int shell_execute(char **args);
#endif