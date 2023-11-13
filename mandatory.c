#include "main.h"

/**
 * print_str - print a string and return the number of bytes written.
 *
 * @s: array of characters
 *
 * Return: number of characters printed otherwise -1 on error.
 */
int print_str(char *s)
{
	int len = 0;

	if (s == NULL)
		s = "(null)";

	while (s[len])
		len++;
	return (write(1, s, len));
}

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(int c)
{
	return (write(1, &c, 1));
}
