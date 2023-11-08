#include "shell.h"

/**
 * _prompt - Function that prints prompt
*/

void _prompt(void)
{
	/**
	 * display the prompt
	*/
	write(STDOUT_FILENO, "#cisfun$ ", 10);
}
