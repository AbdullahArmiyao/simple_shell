#ifndef SIM_SHELL_H
#define SIM_SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

#define BUFF_SIZE 300

void disp_prompt();
void exec_cmd(char *input);
int main();

#endif
