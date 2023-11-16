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
 *
 * Return: number of characters printed otherwise -1 on error.
 */
int print_str(char *s)
{
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
		if (s[len] < 32 || s[len] >= 127)
		{
			if (len > 1)
				res += write(1, s, len);
			res += write(1, "\\x", 2);
			if (s[len] < 16)
				res += write(1, "0", 1);
			res += put_nbr_ubase(s[len], 16, 1, 0);
			s += len + 1;
			len = 0;
		}
		else
			len++;
	}
	res += len > 1 ? write(1, s, len) : 0;
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

/**
 * _rot13 - rotate string by 13, rotation applied only on alphabets
 *
 * @s: array of characters
 * Return: number of char printed;
 */
int _rot13(char *s)
{
	int i = 0;
	char *d;

	if (s == NULL)
		return (write(1, "(null)", 6));
	d = malloc(sizeof(char *) * _strlen(s));
	if (!d)
		return (-1);
	while (s[i])
	{
		if (s[i] >= 'a' && s[i] <= 'z')
			d[i] = (s[i] - 'a' + 13) % 26 + 'a';
		else if (s[i] >= 'A' && s[i] <= 'Z')
			d[i] = (s[i] - 'A' + 13) % 26 + 'A';
		else
			d[i] = s[i];
		i++;
	}
	return (write(1, d, i));
}
