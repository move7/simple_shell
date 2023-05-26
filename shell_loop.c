#include "main.h"

/**
 * shell_loop - loop for shell
 *
 * Return: void
 */
void shell_loop(void)
{
	char *input, *envp[] = {NULL}, **tokens = NULL, *path_cmd, *path = NULL;
	int statut;
	pid_t pid;

	while (1)
	{
		display_prompt();
		input = read_line();
		tokens = get_arguments(input);
		statut = shell_execute(tokens);
		path = get_path_variable();
		if (statut == -1)
		{
			free_all(tokens, path, input);
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
					execve(path_cmd, tokens, envp);
				else
					wait(NULL);
				if (tokens[0][0] != '/')
					free(path_cmd);
			}
			else
				_perror(ERR_PATH);
		}
		free_all(tokens, path, input);
	}
}
