#include "main.h"

/**
 *display_prompt - prints the shell prompt
 *
 *Return: void
 */
void display_prompt(void)
{
	if (isatty(STDIN_FILENO))
	_puts(PROMPT);
}
