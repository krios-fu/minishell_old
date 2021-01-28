/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krios-fu <krios-fu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 16:20:05 by krios-fu          #+#    #+#             */
/*   Updated: 2021/01/27 20:46:12 by krios-fu         ###   ########.fr       */
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
	char str [1054];
	
	ft_head();
	
	while(1)
	{
		ft_prompt();
		read(0, str, 1053);
		if(ft_strnstr(str, "env", 3))
			ft_print_envp(ft_envp(envp));
	}

	return (0);
}