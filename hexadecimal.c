#include "main.h"

/**
 * print_hex - printing a number in hexadecimal format in lowercase.
 * @x: the number to convert into hexadecimal.
 * @base: the base number of hexadecimal.
 *
 * Return: the number of charcters printed or -1 in case of failure.
 */
int print_hex(long x, int base)
{
	int counter = 0;
	char *numbers = "0123456789abcdef";

	if (x < base)
		return (_putchar(numbers[x]));

	else if (x >= base)
	{
		counter = print_hex(x / base, base);
		return (counter + (print_hex(x % base, base)));
	}

	return (-1);
}


/**
 * print_HEX - printing a number in hexadecimal format in uppercase.
 * @x: the number to convert into hexadecimal.
 * @base: the base number of hexadecimal.
 *
 * Return: the number of charcters printed or -1 in case of failure.
 */
int print_HEX(long x, int base)
{
	int counter = 0;
	char *numbers = "0123456789ABCDEF";

	if (x < base)
		return (_putchar(numbers[x]));

	else if (x >= base)
	{
		counter = print_HEX(x / base, base);
		return (counter + (print_HEX(x % base, base)));
	}

	return (-1);
}
