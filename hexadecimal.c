#include "main.h"

/**
 * print_hex - printing a number in hexadecimal format in lowercase.
 * @x: the number to convert into hexadecimal.
 * @base: the base number of hexadecimal.
 *
 * Return: the number of characters printed or -1 in case of failure.
 */
int print_hex(unsigned int x, unsigned int base)
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
 * Return: the number of characters printed or -1 in case of failure.
 */
int print_HEX(unsigned int x, unsigned int base)
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

/**
 * print_pointer - printing a pointer address in hexadecimal format.
 * @ptr: the pointer to print.
 *
 * Return: the number of characters printed on success or (-1) on failure.
 */
int print_pointer(void *ptr)
{
	char *str = "0x";
	
	if (ptr == NULL)
		return (print_str(ptr));

	write(1, str, 2);

	return (print_num((unsigned long) ptr, 16) + 2);
}
