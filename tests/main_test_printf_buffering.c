/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test_printf_buffering.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkettani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 17:31:27 by jkettani          #+#    #+#             */
/*   Updated: 2019/02/18 17:54:40 by jkettani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

int		main(int ac, char **av)
{
	(void)ac;
	(void)av;
	// No newline character
	printf("%s", "Line1");
	write(STDOUT_FILENO, "Line2", 5);
	printf("%s\n", "Line3");

	// Newline character
	printf("%s\n", "Line1");
	write(STDOUT_FILENO, "Line2\n", 6);
	printf("%s\n", "Line3");

	// No newline character but buffer flushed
	printf("%s", "Line1");
	fflush(stdout);
	write(STDOUT_FILENO, "Line2", 5);
	printf("%s\n", "Line3");
	return (0);
}
