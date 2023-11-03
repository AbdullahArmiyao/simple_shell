#include "shell.h"

/**
 * exec_cmd - function responsible for the execution of the command
 * @arguments: user input
*/

void exec_cmd(char *arguments[])
{
	/* call the fork system call */
	pid_t pid = fork();
	/* if there is no command, return */
	if (arguments[0] == NULL)
		return;
	/* if fork fails, print the error message */
	if (pid == -1)
		perror("fork");
	else if (pid == 0)
	{
		/* begin child process */
		/* if the command fails with execvp, print error message*/
		if (execve(arguments[0], arguments, NULL) == -1)
		{
			perror("execve");
			/* exit child process */
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
