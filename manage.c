#include "main.h"

/**
 * manage_string - check for string specifier type and call the function
 * that print it otherwise return.
 *
 * @ptr: pointer to the next character following percentage.
 * @args: list of variadic arguments.
 *
 * Return: number of characters printed, -2 for not finding string specifier
 * otherwise -1 on error.
 */
int manage_string(char *ptr, va_list args)
{
	if (*ptr == 'c' || *ptr == '%')
		return (_putchar(*ptr == '%' ? '%' : va_arg(args, int)));
	if (*ptr == 's')
		return (print_str(va_arg(args, char *)));
	if (*ptr == 'S')
		return (print_Str(va_arg(args, char *)));
	if (*ptr == 'R')
		return (_rot13(va_arg(args, char *)));
	if (*ptr == 'r')
		return (_print_rev(va_arg(args, char *)));
	return (-2);
}

/**
 * manage_nbr - check for number specifier type and call the function
 * that print it otherwise return.
 *
 * @ptr: pointer to the next character following percentage.
 * @args: list of variadic arguments.
 *
 * Return: number of characters printed, -2 for not finding number specifier
 * otherwise -1 on error.
 */
int manage_nbr(char *ptr, va_list args)
{
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
	return (-2);
}

/**
 * check_type - check specifier type and call the function that print it,
 * otherwise return -1 on error.
 *
 * @ptr: pointer to the next character following percentage.
 * @args: list of variadic arguments.
 *
 * Return: number of characters printed otherwise -1 on error.
 */
int check_type(char *ptr, va_list args)
{
	int res;

	if (*ptr == '\0')
		return (-1);
	res = manage_nbr(ptr, args);
	if (res == -2)
		res = manage_string(ptr, args);
	if (res != -2)
		return (res);
	return (_putchar('%') + _putchar(*ptr));
}
