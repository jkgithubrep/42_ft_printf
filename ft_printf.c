/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkettani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 12:18:13 by jkettani          #+#    #+#             */
/*   Updated: 2019/01/14 16:09:41 by jkettani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdio.h>

void		ft_printf(const char *fmt, ...)
{
	va_list		va;
	int			d;

	va_start(va, fmt);
	while (*fmt)
	{
		d = va_arg(va, int);
		printf("%d", d);
		++fmt;
	}
	printf("\n");
	va_end(va);
}

int		main(void)
{
	ft_printf("123456", 1, 2, 3, 4, 5, 6);
	return (0);
}
