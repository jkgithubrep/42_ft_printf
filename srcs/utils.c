/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkettani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 14:25:08 by jkettani          #+#    #+#             */
/*   Updated: 2019/03/06 11:37:56 by jkettani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "libft.h"
#include <stdio.h>

/*
** Take a string starting with a digit as argument, extract the number as an int
** and return pointer to next non-digit character in the string.
** Int value either is saved as a precision or a width depending on the value
** of the flag FL_PREC.
*/

const char		*save_value_skip_digits(const char *fmt, t_format *conv_params)
{
	int		int_value;

	int_value = ft_atoi(fmt);
	if (conv_params->flags & FL_PREC)
		conv_params->prec = int_value;
	else
		conv_params->width = int_value;
	fmt = ft_strskip(fmt, &ft_isdigit);
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
	if (c == PERCENT)
		conv_params->flags |= FL_ERR;
	if (c == 'p')
	{
		conv_params->flags |= (FL_HASH | FL_POINT);
		conv_params->len_mod = LEN_MOD_L;
		conv_params->type_char = 'x';
	}
	else if (c == 'D' || c == 'O' || c == 'U')
	{
		conv_params->len_mod = LEN_MOD_L;
		conv_params->type_char = ft_tolower(c);
	}
	else
		conv_params->type_char = c;
	conv_params->is_signed = (ft_instr(conv_params->type_char, SIGNED_TYPES)) ?
															SIGNED : UNSIGNED;
}

/*
** Parse a conversion specification (string portion starting after the `%`
** character and ending with a conversion specifier) and extract the
** different parameters (flags, width, precision, length, type).
*/

const char		*parse_conv_spec(const char *fmt, t_format *conv_params)
{
	while (*fmt && !ft_instr(*fmt, TYPES))
	{
		if (ft_isdigit(*fmt) && *fmt != ZERO)
			fmt = save_value_skip_digits(fmt, conv_params) - 1;
		else if (*fmt == DOT)
		{
			conv_params->flags |= FL_PREC;
			if (ft_isdigit(*(fmt + 1)))
				fmt = save_value_skip_digits(fmt + 1, conv_params) - 1;
		}
		else if (ft_instr(*fmt, FLAGS))
			save_flag(*fmt, conv_params);
		else if (ft_instr(*fmt, LEN_MODIFS))
			save_len_modif(fmt, conv_params);
		else
		{
			conv_params->flags |= FL_ERR;
			break ;
		}
		++fmt;
	}
	if (*fmt)
		save_type(*fmt, conv_params);
	return ((*fmt) ? ++fmt : fmt);
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
	else if (conv_params->len_mod == LEN_MOD_J)
		arg_val = (intmax_t)va_arg(args, intmax_t);
	else if (conv_params->len_mod == LEN_MOD_Z)
		arg_val = (ssize_t)va_arg(args, ssize_t);
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
	else if (conv_params->len_mod == LEN_MOD_Z)
		val.s_size_t = (ssize_t)arg_val;
	else if (conv_params->len_mod == LEN_MOD_J)
		val.s_intmax = (intmax_t)arg_val;
	return (val);
}

/*
** Convert the intmax_t `arg_val` to a string based on the base given
** as argument and on the `len_mod` member value in the t_format structure.
*/

char			*int_arg_val_to_str_conv(intmax_t arg_val, const char *base,
					t_format *conv_params)
{
	t_ints		val;

	val = convert_imax_to_ints(arg_val, conv_params);
	if (conv_params->len_mod == LEN_MOD_HH)
		return (conv_params->is_signed ? ft_imaxtoa_base(val.s_char, base)
										: ft_uimaxtoa_base(val.u_char, base));
	else if (conv_params->len_mod == LEN_MOD_H)
		return (conv_params->is_signed ? ft_imaxtoa_base(val.s_short, base)
										: ft_uimaxtoa_base(val.u_short, base));
	else if (conv_params->len_mod == LEN_MOD_L)
		return (conv_params->is_signed ? ft_imaxtoa_base(val.s_lint, base)
										: ft_uimaxtoa_base(val.u_lint, base));
	else if (conv_params->len_mod == LEN_MOD_LL)
		return (conv_params->is_signed ? ft_imaxtoa_base(val.s_llint, base)
										: ft_uimaxtoa_base(val.u_llint, base));
	else if (conv_params->len_mod == LEN_MOD_J)
		return (conv_params->is_signed ? ft_imaxtoa_base(val.s_intmax, base)
										: ft_uimaxtoa_base(val.u_intmax, base));
	else if (conv_params->len_mod == LEN_MOD_Z)
		return (conv_params->is_signed ? ft_imaxtoa_base(val.s_size_t, base)
										: ft_uimaxtoa_base(val.u_size_t, base));
	else
		return (conv_params->is_signed ? ft_imaxtoa_base(val.s_int, base)
										: ft_uimaxtoa_base(val.u_int, base));
}

