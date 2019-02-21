/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebbaill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 22:49:46 by sebbaill          #+#    #+#             */
/*   Updated: 2019/02/21 14:46:31 by jkettani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

int					is_conv_spec_launcher(void);

typedef struct		s_launcher
{
	char			*fct_name;
	int				(*launcher)(void);
}					t_launcher;

t_launcher			g_launchtab[] =
{
	{"is_conv_spec", &is_conv_spec_launcher},
	{"", NULL}
};

#endif
