#include "main.h"

/**
 * _perror- print error message
 * @error: error
 * Return: void
 */
void _perror(int error)
{
	switch (error)
	{
		case ERR_MALLOC:
		write(STDERR_FILENO, ERR_MALLOC_MESSAGE, _strlen(ERR_MALLOC_MESSAGE));
		break;
		case ERR_FORK:
		write(STDERR_FILENO, ERR_FORK_MESSAGE, _strlen(ERR_FORK_MESSAGE));
		perror("Error");
		break;
		case ERR_PATH:
		write(STDERR_FILENO, ERR_PATH_MESSAGE, _strlen(ERR_PATH_MESSAGE));
		break;
		default:
		return;
	}
}
