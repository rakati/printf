#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include "../main.h"

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
			return (0);                                                                               \
		}                                                                                             \
		if (print_output == 1)                                                                        \
		{                                                                                             \
			printf("### \033[0;34m_printf ouput\033[0m -----------\n%s\nlen=%d\n", buffer1, result1); \
			printf("### \033[0;34mprintf ouput\033[0m -----------\n%s\nlen=%d\n", buffer2, result2);  \
		}                                                                                             \
	} while (0);

int rand_short()
{
	return (rand() % SHRT_MAX);
}

int rand_long()
{
	return (rand() + rand());
}

int main(int ac, char **av)
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
	int rand_int = rand();
	short int rand_shortint = rand_short();
	long int rand_longint = rand_long();

	if (ac != 2)
	{
		printf("Usage: ./program [option_nbr]]\nOptions:\n%s%s%s%s%s%s%s%s%s%s",
			   "\t- 0: Test all\n",
			   "\t- 1: Test Strings and chars\n",
			   "\t- 2: Test Numbers\n",
			   "\t- 3: Test Percentage\n",
			   "\t- 4: Test Unsigned Numbers\n",
			   "\t- 5: Test Rot 13\n",
			   "\t- 6: Test Address\n",
			   "\t- 7: Test binary\n",
			   "\t- 8: Test Reverse string\n",
			   "\t- 9: Test non printable string\n");
		return (1);
	}

	/**
	 * seed the rand function
	 */
	srand(time(NULL));

	if (av[1][0] == '0' || av[1][0] == '1')
	{ /**
	   * testing strings
	   */
		_printf("\033[0;35m---------------------------------------------\n\033[0m");
		_printf("\033[0;35m|              Testing Strings              |\n\033[0m");
		_printf("\033[0;35m---------------------------------------------\n\033[0m");
		TEST("Test with simple string", 0, ("Hello, World!"));
		TEST("Test with another simple string", 0, ("%s", "Hello, World!"));
		TEST("Test with NULL", 0, (NULL));
		TEST("Test with NULL string", 0, ("this is %s string", NULL));
		TEST("Test capital", 0, ("ABCDE"));
		TEST("Test multiple strings", 0, ("m%sple %str%s", "ulti", "s", "ing\n"));
		TEST("Test special characters", 0, ("\t\r\\m\n\n"));
		/**
		 * testing char
		 * Non-printable char behavior is not define
		 */

		TEST("Test one char", 0, ("%c", 'c'));
	}
	if (av[1][0] == '0' || av[1][0] == '3')
	{ /**
	   * testing percentage
	   */
		_printf("\033[0;35m---------------------------------------------\n\033[0m");
		_printf("\033[0;35m|              Testing Percentage           |\n\033[0m");
		_printf("\033[0;35m---------------------------------------------\n\033[0m");
		TEST("Test double percentages", 0, ("total is 100%%"));
		TEST("Test one percentage ", 0, ("%"));
		TEST("Test triple percentages ", 0, ("%%%"));
		TEST("Test six percentages ", 0, ("%%%%%%"));
		TEST("Test five percentages ", 0, ("%%%%%"));
		TEST("Test |% | ", 0, ("% "));
		TEST("Test |% % % % | ", 0, ("% % % % "));

		/**
		 * testing unknown specifier
		 * Note: for other unkown the behavior is undefined and not
		 * in the scope of this project (%m, %t ...)
		 */

		TEST("Test triple percentages with text", 0, ("%%%,rttotrt"));
	}
	if (av[1][0] == '0' || av[1][0] == '2')
	{ /**
	   * testing integers
	   */
		_printf("\033[0;35m---------------------------------------------\n\033[0m");
		_printf("\033[0;35m|              Testing Integers             |\n\033[0m");
		_printf("\033[0;35m---------------------------------------------\n\033[0m");
		TEST("Test one integer with d", 0, ("%d", rand_int));
		TEST("Test one integer with i", 0, ("%i", rand_int));
		TEST("Test negative integer with d", 0, ("%d", -rand_int));
		TEST("Test negative integer with i", 0, ("%i", -rand_int));
		TEST("Test zero integer with d", 0, ("%d", 0));
		TEST("Test zero integer with i", 0, ("%i", 0));
		TEST("Test max int with d", 0, ("%d", INT_MAX));
		TEST("Test min int with d", 0, ("%d", INT_MIN));
		TEST("Test max int with i", 0, ("%i", INT_MAX));
		TEST("Test min int with i", 0, ("%i", INT_MIN));

		/**
		 * testing long int with li and ld
		 */
		TEST("Test one integer with ld", 0, ("%ld", rand_longint));
		TEST("Test one integer with li", 0, ("%li", rand_longint));
		TEST("Test negative integer with ld", 0, ("%ld", -rand_longint));
		TEST("Test negative integer with li", 0, ("%li", -rand_longint));
		TEST("Test zero integer with ld", 0, ("%ld", 0));
		TEST("Test zero integer with li", 0, ("%li", 0));
		TEST("Test max int with ld", 0, ("%ld", INT_MAX));
		TEST("Test min int with ld", 0, ("%ld", INT_MIN));
		TEST("Test max int with li", 0, ("%li", INT_MAX));
		TEST("Test min int with li", 0, ("%li", INT_MIN));
		TEST("Test max int with ld", 0, ("%ld", LONG_MAX));
		TEST("Test min int with ld", 0, ("%ld", LONG_MIN));
		TEST("Test max int with li", 0, ("%li", LONG_MAX));
		TEST("Test min int with li", 0, ("%li", LONG_MIN));
		TEST("Test length only with l", 0, ("%l\n"));

		/**
		 * testing short integers with hi and hd
		 */
		TEST("Test one integer with hd", 0, ("%hd", rand_shortint));
		TEST("Test one integer with hi", 0, ("%hi", rand_shortint));
		TEST("Test negative integer with hd", 0, ("%hd", -rand_shortint));
		TEST("Test negative integer with hi", 0, ("%hi", -rand_shortint));
		TEST("Test zero integer with hd", 0, ("%hd", 0));
		TEST("Test zero integer with hi", 0, ("%hi", 0));
		TEST("Test max int with hd", 0, ("%hd", SHRT_MAX));
		TEST("Test min int with hd", 0, ("%hd", SHRT_MIN));
		TEST("Test max int with hi", 0, ("%hi", SHRT_MAX));
		TEST("Test min int with hi", 0, ("%hi", SHRT_MIN));
		TEST("Test length only with h", 0, ("%h\n"));
	}
	if (av[1][0] == '0' || av[1][0] == '4')
	{ /**
	   * testing Unsigned int printed in u, o, x, X
	   */
		_printf("\033[0;35m---------------------------------------------\n\033[0m");
		_printf("\033[0;35m|              Testing UIntegers            |\n\033[0m");
		_printf("\033[0;35m---------------------------------------------\n\033[0m");
		TEST("Test rand uinteger in hex %x", 0, ("%x", rand_int));
		TEST("Test rand uinteger in HEX %X", 0, ("%X", rand_int));
		TEST("Test rand uinteger using u %u", 0, ("%u", rand_int));
		TEST("Test rand uinteger in octal %o", 0, ("%o", rand_int));

		TEST("Test zero in hex %x", 0, ("%x", 0));
		TEST("Test zero in HEX %X", 0, ("%X", 0));
		TEST("Test zero using u %u", 0, ("%u", 0));
		TEST("Test zero in octal %o", 0, ("%o", 0));

		TEST("Test MAX uinteger in hex %x", 0, ("%x", UINT_MAX));
		TEST("Test MAX uinteger in HEX %X", 0, ("%X", UINT_MAX));
		TEST("Test MAX uinteger using u %u", 0, ("%u", UINT_MAX));
		TEST("Test MAX uinteger in octal %o", 0, ("%o", UINT_MAX));

		/**
		 * testing Unsigned long int printed in lu, lo, lx, lX
		 */
		TEST("Test rand Unsigned long int in hex %x", 0, ("%x", rand_int));
		TEST("Test rand Unsigned long int in HEX %X", 0, ("%X", rand_int));
		TEST("Test rand Unsigned long int using u %u", 0, ("%u", rand_int));
		TEST("Test rand Unsigned long int in octal %o", 0, ("%o", rand_int));

		TEST("Test zero in hex %x", 0, ("%x", 0));
		TEST("Test zero in HEX %X", 0, ("%X", 0));
		TEST("Test zero using u %u", 0, ("%u", 0));
		TEST("Test zero in octal %o", 0, ("%o", 0));

		TEST("Test MAX uinteger in hex %x", 0, ("%x", UINT_MAX));
		TEST("Test MAX uinteger in HEX %X", 0, ("%X", UINT_MAX));
		TEST("Test MAX uinteger using u %u", 0, ("%u", UINT_MAX));
		TEST("Test MAX uinteger in octal %o", 0, ("%o", UINT_MAX));

		/**
		 * testing unsigned short int printed in hu, ho, hx, hX
		 */
		TEST("Test rand unsigned short int in hex %hx", 0, ("%hx", rand_int));
		TEST("Test rand unsigned short int in HEX %hX", 0, ("%hX", rand_int));
		TEST("Test rand unsigned short int using u %hu", 0, ("%hu", rand_int));
		TEST("Test rand unsigned short int in octal %ho", 0, ("%ho", rand_int));

		TEST("Test zero int in hex %hx", 0, ("%hx", 0));
		TEST("Test zero in in HEX %hX", 0, ("%hX", 0));
		TEST("Test zero using u %hu", 0, ("%hu", 0));
		TEST("Test zero in octal %ho", 0, ("%ho", 0));

		TEST("Test MAX unsigned short int in hex %hx", 0, ("%hx", UINT_MAX));
		TEST("Test MAX unsigned short int in HEX %hX", 0, ("%hX", UINT_MAX));
		TEST("Test MAX unsigned short int using u %hu", 0, ("%hu", UINT_MAX));
		TEST("Test MAX unsigned short int in octal %ho", 0, ("%ho", UINT_MAX));
	}
	if (av[1][0] == '0' || av[1][0] == '7')
	{ /**
	   * testing binary
	   */
		_printf("\033[0;35m---------------------------------------------\n\033[0m");
		_printf("\033[0;35m|              Testing Binary               |\n\033[0m");
		_printf("\033[0;35m---------------------------------------------\n\033[0m");
		_printf("%b\n", 0);
		_printf("%b\n", 2);
		_printf("%b\n", 4);
		_printf("%b\n", 2147483647);
		_printf("%b\n", 98);
	}

	if (av[1][0] == '0' || av[1][0] == '9')
	{ /**
	   * testing printable char with S
	   */
		_printf("\033[0;35m---------------------------------------------\n\033[0m");
		_printf("\033[0;35m|              Testing !String              |\n\033[0m");
		_printf("\033[0;35m---------------------------------------------\n\033[0m");
		_printf("%S\n", "Best\nSchool");
		s[0] = 12;
		_printf("%S\n", s);

		s[0] = 127;
		_printf("%S\n", s);
	}

	if (av[1][0] == '0' || av[1][0] == '6')
	{ /**
	   * testing %p format specifier to print the pointer address
	   */
		_printf("\033[0;35m---------------------------------------------\n\033[0m");
		_printf("\033[0;35m|              Testing Addresses            |\n\033[0m");
		_printf("\033[0;35m---------------------------------------------\n\033[0m");
		TEST("Test pointer address with p", 0, ("%p", addr));
		TEST("Test pointer -1", 0, ("address\n%p\nNice!\n", p));
		TEST("Test NULL pointer", 0, ("%p", NULL));
		TEST("Test serviral pointers", 0, ("several addresses?\n%p,%p,%p,%p\nNice!\n", p1, p2, p3, p4));
		TEST("Test pointer address with pppp", 0, ("%ppppp", p1));
	}

	if (av[1][0] == '0' || av[1][0] == '5')
	{ /**
	   * testing %R to print the rot 13 of string
	   * %R not supported by printf so compare string outputted by printf
	   */
		_printf("\033[0;35m---------------------------------------------\n\033[0m");
		_printf("\033[0;35m|              Testing ROT13                |\n\033[0m");
		_printf("\033[0;35m---------------------------------------------\n\033[0m");
		_printf("%R", "Quartz glyph job vext cwm porchrop finks!\n");
		printf("Dhnegm tylcu wbo irkg pjz cbepuebc svaxf!\n");

		_printf("%R", "The Quick Brown Fox Jumps Over The Lazy Dog\n");
		printf("Gur Dhvpx Oebja Sbk Whzcf Bire Gur Ynml Qbt\n");
	}
	if (av[1][0] == '0' || av[1][0] == '8')
	{ /**
	   * testing %r to print string reversed
	   * %r in printf is printed as it is.
	   */
		_printf("\033[0;35m---------------------------------------------\n\033[0m");
		_printf("\033[0;35m|              Testing Revers str           |\n\033[0m");
		_printf("\033[0;35m---------------------------------------------\n\033[0m");
		result1 = _printf("%r\n", "12345");
		result2 = printf("%s\n", "54321");
		printf("compare len |%d| vs |%d|\n", result1, result2);

		result1 = _printf("%r\n", "0");
		result2 = printf("%s\n", "0");
		printf("compare len |%d| vs |%d|\n", result1, result2);

		result1 = _printf("|%r|\n", "\n12\n34\n5");
		result2 = printf("|%s|\n", "5\n43\n21\n");
		printf("compare len |%d| vs |%d|\n", result1, result2);

		result1 = _printf("Complete the sentence: You %r nothing, Jon Snow.\n", "know");
		result2 = printf("%s\n", "Complete the sentence: You wonk nothing, Jon Snow.");
		printf("compare len |%d| vs |%d|\n", result1, result2);

		result1 = _printf("Complete the sentence: You %r nothing, Jon Snow.\n", "");
		result2 = printf("%s\n", "Complete the sentence: You  nothing, Jon Snow.");
		printf("compare len |%d| vs |%d|\n", result1, result2);
	}

	/**
	 * testing %r to print string reversed
	 * %r in printf is printed as it is.
	 */
	_printf("\033[0;35m---------------------------------------------\n\033[0m");
	_printf("\033[0;35m|              Testing the + flag           |\n\033[0m");
	_printf("\033[0;35m---------------------------------------------\n\033[0m");
	TEST("test with |%+|", 0, ("|%+|\n"));
	TEST("test with |%+d|", 0, ("d|%+d|\n", 1024));
	TEST("test with |%+ld|", 0, ("ld|%+ld|\n", 12));
	TEST("test with |%+hd|", 0, ("hd|%+hd|\n", 12));
	TEST("test with |%+d|", 0, ("d|%+d|\n", -12));
	TEST("test with |%+d|", 0, ("d|%+d|\n", 0));
	TEST("test with max int |%+d|", 0, ("d|%+d|\n", INT_MAX));
	TEST("test with min int |%+d|", 0, ("d|%+d|\n", INT_MIN));
	TEST("test with min int |%+d|", 0, ("d|%+d|\n", INT_MIN));
	TEST("test with min int |%+d|", 0, ("d|%+d|\n", LONG_MAX));
	TEST("test with |%+s|", 0, ("s|%+s|\n", "hello"));
	TEST("test with |%+c|", 0, ("c|%+c|\n", 'R'));
	TEST("test with |%+x|", 0, ("x|%+x|\n", 12));
	TEST("test with |%+X|", 0, ("X|%+X|\n", 12));
	TEST("test with |%+o|", 0, ("o|%+o|\n", 12));
	TEST("test with |%+p|", 0, ("p|%+p|\n", 12));

	_printf("\033[0;35m---------------------------------------------\n\033[0m");
	_printf("\033[0;35m|              Testing the # flag           |\n\033[0m");
	_printf("\033[0;35m---------------------------------------------\n\033[0m");
	TEST("test with |%#x|", 0, ("x|%+#x|\n", 12));
	TEST("test with |%#x|", 0, ("x|%#x|\n", 12));
	TEST("test with |%#x|", 0, ("x|%#x|\n", 0));
	TEST("test with |%#x|", 0, ("x|%#x|\n", -13));
	TEST("test with |%#X|", 0, ("X|%+#X|\n", UINT_MAX));
	TEST("test with |%#X|", 0, ("X|%#X|\n", UINT_MAX));
	TEST("test with |%#X|", 0, ("X|%#X|\n", 0));
	TEST("test with |%+#o|", 0, ("o|%+#o|\n", 12));
	TEST("test with |%#o|", 0, ("o|%#o|\n", 12));
	TEST("test zero with |%#o|", 0, ("o|%#o|\n", 0));
	TEST("test umax with |%#o|", 0, ("o|%#o|\n", UINT_MAX));
	TEST("test with |%#o|", 0, ("o|%#o|\n", -1));
	TEST("test with |%#s|", 0, ("o|%#s|\n", "fsf"));
	TEST("test with |%#s|", 0, ("o|%#s|\n", NULL));

	_printf("\033[0;35m---------------------------------------------\n\033[0m");
	_printf("\033[0;35m|              Testing the ' ' flag         |\n\033[0m");
	_printf("\033[0;35m---------------------------------------------\n\033[0m");

	TEST("test with |% |", 0, ("|% |\n"));
	TEST("test with |% d|", 0, ("d|% d|\n", 1024));
	TEST("test with |% ld|", 0, ("ld|% ld|\n", 12));
	TEST("test with |% hd|", 0, ("hd|% hd|\n", 12));
	TEST("test with |% d|", 0, ("d|% d|\n", -12));
	TEST("test with |% d|", 0, ("d|% d|\n", 0));
	TEST("test with max int |% d|", 0, ("d|% d|\n", INT_MAX));
	TEST("test with min int |% d|", 0, ("d|% d|\n", INT_MIN));
	TEST("test with min int |% d|", 0, ("d|% d|\n", INT_MIN));
	TEST("test with min int |% d|", 0, ("d|% d|\n", LONG_MAX));
	TEST("test with |% s|", 0, ("s|% s|\n", "hello"));
	TEST("test with |% c|", 0, ("c|% c|\n", 'R'));
	TEST("test with |% x|", 0, ("x|% x|\n", 12));
	TEST("test with |% X|", 0, ("X|% X|\n", 12));
	TEST("test with |% o|", 0, ("o|% o|\n", 12));
	TEST("test with |% p|", 0, ("p|% p|\n", 12));
	return 0;
}
