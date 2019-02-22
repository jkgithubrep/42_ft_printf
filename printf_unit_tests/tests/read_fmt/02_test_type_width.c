/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   02_test_type_width.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkettani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 22:22:35 by jkettani          #+#    #+#             */
/*   Updated: 2019/02/22 22:22:47 by jkettani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#define CP conv_params
#define WIDTH CP.width
#define PREC CP.prec
#define L_FLAGS CP.flags
#define LEN_MOD CP.len_mod
#define TYPE_C CP.type_char

int		read_fmt_test_type_width(void)
{
	t_format	conv_params = { .width = 0, .prec = 0, .flags = 0u,
								.len_mod = LEN_MOD_NA, .type_char = 0};
	char		*fmt;
	const char	*ret;

	fmt = "10d";
	ret = read_fmt(fmt, &conv_params);
	if (!*ret && WIDTH == 10 && PREC == 0 && L_FLAGS == 0u 
			&& LEN_MOD == LEN_MOD_NA && TYPE_C == 'd')
		return (0);
	else
		return (-1);
}
