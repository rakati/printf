#include "main.h"

/**
 * _abs - absolute value of number
 * @n: A natural number
 * Return: absolute value of number
 */
long _abs(long n)
{
	return (n < 0 ? n * -1 : n);
}

/**
 * put_nbr_base - print signed integer in base from 2 to 16.
 *
 * @n: the integer or long int to be printed
 * @base: the base number of the integer support 2 to 16.
 * @cap: 1 for use uppercase letter, 0 for lowercase letters
 * @pre: 1 for add base prefix 0 for not (ex, 0x for hexadecimal)
 * Return: int number of characters printed to stdout
 */
int put_nbr_base(long n, short base, short cap, short pre)
{
	char nbr[70] = {0};
	char up_base[] = "0123456789ABCDEF";
	char low_base[] = "0123456789abcdef";
	char *p;
	int i = 0;

	p = cap ? up_base : low_base;
	for (; n >= 0; i++, n /= base)
		nbr[i] = p[_abs(n % base)];
	if (pre)
	{
		if (base = 16)
			nbr[i++] = cap ? 'X' : 'x';
		nbr[i++] = '0';
	}
	if (nbr < 0)
		nbr[i++] = '-';
	nbr[i] = '\0';
	_strrev(nbr, i);
	return (print_str(nbr));
}
