#include "main.h"

/**
 * get_path_variable - return PATH
 *
 * Return:  PATH environment variable
 */
char *_getenv(char *var)
{
	int j, length, i = 0;
	char *path, *path_var = NULL;
	char **environ_copy = duplicate_environ();

	var = _concat_strings(var, "=", "");
	length = _strlen(var);

	while (environ_copy[i] != NULL)
	{
		if (_strncmp(environ_copy[i], var, length) == 1)
		{
			path_var = environ_copy[i] + length;
			path = malloc(_strlen(path_var) + 1);
			if (path == NULL)
			{
				_perror(ERR_MALLOC);
				return (NULL);
			}
			path = _strcpy(path, path_var);
			for (j = 0; environ_copy[j] != NULL; j++)
				free(environ_copy[j]);
			return (path);
		}
		i++;
	}
	return (NULL);
}
