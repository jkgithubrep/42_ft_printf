/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_output_tests.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkettani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/05 17:33:49 by jkettani          #+#    #+#             */
/*   Updated: 2019/02/21 17:20:13 by jkettani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <float.h>
#include <math.h>
#include <unistd.h>
/*
** Colors definition
*/
//#define BOLD "\x1b[1m"
//#define UNDERLINE "\x1b[4m"
//#define NC "\x1b[0m"
//#define RED "\x1b[31m"
//#define GREEN "\x1b[32m"
//#define YELLOW "\x1b[33m"
//#define BLUE "\x1b[34m"
//#define MAGENTA "\x1b[35m"
/*
** Colors definition canceled
*/
#define BOLD ""
#define UNDERLINE ""
#define NC ""
#define RED ""
#define GREEN ""
#define YELLOW ""
#define BLUE ""
#define MAGENTA ""
/*
** Macro that formats the printf test output
*/
#define PRINTF_TEST_ARGS do { \
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
#define PRINTF_TEST_NO_ARGS do { \
					int		ret;\
					printf(" > %s (", desc);\
					printf("\"|");\
					printf(MAGENTA "%s" NC, fmt);\
					printf("|\"|): ");\
					printf("|" YELLOW);\
					ret = printf(fmt);\
					printf(NC "|");\
					printf(", |" YELLOW);\
					printf("%d", ret);\
					printf(NC "|");\
					printf("\n");\
					} while (0)
#define PRINTF_TEST_2_ARGS do { \
					int		ret;\
					printf(" > %s (", desc);\
					printf("\"|");\
					printf(MAGENTA "%s" NC, fmt);\
					printf("|\", |");\
					printf(BLUE "%s" NC, test1_str);\
					printf("|, |");\
					printf(BLUE "%s" NC, test2_str);\
					printf("|): ");\
					printf("|" YELLOW);\
					ret = printf(fmt, test1, test2);\
					printf(NC "|");\
					printf(", |" YELLOW);\
					printf("%d", ret);\
					printf(NC "|");\
					printf("\n");\
					} while (0)
#define PRINTF_TEST_3_ARGS do { \
					int		ret;\
					printf(" > %s (", desc);\
					printf("\"|");\
					printf(MAGENTA "%s" NC, fmt);\
					printf("|\", |");\
					printf(BLUE "%s" NC, test1_str);\
					printf("|, |");\
					printf(BLUE "%s" NC, test2_str);\
					printf("|, |");\
					printf(BLUE "%s" NC, test3_str);\
					printf("|): ");\
					printf("|" YELLOW);\
					ret = printf(fmt, test1, test2, test3);\
					printf(NC "|");\
					printf(", |" YELLOW);\
					printf("%d", ret);\
					printf(NC "|");\
					printf("\n");\
					} while (0)
#define PRINTF_TEST_4_ARGS do { \
					int		ret;\
					printf(" > %s (", desc);\
					printf("\"|");\
					printf(MAGENTA "%s" NC, fmt);\
					printf("|\", |");\
					printf(BLUE "%s" NC, test1_str);\
					printf("|, |");\
					printf(BLUE "%s" NC, test2_str);\
					printf("|, |");\
					printf(BLUE "%s" NC, test3_str);\
					printf("|, |");\
					printf(BLUE "%s" NC, test4_str);\
					printf("|): ");\
					printf("|" YELLOW);\
					ret = printf(fmt, test1, test2, test3, test4);\
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
	PRINTF_TEST_ARGS;
}

void	test_string(char *desc, char *fmt, char *test_str, char *test)
{
	PRINTF_TEST_ARGS;
}

void	test_unsigned_char(char *desc, char *fmt, char *test_str, unsigned char test)
{
	PRINTF_TEST_ARGS;
}

void	test_int(char *desc, char *fmt, char *test_str, int test)
{
	PRINTF_TEST_ARGS;
}

void	test_unsigned_int(char *desc, char *fmt, char *test_str, unsigned int test)
{
	PRINTF_TEST_ARGS;
}

