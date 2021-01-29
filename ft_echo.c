/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krios-fu <krios-fu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 23:10:33 by krios-fu          #+#    #+#             */
/*   Updated: 2021/01/29 17:18:34 by krios-fu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void    ft_echo(char *str, char *argv)
{
	while (*str == ' ')
		str++;
	if(*str == '\0')
	{
		write(1, "\n", 1);
		return ;
	}
	if (argv[0] == '-' && argv[1] == 'n')
		ft_printf("%s", str);
	else
		ft_printf("%s\n", str);
}