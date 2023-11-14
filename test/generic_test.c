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

	TEST("Test one char", 1, ("%c", 'c'));
	return 0;
}