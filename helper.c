#include "main.h"

/**
 * check_type - check specifier type and called function that print the type,
 * otherwise return -1 if type not supported
 *
 * @ptr: pointer to the next character following percentage.
 * @arg: list of variadic arguments.
 *
 * Description:
 * - use switch case to find if specifier is supported or not
 * 		- if specifier supported call function that print the specifier type
 * 		  ex (s: call print_str, d: call print_int ...) and return number of
 * 			characters printed by the called function
 * 		- return -1 if specifier not supported (found r).
 *
 */
int check_type(char *ptr, va_list arg)
{
}

/**
 * print_str - print a string and return str_len of string.
 * if str is NULL, return -1.
 */
int print_str(char *s)
{
}
