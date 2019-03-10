/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_ft_printf_test.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkettani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/28 16:50:07 by jkettani          #+#    #+#             */
/*   Updated: 2019/03/10 15:31:23 by jkettani         ###   ########.fr       */
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
	return (0);
}
