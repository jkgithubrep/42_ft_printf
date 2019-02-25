/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkettani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 12:28:29 by jkettani          #+#    #+#             */
/*   Updated: 2019/02/25 19:18:18 by jkettani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#define ARGS "%s", "Ma chaine de caracteres"

int		main(int ac, char **av)
{
	(void)ac;
	(void)av;
	
	ft_printf(ARGS);
	return (0);
}
