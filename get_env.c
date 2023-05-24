#include "main.h"

/**
<<<<<<< HEAD
 * _getenv - return PATH
 * @var: environment variable to get
 * Return:  PATH environment variable
 */

=======
 * get_path_variable - return PATH
 *
 * Return:  PATH environment variable
 */
>>>>>>> a55a477274a38fe51e2fb1670b5d959c0e1bd81b
char *_getenv(char *var)
{
	int j, length, i = 0;
	char *path, *path_var = NULL;
	char **environ_copy = duplicate_environ();

	var = _concat_strings(var, "=", "");
	length = _strlen(var);
<<<<<<< HEAD
=======

>>>>>>> a55a477274a38fe51e2fb1670b5d959c0e1bd81b
	while (environ_copy[i] != NULL)
	{
		if (_strncmp(environ_copy[i], var, length) == 1)
		{
<<<<<<< HEAD
		path_var = environ_copy[i] + length;	
		path = malloc(_strlen(path_var) + 1);
			if (path == NULL) 
=======
			path_var = environ_copy[i] + length;
			path = malloc(_strlen(path_var) + 1);
			if (path == NULL)
>>>>>>> a55a477274a38fe51e2fb1670b5d959c0e1bd81b
			{
				_perror(ERR_MALLOC);
				return (NULL);
			}
			path = _strcpy(path, path_var);
<<<<<<< HEAD
			for (j = 0; environ_copy[j] != NULL; j++) 
=======
			for (j = 0; environ_copy[j] != NULL; j++)
>>>>>>> a55a477274a38fe51e2fb1670b5d959c0e1bd81b
				free(environ_copy[j]);
			return (path);
		}
		i++;
	}
	return (NULL);
}
