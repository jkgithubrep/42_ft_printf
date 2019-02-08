/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_output_tests.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkettani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/05 17:33:49 by jkettani          #+#    #+#             */
/*   Updated: 2019/02/08 15:09:36 by jkettani         ###   ########.fr       */
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

void	test_unsigned_short(char *desc, char *fmt, char *test_str, unsigned short test)
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

void	test_unsigned_long_long(char *desc, char *fmt, char *test_str, unsigned long long test)
{
	PRINTF_TEST;
}

void	test_float(char *desc, char *fmt, char *test_str, float test)
{
	PRINTF_TEST;
}


void	test_type_int(void)
{
	print_h1("TYPE: INT (%d | %i)");
	print_h2("=> Valid format:");
	test_int("Zero", "%d", "0", 0);
	test_int("Zero + . precision", "%.d", "0", 0);
	test_int("Zero + .3 precision", "%.3d", "0", 0);
	test_int("Random int", "%d", "42", 42);
//	test_int("Random int + 'INT_MAX + 1' width", "%2147483648d", "42", 42);
//	test_int("Random int + 'INT_MAX + 1' precision", "%.2147483648d", "42", 42);
	test_int("Random int + 'UINT_MAX' width", "%4294967295d", "42", 42);
	test_int("Int max", "%d", "2147483647", INT_MAX);
	test_int("Int max + 1 -- overflow", "%d", "2147483648", INT_MAX + 1);
	test_int("Int min", "%d", "-2147483648", INT_MIN);
	test_int("Unsigned int max -- overflow", "%d", "4294967295", UINT_MAX);
	test_int("Random int + '.1' precision -- precision < nb digits", "%.1d", "42", 42);
	test_int("Random int + '.4' precision -- precision > nb digits", "%.4d", "42", 42);
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
	test_int("Random int + '+' flag + '5' width -- width before flag -- invalid conversion specifier", "%5+d", "42", 42);
	test_int("Random int + '+' flag + '5' width  + '........3' precision -- invalid conversion specifier", "%+5.......3d", "42", 42);
	test_int("Random int + '#' flag -- undefined behavior", "%#d", "42", 42);
	test_int("Random int + '+' flag + ' ' flag -- ' ' flag ignored", "%+ d", "42", 42);
	test_int("Random int + '-' flag + '0' flag -- '0' flag ignored", "%-05d", "42", 42);
	test_int("Random int + invalid conversion specifier", "%=d", "42", 42);
	test_int("Random int + '+' flag + '0' flag + invalid conversion specifier", "%+0=d", "42", 42);
	test_int("Random int + '+' flag + invalid conversion specifier -- alternate", "%+=+d", "42", 42);
	test_int("Random int + \% sign only", "%", "42", 42);
	test_int("Random int + \% sign + '5' width -- no type", "%5", "42", 42);
}

