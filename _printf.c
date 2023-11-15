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
	int i, res;
	char *p = (char *)format;
	char b[1024];

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
			i = 1;
		}
		else
		{
			for (i = 0; p[i] && p[i] != '%' && i < 1023; i++)
				b[i] = p[i];
			b[i] = '\0';
			res = write(1, b, i);
		}
		if (res < 0)
			return (-1);
		counter += res;
		p += i;
	}
	va_end(args);
	return (counter);
}
