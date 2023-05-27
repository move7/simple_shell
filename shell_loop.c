#include "main.h"

/**
 * shell_loop - loop for shell
 *
 * Return: void
 */
void shell_loop(void)
{
	char *input, **tokens = NULL;
	int statut;
	/*
	 * pid_t pid;
	 * struct stat st; *envp[] = {NULL},
	 */

	while (1)
	{
		display_prompt();
		input = read_line();
		if (_strcmp(input, "") == 1)
		{
			free(input);
			continue;
		}
		tokens = get_arguments(input);
		statut = shell_execute(tokens);
		if (statut == -1)
		{
			free_all(tokens, input);
			exit(EXIT_SUCCESS);
		}
		if (statut == 1)
			exec_process(tokens);
		else
			free(tokens);
		free(input);
	}
}
