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
	default:
		if (_putchar('%') < 0)
			return -1;
		counter = _putchar(*ptr);
		if (counter > 0)
			counter++;
	}
	return (counter);
}
