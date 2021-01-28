/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abello-r <abello-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 16:20:05 by krios-fu          #+#    #+#             */
/*   Updated: 2021/01/28 13:50:47 by abello-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void ft_prompt(void)
{
	write(1, "\x1b[33mmini\x1b[34mshe\x1b[31mll> \x1b[37m", 31);
}

 void ft_head (void)
 {
	printf(" \x1b[33m__  __  _        _      _          _  _ 42\n| \\  / |(_) _ _  (_) ___| |_   ___ | || |\n\x1b[34m| |\\/| || || ' \\ | |(_-<| ' \\ / -_)| || |\n\x1b[31m|_|  |_||_||_||_||_|/__/|_||_|\\___||_||_|\n");
	printf("\t\t  \x1b[37mBy: Abello-r & Krios-fu\n\n\n\n");

 }
 
int main (int argc, char *argv [], char *envp [])
{
	char str[4];
	t_list *envp_l;
	
	argc = 0;
	argv = 0;
	envp_l = ft_envp(envp);
	ft_head();
	
	while(1)
	{
		ft_prompt();
		read(0, str, 1053);
		if(!ft_strncmp(str, "pwd", 3))
			ft_pwd_print(envp_l);
		else if(!ft_strncmp(str, "env", 3))
			ft_print_envp(envp_l);
		printf("%s", str);
	}

	return (0);
}