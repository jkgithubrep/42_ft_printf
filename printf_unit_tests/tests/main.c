/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkettani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 21:34:44 by jkettani          #+#    #+#             */
/*   Updated: 2019/01/22 14:59:13 by jkettani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include "libunit.h"
#include "main.h"

int		main(int ac, char **av)
{
	unsigned int	i;
	unsigned int	j;
	int				err;
	int				fd;

	fd = 1;
	err = 0;
	if (ac == 1)
	{
		i = 0;
		while (strcmp(g_launchtab[i].fct_name, ""))
		{
			(g_launchtab[i++].launcher)();
			dprintf(fd, "\n");
		}
	}
	else
	{
		i = 0;
		while (av[i])
		{
			j = 0;
			while (strcmp(g_launchtab[j].fct_name, ""))
			{
				if (!strcmp(g_launchtab[j].fct_name, av[i]))
				{
					if (err == (g_launchtab[j].launcher)())
						print_error_fd(err, 1);
					dprintf(fd, "\n");
					break ;
				}
				j++;
			}
			i++;
		}
	}
	return (0);
}
