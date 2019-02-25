/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01_basic_test.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkettani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/23 19:19:10 by jkettani          #+#    #+#             */
/*   Updated: 2019/02/25 21:58:47 by jkettani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

#define TYPE char *

int		asprintf_basic_test(void)
{
	char		*str;
	char		*fmt;
	TYPE		val;
	int			ret;

	fmt = "%s";
	val = "ma chaine";
	printf("|");
	printf(fmt, val);
	printf("|\n");
	ft_asprintf(&str, fmt, val);
	printf("|%s|\n", str);
	ret = strcmp(str, "1234");
	if (str)
		free(str);
	if (!ret)
		return (0);
	else
		return (-1);
}

