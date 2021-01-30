/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krios-fu <krios-fu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 16:20:05 by krios-fu          #+#    #+#             */
/*   Updated: 2021/01/30 14:27:18 by krios-fu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void ft_prompt(void)
{
	write(1, "\x1b[32mminishell> \x1b[37m", 21);
}

 void ft_head (void)
 {
	ft_printf(" \x1b[33m__  __  _        _      _          _  _ 42\n| \\  / |(_) _ _  (_) ___| |_   ___ | || |\n\x1b[34m| |\\/| || || ' \\ | |(_-<| ' \\ / -_)| || |\n\x1b[31m|_|  |_||_||_||_||_|/__/|_||_|\\___||_||_|\n");
	ft_printf("\t\t  \x1b[37mBy: Abello-r & Krios-fu\n\n\n\n");

 }
 
int main (int argc, char *argv[], char *envp[])
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
	ft_head();
	ft_prompt();
	envp[0] = NULL;
	envp_l = NULL;//ft_set_envp(envp);
	
	while(get_next_line (0, &line) > 0)
	{

		comand = ft_set_comand(line);
		n_cmd = 0;
		while (comand[n_cmd] != (void *)'\0')
		{
			spc = 0;
			while (comand[n_cmd][spc]== ' ')
				spc++;
			if(!ft_strncmp(&comand[n_cmd][spc], "pwd ", 4) || !ft_strncmp(&comand[n_cmd][spc], "pwd", 4))
					ft_pwd_print();
			else if(!ft_strncmp(&comand[n_cmd][spc], "PWD ", 4) || !ft_strncmp(&comand[n_cmd][spc], "PWD", 4))
					ft_pwd_print();
			else if(!ft_strncmp(&comand[n_cmd][spc], "env ", 4) || !ft_strncmp(&comand[n_cmd][spc], "env", 3))
					ft_printf_env(envp_l);
		//	else if(!ft_strncmp(&comand[n_cmd][spc], "echo -n", 6))
		//			ft_echo(&comand[n_cmd][7 + spc], "-n");
			else if(!ft_strncmp(&comand[n_cmd][spc], "echo ", 5) || !ft_strncmp(&comand[n_cmd][spc], "echo", 5))
					ft_prit_echo(&comand[n_cmd][5 + spc]);
			else
				ft_error_msg (&comand[n_cmd][spc]);
			n_cmd++;
		}
		ft_prompt();
	free(line);
	}

	return (0);
}