#include "main.h"

/**
 * main - entry point
 *
 * Return: 0 on success, 1 on error
 */
int main(void)
{
	char *path_var = get_path_variable();
	shell_loop(path_var);
	free(path_var);
	return (0);
}
