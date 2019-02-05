/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkettani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 12:28:29 by jkettani          #+#    #+#             */
/*   Updated: 2019/02/05 15:25:54 by jkettani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include "libft.h"

int		main(int ac, char **av)
{
	char	*str;
	(void)ac;
	(void)av;
	
//	str = "♈ ";
//	str = "\u2648";
	str = "\xE2\x99\x88";
	ft_print_bytes(&str, 4);
	printf("\n");
	printf("%s\n", str);
	//ft_printf("un: %d\ndeux: %d\ntrois: %d\n", 1, 2, 3);	
	return (0);
}
