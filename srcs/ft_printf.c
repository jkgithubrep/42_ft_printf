/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkettani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 12:18:13 by jkettani          #+#    #+#             */
/*   Updated: 2019/02/21 14:55:00 by jkettani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** <stdarg.h>: variable argument lists
** <unistd.h>: standard file descriptor macros, write syscall
*/
#include <stdarg.h>
#include <unistd.h>
#include "libft.h"
#include "ft_printf.h"

int				ft_printf(const char *fmt, ...)
{
	va_list		args;
	int			count;

	count = 0;
	va_start(args, fmt);
	count = ft_vdprintf(STDOUT_FILENO, fmt, args);
	va_end(args);
	return (count);
}

int				ft_dprintf(int d, const char *fmt, ...)
{
	va_list		args;
	int			count;

	count = 0;
	va_start(args, fmt);
	count = ft_vdprintf(d, fmt, args);
	va_end(args);
	return (count);
}

int				ft_vdprintf(int d, const char *fmt, va_list args)
{
	int			count;
	int			ret;
	char		*str;

	str = NULL;
	ret = 0;
	count = 0;
	if ((count = ft_vasprintf(&str, fmt, args)) == -1)
		return (-1);
	ret = write(d, str, count);
	ft_strdel(&str);
	return ((ret != -1) ? count : -1);
}

int				ft_vasprintf(char **str, const char *fmt, va_list args)
{
	int			count;

	(void)str;
	(void)fmt;
	(void)args;
	count = 0;
	return (count);
}
