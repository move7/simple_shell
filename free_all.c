#include "main.h"
/**
 * free_all - frees all malloc'd space at end of main loop
 * @tokens: pointer to tokens array
 * @path: pointer to path variable
 * @input: pointer to user input buffer
 * Return: void
 */
void free_all(char **tokens, char *input)
{
	free(tokens);
	free(input);
}
