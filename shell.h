#ifndef SIM_SHELL_H
#define SIM_SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

#define MAX_ARGS 100
#define BUFF_SIZE 300

/**
 * char *_strtok(char *str, const char *delim);
 * size_t _strcspn(const char *str, const char *reject);
 * char *_strchr(const char *str, int c);
 */

void _prompt(void);
void _execute(char *arguments[]);
void process_input(char *input);
char *_path(char *command);

#endif
