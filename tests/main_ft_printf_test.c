/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_ft_printf_test.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkettani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/28 16:50:07 by jkettani          #+#    #+#             */
/*   Updated: 2019/03/21 10:42:43 by jkettani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <math.h>
#include <float.h>
#include <limits.h>
#include <stdio.h>

#define ARGS "string: %s | int: %d | float: %f", "ceci est un test", 1568943, 9.965

int		main(int ac, char **av)
{
	int		ret;

	(void)ac;
	(void)av;
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
