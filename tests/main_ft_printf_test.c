/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_ft_printf_test.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkettani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/28 16:50:07 by jkettani          #+#    #+#             */
/*   Updated: 2019/03/19 18:53:05 by jkettani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <math.h>
#include <float.h>
#include <limits.h>
#include <stdio.h>

//#define ARGS "{bold}{red}%s {green}%s {yellow}%s {blue}%s {magenta}%s {cyan}%s{reset}", "Y", "a", "plein", "de", "couleurs", "!!!"
#define ARGS "%12.5g", 30.253
//#define ARGS "%e", 9999.9999

int		main(int ac, char **av)
{
//	t_dbls 	value;
	int		ret;

	(void)ac;
	(void)av;
//	value.ulint = (ULONG_MAX >> 12) | (1UL << 63);
//	printf("mantissa: %llu\n", value.dbl_parts.mantissa);
//	printf("exponent: %d\n", value.dbl_parts.exponent);
//	printf("sign: %d\n", value.dbl_parts.sign);
//	printf("%a\n", value.dbl);
	printf("|");
	fflush(stdout);
	ret = printf(ARGS);
	printf("|\n");
	printf("> ret = |%d|\n", ret);
	printf("|");
	fflush(stdout);
	ret = ft_printf(ARGS);
	printf("|\n");
	printf("> ret = |%d|\n", ret);
	return (0);
}
