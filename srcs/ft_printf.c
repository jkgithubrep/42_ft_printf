/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkettani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 12:18:13 by jkettani          #+#    #+#             */
/*   Updated: 2019/02/26 14:03:50 by jkettani         ###   ########.fr       */
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
#include "utils.h"
#include <stdio.h>

int				ft_printf(const char *fmt, ...)
{
	va_list		args;
	int			count;

	va_start(args, fmt);
	count = ft_vdprintf(STDOUT_FILENO, fmt, args);
	va_end(args);
	return (count);
}

int				ft_dprintf(int d, const char *fmt, ...)
{
	va_list		args;
	int			count;

	va_start(args, fmt);
	count = ft_vdprintf(d, fmt, args);
	va_end(args);
	return (count);
}

int				ft_asprintf(char **str, const char *fmt, ...)
{
	va_list		args;
	int			count;

	va_start(args, fmt);
	count = ft_vasprintf(str, fmt, args);
	va_end(args);
	return (count);
}

int				ft_vdprintf(int d, const char *fmt, va_list args)
{
	char		*str;
	int			count;
	int			ret;

	str = NULL;
	if ((count = ft_vasprintf(&str, fmt, args)) == EXIT_FAIL)
		return (EXIT_FAIL);
	ret = write(d, str, count);
	ft_strdel(&str);
	return (ret);
}

int				ft_vasprintf(char **str, const char *fmt, va_list args)
{
	int			count;

	count = parse_fmt(str, fmt, args);
	return (count);
}
