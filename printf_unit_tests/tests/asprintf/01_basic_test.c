/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01_basic_test.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkettani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/23 19:19:10 by jkettani          #+#    #+#             */
/*   Updated: 2019/02/28 18:08:55 by jkettani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <limits.h>

#define ARGS "hello ca%----4c %c va %10c%-c ??", '\0', '\n', (char)110, 0
//#define ARGS "hello %-4c %c ca %10c%-c ??", '\0', '\n', (char)110, 0

int		asprintf_basic_test(void)
{
	int			ret;

	ret = 1;
	printf("1. printf - unix: |");
	ret = printf(ARGS);
	printf("|, ret = |%d|\n", ret);
	printf("2. printf - mine: |");
	fflush(stdout);
	ret = ft_printf(ARGS);
	printf("|, ret = |%d|\n", ret);
	if (!ret)
		return (0);
	else
		return (-1);
}

