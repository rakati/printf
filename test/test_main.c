#include "../main.h"
#include <stdio.h>

int main(void)
{
	int len1, len2;
	char c = 'a';

	len1 = _printf("this is [%c] test to our [%s] function\n", c, "costum printf");
	len2 = printf("this is [%c] test to our [%s] function\n", c, "costum printf");

	printf("_printf: [%d]\n printf: [%d]\n", len1, len2);
	return (0);
}
