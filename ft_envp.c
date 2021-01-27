/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_envp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krios-fu <krios-fu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 18:13:28 by krios-fu          #+#    #+#             */
/*   Updated: 2021/01/27 20:40:39 by krios-fu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_list *ft_envp(char ** envp)
{
    t_list *envp_l;

    int i ;

    i = 1; 
    envp_l = ft_lstnew (envp [0]);
    while (envp[i])
    {
        ft_lstadd_back(&envp_l, ft_lstnew (envp [i]));
        i++;
    }  
    return(envp_l);
}

void ft_print_envp(t_list *envp_l)
{
    while (envp_l)
    {
        printf("%s\n", envp_l->content);
        envp_l = envp_l->next;
    }  
}