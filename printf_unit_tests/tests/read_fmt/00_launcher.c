/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_launcher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkettani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 15:59:47 by jkettani          #+#    #+#             */
/*   Updated: 2019/02/22 22:34:26 by jkettani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libunit.h"
#include "utils.h"
#include "read_fmt.h"

int					read_fmt_launcher(void)
{
	t_unit_test 	*test_list;
	int				err;
	int				fd;

	err = 0;
	fd = 1;
	test_list = NULL;
	print_fct_name_fd("READ_FMT", fd);
	if ((err = load_test(&test_list, "Type only (\"d\")", 
						&read_fmt_test_type_only, SUCCESS)))
		print_error_fd(err, fd);
	if ((err = load_test(&test_list, "Type + width (\"10d\")", 
						&read_fmt_test_type_width, SUCCESS)))
		print_error_fd(err, fd);
	if ((err = load_test(&test_list, "Type + width + precision (\"10.34d\")", 
						&read_fmt_test_type_width_precision, SUCCESS)))
		print_error_fd(err, fd);
	if ((err = load_test(&test_list, "Type + len modifier h (\"hd\")", 
						&read_fmt_test_type_len_mod_h, SUCCESS)))
		print_error_fd(err, fd);
	if ((err = load_test(&test_list, "Type + len modifier hh (\"hhd\")", 
						&read_fmt_test_type_len_mod_hh, SUCCESS)))
		print_error_fd(err, fd);
	return (launch_tests(&test_list, fd));
}
