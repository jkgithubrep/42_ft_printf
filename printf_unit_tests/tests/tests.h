/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkettani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/03 16:27:36 by jkettani          #+#    #+#             */
/*   Updated: 2019/03/03 16:45:10 by jkettani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TESTS_H
# define TESTS_H

typedef struct		s_result{
	char 			*user_str;
	char			*ref_str;
	int				user_ret;
	int				ref_ret;
}					t_result;

void		print_test_result_values_trace(t_result *result, int fd_trace);

# endif
