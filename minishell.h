/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krios-fu <krios-fu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 18:14:39 by krios-fu          #+#    #+#             */
/*   Updated: 2021/01/30 15:52:23 by krios-fu         ###   ########.fr       */
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
void	ft_prit_echo(char *str);
char    **ft_set_comand (char *str);
void	ft_error_msg (char *str);

#endif
