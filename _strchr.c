#include "shell.h"

/**
 * _strchr - locates the first occurrence of a character in a string
 * @str: input string
 * @c: character to find in the string
 *
 * Return: Pointer to the first occurrence of the character in the
 * string or NULL if not found
 */
char *_strchr(const char *str, int c)
{
	while (*str != '\0')
	{
		if (*str == c)
		return ((char *)str);
	str++;
	}

	if (c == '\0')
	return ((char *)str);

	return (NULL);
}
