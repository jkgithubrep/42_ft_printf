/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkettani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 14:25:08 by jkettani          #+#    #+#             */
/*   Updated: 2019/02/21 16:21:47 by jkettani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

/* 
** Check if char argument c is a conversion specifier.
** Return value: returns zero if c is not a conversion specifier and non-zero
**               if the character tests true.
*/
int				is_conv_spec(char c)
{
	char	*ptr;

	ptr = ft_strchr(CONV_SPECS, c);
	return (!!ptr && *ptr);
}

//				(char **str, const char *fmt)
//{
//	char	buf[BUF_SIZE];
//	int		i;
//
//	i = 0;
//	while (*fmt)
//	{
//		if (*fmt != '%')
//
//		else
//			
//
//		if (i < BUF_SIZE)
//			buf[i++] = *ftm++;
//		else
//		{
//			if (!str)
//				
//			*str = ft_memjoinfree(*str, str_size, buf, i);
//			ft_bzero(buf, BUF_SIZE)
//			i = 0;
//		}
//	}
