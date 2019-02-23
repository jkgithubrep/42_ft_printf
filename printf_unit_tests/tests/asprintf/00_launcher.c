/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_launcher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkettani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 15:59:47 by jkettani          #+#    #+#             */
/*   Updated: 2019/02/23 19:24:52 by jkettani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libunit.h"
#include "utils.h"
#include "asprintf.h"

int					asprintf_launcher(void)
{
	t_unit_test 	*test_list;
	int				err;
	int				fd;

	err = 0;
	fd = 1;
	test_list = NULL;
	print_fct_name_fd("ASPRINTF", fd);
	if ((err = load_test(&test_list, "Basic test", 
						&asprintf_basic_test, SUCCESS)))
		print_error_fd(err, fd);
	return (launch_tests(&test_list, fd));
}
