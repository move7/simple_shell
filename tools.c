#include "main.h"

/**
 * _strlen - returns the length of a string
 * @str: string to be evaluated
 * Return: length of string
 */
int _strlen(char *str)
{
	int i = 0;

	while (str[i] != '\0')
		i++;

	return (i);
}


/**
 * _puts - prints a string without a \n
 * @str: string to be printed
 * Return: void
 */
void _puts(char *str)
{
	unsigned int length;

	length = _strlen(str);

	write(STDOUT_FILENO, str, length);
}

/**
 *prompt - prints the shell prompt
 *
 *Return: void
 */
void display_prompt(void)
{
	_puts(PROMPT);
}

/**
 *read_line- get input from user
 *
 *Return: buffer with input
 */
char *read_line(void)
{
	char *line;//[BUFFER];
    size_t len = 0;
    ssize_t nread;

    nread = getline(&line, &len, stdin);
	if (nread == EOF || nread == -1)
		exit(EXIT_SUCCESS);
    
	return(line);
}
/**
 * get_arguments- array of parameters
 * @str: user input
 * Return: array of arg
 */
char **get_arguments(char *str)
{
	char *token, *separator = " ";
	int i = 0;

	token = strtok(str,separator);
	while (strtok(NULL,separator))
		i++;
	
	char **tokens = (char **)malloc((i+2)*sizeof(char*));
	token = strtok(str,separator);
	while (token)
	{
		token = strtok(NULL,separator);
	}
	
}