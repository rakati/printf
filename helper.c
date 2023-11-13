#include "main.h"

/**
 * check_type - check specifier type and called function that print the type,
 * otherwise return -1 if type not supported
 *
 * @ptr: pointer to the next character following percentage.
 * @arg: list of variadic arguments.
 *
 * Description:
 * - use switch case to find if specifier is supported or not
 * 		- if specifier supported call function that print the specifier type
 * 		  ex (s: call print_str, d: call print_int ...) and return number of
 * 			characters printed by the called function
 * 		- return -1 if specifier not supported (found r).
 *
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

	default:
		return (-1);
	}

	return (counter);
}

/**
 * print_str - print a string and return the number of bytes written.
 * if str is NULL, return -1.
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

/*
   int counter = 0;
   while (*s != '\0')
   {
	counter += print_char((int)*s);
	s++;
	}

	return (counter); */

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
