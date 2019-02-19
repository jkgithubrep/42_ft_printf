/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkettani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 12:18:13 by jkettani          #+#    #+#             */
/*   Updated: 2019/02/19 11:56:58 by jkettani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** <stdarg.h>: variable argument lists
** <unistd.h>: standard file descriptor macros
*/
#include <stdarg.h>
#include <unistd.h>

int				ft_printf(const char *fmt, ...)
{
	va_list		args;
	int			ret;

	va_start(args, fmt);
	ret = ft_vdprintf(STDOUT_FILENO, fmt, args);
	va_end(args);
	return (0);
}

int		ft_dprintf(int d, const char *fmt, ...)
{
	return (0);
}

int		ft_vdprintf(int d, const char *fmt, va_list args)
{
	return (0);
}

int		ft_vasprintf(char **ret, const char *fmt, va_list args)
{
	return (0);
}
