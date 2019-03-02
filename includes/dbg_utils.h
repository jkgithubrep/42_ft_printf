/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dbg_utils.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apion <apion@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 18:15:55 by apion             #+#    #+#             */
/*   Updated: 2019/02/26 15:01:22 by jkettani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DBG_UTILS_H
# define DBG_UTILS_H

# include "libft.h"
# include "ft_printf.h"

void	print_bits(unsigned short nb);
void	dbg_print_nbr(const char *str, const int n);
void	dbg_print_bin(const unsigned short n);
void	dbg_print_conv_params(t_format *conv_params);

#endif
