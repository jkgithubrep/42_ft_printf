/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01_basic_test.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkettani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/23 19:19:10 by jkettani          #+#    #+#             */
/*   Updated: 2019/02/24 16:01:40 by jkettani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

int		asprintf_basic_test(void)
{
	char		*str;
	int			ret;

	printf("printf: %hhd ", (char)1234);
	ft_asprintf(&str, "%hhd", (char)1234);
	printf("%s", str);
	ret = strcmp(str, "*");
	if (str)
		free(str);
	if (!ret)
		return (0);
	else
		return (-1);
}

