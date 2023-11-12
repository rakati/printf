#include "main.h"

/**
 * _printf - ...
 *
 * @format: ...
 * Parameters:
 *  - va_list args: declare args (va_list) then initialize arg list with va_start(args, format)
 *  - int counter: count number of characters printed
 *
 * TODO:
 * # printf function:
 * ex: "hello %r %s toto %% %c..1234 %c %c %c,", "valhala", 'A', 'B', 'C' , 'R'.
 * - initialize va_list,
 * int counter ()
 * - iterate over format string and find specifier (%c, s, %)
 * - call check_type function
 *
 *
 * # int check_type (char* (add_per_pos + 1), va_list ):
 * - check specifier type (switch case for character (error -1) (print_cour))
 * - future: call function check width, flag ...
 * - call function to print type (print_string, print_char, print_nbr ...)
 *
 */
int _printf(char *format, ...)
{
}
