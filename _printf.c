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
	int mv, res;
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
			res = check_type(p, args, &mv);
		}
		else
		{
			for (mv = 0; p[mv] && p[mv] != '%' && mv < 1023; mv++)
				b[mv] = p[mv];
			b[mv] = '\0';
			res = write(1, b, mv);
		}
		if (res < 0)
			return (-1);
		counter += res;
		p += mv;
	}
	va_end(args);
	return (counter);
}
