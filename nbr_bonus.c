#include "main.h"

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
