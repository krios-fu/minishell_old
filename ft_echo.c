/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abello-r <abello-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 23:10:33 by krios-fu          #+#    #+#             */
/*   Updated: 2021/02/18 15:52:21 by abello-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Falta controlar estos casos = echo hola" y echo "hola (dquotes)

#include "minishell.h"

void	ft_print_echo(char *str)
{
	int flag;
	int spc;
	int	flag_spc;
	int star;

	star = 0;
	flag_spc = 0;
	spc = 0;
	flag = 0;

	char *dup;

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
		if (*str == '\"')
		{
			str++;
			spc = 1;
			if(flag_spc > 0)
			{
				spc = 0;
				flag_spc = 0;
			}
			flag_spc = (spc != 0) ? 1 : 0;
			dup = ft_strdup(str);
		}
		if(*str == '\\' && str[1] == 'n' && spc == 0)
			str++;
		else if(*str == '\\' && str[1] == '\"' && spc == 1)
		{
			ft_dquote(dup);
			free(dup);
			break ;
		}
		else if (*str == '\\')
			str++;
		write(1, str, 1);
		(spc == 0 && str[1] == ' ') ? write(1, " ", 1) : 0;	 // si estoy al final de una palabra y no estoy en una cadena con comillas, imprimo un unico espacio para separar las palabra
		str++;
		star = 1;
	}
	if (flag_spc == 1)
		ft_dquote(str);
	(flag == 0) ? write(1, "\n", 1) : 0;
}

void ft_dquote(char *str)
{
	char *line;
	write(1,"\rdquote> ", 10); 
		while(get_next_line (0, &line) > 0)
		{
			ft_printf("dquote> ");
			if (*line == '\"')
			{
				ft_print_echo(str);
				break ;
			}
			free(line);
		}
	free(line);
}