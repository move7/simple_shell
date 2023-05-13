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
//------tools.c
int _strlen(char *s);
void _puts(char *str);
void display_prompt(void);
char *read_line(void);
char **get_arguments(char *str);
#endif