/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkettani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 11:24:15 by jkettani          #+#    #+#             */
/*   Updated: 2019/01/15 18:39:13 by jkettani         ###   ########.fr       */
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

void	test_int(char *desc, char *fmt, char *test_str, int test)
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
	test_int("Zero with 0 precision", "%.d", "0", 0);
	test_int("Random int", "%d", "42", 42);
	test_int("Int max", "%d", "2147483647", INT_MAX);
	test_int("Int max + 1", "%d", "2147483648", INT_MAX + 1);
	test_int("Int min", "%d", "-2147483648", INT_MIN);
	test_int("Unsigned int max", "%d", "4294967295", UINT_MAX);
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
	test_int("Random int left aligned with 5 spaces and + sign -- multiple - and + signs", "%---++++5d", "42", 42);
	test_int("Random int left aligned with 5 spaces and space instead of + sign", "%- 5d", "42", 42);
	test_int("Random int left aligned with 5 spaces and space instead of + sign -- reverse order", "% -5d", "42", 42);
	test_int("Random int left aligned with 5 spaces and space instead of + sign -- multiple - and spaces", "%----    5d", "42", 42);
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
	printf("|%.5d|\n", 42);
	printf("\n");
	return (0);
}
