/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkettani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 23:27:01 by jkettani          #+#    #+#             */
/*   Updated: 2019/01/25 17:53:57 by jkettani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINT_H
# define PRINT_H

void		print_error_fd(int err, int fd);
void		print_test_result_fd(t_unit_test *test, t_stats *stats, int fd);
void		print_final_fd(t_stats *stats, int fd);
void		print_fct_name_fd(char *fct_name, int fd);

#endif
