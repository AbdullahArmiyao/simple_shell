#ifndef SIM_SHELL_H
#define SIM_SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_ARGS 50
#define BUFF_SIZE 300

void disp_prompt();
char *_strtok(char *str, const char *delim);
size_t _strcspn(const char *str, const char *reject);
char *_strchr(const char *str, int c);
void exec_cmd(char *arguments[]);
void process_input(char *input);

#endif
