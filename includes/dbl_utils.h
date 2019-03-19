/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dbl_utils.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkettani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 14:55:07 by jkettani          #+#    #+#             */
/*   Updated: 2019/03/19 17:04:49 by jkettani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DBL_UTILS_H
# define DBL_UTILS_H

char		*handle_dbl_limit_values(t_dbls *arg_val, t_format *conv_params);
char		*handle_dbl_precision(char **digits, int exponent,
													t_format *conv_params);
void		handle_g_conv_spec(int exponent, t_format *conv_params);

#endif