/*
** Convert the intmax_t `arg_value` to a string based on the `type_char` member
** value in the t_format structure.
*/

char			*int_arg_val_to_str(intmax_t arg_val, t_format *conv_params)
{
	char		*str;

	if ((conv_params->flags & FL_NULL) && (conv_params->flags & FL_PREC)
			&& !conv_params->prec)
		str = ft_strnew(0);
	else if (conv_params->type_char == 'o')
		str = int_arg_val_to_str_conv(arg_val, OCT_BASE, conv_params);
	else if (conv_params->type_char == 'x')
		str = int_arg_val_to_str_conv(arg_val, L_HEX_BASE, conv_params);
	else if (conv_params->type_char == 'X')
		str = int_arg_val_to_str_conv(arg_val, U_HEX_BASE, conv_params);
	else if (conv_params->type_char == 'u')
		str = int_arg_val_to_str_conv(arg_val, DEC_BASE, conv_params);
	else if (conv_params->type_char == 'b')
		str = int_arg_val_to_str_conv(arg_val, BIN_BASE, conv_params);
	else
		str = int_arg_val_to_str_conv(arg_val, DEC_BASE, conv_params);
	return (str);
}

/*
** Calculate the number of zeros for the precision:
**     1) FL_PREC flag is set (if precision is given, '0' flag is ignored):
**            nb = MAX(nb of digits, precision) - nb of digits;
**  or
**     2) FL_ZERO flag is set but not FL_MINUS ('-' flag overides '0' flag):
**         a) type is signed ('d' or 'i'):
**            nb = MAX(width - (nb of digits [+ 1 for sign symbol]), 0);
**         b) type is prefixed ('x' or 'X'):
**            nb = MAX(width - (nb of digits + 2), 0);
**         c) type is 'o' or 'u':
**            nb = MAX(width - nb_digits, 0);
**     if:
**         - type is 'o'
**         - FL_HASH flag is set
**         - nb of zeros to add equals to zero
**         and
**                - value is not equal to zero
**            or  - value is zero
**                - FL_PREC flag is set
**                - precision equals zero
**     then, +1 is added to force the increase of the precision.
*/

int				get_nb_zeros_prec(int nb_digits, t_format *conv_params)
{
	int			nb;

	nb = 0;
	if (conv_params->flags & FL_PREC)
		nb = (int)ft_max(nb_digits, conv_params->prec) - nb_digits;
	else if ((conv_params->flags & FL_ZERO) && !(conv_params->flags & FL_MINUS))
	{
		if (ft_instr(conv_params->type_char, SIGNED_TYPES))
			nb = (int)ft_max(conv_params->width
					- (nb_digits + ((conv_params->is_neg)
							|| (conv_params->flags & FL_PLUS)
							|| (conv_params->flags & FL_SPACE))), 0);
		else if (has_prefix(conv_params))
			nb = (int)ft_max(conv_params->width - (nb_digits + 2), 0);
		else
			nb = (int)ft_max(conv_params->width - nb_digits, 0);
	}
	if ((conv_params->type_char == 'o') && (conv_params->flags & FL_HASH)
			&& !nb && (!(conv_params->flags & FL_NULL)
				|| ((conv_params->flags & FL_NULL)
					&& (conv_params->flags & FL_PREC) && !conv_params->prec)))
		nb++;
	return (nb);
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
** Check if `val_str` should be prefixed with a sign symbol ('-', '+' or ' '):
**  - type is 'd' or 'i',
**		1) - the value is a negative number,
**		   - at least one zero has been added for the precision/padding;
**	or  2) - the value is a positive number,
**         - either flag FL_PLUS ('+') or FL_SPACE (' ') is set.
*/

