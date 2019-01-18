/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkettani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 12:18:13 by jkettani          #+#    #+#             */
/*   Updated: 2019/01/18 15:27:02 by jkettani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdio.h>
#include "libft.h"

int		ft_printf(const char *fmt, ...)
{
	va_list		va;
	int			d;
	const char	*str_begin;
	char		*str_print;

	va_start(va, fmt);
	str_begin = (const char *)fmt;
	str_print = NULL;
	while (*fmt)
	{			
		if (*fmt == '%')
		{
			if (!(str_print = ft_strdup_c(str_begin, '%')))
				return (-1);	
			ft_putstr(str_print);
			ft_strdel(&str_print);
			d = va_arg(va, int);
			ft_putnbr(d);
			fmt += 2;
			str_begin = fmt;
		}
		++fmt;
	}
	va_end(va);
	return (0);
}
