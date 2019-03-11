/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_ft_printf_test.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkettani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/28 16:50:07 by jkettani          #+#    #+#             */
/*   Updated: 2019/03/11 19:04:53 by jkettani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "print_bigint_utils.h"
#include <stdio.h>
#include <math.h>
#include <float.h>

void	print_diff_dbl(double value)
{
	printf("%9s: %.1350f\n", "printf", value);
	ft_printf("%9s: %.1350f\n", "ft_printf", value);
}

void	print_diff_ldbl(long double value)
{
	printf("%9s: %Lf\n", "printf", value);
	ft_printf("%9s: %Lf\n", "ft_printf", value);
}

int		main(int ac, char **av)
{
	double		value;

	(void)ac;
	(void)av;
	value = DBL_MIN;
	print_diff_dbl(value);
	value = DBL_MAX;
	print_diff_dbl(value);
	value = 0.1;
	print_diff_dbl(value);
	value = 9999.9999;
	return (0);
}
