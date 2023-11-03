#include "shell.h"

/**
 * _strcspn - finds the length of the prefix substring that does not contain characters in 'reject'
 * @str: input string
 * @reject: string containing the characters to avoid
 *
 * Return: Length of the prefix substring
 */
size_t _strcspn(const char *str, const char *reject)
{
    const char *p, *r;
    size_t count = 0;

    for (p = str; *p != '\0'; p++)
    {
        for (r = reject; *r != '\0'; r++)
        {
            if (*p == *r)
                return count;
        }
        count++;
    }

    return count;
}
