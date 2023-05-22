#include "main.h"

/**
 * _perror- print error message
 * @error: error
 * Return: void
 */
void _perror(char *error)
{
	
    if(error)
       {
        write(STDERR_FILENO, error, _strlen(error));
       } 
	perror("Error");    
  
}