void	test_type_unsigned_octal(void)
{
	print_h1("TYPE: OCTAL (%d | %i)");
	print_h2("=> Valid format:");
	test_unsigned_int("Zero", "%o", "0U", 0U);
	test_unsigned_int("Zero + . precision", "%.o", "0U", 0U);
	test_unsigned_int("Zero + .3 precision", "%.3o", "0U", 0U);
	test_unsigned_int("Random unsigned int", "%o", "42U", 42U);
	test_unsigned_int("Random unsigned int + 'UINT_MAX + 1' width", "%4294967295o", "42U", 42U);
	test_unsigned_int("Random unsigned int + 'UINT_MAX + 1' precision", "%.4294967295o", "42U", 42U);
	test_unsigned_int("Unsigned int max", "%o", "4294967295", UINT_MAX);
	test_unsigned_int("Unsigned int max + 1", "%o", "4294967296", UINT_MAX + 1);
	test_unsigned_int("Random unsigned int + '.1' precision -- precision < nb digits", "%.1o", "42U", 42U);
	test_unsigned_int("Random unsigned int + '.4' precision -- precision > nb digits", "%.4o", "42U", 42U);
	test_unsigned_int("Random unsigned int + '3' width + '.5' precision -- precision > width", "%3.5o", "42U", 42U);
	test_unsigned_int("Random unsigned int + '5' width + '.3' precision -- precision < width", "%5.3o", "42U", 42U);
	test_unsigned_int("Random unsigned int + '0' flag", "%0o", "42U", 42U);
	test_unsigned_int("Random unsigned int + '0' flag + '5' width", "%05o", "42U", 42U);
	test_unsigned_int("Random unsigned int + multiple '0' flags + '5' width", "%00005o", "42U", 42U);
	test_unsigned_int("Random unsigned int + 5 width", "%5o", "42U", 42U);
	test_unsigned_int("Random unsigned int + '1' width -- width < nb digits", "%1o", "42U", 42U);
	test_unsigned_int("Random unsigned int + '-' flag + '5' width", "%-5o", "42U", 42U);
	test_unsigned_int("Random unsigned int + multiple '-' flags", "%------5o", "42U", 42U);
	test_unsigned_int("Random unsigned int + '-' flag + '1' width -- width < nb digits", "%-1o", "42U", 42U);
	test_unsigned_int("Random unsigned int + '#' flag + '5' width", "%#5o", "42U", 42U);
	test_unsigned_int("Random unsigned int + '#' flag + '5' width + '.4' precision", "%#5.4o", "42U", 42U);
	test_unsigned_char("Random unsigned char + 'hh' modifier", "%hho", "(unsigned char)'*'", (unsigned char)'*');
	test_unsigned_char("Random unsigned char + 'hh' modifier", "%hho", "(unsigned char)298u", (unsigned char)298u);
	test_unsigned_short("Unsigned short max + 'h' modifier", "%ho", "(unsigned short)USHRT_MAX", (unsigned short)USHRT_MAX);
	test_unsigned_short("Unsigned short max + 1 + 'h' modifier", "%ho", "(unsigned short)(USHRT_MAX + 1)", (unsigned short)(USHRT_MAX + 1));
	test_unsigned_long("Unsigned long max + 'l' modifier", "%lo", "(unsigned long)ULONG_MAX", (unsigned long)ULONG_MAX);
	test_unsigned_long_long("Unsigned long long max + 'll' modifier", "%llo", "(unsigned long long)ULLONG_MAX", (unsigned long long)ULLONG_MAX);
	test_unsigned_long_long("Unsigned long long max + 'L' length modifier", "%Lo", "ULLONG_MAX", ULLONG_MAX);
	print_h2("=> Invalid format:");
	test_unsigned_int("Random unsigned int + '+' flag -- flag '+' undefined behavior", "%+o", "42U", 42U);
	test_unsigned_int("Random unsigned int + multiple '+' flags -- flag '+' undefined behavior", "%++++o", "42U", 42U);
	test_unsigned_int("Random unsigned int + ' ' flag + '0' flag + '5' width -- flag ' ' undefined behavior", "% 05o", "42U", 42U);
	test_unsigned_int("Random unsigned int + '+' flag + '0' flag + '5' width -- flag '+' undefined behavior", "%+05o", "42U", 42U);
	test_unsigned_int("Random unsigned int + '+' flag + '0' flag + '5' width -- flag '+' undefined behavior", "%0+5o", "42U", 42U);
	test_unsigned_int("Random unsigned int + multiple '+' flags  + multiple '0' flags + '5' width -- flag '+' undefined behavior", "%+++++000005o", "42U", 42U);
	test_unsigned_int("Random unsigned int + ' ' flag -- flag ' ' undefined behavior", "% o", "42U", 42U);
	test_unsigned_int("Random unsigned int + multiple ' ' flags -- flag ' ' undefined behavior", "%     o", "42U", 42U);
	test_unsigned_int("Random unsigned int + '+' flag + '5' width -- flag '+' undefined behavior", "%+5o", "42U", 42U);
	test_unsigned_int("Random unsigned int + '-' flag + '+' flag + '5' width -- flag '+' undefined behavior", "%-+5o", "42U", 42U);
	test_unsigned_int("Random unsigned int + '-' flag + '+' flag + '5' width -- flag '+' undefined behavior", "%---++++---5o", "42U", 42U);
	test_unsigned_int("Random unsigned int + '-' flag + ' ' flag + '5' width -- flag ' ' undefined behavior", "%- 5o", "42U", 42U);
	test_unsigned_int("Random unsigned int + '-' flag + ' ' flag + '5' width -- flag ' ' undefined behavior", "% -5o", "42U", 42U);
	test_unsigned_int("Random unsigned int + '-' flag + ' ' flag + '5' width -- flag ' ' undefined behavior", "%----    ---5o", "42U", 42U);
}

