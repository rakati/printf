#include "main.h"

/**
 * check_type - check specifier type and call the function that print it,
 * otherwise return -1 on error.
 *
 * @ptr: pointer to the next character following percentage.
 * @args: list of variadic arguments.
 *
 * Return: number of characters printed otherwise -1 on error.
 */
int check_type(char *ptr, va_list args)
{
	int counter = 0;

	switch (*ptr)
	{
	case 'c':
		counter += _putchar(va_arg(args, int));
		break;

	case 's':
		counter += print_str(va_arg(args, char *));
		break;
	case '%':
		counter += _putchar('%');

	default:
		return (-1);
	}

	return (counter);
}

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
	char *str = s;

	if (s == NULL)
		return (-1);

	while (*str)
	{
		len++;
		str++;
	}

	return (write(1, s, len));
}

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
