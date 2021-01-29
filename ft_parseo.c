/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parseo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krios-fu <krios-fu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/29 15:28:11 by krios-fu          #+#    #+#             */
/*   Updated: 2021/01/29 16:39:27 by krios-fu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**ft_set_comand (char *str)
{
	char **comand;
	int i;

	i = 0;

	comand = ft_split(str, ';');

	/*while (comand [i] != '\0')
	{
		ft_printf("%s", comand[i]);
		i++;
	}*/
	return (comand);
}
