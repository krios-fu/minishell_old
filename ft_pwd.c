/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krios-fu <krios-fu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 21:57:18 by krios-fu          #+#    #+#             */
/*   Updated: 2021/01/29 16:15:08 by krios-fu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_pwd_print()
{
	char *pwd;
	
	pwd = getcwd(NULL, 0);
	ft_printf("%s\n", pwd);
	free (pwd);
}