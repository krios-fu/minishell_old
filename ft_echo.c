/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krios-fu <krios-fu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 23:10:33 by krios-fu          #+#    #+#             */
/*   Updated: 2021/01/29 19:32:03 by krios-fu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void    ft_echo(char *str)
{
	while (*str == ' ')
		str++;
	if (str[0] == '-' && str[1] == 'n' && str[2] == ' ')
	{
		while (*str == ' ' || *str == '-' || *str == 'n')
			str++;
		ft_printf("%s", str);
		return ;
	}
	while (*str == ' ')
			str++;
	if(*str == '\0')
	{
		write(1, "\n", 1);
		return ;
	}
	else
		ft_printf("%s\n", str);
//	if (argv[0] == '-' && argv[1] == 'n')
//		ft_printf("%s", str);
}