#include "shell.h"

/**
 * main - main function to run shell
 * Return: 0 on success
*/

int main(void)
{
	char buffer[BUFF_SIZE];

	while (1)
	{
		_prompt();

		if (fgets(buffer, BUFF_SIZE, stdin) == NULL)
		{
			printf("\n");
			break;
		}


		buffer[strcspn(buffer, "\n")] = '\0';
		process_input(buffer);
	}

	return (0);
}
