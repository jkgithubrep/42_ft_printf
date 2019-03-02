/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01_basic_test.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkettani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/29 12:51:33 by jkettani          #+#    #+#             */
/*   Updated: 2019/01/22 18:05:42 by jkettani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include "tests.h"

int		random_int(void)
{
	char	*line;
	char	buf[3] = {0};
	int		out;
	int		p[2];
	int		fd;
	int		ret;

	ret = 0;
	fd = 1;
	line = NULL;
	out = dup(fd);
	pipe(p);
	dup2(p[1], fd);
	ft_putnbr(42);
	close(p[1]);
	dup2(out, fd);
	read(p[0], buf, 3);
	close(p[0]);	
	if (strcmp(buf, "42") == 0)
		ret = 1;
	else
		ret = 0;
	free(line);
	return (ret);
}

int		putnbr_basic_test(void)
{
	if (random_int())
		return (0);
	else
		return (-1);
}
