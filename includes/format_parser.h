/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_parser.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkettani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 13:28:03 by jkettani          #+#    #+#             */
/*   Updated: 2019/03/18 19:52:32 by jkettani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORMAT_PARSER_H
# define FORMAT_PARSER_H

int				parse_fmt(char **str, const char *fmt, va_list args);
int				add_to_buff(t_worker *work, char *val_str, int len);

#endif
