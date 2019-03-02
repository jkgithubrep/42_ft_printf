/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libunit.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkettani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 14:47:30 by jkettani          #+#    #+#             */
/*   Updated: 2019/02/07 13:30:39 by jkettani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBUNIT_H
# define LIBUNIT_H
# define COLOR_RED "\x1b[31m"
# define COLOR_GREEN "\x1b[32m"
# define COLOR_RESET "\x1b[0m"
# define SUCCESS 0
# define FAILURE -1
# define TIMEOUT 5
# include <signal.h>

/* 
** test_name: description of the test
** exp_ret: expected return value of the test
** test_fct: test function
*/
typedef struct				s_unit_test
{
	char					*test_name;
	int						exp_ret;
	int						(*test_fct)(void);
	struct s_unit_test		*next;
}							t_unit_test;

typedef struct				s_stats
{
	int						test_ret;
	int						status;
	int						count_success;
	int						count_tests;
}							t_stats;

int							load_test(t_unit_test **test_list, char *test_name, 
										int (*test_fct)(void), int exp_ret);
int							launch_tests(t_unit_test **test_list, int fd);
void						print_error_fd(int err, int fd);
void						print_header_fd(int fd);
void						print_fct_name_fd(char *fct_name, int fd);

#endif
