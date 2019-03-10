/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_ft_printf_test.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkettani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/28 16:50:07 by jkettani          #+#    #+#             */
/*   Updated: 2019/03/10 23:22:50 by jkettani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "print_bigint_utils.h"
#include <stdio.h>
#include <math.h>
#include <float.h>

void	print_diff(t_dbls *value)
{
	printf("dragon:\n");
	dragon4(value);
	printf("printf:\n%.300f\n", value->dbl);
}

int		main(int ac, char **av)
{
	t_dbls			value;

	(void)ac;
	(void)av;
	value.dbl = DBL_MAX;
	print_diff(&value);
	value.dbl = 0.1;
	print_diff(&value);
	value.dbl = DBL_MIN;
	print_diff(&value);
	value.dbl = 500;
	print_diff(&value);
	return (0);
}

//int		main(int ac, char **av)
//{
//	t_bigint	bigint1;
//	t_bigint	bigint2;
//	t_bigint	result;
//
//	(void)ac;
//	(void)av;
//	bigint1 = (t_bigint){2, {1, 2}};
//	bigint2 = (t_bigint){1, {1, 0}};
//	result = (t_bigint){0, {0}};
//	print_bigint(&bigint1, "bigint 1");
//	print_bigint(&bigint2, "bigint 2");
//	bigint_substract(&bigint1, &bigint2, &result);
//	print_bigint(&result, "result");
//	return (0);
//}
