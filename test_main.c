#include "main.h"
#include <stdio.h>

int main(void)
{
	char c = 'a';

	_printf("this is [%c] test to our [%s] function\n", c, "costum printf");
	printf("this is [%c] test to our [%s] function\n", c, "costum printf");

	return (0);
}
