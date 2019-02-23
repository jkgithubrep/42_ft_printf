/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01_basic_test.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkettani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/23 19:19:10 by jkettani          #+#    #+#             */
/*   Updated: 2019/02/23 20:30:28 by jkettani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

int		asprintf_basic_test(void)
{
	char	*str;
	int		ret;

	ft_asprintf(&str, "%u", UINT_MAX);
	printf("%s", str);
	ret = strcmp(str, "52");
	if (str)
		free(str);
	if (!ret)
		return (0);
	else
		return (-1);
}

