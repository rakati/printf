#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>


int check_type(char *ptr, va_list arg);
int print_str(char *s);
int _printf(char *format, ...);
int print_char(int c);



#endif
