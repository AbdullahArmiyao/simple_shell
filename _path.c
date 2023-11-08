#include "shell.h"

/**
 * _path - function to handle the path
 * @command: command
 * Return: result
*/

char *_path(char *command)
{
	char *path = "/usr/bin:/bin";  /* PATH  */
	char *path_copy = strdup(path);  /* PATH  */
	char *dir = strtok(path_copy, ":");
	char *result = NULL;

	if (command == NULL)
		return (result);
	while (dir != NULL)/* Iterating through each directory in PATH */
	{
		size_t dir_len = strlen(dir);  /* Calculate length of directory path*/
		size_t cmd_len = strlen(command); /*Calculate length of the command*/
		/*
			* Allocate memory for the full path by considering
			* the directory and command length, 1 for '/' and 1 for '\0'
		*/
		char *full_path = malloc(dir_len + 1 + cmd_len + 1);

		if (full_path == NULL)
		{
			free(path_copy);
			return (NULL);  /*Return NULL if malloc fails*/
		}
		/*Construct the full path by appending the directory and the command*/
		strcpy(full_path, dir);  /*Copy directory path to full path string*/
		full_path[dir_len] = '/';  /*Add '/' between directory and command*/
		strcpy(full_path + dir_len + 1, command); /*Append command after '/'*/
		/*Check if the command is executable within the current directory*/
		if (access(full_path, X_OK) != -1)
		{
			result = full_path;
			break;
		}
		else
		{
		/*Free the memory allocated for full_path if the command is not found*/
			free(full_path);
		}
		dir = strtok(NULL, ":");  /*Move to the next directory in the PATH*/
	}
	free(path_copy);
	return (result); /*Return NULL if the command is not found in any directory*/
}
