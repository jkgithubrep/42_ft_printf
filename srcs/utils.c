/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkettani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 10:44:52 by jkettani          #+#    #+#             */
/*   Updated: 2019/03/17 09:07:52 by jkettani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "libft.h"
#include <stdio.h>
#include "print_bigint_utils.h"

/*
** Take a string starting with a digit, extract the number as an int and return
** a pointer to the next non-digit character in the string.
** The value is either saved as a precision or a width depending on the value
** of the `FL_PREC' flag.
*/

const char		*save_value_skip_digits(const char *fmt, t_format *conv_params)
{
	int		int_value;

	int_value = ft_atoi(fmt);
	if (int_value >= 0)
	{
		if (conv_params->flags & FL_PREC)
			conv_params->prec = int_value;
		else
			conv_params->width = int_value;
	}
	else if (conv_params->flags & FL_PREC)
		conv_params->flags ^= FL_PREC;
	fmt = ft_strskip(fmt, &ft_isdigit);
	return (fmt);
}

/*
** Update the `flags' member in the `t_format' structure.
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
** Update the `len_modif' member value in the `t_format' structure.
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
** Parse a conversion specification (string portion starting after the `%'
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
** parameters in the `t_format' structure.
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
** Extract the next value in the va_list and update the right member of the
** union based on the value of the length modifier:
**   - LEN_MOD_CAP_L (`L'): long double
**   - else: double
** If the value equals zero, set the FL_NULL flag.
** If the value is negative (sign bit equals 1), and the value is not `nan',
** set the `is_neg' flag to 1.
*/

