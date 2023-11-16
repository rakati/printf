#include "main.h"

/**
 * check_type - check specifier type and call the function that print it,
 * otherwise return -1 on error.
 *
 * @ptr: pointer to the next character following percentage.
 * @args: list of variadic arguments.
 *
 * Return: number of characters printed otherwise -1 on error.
 * //return (print_num((long)va_arg(args, unsigned int), 10));
 */
int check_type(char *ptr, va_list args)
{
	if (*ptr == 'c' || *ptr == '%')
		return (_putchar(*ptr == '%' ? '%' : va_arg(args, int)));
	if (*ptr == 's')
		return (print_str(va_arg(args, char *)));
	if (*ptr == 'S')
		return (print_Str(va_arg(args, char *)));
	if (*ptr == 'd' || *ptr == 'i')
		return (put_nbr(va_arg(args, int), 0));
	if (*ptr == 'x' || *ptr == 'X')
		return (put_nbr_ubase(va_arg(args, unsigned int), 16, *ptr == 'X', 0));
	if (*ptr == 'u')
		return (put_nbr_ubase(va_arg(args, unsigned int), 10, 0, 0));
	if (*ptr == 'o')
		return (put_nbr_ubase(va_arg(args, unsigned int), 8, 0, 0));
	if (*ptr == 'b')
		return (put_nbr_ubase(va_arg(args, unsigned int), 2, 0, 0));
	if (*ptr == 'p')
		return (print_pointer(va_arg(args, void *)));
	if (*ptr == '\0')
		return (-1);
	return (_putchar('%') + _putchar(*ptr));
}
