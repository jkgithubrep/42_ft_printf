/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_ft_printf_test.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkettani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/28 16:50:07 by jkettani          #+#    #+#             */
/*   Updated: 2019/03/20 13:06:21 by jkettani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <math.h>
#include <float.h>
#include <limits.h>
#include <stdio.h>

#define ARGS "%s|%-s|%23s|%.5s|%.50s|%-23s|%-.5s|%-.50s|%23.5s|%23.50s|%-23.5s|%-23.50s", NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL
#define ARGS "%.50s", NULL

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
