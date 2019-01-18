/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_temp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkettani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 11:52:15 by jkettani          #+#    #+#             */
/*   Updated: 2019/01/17 11:48:00 by jkettani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <limits.h>

void	print_bits(int nb)
{
	unsigned int	mask;
	int				i;

	mask = 1 << 31;
	i = 0;
	while (mask)
	{
		if (i && !(i % 4))
			printf(" ");
		printf("%c", (mask & nb) ? '1' : '0');
		mask >>= 1;
		i++;
	}
	printf("\n");
}

int		main(void)
{
	int	nb;

	nb = -1;
	print_bits(nb);
	printf("%lu\n", sizeof(float));
	printf("%lu\n", sizeof(double));
	printf("%lu\n", sizeof(long double));
	return (0);
}
