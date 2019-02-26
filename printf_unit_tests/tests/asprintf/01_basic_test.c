/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01_basic_test.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkettani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/23 19:19:10 by jkettani          #+#    #+#             */
/*   Updated: 2019/02/26 18:31:00 by jkettani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

#define ARGS "%+d", -42

int		asprintf_basic_test(void)
{
	char		*str;
	int			ret;

	printf("|");
	printf(ARGS);
	printf("|\n");
	ft_asprintf(&str, ARGS);
	printf("|%s|\n", str);
	ret = strcmp(str, "ma chaine");
	if (str)
		free(str);
	if (!ret)
		return (0);
	else
		return (-1);
}

