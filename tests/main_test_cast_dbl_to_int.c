/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkettani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 12:28:29 by jkettani          #+#    #+#             */
/*   Updated: 2019/03/01 13:53:22 by jkettani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <stdio.h>

int		main(int ac, char **av)
{
	double	dbl;
	int		nb;

	(void)ac;
	(void)av;
	dbl = 0.002;
	nb = (int)floor(log10(dbl));

	printf("%d\n", nb);
	return (0);
}
