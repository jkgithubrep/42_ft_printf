/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dbl_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkettani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 14:52:31 by jkettani          #+#    #+#             */
/*   Updated: 2019/03/20 12:12:33 by jkettani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

/*
** Check that from index `begin' to then end of `digits', there are only zeros.
*/

static int		check_end_digits(char *digits, size_t begin)
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

static char		*round_nb(char *digits, int *exponent, t_format *conv_params)
{
	size_t		i;
	t_uint		carry;

	i = ft_max(ft_tolower(conv_params->type_char) == 'e' ? 0 : *exponent, 0)
			+ conv_params->prec;
	if (!digits[i + 1] || digits[i + 1] < '5' || ((digits[i + 1] == '5')
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
		if (!arg_val->ldbl_parts.mantissa)
			return (ft_strdup("inf"));
		else
			return (ft_strdup("nan"));
	}
	else
	{
		if (!arg_val->dbl_parts.mantissa)
			return (ft_strdup("inf"));
		else
			return (ft_strdup("nan"));
	}
}

static char		*add_zeros_right(char **digits, int exponent,
									t_format *conv_params)
{
	if (exponent <= 0)
		ft_strpad_right(digits, '0',
				ft_max(conv_params->prec - (ft_strlen(*digits) - 1), 0));
	else
		ft_strpad_right(digits, '0',
			ft_max(exponent - (ft_strlen(*digits) - 1), 0)
			+ conv_params->prec - ((exponent > (int)ft_strlen(*digits) - 1) ?
			0 : ft_strlen(*digits + exponent + 1)));
	return (*digits);
}

static char		*add_exponent_sign(char **val_str, int exponent,
														t_format *conv_params)
{
	char	*append;
	char	*nb_append;
	long	u_exponent;

	append = (exponent < 0) ? ft_strdup("e-") : ft_strdup("e+");
	if (conv_params->type_char == 'E')
		ft_strupper(append);
	if (exponent > -10 && exponent < 10)
		ft_strappend(&append, "0");
	u_exponent = ft_abs(exponent);
	nb_append = ft_uimaxtoa_base(u_exponent, DEC_BASE);
	ft_strappend(&append, nb_append);
	ft_strdel(&nb_append);
	ft_strappend(val_str, append);
	ft_strdel(&append);
	return (*val_str);
}

void			handle_g_conv_spec(int exponent, t_format *conv_params)
{
	conv_params->flags |= FL_TRIM;
	if ((conv_params->flags & FL_PREC) && !conv_params->prec)
		conv_params->prec = 1;
	if ((exponent < conv_params->prec) && (exponent >= -4))
	{
		conv_params->type_char = ft_isupper(conv_params->type_char) ?
			'F' : 'f';
		conv_params->prec = conv_params->prec - 1 - exponent;
	}
	else
	{
		conv_params->type_char = ft_isupper(conv_params->type_char) ?
			'E' : 'e';
		conv_params->prec = conv_params->prec - 1;
	}
}

char			*trim_zeros(char **val_str, int len)
{
	int			i;

	i = len;
	while (i && (*val_str)[i] == '0')
		--i;
	if ((*val_str)[i] == '.')
		--i;
	if (!ft_strcut(val_str, i + 1))
		return (NULL);
	return (*val_str);
}

char			*add_dbl_prec(char **val_str, char *frac_part,
														t_format *conv_params)
{
	char		*fraction;

	if (!(fraction = ft_strndup(frac_part, conv_params->prec)))
		return (NULL);
	ft_strappend(val_str, fraction);
	ft_strdel(&fraction);
	return (*val_str);
}

char			*handle_conv_switch(char **digits, int exponent,
												t_format *conv_params)
{
	handle_g_conv_spec(exponent, conv_params);
	ft_strpad_left(digits, '0', -exponent);
	return (*digits);
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
	int			exp_add;

	if (exponent < 0 && ft_tolower(conv_params->type_char) == 'f')
		ft_strpad_left(digits, '0', -exponent);
	add_zeros_right(digits, exponent, conv_params);
	round_nb(*digits, &exponent, conv_params);
	if ((conv_params->flags & FL_TRIM) && exponent == -4
			&& ft_tolower(conv_params->type_char) == 'e')
		handle_conv_switch(digits, exponent, conv_params);
	exp_add = ft_max(ft_tolower(conv_params->type_char) == 'e' ? 0 : exponent,
																			0);
	if (!(val_str = ft_strndup(*digits, exp_add + 1)))
		return (NULL);
	if ((conv_params->flags & FL_HASH) || !((conv_params->flags & FL_PREC)
										&& !(conv_params->prec)))
		ft_strappend(&val_str, ".");
	if (conv_params->prec)
		add_dbl_prec(&val_str, *digits + exp_add + 1, conv_params);
	if ((conv_params->flags & FL_TRIM) && !(conv_params->flags & FL_HASH)
			&& ft_instr('.', val_str))
		trim_zeros(&val_str, exp_add + 1 + conv_params->prec);
	if (ft_tolower(conv_params->type_char) == 'e')
		add_exponent_sign(&val_str, exponent, conv_params);
	return (val_str);
}