void	test_type_unsigned_int(void)
{
	print_h1("TYPE: UNSIGNED INT (%u)");
	print_h2("=> Valid format:");
	test_unsigned_int("Zero", "%u", "0U", 0U);
	test_unsigned_int("Zero + . precision", "%.u", "0U", 0U);
	test_unsigned_int("Zero + .3 precision", "%.3u", "0U", 0U);
	test_unsigned_int("Random unsigned int", "%u", "42U", 42U);
	test_unsigned_int("Random unsigned int + 'UINT_MAX + 1' width", "%4294967295u", "42U", 42U);
	test_unsigned_int("Random unsigned int + 'UINT_MAX + 1' precision", "%.4294967295u", "42U", 42U);
	test_unsigned_int("Unsigned int max", "%u", "4294967295", UINT_MAX);
	test_unsigned_int("Unsigned int max + 1", "%u", "4294967296", UINT_MAX + 1);
	test_unsigned_int("Random unsigned int + '.1' precision -- precision < nb digits", "%.1u", "42U", 42U);
	test_unsigned_int("Random unsigned int + '.4' precision -- precision > nb digits", "%.4u", "42U", 42U);
	test_unsigned_int("Random unsigned int + '3' width + '.5' precision -- precision > width", "%3.5u", "42U", 42U);
	test_unsigned_int("Random unsigned int + '5' width + '.3' precision -- precision < width", "%5.3u", "42U", 42U);
	test_unsigned_int("Random unsigned int + '0' flag", "%0u", "42U", 42U);
	test_unsigned_int("Random unsigned int + '0' flag + '5' width", "%05u", "42U", 42U);
	test_unsigned_int("Random unsigned int + multiple '0' flags + '5' width", "%00005u", "42U", 42U);
	test_unsigned_int("Random unsigned int + 5 width", "%5u", "42U", 42U);
	test_unsigned_int("Random unsigned int + '1' width -- width < nb digits", "%1u", "42U", 42U);
	test_unsigned_int("Random unsigned int + '-' flag + '5' width", "%-5u", "42U", 42U);
	test_unsigned_int("Random unsigned int + multiple '-' flags", "%------5u", "42U", 42U);
	test_unsigned_int("Random unsigned int + '-' flag + '1' width -- width < nb digits", "%-1u", "42U", 42U);
	test_unsigned_char("Random unsigned char + 'hh' modifier", "%hhu", "(unsigned char)'*'", (unsigned char)'*');
	test_unsigned_char("Random unsigned char + 'hh' modifier", "%hhu", "(unsigned char)298u", (unsigned char)298U);
	test_unsigned_short("Unsigned short max + 'h' modifier", "%hu", "(unsigned short)USHRT_MAX", (unsigned short)USHRT_MAX);
	test_unsigned_short("Unsigned short max + 1 + 'h' modifier", "%hu", "(unsigned short)(USHRT_MAX + 1)", (unsigned short)(USHRT_MAX + 1));
	test_unsigned_long("Unsigned long max + 'l' modifier", "%lu", "(unsigned long)ULONG_MAX", (unsigned long)ULONG_MAX);
	test_unsigned_long_long("Unsigned long long max + 'll' modifier", "%llu", "(unsigned long long)ULLONG_MAX", (unsigned long long)ULLONG_MAX);
	test_unsigned_long_long("Unsigned long long max + 'L' length modifier", "%Lu", "ULLONG_MAX", ULLONG_MAX);
	print_h2("=> Invalid format:");
	test_unsigned_int("Random unsigned int + '+' flag -- flag '+' undefined behavior", "%+u", "42U", 42U);
	test_unsigned_int("Random unsigned int + multiple '+' flags -- flag '+' undefined behavior", "%++++u", "42U", 42U);
	test_unsigned_int("Random unsigned int + ' ' flag + '0' flag + '5' width -- flag ' ' undefined behavior", "% 05u", "42U", 42U);
	test_unsigned_int("Random unsigned int + '+' flag + '0' flag + '5' width -- flag '+' undefined behavior", "%+05u", "42U", 42U);
	test_unsigned_int("Random unsigned int + '+' flag + '0' flag + '5' width -- flag '+' undefined behavior", "%0+5u", "42U", 42U);
	test_unsigned_int("Random unsigned int + multiple '+' flags  + multiple '0' flags + '5' width -- flag '+' undefined behavior", "%+++++000005u", "42U", 42U);
	test_unsigned_int("Random unsigned int + ' ' flag -- flag ' ' undefined behavior", "% u", "42U", 42U);
	test_unsigned_int("Random unsigned int + multiple ' ' flags -- flag ' ' undefined behavior", "%     u", "42U", 42U);
	test_unsigned_int("Random unsigned int + '+' flag + '5' width -- flag '+' undefined behavior", "%+5u", "42U", 42U);
	test_unsigned_int("Random unsigned int + '-' flag + '+' flag + '5' width -- flag '+' undefined behavior", "%-+5u", "42U", 42U);
	test_unsigned_int("Random unsigned int + '-' flag + '+' flag + '5' width -- flag '+' undefined behavior", "%---++++---5u", "42U", 42U);
	test_unsigned_int("Random unsigned int + '-' flag + ' ' flag + '5' width -- flag ' ' undefined behavior", "%- 5u", "42U", 42U);
	test_unsigned_int("Random unsigned int + '-' flag + ' ' flag + '5' width -- flag ' ' undefined behavior", "% -5u", "42U", 42U);
	test_unsigned_int("Random unsigned int + '-' flag + ' ' flag + '5' width -- flag ' ' undefined behavior", "%----    ---5u", "42U", 42U);
	test_unsigned_int("Random unsigned int + '#' flag + '5' width -- flag '#' undefined behavior", "%#5u", "42U", 42U);
	test_unsigned_int("Random unsigned int + '#' flag + '5' width + '.4' precision -- flag '#' undefined behavior", "%#5.4u", "42U", 42U);
}

