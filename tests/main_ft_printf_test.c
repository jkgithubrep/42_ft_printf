/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_ft_printf_test.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkettani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/28 16:50:07 by jkettani          #+#    #+#             */
/*   Updated: 2019/03/08 15:52:06 by jkettani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "print_bigint_utils.h"
#include <stdio.h>
#include <math.h>

int		main(int ac, char **av)
{
	t_bigint		bigint1;
	t_bigint		bigint2;
	t_bigint		bigintres;

	(void)ac;
	(void)av;
//	bigint1 = (t_bigint){1, {0xFFFFFFFF, 0, 0, 0}};
//	bigint2 = (t_bigint){2, {2, 1, 0, 0}};
	bigintres = (t_bigint){0, {0, 0, 0, 0}};
//	print_bigint(&bigint1, "BIG INT1");
//	print_bigint(&bigint2, "BIG INT2");
	bigint_pow10(&bigintres, 3);
	print_bigint(&bigintres, "BIG INT RES");
	return (0);
}
