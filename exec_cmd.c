#include "shell.h"

/**
 * _execute - function responsible for the execution of the command
 * @arguments: user input
*/

void _execute(char *arguments[])
{
	char *cmd_with_path = _path(arguments[0]);
	char *err_msg = "command not found\n";
	/* call the fork system call */
	pid_t pid = fork();
	/* if there is no command, return */
	if (arguments[0] == NULL)
	{
		write(STDERR_FILENO, err_msg, strlen(err_msg));
		return;
	}
	/* if fork fails, print the error message */
	if (pid < 0)
		perror("fork");
	else if (pid == 0)
	{
		/* begin child process */
		/* if the command fails with execvp, print error message */
		if (cmd_with_path != NULL)
		{
			if (execve(cmd_with_path, arguments, NULL) == -1)
			{
				perror("execve");
				free(cmd_with_path);
				exit(EXIT_FAILURE);/* exit child process */
			}
			free(cmd_with_path);
		}
		else
		{
			write(STDERR_FILENO, err_msg, strlen(err_msg));
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		/* initialze parent process */
		int status;
		waitpid(pid, &status, 0);
	}
}
