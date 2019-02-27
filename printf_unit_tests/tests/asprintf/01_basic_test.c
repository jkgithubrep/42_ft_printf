/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01_basic_test.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkettani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/23 19:19:10 by jkettani          #+#    #+#             */
/*   Updated: 2019/02/27 18:19:25 by jkettani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

#define ARGS "%0#44zo", -975099071
//#define ARGS "%#zo", 0

int		asprintf_basic_test(void)
{
	char		*str;
	int			ret;

	printf("|");
	ret = printf(ARGS);
	printf("|, ret = |%d|\n", ret);
	ret = ft_asprintf(&str, ARGS);
	printf("|%s|, ret = |%d|\n", str, ret);
	ret = strcmp(str, "ma chaine");
	if (str)
		free(str);
	if (!ret)
		return (0);
	else
		return (-1);
}

