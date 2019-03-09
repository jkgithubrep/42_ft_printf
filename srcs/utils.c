/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkettani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 14:25:08 by jkettani          #+#    #+#             */
/*   Updated: 2019/03/09 17:09:42 by jkettani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "libft.h"
#include <stdio.h>
#include "print_bigint_utils.h"

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
	if (ft_instr(conv_params->type_char, INT_TYPES))
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

/*
** First compare bigint lenghts and return the difference if they are not equal.
** Otherwise, compare blocks one by one from high to low. If blocks are not
** equal, return 1 if block 1 is greater than block 2, else return -1.
** If all blocks are equal, return 0.
*/

int				bigint_compare(const t_bigint *bigint1, const t_bigint *bigint2)
{
	int			i; 

	if (bigint1->length != bigint2->length)
		return (bigint1->length - bigint2->length);
	i = bigint1->length;
	while (i--)
		if (bigint1->blocks[i] != bigint2->blocks[i])
			return ((bigint1->blocks[i] > bigint2->blocks[i]) ? 1 : -1);
	return (0);
}

void			order_bigints(const t_bigint *bigint1, const t_bigint *bigint2,
					const t_bigint **small_nb, const t_bigint **large_nb)
{
	if (bigint1->length > bigint2->length)
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

int				bigint_size(const t_bigint *bigint)
{
	int			i;

	i = BIGINT_SIZE;
	while (i--)
		if (bigint->blocks[i])
			return (i + 1);
	return (0);
}

void			bigint_add(const t_bigint *bigint1, const t_bigint *bigint2,
							t_bigint *result)
{
	const t_bigint	*large_nb;
	const t_bigint	*small_nb;
	t_ulint			sum;
	t_ulint			carry;
	int				i;

	order_bigints(bigint1, bigint2, &small_nb, &large_nb);
	sum = 0LU;
	carry = 0LU;
	i = 0;
	while (i < small_nb->length)
	{
		sum = carry + (t_ulint)small_nb->blocks[i]
					+ (t_ulint)large_nb->blocks[i];
		result->blocks[i] = (t_uint)(sum & 0xFFFFFFFFLU);
		carry = sum >> BIGINT_BLOCK_SIZE;
		i++;
	}
	while (i < large_nb->length)
	{
		sum = carry + (t_ulint)large_nb->blocks[i];
		result->blocks[i]  = (t_uint)(sum & 0xFFFFFFFFLU);
		carry = sum >> BIGINT_BLOCK_SIZE;
		i++;
	}
	if (carry && (i < BIGINT_SIZE))
		result->blocks[i] = (t_uint)(carry & 0xFFFFFFFFLU);
	result->length = (carry) ? large_nb->length + 1 : large_nb->length;
}

void			bigint_substract(const t_bigint *bigint1,
									const t_bigint *bigint2, t_bigint *result)
{
	const t_bigint	*large_nb;
	const t_bigint	*small_nb;
	t_ulint			rem;
	t_ulint			carry;
	t_ulint			tmp;
	int				i;

	if (bigint_compare(bigint1, bigint2) >= 0)
	{
		large_nb = bigint1;
		small_nb = bigint2;
	}
	else
	{
		large_nb = bigint2;
		small_nb = bigint1;
	}
	rem = 0LU;
	carry = 0LU;
	i = 0;
	while (i < small_nb->length)
	{
		tmp = (t_ulint)large_nb->blocks[i] - carry;
		if (((large_nb->blocks[i] > 0) || (!large_nb->blocks[i] && !carry)) 
				&& (tmp >= (t_ulint)small_nb->blocks[i]))
			rem = tmp - (t_ulint)small_nb->blocks[i];
		else
			rem = tmp + (1LU << 32) - (t_ulint)small_nb->blocks[i];
		carry = (((large_nb->blocks[i] > 0) || (!large_nb->blocks[i] && !carry))
					&& (tmp >= (t_ulint)small_nb->blocks[i])) ? 0LU : 1LU;
		result->blocks[i] = (t_uint)(rem & 0xFFFFFFFFLU);
		i++;
	}
	while (i < large_nb->length)
	{
		if (large_nb->blocks[i] || (!large_nb->blocks[i] && !carry))
			rem = (t_ulint)large_nb->blocks[i] - carry;
		else
			rem = (t_ulint)large_nb->blocks[i] + (1LU << 32) - carry;
		carry = (large_nb->blocks[i] || (!large_nb->blocks[i] && !carry)) ?
					0LU : 1LU;
		result->blocks[i] = (t_uint)(rem & 0xFFFFFFFFLU);
		i++;
	}
	result->length = bigint_size(result);
}

void			uimax_to_bigint(uintmax_t nb, t_bigint *result)
{
	int			i;

	i = -1;
	while (nb && ++i < BIGINT_SIZE)
	{
		result->blocks[i] = (t_uint)(nb & 0xFFFFFFFFLU);
		nb >>= BIGINT_BLOCK_SIZE;
	}
	result->length = bigint_size(result);
}

void			bigint_shiftleft(t_bigint *result, t_uint shift)
{
	t_uint		i;
	int			block_size;

	if (!shift)
		return ;
	i = BIGINT_SIZE;
	block_size = BIGINT_BLOCK_SIZE;
	if (!(shift % block_size))
		while (--i >= (shift / block_size))
			result->blocks[i] = result->blocks[i - (shift / block_size)];
	else
	{
		while (--i >= (shift/block_size + 1))
		{
	//		printf("result->blocks[i - (shift/block_size + 1)]=%u\n", result->blocks[i - (shift/block_size + 1)]);
	//		printf("block_size - shift %% block_size = %d\n", block_size - shift % block_size);
	//		printf("i - (shift/block_size + 1) >> (block_size - shift %% block_size) = %d\n", result->blocks[i - (shift/block_size + 1)] >> (block_size - shift % block_size));
			result->blocks[i] = (result->blocks[i - (shift / block_size + 1)]
									>> (block_size - (shift % block_size)))
									| (result->blocks[i - shift / block_size]
										<< (shift % block_size));
			//printf("i=%d\n", i);
			//print_bigint(result, "result");
		}
		result->blocks[i] = result->blocks[i - shift/block_size]
								<< (shift % block_size);
		--i;
	}
	++i;
	while (i--)
		result->blocks[i] = 0;
	result->length = bigint_size(result);
}

void			bigint_multiply_nb(t_bigint *result, t_uint nb)
{
	int			i;
	t_ulint		carry;
	t_ulint		res;

	i = 0;
	carry = 0LU;
	while (i < result->length)
	{
		res = (t_ulint)result->blocks[i] * (t_ulint)nb + carry;
		result->blocks[i] = (t_uint)(res & 0xFFFFFFFFLU);
		carry = res >> 32;
		i++;
	}
	if (carry && i < BIGINT_SIZE)
		result->blocks[i] = (t_uint)(carry & 0xFFFFFFFFLU);
	result->length = bigint_size(result);
}

void			bigint_cpy(t_bigint *dest, const t_bigint *src)
{
	int			i;
	
	i = -1;
	while (++i < src->length)
		dest->blocks[i] = src->blocks[i];
	dest->length = src->length;
}

void			bigint_multiply(const t_bigint *bigint1, 
									const t_bigint *bigint2, t_bigint *result)
{
	const t_bigint	*large_nb;
	const t_bigint	*small_nb;
	t_bigint		bigint_tmp;
	t_bigint		bigint_tmp2;
	int				i;
	int				shift;

	if (bigint_compare(bigint1, bigint2) >= 0)
	{
		large_nb = bigint1;
		small_nb = bigint2;
	}
	else
	{
		large_nb = bigint2;
		small_nb = bigint1;
	}
	i = 0;
	shift = 0;
	print_bigint(large_nb, "multi: large_nb");
	print_bigint(small_nb, "multi: small_nb");
	while (i < small_nb->length)
	{
		bigint_tmp = (t_bigint){0, {0}};
		bigint_cpy(&bigint_tmp, large_nb);
		bigint_multiply_nb(&bigint_tmp, small_nb->blocks[i]);		
		printf("small_nb[%d]=%u\n", i, small_nb->blocks[i]);
		print_bigint(&bigint_tmp, "multi: bigint tmp after multiply by n");
		bigint_shiftleft(&bigint_tmp, shift * BIGINT_BLOCK_SIZE);
		print_bigint(&bigint_tmp, "multi: bigint tmp shifted");
		bigint_tmp2 = (t_bigint){0, {0}};
		bigint_add(result, &bigint_tmp, &bigint_tmp2);	
		*result = (t_bigint){0, {0}};
		bigint_cpy(result, &bigint_tmp2);
		print_bigint(result, "multi: result");
		++i;
		++shift;
	}
}

int				get_exponent(double value)
{
	int			exp;

	exp = 0;
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

void				bigint_pow10(t_bigint *result, t_uint exponent)
{
	t_uint			*first_pow10;
	t_bigint		lookup_tbl[6] = {{1, {100000000}}, {2, {0x6fc10000, 0x002386f2}},
    	{4, {0x00000000, 0x85acef81, 0x2d6d415b, 0x000004ee}}, {7, {0x00000000,
		0x00000000, 0xbf6a1f01, 0x6e38ed64, 0xdaa797ed, 0xe93ff9f4,
		0x00184f03}}, {14, {0x00000000, 0x00000000, 0x00000000, 0x00000000,
		0x2e953e01, 0x03df9909, 0x0f1538fd, 0x2374e42f, 0xd3cff5ec, 0xc404dc08,
		0xbccdb0da, 0xa6337f19, 0xe91f2603, 0x0000024e}}, {27, {0x00000000,
		0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
        0x00000000, 0x982e7c01, 0xbed3875b, 0xd8d99f72, 0x12152f87, 0x6bde50c6,
		0xcf4a6e70, 0xd595d80f, 0x26b2716e, 0xadc666b0, 0x1d153624, 0x3c42d35a,
		0x63ff540e, 0xcc5573c0, 0x65f9ef17, 0x55bc28f2, 0x80dcc7f7, 0xf46eeddc,
		0x5fdcefce, 0x000553f7}}};
	t_bigint		bigint_tmp;
	t_uint			tbl_index;
	
	first_pow10 = (t_uint[8]){1, 10, 100, 1000, 10000, 100000, 1000000, 10000000};
	if (exponent & 0x7)
		uimax_to_bigint(first_pow10[exponent & 0x7], result);
	else
		uimax_to_bigint(1U, result);
	exponent >>= 3;
	tbl_index = 0;
	while (exponent)
	{
		if (exponent & 1U)
		{
			printf("index: %d\n", tbl_index);
			bigint_tmp = (t_bigint){0, {0}};
			print_bigint(result, "pow10: result before multi");
			print_bigint(&lookup_tbl[tbl_index], "pow10: lookup");
			bigint_multiply(result, &lookup_tbl[tbl_index], &bigint_tmp);
			print_bigint(&bigint_tmp, "pow10: bigint tmp");
			*result = (t_bigint){0, {0}};
			bigint_cpy(result, &bigint_tmp);
//			if (tbl_index == 2)
//				break ;
		}
		exponent >>= 1;
		++tbl_index;
	}
}

int				bigint_divide(const t_bigint *dividend, const t_bigint *divisor)
{
	int				res;
	t_bigint		bigint_tmp;

	res = 5;
	bigint_tmp = (t_bigint){0, {0}};
	bigint_cpy(&bigint_tmp, divisor);
	bigint_multiply_nb(&bigint_tmp, res);
	if (bigint_compare(dividend, &bigint_tmp) > 0)
	{
		while (bigint_compare(dividend, &bigint_tmp) > 0)
		{
			bigint_add(&bigint_tmp, divisor, &bigint_tmp);
			++res;	
		}
	}
	else if (bigint_compare(dividend, &bigint_tmp) < 0)
	{
		res = 1;
		bigint_tmp = (t_bigint){0, {0}};
		bigint_cpy(&bigint_tmp, divisor);
		while (bigint_compare(dividend, &bigint_tmp) > 0)
		{
			bigint_add(&bigint_tmp, divisor, &bigint_tmp);
			++res;	
		}
	}
	else
		return (res);
	return (res - 1);
}

void			dragon4(t_dbls *value)
{
	char		string[10000] = {0};
	t_bigint	val_num;
	t_bigint	val_den;
	t_bigint	bigint_tmp;
	t_bigint	pow10;
	t_ullint	val_mantissa;
	int			digit_exp;
	int			val_exponent;
	int			i;
	int			digit;
	
	val_mantissa = (t_ullint)value->dbl_parts.mantissa + (1LLU << 52);
	val_exponent = (int)value->dbl_parts.exponent - 1075;
	printf("val_mantissa: %llu\n", val_mantissa);
	printf("val_exponent: %d\n", val_exponent);
	val_num = (t_bigint){0, {0}};
	val_den = (t_bigint){0, {0}};
	uimax_to_bigint(val_mantissa, &val_num);
	print_bigint(&val_num, "val_mantissa converted to val_num");
	if (val_exponent > 0)
	{
		bigint_shiftleft(&val_num, val_exponent);
		uimax_to_bigint(1, &val_den);
	}
	else
	{
		uimax_to_bigint(1, &val_den);
		bigint_shiftleft(&val_den, -val_exponent);
	}
	print_bigint(&val_num, "val_num after exponent");
	print_bigint(&val_den, "val_den after exponent");
	digit_exp = get_exponent(value->dbl);
	printf("first_digit_exponent: %d\n", digit_exp);
	bigint_tmp = (t_bigint){0, {0}};
	pow10 = (t_bigint){0, {0}};
	if (digit_exp > 0)
	{
		bigint_pow10(&pow10, digit_exp);
		print_bigint(&pow10, "power 10");
		bigint_multiply(&val_den, &pow10, &bigint_tmp);
		print_bigint(&bigint_tmp, "bigint tmp");
		val_den = (t_bigint){0, {0}};
		bigint_cpy(&val_den, &bigint_tmp);
	}
	else if (digit_exp < 0)
	{
		bigint_pow10(&pow10, -digit_exp);
		print_bigint(&pow10, "power 10");
		bigint_multiply(&val_num, &pow10, &bigint_tmp);
		val_num = (t_bigint){0, {0}};
		bigint_cpy(&val_num, &bigint_tmp);
	}
	print_bigint(&val_num, "BIGINT NUM");
	print_bigint(&val_den, "BIGINT DEN");
	i = 0;
	while (val_num.length > 0 && i < 10000)
	{
		if (i == 0)
		{
			print_bigint(&val_num, "val_num");
			print_bigint(&val_den, "val_den");
		}
		digit = bigint_divide(&val_num, &val_den);
		if (i == 0)
			printf("digit: %d\n", digit);
		string[i] = '0' + digit;
		bigint_tmp = (t_bigint){0, {0}};
		bigint_cpy(&bigint_tmp, &val_den);
		bigint_multiply_nb(&bigint_tmp, digit);
		bigint_substract(&val_num, &bigint_tmp, &val_num);
		bigint_multiply_nb(&val_num, 10);
		++i;
	}
	printf("%s\n", string);
}

void			conv_handler(t_worker *work, const char **fmt, va_list args,
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
