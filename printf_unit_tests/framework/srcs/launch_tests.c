/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch_tests.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkettani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 18:42:36 by jkettani          #+#    #+#             */
/*   Updated: 2019/01/25 11:36:40 by jkettani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <errno.h>
#include "libunit.h"
#include "print.h"
#include "print_util.h"
#include "error.h"

static void				reset_stats(t_stats *stats)
{
	stats->test_ret = 0;
	stats->status = 0;
	stats->count_success = 0;
	stats->count_tests = 0;
}

static int				launch_unit_test(t_unit_test *test, t_stats *stats, int fd)
{
	pid_t	pid;

	pid = fork();
	if (pid == 0)
	{
		alarm(TIMEOUT);
		stats->test_ret = (*test->test_fct)();
		exit(stats->test_ret);
	}
	else if (pid > 0)
	{
		wait(&(stats->status));
		if (WIFEXITED(stats->status))
			stats->status = WEXITSTATUS(stats->status);
		else if (WIFSIGNALED(stats->status))
			stats->status = WTERMSIG(stats->status);
		else
			return (EUSIG);
		print_test_result_fd(test, stats, fd);
	}
	else if (pid == -1)
		return (errno);
	return (0);
}

static t_unit_test		*del_test_next(t_unit_test *test)
{
	t_unit_test *next;

	next = test->next;
	free(test); 
	return (next);
}

static void				del_list(t_unit_test **test_list)
{
	if (!test_list)
		return ;
	while (*test_list)
		*test_list = del_test_next(*test_list);
}

int						launch_tests(t_unit_test **test_list, int fd)
{
	t_unit_test		*test;
	t_stats			stats;
	int				err;

	if (!test_list)
		return (ENULL);
	reset_stats(&stats);
	fd = 1;
	test = *test_list;
	while (test)
	{
		if ((err = launch_unit_test(test, &stats, fd)))
		{
			del_list(&test);
			return (err);
		}
		test = del_test_next(test);
	}
	print_final_fd(&stats, fd);
	return ((stats.count_success != stats.count_tests) ? -1 : 0);
}
