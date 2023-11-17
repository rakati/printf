#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include <limits.h>

/*
 * string functions
 */
int _putchar(int c);
int _strlen(char *s);
int print_str(char *s);
int print_pointer(void *ptr, int flag);
int print_Str(char *s);
void _strrev(char *s, int l);

/*
 * other functions
 */
int _rot13(char *s);
int _print_rev(char *s);

/*
 * number functions
 */
long _abs(long n);
int put_nbr_ubase(unsigned long n, short base, short cap, short pre);
int put_nbr(long n, short flag);

/*
 * printf function with its manager
 */
int manage_string(char *ptr, va_list args);
int manage_nbr(char *ptr, va_list args, int *mv);
int check_type(char *ptr, va_list arg, int *mv);
int _printf(const char *format, ...);

#endif
