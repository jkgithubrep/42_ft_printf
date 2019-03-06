/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_ft_printf_test.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkettani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/28 16:50:07 by jkettani          #+#    #+#             */
/*   Updated: 2019/03/06 22:10:34 by jkettani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "print_bigint_utils.h"
#include <stdio.h>
#include <math.h>

int		main(int ac, char **av)
{
	t_bigint	bigint1;
	t_bigint	bigint2;
	t_bigint	bigintsum;

	(void)ac;
	(void)av;
	bigint1 = (t_bigint){1, {1, 0, 0, 0}};
	bigint2 = (t_bigint){4, {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFF}};
	bigintsum = (t_bigint){0, {0, 0, 0, 0}};
	print_bigint(&bigint1, "BIG INT 1");
	print_bigint(&bigint2, "BIG INT 2");
	print_bigint(&bigintsum, "BIG INT SUM");
	bigint_add(&bigint1, &bigint2, &bigintsum);
	print_bigint(&bigintsum, "BIG INT SUM");
	return (0);
}