void	test_short(char *desc, char *fmt, char *test_str, short test)
{
	PRINTF_TEST_ARGS;
}

void	test_unsigned_short(char *desc, char *fmt, char *test_str, unsigned short test)
{
	PRINTF_TEST_ARGS;
}

void	test_long(char *desc, char *fmt, char *test_str, long test)
{
	PRINTF_TEST_ARGS;
}

void	test_unsigned_long(char *desc, char *fmt, char *test_str, unsigned long test)
{
	PRINTF_TEST_ARGS;
}

void	test_long_long(char *desc, char *fmt, char *test_str, long long test)
{
	PRINTF_TEST_ARGS;
}

void	test_unsigned_long_long(char *desc, char *fmt, char *test_str, unsigned long long test)
{
	PRINTF_TEST_ARGS;
}

void	test_double(char *desc, char *fmt, char *test_str, double test)
{
	PRINTF_TEST_ARGS;
}

void	test_long_double(char *desc, char *fmt, char *test_str, long double test)
{
	PRINTF_TEST_ARGS;
}

void	test_void_pointer(char *desc, char *fmt, char *test_str, void *test)
{
	PRINTF_TEST_ARGS;
}

void	test_no_args(char *desc, char *fmt)
{
	PRINTF_TEST_NO_ARGS;
}

void	test_2_int(char *desc, char *fmt, char *test1_str, char *test2_str, int test1, int test2)
{
	PRINTF_TEST_2_ARGS;
}

void	test_3_int(char *desc, char *fmt, char *test1_str, char *test2_str, char *test3_str, int test1, int test2, int test3)
{
	PRINTF_TEST_3_ARGS;
}

