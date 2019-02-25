/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkettani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 14:25:08 by jkettani          #+#    #+#             */
/*   Updated: 2019/02/25 21:57:46 by jkettani         ###   ########.fr       */
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
** Return value: returns zero if c is not a length modifier and non-zero
**               if the character tests true.
*/

int				is_len_modif(const char c)
{
	return (ft_is_in_str(c, LEN_MODIFS));
}

/*
** Check if char argument c is a signed type.
** Return value: returns zero if c is not a signed type and non-zero if the
**               character tests true.
*/

int				is_signed_type(const char c)
{
	return (ft_is_in_str(c, SIGNED_TYPES));
}

/*
** Check if char argument c is a numeric type.
** Return value: returns zero if c is not a numeric type  and non-zero if
**               character tests true.
*/

int				is_num_type(const char c)
{
	return (ft_is_in_str(c, NUM_TYPES));
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
	return (ft_strskip(fmt, &ft_isdigit));
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
	conv_params->is_signed = (is_signed_type(c)) ? SIGNED : UNSIGNED;
}

/*
** Parse a conversion specification (string portion starting after the `%`
** character and ending with a conversion specifier) and extract the
** different parameters (flags, width, precision, length, type).
*/

const char		*parse_conv_spec(const char *fmt, t_format *conv_params)
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
	if (*fmt)
		save_type(*fmt, conv_params);
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
** Extract the next value in the va_list as a char *.
*/

char			*get_str_arg_val(va_list args)
{
	return ((char *)va_arg(args, char *));
}

/*
** Extract the next value in the va_list as an unsigned char.
*/

