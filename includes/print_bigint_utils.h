/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_bigint_utils.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkettani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 21:34:10 by jkettani          #+#    #+#             */
/*   Updated: 2019/03/06 21:49:13 by jkettani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINT_BIGINT_UTILS_H
# define PRINT_BIGINT_UTILS_H

void	print_32bits(unsigned int nb);
void	print_bigint_header(void);
void	print_separation(void);
void	print_blocks_dec(const t_bigint *bigint);
void	print_blocks_bin(const t_bigint *bigint);
void	print_bigint(const t_bigint *bigint, const char *name);

#endif
