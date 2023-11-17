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
 * put_nbr - print decimal signed integer
 *
 * @n: the integer or long int to be printed
 * @flag: 1 for printing sing + if positive 0 for not
 *
 * Return: int number of characters printed to stdout
 */
int put_nbr(long n, short flag)
{
	char nbr[65];
	char b[] = "0123456789";
	int i = 0, s = n < 0;

	if (n == 0)
		nbr[i++] = '0';
	for (; n != 0; n /= 10)
		nbr[i++] = b[_abs(n % 10)];
	if (s)
		nbr[i++] = '-';
	else if (flag == 1)
		nbr[i++] = '+';
	nbr[i] = '\0';
	_strrev(nbr, i);
	return (print_str(nbr));
}

/**
 * put_nbr_ubase - print unsigned integer in base from 2 to 16.
 *
 * @n: the integer or long int to be printed
 * @base: the base number of the integer support 2 to 16.
 * @cap: 1 for use uppercase letter, 0 for lowercase letters
 * @pre: 1 for add base prefix 0 for not (ex, 0x for hexadecimal)
 *
 * Return: int number of characters printed to stdout
 */
int put_nbr_ubase(unsigned long n, short base, short cap, short pre)
{
	char nbr[70] = {0};
	char up_base[] = "0123456789ABCDEF";
	char low_base[] = "0123456789abcdef";
	char *p;
	int i = 0;

	p = cap ? up_base : low_base;
	if (n == 0)
	{
		nbr[i++] = '0';
		pre = 0;
	}
	for (; n > 0; i++, n /= base)
		nbr[i] = p[n % base];
	if (pre == 1)
	{
		if (base == 16)
			nbr[i++] = cap ? 'X' : 'x';
		nbr[i++] = '0';
	}
	nbr[i] = '\0';
	_strrev(nbr, i);
	return (print_str(nbr));
}

/**
 * print_pointer - printing a pointer address in hexadecimal format.
 * @ptr: the pointer to print.
 * @flag: 1 means presence of the '+' flag 0 for not.
 *
 * Return: the number of characters printed on success or (-1) on failure.
 */
int print_pointer(void *ptr, int flag)
{
	if (ptr == NULL)
		return (write(1, "(nil)", 5));
	if (flag == 1)
		return (write(1, "+", 1) + put_nbr_ubase((unsigned long)ptr, 16, 0, 1));
	return (put_nbr_ubase((unsigned long)ptr, 16, 0, 1));
}
