/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krios-fu <krios-fu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 18:14:39 by krios-fu          #+#    #+#             */
/*   Updated: 2021/01/27 22:35:20 by krios-fu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _MINISHELL_H
# define _MINISHELL_H

#include "./libft/libft.h"
#include <unistd.h>
#include <stdio.h>


t_list	*ft_envp(char ** envp);
void	ft_print_envp(t_list *envp_l);
void    ft_pwd_print(t_list *env_l);

#endif