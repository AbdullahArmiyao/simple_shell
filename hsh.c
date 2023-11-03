#include "shell.h"

/**
 * main - main function to run shell
 *
 * @argc: argument count
 * @argv: argument vector
 *
 * Return: 0 on success
*/

int main()
{
    char buffer[BUFF_SIZE];

    while (1)
    {
        disp_prompt();

        if (fgets(buffer, BUFF_SIZE, stdin) == NULL)
        {
            printf("\n");
            break;
        }

        buffer[_strcspn(buffer, "\n")] = '\0';
        process_input(buffer);
    }

    return (0);
}