t_dbls			*get_dbl_arg_val(t_dbls *arg_val, t_format *conv_params,
															va_list args)
{
	if (conv_params->len_mod == LEN_MOD_CAP_L)
	{
		if (!(arg_val->ldbl = (long double)va_arg(args, long double)))
			conv_params->flags |= FL_NULL;
		if (arg_val->ldbl_parts.sign 
				&& !(arg_val->ldbl_parts.exponent == 0x7FFF 
					&& arg_val->ldbl_parts.mantissa))
			conv_params->is_neg = 1;
	}
	else
	{
		if (!(arg_val->dbl = (double)va_arg(args, double)))
			conv_params->flags |= FL_NULL;
		if (arg_val->dbl_parts.sign
				&& !(arg_val->dbl_parts.exponent == 0x7FF 
					&& arg_val->dbl_parts.mantissa))
			conv_params->is_neg = 1;
	}	
	if (!(conv_params->flags & FL_PREC))
		conv_params->prec = 6;
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

int				get_nb_zeros_prec_dbl(int nb_digits, t_format *conv_params)
{
	int			nb;

	nb = 0;
	if ((conv_params->flags & FL_ZERO) && !(conv_params->flags & FL_MINUS))
		nb = (int)ft_max(conv_params->width
				- (nb_digits + ((conv_params->is_neg)
						|| (conv_params->flags & FL_PLUS)
						|| (conv_params->flags & FL_SPACE))), 0);
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
	else if (!ft_instr(conv_params->type_char, INT_TYPES)
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



char			*format_dbl_str(char *val_str, t_format *conv_params)
{
	int		padding;
	int		nb_digits;
	int		nb_zeros_prec;

	nb_digits = ft_strlen(val_str);
	nb_zeros_prec = get_nb_zeros_prec_dbl(nb_digits, conv_params);
	if (nb_zeros_prec)
		prepend_prec(&val_str, nb_zeros_prec);
	if (has_sign(1, conv_params))
		prepend_sign(&val_str, conv_params);
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

char			*get_formatted_str_from_int(t_format *conv_params, va_list args)
{
	intmax_t	arg_val;
	char		*val_str;

	if (!(arg_val = get_int_arg_val(conv_params, args)))
		conv_params->flags |= FL_NULL;
	val_str = int_arg_val_to_str(arg_val, conv_params);
	val_str = format_int_str(val_str, conv_params);
	return (val_str);
}

/*
** Check that from index `begin' to then end of `digits', there are only zeros.
*/

int				check_end_digits(char *digits, size_t begin)
{
	size_t		i;

	i = begin;
	while (digits[i])
	{
		if (digits[i] != '0')
			return (0);
		i++;
	}
	return (1);
}

char			*round_nb(char *digits, int *exponent, t_format *conv_params)
{
	size_t		i;
	t_uint		carry;

	i = ft_max(*exponent, 0) + conv_params->prec;
	if (!digits[i + 1] || digits[i + 1]  < '5' || ((digits[i + 1] == '5') 
			&& !((digits[i] - '0') & 1U) && check_end_digits(digits, i + 2)))
		return (digits);
	carry = 1U;
	while (i && carry)
	{
		if ((digits[i] = (digits[i] == '9') ? '0' : digits[i] + 1) != '0')
			carry = 0U;
		--i;
	}
	if (i || !carry)
		return (digits);
	if (digits[i] == '9')
	{
		digits[i] = '1';
		digits[ft_max((*exponent)++, 0) + conv_params->prec + 1] = '0';
	}
	else
		digits[i]++;
	return (digits);
}

/*
** Handle specific values `nan' and `inf':
**  - `nan': exponent = 0x7FF (double) / exponent = 0x7FFF (long double)
**           and mantissa > 0;
**  - `inf': exponent = 0x7FF (double) / exponent = 0x7FFF (long double)
**           and mantissa = 0;
*/

char			*handle_dbl_limit_values(t_dbls *arg_val, t_format *conv_params)
{
	if (conv_params->len_mod == LEN_MOD_CAP_L)
	{
		if (arg_val->ldbl_parts.exponent == 0x7FFF)
		{
			if (!arg_val->ldbl_parts.mantissa)
				return (ft_strdup("inf"));
			else
				return (ft_strdup("nan"));
		}
	}
	else 
	{
		if (arg_val->dbl_parts.exponent == 0x7FF)
		{
			if (!arg_val->dbl_parts.mantissa)
				return (ft_strdup("inf"));
			else
				return (ft_strdup("nan"));
		}
	}
	return (NULL);
}

/*
** Convert the digits extracted to a final value by rounding the number and 
** inserting a `.' at the right place.
** If exponent < 0, missing zeros must be added (ex: from 0.0142 only 142 digits
** would be extracted, 2 zeros must be prepended).
*/

char			*handle_dbl_precision(char **digits, int exponent,
										t_format *conv_params)
{
	char		*val_str;
	char		*fraction;

	if (exponent < 0)
		ft_strpad_left(digits, '0', -exponent);
	if (exponent <= 0)
		ft_strpad_right(digits, '0',
				ft_max(conv_params->prec - (ft_strlen(*digits) - 1), 0));
	else
		ft_strpad_right(digits, '0', 
			ft_max(exponent - (ft_strlen(*digits) - 1), 0) 
			+ conv_params->prec - ((exponent > (int)ft_strlen(*digits) - 1) ?
			0 : ft_strlen(*digits + exponent + 1)));
	round_nb(*digits, &exponent, conv_params);
	if (!(val_str = ft_strndup(*digits, ft_max(exponent, 0) + 1)))
		return (NULL);
	if ((conv_params->flags & FL_HASH) || !((conv_params->flags & FL_PREC)
										&& !(conv_params->prec)))
		ft_strappend(&val_str, ".");
	if (conv_params->prec)
	{
		if (!(fraction = ft_strndup(*digits + ft_max(exponent, 0) + 1,
													conv_params->prec)))
			return (NULL);
		ft_strappend(&val_str, fraction);
		ft_strdel(&fraction);
	}
	return (val_str);
}


/*
** Convert the double value to a string with the right precision.
*/

char			*dbl_arg_val_to_str(t_dbls *arg_val, t_format *conv_params)
{
	char		*digits;
	char		*val_str;
	int			exponent;

	if ((val_str = handle_dbl_limit_values(arg_val, conv_params)))
	{
		if (conv_params->flags & FL_ZERO)
			conv_params->flags ^= FL_ZERO;
		if (!ft_strcmp(val_str, "nan"))
		{
			conv_params->flags |= (FL_PLUS | FL_SPACE);
			conv_params->flags ^= (FL_PLUS | FL_SPACE);
		}
		return (val_str);
	}
	if (!(digits = ft_strnew(BUF_DIGITS_SIZE)))
		return (NULL);
	exponent = 0;
	if (!(conv_params->flags & FL_NULL))
		dragon4(arg_val, digits, &exponent, conv_params);
	else
		digits[0] = '0';
	val_str = handle_dbl_precision(&digits, exponent, conv_params);
	ft_strdel(&digits);
	return (val_str);
}

char			*get_formatted_str_from_dbl(t_format *conv_params, va_list args)
{
	t_dbls		arg_val;
	char		*val_str;

	arg_val.ldbl = 0.L;
	get_dbl_arg_val(&arg_val, conv_params, args);
	val_str = dbl_arg_val_to_str(&arg_val, conv_params);
	val_str = format_dbl_str(val_str, conv_params);
	return (val_str);
}

char			*get_formatted_str_from_char(t_format *conv_params,
																va_list args)
{
	t_uchar		arg_val;
	char		*val_str;

	if (conv_params->flags & FL_ERR)
		arg_val = conv_params->type_char;
	else
		arg_val = (t_uchar)va_arg(args, int);
	if (!arg_val)
		conv_params->flags |= FL_NULL;
	val_str = char_arg_val_to_str(arg_val);
	val_str = format_char_str(val_str, conv_params);
	return (val_str);
}

char			*get_formatted_str_from_str(t_format *conv_params, va_list args)
{
	char		*val_str;

	if (!(val_str = (char *)va_arg(args, char *)))
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
	if (ft_instr(conv_params->type_char, INT_TYPES))
		val_str = get_formatted_str_from_int(conv_params, args);
	else if (ft_instr(conv_params->type_char, DBL_TYPES))
		val_str = get_formatted_str_from_dbl(conv_params, args);
	else if (conv_params->type_char == 'c' || conv_params->flags & FL_ERR)
		val_str = get_formatted_str_from_char(conv_params, args);
	else if (conv_params->type_char == 's')
		val_str = get_formatted_str_from_str(conv_params, args);
	else if (!conv_params->type_char)
		val_str = ft_strnew(0);
	return (val_str);
}

int				build_final_str(t_worker *work, char *append, int len)
{
	char		*tmp;

	if (!work->str)
	{
		if (!(tmp = (char *)ft_memjoin("", 0, append, len)))
			return (EXIT_FAIL);
	}
	else
	{
		if (!(tmp = (char	*)ft_memjoin(work->str, work->count, append, len)))
			return (EXIT_FAIL);
	}
	if (work->str)
		ft_strdel(&work->str);
	work->str = tmp;
	work->count += len;
	return (EXIT_SUCCESS);
}

int				save_buf(t_worker *work)
{
	if (build_final_str(work, work->buf, work->i) < 0)
		return (EXIT_FAIL);
	work->i = 0;
	return (EXIT_SUCCESS);
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

/*
** First compare bigint lengths, and return 1 if length of bigint1 is greater
** than length of bigint2.
** If lengths are equal, compare blocks one by one from high to low. 
** If blocks values are not equal, return 1 if block of bigint1 is greater than 
** block of bigint2, else return -1.
** If all blocks are equal, return 0.
*/

int				bigint_compare(const t_bigint *bigint1, const t_bigint *bigint2)
{
	size_t		i; 

	if (bigint1->length != bigint2->length)
		return ((bigint1->length > bigint2->length) ? 1 : -1);
	i = bigint1->length;
	while (i--)
		if (bigint1->blocks[i] != bigint2->blocks[i])
			return ((bigint1->blocks[i] > bigint2->blocks[i]) ? 1 : -1);
	return (0);
}

/*
** Make `large_nb' point on the biggest big int, and `small_nb` on the
** smallest.
*/

void			order_bigints(const t_bigint *bigint1, const t_bigint *bigint2,
					const t_bigint **small_nb, const t_bigint **large_nb)
{
	if (bigint_compare(bigint1, bigint2) >= 0)
	{
		*large_nb = bigint1;
		*small_nb = bigint2;
	}
	else
	{
		*large_nb = bigint2;
		*small_nb = bigint1;
	}
}

/*
** Return the number of blocks used to store the bigint.
*/

size_t			bigint_size(const t_bigint *bigint)
{
	size_t		i;

	i = BIGINT_SIZE;
	while (i--)
		if (bigint->blocks[i])
			return (i + 1);
	return (0);
}

/*
** Add `bigint1' and `bigint2' and store the sum in `result'.
** Return a pointer to `result'.
*/

t_bigint		*bigint_add(const t_bigint *bigint1, const t_bigint *bigint2,
							t_bigint *result)
{
	t_ulint			sum;
	t_ulint			carry;
	size_t			i;
	size_t			max_len;

	sum = 0UL;
	carry = 0UL;
	i = 0;
	max_len = (size_t)ft_max(bigint1->length, bigint2->length);
	while (i < max_len)
	{
		sum = carry + (t_ulint)bigint1->blocks[i]
					+ (t_ulint)bigint2->blocks[i];
		result->blocks[i] = (t_uint)(sum & 0xFFFFFFFFUL);
		carry = sum >> BIGINT_BLOCK_SIZE;
		i++;
	}
	if (carry && (i < BIGINT_SIZE))
		result->blocks[i] = (t_uint)(carry & 0xFFFFFFFFUL);
	result->length = (carry) ? max_len + 1 : max_len;
	return (result);
}

/*
** Substract the smallest number from `bigint1' and `bigint2' to the biggest
** from `bigint1` and `bigint2' and store the difference in `result'.
** Return a pointer to `result'.
*/

t_bigint		*bigint_substract(const t_bigint *bigint1,
									const t_bigint *bigint2, t_bigint *result)
{
	const t_bigint	*large_nb;
	const t_bigint	*small_nb;
	t_ulint			carry;
	t_ulint			tmp;
	size_t			i;

	carry = 0UL;
	i = 0;
	order_bigints(bigint1, bigint2, &small_nb, &large_nb);
	while (i < large_nb->length)
	{
		tmp = (t_ulint)large_nb->blocks[i] - carry;
		carry = (((large_nb->blocks[i] > 0) || (!large_nb->blocks[i] && !carry))
					&& (tmp >= (t_ulint)small_nb->blocks[i])) ? 0UL : 1UL;
		result->blocks[i] = (t_uint)((tmp + ((carry) ? (1UL << 32) : 0UL)
					- (t_ulint)small_nb->blocks[i]) & 0xFFFFFFFFUL);
		i++;
	}
	result->length = bigint_size(result);
	return (result);
}

/*
** Convert a uintmax_t number to a bigint and store the obtained bigint in
** `result'.
** Return a pointer to `result'.
*/

t_bigint		*uimax_to_bigint(uintmax_t nb, t_bigint *result)
{
	int			i;

	i = -1;
	while (nb && ++i < BIGINT_SIZE)
	{
		result->blocks[i] = (t_uint)(nb & 0xFFFFFFFFUL);
		nb >>= BIGINT_BLOCK_SIZE;
	}
	result->length = bigint_size(result);
	return (result);
}

/*
** Shift the bigint to the left.
*/

t_bigint		*bigint_shiftleft(t_bigint *result, t_uint shift)
{
	t_uint		i;
	int			block_size;

	if (!shift)
		return (result);
	i = BIGINT_SIZE;
	block_size = BIGINT_BLOCK_SIZE;
	if (!(shift % block_size))
		while (--i >= (shift / block_size))
			result->blocks[i] = result->blocks[i - (shift / block_size)];
	else
	{
		while (--i >= (shift/block_size + 1))
			result->blocks[i] = (result->blocks[i - (shift / block_size + 1)]
				>> (block_size - (shift % block_size))) 
				| (result->blocks[i - shift / block_size] 
					<< (shift % block_size));
		result->blocks[i] = result->blocks[i - shift/block_size]
								<< (shift % block_size);
	}
	i = !(shift % block_size) ? i + 1 : i;
	while (i--)
		result->blocks[i] = 0;
	result->length = bigint_size(result);
	return (result);
}

/*
** Multiply a bigint by an unsigned int.
*/

t_bigint		*bigint_multiply_nb(t_bigint *result, t_uint nb)
{
	size_t		i;
	t_ulint		carry;
	t_ulint		res;

	if (nb == 1)
		return (result);
	i = 0;
	carry = 0UL;
	while (i < result->length)
	{
		res = (t_ulint)result->blocks[i] * (t_ulint)nb + carry;
		result->blocks[i] = (t_uint)(res & 0xFFFFFFFFUL);
		carry = res >> 32;
		i++;
	}
	if (carry && i < BIGINT_SIZE)
		result->blocks[i] = (t_uint)(carry & 0xFFFFFFFFUL);
	result->length = bigint_size(result);
	return (result);
}

t_bigint		*bigint_cpy(t_bigint *dest, const t_bigint *src)
{
	size_t		i;
	
	i = 0;
	while (i < src->length)
	{
		dest->blocks[i] = src->blocks[i];
		i++;
	}
	dest->length = src->length;
	return (dest);
}

t_bigint		*bigint_multiply(const t_bigint *bigint1, 
									const t_bigint *bigint2, t_bigint *result)
{
	const t_bigint	*large_nb;
	const t_bigint	*small_nb;
	t_bigint		bigint_tmp;
	size_t			i;
	int				shift;

	i = 0;
	shift = 0;
	order_bigints(bigint1, bigint2, &small_nb, &large_nb);
	while (i < small_nb->length)
	{
		bigint_tmp = (t_bigint){0, {0}};
		bigint_cpy(&bigint_tmp, large_nb);
		bigint_multiply_nb(&bigint_tmp, small_nb->blocks[i]);		
		bigint_shiftleft(&bigint_tmp, shift * BIGINT_BLOCK_SIZE);
		bigint_add(result, &bigint_tmp, result);	
		++i;
		++shift;
	}
	return (result);
}


void				bigint_pow10(t_bigint *result, t_uint exponent)
{
	const t_uint	first_pow10[8] = {1, 10, 100, 1000, 10000, 100000, 1000000, 
										10000000};
	const t_bigint	lookup_tbl[6] = 
					{{1, {100000000}},
					{2, {0x6fc10000, 0x002386f2}},
					{4, {0x00000000, 0x85acef81, 0x2d6d415b, 0x000004ee}},
					{7, {0x00000000, 0x00000000, 0xbf6a1f01, 0x6e38ed64,
						0xdaa797ed, 0xe93ff9f4, 0x00184f03}},
					{14, {0x00000000, 0x00000000, 0x00000000, 0x00000000, 
							0x2e953e01, 0x03df9909, 0x0f1538fd, 0x2374e42f, 
							0xd3cff5ec, 0xc404dc08, 0xbccdb0da, 0xa6337f19, 
							0xe91f2603, 0x0000024e}},
					{27, {0x00000000, 0x00000000, 0x00000000, 0x00000000,
							0x00000000,0x00000000, 0x00000000, 0x00000000, 
							0x982e7c01, 0xbed3875b, 0xd8d99f72, 0x12152f87, 
							0x6bde50c6, 0xcf4a6e70, 0xd595d80f, 0x26b2716e, 
							0xadc666b0, 0x1d153624, 0x3c42d35a, 0x63ff540e, 
							0xcc5573c0, 0x65f9ef17, 0x55bc28f2, 0x80dcc7f7, 
							0xf46eeddc, 0x5fdcefce, 0x000553f7}}};
	t_bigint		bigint_tmp;
	t_uint			tbl_index;
	t_uint			count;
	t_uint			i;
	
	if (exponent & 0x7)
		uimax_to_bigint(first_pow10[exponent & 0x7], result);
	else
		uimax_to_bigint(1U, result);
	exponent >>= 3;
	tbl_index = 0;
	while (exponent && tbl_index < 6)
	{
		if (exponent & 1U)
		{
			bigint_tmp = (t_bigint){0, {0}};
			bigint_multiply(result, &lookup_tbl[tbl_index], &bigint_tmp);
			*result = (t_bigint){0, {0}};
			bigint_cpy(result, &bigint_tmp);
		}
		exponent >>= 1;
		++tbl_index;
	}
	count = 1U << 1;
	while (exponent)
	{
		if (exponent & 1U)
		{
			i = 0;
			while (i < count)
			{
				bigint_tmp = (t_bigint){0, {0}};
				bigint_multiply(result, &lookup_tbl[5], &bigint_tmp);
				*result = (t_bigint){0, {0}};
				bigint_cpy(result, &bigint_tmp);
				i++;
			}
		}
		exponent >>= 1;
		count <<= 1;
	}
}

/*
** Assuming  0 <= dividend / divisor < 10, give the result of the integer
** division of dividend by divisor.
*/

int				bigint_divide(const t_bigint *dividend, const t_bigint *divisor)
{
	int				res;
	t_bigint		bigint_tmp;

	res = 5;
	bigint_tmp = (t_bigint){0, {0}};
	bigint_multiply_nb(bigint_cpy(&bigint_tmp, divisor), res);
	if (bigint_compare(dividend, &bigint_tmp) > 0)
	{
		while (bigint_compare(dividend, bigint_add(&bigint_tmp, divisor,
														&bigint_tmp)) > 0)
			++res;	
		return (!bigint_compare(dividend, &bigint_tmp) ? res + 1 : res);
	}
	if (bigint_compare(dividend, &bigint_tmp) < 0)
	{
		while (bigint_compare(dividend, bigint_substract(&bigint_tmp, divisor,
														&bigint_tmp)) < 0)
			--res;	
		return (res - 1);
	}
	return (res);
}

/*
** Calculate the value of val_exponent and val_mantissa for each representation
** based on the following formulae:
**  - normalized number:
** ( 1 + mantissa / 2^(nb mantissa bits) ) * 2 ^ (exp + 1 - 2^(nb exp bits - 1))
**  - denormalized number:
** ( mantissa / 2^(nb of mantissa bits) ) * 2 ^ ( 1 + 1 - 2^(nb exp bits - 1) )
** 
**  Representations:
**  - 64-bit denormalized:
**          value = ( mantissa / 2^52 ) * 2 ^ (1 - 1023)
**                = mantissa * 2 ^ ( 1 - 1023 - 52 )
**  - 64-bit normalized:
**			value = ( 1 + mantissa / 2^52 ) * 2 ^ ( exponent - 1023 )
**                = ( 2^52 + mantissa ) * 2 ^ ( exponent - 1023 - 52 )
**  - 80-bit denormalized:
**          value = ( mantissa / 2^63 ) * 2 ^ (1 - 16383)
**                - mantissa * 2 ^ ( 1 - 16383 - 63 )
**  - 80-bit normalized:
**          value = ( 1 + mantissa / 2^63 ) * 2 ^ ( exponent - 16383 )
**                = ( 2^63 + mantissa ) * 2 ^ ( exponent - 16383 - 63 )
*/

void			init_mantissa_exponent(t_dbls *arg_val, t_ullint *val_mantissa, 
					int *val_exponent, t_format *conv_params)
{
	if (conv_params->len_mod == LEN_MOD_CAP_L)
	{
		*val_mantissa = (t_ullint)arg_val->ldbl_parts.mantissa
					+ ((arg_val->ldbl_parts.exponent) ? (1ULL << 63) : 0ULL);
		*val_exponent = (int)arg_val->ldbl_parts.exponent - 16446
					+ ((arg_val->ldbl_parts.exponent) ? 0 : 1);
	}
	else
	{
		*val_mantissa = (t_ullint)arg_val->dbl_parts.mantissa 
						+ ((arg_val->dbl_parts.exponent) ? (1ULL << 52) : 0ULL);
		*val_exponent = (int)arg_val->dbl_parts.exponent - 1075
						+ ((arg_val->dbl_parts.exponent) ? 0 : 1);
	}
}
					
/*
** First, represent the floating-point number as a pair of integers in the
** equation: 
**
**                 val_mantissa * 2 ^ (val_exponent)
**
** Then, represent it as a fraction of two big int depending on the value of
** val_exponent:
**   - val_exponent >= 0:          val_mantissa * 2 ^ (val_exponent)
**                                ---------------------------------
**                                               1
**
**   - val_exponent < 0:                    val_mantissa
**                                ---------------------------------
**                                       2 ^ (-val_exponent)
** 
*/

void			initialize_fraction(t_dbls *arg_val, t_bigint *val_num,
									t_bigint *val_den, t_format *conv_params)
{
	t_ullint	val_mantissa;
	int			val_exponent;

	val_mantissa = 0ULL;
	val_exponent = 0;
	init_mantissa_exponent(arg_val, &val_mantissa, &val_exponent, conv_params);
	uimax_to_bigint(val_mantissa, val_num);
	if (val_exponent >= 0)
	{
		bigint_shiftleft(val_num, val_exponent);
		uimax_to_bigint(1, val_den);
	}
	else
	{
		uimax_to_bigint(1, val_den);
		bigint_shiftleft(val_den, -val_exponent);
	}
}

/*
** Scale the fraction so that 0 <= val_num / val_den < 10, ie. first digit is in
** the ones place.
** Example: 
**   - 142.5 would become 1.425 --> val_num / (val_den * 10^2)
**   - 0.01425 would become 1.425 --> val_num / (val_den * 10^-2)
**                                --> (val_num * 10^2) / val_den
*/

void			scale_fraction(t_bigint *val_num, t_bigint *val_den,
									int exponent)
{
	t_bigint	bigint_tmp;
	t_bigint	pow10;

	bigint_tmp = (t_bigint){0, {0}};
	pow10 = (t_bigint){0, {0}};
	if (exponent > 0)
	{
		bigint_pow10(&pow10, exponent);
		bigint_multiply(val_den, &pow10, &bigint_tmp);
		*val_den = (t_bigint){0, {0}};
		bigint_cpy(val_den, &bigint_tmp);
	}
	else if (exponent < 0)
	{
		bigint_pow10(&pow10, -exponent);
		bigint_multiply(val_num, &pow10, &bigint_tmp);
		*val_num = (t_bigint){0, {0}};
		bigint_cpy(val_num, &bigint_tmp);
	}
}

int				get_exponent(t_ldbl value)
{
	int			exp;

	exp = 0;
	if (value < 0)
		value *= -1;
	if (!value)
		return (exp);
	if (value > 1)
	{
		while (value >= 10)
		{
			value /= 10;
			++exp;
		}
		return (exp);
	}
	while (value < 1)
	{
		value *= 10;
		++exp;
	}
	return (-exp);
}

/*
** Get the power of ten of the floating-point number written in scientific 
** notation.
** Example: 142.5 = 1.425 * 10 ^ 2 --> exponent = 2
*/

void			get_first_digit_exponent(t_dbls *arg_val, int *exponent,
												t_format *conv_params)
{
	if (conv_params->len_mod == LEN_MOD_CAP_L)
		*exponent = get_exponent(arg_val->ldbl);
	else
		*exponent = get_exponent(arg_val->dbl);
}

/*
** Get the representation of the floating-point number as a fraction of 2 big
** ints which is superior to 0 and strictly inferior to 10.
** Extract the digits as the integer division of the numerator by the
** denominator.
** Compute the remainder by substracting the digit extracted
** (ex: 1.425 - 1 --> 0.425).
** Scale the next digit in the first place (ex: 0.425 * 10 --> 4.25).
** Repeat until numerator equals 0.
*/

void			dragon4(t_dbls *arg_val, char *digits, int *exponent, t_format 
																*conv_params)
{
	t_bigint	val_num;
	t_bigint	val_den;
	t_bigint	bigint_tmp;
	int			i;
	int			digit;
	
	val_num = (t_bigint){0, {0}};
	val_den = (t_bigint){0, {0}};
	initialize_fraction(arg_val, &val_num, &val_den, conv_params);
	get_first_digit_exponent(arg_val, exponent, conv_params);
	scale_fraction(&val_num, &val_den, *exponent);
	i = 0;
	while (val_num.length > 0 && i < BUF_DIGITS_SIZE)
	{
		digit = bigint_divide(&val_num, &val_den);
		digits[i] = '0' + digit;
		bigint_tmp = (t_bigint){0, {0}};
		bigint_cpy(&bigint_tmp, &val_den);
		bigint_multiply_nb(&bigint_tmp, digit);
		bigint_substract(&val_num, &bigint_tmp, &val_num);
		bigint_multiply_nb(&val_num, 10);
		++i;
	}
}

int				conv_handler(t_worker *work, const char **fmt, va_list args,
								t_format *conv_params)
{
	char 		*formatted_str;
	char		*tmp;
	int			len;

	*conv_params = (t_format){0, 0, 0, 0, 0u, LEN_MOD_NA, UNSIGNED};
	*fmt = parse_conv_spec(*fmt + 1, conv_params);
	formatted_str = get_formatted_str(conv_params, args);
	if ((conv_params->type_char == 'c') && (conv_params->flags & FL_NULL)
			&& (conv_params->flags & FL_MINUS))
	{
		if (!(tmp = ft_strnew(1)))
			return (EXIT_FAIL);
		add_to_buff(work, tmp, 1);
	}
	len = ft_strlen(formatted_str);
	if ((conv_params->type_char == 'c') && (conv_params->flags & FL_NULL) &&
			!(conv_params->flags & FL_MINUS))
		len++;
	add_to_buff(work, formatted_str, len);
	return (EXIT_SUCCESS);
}

int				parse_fmt(char **str, const char *fmt, va_list args)
{
	t_format	conv_params;
	t_worker	work;

	work = (t_worker){NULL, {0}, 0, 0};
	while (*fmt)
	{
		if (work.i > BUF_SIZE - 1)
			if (save_buf(&work) < 0)
				return (EXIT_FAIL);
		if (*fmt == PERCENT)
			conv_handler(&work, &fmt, args, &conv_params);
		else
			work.buf[work.i++] = *fmt++;
	}
	save_buf(&work);
	*str = work.str;
	return (work.count);
}
