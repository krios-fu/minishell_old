/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krios-fu <krios-fu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 23:10:33 by krios-fu          #+#    #+#             */
/*   Updated: 2021/01/31 19:59:32 by krios-fu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_prit_echo(char *str)
{
	int flag;
	int spc;
	int	flag_spc;
	int star;

	star = 0;
	flag_spc = 0;
	spc = 0;
	flag = 0;
	while (*str != '\0')
	{
		while (*str == ' ' && spc == 0)
			str++;
		while (str[0] == '-' && str[1] == 'n'  && str[2] == ' ' && star == 0)
		{
			flag = 1;
			str = &str[3];
			while (*str == ' ')
					str++;
		}
		if (*str == 34) // "
		{
			str++;
			spc = 1;
			if(flag_spc > 0)
			{
				spc = 0;
				flag_spc = 0;
			}
			flag_spc = (spc != 0) ? 1 : 0;
		}
		if(*str == 92) //
			str++;
		write(1, str, 1);
		(spc == 0 && str[1] == ' ') ? write(1, " ", 1) : 0;	 // si estoy al final de una palabra y no estoy en una cadena con comillas, imprimo un unico espacio para separar las palabra
		str++;
		star = 1;
	}
	if (flag_spc == 1)
		ft_dquote();
	(flag == 0) ? write(1, "\n", 1) : 0;
	
}

void ft_dquote(void)
{
	char *line;

	write(1,"\rdquote> ", 10);
		while(get_next_line (0, &line) > 0)
		{
			ft_printf("dquote> ");
			free(line);
		}
}