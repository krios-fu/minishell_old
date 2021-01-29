/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krios-fu <krios-fu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 23:10:33 by krios-fu          #+#    #+#             */
/*   Updated: 2021/01/30 00:36:18 by krios-fu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
** funcion echo resive un puntero despues de la palabra echo
** avanza los espacios hasta encontra -n  
** verifica la flag
** avanza hasta encontrar los argumentos
*/
void    ft_echo(char *str)
{
	while (*str == ' ')
		str++;
	if (str[0] == '-' && str[1] == 'n' && (str[2] == ' ' ||  str[2] == '\0') && (ft_strlen(str) > 2))
	{
		while (*str == ' ' || *str == '-' || *str == 'n')
			str++;
		//ft_dquote(str); // simulo echo con una sola " ejemplo origina: echo "e --> dquote> 
		if(*str == '\\') //verifico que se imprima con comillas
			ft_printf("\"%s\"", ft_strtrim(str, "\\\""));
		else
			ft_printf("%s", ft_strtrim(str, "\\\""));
		return ;
	}
	while (*str == ' ')
		str++;
	//ft_dquote(str); 
	if(*str == '\0')
		write(1, "\n", 1);
	else if(*str == '\\') //verifico que se imprima con comillas
			ft_printf("\"%s\"", ft_strtrim(str, "\\\""));
		else
			ft_printf("%s", ft_strtrim(str, "\\\""));
}

void	ft_prit_echo(char *str)
{
	char **new_str;
	int i;
	int flag; 

	flag = 0;
	i = 0;
	new_str = ft_split(str, '\"');
	
	while (new_str[i])
	{
		if (new_str[i][0] != '-' && new_str[i][1] != 'n' && new_str[i][2] != '\0')
			ft_echo(new_str[i]);
		else
			flag = 1;
		
		if(new_str[i + 1] && flag != 1)
			write(1, " ", 1);

		i++;
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