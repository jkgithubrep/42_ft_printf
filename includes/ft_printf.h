/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkettani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 12:18:38 by jkettani          #+#    #+#             */
/*   Updated: 2019/01/18 18:40:18 by jkettani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

/*
** INTEGER CONVERSION:
** minus ('-'): Left-justify the result in the field.
** plus ('+'):  For signed %d and %i conversions, print a plus sign if the value
**              is positive.
** space (' '): For signed %d and %i conversions, if the result does not start
**              with a plus or minus sign, prefix it with a space instead.
**              Flag ignored if '+' flag also supplied.
** hash ('#'):  For the '%o' conversion, forces the leading digit to be '0'
**              as if by increasing the precision.
**              For '%x' or '%X', prefixes a leading '0x' or '0X' to the
**              result.
**              Does not do anything for '%d', '%i' or '%u'.
** zero ('0'):  Pad the field with zeros instead of spaces.
**              The zeros are placed after any indication of sign or base.
**              Flag ignored if '-' flag also specified, or if a precision
**              is specified.
*/
enum	e_flags{
	minus = 0x1,
	plus = 0x2,
	space = 0x4,
	hash = 0x8,
	zero = 0x10,
};

int		ft_printf(const char *fmt, ...);

#endif
