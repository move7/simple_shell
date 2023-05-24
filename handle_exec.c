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
	built_in_command built_in_commands[] = { BUILT_IN_COMMANDS };

	if (args[0] == NULL)
		return (1);
	for (i = 0; built_in_commands[i].name != NULL; i++)
		if (_strcmp(args[0], built_in_commands[i].name) == 1)
			return (built_in_commands[i].func(args + 1));
	return (1);
}
