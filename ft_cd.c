/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krios-fu <krios-fu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/31 22:12:02 by krios-fu          #+#    #+#             */
/*   Updated: 2021/01/31 22:49:11 by krios-fu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_chdir(char *str)
{
	char *s;
	s = ft_strtrim(str, " ");
	if (chdir(s))
		ft_printf("cd: no such file or directory: %s\n", str);
	free(s);
}