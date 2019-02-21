/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkettani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 12:28:29 by jkettani          #+#    #+#             */
/*   Updated: 2019/02/21 12:35:58 by jkettani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	test_dereferencing(char **str)
{
	if (*str == NULL)
		printf("%s\n", "No segfault");
}

int		main(int ac, char **av)
{
	char	*str;

	(void)ac;
	(void)av;
	str = NULL;
	test_dereferencing(&str);
	return (0);
}
