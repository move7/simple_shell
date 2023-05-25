#include "main.h"

/**
 * shell_loop - loop for shell
 *@path_var: path
 *
 * Return: void
 */
void shell_loop(char *path_var)
{
	char *input, *envp[] = {NULL}, **tokens = NULL, *path_cmd = NULL, *path = NULL;
	int statut;
	pid_t pid;

	while (1)
	{
		display_prompt();
		input = read_line();
		if(input == NULL)
			break;
		tokens = get_arguments(input);
		statut = shell_execute(tokens);
		path = malloc(_strlen(path_var) + 1);
		path = _strcpy(path, path_var); /*get_path_variable();*/
		if (statut == -1)
		{
			free_all(tokens, path, input, path_var, 1);
			exit(EXIT_SUCCESS);
		}
		if (statut == 1)
		{
			path_cmd = _find_cmd_path(path, tokens[0]);
			if (path_cmd)
			{
				pid = fork();
				if (pid < 0)
					_perror(ERR_FORK);
				else if (pid == 0)
				{
					execve(path_cmd, tokens, envp);
					free(path_cmd);
				}
				else
					wait(NULL);
			}
			else
				_perror(ERR_PATH);
		}
		free_all(tokens, path, input, path_var, 0);
	}
}
