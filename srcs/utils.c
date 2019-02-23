/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkettani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 14:25:08 by jkettani          #+#    #+#             */
/*   Updated: 2019/02/23 19:44:19 by jkettani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "libft.h"
#include <stdio.h>

/*
** Check if char argument c is a conversion specifier (or type).
** Return value: returns zero if c is not a conversion specifier and non-zero
**               if the character tests true.
*/

int				is_type(const char c)
{
	return (ft_is_in_str(c, TYPES));
}

/*
** Check if char argument c is a flag.
** Return value: returns zero if c is not a flag and non-zero
**               if the character tests true.
*/

int				is_flag(const char c)
{
	return (ft_is_in_str(c, FLAGS));
}

/*
** Check if char argument c is a length modifier.
** Return value: returns zero if c is not a length modifier  and non-zero
**               if the character tests true.
*/

int				is_len_modif(const char c)
{
	return (ft_is_in_str(c, LEN_MODIFS));
}

/*
** Save int value either as a precision or a width depending on the value
** of the flag FL_PREC.
*/

void			save_int_value(int int_value, t_format *conv_params)
{
	if (conv_params->flags & FL_PREC)
		conv_params->prec = int_value;
	else
		conv_params->width = int_value;
}

const char		*skip_digits(const char *fmt)
{
	while (*fmt && ft_isdigit(*fmt))
		++fmt;
	return (fmt);
}

const char		*save_value_skip_digits(const char *fmt, t_format *conv_params)
{
	int		int_value;

	int_value = ft_atoi(fmt);
	save_int_value(int_value, conv_params);
	fmt = skip_digits(fmt);
	return (fmt);
}

void			save_flag(const char c, t_format *conv_params)
{
	if (c == MINUS)
		conv_params->flags |= FL_MINUS;
	else if (c == PLUS)
		conv_params->flags |= FL_PLUS;
	else if (c == SPACE)
		conv_params->flags |= FL_SPACE;
	else if (c == HASH)
		conv_params->flags |= FL_HASH;
	else if (c == ZERO)
		conv_params->flags |= FL_ZERO;
}

void			save_len_modif(const char *fmt, t_format *conv_params)
{
	if (*fmt == 'h')
		conv_params->len_mod = (*(fmt - 1) == 'h') ? LEN_MOD_HH : LEN_MOD_H;
	else if (*fmt == 'l')
		conv_params->len_mod = (*(fmt - 1) == 'l') ? LEN_MOD_LL : LEN_MOD_L;
	else if (*fmt == 'L')
		conv_params->len_mod = LEN_MOD_CAP_L;
	else if (*fmt == 'j')
		conv_params->len_mod = LEN_MOD_J;
	else if (*fmt == 'z')
		conv_params->len_mod = LEN_MOD_Z;
}

const char		*read_fmt(const char *fmt, t_format *conv_params)
{
	while (*fmt && !is_type(*fmt))
	{
		if (ft_isdigit(*fmt) && *fmt != ZERO)
			fmt = save_value_skip_digits(fmt, conv_params) - 1;
		else if (*fmt == DOT)
			conv_params->flags |= FL_PREC;
		else if (is_flag(*fmt))
			save_flag(*fmt, conv_params);
		else if (is_len_modif(*fmt))
			save_len_modif(fmt, conv_params);
		else
			break ;
		++fmt;
	}
	if (*fmt && is_type(*fmt))
		conv_params->type_char = *fmt;
	return (++fmt);
}

intmax_t		get_int_arg_value(t_format *conv_params, va_list args)
{
	intmax_t	arg_value;

	arg_value = 0;
	if (conv_params->len_mod == LEN_MOD_HH)
		arg_value = (char)va_arg(args, int);
	else if (conv_params->len_mod == LEN_MOD_H)
		arg_value = (short)va_arg(args, int);
	else if (conv_params->len_mod == LEN_MOD_L)
		arg_value = (long)va_arg(args, long);
	else if (conv_params->len_mod == LEN_MOD_LL)
		arg_value = (long long)va_arg(args, long long);
	else
		arg_value = (int)va_arg(args, int);
	return (arg_value);
}

char			*get_str_from_ivalue(intmax_t arg_value, t_format *conv_params)
{
	t_ints		val;
	char		*str;

	val.s_llint = (long long)arg_value;
	printf("%c", conv_params->type_char);
	if (conv_params->type_char == 'o')
		str = ft_uimaxtoa_base(val.u_llint, OCT);
	else if (conv_params->type_char == 'x' || conv_params->type_char == 'X')
		str = ft_uimaxtoa_base(val.u_llint, HEX);
	else if (conv_params->type_char == 'u')
		str = ft_uimaxtoa_base(val.u_llint, DEC);
	else
		str = ft_imaxtoa_base(val.s_llint, DEC);
	return (str);
}

void			init_conv_params(t_format *conv_params)
{
	conv_params->width = 0;
	conv_params->prec = 0;
	conv_params->flags = 0u;
	conv_params->len_mod = LEN_MOD_NA;
	conv_params->type_char = 0;
}

void			parse_fmt(char **str, const char *fmt, va_list args)
{
	t_format	conv_params;
	intmax_t	arg_value;

	init_conv_params(&conv_params);
	while (*fmt)
	{
		if (*fmt == PERCENT && *(fmt + 1) != PERCENT)
		{
			fmt = read_fmt(++fmt, &conv_params);
			arg_value = get_int_arg_value(&conv_params, args);
			*str = get_str_from_ivalue(arg_value, &conv_params);
		}
		else
			++fmt;
	}
}
