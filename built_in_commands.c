#include "main.h"

/**
*shell_cd - changes the directory
*@args: argument to pass
 **Return: 1
**/
int shell_cd(char **args)
{
	char *home = _getenv("HOME"), *oldpwd = _getenv("PWD"), cwd[1024];
	char *dir = args[0];

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
	if (getcwd(cwd, _strlen(cwd)) == NULL)
	{
		perror("getcwd");
		return (-2);
	}
	if (setenv("OLDPWD", cwd, 1) == -1)
	{
		perror("setenv");
		return (-2);
	}
	if (chdir(dir) == -1)
	{
		perror("chdir");
		return (-2);
	}
	if (getcwd(cwd, _strlen(cwd)) == NULL)
	{
		perror("getcwd");
		return (-2);
	}
	if (setenv("PWD", cwd, 1) == -1)
	{
		perror("setenv");
		return (-2);
	}
	return (0);
}

/**
**shell_exit - exits the shell
**@arg: the source string
**Return: -1 or 1
**/
int shell_exit(char **arg)
{

	int check;

	if (arg[1])
	{
		check = _atoi(arg[1]);
		if (check == -1)
		{
			perror("Illegal number: ");
			return (-2);
		}
		return (-1);
	}
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
