/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkettani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 14:30:56 by jkettani          #+#    #+#             */
/*   Updated: 2019/02/25 21:18:03 by jkettani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "ft_printf.h"
# include "dbg_utils.h"

int				is_type(const char c);
int				is_flag(const char c);
int				is_len_modif(const char c);
int				is_num_type(const char c);
void			save_int_value(int int_value, t_format *conv_params);
const char		*skip_digits(const char *fmt);
const char		*save_value_skip_digits(const char *fmt, t_format *conv_params);
void			save_flag(const char c, t_format *conv_params);
void			save_len_modif(const char *fmt, t_format *conv_params);
void			save_type(const char c, t_format *conv_params);
const char		*parse_conv_spec(const char *fmt, t_format *conv_params);
intmax_t		get_int_arg_val(t_format *conv_params, va_list args);
char			*int_arg_val_to_str(intmax_t arg_val, t_format *conv_params);
void			init_variables(t_format *conv_params, int *i, t_result *result);
int				parse_fmt(char **str, const char *fmt, va_list args);
t_ints			convert_imax_to_ints(intmax_t arg_val, t_format *conv_params);
char			*int_arg_val_to_str_conv(intmax_t arg_val, const char *base,
					t_format *conv_params);
int				get_nb_zeros_prec(int nb_digits, int prec);
int				get_nb_padding(int curr_len, int width);
char			*prepend_prec(char **val_str, int nb_zeros_prec);
char			*prepend_sign(char **val_str, t_format *conv_params);
char			*prepend_prefix(char **val_str, t_format *conv_params);
char			*add_padding(char **val_str, int padding, 
					t_format *conv_params);
char			*format_int_str(char *val_str, t_format *conv_params);
int				has_sign(int nb_zeros_prec, t_format *conv_params);
int				has_prefix(t_format *conv_params);
char			*get_formatted_str(t_format *conv_params, va_list args);
char			*get_formatted_str_str(t_format *conv_params, va_list args);
char			*get_formatted_str_char(t_format *conv_params, va_list args);
char			*get_formatted_str_int(t_format *conv_params, va_list args);
char			*format_str(char *val_str, t_format *conv_params);
char			*format_char_str(char *val_str, t_format *conv_params);
char			*char_arg_val_to_str(t_uchar arg_val);

#endif
