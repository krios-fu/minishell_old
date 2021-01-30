/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krios-fu <krios-fu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 23:10:33 by krios-fu          #+#    #+#             */
/*   Updated: 2021/01/30 16:28:43 by krios-fu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
** funcion echo resive un puntero despues de la palabra echo
** avanza los espacios hasta encontra -n  
** verifica la flag
** avanza hasta encontrar los argumentos
*/
char    *ft_print_echo2(char *str)
{
	while(str[0] != 92 && str[1] != 34 && *str != '\0')
	{
		write(1, str, 1);
		str++;
	}
	return (str);
}

void	ft_prit_echo(char *str)
{
	int flag;

	flag = 0;
	while (*str != '\0')
	{
		while (*str == ' ')
			str++;
		while (str[0] == '-' && str[1] == 'n' && flag == 0)
		{
			str++;
			flag = 1;
			str++;
		}
		if(*str == 92)
		{
			str++;
			str = ft_print_echo2 (str);
		}
		while (*str == ' ')
			str++;
		if (str)
		{
			if (*str != 34)
				write(1, str, 1);
		}
		else 
			break;
		str++;
	}
	if (flag == 0)
			write(1, "\n", 1);
}

void ft_dquote(char *str)
{
	char *line;
	int i;

	i = ft_strlen(str);

	if(str[0] == '\"' &&  str[i - 1] != '\"')
	{
		ft_printf("dquote> ");
		while(get_next_line (0, &line) > 0)
		{
			ft_printf("dquote> ");
			free(line);
		}
	}
}