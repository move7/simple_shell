#include "main.h"

/**
 *read_line- get input from user
 *
 *Return: buffer with input
 */
char *read_line(void)
{
	char *line;
	size_t len = 0;
	ssize_t nread;
<<<<<<< HEAD
	
	nread = getline(&line, &len, stdin);
=======

	nread = getline(&line, &len, stdin);

>>>>>>> a55a477274a38fe51e2fb1670b5d959c0e1bd81b
	if (nread == EOF || nread == -1)
		exit(EXIT_SUCCESS);
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
<<<<<<< HEAD
	
=======

>>>>>>> a55a477274a38fe51e2fb1670b5d959c0e1bd81b
	if (tokens == NULL)
	{
		_perror(ERR_MALLOC);
		return (NULL);
	}
<<<<<<< HEAD
	i = 0;
	token = _strtok(str, SEPARATORS);
	
	while (token != NULL)
	{
		tokens[i] = token;
		token = _strtok(NULL, SEPARATORS);
=======
	token = strtok(str, SEPARATORS);
	while (token != NULL)
	{
		tokens[i] = token;
		token = strtok(NULL, SEPARATORS);
>>>>>>> a55a477274a38fe51e2fb1670b5d959c0e1bd81b
		i++;
	}
	tokens[i] = NULL;
	return (tokens);
}
