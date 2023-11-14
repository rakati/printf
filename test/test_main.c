#include "../main.h"
#include <stdio.h>

int main(void)
{
	int len1, len2;
	char c = 'a';

	/* test string and char */
	len1 = _printf("this is [%c] test to our [%s] function\n", c, "costum printf");
	len2 = printf("this is [%c] test to our [%s] function\n", c, "costum printf");
	printf("_printf: [%d]\n printf: [%d]\n", len1, len2);

	printf("--------------------\n");

	/* test Null ptr */
	len1 = _printf("this is null[%s]\n", NULL);
	len2 = printf("this is null[%s]\n", NULL);
	printf("_printf: [%d]\n printf: [%d]\n", len1, len2);

	printf("--------------------\n");

	/* test unknown specifier */
	len1 = _printf("this is unknown[%r]\n");
	len2 = printf("this is unknown[%r]\n");
	printf("_printf: [%d]\n printf: [%d]\n", len1, len2);

	printf("--------------------\n");

	/* test decimal numbers */
	_printf("Length:[%d, %i]\n", len1, len1);
	printf("Length:[%d, %i]\n", len2, len2);
	_printf("Negative:[%d]\n", -762534);
	printf("Negative:[%d]\n", -762534);

	printf("--------------------\n");

	return (0);
}
