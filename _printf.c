#include "main.h"

/**
 * _printf - printf formatted string.
 *
 * @format: formatted string
 *
 * Return: number of characters printed
 */
int _printf(const char *format, ...)
{
	va_list(args);
	int counter;
	int res;
	char *p = (char *)format;

	if (!p)
		return (-1);
	va_start(args, format);
	counter = 0;
	while (*p != '\0')
	{
		if (*p == '%')
		{
			p++;
			res = check_type(p, args);
		}
		else
			res = write(1, p, 1);
		if (res < 0)
			return (res);
		counter += res;
		p++;
	}
	va_end(args);
	return (counter);
}
