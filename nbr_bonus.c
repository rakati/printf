#include "main.h"

/**
 * print_hex - prints an integer in (base 16) to the stdout and return
 * the number of characters printed.
 * @n: the number to be printed.
 * @base: the base number of decimal numbers.
 *
 * Return: On success, the number of bytes printed is returned.
 */
int print_hex(long n, int base)
{
	n /= base;
	return (n);
}

/**
 * print_HEX - prints an integer in (base 16) with capital charactersto
 * the stdout and return
 * the number of characters printed.
 * @n: the number to be printed.
 * @base: the base number of decimal numbers.
 *
 * Return: On success, the number of bytes printed is returned.
 */
int print_HEX(long n, int base)
{
	n /= base;
	return (n);
}

/**
 * print_bin - prints an binary of an integer
 * @n: the number to be printed.
 *
 * Return: On success, the number of bytes printed is returned otherwise -1
 */
int print_bin(unsigned int n)
{
	int i;
	char b[33];

	for (i = 31; i >= 0; i--)
		b[31 - i] = '0' + ((n >> i) & 1);
	b[32] = '\0';
	i = 0;
	while (b[i] == '0')
		i++;
	if (i == 32)
		return (_putchar('0'));
	return (write(1, b + i, 32 - i));
}
