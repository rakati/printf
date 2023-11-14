
<h1  align="center"><img src="https://miro.medium.com/v2/resize:fit:2400/1*E1LonYGC5Fx4QLY4W5SaVA.jpeg" width="100" alt="Udacity logo">ALX-Africa Software Engineering Program</h1>

# Implementation of C Printf
## Overview
This project is part of the ALX Software Engineering program - Low level programming part.
In this project we will reimplement the C printf function according the instruction giving by **ALX**.

## 0x11. C - printf
### Resources
- [Secrets of printf](https://intranet.alxswe.com/rltoken/7Vw7aUWgwC7JYUrqI4bh4Q)
- [Variadic function in C](https://www.gnu.org/software/libc/manual/html_node/Variadic-Functions.html)

- `printf (3)` (`man page`).

### Authorized functions and macros
- `write`
- `malloc`
- `free`
- `va_start`
- `va_end`
- `va_copy`
- `va_arg`

## How to test
tests are placed in test folder, we create a similar unit test, that compare output and returned value of our _printf with c printf.

- to run test do:
```shell
gcc -Wall -Wextra -Werror -pedantic -std=gnu89 -Wno-format ../*.c -I../ generic_test.c
./a.out
```
- To add new test case, add following line to the main function.
```c
TEST("test case description", 1, (arguments_of_printf));
```
- `1` for printing outputs of the two functions to stdout, use 0 if you don't want to see output.
- `(arguments_of_printf)`: not that arguments should be surrounded by parentheses, ex `("this is %s, and this is an int %d", "string", 1337)`.

## Team of 2:
- me (Nouredine Ouhaddou)
- AMINE Zoukri.

*Note: Other requirements and instructions are not mentioned, keeping alx program private, and share only necessarily stuff.*
