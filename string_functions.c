#include "main.h"

/**
 * print_Str - print a string and return the number of bytes written.
 *
 * @s: array of characters
 *
 * Return: number of characters printed otherwise -1 on error.
 */
int print_Str(char *s)
{
	int len = 0;
	int res = 0;

	if (s == NULL)
		s = "(null)";

	while (s[len])
	{
		if (s[len] < 32 || s[len] >= 127)
		{
			res += write(1, "\\x", 2);
			if (s[len] < 16)
				res += write(1, "0", 1);
			res += print_HEX(s[len], 16);
		}
		else
			res += write(1, s + len, 1);
		len++;
	}
	return (res);
}
