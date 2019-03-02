/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dbg_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apion <apion@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 18:20:30 by apion             #+#    #+#             */
/*   Updated: 2019/02/26 15:01:24 by jkettani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dbg_utils.h"
#include "unistd.h"

void	print_bits(unsigned short nb)
{
	unsigned long	count;
	unsigned short	mask;

	count = sizeof(nb) * 8;
	mask = 1 << (sizeof(nb) * 8 - 1);
	while (count-- > 0)
		write(1, (mask >> (15 - count) & nb) ? "1" : "0", 1);
}

void	dbg_print_nbr(const char *str, const int n)
{
	ft_putstr(str);
	ft_putstr(": ");
	ft_putnbr(n);
	ft_putendl(0);
}

void	dbg_print_bin(const unsigned short n)
{
	ft_putstr("dec: ");
	ft_putnbr(n);
	ft_putstr("\nbin: ");
	ft_putnbr_base(n, 2);
	ft_putendl(0);
}

void	dbg_print_conv_params(t_format *conv_params)
{
	ft_putstr("type_char: ");
	ft_putchar(conv_params->type_char);
	ft_putendl(0);
	ft_putstr("is_neg: ");
	ft_putnbr(conv_params->is_neg);
	ft_putendl(0);
	ft_putstr("prec: ");
	ft_putnbr(conv_params->prec);
	ft_putendl(0);
	ft_putstr("width: ");
	ft_putnbr(conv_params->width);
	ft_putendl(0);
	ft_putstr("flags: ");
	ft_putnbr_base(conv_params->flags, 2);
	ft_putendl(0);
}
