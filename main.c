/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkettani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 11:24:15 by jkettani          #+#    #+#             */
/*   Updated: 2019/01/16 14:42:25 by jkettani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <limits.h>
#define BOLD "\x1b[1m"
#define UNDERLINE "\x1b[4m"
#define NC "\x1b[0m"
#define RED "\x1b[31m"
#define GREEN "\x1b[32m"
#define YELLOW "\x1b[33m"
#define BLUE "\x1b[34m"
#define MAGENTA "\x1b[35m"

void	print_h1(char *str)
{
	printf(UNDERLINE "\n%s\n" NC, str);
}

void	print_h2(char *str)
{
	printf(BOLD "\n%s\n\n" NC, str);
}

void	test_desc(char *desc, char *fmt, char *test_str)
{
	printf(" > %s (", desc);
	printf("\"|");
	printf(MAGENTA "%s" NC, fmt);
	printf("|\", |");
	printf(BLUE "%s" NC, test_str);
	printf("|): ");
}

void	test_char(char *desc, char *fmt, char *test_str, char test)
{
	test_desc(desc, fmt, test_str);
	printf("|" YELLOW);
	printf(fmt, test);
	printf(NC "|");
	printf("\n");
}

void	test_unsigned_char(char *desc, char *fmt, char *test_str, unsigned char test)
{
	test_desc(desc, fmt, test_str);
	printf("|" YELLOW);
	printf(fmt, test);
	printf(NC "|");
	printf("\n");
}

void	test_int(char *desc, char *fmt, char *test_str, int test)
{
	test_desc(desc, fmt, test_str);
	printf("|" YELLOW);
	printf(fmt, test);
	printf(NC "|");
	printf("\n");
}

void	test_unsigned_int(char *desc, char *fmt, char *test_str, unsigned int test)
{
	test_desc(desc, fmt, test_str);
	printf("|" YELLOW);
	printf(fmt, test);
	printf(NC "|");
	printf("\n");
}

void	test_short(char *desc, char *fmt, char *test_str, short test)
{
	test_desc(desc, fmt, test_str);
	printf("|" YELLOW);
	printf(fmt, test);
	printf(NC "|");
	printf("\n");
}

void	test_long(char *desc, char *fmt, char *test_str, long test)
{
	test_desc(desc, fmt, test_str);
	printf("|" YELLOW);
	printf(fmt, test);
	printf(NC "|");
	printf("\n");
}

void	test_unsigned_long(char *desc, char *fmt, char *test_str, unsigned long test)
{
	test_desc(desc, fmt, test_str);
	printf("|" YELLOW);
	printf(fmt, test);
	printf(NC "|");
	printf("\n");
}

void	test_long_long(char *desc, char *fmt, char *test_str, long long test)
{
	test_desc(desc, fmt, test_str);
	printf("|" YELLOW);
	printf(fmt, test);
	printf(NC "|");
	printf("\n");
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
	test_int("Zero with .0 precision", "%.d", "0", 0);
	test_int("Zero with .3 precision", "%.3d", "0", 0);
	test_int("Random int", "%d", "42", 42);
	test_int("Int max", "%d", "2147483647", INT_MAX);
	test_int("Int max + 1", "%d", "2147483648", INT_MAX + 1);
	test_int("Int min", "%d", "-2147483648", INT_MIN);
	test_int("Unsigned int max", "%d", "4294967295", UINT_MAX);
	test_int("Random int with precision .1", "%.1d", "42", 42);
	test_int("Random int with precision .4", "%.1d", "42", 42);
	test_int("Random int with 3 width and .5 precision -- precision > width", "%3.5d", "42", 42);
	test_int("Random int with 5 width and .3 precision -- precision < width", "%5.3d", "42", 42);
	test_int("Random int filled with 0", "%0d", "42", 42);
	test_int("Random int with 5 spaces filled with 0", "%05d", "42", 42);
	test_int("Random int with 5 spaces filled with 0 -- multiple 0", "%00005d", "42", 42);
	test_int("Random int with + sign", "%+d", "42", 42);
	test_int("Random int with multiple + signs", "%++++d", "42", 42);
	test_int("Random int with 5 spaces filled with 0 and space instead of + sign", "% 05d", "42", 42);
	test_int("Random int with + sign and 5 spaces filled with 0", "%+05d", "42", 42);
	test_int("Random int with + sign and 5 spaces filled with 0 -- 0 and + sign in reverse order", "%0+5d", "42", 42);
	test_int("Random int with multiple + signs and 5 spaces filled with multiple 0", "%+++++000005d", "42", 42);
	test_int("Random int and space instead of + sign", "% d", "42", 42);
	test_int("Random int and multiple spaces instead of + signs", "%     d", "42", 42);
	test_int("Random int with 5 spaces", "%5d", "42", 42);
	test_int("Random int with 5 spaces and + sign", "%+5d", "42", 42);
	test_int("Random int with 1 space", "%1d", "42", 42);
	test_int("Random int left aligned with 5 spaces", "%-5d", "42", 42);
	test_int("Random int left aligned with 5 spaces -- multiple - signs", "%------5d", "42", 42);
	test_int("Random int left aligned with 5 spaces and + sign", "%-+5d", "42", 42);
	test_int("Random int left aligned with 5 spaces and + sign -- multiple - and + signs", "%---++++---5d", "42", 42);
	test_int("Random int left aligned with 5 spaces and space instead of + sign", "%- 5d", "42", 42);
	test_int("Random int left aligned with 5 spaces and space instead of + sign -- reverse order", "% -5d", "42", 42);
	test_int("Random int left aligned with 5 spaces and space instead of + sign -- multiple - and spaces", "%----    ---5d", "42", 42);
	test_int("Random int left aligned with 1 space", "%-1d", "42", 42);
	test_char("Random char with hh length modifier", "%hhd", "298", (char)42);
	test_char("Random char with hh length modifier", "%hhd", "298", (char)298);
	test_short("Short max with h length modifier", "%hd", "32767", SHRT_MAX);
	test_short("Short max + 1 with h length modifier", "%hd", "32767", (short)(SHRT_MAX + 1));
	test_long("Long max with l length modifier", "%ld", "9223372036854775807", LONG_MAX);
	test_long_long("Long long max with ll length modifier", "%lld", "9223372036854775807", LLONG_MAX);
	test_long_long("Long long max with L length modifier", "%Ld", "9223372036854775807", LLONG_MAX);
}

void	test_type_octal(void)
{
	print_h1("TYPE: OCTAL (%o)");
	print_h2("=> Valid format:");
	test_int("Random int", "%o", "42", 42);
	test_int("Random int with # flag", "%#o", "42", 42);
	test_int("Random int with 5 spaces filled with 0 and # flag", "%0#5o", "42", 42);
	test_int("Random int with multiple # flags", "%######o", "42", 42);
	test_int("Int max", "%o", "2147483647", INT_MAX);
	test_int("Int max + 1", "%o", "2147483648", INT_MAX + 1);
	test_int("Int min", "%o", "-2147483648", INT_MIN);
	test_int("Unsigned int max", "%o", "4294967295", UINT_MAX);
	test_int("Random int filled with 0", "%0o", "42", 42);
	test_int("Random int with 5 spaces filled with 0", "%05o", "42", 42);
	test_int("Random int with 5 spaces", "%5o", "42", 42);
	test_int("Random int with 1 space", "%1o", "42", 42);
	test_int("Random int left aligned with 5 spaces", "%-5o", "42", 42);
	test_int("Random int left aligned with 1 space", "%-1o", "42", 42);
	test_char("Random char with hh length modifier", "%hho", "298", (char)42);
	test_char("Random char with hh length modifier", "%hho", "298", (char)298);
	test_short("Short max with h length modifier", "%ho", "32767", SHRT_MAX);
	test_short("Short max + 1 with h length modifier", "%ho", "32767", (short)(SHRT_MAX + 1));
	test_long("Long max with l length modifier", "%lo", "9223372036854775807", LONG_MAX);
	test_long_long("Long long max with ll length modifier", "%llo", "9223372036854775807", LLONG_MAX);
	test_long_long("Long long max with L length modifier", "%Lo", "9223372036854775807", LLONG_MAX);
}

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

int		main(int ac, char **av)
{
	(void)ac;
	(void)av;
	//CHAR
	test_type_char();
	//INT
	test_type_int();
	//OCTAL
	test_type_octal();
	//UNSIGNED INT
	test_type_unsigned_int();
	//HEXADECIMAL x
	test_type_hexadecimal_x();
	//HEXADECIMAL X
	test_type_hexadecimal_X();
	printf("\n");
	printf("|%#010x|\n", 42);
	return (0);
}
