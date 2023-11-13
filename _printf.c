#include "main.h"

/**
 * _printf - printf formatted string.
 *
 * @format: formatted string
 *
 * Return: number of characters printed
 */
int _printf(char *format, ...)
{
	va_list(args);
	int counter;
	int res;

	va_start(args, format);
	counter = 0;

	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			res = check_type(format, args);
		}
		else
			res = write(1, format, 1);
		if (res < 0)
			return (res);
		counter += res;
		format++;
	}
	va_end(args);
	return (counter);
}
