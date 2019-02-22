/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkettani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 14:25:08 by jkettani          #+#    #+#             */
/*   Updated: 2019/02/22 21:27:02 by jkettani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "libft.h"

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
