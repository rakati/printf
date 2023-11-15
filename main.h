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
int print_hex(unsigned long x, unsigned int base);
int print_HEX(unsigned long x, unsigned int base);
int print_pointer(void *ptr);
int print_bin(unsigned int n);
int print_Str(char *s);
int _printf(const char *format, ...);

#endif
