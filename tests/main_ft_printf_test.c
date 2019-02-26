/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkettani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 12:28:29 by jkettani          #+#    #+#             */
/*   Updated: 2019/02/26 15:56:23 by jkettani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

#define ARGS "%jx", -4294967296

int		main(int ac, char **av)
{
	(void)ac;
	(void)av;
	
	ft_printf(ARGS);
	printf("\n");
	printf(ARGS);
	return (0);
}
