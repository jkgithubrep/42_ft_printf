/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01_test_type_only.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkettani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 22:19:07 by jkettani          #+#    #+#             */
/*   Updated: 2019/02/25 18:48:10 by jkettani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#define CP conv_params
#define WIDTH CP.width
#define PREC CP.prec
#define L_FLAGS CP.flags
#define LEN_MOD CP.len_mod
#define TYPE_C CP.type_char

int		read_fmt_test_type_only(void)
{
	t_format	conv_params = { .width = 0, .prec = 0, .flags = 0u,
								.len_mod = LEN_MOD_NA, .type_char = 0};
	char		*fmt;
	const char	*ret;

	fmt = "o";
	ret = parse_conv_spec(fmt, &conv_params);
	if (!*ret && WIDTH == 0 && PREC == 0
			&& L_FLAGS == 0u
			&& LEN_MOD == LEN_MOD_NA && TYPE_C == 'o')
		return (0);
	else
		return (-1);
}
