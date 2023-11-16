#include "../main.h"
#include <stdio.h>
#include <stdarg.h>
#include <string.h>

#define TEST(test_info, print_output, args)                                                           \
	do                                                                                                \
	{                                                                                                 \
		f1 = freopen("output1.txt", "w", stdout);                                                     \
		if (f1)                                                                                       \
		{                                                                                             \
			result1 = _printf args;                                                                   \
			fflush(stdout);                                                                           \
			fclose(f1);                                                                               \
		}                                                                                             \
		f2 = freopen("output2.txt", "w", stdout);                                                     \
		if (f2)                                                                                       \
		{                                                                                             \
			result2 = printf args;                                                                    \
			fflush(stdout);                                                                           \
			fclose(f2);                                                                               \
		}                                                                                             \
		f1 = fopen("output1.txt", "r");                                                               \
		fgets(buffer1, sizeof(buffer1), f1);                                                          \
		fclose(f1);                                                                                   \
		f2 = fopen("output2.txt", "r");                                                               \
		fgets(buffer2, sizeof(buffer2), f2);                                                          \
		fclose(f2);                                                                                   \
		freopen("/dev/tty", "w", stdout);                                                             \
		if (strcmp(buffer1, buffer2) == 0 && result1 == result2)                                      \
		{                                                                                             \
			printf("\033[0;32mPASS: %s\033[0m\n", test_info);                                         \
		}                                                                                             \
		else                                                                                          \
		{                                                                                             \
			printf("\033[0;31mFAIL: %s\033[0m\n", test_info);                                         \
			printf("    _printf returned '%s' (return value %d)\n", buffer1, result1);                \
			printf("    printf returned '%s' (return value %d)\n", buffer2, result2);                 \
		}                                                                                             \
		if (print_output == 1)                                                                        \
		{                                                                                             \
			printf("### \033[0;34m_printf ouput\033[0m -----------\n%s\nlen=%d\n", buffer1, result1); \
			printf("### \033[0;34mprintf ouput\033[0m -----------\n%s\nlen=%d\n", buffer2, result2);  \
		}                                                                                             \
	} while (0);

int main()
{
	char buffer1[1000], buffer2[1000];
	FILE *f1, *f2;
	int result1, result2;
	char s[10] = {0};
	void *addr = (void *)0x7ffe637541f0;
	void *p = (void *)-1;
	void *p1 = (void *)0x7fff5100b6f8;
	void *p2 = (void *)0x7faf51f0f608;
	void *p3 = (void *)0x6ff42510b6f8;
	void *p4 = (void *)0x7fff510236f8;

	/**
	 * testing strings
	 */
	TEST("Test with simple string", 0, ("Hello, World!"));
	TEST("Test with another simple string", 0, ("%s", "Hello, World!"));
	TEST("Test with NULL", 0, (NULL));
	TEST("Test with NULL string", 0, ("this is %s string", NULL));
	TEST("Test capital", 0, ("ABCDE"));
	TEST("Test multiple strings", 0, ("m%sple %string", "ulti", "s", "ing\n"));
	TEST("Test special characters", 0, ("\t\r\\m\n\n"));

	/**
	 * testing percentage
	 */
	TEST("Test double percentages", 0, ("total is 100%%"));
	TEST("Test one percentage ", 0, ("%"));
	TEST("Test one percentage with text", 0, ("%rart"));
	TEST("Test triple percentages ", 0, ("%%%"));
	TEST("Test six percentages ", 0, ("%%%%%%"));
	TEST("Test five percentages ", 0, ("%%%%%"));

	/**
	 * testing unknown specifier
	 * Note: for other unkown the behavior is undefined and not
	 * in the scope of this project (%m, %t ...)
	 */

	TEST("Test unknown r", 0, ("%r"));
	TEST("Test triple percentages with text", 0, ("%%%rttotrt"));

	/**
	 * testing char
	 * Non-printable char behavior is not define
	 */

	TEST("Test one char", 0, ("%c", 'c'));

	/**
	 * testing integers
	 */
	TEST("Test one integer with d", 0, ("%d", 42));
	TEST("Test one integer with i", 0, ("%i", 42));
	TEST("Test negative integer with d", 0, ("%d", -1337));
	TEST("Test negative integer with d", 0, ("%d", -8000));
	TEST("Test negative integer with i", 0, ("%i", -1337));
	TEST("Test negative integer with i", 0, ("%i", -8000));
	TEST("Test zero integer with d", 0, ("%d", 0));
	TEST("Test zero integer with i", 0, ("%i", 0));
	TEST("Test max int with d", 0, ("%d", 2147483647));
	TEST("Test min int with d", 0, ("%d", -2147483648));
	TEST("Test max int with i", 0, ("%i", 2147483647));
	TEST("Test min int with i", 0, ("%i", -2147483648));
	TEST("Test integer in string with d", 0, ("this is a %d\n", 0));
	TEST("Test integer in string with d", 0, ("%d + %d = %d\n", 12, 10, 12 + 10));

	/**
	 * testing HEXADECIMAL
	 */

	TEST("Test one integer with x", 0, ("%x", 42));
	TEST("Test one integer with X", 0, ("%X", 42));

	TEST("Test zero integer with x", 0, ("%x", 0));
	TEST("Test zero integer with X", 0, ("%X", 0));

	/**
	 * testing binary
	 */
	_printf("%b\n", 0);
	_printf("%b\n", 2);
	_printf("%b\n", 4);
	_printf("%b\n", 2147483647);
	_printf("%b\n", 98);

	/**
	 * testing printable char with S
	 */
	_printf("%S\n", "Best\nSchool");
	s[0] = 12;
	_printf("%S\n", s);

	s[0] = 127;
	_printf("%S\n", s);

	/**
	 * testing o and u
	 */

	TEST("Test one integer with o", 0, ("%o", 42));
	TEST("Test one integer with u", 0, ("%u", 42));
	TEST("Test negative integer with o", 0, ("%o", 1337));
	TEST("Test negative integer with o", 0, ("%o", -8000));
	TEST("Test negative integer with u", 0, ("%u", 1337));
	TEST("Test negative integer with u", 0, ("%u", 8000));
	TEST("Test zero integer with o", 0, ("%o", 0));
	TEST("Test zero integer with u", 0, ("%u", 0));
	TEST("Test max int with o", 0, ("%o", 2147483647));
	TEST("Test max int with u", 0, ("%u", 2147483647));
	TEST("Test max uint with u", 0, ("%u", 2147483648));
	TEST("Test integer in string with d", 0, ("this is a %o\n", 0));
	TEST("Test integer in string with d", 0, ("%u + %u = %u\n", 12, 10, 12 + 10));

	/** 
	 * testing %p format specifier to print the pointer address
	 */

	TEST("Test pointer address with p", 0, ("%p", addr));
	TEST("Test pointer -1", 0, ("address\n%p\nNice!\n", p));
	TEST("Test NULL pointer", 0, ("%p", NULL));
	TEST("Test serviral pointers", 0, ("several addresses?\n%p,%p,%p,%p\nNice!\n", p1, p2, p3, p4));
	TEST("Test pointer address with pppp", 0, ("%ppppp", p1));
	return 0;
}