void	test_4_int(char *desc, char *fmt, char *test1_str, char *test2_str, char *test3_str, char *test4_str, int test1, int test2, int test3, int test4)
{
	PRINTF_TEST_4_ARGS;
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
	test_int("Random int + 'UINT_MAX + 15' width", "%4294967310d", "42", 42);
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
	test_unsigned_int("Random unsigned int + 'UINT_MAX + 1' width", "%4294967296o", "42U", 42U);
	test_unsigned_int("Random unsigned int + 'UINT_MAX + 1' precision", "%.4294967296o", "42U", 42U);
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

void	test_type_double_f(void)
{
	print_h1("TYPE: DOUBLE (%f)");
	print_h2("=> Valid format:");
	test_double("Zero double", "%f", "0.", 0.);
	test_double("Minus zero double", "%f", "-0.", -0.);
	test_double("Zero double + '.' precision", "%.f", "0.", 0.);
	test_double("Minus zero double + '.' precision", "%.f", "-0.", -0.);
	test_double("NaN", "%f", "0./0.", 0./0.);
	test_double("NaN + '5' width", "%5f", "0./0.", 0./0.);
	test_double("Infinity", "%f", "INFINITY", INFINITY);
	test_double("1 divided by infinity", "%f", "1./INFINITY", 1./INFINITY);
	test_double("0 multiplied by by infinity", "%f", "0. * INFINITY", 0. * INFINITY);
	test_double("Random double", "%f", ".1", .1);
	test_double("Random double + '.30' precision", "%.30f", ".1", .1);
	test_double("Random double + '.30' precision", "%.30f", ".2", .2);
	test_double("Random double", "%f", "42.", 42.);
	test_double("Random double + '12' width", "%12f", "42.", 42.);
	test_double("Random double + '-' flag + '12' width", "%-12f", "42.", 42.);
	test_double("Random double + '-' flag + '+' flag + '12' width", "%-+12f", "42.", 42.);
	test_double("Random double + '-' flag + ' ' flag + '12' width", "%- 12f", "42.", 42.);
	test_double("Random double + '0' flag + '12' width", "%012f", "42.", 42.);
	test_double("Random double + '+' flag + '0' flag + '12' width", "%+012f", "42.", 42.);
	test_double("Random double + ' ' flag + '0' flag + '12' width", "% 012f", "42.", 42.);
	test_double("Random double + '.' precision", "%.f", "42.", 42.);
	test_double("Random double + '#' flag + '.' precision", "%#.f", "42.", 42.);
	test_double("Random double + '.2' precision", "%.2f", "42.", 42.);
	test_double("Random double + '.30' precision", "%.30f", "42.", 42.);
	test_double("Power of 10", "%f", "1e22", 1e22);
	test_double("Power of 10", "%f", "1e23", 1e23);
	test_double("Double max", "%f", "DBL_MAX", DBL_MAX);
	test_long_double("Double max", "%Lf", "LDBL_MAX", LDBL_MAX);
	test_double("Double min + '.1025' precision", "%.1025f", "DBL_MIN", DBL_MIN);
	test_double("Negative number", "%f", "-42.", -42.);
	test_double("Number with null integer part and 3 digits decimal part", "%f", ".123", .123);
	test_double("Number with null integer part and 7 digits decimal part", "%f", ".1234567", .1234567);
	test_double("Number with 1 digit integer part and 7 digits decimal part", "%f", "1.1234567", 1.1234567);
	test_double("Number with 2 digits integer part and 7 digits decimal part", "%f", "12.1234567", 12.1234567);
	test_double("Number with 3 digits integer part and 7 digits decimal part", "%f", "123.1234567", 123.1234567);
	test_double("Number with 4 digits integer part and 7 digits decimal part", "%f", "1234.1234567", 1234.1234567);
}

void	test_type_double_e(void)
{
	print_h1("TYPE: DOUBLE (%e)");
	print_h2("=> Valid format:");
	test_double("Zero double", "%e", "0.", 0.);
	test_double("Minus zero double", "%e", "-0.", -0.);
	test_double("Zero double + '.' precision", "%.e", "0.", 0.);
	test_double("Minus zero double + '.' precision", "%.e", "-0.", -0.);
	test_double("NaN", "%e", "0./0.", 0./0.);
	test_double("NaN + '5' width", "%5e", "0./0.", 0./0.);
	test_double("Infinity", "%e", "INFINITY", INFINITY);
	test_double("1 divided by infinity", "%e", "1./INFINITY", 1./INFINITY);
	test_double("0 multiplied by by infinity", "%e", "0. * INFINITY", 0. * INFINITY);
	test_double("Random double", "%e", ".1", .1);
	test_double("Random double + '.30' precision", "%.30e", ".1", .1);
	test_double("Random double + '.30' precision", "%.30e", ".2", .2);
	test_double("Random double", "%e", "42.", 42.);
	test_double("Random double + '12' width", "%12e", "42.", 42.);
	test_double("Random double + '-' flag + '12' width", "%-12e", "42.", 42.);
	test_double("Random double + '-' flag + '+' flag + '12' width", "%-+12e", "42.", 42.);
	test_double("Random double + '-' flag + ' ' flag + '12' width", "%- 12e", "42.", 42.);
	test_double("Random double + '0' flag + '12' width", "%012e", "42.", 42.);
	test_double("Random double + '+' flag + '0' flag + '12' width", "%+012e", "42.", 42.);
	test_double("Random double + ' ' flag + '0' flag + '12' width", "% 012e", "42.", 42.);
	test_double("Random double + '.' precision", "%.e", "42.", 42.);
	test_double("Random double + '.' precision", "%.e", "46.", 46.);
	test_double("Random double + '.' precision", "%.e", "42.", 45.);
	test_double("Random double + '.' precision", "%.e", "55.", 55.);
	test_double("Random double + '#' flag + '.' precision", "%#.e", "42.", 42.);
	test_double("Random double + '.2' precision", "%.2e", "42.", 42.);
	test_double("Random double + '.30' precision", "%.30e", "42.", 42.);
	test_double("Power of 10", "%e", "1e22", 1e22);
	test_double("Power of 10", "%e", "1e23", 1e23);
	test_double("Double max", "%e", "DBL_MAX", DBL_MAX);
	test_double("Double max + '.315' precision", "%.315e", "DBL_MAX", DBL_MAX);
	test_long_double("Double max", "%Le", "LDBL_MAX", LDBL_MAX);
	test_double("Double min", "%e", "DBL_MIN", DBL_MIN);
	test_double("Double min + '.730' precision", "%.730e", "DBL_MIN", DBL_MIN);
	test_double("Negative number", "%e", "-42.", -42.);
	test_double("Number with null integer part and 3 digits decimal part", "%e", ".123", .123);
	test_double("Number with null integer part and 7 digits decimal part", "%e", ".1234567", .1234567);
	test_double("Number with 1 digit integer part and 7 digits decimal part", "%e", "1.1234567", 1.1234567);
	test_double("Number with 2 digits integer part and 7 digits decimal part", "%e", "12.1234567", 12.1234567);
	test_double("Number with 3 digits integer part and 7 digits decimal part", "%e", "123.1234567", 123.1234567);
	test_double("Number with 4 digits integer part and 7 digits decimal part", "%e", "1234.1234567", 1234.1234567);
}

void	test_type_double_g(void)
{
	print_h1("TYPE: DOUBLE (%g)");
	print_h2("=> Valid format:");
	test_double("Zero double", "%g", "0.", 0.);
	test_double("Minus zero double", "%g", "-0.", -0.);
	test_double("Zero double + '.' precision", "%.g", "0.", 0.);
	test_double("Minus zero double + '.' precision", "%.g", "-0.", -0.);
	test_double("NaN", "%g", "0./0.", 0./0.);
	test_double("NaN + '5' width", "%5g", "0./0.", 0./0.);
	test_double("Infinity", "%g", "INFINITY", INFINITY);
	test_double("1 divided by infinity", "%g", "1./INFINITY", 1./INFINITY);
	test_double("0 multiplied by by infinity", "%g", "0. * INFINITY", 0. * INFINITY);
	test_double("Random double", "%g", ".1", .1);
	test_double("Random double + '.30' precision", "%.30g", ".1", .1);
	test_double("Random double + '.30' precision", "%.30g", ".2", .2);
	test_double("Random double", "%g", "42.", 42.);
	test_double("Random double + '#' flag", "%#g", "42.", 42.);
	test_double("Random double + '#' flag + '.2' precision", "%#.2g", "42.", 42.);
	test_double("Random double + '12' width", "%12g", "42.", 42.);
	test_double("Random double + '-' flag + '12' width", "%-12g", "42.", 42.);
	test_double("Random double + '-' flag + '+' flag + '12' width", "%-+12g", "42.", 42.);
	test_double("Random double + '-' flag + ' ' flag + '12' width", "%- 12g", "42.", 42.);
	test_double("Random double + '0' flag + '12' width", "%012g", "42.", 42.);
	test_double("Random double + '+' flag + '0' flag + '12' width", "%+012g", "42.", 42.);
	test_double("Random double + ' ' flag + '0' flag + '12' width", "% 012g", "42.", 42.);
	test_double("Random double + '.' precision", "%.g", "42.", 42.);
	test_double("Random double + '.' precision", "%.g", "46.", 46.);
	test_double("Random double + '.' precision", "%.g", "42.", 45.);
	test_double("Random double + '.' precision", "%.g", "55.", 55.);
	test_double("Random double + '#' flag + '.' precision", "%#.g", "42.", 42.);
	test_double("Random double + '.2' precision", "%.2g", "42.", 42.);
	test_double("Random double + '.30' precision", "%.30g", "42.", 42.);
	test_double("Power of 10 + default precision", "%g", "1e-5", 1e-5);
	test_double("Power of 10 + default precision", "%g", "1e-4", 1e-4);
	test_double("Power of 10 + default precision", "%g", "1e5", 1e5);
	test_double("Power of 10 + default precision", "%g", "1e6", 1e6);
	test_double("Power of 10 + '.21' precision", "%.21g", "1e22", 1e22);
	test_double("Power of 10 + '.23' precision", "%.23g", "1e22", 1e22);
	test_double("Power of 10", "%g", "1e22", 1e22);
	test_double("Power of 10", "%g", "1e23", 1e23);
	test_double("Double max", "%g", "DBL_MAX", DBL_MAX);
	test_double("Double max + '.315' precision", "%.315g", "DBL_MAX", DBL_MAX);
	test_long_double("Double max", "%Lg", "LDBL_MAX", LDBL_MAX);
	test_double("Double min", "%g", "DBL_MIN", DBL_MIN);
	test_double("Double min + '.730' precision", "%.730g", "DBL_MIN", DBL_MIN);
	test_double("Negative number", "%g", "-42.", -42.);
	test_double("Number with null integer part and 3 digits decimal part", "%g", ".123", .123);
	test_double("Number with null integer part and 7 digits decimal part", "%g", ".1234567", .1234567);
	test_double("Number with 1 digit integer part and 7 digits decimal part", "%g", "1.1234567", 1.1234567);
	test_double("Number with 2 digits integer part and 7 digits decimal part", "%g", "12.1234567", 12.1234567);
	test_double("Number with 3 digits integer part and 7 digits decimal part", "%g", "123.1234567", 123.1234567);
	test_double("Number with 4 digits integer part and 7 digits decimal part", "%g", "1234.1234567", 1234.1234567);
}

void	test_type_double_a(void)
{
	print_h1("TYPE: DOUBLE (%a)");
	print_h2("=> Valid format:");
	test_double("Zero double", "%a", "0.", 0.);
	test_double("Minus zero double", "%a", "-0.", -0.);
	test_double("Zero double + '.' precision", "%.a", "0.", 0.);
	test_double("Minus zero double + '.' precision", "%.a", "-0.", -0.);
	test_double("NaN", "%a", "0./0.", 0./0.);
	test_double("NaN + '5' width", "%5a", "0./0.", 0./0.);
	test_double("Infinity", "%a", "INFINITY", INFINITY);
	test_double("1 divided by infinity", "%a", "1./INFINITY", 1./INFINITY);
	test_double("0 multiplied by by infinity", "%a", "0. * INFINITY", 0. * INFINITY);
	test_double("Random double", "%a", ".1", .1);
	test_double("Random double + '.30' precision", "%.30a", ".1", .1);
	test_double("Random double + '.30' precision", "%.30a", ".2", .2);
	test_double("Random double", "%a", "42.", 42.);
	test_double("Random double + '#' flag", "%#a", "42.", 42.);
	test_double("Random double + '#' flag + '.2' precision", "%#.2a", "42.", 42.);
	test_double("Random double + '12' width", "%12a", "42.", 42.);
	test_double("Random double + '-' flag + '12' width", "%-12a", "42.", 42.);
	test_double("Random double + '-' flag + '+' flag + '12' width", "%-+12a", "42.", 42.);
	test_double("Random double + '-' flag + ' ' flag + '12' width", "%- 12a", "42.", 42.);
	test_double("Random double + '0' flag + '12' width", "%012a", "42.", 42.);
	test_double("Random double + '+' flag + '0' flag + '12' width", "%+012a", "42.", 42.);
	test_double("Random double + ' ' flag + '0' flag + '12' width", "% 012a", "42.", 42.);
	test_double("Random double + '.' precision", "%.a", "42.", 42.);
	test_double("Random double + '.' precision", "%.a", "46.", 46.);
	test_double("Random double + '.' precision", "%.a", "42.", 45.);
	test_double("Random double + '.' precision", "%.a", "55.", 55.);
	test_double("Random double + '#' flag + '.' precision", "%#.a", "42.", 42.);
	test_double("Random double + '.2' precision", "%.2a", "42.", 42.);
	test_double("Random double + '.30' precision", "%.30a", "42.", 42.);
	test_double("Power of 10 + default precision", "%a", "1e-5", 1e-5);
	test_double("Power of 10 + default precision", "%a", "1e-4", 1e-4);
	test_double("Power of 10 + default precision", "%a", "1e5", 1e5);
	test_double("Power of 10 + default precision", "%a", "1e6", 1e6);
	test_double("Power of 10 + '.21' precision", "%.21a", "1e22", 1e22);
	test_double("Power of 10 + '.23' precision", "%.23a", "1e22", 1e22);
	test_double("Power of 10", "%a", "1e22", 1e22);
	test_double("Power of 10", "%a", "1e23", 1e23);
	test_double("Double max", "%a", "DBL_MAX", DBL_MAX);
	test_double("Double max + '.30' precision", "%.30a", "DBL_MAX", DBL_MAX);
	test_long_double("Double max", "%La", "LDBL_MAX", LDBL_MAX);
	test_double("Double min", "%a", "DBL_MIN", DBL_MIN);
	test_double("Double min + '.10' precision", "%.10a", "DBL_MIN", DBL_MIN);
	test_double("Negative number", "%a", "-42.", -42.);
	test_double("Number with null integer part and 3 digits decimal part", "%a", ".123", .123);
	test_double("Number with null integer part and 7 digits decimal part", "%a", ".1234567", .1234567);
	test_double("Number with 1 digit integer part and 7 digits decimal part", "%a", "1.1234567", 1.1234567);
	test_double("Number with 2 digits integer part and 7 digits decimal part", "%a", "12.1234567", 12.1234567);
	test_double("Number with 3 digits integer part and 7 digits decimal part", "%a", "123.1234567", 123.1234567);
	test_double("Number with 4 digits integer part and 7 digits decimal part", "%a", "1234.1234567", 1234.1234567);
}

void	test_type_char(void)
{
	print_h1("TYPE: CHAR (%c)");
	print_h2("=> Valid format:");
	test_char("Non printable ASCII char nul", "%c", "0", 0);
	test_char("Non printable ASCII char horizontal tab", "%c", "9", 9);
	test_char("Non printable ASCII char vertical tab", "%c", "11", 11);
	test_char("Digit ASCII char '3'", "%c", "'3'", '3');
	test_char("Capital letter ASCII char 'Z'", "%c", "'Z'", 'Z');
	test_char("Small letter ASCII char 'a'", "%c", "'a'", 'a');
	test_char("Symbol ASCII char '*'", "%c", "42", 42);
	test_char("Non printable ASCII char 'del'", "%c", "127", 127);
	test_int("Int greater than 127 -- 128", "%c", "128", 128);
	test_int("Int greater than 127 -- 298 = 42 + 256", "%c", "298", 298);
	test_char("Negative number", "%c", "-1", -1);
	test_char("Negative number", "%c", "-42", -42);
	test_int("Negative number -- 97 = -159 + 256", "%c", "-159", -159);
	test_char("Small letter ASCII char 'a' + '10' width", "%10c", "'a'", 'a');
	test_char("Small letter ASCII char 'a' + '-' flag + '10' width", "%-10c", "'a'", 'a');
	test_char("Small letter ASCII char 'a' + multiple '-' flags + '10' width", "%-----10c", "'a'", 'a');
	test_int("Int greater than 127 + modifier 'l' -- 298 = 42 + 256", "%lc", "298", 298);
}

void	test_type_string(void)
{
	print_h1("TYPE: STRING (%s)");
	print_h2("=> Valid format:");
	test_string("NULL pointer", "%s", "NULL", NULL);
	test_string("Random string", "%s", "Random string", "Random string");
	test_string("Random string + '.' precision", "%.s", "Random string", "Random string");
	test_string("Random string + '.10' precision", "%.10s", "Random string", "Random string");
	test_string("Random string + '15' width", "%15s", "Random string", "Random string");
	test_string("Random string + '-' flag + '15' width", "%-15s", "Random string", "Random string");
	test_string("Emoticone", "%s", "😁", "😁");
	test_string("Emoticone utf8 encoded", "%s", "\xF0\x9F\x98\x84", "\xF0\x9F\x98\x84");
	test_string("Emoticone + '.3' precision", "%.3s", "😁", "😁");
	test_string("Emoticone + '.4' precision", "%.4s", "😁", "😁");
	test_string("Emoticone + '.5' precision", "%.5s", "😁", "😁");
	test_string("Emoticone + '.10' precision", "%.5s", "😁", "😁");
	test_string("Emoticone + '1' width", "%1s", "😁", "😁");
	test_string("Emoticone + '5' width", "%5s", "😁", "😁");
	test_string("Emoticone + '-' flag + '5' width", "%-5s", "😁", "😁");
	test_string("Latin extended-A", "%s", "ă", "ă");
}

void	test_type_pointer(void)
{
	int		test_int;
	char	test_char;

	test_int = 42;
	test_char = '*';
	print_h1("TYPE: POINTER (%p)");
	print_h2("=> Valid format:");
	test_void_pointer("NULL pointer", "%p", "NULL", NULL);
	test_void_pointer("Random string", "%p", "Random string", "Random string");
	test_void_pointer("Random string + '5' width", "%5p", "Random string", "Random string");
	test_void_pointer("Random string + '30' width", "%30p", "Random string", "Random string");
	test_void_pointer("Random string + '-' flag + '30' width", "%-30p", "Random string", "Random string");
	test_void_pointer("Random int", "%p", "&test_int", &test_int);
	test_void_pointer("Random char", "%p", "&test_char", &test_char);
}

void	test_misc(void)
{
	print_h1("TYPE: MISC");
	print_h2("=> Valid format:");
	test_no_args("2 '%' signs", "%%");
	test_no_args("3 '%' signs", "%%%");
	test_no_args("4 '%' signs", "%%%%");
	test_2_int("'*' field width", "%*d", "10", "1", 10, 1);
	test_2_int("'.*' precision", "%.*d", "10", "1", 10, 1);
	test_3_int("'*' field width + '.*' precision", "%*.*d", "10", "2", "1", 10, 3, 1);
	test_4_int("4 args + '*' field width", "%*d%*d", "10", "1", "10", "100", 10, 1, 10, 100);
	test_2_int("2 args + '$' sign + '*' field width", "%2$*1$d %1$*1$d", "10", "1", 10, 1);
	test_2_int("2 args + '$' sign + '.*' precision", "%2$.*1$d %1$.*1$d", "10", "1", 10, 1);
	print_h2("=> Invalid format:");
	test_3_int("'**' field width", "%**d", "2", "10", "1", 2, 10, 100);
	test_3_int("'***' field width", "%***d", "2", "10", "1", 2, 10, 100);
}


int		main(int ac, char **av)
{
	void	(*tab_test[])(void) = {
		&test_type_int, 
		&test_type_unsigned_octal,
		&test_type_unsigned_int,
		&test_type_unsigned_hexadecimal_x,
		&test_type_unsigned_hexadecimal_X,
		&test_type_double_f,
		&test_type_double_e,
		&test_type_double_a,
		&test_type_char,
		&test_type_string,
		&test_type_pointer,
		&test_misc,
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
		if (!strcmp(av[1],"int"))
			test_type_int();
		else if (!strcmp(av[1],"u_octal"))
			test_type_unsigned_octal();
		else if (!strcmp(av[1],"u_int"))
			test_type_unsigned_int();
		else if (!strcmp(av[1],"u_hexa_x"))
			test_type_unsigned_hexadecimal_x();
		else if (!strcmp(av[1],"u_hexa_X"))
			test_type_unsigned_hexadecimal_X();
		else if (!strcmp(av[1],"double_f"))
			test_type_double_f();
		else if (!strcmp(av[1],"double_e"))
			test_type_double_e();
		else if (!strcmp(av[1],"double_g"))
			test_type_double_g();
		else if (!strcmp(av[1],"double_a"))
			test_type_double_a();
		else if (!strcmp(av[1],"char"))
			test_type_char();
		else if (!strcmp(av[1],"string"))
			test_type_string();
		else if (!strcmp(av[1],"pointer"))
			test_type_pointer();
		else if (!strcmp(av[1],"misc"))
			test_misc();
		else
			printf("%s\n", "Unknown category");
	}
	else
	{
		printf("%s\n", "Wrong number of arguments, 0 or 1 expected");
	}
	printf("\n");
//	printf("|%s%c\0%s|\n", "Hello", 0, ", ça va ?");
	printf("|%1$d|\n", 42);
	return (0);
}
