#include "shell.h"

/**
 * process_input - function to extract tokens from the input string
 * and separates it into different parts
 * @input: input
*/

void process_input(char *input)
{
	char *command_with_args[MAX_ARGS]; /*Array to hold command and arguments*/
	int i = 0; /* variables */
	const char delim[] = " \t\n"; /* Delimiters for tokenization */
	char *tok = strtok(input, delim); /* Get the first token */

	while (tok != NULL && i < MAX_ARGS - 1)
	{
		command_with_args[i++] = tok; /* Store the token in the array */
		tok = strtok(NULL, delim); /* Get the next token */
	}
	command_with_args[i] = NULL; /* NULL-terminate the array */

	_execute(command_with_args); /* Execute the command with arguments */
}
