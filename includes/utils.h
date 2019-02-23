/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkettani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 14:30:56 by jkettani          #+#    #+#             */
/*   Updated: 2019/02/23 19:14:13 by jkettani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "ft_printf.h"

int				is_type(const char c);
int				is_flag(const char c);
int				is_len_modif(const char c);
void			save_int_value(int int_value, t_format *conv_params);
const char		*skip_digits(const char *fmt);
const char		*save_value_skip_digits(const char *fmt, t_format *conv_params);
void			save_flag(const char c, t_format *conv_params);
void			save_len_modif(const char *fmt, t_format *conv_params);
const char		*read_fmt(const char *fmt, t_format *conv_params);
intmax_t		get_int_arg_value(t_format *conv_params, va_list args);
char			*get_str_from_ivalue(intmax_t arg_value, t_format *conv_params);
void			init_conv_params(t_format *conv_params);
void			parse_fmt(char **str, const char *fmt, va_list args);

#endif
