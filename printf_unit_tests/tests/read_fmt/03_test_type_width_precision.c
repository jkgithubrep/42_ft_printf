/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   03_test_type_width_precision.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkettani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 22:25:04 by jkettani          #+#    #+#             */
/*   Updated: 2019/02/22 22:27:25 by jkettani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "utils.h"
#define CP conv_params
#define WIDTH CP.width
#define PREC CP.prec
#define L_FLAGS CP.flags
#define LEN_MOD CP.len_mod
#define TYPE_C CP.type_char

int		read_fmt_test_type_width_precision(void)
{
	t_format	conv_params = { .width = 0, .prec = 0, .flags = 0u,
								.len_mod = LEN_MOD_NA, .type_char = 0};
	char		*fmt;
	const char	*ret;

	fmt = "10.34d";
	ret = read_fmt(fmt, &conv_params);
	if (!*ret && WIDTH == 10 && PREC == 34 && L_FLAGS == FL_PREC
			&& LEN_MOD == LEN_MOD_NA && TYPE_C == 'd')
		return (0);
	else
		return (-1);
}
