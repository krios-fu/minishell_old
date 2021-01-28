/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krios-fu <krios-fu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 16:20:05 by krios-fu          #+#    #+#             */
/*   Updated: 2021/01/28 23:52:20 by krios-fu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void ft_prompt(void)
{
	write(1, "\x1b[33mmini\x1b[34mshe\x1b[31mll> \x1b[37m", 32);
}

 void ft_head (void)
 {
	printf(" \x1b[33m__  __  _        _      _          _  _ 42\n| \\  / |(_) _ _  (_) ___| |_   ___ | || |\n\x1b[34m| |\\/| || || ' \\ | |(_-<| ' \\ / -_)| || |\n\x1b[31m|_|  |_||_||_||_||_|/__/|_||_|\\___||_||_|\n");
	printf("\t\t  \x1b[37mBy: Abello-r & Krios-fu\n\n\n\n");

 }
 
int main (int argc, char *argv [], char *envp [])
{
	char *line;
	t_list *envp_l;
	
	argc = 0;
	argv = 0;
	envp_l = ft_envp(envp);
	ft_head();
	ft_prompt();
	while(get_next_line (0, &line) > 0)
	{
		
		if(!ft_strncmp(line, "pwd", 3))
			ft_pwd_print();
		else if(!ft_strncmp(line, "env", 3))
			ft_print_envp(envp_l);
			else if(!ft_strncmp(line, "echo", 4))
				ft_echo(&line[5], "-n");

		ft_prompt();
	}

	return (0);
}