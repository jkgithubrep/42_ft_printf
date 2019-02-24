/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkettani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 14:25:08 by jkettani          #+#    #+#             */
/*   Updated: 2019/02/24 17:44:34 by jkettani         ###   ########.fr       */
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
**
*/

int				is_signed_type(const char c)
{
	return (ft_is_in_str(c, SIGNED_TYPES);
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

/*
** Skip digits in the string given as argument.
** Return a pointer to the next non-digit char.
*/

const char		*skip_digits(const char *fmt)
{
	while (*fmt && ft_isdigit(*fmt))
		++fmt;
	return (fmt);
}

/*
** Take a string starting with a digit as argument, extract the number as an int
** and return pointer to next non-digit character in the string.
*/

const char		*save_value_skip_digits(const char *fmt, t_format *conv_params)
{
	int		int_value;

	int_value = ft_atoi(fmt);
	save_int_value(int_value, conv_params);
	fmt = skip_digits(fmt);
	return (fmt);
}

/*
** Update the `flags` member in the t_format structure given as argument based
** on the flag character given argument.
*/

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

/*
** Update the `len_modif` member value in the t_format structure given as
** argument.
*/

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

void			save_type(const char c, t_format *conv_params)
{
	conv_params->type_char = c;
	conv_params->is_signed = ft_is_signed_type(c);
}

/*
** Parse a conversion specification (string portion starting after the `%`
** character and ending with a conversion specifier) and extract the
** different parameters (flags, width, precision, length, type).
*/

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

/*
** Extract the next value in the va_list as an intmax_t based on the
** parameters in the t_format structure.
*/

intmax_t		get_int_arg_val(t_format *conv_params, va_list args)
{
	intmax_t	arg_val;

	arg_val = 0;
	if (conv_params->len_mod == LEN_MOD_HH)
		arg_val = (char)va_arg(args, int);
	else if (conv_params->len_mod == LEN_MOD_H)
		arg_val = (short)va_arg(args, int);
	else if (conv_params->len_mod == LEN_MOD_L)
		arg_val = (long)va_arg(args, long);
	else if (conv_params->len_mod == LEN_MOD_LL)
		arg_val = (long long)va_arg(args, long long);
	else
		arg_val = (int)va_arg(args, int);
	return (arg_val);
}

/*
** Return a t_ints union with the right member initialized based on the
** value of the `len_mod` member in the t_format structure.
*/

t_ints			convert_imax_to_ints(intmax_t arg_val, t_format *conv_params)
{
	t_ints		val;

	val.s_int = 0;
	if (conv_params->len_mod == LEN_MOD_NA)
		val.s_int = (int)arg_val;
	else if (conv_params->len_mod == LEN_MOD_HH)
		val.s_char = (char)arg_val;
	else if (conv_params->len_mod == LEN_MOD_H)
		val.s_short = (short)arg_val;
	else if (conv_params->len_mod == LEN_MOD_L)
		val.s_lint = (long)arg_val;
	else if (conv_params->len_mod == LEN_MOD_LL)
		val.s_llint = (long long)arg_val;
	return (val);
}

/*
** Convert the intmax_t `arg_val` to a string based on the base given
** as argument and on the `len_mod` member value in the t_format structure.
*/

char			*convert_val_to_str(intmax_t arg_val, const char *base, 
					t_format *conv_params)
{
	char			*str;
	t_ints			val;

	val = convert_imax_to_ints(arg_val, conv_params);
	str = NULL;
	if (conv_params->len_mod == LEN_MOD_NA)
		str = conv_params->is_signed ? ft_imaxtoa_base(val.s_int, base)
										: ft_uimaxtoa_base(val.u_int, base);
	else if (conv_params->len_mod == LEN_MOD_HH)
		str = conv_params->is_signed ? ft_imaxtoa_base(val.s_char, base)
										: ft_uimaxtoa_base(val.u_char, base);
	else if (conv_params->len_mod == LEN_MOD_H)
		str = conv_params->is_signed ? ft_imaxtoa_base(val.s_short, base)
										: ft_uimaxtoa_base(val.u_short, base);
	else if (conv_params->len_mod == LEN_MOD_L)
		str = conv_params->is_signed ? ft_imaxtoa_base(val.s_lint, base)
										: ft_uimaxtoa_base(val.u_lint, base);
	else if (conv_params->len_mod == LEN_MOD_LL)
		str = conv_params->is_signed ? ft_imaxtoa_base(val.s_llint, base)
										: ft_uimaxtoa_base(val.u_llint, base);
	return (str);
}


/*
** Convert the intmax_t `arg_value` to a string based on the `type_char` member
** value in the t_format structure.
*/

char			*get_str_from_ival(intmax_t arg_val, t_format *conv_params)
{
	char		*str;

	if (conv_params->type_char == 'o')
		str = convert_val_to_str(arg_val, OCT_BASE, UNSIGNED, conv_params);
	else if (conv_params->type_char == 'x')
		str = convert_val_to_str(arg_val, L_HEX_BASE, UNSIGNED, conv_params);
	else if (conv_params->type_char == 'X')
		str = convert_val_to_str(arg_val, U_HEX_BASE, UNSIGNED, conv_params);
	else if (conv_params->type_char == 'u')
		str = convert_val_to_str(arg_val, DEC_BASE, UNSIGNED, conv_params);
	else
		str = convert_val_to_str(arg_val, DEC_BASE, SIGNED, conv_params);
	return (str);
}

int				nb_zeros_prec(int nb_digits, int prec)
{
	return ((int)ft_max(nb_digits, prec) - nb_digits);
}

int				nb_padding(int nb_digits, int nb_zeros_prec, int prefix_size,
					int width)
{
	return (width - (nb_digits + nb_zeros_prec + prefix_size));	
}

int				str_prepend(char *val_str, t_format *conv_params)
{
	int		nb_zeros_prec;
	int		nb_digits;
	int		sign;

	nb_zeros_prec = 0;
	sign = (str[0] == '-' || (conv_params->flags & FL_PLUS)
			|| (conv_params->flags & FL_SPACE));
	nb_digits = ft_strlen(str) - (str[0] == '-' ? 1 : 0);
	if (conv_params->flags & FL_PREC)
		nb_zeros_prec = nb_zeros_prec(nb_digits, conv_params->prec);
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
	char		*buf[BUF_SIZE];
	char		*val_str;
	t_format	conv_params;
	intmax_t	arg_val;

	init_conv_params(&conv_params);
	while (*fmt)
	{
		if (*fmt == PERCENT && *(fmt + 1) != PERCENT)
		{
			fmt = read_fmt(++fmt, &conv_params);
			arg_val = get_int_arg_val(&conv_params, args);
			*val_str = get_str_from_ival(arg_val, &conv_params);
		}
		else
			++fmt;
	}
}
