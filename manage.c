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
 * manage_nbr_flag - check for number specifier with flag and call the function
 * that print it otherwise return.
 *
 * Description: the `l` and `h` length are changing the size of the requested
 * type through va_arg, so we still request int or uint but in different size,
 * check table below.
 * more info [https://cplusplus.com/reference/cstdio/printf/]
 * ------------------------------------------
 * length |  d i	  | u o x X
 * ------------------------------------------
 * h      | short int |	unsigned short int
 * ------------------------------------------
 * l	  | long int  |	unsigned long int
 * ------------------------------------------
 *
 * @p: pointer to the next character following percentage.
 * @l: list of variadic arguments.
 *
 * Return: number of characters printed, -2 for not finding number specifier
 * otherwise -1 on error.
 */
int manage_nbr_flag(char *p, va_list l)
{
	if (*p == 'h' && (p[1] == 'd' || p[1] == 'i'))
		return (put_nbr((short int)va_arg(l, int), 0));
	if (*p == 'h' && (p[1] == 'x' || p[1] == 'X'))
		return (put_nbr_ubase((unsigned short int)va_arg(l, int), 16,
							  p[1] == 'X', 0));
	if (*p == 'h' && p[1] == 'u')
		return (put_nbr_ubase((unsigned short int)va_arg(l, int), 10, 0, 0));
	if (*p == 'h' && p[1] == 'o')
		return (put_nbr_ubase((unsigned short int)va_arg(l, int), 8, 0, 0));

	if (*p == 'l' && (p[1] == 'd' || p[1] == 'i'))
		return (put_nbr(va_arg(l, long int), 0));
	if (*p == 'l' && (p[1] == 'x' || p[1] == 'X'))
		return (put_nbr_ubase(va_arg(l, unsigned long int), 16, p[1] == 'X',
							  0));
	if (*p == 'l' && p[1] == 'u')
		return (put_nbr_ubase(va_arg(l, unsigned long int), 10, 0, 0));
	if (*p == 'l' && p[1] == 'o')
		return (put_nbr_ubase(va_arg(l, unsigned long int), 8, 0, 0));
	return (-2);
}

/**
 * manage_nbr - check for number specifier type and call the function
 * that print it otherwise return.
 *
 * @ptr: pointer to the next character following percentage.
 * @args: list of variadic arguments.
 * @mv: an integer defines number of move for format string, by default mv will
 *
 * Return: number of characters printed, -2 for not finding number specifier
 * otherwise -1 on error.
 */
int manage_nbr(char *ptr, va_list args, int *mv)
{
	int res;

	res = manage_nbr_flag(ptr, args);
	if (res != -2)
	{
		*mv = 2;
		return (res);
	}
	if (*ptr == 'l' || *ptr == 'h')
		return (write(1, "%", 1));
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
 * @mv: an integer defines number of move for format string, by default mv will
 * be 1, but for flags and length mv will be setted.
 *
 * Return: number of characters printed otherwise -1 on error.
 */
int check_type(char *ptr, va_list args, int *mv)
{
	int res;

	*mv = 1;
	if (*ptr == '\0')
		return (-1);
	res = manage_nbr(ptr, args, mv);
	if (res == -2)
		res = manage_string(ptr, args);
	if (res != -2)
		return (res);
	return (_putchar('%') + _putchar(*ptr));
}
