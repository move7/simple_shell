#include "main.h"

/**
 * get_path_variable - return PATH
 *
 * Return:  PATH environment variable
 */
char *get_path_variable()
{
	int j, i = 0;
	char *path, *path_var = NULL;
	char **environ_copy = duplicate_environ();

	while (environ_copy[i] != NULL)
	{
		if (_strncmp(environ_copy[i], "PATH=", 5) == 1)
		{
			path_var = environ_copy[i] + 5;
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

/**
 * duplicate_environ - duplicate environ
 *
 * Return:  duplicated environ
 */
char **duplicate_environ()
{
	int i, j, num_variables = 0;
	char **environ_copy;

	while (environ[num_variables] != NULL)
	{
		num_variables++;
	}
	environ_copy = malloc((num_variables + 1) * sizeof(char *));
	if (environ_copy == NULL)
	{
		_perror(ERR_MALLOC);
		return (NULL);
	}
	for (i = 0; i < num_variables; i++)
	{
		int length = _strlen(environ[i]);

		environ_copy[i] = malloc((length + 1) * sizeof(char));
		if (environ_copy[i] == NULL)
		{
			for (j = 0; j < i; j++)
			{
				free(environ_copy[j]);
			}
			free(environ_copy);
			_perror(ERR_MALLOC);
			return (NULL);
		}
		_strcpy(environ_copy[i], environ[i]);
	}
	environ_copy[num_variables] = NULL;
	return (environ_copy);
}
/**
 * _find_cmd_path - return PATH
 * @path: full path
 * @cmd: command to be searcher
 * Return:  PATH environment variable
 */
char *_find_cmd_path(char *path, char *cmd)
{
	char *token, *path_tmp, *separator = ":";
	struct stat st;

	if (cmd[0] == '/')
	{
		if (stat(cmd, &st) == 0)
			return (cmd);
		else
			_perror(ERR_PATH);
	}
	token = _strtok(path, separator);
	while (token)
	{
		path_tmp = _concat_strings(token, "/", cmd);
		if (stat(path_tmp, &st) == 0 && st.st_mode & S_IXUSR)
		{
			return (path_tmp);
		}
		free(path_tmp);
		token = _strtok(NULL, separator);
	}
	return (NULL);
}