t_uchar			get_char_arg_val(va_list args)
{
	return ((t_uchar)va_arg(args, int));
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

char			*int_arg_val_to_str_conv(intmax_t arg_val, const char *base,
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

char			*int_arg_val_to_str(intmax_t arg_val, t_format *conv_params)
{
	char		*str;

	if (conv_params->type_char == 'o')
		str = int_arg_val_to_str_conv(arg_val, OCT_BASE, conv_params);
	else if (conv_params->type_char == 'x')
		str = int_arg_val_to_str_conv(arg_val, L_HEX_BASE, conv_params);
	else if (conv_params->type_char == 'X')
		str = int_arg_val_to_str_conv(arg_val, U_HEX_BASE, conv_params);
	else if (conv_params->type_char == 'u')
		str = int_arg_val_to_str_conv(arg_val, DEC_BASE, conv_params);
	else
		str = int_arg_val_to_str_conv(arg_val, DEC_BASE, conv_params);
	return (str);
}

/*
** Calculate the number of zeros for the precision.
*/

int				get_nb_zeros_prec(int nb_digits, int prec)
{
	return ((int)ft_max(nb_digits, prec) - nb_digits);
}

/*
** Calculate the size of the padding.
*/

int				get_nb_padding(int curr_len, int width)
{
	return (width - curr_len);
}

/*
** Prepend zeros for the precision to `val_str`. If `val_str` corresponds to a
** negative number, replace the `-` sign by a zero and pad with
** `nb_zeros_prec` - 1.
*/

char			*prepend_prec(char **val_str, int nb_zeros_prec)
{
	if ((*val_str)[0] == '-')
	{
		(*val_str)[0] = '0';
		ft_strpad_left(val_str, '0', nb_zeros_prec - 1);
	}
	else
		ft_strpad_left(val_str, '0', nb_zeros_prec);
	return (*val_str);
}

/*
** Check if `val_str` should be prefixed with a sign symbol ('-', '+' or ' ').
*/

int				has_sign(int nb_zeros_prec, t_format *conv_params)
{
	return (is_signed_type(conv_params->type_char)
				&& ((conv_params->is_neg && nb_zeros_prec)
					|| (conv_params->flags & FL_PLUS)
					|| (conv_params->flags & FL_SPACE)));
}

/*
** Prepend sign after the precision has been set.
*/

char			*prepend_sign(char **val_str, t_format *conv_params)
{
	if (conv_params->is_neg)
		ft_strprepend("-", val_str);
	else if (conv_params->flags & FL_PLUS)
		ft_strprepend("+", val_str);
	else if (conv_params->flags & FL_SPACE)
		ft_strprepend(" ", val_str);
	return (*val_str);
}

/*
** Check if `val_str` should have a prefix ('0', '0x' or '0X');
*/

int				has_prefix(t_format *conv_params)
{
	return ((conv_params->flags & FL_HASH)
			&& ft_is_in_str(conv_params->type_char, TYPE_PREFIX));
}

/*
** Add the right prefix depending on the type if the flag `FL_HASH` is set.
*/

char			*prepend_prefix(char **val_str, t_format *conv_params)
{
	if (conv_params->type_char == 'o')
		ft_strprepend(PREF_OCT, val_str);
	else if (conv_params->type_char == 'x')
		ft_strprepend(PREF_L_HEX, val_str);
	else if (conv_params->type_char == 'X')
		ft_strprepend(PREF_U_HEX, val_str);
	return (*val_str);
}

/*
** Add padding after or before the formated value depending on the flag
** `FL_MINUS` value. Pads with zeros if `FL_MINUS` flag not set and no precision
** is given.
*/

char			*add_padding(char **val_str, int padding, t_format *conv_params)
{
	if (conv_params->flags & FL_MINUS)
		ft_strpad_right(val_str, ' ', padding);
	else if (is_num_type(conv_params->type_char)
				&& (conv_params->flags & FL_ZERO)
				&& !(conv_params->flags & FL_PREC))
		ft_strpad_left(val_str, '0', padding);
	else
		ft_strpad_left(val_str, ' ', padding);
	return (*val_str);
}

/*
** Format the `val_str` string depending on the conversion specification.
*/

char			*format_int_str(char *val_str, t_format *conv_params)
{
	int		nb_zeros_prec;
	int		nb_digits;
	int		padding;

	conv_params->is_neg = (val_str[0] == '-') ? 1 : 0;
	nb_digits = ft_strlen(val_str) - conv_params->is_neg;
	nb_zeros_prec = get_nb_zeros_prec(nb_digits, conv_params->prec);
	if (nb_zeros_prec)
		prepend_prec(&val_str, nb_zeros_prec);
	if (has_sign(nb_zeros_prec, conv_params))
		prepend_sign(&val_str, conv_params);
	if (has_prefix(conv_params))
		prepend_prefix(&val_str, conv_params);
	if ((padding = get_nb_padding(ft_strlen(val_str), conv_params->width)) > 0)
		add_padding(&val_str, padding, conv_params);
	return (val_str);
}

char			*char_arg_val_to_str(t_uchar arg_val)
{
	char	*str;

	str = ft_strcnew(1, arg_val);
	return (str);
}

char			*format_char_str(char *val_str, t_format *conv_params)
{
	if (conv_params->width > 1)
		add_padding(&val_str, conv_params->width - 1, conv_params);
	return (val_str);
}

char			*format_str(char *val_str, t_format *conv_params)
{
	int		padding;

	if (conv_params->flags & FL_PREC)
		ft_strcut(&val_str, conv_params->prec);
	if ((padding = get_nb_padding(ft_strlen(val_str), conv_params->width)) > 0)
		add_padding(&val_str, padding, conv_params);
	return (val_str);
}

char			*get_formatted_str_int(t_format *conv_params, va_list args)
{
	intmax_t	arg_val;
	char		*val_str;

	if (!(arg_val = get_int_arg_val(conv_params, args)))
		conv_params->flags |= FL_NULL;
	val_str = int_arg_val_to_str(arg_val, conv_params);
	val_str = format_int_str(val_str, conv_params);
	return (val_str);
}

char			*get_formatted_str_char(t_format *conv_params, va_list args)
{
	t_uchar		arg_val;
	char		*val_str;

	if (!is_type(conv_params->type_char))
		arg_val = conv_params->type_char;
	else
		arg_val = get_char_arg_val(args);
	val_str = char_arg_val_to_str(arg_val);
	val_str = format_char_str(val_str, conv_params);
	return (val_str);
}

char			*get_formatted_str_str(t_format *conv_params, va_list args)
{
	char		*val_str;

	val_str = ft_strdup(get_str_arg_val(args));
	val_str = format_str(val_str, conv_params);
	return (val_str);
}

char			*get_formatted_str(t_format *conv_params, va_list args)
{
	char		*val_str;

	val_str = NULL;
	if (is_num_type(conv_params->type_char))
		val_str = get_formatted_str_int(conv_params, args);
	else if (conv_params->type_char == 'c')
		val_str = get_formatted_str_char(conv_params, args);
	else if (conv_params->type_char == 's')
		val_str = get_formatted_str_str(conv_params, args);
	return (val_str);
}

void			flush_buf(char *buf, int *index, char **str)
{
	char	*tmp;
	char	*tmp2;

	tmp = ft_strnew(*index);
	ft_memcpy(tmp, buf, *index);
	*str = ft_strjoin(*str, tmp);
	ft_putendl(tmp2);
	ft_strdel(str);
	*str = tmp2;
	ft_bzero(buf, *index);
	*index = 0;
}

void			add_to_buff(char *buf, int *index, t_result *result, char **str)
{
	int		len;
	int		i;

	len = ft_strlen(result->str);
	result->count += len;
	if (*index + len > BUF_SIZE)
		flush_buf(buf, index, str);
	else
	{
		i = 0;
		while (len--)
			buf[(*index)++] = result->str[i++];
		ft_strdel(&result->str);
	}
}

void			init_variables(t_format *conv_params, int *i, t_result *result)
{
	conv_params->width = 0;
	conv_params->prec = 0;
	conv_params->flags = 0u;
	conv_params->len_mod = LEN_MOD_NA;
	conv_params->type_char = 0;
	conv_params->is_signed = UNSIGNED;
	conv_params->is_neg = 0;
	*i = 0;
	result->str = ft_strnew(0);
	result->count = 0;
}

int				parse_fmt(char **str, const char *fmt, va_list args)
{
	char		buf[BUF_SIZE] = {0};
	int			i;
	t_result	result;
	t_format	conv_params;

	init_variables(&conv_params, &i, &result);
	while (*fmt)
	{
		if (*fmt == PERCENT && *(fmt + 1) != PERCENT)
		{
			fmt = parse_conv_spec(fmt + 1, &conv_params);
			result.str = get_formatted_str(&conv_params, args);
		}
		else if (*fmt == PERCENT && *(fmt + 1) == PERCENT)
		{
			result.str = ft_strdup("%");
			fmt = fmt + 2;
		}
		else
			result.str = ft_strcnew(*fmt++, 1);
		add_to_buff(buf, &i, &result, str);
	}
	dbg_print_nbr("count", result.count);
	dbg_print_nbr("index", i);
	flush_buf(buf, &i, str);
	return (result.count);
}
