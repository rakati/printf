#include "main.h"

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(int c)
{
	return (write(1, &c, 1));
}

/**
 * _strlen - calculate length of string
 *
 * @s: array of characters
 * Return: length of string
 */

int _strlen(char *s)
{
	int i = 0;

	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

/**
 * print_str - print a string and return the number of bytes written.
 *
 * @s: array of characters
 * @p: 1 printing non printable 0 for not
 *
 * Return: number of characters printed otherwise -1 on error.
 */
int print_str(char *s)
{
	int len = 0;

	if (s == NULL)
		s = "(null)";
	return (write(1, s, _strlen(s)));
}

/**
 * print_Str - print a string and return the number of bytes written.
 *
 * @s: array of characters
 *
 * Return: number of characters printed otherwise -1 on error.
 */
int print_Str(char *s)
{
	int len = 0, res = 0;

	if (s == NULL)
		return (write(1, "(null)", 6));
	while (s[len])
	{
		while (s[len] >= 32 && s[len] < 127)
			len++;
		if (!s[len])
			break;
		res += write(1, s, len);
		s += len;
		len = 0;
		res += write(1, "\\x", 2);
		if (*s < 16)
			res += write(1, "0", 1);
		res += put_nbr_base(*s, 16, 1, 0);
	}
	res += write(1, s, len);
	return (res);
}

/**
 * _strrev - inplace reverse string
 *
 * @s: array of characters
 * @l: length of string or-1 if not available
 */
void _strrev(char *s, int l)
{
	int i = 0;
	char tmp;

	if (l < 0)
		l = _strlen(s);
	for (i = 0; i < l / 2; i++)
	{
		tmp = s[i];
		s[i] = s[l - i - 1];
		s[l - i - 1] = tmp;
	}
}
