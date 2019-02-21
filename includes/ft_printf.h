/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkettani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 12:18:38 by jkettani          #+#    #+#             */
/*   Updated: 2019/02/21 17:05:36 by jkettani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>

/*
** List of the conversion specifiers expected to end a conversion specification:
**  - d, i: int converted to signed decimal notation;
**  - o, u, x, X: unsigned int converted to octal (o), unsigned decimal (u),
**    or unsigned hexadecimal (x, X);
**  - e, E: double argument rounded and converted in the style [-]d.ddde+/-dd
**          (exponential notation);
**  - f: double argument rounded and converted in the style [-]ddd.ddd
**       (fixed-point) notation;
**  - g, G: double argument converted in the style of f or e (or E for G conver-
**          sions);
**  - a, A: double argument converted to hexadecimal notation in the style
**          [-]0xh.hhhp+/-dd (0X for A conversions);
**  - c: int argument converted to an unsigned char;
**  - s: const char * argument (string) is printed;
**  - p: void * pointer argument printed in hexadecimal;
**  - %: a '%' is written, no argument is converted.
*/
# define CONV_SPECS "dcsouxXfeEgGaApi%"

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
	MINUS = 0x1,
	PLUS = 0x2,
	SPACE = 0x4,
	HASH = 0x8,
	ZERO = 0x10,
};

int		ft_printf(const char *fmt, ...);
int		ft_dprintf(int d, const char *fmt, ...);
int		ft_vdprintf(int d, const char *fmt, va_list args);
int		ft_vasprintf(char **str, const char *fmt, va_list args);

#endif
