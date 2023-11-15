#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include <limits.h>

int check_type(char *ptr, va_list arg);
int print_str(char *s);
int _putchar(int c);
int print_num(long n, int base);
int print_hex(long x, int base);
int print_HEX(long x, int base);
int _printf(const char *format, ...);

#endif
