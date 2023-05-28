#include "main.h"

/**
 * _getenv - return PATH
 * @var: environment variable to get
 * Return:  PATH environment variable
 */

char *_getenv(char *var)
{
	int j, length, i = 0;
	char *var_tmp, *path, *path_var = NULL;
	char **environ_copy = duplicate_environ();

	var_tmp = malloc(_strlen(var) + 2);
	if (var_tmp == NULL)
	{
		_perror(ERR_MALLOC);
		return (NULL);
	}
	_strcpy(var_tmp, var);
	_concat_strings(var_tmp, "=");
	length = _strlen(var_tmp);
	while (environ_copy[i] != NULL)
	{
		if (_strncmp(environ_copy[i], var_tmp, length) == 1)
		{
			path_var = environ_copy[i] + length;
			path = malloc(_strlen(path_var) + 1);
			if (path == NULL)
			{
				free(var_tmp);
				_perror(ERR_MALLOC);
				return (NULL);
			}
			path = _strcpy(path, path_var);
			for (j = 0; environ_copy[j] != NULL; j++)
				free(environ_copy[j]);
			free(environ_copy);
			free(var_tmp);
			return (path);
		}
		i++;
	}
	for (j = 0; environ_copy[j] != NULL; j++)
		free(environ_copy[j]);
	free(environ_copy);
	free(var_tmp);
	return (NULL);
}
