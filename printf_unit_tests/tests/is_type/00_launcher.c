/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_launcher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkettani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 15:59:47 by jkettani          #+#    #+#             */
/*   Updated: 2019/02/21 16:25:28 by jkettani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libunit.h"
#include "utils.h"
#include "is_conv_spec.h"

int					is_conv_spec_launcher(void)
{
	t_unit_test 	*test_list;
	int				err;
	int				fd;

	err = 0;
	fd = 1;
	test_list = NULL;
	print_fct_name_fd("IS_CONV_SPEC", fd);
	if ((err = load_test(&test_list, "Test specifier 'd'", 
						&is_conv_spec_test_d, SUCCESS)))
		print_error_fd(err, fd);
	if ((err = load_test(&test_list, "Test specifier 'i'", 
						&is_conv_spec_test_i, SUCCESS)))
		print_error_fd(err, fd);
	if ((err = load_test(&test_list, "Test specifier '%'",
						&is_conv_spec_test_char_0, SUCCESS)))
		print_error_fd(err, fd);
	if ((err = load_test(&test_list, "Test non specifier char 'y'", 
						&is_conv_spec_test_no_spec, SUCCESS)))
		print_error_fd(err, fd);
	if ((err = load_test(&test_list, "Test non specifier '\\0'",
						&is_conv_spec_test_char_0, SUCCESS)))
		print_error_fd(err, fd);
	return (launch_tests(&test_list, fd));
}
