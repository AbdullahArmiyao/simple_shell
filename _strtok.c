#include "shell.h"

/**
 * _strtok - string tokenization
 * @str: string
 * @delim: delimeter
 * Return: next token
*/

char *_strtok(char *str, const char *delim)
{
    static char *token = NULL;  /* To store the position of the next token */
    static char *next_token = NULL;/*store the position of the start of token*/

    /* If a new string is given, set the position to the start */
    if (str != NULL)
    {
        token = str;
        next_token = str;
    }

    if (token == NULL)
        return NULL;

    /* Find the start of token, skipping any leading delimiters */
    next_token = token;
    while (*next_token != '\0' && _strchr(delim, *next_token) != NULL)
        next_token++;

    /* If no token is found, return NULL */
    if (*next_token == '\0')
    {
        token = NULL;
        return NULL;
    }

    /* Otherwise, find the end of the token */
    token = next_token;
    while (*token != '\0' && _strchr(delim, *token) == NULL)
        token++;

    if (*token != '\0')
    {
        *token = '\0';  /* Null-terminate the token */
        token++;  /* Move to the next character for future calls */
    }
    else
    {
        token = NULL;  /* If the end of string is reached, set token to NULL*/
    }

    return next_token;  /* Return the start of the token*/
}
