/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   06_test_hard_valid.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkettani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/23 12:09:39 by jkettani          #+#    #+#             */
/*   Updated: 2019/02/23 12:12:44 by jkettani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#define CP conv_params
#define WIDTH CP.width
#define PREC CP.prec
#define L_FLAGS CP.flags
#define LEN_MOD CP.len_mod
#define TYPE_C CP.type_char

int		read_fmt_test_type_hard_valid(void)
{
	t_format	conv_params = { .width = 0, .prec = 0, .flags = 0u,
								.len_mod = LEN_MOD_NA, .type_char = 0};
	char		*fmt;
	const char	*ret;

	fmt = "++---00   ##2399.123456hhd";
	ret = read_fmt(fmt, &conv_params);
	if (!*ret && WIDTH == 2399 && PREC == 123456
			&& L_FLAGS == (FL_PLUS | FL_MINUS | FL_ZERO | FL_SPACE | FL_HASH
				| FL_PREC)
			&& LEN_MOD == LEN_MOD_HH && TYPE_C == 'd')
		return (0);
	else
		return (-1);
}
