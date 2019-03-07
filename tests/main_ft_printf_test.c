/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_ft_printf_test.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkettani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/28 16:50:07 by jkettani          #+#    #+#             */
/*   Updated: 2019/03/07 16:53:37 by jkettani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "print_bigint_utils.h"
#include <stdio.h>
#include <math.h>

int		main(int ac, char **av)
{
	t_bigint	bigint;
	double		dbl;

	(void)ac;
	(void)av;
	bigint = (t_bigint){4, {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF}};
	print_bigint(&bigint, "BIG INT");
	bigint_shiftleft(&bigint, 64);
	print_bigint(&bigint, "BIG INT SHIFTED");
	dbl = 1.0000e-123;
	printf("%f --> exp: %d\n", dbl, get_exponent(dbl));
	return (0);
}
