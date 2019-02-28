/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_ft_printf_test.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkettani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/28 16:50:07 by jkettani          #+#    #+#             */
/*   Updated: 2019/02/28 17:30:58 by jkettani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

#define ARGS "%#023yo\n", 233

int		main(int ac, char **av)
{
	(void)ac;
	(void)av;
	ft_printf(ARGS);
	return (0);
}
