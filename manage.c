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
	int counter;

	switch (*ptr)
	{
	case 'c':
		counter = _putchar(va_arg(args, int));
		break;
	case 's':
		counter = print_str(va_arg(args, char *));
		break;
	case '%':
		counter = _putchar('%');
		break;
	case 'd':
	case 'i':
		counter = print_num((long)va_arg(args, int), 10);
		break;
	case 'x':
		counter = print_hex((long)va_arg(args, unsigned int), 16);
		break;
	case 'X':
		counter = print_HEX((long)va_arg(args, unsigned int), 16);
		break;
	case 'o':
		counter = print_num((long)va_arg(args, unsigned int), 8);
		break;
	case '\0':
		return (-1);
	default:
		if (_putchar('%') < 0)
			return (-1);
		counter = _putchar(*ptr);
		if (counter > 0)
			counter++;
	}
	return (counter);
}
