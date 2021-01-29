/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abello-r <abello-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 21:57:18 by krios-fu          #+#    #+#             */
/*   Updated: 2021/01/29 14:08:47 by abello-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_pwd_print()
{
	char *pwd;
	
	pwd = getcwd(NULL, 0);
	ft_printf("%s\n", pwd);
	free (pwd);
	//hola
}