#include "main.h"

/**
 * _strlen - returns the length of a string
 * @str: string to be evaluated
 * Return: length of string
 */
int _strlen(char *str)
{
	int i = 0;

	while (str[i] != '\0')
		i++;

	return (i);
}


/**
 * _puts - prints a string without a new line symbol
 * @str: string to be printed
 * Return: void
 */
void _puts(char *str)
{
	unsigned int length;

	length = _strlen(str);

	write(STDOUT_FILENO, str, length);
}

/**
 * _strcmp - compares 2 strings if they are exactly the same
 * @s1: first string to be compared
 * @s2: second string to be compared
 *
 * Return: 1 if strings are equal, otherwise -1
 */
int _strcmp(char *s1, char *s2)
{
	unsigned int i = 0;

	if (_strlen(s1) != _strlen(s2))
		return (-1);

	while (s1[i] != '\0' && s2[i] != '\0')
	{
		if (s1[i] != s2[i])
			return (-1);
		i++;
	}
	return (1);
}
