/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_output_tests.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkettani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/05 17:33:49 by jkettani          #+#    #+#             */
/*   Updated: 2019/02/06 16:15:54 by jkettani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <float.h>
#define BOLD "\x1b[1m"
#define UNDERLINE "\x1b[4m"
#define NC "\x1b[0m"
#define RED "\x1b[31m"
#define GREEN "\x1b[32m"
#define YELLOW "\x1b[33m"
#define BLUE "\x1b[34m"
#define MAGENTA "\x1b[35m"
#define PRINTF_TEST do { \
	int		ret;\
	printf(" > %s (", desc);\
	printf("\"|");\
	printf(MAGENTA "%s" NC, fmt);\
	printf("|\", |");\
	printf(BLUE "%s" NC, test_str);\
	printf("|): ");\
	printf("|" YELLOW);\
	ret = printf(fmt, test);\
	printf(NC "|");\
	printf(", |" YELLOW);\
	printf("%d", ret);\
	printf(NC "|");\
	printf("\n");\
	} while (0)

void	print_h1(char *str)
{
	printf(UNDERLINE "\n%s\n" NC, str);
}

void	print_h2(char *str)
{
	printf(BOLD "\n%s\n\n" NC, str);
}

void	test_char(char *desc, char *fmt, char *test_str, char test)
{
	PRINTF_TEST;
}

void	test_unsigned_char(char *desc, char *fmt, char *test_str, unsigned char test)
{
	PRINTF_TEST;
}

void	test_int(char *desc, char *fmt, char *test_str, int test)
{
	PRINTF_TEST;
}

void	test_unsigned_int(char *desc, char *fmt, char *test_str, unsigned int test)
{
	PRINTF_TEST;
}

void	test_short(char *desc, char *fmt, char *test_str, short test)
{
	PRINTF_TEST;
}

void	test_long(char *desc, char *fmt, char *test_str, long test)
{
	PRINTF_TEST;
}

void	test_unsigned_long(char *desc, char *fmt, char *test_str, unsigned long test)
{
	PRINTF_TEST;
}

void	test_long_long(char *desc, char *fmt, char *test_str, long long test)
{
	PRINTF_TEST;
}

void	test_float(char *desc, char *fmt, char *test_str, float test)
{
	PRINTF_TEST;
}

void	test_type_char(void)
{
	print_h1("TYPE: CHAR (%c)");
	print_h2("=> Valid format:");
	test_char("Non printable ASCII char nul", "%c", "0", 0);
	test_char("Non printable ASCII char horizontal tab", "%c", "9", 9);
	test_char("Non printable ASCII char vertical tab", "%c", "11", 11);
	test_char("Digit ASCII char 3", "%c", "'3'", '3');
	test_char("Capital letter ASCII char Z", "%c", "'Z'", 'Z');
	test_char("Small letter ASCII char 'a'", "%c", "'a'", 'a');
	test_char("Symbol ASCII char *", "%c", "42", 42);
	test_char("Non printable ASCII char del", "%c", "127", 127);
	test_char("Int greater than 127 -- 128", "%c", "128", (char)128);
	test_char("Int greater than 127 -- 298 = 42 + 256", "%c", "298", (char)298);
	test_char("Negative number", "%c", "-1", -1);
	test_char("Negative number", "%c", "-42", -42);
	test_char("Negative number -- 97 = -159 + 256", "%c", "-159", (char)-159);
	test_char("Small letter ASCII char 'a' right aligned", "%10c", "'a'", 'a');
	test_char("Small letter ASCII char 'a' left justified", "%-10c", "'a'", 'a');
	test_char("Small letter ASCII char 'a' left justified -- multiple - signs", "%-----10c", "'a'", 'a');
	test_char("Int greater than 127 with length modifier l -- 298 = 42 + 256", "%lc", "298", (char)298);
}

void	test_type_int(void)
{
	print_h1("TYPE: INT (%d | %i)");
	print_h2("=> Valid format:");
	test_int("Zero", "%d", "0", 0);
	test_int("Zero + . precision", "%.d", "0", 0);
	test_int("Zero + .3 precision", "%.3d", "0", 0);
	test_int("Random int", "%d", "42", 42);
	test_int("Random int + 'INT_MAX + 1' width", "%2147483648d", "42", 42);
	test_int("Random int + 'INT_MAX + 1' precision", "%.2147483648d", "42", 42);
	test_int("Int max", "%d", "2147483647", INT_MAX);
	test_int("Int max + 1", "%d", "2147483648", INT_MAX + 1);
	test_int("Int min", "%d", "-2147483648", INT_MIN);
	test_int("Unsigned int max", "%d", "4294967295", UINT_MAX);
	test_int("Random int + '.1' precision -- precision < nb digits", "%.1d", "42", 42);
	test_int("Random int + '.4' precision -- precision > nb digits", "%.1d", "42", 42);
	test_int("Random int + '3' width + '.5' precision -- precision > width", "%3.5d", "42", 42);
	test_int("Random int + '5' width + '.3' precision -- precision < width", "%5.3d", "42", 42);
	test_int("Random int + '0' flag", "%0d", "42", 42);
	test_int("Random int + '0' flag + '5' width", "%05d", "42", 42);
	test_int("Random int + multiple '0' flags + '5' width", "%00005d", "42", 42);
	test_int("Random int + '+' flag", "%+d", "42", 42);
	test_int("Random int + multiple '+' flags", "%++++d", "42", 42);
	test_int("Random int + ' ' flag + '0' flag + '5' width", "% 05d", "42", 42);
	test_int("Random int + '+' flag + '0' flag + '5' width", "%+05d", "42", 42);
	test_int("Random int + '+' flag + '0' flag + '5' width -- flags in reverse order", "%0+5d", "42", 42);
	test_int("Random int + multiple '+' flags  + multiple '0' flags + '5' width", "%+++++000005d", "42", 42);
	test_int("Random int + ' ' flag", "% d", "42", 42);
	test_int("Random int + multiple ' ' flags", "%     d", "42", 42);
	test_int("Random int + 5 width", "%5d", "42", 42);
	test_int("Random int + '+' flag + '5' width", "%+5d", "42", 42);
	test_int("Random int + '1' width -- width < nb digits", "%1d", "42", 42);
	test_int("Random int + '-' flag + '5' width", "%-5d", "42", 42);
	test_int("Random int + multiple '-' flags", "%------5d", "42", 42);
	test_int("Random int + '-' flag + '+' flag + '5' width", "%-+5d", "42", 42);
	test_int("Random int + '-' flag + '+' flag + '5' width -- flags alternate", "%---++++---5d", "42", 42);
	test_int("Random int + '-' flag + ' ' flag + '5' width", "%- 5d", "42", 42);
	test_int("Random int + '-' flag + ' ' flag + '5' width -- reverse order", "% -5d", "42", 42);
	test_int("Random int + '-' flag + ' ' flag + '5' width -- flags alternate", "%----    ---5d", "42", 42);
	test_int("Random int + '-' flag + '1' width -- width < nb digits", "%-1d", "42", 42);
	test_char("Random char + 'hh' modifier", "%hhd", "42", (char)42);
	test_char("Random char + 'hh' modifier", "%hhd", "298", (char)298);
	test_short("Short max + 'h' modifier", "%hd", "32767", SHRT_MAX);
	test_short("Short max + 1 + 'h' modifier", "%hd", "32767", (short)(SHRT_MAX + 1));
	test_long("Long max + 'l' modifier", "%ld", "9223372036854775807", LONG_MAX);
	test_long_long("Long long max + 'll' modifier", "%lld", "9223372036854775807", LLONG_MAX);
	test_long_long("Long long max + 'L' length modifier", "%Ld", "9223372036854775807", LLONG_MAX);
	print_h2("=> Invalid format:");
	test_int("Random int + '+' flag + ' ' flag -- ' ' flag ignored", "%+ d", "42", 42);
	test_int("Random int + '-' flag + '0' flag -- '0' flag ignored", "%-05d", "42", 42);
	test_int("Random int + invalid conversion specifier", "%=d", "42", 42);
	test_int("Random int + '+' flag + '0' flag + invalid conversion specifier", "%+0=d", "42", 42);
	test_int("Random int + '+' flag + invalid conversion specifier -- alternate", "%+=+d", "42", 42);
	test_int("Random int + \% sign only", "%", "42", 42);
	test_int("Random int + \% sign + '5' width -- no type", "%5", "42", 42);
}

void	test_type_octal(void)
{
	print_h1("TYPE: OCTAL (%d | %i)");
	print_h2("=> Valid format:");
	test_int("Zero", "%o", "0", 0);
	test_int("Zero + . precision", "%.o", "0", 0);
	test_int("Zero + .3 precision", "%.3o", "0", 0);
	test_int("Random int", "%o", "42", 42);
	test_int("Random int + 'INT_MAX + 1' width", "%2147483648o", "42", 42);
	test_int("Random int + 'INT_MAX + 1' precision", "%.2147483648o", "42", 42);
	test_int("Int max", "%o", "2147483647", INT_MAX);
	test_int("Int max + 1", "%o", "2147483648", INT_MAX + 1);
	test_int("Int min", "%o", "-2147483648", INT_MIN);
	test_int("Unsigned int max", "%o", "4294967295", UINT_MAX);
	test_int("Random int + '.1' precision -- precision < nb digits", "%.1o", "42", 42);
	test_int("Random int + '.4' precision -- precision > nb digits", "%.1o", "42", 42);
	test_int("Random int + '3' width + '.5' precision -- precision > width", "%3.5o", "42", 42);
	test_int("Random int + '5' width + '.3' precision -- precision < width", "%5.3o", "42", 42);
	test_int("Random int + '0' flag", "%0o", "42", 42);
	test_int("Random int + '0' flag + '5' width", "%05o", "42", 42);
	test_int("Random int + multiple '0' flags + '5' width", "%00005o", "42", 42);
	test_int("Random int + '+' flag", "%+o", "42", 42);
	test_int("Random int + multiple '+' flags", "%++++o", "42", 42);
	test_int("Random int + ' ' flag + '0' flag + '5' width", "% 05o", "42", 42);
	test_int("Random int + '+' flag + '0' flag + '5' width", "%+05o", "42", 42);
	test_int("Random int + '+' flag + '0' flag + '5' width -- flags in reverse order", "%0+5o", "42", 42);
	test_int("Random int + multiple '+' flags  + multiple '0' flags + '5' width", "%+++++000005o", "42", 42);
	test_int("Random int + ' ' flag", "% o", "42", 42);
	test_int("Random int + multiple ' ' flags", "%     o", "42", 42);
	test_int("Random int + 5 width", "%5o", "42", 42);
	test_int("Random int + '+' flag + '5' width", "%+5o", "42", 42);
	test_int("Random int + '1' width -- width < nb digits", "%1o", "42", 42);
	test_int("Random int + '-' flag + '5' width", "%-5o", "42", 42);
	test_int("Random int + multiple '-' flags", "%------5o", "42", 42);
	test_int("Random int + '-' flag + '+' flag + '5' width", "%-+5o", "42", 42);
	test_int("Random int + '-' flag + '+' flag + '5' width -- flags alternate", "%---++++---5o", "42", 42);
	test_int("Random int + '-' flag + ' ' flag + '5' width", "%- 5o", "42", 42);
	test_int("Random int + '-' flag + ' ' flag + '5' width -- reverse order", "% -5o", "42", 42);
	test_int("Random int + '-' flag + ' ' flag + '5' width -- flags alternate", "%----    ---5o", "42", 42);
	test_int("Random int + '-' flag + '1' width -- width < nb digits", "%-1o", "42", 42);
	test_char("Random char + 'hh' modifier", "%hho", "42", (char)42);
	test_char("Random char + 'hh' modifier", "%hho", "298", (char)298);
	test_short("Short max + 'h' modifier", "%ho", "32767", SHRT_MAX);
	test_short("Short max + 1 + 'h' modifier", "%ho", "32767", (short)(SHRT_MAX + 1));
	test_long("Long max + 'l' modifier", "%lo", "9223372036854775807", LONG_MAX);
	test_long_long("Long long max + 'll' modifier", "%llo", "9223372036854775807", LLONG_MAX);
	test_long_long("Long long max + 'L' length modifier", "%Lo", "9223372036854775807", LLONG_MAX);
	print_h2("=> Invalid format:");
	test_int("Random int + '+' flag + ' ' flag -- ' ' flag ignored", "%+ o", "42", 42);
	test_int("Random int + '-' flag + '0' flag -- '0' flag ignored", "%-05o", "42", 42);
	test_int("Random int + invalid conversion specifier", "%=o", "42", 42);
	test_int("Random int + '+' flag + '0' flag + invalid conversion specifier", "%+0=o", "42", 42);
	test_int("Random int + '+' flag + invalid conversion specifier -- alternate", "%+=+o", "42", 42);
	test_int("Random int + \% sign only", "%", "42", 42);
	test_int("Random int + \% sign + '5' width -- no typo", "%5", "42", 42);
}

//void	test_type_octal(void)
//{
//	print_h1("TYPE: OCTAL (%o)");
//	print_h2("=> Valid format:");
//	test_int("Random int", "%o", "42", 42);
//	test_int("Random int with # flag", "%#o", "42", 42);
//	test_int("Random int with 5 spaces filled with 0 and # flag", "%0#5o", "42", 42);
//	test_int("Random int with multiple # flags", "%######o", "42", 42);
//	test_int("Int max", "%o", "2147483647", INT_MAX);
//	test_int("Int max + 1", "%o", "2147483648", INT_MAX + 1);
//	test_int("Int min", "%o", "-2147483648", INT_MIN);
//	test_int("Unsigned int max", "%o", "4294967295", UINT_MAX);
//	test_int("Random int filled with 0", "%0o", "42", 42);
//	test_int("Random int with 5 spaces filled with 0", "%05o", "42", 42);
//	test_int("Random int with 5 spaces", "%5o", "42", 42);
//	test_int("Random int with 1 space", "%1o", "42", 42);
//	test_int("Random int left aligned with 5 spaces", "%-5o", "42", 42);
//	test_int("Random int left aligned with 1 space", "%-1o", "42", 42);
//	test_char("Random char with hh length modifier", "%hho", "298", (char)42);
//	test_char("Random char with hh length modifier", "%hho", "298", (char)298);
//	test_short("Short max with h length modifier", "%ho", "32767", SHRT_MAX);
//	test_short("Short max + 1 with h length modifier", "%ho", "32767", (short)(SHRT_MAX + 1));
//	test_long("Long max with l length modifier", "%lo", "9223372036854775807", LONG_MAX);
//	test_long_long("Long long max with ll length modifier", "%llo", "9223372036854775807", LLONG_MAX);
//	test_long_long("Long long max with L length modifier", "%Lo", "9223372036854775807", LLONG_MAX);
//}

void	test_type_unsigned_int(void)
{
	print_h1("TYPE: UNSIGNED INT (%u)");
	print_h2("=> Valid format:");
	test_unsigned_int("Random unsigned int", "%u", "42u", 42u);
	test_unsigned_int("Int max + 1", "%u", "2147483648", INT_MAX + 1);
	test_unsigned_int("Unsigned int max", "%u", "4294967295", UINT_MAX);
	test_unsigned_int("Unsigned int max + 1", "%u", "4294967296", UINT_MAX + 1);
	test_unsigned_int("Negative number", "%u", "-1", -1);
	test_unsigned_int("Random unsigned int with 5 width", "%5u", "42u", 42u);
	test_unsigned_int("Random unsigned int with 5 width and - flag", "%-5u", "42u", 42u);
	test_unsigned_int("Random unsigned int with 5 width and .3 precision", "%5.3u", "42u", 42u);
	test_unsigned_int("Random unsigned int with 5 width and .3 precision and - flag", "%-5.3u", "42u", 42u);
	test_unsigned_int("Random unsigned int with 3 width and .5 precision", "%3.5u", "42u", 42u);
	test_unsigned_int("Random unsigned int with 3 width and .5 precision", "%3.5u", "42u", 42u);
	test_unsigned_char("Unsigned char max with hh length modifier", "%hhu", "255", (unsigned char)UCHAR_MAX);
	test_unsigned_char("Unsigned char max + 1  with hh length modifier", "%hhu", "256", (unsigned char)(UCHAR_MAX + 1));
	test_unsigned_long("Unsigned long max with l length modifier", "%lu", "18446744073709551615", (unsigned long)ULONG_MAX);
}

void	test_type_hexadecimal_x(void)
{
	print_h1("TYPE: HEXADECIMAL (%x)");
	print_h2("=> Valid format:");
	test_unsigned_int("Random unsigned int", "%x", "42u", 42u);
	test_unsigned_int("Zero", "%x", "0u", 0u);
	test_unsigned_int("Zero with .0 precision", "%.x", "0u", 0u);
	test_unsigned_int("Zero with .3 precision", "%.3x", "0u", 0u);
	test_unsigned_int("Unsigned int max", "%x", "4294967295u", UINT_MAX);
	test_unsigned_int("Unsigned int max + 1", "%x", "4294967296u", UINT_MAX + 1);
	test_unsigned_int("Random unsigned int with 5 width", "%5x", "42u", 42u);
	test_unsigned_int("Random unsigned int with 5 width and # flag", "%#5x", "42u", 42u);
	test_unsigned_int("Random unsigned int with 5 width and # flag and .3 precision", "%#5.3x", "42u", 42u);
	test_unsigned_int("Random unsigned int with 10 width and # and 0 flags", "%#010x", "42u", 42u);
	test_unsigned_int("Random unsigned int with 5 width and - flag", "%-5x", "42u", 42u);
	test_unsigned_int("Random unsigned int with 5 width and 0 flag", "%05x", "42u", 42u);
}

void	test_type_hexadecimal_X(void)
{
	print_h1("TYPE: HEXADECIMAL (%X)");
	print_h2("=> Valid format:");
	test_unsigned_int("Random unsigned int", "%X", "42u", 42u);
	test_unsigned_int("Zero", "%X", "0u", 0u);
	test_unsigned_int("Zero with .0 precision", "%.X", "0u", 0u);
	test_unsigned_int("Zero with .3 precision", "%.3X", "0u", 0u);
	test_unsigned_int("Unsigned int max", "%X", "4294967295u", UINT_MAX);
	test_unsigned_int("Unsigned int max + 1", "%X", "4294967296u", UINT_MAX + 1);
	test_unsigned_int("Random unsigned int with 5 width", "%5X", "42u", 42u);
	test_unsigned_int("Random unsigned int with 5 width and # flag", "%#5X", "42u", 42u);
	test_unsigned_int("Random unsigned int with 5 width and # flag and .3 precision", "%#5.3X", "42u", 42u);
	test_unsigned_int("Random unsigned int with 10 width and # and 0 flags", "%#010X", "42u", 42u);
	test_unsigned_int("Random unsigned int with 5 width and - flag", "%-5X", "42u", 42u);
	test_unsigned_int("Random unsigned int with 5 width and 0 flag", "%05X", "42u", 42u);
}

void	test_type_float_f(void)
{
	print_h1("TYPE: FLOAT (%f)");
	print_h2("=> Valid format:");
	test_float("Zero float:", "%f", "0.f", 0.f);
	test_float("Random float:", "%f", "42.f", 42.f);
	test_float("Negative number:", "%f", "-42.f", -42.f);
	test_float("Number with null integer part and 3 digits decimal part", "%f", ".123f", .123f);
	test_float("Number with null integer part and 7 digits decimal part", "%f", ".1234567f", .1234567f);
	test_float("Number with 1 digit integer part and 7 digits decimal part", "%f", "1.1234567f", 1.1234567f);
	test_float("Number with 2 digits integer part and 7 digits decimal part", "%f", "12.1234567f", 12.1234567f);
	test_float("Number with 3 digits integer part and 7 digits decimal part", "%f", "123.1234567f", 123.1234567f);
	test_float("Number with 4 digits integer part and 7 digits decimal part", "%f", "1234.1234567f", 1234.1234567f);
}

int		main(int ac, char **av)
{
	char	*str;
	void	(*tab_test[])(void) = {
		&test_type_char, 
		&test_type_int, 
		&test_type_octal,
		&test_type_unsigned_int,
		&test_type_hexadecimal_x,
		&test_type_hexadecimal_X,
		&test_type_float_f
	};
	int		i;

	if (ac == 1)
	{
		i = -1;
		while (++i < sizeof(tab_test)/sizeof(tab_test[0]))
			(*tab_test[i])();
	}
	else if (ac == 2)
	{
		if (!strcmp(av[1],"char"))
			test_type_char();
		else if (!strcmp(av[1],"int"))
			test_type_int();
		else if (!strcmp(av[1],"octal"))
			test_type_octal();
		else if (!strcmp(av[1],"unsigned_int"))
			test_type_unsigned_int();
		else if (!strcmp(av[1],"hexa_x"))
			test_type_hexadecimal_x();
		else if (!strcmp(av[1],"hexa_X"))
			test_type_hexadecimal_X();
		else if (!strcmp(av[1],"float_f"))
			test_type_float_f();
		else
			printf("%s\n", "Unknown category");
	}
	else
	{
		printf("%s\n", "Wrong number of arguments, 0 or 1 expected.");
	}
	printf("\n");
	printf("|%o|\n", 0);
	printf("|%o|\n", 0);
	printf("|%.o|\n", 0);
	printf("|%.3o|\n", 0);
	printf("|%o|\n", 42);
	printf("|%2147483648o|\n", 42);
	printf("|%.2147483648o|\n", 42);
	printf("|%o|\n", INT_MAX);
	printf("|%o|\n", INT_MAX + 1);
	printf("|%o|\n", INT_MIN);
	printf("|%o|\n", UINT_MAX);
	printf("|%.1o|\n", 42);
	printf("|%.1o|\n", 42);
	printf("|%3.5o|\n", 42);
	printf("|%5.3o|\n", 42);
	printf("|%0o|\n", 42);
	printf("|%05o|\n", 42);
	printf("|%00005o|\n", 42);
	printf("|%+o|\n", 42);
	printf("|%++++o|\n", 42);
	printf("|% 05o|\n", 42);
	printf("|%+05o|\n", 42);
	printf("|%0+5o|\n", 42);
	printf("|%+++++000005o|\n", 42);
	printf("|% o|\n", 42);
	printf("|%     o|\n", 42);
	printf("|%5o|\n", 42);
	printf("|%+5o|\n", 42);
	printf("|%1o|\n", 42);
	printf("|%-5o|\n", 42);
	printf("|%------5o|\n", 42);
	printf("|%-+5o|\n", 42);
	printf("|%---++++---5o|\n", 42);
	printf("|%- 5o|\n", 42);
	printf("|% -5o|\n", 42);
	printf("|%----    ---5o|\n", 42);
	printf("|%-1o|\n", 42);
	printf("|%hho|\n", (char)42);
	printf("|%hho|\n", (char)298);
	printf("|%ho|\n", SHRT_MAX);
	printf("|%ho|\n", (short)(SHRT_MAX + 1));
	printf("|%lo|\n", LONG_MAX);
	printf("|%llo|\n", LLONG_MAX);
	printf("|%Lo|\n", LLONG_MAX);
	return (0);
}
