/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test_write.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkettani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 10:58:05 by jkettani          #+#    #+#             */
/*   Updated: 2019/02/21 10:58:11 by jkettani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		main(int ac, char **av)
{
	char str[] = {'H', 'i', 0, ',', ' ', 'c', 'a', ' ', 'v', 'a', '?', '\n'};

	(void)ac;
	(void)av;
	write(1, str, sizeof(str));
	return (0);
}