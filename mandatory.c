#include "main.h"

/**
 * print_str - print a string and return the number of bytes written.
 *
 * @s: array of characters
 *
 * Return: number of characters printed otherwise -1 on error.
 */
int print_str(char *s)
{
	int len = 0;

	if (s == NULL)
		s = "(null)";

	while (s[len])
		len++;
	return (write(1, s, len));
}

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
 * print_num - prints an integer in (base 10) to the stdout and return
 * the number of characters printed.
 * @n: the number to be printed.
 * @base: the base number of decimal numbers.
 *
 * Return: On success, the number of bytes printed is returned.
 */
int print_num(long n, int base)
{
	int counter = 0;
	int check = 0;
	char *numbers = "0123456789";

	if (n < 0)
	{
		check = write(1, "-", 1);

		if (check == -1)
			return (check);

		return (print_num(-n, base) + 1);
	}
	else if (n < base)
		return (_putchar(numbers[n]));

	else if (n > base)
	{
		counter = print_num(n / base, base);
		return (counter + (print_num(n % base, base)));
	}

	return (-1);
}
