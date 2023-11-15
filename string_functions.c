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
	char buff[1025];
	int i = 0;
	int res;

	if (s == NULL)
		s = "(null)";

	while (s[len])
	{
		if (i < 1023)
		{
			if (s[len] < 32 || s[len] >= 127)
			{
				buff[i++] = '\\';
				buff[i] = 'x';
			}
			else
				buff[i] = s[len];
			i++;
			len++;
			buff[i] = '\0';
		}
		else
		{
			res = write(1, buff, i);
			if (res < 0)
				return (-1);
			i = 0;
		}
	}
	if (i > 0)
		return (write(1, buff, i));
	return (-1);
}
