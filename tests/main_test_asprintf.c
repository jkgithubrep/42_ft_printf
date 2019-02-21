/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test_asprintf.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkettani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 11:39:10 by jkettani          #+#    #+#             */
/*   Updated: 2019/02/21 11:41:44 by jkettani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

int		main(int ac, char **av)
{
	char 	*str;
	int		ret;

	(void)ac;
	(void)av;
	ret = asprintf(&str, "%s%c%s\n", "Hi", 0, ", what's up?");
	write(1, str, ret);
	printf("%s", str);
	return (0);
}
