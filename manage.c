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
	int f = 0;

	f += (*ptr == '+') + (*ptr == '#');
	if (ptr[f] == 'c' || ptr[f] == '%')
		return (_putchar(ptr[f] == '%' ? '%' : va_arg(args, int)));
	if (ptr[f] == 's')
		return (print_str(va_arg(args, char *)));
	if (ptr[f] == 'S')
		return (print_Str(va_arg(args, char *)));
	if (ptr[f] == 'R')
		return (_rot13(va_arg(args, char *)));
	if (ptr[f] == 'r')
		return (_print_rev(va_arg(args, char *)));
	return (-2);
}

/**
 * manage_nbr_flag - check for number specifier with flag and call the function
 * that print it otherwise return.
 *
 * Description: the `l` and `h` length are changing the size of the requested
 * type through va_arg, so we still request int or uint but in different size.
 * more info [https://cplusplus.com/reference/cstdio/printf/]
 *
 * @p: pointer to the next character following percentage.
 * @l: list of variadic arguments.
 * @flag: 1 means presence of '+' flag otherwise 0.
 * @pre: 1 means presence of '#' flag otherwise 0.
 *
 * Return: number of characters printed, -2 for not finding number specifier
 * otherwise -1 on error.
 */
int manage_nbr_flag(char *p, va_list l, int flag, int pre)
{
	if (*p == 'h' && (p[1] == 'd' || p[1] == 'i'))
		return (put_nbr((short int)va_arg(l, int), flag));
	if (*p == 'h' && (p[1] == 'x' || p[1] == 'X'))
		return (put_nbr_ubase((unsigned short int)va_arg(l, int), 16,
							  p[1] == 'X', pre));
	if (*p == 'h' && p[1] == 'u')
		return (put_nbr_ubase((unsigned short int)va_arg(l, int), 10, 0, 0));
	if (*p == 'h' && p[1] == 'o')
		return (put_nbr_ubase((unsigned short int)va_arg(l, int), 8, 0, pre));

	if (*p == 'l' && (p[1] == 'd' || p[1] == 'i'))
		return (put_nbr(va_arg(l, long int), flag));
	if (*p == 'l' && (p[1] == 'x' || p[1] == 'X'))
		return (put_nbr_ubase(va_arg(l, unsigned long int), 16, p[1] == 'X',
							  pre));
	if (*p == 'l' && p[1] == 'u')
		return (put_nbr_ubase(va_arg(l, unsigned long int), 10, 0, 0));
	if (*p == 'l' && p[1] == 'o')
		return (put_nbr_ubase(va_arg(l, unsigned long int), 8, 0, pre));
	return (-2);
}

/**
 * manage_nbr - check for number specifier type and call the function
 * that print it otherwise return.
 *
 * @ptr: pointer to the next character following percentage.
 * @args: list of variadic arguments.
 * @mv: an integer ptr defines number of moves for format string
 *
 * Return: number of characters printed, -2 for not finding number specifier
 * otherwise -1 on error.
 */
int manage_nbr(char *ptr, va_list args, int *mv)
{
	int res;
	int f = 0;
	int pre = 0;

	if (*ptr == '+' || (ptr + 1 && ptr[1] == '+'))
		f = 1;
	if (*ptr == '#' || (ptr + 1 && ptr[1] == '#'))
		pre = 1;
	res = manage_nbr_flag(ptr + f + pre, args, f, pre);
	if (res != -2)
	{
		*mv = 2 + f + pre;
		return (res);
	}
	*mv += f + pre;
	if (ptr[f] == 'l' || ptr[f] == 'h')
		return (write(1, "%", 1));
	if (ptr[f] == 'd' || ptr[f] == 'i')
		return (put_nbr(va_arg(args, int), f));
	if (ptr[f + pre] == 'x' || ptr[f + pre] == 'X')
		return (put_nbr_ubase(va_arg(args, unsigned int), 16,
							  ptr[f + pre] == 'X', pre));
	if (ptr[f] == 'u')
		return (put_nbr_ubase(va_arg(args, unsigned int), 10, 0, 0));
	if (ptr[f + pre] == 'o')
		return (put_nbr_ubase(va_arg(args, unsigned int), 8, 0, pre));
	if (ptr[f] == 'b')
		return (put_nbr_ubase(va_arg(args, unsigned int), 2, 0, 0));
	if (ptr[f] == 'p')
		return (print_pointer(va_arg(args, void *), f));
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
	*mv = 1;
	return (_putchar('%') + _putchar(*ptr));
}
