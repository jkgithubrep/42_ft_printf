/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkettani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 12:28:29 by jkettani          #+#    #+#             */
/*   Updated: 2019/02/26 17:48:24 by jkettani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

#define ARGS "%10s", NULL

int		main(int ac, char **av)
{
	(void)ac;
	(void)av;
	
	ft_printf(ARGS);
	printf("\n");
	printf(ARGS);
	return (0);
}
