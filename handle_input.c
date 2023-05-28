#include "main.h"

/**
 *read_line- get input from user
 *
 *Return: buffer with input
 */
char *read_line(void)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t nread;

	fflush(stdout);
	nread = getline(&line, &len, stdin);
	if (nread == EOF || nread == -1)
	{
		free(line);
		exit(EXIT_SUCCESS);
	}
	remove_comments(line);
	if (line[nread - 1] == '\n')
		line[nread - 1] = '\0';
	return (line);
}

/**
 * get_arguments- array of parameters
 * @str: user input
 * Return: array of arg
 */
char **get_arguments(char *str)
{
	char *token;
	int i = 0;
	char **tokens = (char **)malloc(BUFFER * sizeof(char));
	
	if (tokens == NULL)
	{
		_perror(ERR_MALLOC);
		return (NULL);
	}
	i = 0;
	token = strtok(str, SEPARATORS);
	while (token != NULL)
	{
		tokens[i] = token;
		token = strtok(NULL, SEPARATORS);
		i++;
	}
	tokens[i] = NULL;
	return (tokens);
}
/**
 * remove_comments - remove comments by replacing '#' with '\0'
 * @input: address of the string to modify
 *
 * Return: Always 0;
 */
void remove_comments(char *input)
{
	int i;

	for (i = 0; input[i] != '\0'; i++)
	{
		if (input[i] == '#' && (!i || input[i - 1] == ' '))
		{
			input[i] = '\0';
			break;
		}
	}
}