void	test_type_unsigned_hexadecimal_x(void)
{
	print_h1("TYPE: HEXADECIMAL (%x)");
	print_h2("=> Valid format:");
	test_unsigned_int("Zero", "%x", "0U", 0U);
	test_unsigned_int("Zero + . precision", "%.x", "0U", 0U);
	test_unsigned_int("Zero + .3 precision", "%.3x", "0U", 0U);
	test_unsigned_int("Random unsigned int", "%x", "42U", 42U);
	test_unsigned_int("Random unsigned int + 'UINT_MAX + 1' width", "%4294967295x", "42U", 42U);
	test_unsigned_int("Random unsigned int + 'UINT_MAX + 1' precision", "%.4294967295x", "42U", 42U);
	test_unsigned_int("Unsigned int max", "%x", "4294967295", UINT_MAX);
	test_unsigned_int("Unsigned int max + 1", "%x", "4294967296", UINT_MAX + 1);
	test_unsigned_int("Random unsigned int + '.1' precision -- precision < nb digits", "%.1x", "42U", 42U);
	test_unsigned_int("Random unsigned int + '.4' precision -- precision > nb digits", "%.4x", "42U", 42U);
	test_unsigned_int("Random unsigned int + '3' width + '.5' precision -- precision > width", "%3.5x", "42U", 42U);
	test_unsigned_int("Random unsigned int + '5' width + '.3' precision -- precision < width", "%5.3x", "42U", 42U);
	test_unsigned_int("Random unsigned int + '0' flag", "%0x", "42U", 42U);
	test_unsigned_int("Random unsigned int + '0' flag + '5' width", "%05x", "42U", 42U);
	test_unsigned_int("Random unsigned int + multiple '0' flags + '5' width", "%00005x", "42U", 42U);
	test_unsigned_int("Random unsigned int + 5 width", "%5x", "42U", 42U);
	test_unsigned_int("Random unsigned int + '1' width -- width < nb digits", "%1x", "42U", 42U);
	test_unsigned_int("Random unsigned int + '-' flag + '5' width", "%-5x", "42U", 42U);
	test_unsigned_int("Random unsigned int + multiple '-' flags", "%------5x", "42U", 42U);
	test_unsigned_int("Random unsigned int + '-' flag + '1' width -- width < nb digits", "%-1x", "42U", 42U);
	test_unsigned_int("Random unsigned int + '#' flag + '5' width", "%#5x", "42U", 42U);
	test_unsigned_int("Random unsigned int + '#' flag + '5' width + '.4' precision", "%#5.4x", "42U", 42U);
	test_unsigned_char("Random unsigned char + 'hh' modifier", "%hhx", "(unsigned char)'*'", (unsigned char)'*');
	test_unsigned_char("Random unsigned char + 'hh' modifier", "%hhx", "(unsigned char)298u", (unsigned char)298u);
	test_unsigned_short("Unsigned short max + 'h' modifier", "%hx", "(unsigned short)USHRT_MAX", (unsigned short)USHRT_MAX);
	test_unsigned_short("Unsigned short max + 1 + 'h' modifier", "%hx", "(unsigned short)(USHRT_MAX + 1)", (unsigned short)(USHRT_MAX + 1));
	test_unsigned_long("Unsigned long max + 'l' modifier", "%lx", "(unsigned long)ULONG_MAX", (unsigned long)ULONG_MAX);
	test_unsigned_long_long("Unsigned long long max + 'll' modifier", "%llx", "(unsigned long long)ULLONG_MAX", (unsigned long long)ULLONG_MAX);
	test_unsigned_long_long("Unsigned long long max + 'L' length modifier", "%Lx", "ULLONG_MAX", ULLONG_MAX);
	print_h2("=> Invalid format:");
	test_unsigned_int("Random unsigned int + '+' flag -- flag '+' undefined behavior", "%+x", "42U", 42U);
	test_unsigned_int("Random unsigned int + multiple '+' flags -- flag '+' undefined behavior", "%++++x", "42U", 42U);
	test_unsigned_int("Random unsigned int + ' ' flag + '0' flag + '5' width -- flag ' ' undefined behavior", "% 05x", "42U", 42U);
	test_unsigned_int("Random unsigned int + '+' flag + '0' flag + '5' width -- flag '+' undefined behavior", "%+05x", "42U", 42U);
	test_unsigned_int("Random unsigned int + '+' flag + '0' flag + '5' width -- flag '+' undefined behavior", "%0+5x", "42U", 42U);
	test_unsigned_int("Random unsigned int + multiple '+' flags  + multiple '0' flags + '5' width -- flag '+' undefined behavior", "%+++++000005x", "42U", 42U);
	test_unsigned_int("Random unsigned int + ' ' flag -- flag ' ' undefined behavior", "% x", "42U", 42U);
	test_unsigned_int("Random unsigned int + multiple ' ' flags -- flag ' ' undefined behavior", "%     x", "42U", 42U);
	test_unsigned_int("Random unsigned int + '+' flag + '5' width -- flag '+' undefined behavior", "%+5x", "42U", 42U);
	test_unsigned_int("Random unsigned int + '-' flag + '+' flag + '5' width -- flag '+' undefined behavior", "%-+5x", "42U", 42U);
	test_unsigned_int("Random unsigned int + '-' flag + '+' flag + '5' width -- flag '+' undefined behavior", "%---++++---5x", "42U", 42U);
	test_unsigned_int("Random unsigned int + '-' flag + ' ' flag + '5' width -- flag ' ' undefined behavior", "%- 5x", "42U", 42U);
	test_unsigned_int("Random unsigned int + '-' flag + ' ' flag + '5' width -- flag ' ' undefined behavior", "% -5x", "42U", 42U);
	test_unsigned_int("Random unsigned int + '-' flag + ' ' flag + '5' width -- flag ' ' undefined behavior", "%----    ---5x", "42U", 42U);
}

