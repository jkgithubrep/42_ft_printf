/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_util.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkettani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 23:23:12 by jkettani          #+#    #+#             */
/*   Updated: 2018/12/02 16:11:00 by jkettani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINT_UTIL_H
# define PRINT_UTIL_H

void		putchar_fd(char c, int fd);
void		putstr_fd(char const *str, int fd);
void		putendl_fd(char const *s, int fd);
void		putnbr_fd(int n, int fd);

#endif
