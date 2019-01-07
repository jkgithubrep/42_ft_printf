/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkettani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 11:24:15 by jkettani          #+#    #+#             */
/*   Updated: 2019/01/07 17:54:37 by jkettani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#define BOLD "\x1b[1m"
#define UNDERLINE "\x1b[4m"
#define NC "\x1b[0m"
#define RED "\x1b[31m"
#define GREEN "\x1b[32m"
#define YELLOW "\x1b[33m"
#define BLUE "\x1b[34m"
#define MAGENTA "\x1b[35m"

void	test_char(char *desc, char *fmt, char *test_str, int test)
{
	printf(" > %s (", desc);
	printf("\"|");
	printf(MAGENTA "%s" NC, fmt);
	printf("|\", |");
	printf(BLUE "%s" NC, test_str);
	printf("|): ");
	printf("|" YELLOW);
	printf(fmt, test);
	printf(NC "|");
	printf("\n");
}

int		main(int ac, char **av)
{
	(void)ac;
	(void)av;
	printf(UNDERLINE "TYPE: CHAR\n" NC);
	test_char("Non printable ASCII char nul", "%c", "0", 0);
	test_char("Non printable ASCII char nul with left blank spaces", "%10c", "0", 0);
	test_char("Non printable ASCII char horizontal tab", "%c", "9", 9);
	test_char("Non printable ASCII char vertical tab", "%c", "11", 11);
	test_char("Small letter ASCII char a", "%c", "'a'", 'a');
	test_char("Small letter ASCII char a with left blank spaces", "%10c", "'a'", 'a');
	test_char("Small letter ASCII char a with left blank spaces and spaces between number and type [INVALID]", "%10   c", "'a'", 'a');
	test_char("Small letter ASCII char a with left blank spaces and spaces between \% and number [UNDEFINED]", "%    10c", "'a'", 'a');
	test_char("Small letter ASCII char a with left blank spaces and spaces before and after number [INVALID]", "%    10     c", "'a'", 'a');
	test_char("Small letter ASCII char a with left zeros [UNDEFINED]", "%010c", "'a'", 'a');
	test_char("Small letter ASCII char a with left zeros and space before and after [INVALID]", "%   0   10   c", "'a'", 'a');
	test_char("Small letter ASCII char a with left zeros -- multiple zeros in argument [UNDEFINED]", "%00010c", "'a'", 'a');
	test_char("Small letter ASCII char a with left zeros -- multiple zeros in argument and + sign after zeros [UNDEFINED]", "%000+10c", "'a'", 'a');
	test_char("Small letter ASCII char a with left zeros -- multiple zeros in argument and + sign before zeros", "%+00010c", "'a'", 'a');
	test_char("Small letter ASCII char a with left zeros -- multiple zeros in argument and + sign between zeros", "%0+0010c", "'a'", 'a');
	test_char("Small letter ASCII char a with right blank spaces", "%-10c", "'a'", 'a');
	test_char("Small letter ASCII char a with right zeroes spaces -- minus sign before zero", "%-010c", "'a'", 'a');
	test_char("Small letter ASCII char a with right zeroes spaces -- minus sign after zero", "%0-10c", "'a'", 'a');
	test_char("Small letter ASCII char a with right zeroes spaces -- multiple zeros after - sign", "%-00010c", "'a'", 'a');
	test_char("Small letter ASCII char a with right zeroes spaces -- minus sign between zeros", "%00-010c", "'a'", 'a');
	test_char("Digit ASCII char 3", "%c", "'3'", '3');
	test_char("Capital letter ASCII char Z", "%c", "'Z'", 'Z');
	test_char("Symbol ASCII char *", "%c", "42", 42);
	test_char("Non printable ASCII char del", "%c", "127", 127);
	test_char("Int greater than 127 -- 128", "%c", "128", 128);
	test_char("Int greater than 127 -- 298 = 42 + 256", "%c", "298", 298);
	test_char("Negative number", "%c", "-1", -1);
	test_char("Negative number", "%c", "-42", -42);
	test_char("Negative number -- 126 = -130 + 256", "%c", "-130", -130);
	test_char("Negative number -- 97 = -159 + 256", "%c", "-159", -159);
	printf("%+0010c", 'a');
	return (0);
}
