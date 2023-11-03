#include "shell.h"

/**
 * pnt_err_mess - Function that prints error message
*/

void disp_prompt()
{
    /**
     * display the prompt
    */
    write(STDOUT_FILENO, "#cisfun$ ", 10);
}
