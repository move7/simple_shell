#include "main.h"

/**
 * _strncmp - ccompares  the first N characters
 * @s1: first string to be compared
 * @s2: second  string to be compared
 * @n: number of characters to be compared
 * Return: 1 if strings are equal, otherwise -1
 */
int _strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int i = 0;

	while (i < n)
	{
		if (s1[i] != s2[i])
			return (-1);
		i++;
	}
	return (1);
}

/**
 * *_strncpy - copies string pointed to by src to the buffer pointed to dest
 * @dest: string destination
 * @src: string source
 * @n: nuber of char to copied
 *
 * Return: the pointer to dest
 */

char *_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int i;

	for (i = 0; i <= n; i++)
		dest[i] = src[i];

	return (dest);
}

/**
 * _strcpy - copies string pointed to by src to the buffer pointed to dest
 * @dest: string destination
 * @src: string source
 * Return: the pointer to dest
 */
char *_strcpy(char *dest, char *src)
{
	int i;
	int j = _strlen(src);

	for (i = 0; i <= j; i++)
		dest[i] = src[i];

	return (dest);
}
/**
 * _concat_strings - concatanate 2 strings
 * @s1: first string to be compared
 * @s2: second string to be compared
 *
 * Return: 1 if strings are equal, otherwise -1
 */
char *_concat_strings(char *s1, char *s2)
{
	char *ret = s1;

	while (*s1)
		s1++;
	while (*s2)
		*s1++ = *s2++;
	*s1 = *s2;
	return (ret);
}

/**
 * _strtok - separates strings with delimiters
 * @line: It´s pointer to array we receive path.
 * @delim: It´s characters we mark off string in parts.
 * Return: A pointer to the created token
*/
char *_strtok(char *line, char *delim)
{
	int j;
	static char *str;
	char *copystr;

	if (line != NULL)
		str = line;
	
	for (; *str != '\0'; str++)
	{
		for (j = 0; delim[j] != '\0'; j++)
		{
			if (*str == delim[j])
			break;
		}
		if (delim[j] == '\0')
			break;
	}
	copystr = str;
	if (*copystr == '\0')
		return (NULL);
	for (; *str != '\0'; str++)
	{
		for (j = 0; delim[j] != '\0'; j++)
		{
			if (*str == delim[j])
			{
				*str = '\0';
				str++;
				return (copystr);
			}
		}
	}
	return (copystr);
}
