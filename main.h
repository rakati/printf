#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include <limits.h>

int check_type(char *ptr, va_list arg);
int print_str(char *s);
int _putchar(int c);
int print_num(int n, int base);
int _printf(char *format, ...);

#endif
