#include "main.h"

/**
 * shell_execute - prompt to execute shell
 * @args: argument passed
 *
 *  Return: Always 0
 */

int shell_execute(char **args)
{
	int i = 0;
	built_in_command built_in_commands[] = {
		{ "cd", shell_cd },
		{ "exit", shell_exit },
		{ "env", shell_env},
		{ NULL, NULL }
	};

	if (args[0] == NULL)
		return (1);
	for (i = 0; built_in_commands[i].name != NULL; i++)
		if (_strcmp(args[0], built_in_commands[i].name) == 1)
			return (built_in_commands[i].func(args + 1));
	return (1);
}
/**
 * exec_process - execute the command
 *@arg: arguments
 *
 * Return: void
 */
void exec_process(char **arg)
{
	char *path_cmd = NULL, *path = NULL;
	pid_t pid;
	char *envp[] = {NULL};

	path = get_path_variable();
	path_cmd = _find_cmd_path(path, arg[0]);
	if (path_cmd)
	{
		pid = fork();
		if (pid < 0)
			_perror(ERR_FORK);
		else if (pid == 0)
			execve(path_cmd, arg, envp);
		else
			wait(NULL);
		free(path);
	}
	else
	{
		free(path);
		_perror(ERR_PATH);
	}
	free(arg);
}
/**
 * _atoi - converts a string to an integer
 * @s: the string to be converted
 * Return: 0 if no numbers in string, converted number otherwise
 *       -1 on error
 */
int _atoi(char *s)
{
	int i = 0;
	unsigned long int result = 0;

	if (*s == '+')
		s++;
	for (i = 0;  s[i] != '\0'; i++)
	{
		if (s[i] >= '0' && s[i] <= '9')
		{
			result *= 10;
			result += (s[i] - '0');
			if (result > INT_MAX)
				return (-1);
		}
		else
			return (-1);
	}
	return (result);
}

