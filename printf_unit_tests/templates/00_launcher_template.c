/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_launcher_template.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkettani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/01 18:52:34 by jkettani          #+#    #+#             */
/*   Updated: 2019/03/01 18:59:30 by jkettani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libunit.h"
#include "ft_printf.h"
#include "TEST_HEADER.h" // ex: "type_c.h"

int					TEST_TYPE_NAME_launcher(void) // ex: type_c_launcher(void);
{
	t_unit_test 	*test_list;
	int				err;
	int				fd;

	err = 0;
	fd = 1;
	test_list = NULL;
	print_fct_name_fd("TEST_TYPE_NAME", fd); // ex: "type c"
	if ((err = load_test(&test_list, "TEST_NAME", // ex: "%10c"
			&TEST_TYPE_TEST_NAME, SUCCESS))) // ex: &type_c_width_test
		print_error_fd(err, fd);
	return (launch_tests(&test_list, fd));
}