void	test_type_unsigned_hexadecimal_X(void)
{
	print_h1("TYPE: HEXADECIMAL (%X)");
	print_h2("=> Valid format:");
	test_unsigned_int("Zero", "%X", "0U", 0U);
	test_unsigned_int("Zero + . precision", "%.X", "0U", 0U);
	test_unsigned_int("Zero + .3 precision", "%.3X", "0U", 0U);
	test_unsigned_int("Random unsigned int", "%X", "42U", 42U);
	test_unsigned_int("Random unsigned int + 'UINT_MAX + 1' width", "%4294967295X", "42U", 42U);
	test_unsigned_int("Random unsigned int + 'UINT_MAX + 1' precision", "%.4294967295X", "42U", 42U);
	test_unsigned_int("Unsigned int maX", "%X", "4294967295", UINT_MAX);
	test_unsigned_int("Unsigned int max + 1", "%X", "4294967296", UINT_MAX + 1);
	test_unsigned_int("Random unsigned int + '.1' precision -- precision < nb digits", "%.1X", "42U", 42U);
	test_unsigned_int("Random unsigned int + '.4' precision -- precision > nb digits", "%.4X", "42U", 42U);
	test_unsigned_int("Random unsigned int + '3' width + '.5' precision -- precision > width", "%3.5X", "42U", 42U);
	test_unsigned_int("Random unsigned int + '5' width + '.3' precision -- precision < width", "%5.3X", "42U", 42U);
	test_unsigned_int("Random unsigned int + '0' flag", "%0X", "42U", 42U);
	test_unsigned_int("Random unsigned int + '0' flag + '5' width", "%05X", "42U", 42U);
	test_unsigned_int("Random unsigned int + multiple '0' flags + '5' width", "%00005X", "42U", 42U);
	test_unsigned_int("Random unsigned int + 5 width", "%5X", "42U", 42U);
	test_unsigned_int("Random unsigned int + '1' width -- width < nb digits", "%1X", "42U", 42U);
	test_unsigned_int("Random unsigned int + '-' flag + '5' width", "%-5X", "42U", 42U);
	test_unsigned_int("Random unsigned int + multiple '-' flags", "%------5X", "42U", 42U);
	test_unsigned_int("Random unsigned int + '-' flag + '1' width -- width < nb digits", "%-1X", "42U", 42U);
	test_unsigned_int("Random unsigned int + '#' flag + '5' width", "%#5X", "42U", 42U);
	test_unsigned_int("Random unsigned int + '#' flag + '5' width + '.4' precision", "%#5.4X", "42U", 42U);
	test_unsigned_char("Random unsigned char + 'hh' modifier", "%hhX", "(unsigned char)'*'", (unsigned char)'*');
	test_unsigned_char("Random unsigned char + 'hh' modifier", "%hhX", "(unsigned char)298u", (unsigned char)298u);
	test_unsigned_short("Unsigned short max + 'h' modifier", "%hX", "(unsigned short)USHRT_MAX", (unsigned short)USHRT_MAX);
	test_unsigned_short("Unsigned short max + 1 + 'h' modifier", "%hX", "(unsigned short)(USHRT_MAX + 1)", (unsigned short)(USHRT_MAX + 1));
	test_unsigned_long("Unsigned long max + 'l' modifier", "%lX", "(unsigned long)ULONG_MAX", (unsigned long)ULONG_MAX);
	test_unsigned_long_long("Unsigned long long max + 'll' modifier", "%llX", "(unsigned long long)ULLONG_MAX", (unsigned long long)ULLONG_MAX);
	test_unsigned_long_long("Unsigned long long max + 'L' length modifier", "%LX", "ULLONG_MAX", ULLONG_MAX);
	print_h2("=> Invalid format:");
	test_unsigned_int("Random unsigned int + '+' flag -- flag '+' undefined behavior", "%+X", "42U", 42U);
	test_unsigned_int("Random unsigned int + multiple '+' flags -- flag '+' undefined behavior", "%++++X", "42U", 42U);
	test_unsigned_int("Random unsigned int + ' ' flag + '0' flag + '5' width -- flag ' ' undefined behavior", "% 05X", "42U", 42U);
	test_unsigned_int("Random unsigned int + '+' flag + '0' flag + '5' width -- flag '+' undefined behavior", "%+05X", "42U", 42U);
	test_unsigned_int("Random unsigned int + '+' flag + '0' flag + '5' width -- flag '+' undefined behavior", "%0+5X", "42U", 42U);
	test_unsigned_int("Random unsigned int + multiple '+' flags  + multiple '0' flags + '5' width -- flag '+' undefined behavior", "%+++++000005X", "42U", 42U);
	test_unsigned_int("Random unsigned int + ' ' flag -- flag ' ' undefined behavior", "% X", "42U", 42U);
	test_unsigned_int("Random unsigned int + multiple ' ' flags -- flag ' ' undefined behavior", "%     X", "42U", 42U);
	test_unsigned_int("Random unsigned int + '+' flag + '5' width -- flag '+' undefined behavior", "%+5X", "42U", 42U);
	test_unsigned_int("Random unsigned int + '-' flag + '+' flag + '5' width -- flag '+' undefined behavior", "%-+5X", "42U", 42U);
	test_unsigned_int("Random unsigned int + '-' flag + '+' flag + '5' width -- flag '+' undefined behavior", "%---++++---5X", "42U", 42U);
	test_unsigned_int("Random unsigned int + '-' flag + ' ' flag + '5' width -- flag ' ' undefined behavior", "%- 5X", "42U", 42U);
	test_unsigned_int("Random unsigned int + '-' flag + ' ' flag + '5' width -- flag ' ' undefined behavior", "% -5X", "42U", 42U);
	test_unsigned_int("Random unsigned int + '-' flag + ' ' flag + '5' width -- flag ' ' undefined behavior", "%----    ---5X", "42U", 42U);
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


void	test_type_float_f(void)
{
	print_h1("TYPE: FLOAT (%f)");
	print_h2("=> Valid format:");
	test_float("Zero float", "%f", "0.F", 0.F);
	test_float("Minus zero float", "%f", "-0.F", -0.F);
	test_float("Zero float + '.' precision", "%.f", "0.F", 0.F);
	test_float("Random float", "%f", ".1F", .1F);
	test_float("Random float + '.30' precision", "%.30f", ".1F", .1F);
	test_float("Random float + '.30' precision", "%.30f", ".2F", .2F);
	test_float("Random float", "%f", "42.F", 42.F);
	test_float("Random float + '.30' precision", "%.30f", "42.F", 42.F);
	test_float("Negative number", "%f", "-42.F", -42.F);
	test_float("Number with null integer part and 3 digits decimal part", "%f", ".123f", .123F);
	test_float("Number with null integer part and 7 digits decimal part", "%f", ".1234567f", .1234567F);
	test_float("Number with 1 digit integer part and 7 digits decimal part", "%f", "1.1234567f", 1.1234567F);
	test_float("Number with 2 digits integer part and 7 digits decimal part", "%f", "12.1234567f", 12.1234567F);
	test_float("Number with 3 digits integer part and 7 digits decimal part", "%f", "123.1234567f", 123.1234567F);
	test_float("Number with 4 digits integer part and 7 digits decimal part", "%f", "1234.1234567f", 1234.1234567F);
}

int		main(int ac, char **av)
{
	void	(*tab_test[])(void) = {
		&test_type_int, 
		&test_type_unsigned_octal,
		&test_type_unsigned_int,
		&test_type_unsigned_hexadecimal_x,
		&test_type_unsigned_hexadecimal_X,
		&test_type_char, 
		&test_type_float_f
	};
	int		i;

	if (ac == 1)
	{
		i = -1;
		while (++i < (int)(sizeof(tab_test)/sizeof(tab_test[0])))
			(*tab_test[i])();
	}
	else if (ac == 2)
	{
		if (!strcmp(av[1],"char"))
			test_type_char();
		else if (!strcmp(av[1],"int"))
			test_type_int();
		else if (!strcmp(av[1],"u_octal"))
			test_type_unsigned_octal();
		else if (!strcmp(av[1],"u_int"))
			test_type_unsigned_int();
		else if (!strcmp(av[1],"u_hexa_x"))
			test_type_unsigned_hexadecimal_x();
		else if (!strcmp(av[1],"u_hexa_X"))
			test_type_unsigned_hexadecimal_X();
		else if (!strcmp(av[1],"float_f"))
			test_type_float_f();
		else
			printf("%s\n", "Unknown category");
	}
	else
	{
		printf("%s\n", "Wrong number of arguments, 0 or 1 expected");
	}
	printf("\n");
	printf("|%.100f|\n", 1.F/0.F);
	return (0);
}
