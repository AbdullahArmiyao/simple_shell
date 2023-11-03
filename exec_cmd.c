#include "shell.h"

/**
 * exec_cmd - function responsible for the execution of the command
*/

void exec_cmd(char *input)
{
    /* call the fork system call */
    pid_t pid = fork();
    /* if there is no command, return */
    if (input[0] == '\0')
        return;
    /* if fork fails, print the error message */
    if (pid == -1)
        perror("fork");
    else if (pid == 0)
    {
        /* begin child process */
        char *arguments[2];
        arguments[0] = input;
        arguments[1] = NULL;
        /* if the command fails with execve, print error message*/
        if (execve(input, arguments, NULL) == -1)
        {
            perror("execve");
        }
        /* exit child process */
        exit(EXIT_FAILURE);
    }
    else
    {
        /* initialze parent process */
        int status;
        waitpid(pid, &status, 0);
    }


}
