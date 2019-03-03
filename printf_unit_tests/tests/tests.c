/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkettani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/03 16:37:08 by jkettani          #+#    #+#             */
/*   Updated: 2019/03/03 16:51:56 by jkettani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"
#include <stdio.h>
#include <stdlib.h>

void		print_test_result_values_trace(t_result *result, int fd_trace)
{
	dprintf(fd_trace, "expected: |%s|, ret = %d\n", result->ref_str,
				result->ref_ret);
	dprintf(fd_trace, "actual: |%s|, ret = %d\n", result->user_str,
				result->user_ret);
}

void		free_result(t_result *result)
{
	free(result.user_str);
	free(result.ref_str);
}
