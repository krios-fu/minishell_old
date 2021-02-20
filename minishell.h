/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abello-r <abello-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 18:14:39 by krios-fu          #+#    #+#             */
/*   Updated: 2021/02/18 12:57:36 by abello-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _MINISHELL_H
# define _MINISHELL_H

#include "./srcs/libft/libft.h"
#include "./srcs/gnl/get_next_line_bonus.h"
#include "./srcs/printf/printf.h"
#include <unistd.h>
#include <stdio.h>

t_list	*ft_set_envp(char **envp);
void    ft_printf_env(t_list *envp_l);
void    ft_pwd_print(void);
char    *ft_print_echo2(char *str);
void    ft_dquote(char *str);
void	ft_print_echo(char *str);
char    **ft_set_comand (char *str);
void	ft_error_msg (char *str);
void	ft_chdir(char *str);

#endif
