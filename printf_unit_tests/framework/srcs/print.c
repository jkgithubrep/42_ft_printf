/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkettani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 23:04:12 by jkettani          #+#    #+#             */
/*   Updated: 2019/03/02 17:00:34 by jkettani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include <string.h>
#include <error.h>
#include <stdio.h>
#include <fcntl.h>
#include "error.h"
#include "libunit.h"

/*
** Get a file descriptor.
** If the output mode is stdout, return STDOUT_FILENO, otherwise if the ouput
** mode is a file, open the file and return the corresponding file descriptor.
** File is open either with append mode or trunc mode.
** File permissions: 0666 = 110110110 = rw-rw-rw-
*/

int			get_fd(const char *path, t_output_mode output_mode,
					t_open_mode open_mode)
{
	int		fd;
	int		oflags;	

	if (output_mode == M_STD)
		return (STDOUT_FILENO);
	else if (output_mode == M_FILE)
	{
		oflags = O_RDWR | O_CREAT | ((open_mode == OP_APPEND) ?
													O_APPEND : O_TRUNC);
		if ((fd = open(path, oflags, 0666)) < 0)
			return (-1);
		else
			return (fd);
	}
	else
		return (-1);
}

void		print_trace_header_fd(int fd)
{
	dprintf(fd, "============= TRACE ==============\n\n");
}

void		print_fct_name_fd(char *fct_name, int fd)
{
	dprintf(fd, "%s:\n", fct_name);
}

void		print_fct_name_trace_fd(char *fct_name, int fd)
{
	dprintf(fd, "\n>>>> %s <<<<\n", fct_name);
}

void		print_test_name_trace_fd(char *test_name, int fd)
{
	dprintf(fd, "----------------------------------\n");
	dprintf(fd, "test: %s\n", test_name);
}

void		print_test_name_fd(char *test_name, int fd)
{
	dprintf(fd, "  > %s: ", test_name);
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

void		print_test_result_no_color_fd(t_unit_test *test, t_stats *stats, 
																		int fd)
{
	if (stats->status == test->exp_ret)
		dprintf(fd, "%s\n", "[OK]");
	else if (stats->status == 0 || stats->status == 255)
		dprintf(fd, "%s\n", "[KO]");
	else if (stats->status == SIGBUS)
		dprintf(fd, "%s\n", "[BUSE]");
	else if (stats->status == SIGSEGV)
		dprintf(fd, "%s\n", "[SEGV]");
	else if (stats->status == SIGABRT)
		dprintf(fd, "%s\n", "[SIGA]");
	else if (stats->status == SIGALRM)
		dprintf(fd, "%s\n", "[TIME]");
}

