/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_spec_parser_utils.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkettani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 21:19:20 by jkettani          #+#    #+#             */
/*   Updated: 2019/03/18 21:26:02 by jkettani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

/*
** Take a string starting with a digit, extract the number as an int and return
** a pointer to the next non-digit character in the string.
** The value is either saved as a precision or a width depending on the value
** of the `FL_PREC' flag.
*/

const char			*save_value_skip_digits(const char *fmt,
													t_format *conv_params)
{
	int				int_value;

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

const char			*save_prec(const char *fmt, t_format *conv_params,
															va_list args)
{
	int				prec_arg;

	prec_arg = 0;
	conv_params->flags |= FL_PREC;
	if (ft_isdigit(*(fmt + 1)))
		fmt = save_value_skip_digits(fmt + 1, conv_params) - 1;
	else if (*(fmt + 1) == ASTERISK)
	{
		if ((prec_arg = (int)va_arg(args, int)) < 0)
			conv_params->flags ^= FL_PREC;
		else
			conv_params->prec = prec_arg;
		++fmt;
	}
	return (fmt);
}

void				save_width(t_format *conv_params, va_list args)
{
	int				width_arg;

	width_arg = (int)va_arg(args, int);
	if (width_arg < 0)
		conv_params->flags |= FL_MINUS;
	if ((conv_params->width = (int)ft_abs(width_arg)) < 0)
		conv_params->width = 0;
}
