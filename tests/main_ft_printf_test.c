/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_ft_printf_test.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkettani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/28 16:50:07 by jkettani          #+#    #+#             */
/*   Updated: 2019/03/14 18:13:24 by jkettani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <math.h>
#include <float.h>
#include <limits.h>
#include <stdio.h>

#define ARGS "PDmRG;}TE<Qdb9^G&%%B(WzjB.G;?Xd=\"B[NBK06 `KNW=g`7%^'pJ$yqHyc3o7'&x3} Hwn<BLAu?SGDMv:Jt:AzLlNpX^~_9IAFRq!27to!qyn4ZC/V5*3|ta%yqK}YQ*m3+b[=7jVbZmN!`nB<`hOd{>2UoiRYOrp;2o'@57b^:&.!&u-x[gpOQd/v4"

int		main(int ac, char **av)
{
//	t_dbls 	value;

	(void)ac;
	(void)av;
//	value.ulint = (ULONG_MAX >> 12) | (1UL << 63);
//	printf("mantissa: %llu\n", value.dbl_parts.mantissa);
//	printf("exponent: %d\n", value.dbl_parts.exponent);
//	printf("sign: %d\n", value.dbl_parts.sign);
//	printf("%a\n", value.dbl);
	printf(ARGS);
	printf("\n");
	ft_printf(ARGS);
	printf("\n");
	return (0);
}
