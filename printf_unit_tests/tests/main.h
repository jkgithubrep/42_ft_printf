/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebbaill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 22:49:46 by sebbaill          #+#    #+#             */
/*   Updated: 2019/02/28 18:06:44 by jkettani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

int					is_conv_spec_launcher(void);
int					read_fmt_launcher(void);
int					asprintf_launcher(void);

typedef struct		s_launcher
{
	char			*fct_name;
	int				(*launcher)(void);
}					t_launcher;

t_launcher			g_launchtab[] =
{
//	{"is_conv_spec", &is_conv_spec_launcher},
//	{"read_fmt", &read_fmt_launcher},
	{"asprintf", &asprintf_launcher},
	{"", NULL}
};

#endif
