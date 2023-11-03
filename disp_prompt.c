#include "shell.h"

/**
 * disp_prompt - Function that prints prompt
*/

void disp_prompt()
{
    /**
     * display the prompt
    */
    write(STDOUT_FILENO, "#cisfun$ ", 10);
}
