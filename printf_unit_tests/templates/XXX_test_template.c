/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   XXX_test_template.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkettani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/01 19:01:08 by jkettani          #+#    #+#             */
/*   Updated: 2019/03/01 19:08:36 by jkettani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <limits.h>

#define ARGS "hello ca%----4c %c va %10c%-c ??", '\0', '\n', (char)110, 0

int		test(void)
{
	char	*line;
	char	buf[3] = {0};
	int		out;
	int		p[2];
	int		fd;
	int		ret;

	ret = 0;
	fd = 1;
	out = dup(fd);
	pipe(p);
	dup2(p[1], fd);
	printf(ARGS);
	close(p[1]);
	dup2(out, fd);
	read(p[0], buf, 3);
	close(p[0]);	
	if (strcmp(buf, "42") == 0)
		ret = 1;
	else
		ret = 0;
	return (ret);

}

int		TEST_TYPE_TEST_NAME(void)
{
	if (test())
		return (0);
	else
		return (-1);
}

