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
	char *token;
	int i = 0;
	
	char **tokens = (char **)malloc(BUFFER*sizeof(char));
	if( tokens == NULL)
	{
		_perror(ERR_MALLOC);
		return (NULL);
	}
	i = 0;
	token = strtok(str,SEPARATORS);
	
	while (token!= NULL)
	{
		tokens[i]=token;
		token = strtok(NULL,SEPARATORS);
		i++;
	}
	tokens[i]=NULL;
	return(tokens);
  
}