int				has_sign(int nb_zeros_prec, t_format *conv_params)
{
	return (ft_instr(conv_params->type_char, SIGNED_TYPES)
				&& ((conv_params->is_neg && nb_zeros_prec)
					|| (!conv_params->is_neg && ((conv_params->flags & FL_PLUS)
						|| (conv_params->flags & FL_SPACE)))));
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
** Check if `val_str` should have a prefix ('0x' or '0X'):
**  - type has to be either ('x' or 'X'),
**  - FL_HASH flag is set,
**  - value is not zero.
*/

int				has_prefix(t_format *conv_params)
{
	return ((conv_params->flags & FL_POINT)
			|| (ft_instr(conv_params->type_char, TYPE_PREFIX)
				&& conv_params->flags & FL_HASH
				&& !(conv_params->flags & FL_NULL)));
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
	else if (conv_params->type_char == 'b')
		ft_strprepend(PREF_BIN, val_str);
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
	else if (!ft_instr(conv_params->type_char, NUM_TYPES)
			&& (conv_params->flags & FL_ZERO))
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
	nb_zeros_prec = get_nb_zeros_prec(nb_digits, conv_params);
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

	if (conv_params->flags & FL_ERR)
		arg_val = conv_params->type_char;
	else
		arg_val = get_char_arg_val(args);
	if (!arg_val)
		conv_params->flags |= FL_NULL;
	val_str = char_arg_val_to_str(arg_val);
	val_str = format_char_str(val_str, conv_params);
	return (val_str);
}

char			*get_formatted_str_str(t_format *conv_params, va_list args)
{
	char		*val_str;

	if (!(val_str = get_str_arg_val(args)))
		val_str = ft_strdup("(null)");
	else
		val_str = ft_strdup(val_str);
	val_str = format_str(val_str, conv_params);
	return (val_str);
}

char			*get_formatted_str(t_format *conv_params, va_list args)
{
	char		*val_str;

	val_str = NULL;
	if (ft_instr(conv_params->type_char, NUM_TYPES))
		val_str = get_formatted_str_int(conv_params, args);
	else if (conv_params->type_char == 'c' || conv_params->flags & FL_ERR)
		val_str = get_formatted_str_char(conv_params, args);
	else if (conv_params->type_char == 's')
		val_str = get_formatted_str_str(conv_params, args);
	return (val_str);
}

void			build_final_str(t_worker *work, char *append, int len)
{
	char		*tmp;

	if (!work->str)
		tmp = (char *)ft_memjoin("", 0, append, len);
	else
		tmp = (char	*)ft_memjoin(work->str, work->count, append, len);
	if (work->str)
		ft_strdel(&work->str);
	work->str = tmp;
	work->count += len;
}

void			save_buf(t_worker *work)
{
	build_final_str(work, work->buf, work->i);
	work->i = 0;
}

void			add_to_buff(t_worker *work, char *val_str, int len)
{
	int		i;

	if (!val_str)
		return ;
	if (len > BUF_SIZE || (work->i + len > BUF_SIZE))
		save_buf(work);
	if (len > BUF_SIZE)
		build_final_str(work, val_str, len);
	else
	{
		i = 0;
		while (len--)
			work->buf[(work->i)++] = val_str[i++];
	}
	ft_strdel(&val_str);
}

void			conv_handler(t_worker *work, const char **fmt, va_list args,
								t_format *conv_params)
{
	char 	*formatted_str;
	char	*tmp;
	int		len;

	*conv_params = (t_format){0, 0, 0, 0, 0u, LEN_MOD_NA, UNSIGNED};
	*fmt = parse_conv_spec(*fmt + 1, conv_params);
	formatted_str = get_formatted_str(conv_params, args);
	if ((conv_params->type_char == 'c') && (conv_params->flags & FL_NULL)
			&& (conv_params->flags & FL_MINUS))
	{
		tmp = ft_strnew(1);
		add_to_buff(work, tmp, 1);
	}
	len = ft_strlen(formatted_str);
	if ((conv_params->type_char == 'c') && (conv_params->flags & FL_NULL) &&
			!(conv_params->flags & FL_MINUS))
		len++;
	add_to_buff(work, formatted_str, len);
}

int				parse_fmt(char **str, const char *fmt, va_list args)
{
	t_worker	work;
	t_format	conv_params;

	work = (t_worker){NULL, {0}, 0, 0};
	while (*fmt)
	{
		if (work.i > BUF_SIZE - 1)
			save_buf(&work);
		if (*fmt == PERCENT)
			conv_handler(&work, &fmt, args, &conv_params);
		else
			work.buf[work.i++] = *fmt++;
	}
	save_buf(&work);
	*str = work.str;
	return (work.count);
}
