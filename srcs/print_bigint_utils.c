/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_bigint_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkettani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 21:33:09 by jkettani          #+#    #+#             */
/*   Updated: 2019/03/08 18:00:58 by jkettani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "print_bigint_utils.h"
#include <stdio.h>

void	print_32bits(unsigned int nb)
{
	unsigned int mask;

	mask = 1u << 31;
	while (mask)
	{
		printf("%c", (nb & mask) ? '1' : '0');
		mask >>= 1;	
	}
}

void	print_bigint_header(void)
{
	int i;

	i = BIGINT_SIZE;
	while (i--)
	{
		printf("|%16d", i);
		printf("%16c", ' ');
	}
	printf("|\n");
}

void	print_separation(void)
{
	int i;

	i = 0;
	while (i < BIGINT_SIZE * 32 + (BIGINT_SIZE / 2) * 2 + 1)
	{
		printf("%c", '-');
		i++;
	}
	printf("\n");
}

void	print_blocks_dec(const t_bigint *bigint)
{
	int		i;

	i = BIGINT_SIZE;
	while (i--)
	{
		printf("|%16u", bigint->blocks[i]);
		printf("%16c", ' ');
	}
	printf("|\n");
}

void	print_blocks_bin(const t_bigint *bigint)
{
	int		i;

	i = BIGINT_SIZE;
	while (i--)
	{
		printf("|");
		print_32bits(bigint->blocks[i]);
	}
	printf("|\n");
}

void	print_bigint(const t_bigint *bigint, const char *name)
{
	int		i;

	i = 0;
	printf(">>> %s <<<\n", name);
	printf("length: %d\n", bigint->length);
//	print_separation();
//	print_bigint_header();
//	print_separation();
//	print_blocks_dec(bigint);
//	print_separation();
	print_blocks_bin(bigint);
//	print_separation();
}
