/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_ft_printf_test.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkettani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/28 16:50:07 by jkettani          #+#    #+#             */
/*   Updated: 2019/03/13 12:26:09 by jkettani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "print_bigint_utils.h"
#include <stdio.h>
#include <math.h>
#include <float.h>

//void	print_diff_dbl(double value)
//{
//	printf("%9s: %04.0s\n", "printf", "abcde");
//	ft_printf("%9s: %04.0s\n", "ft_printf", "abcde");
//}
//
//void	print_diff_ldbl(long double value)
//{
//	printf("%9s: %.1300Lf\n", "printf", value);
//	ft_printf("%9s: %.1300Lf\n", "ft_printf", value);
//}

int		main(int ac, char **av)
{
	(void)ac;
	(void)av;
	ft_printf("%60.22Lf", (long double)4385077040);
	return (0);
}
