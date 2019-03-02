/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkettani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 23:04:12 by jkettani          #+#    #+#             */
/*   Updated: 2019/01/27 11:34:31 by jkettani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdlib.h>
#include <string.h>
#include <error.h>
#include <stdio.h>
#include "error.h"
#include "libunit.h"

void		print_fct_name_fd(char *fct_name, int fd)
{
	dprintf(fd, "%s:\n", fct_name);
}

void		print_error_fd(int err, int fd)
{
	if (err < 200)
		dprintf(fd, "%s", strsignal(err));
	else if (err == ENULL)
		dprintf(fd, "%s\n", "NULL pointer.");
	else if (err == EUSIG)
		dprintf(fd, "%s\n", "Undefined signal catched.");
}

void		print_test_result_fd(t_unit_test *test, t_stats *stats, int fd)
{
	stats->count_tests += 1;
	dprintf(fd, "  > %s: ", test->test_name);
	if (stats->status == test->exp_ret)
	{
		dprintf(fd, COLOR_GREEN "%s\n" COLOR_RESET, "[OK]");
		stats->count_success += 1;
	}
	else if (stats->status == 0 || stats->status == 255)
		dprintf(fd, COLOR_RED "%s\n" COLOR_RESET, "[KO]");
	else if (stats->status == SIGBUS)
		dprintf(fd, COLOR_RED "%s\n" COLOR_RESET, "[BUSE]");
	else if (stats->status == SIGSEGV)
		dprintf(fd, COLOR_RED "%s\n" COLOR_RESET, "[SEGV]");
	else if (stats->status == SIGABRT)
		dprintf(fd, COLOR_RED "%s\n" COLOR_RESET, "[SIGA]");
	else if (stats->status == SIGALRM)
		dprintf(fd, COLOR_RED "%s\n" COLOR_RESET, "[TIME]");
}

void		print_final_fd(t_stats *stats, int fd)
{
	if (stats->count_success == stats->count_tests)
		dprintf(fd, COLOR_GREEN "⟹  %d/%d checked\n" COLOR_RESET, 
							stats->count_success, stats->count_tests);
	else
		dprintf(fd, COLOR_RED "⟹  %d/%d checked\n" COLOR_RESET, 
							stats->count_success, stats->count_tests);
}
