/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krios-fu <krios-fu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 16:20:05 by krios-fu          #+#    #+#             */
/*   Updated: 2021/01/29 19:29:46 by krios-fu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void ft_prompt(void)
{
	write(1, "minishell> ", 11);
}

 void ft_head (void)
 {
	printf(" \x1b[33m__  __  _        _      _          _  _ 42\n| \\  / |(_) _ _  (_) ___| |_   ___ | || |\n\x1b[34m| |\\/| || || ' \\ | |(_-<| ' \\ / -_)| || |\n\x1b[31m|_|  |_||_||_||_||_|/__/|_||_|\\___||_||_|\n");
	printf("\t\t  \x1b[37mBy: Abello-r & Krios-fu\n\n\n\n");

 }
 
int main (int argc, char *argv [], char *envp [])
{
	char *line;
	char **comand;
	int  n_cmd;
	int spc;
	t_list *envp_l;
	
	n_cmd = 0;
	spc = 0;
	argc = 0;
	argv = 0;
	envp_l = ft_envp(envp);
	ft_head();
	ft_prompt();
	
	while(get_next_line (0, &line) > 0)
	{
		comand = ft_set_comand(line);
		n_cmd = 0;
		while (comand[n_cmd] != '\0')
		{
			spc = 0;
			while (comand[n_cmd][spc]== ' ')
				spc++;
			if(!ft_strncmp(&comand[n_cmd][spc], "pwd ", 4) || !ft_strncmp(&comand[n_cmd][spc], "pwd", 3))
					ft_pwd_print();
			else if(!ft_strncmp(&comand[n_cmd][spc], "env ", 4) || !ft_strncmp(&comand[n_cmd][spc], "env", 3))
					ft_print_envp(envp_l);
		//	else if(!ft_strncmp(&comand[n_cmd][spc], "echo -n", 6))
		//			ft_echo(&comand[n_cmd][7 + spc], "-n");
			else if(!ft_strncmp(&comand[n_cmd][spc], "echo ", 5) || !ft_strncmp(&comand[n_cmd][spc], "echo", 4))
					ft_echo(&comand[n_cmd][5 + spc]);
			else
				ft_error_msg (&comand[n_cmd][spc]);
			n_cmd++;
		}
		ft_prompt();
		free(line);
	}

	return (0);
}