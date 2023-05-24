#include "main.h"

/**
*shell_cd - changes the directory
*@args: argument to pass
 **Return: 1
**/
int shell_cd(char **args)
{
	char *home = _getenv("HOME");
	char *oldpwd = _getenv("PWD");
	char cwd[1024];
	char *dir = args[0];

	printf("dir = %s\n", home);
	printf("dir = %s\n", oldpwd);
	if (dir == NULL || _strcmp(dir, "~") == 1)
	{
		if (home == NULL)
		{
			_perror(ERR_HOME);
			return (-2);
		}
		dir = home;
	}
	else if (_strcmp(dir, "-") == 1)
	{
		if (oldpwd == NULL)
		{
			_perror(ERR_OLD_PWD);
			return (-2);
		}
		dir = oldpwd;
	}
	else if (getcwd(cwd, _strlen(cwd)) == NULL)
	{
		_perror("getcwd");
		return (-2);
	}
	else if (setenv("OLDPWD", cwd, 1) == -1)
	{
		_perror("setenv");
		return (-2);
	}
	else if (chdir(dir) == -1)
	{
		_perror("chdir");
		return (-2);
	}
	else if (getcwd(cwd, _strlen(cwd)) == NULL)
	{
		_perror("getcwd");
		return (-2);
	}
	else if (setenv("PWD", cwd, 1) == -1)
	{
		_perror("setenv");
		return (-2);
	}
	return (0);
}

/**
**shell_exit - exits the shell
**@var: the source string
 **Return: 0
**/
int shell_exit(char __attribute__((__unused__)) **var)
{
	return (-1);
}

/**
**shell_env - prints environment
**@var: the string enviroment
**Return: void
**/

int shell_env(char __attribute__((__unused__)) **var)
{
	unsigned int i;

	i = 0;
	while (environ[i] != NULL)
	{
		write(STDOUT_FILENO, environ[i], _strlen(environ[i]));
		write(STDOUT_FILENO, "\n", 1);
		i++;
	}
	return (0);
}
