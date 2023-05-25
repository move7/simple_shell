#include "main.h"
/**
 * free_all - frees all malloc'd space at end of main loop
 * @tokens: pointer to tokens array
 * @path: pointer to path variable
 * @input: pointer to user input buffer
 * @fullpath: pointer to full path
 * @flag: flag marking if full_path was malloc'd
 * Return: void
 */
void free_all(char **tokens, char *path, char *input, char *fullpath, int flag)
{
	free(path);
	free(tokens);
	free(input);
	if (flag == 1)
		free(fullpath);
}
